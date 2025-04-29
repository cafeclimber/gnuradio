import re
from importlib import import_module
from pathlib import Path
from string import Template
from textwrap import dedent

from gnuradio import gr
from gnuradio.grc.core import platform

# block_mods = [
#     "analog",
#     "audio",
#     "blocks",
#     "channels",
#     "digital",
#     "dtv",
#     "fec",
#     "fft",
#     "filter",
#     "iio",
#     "network",
#     "pdu",
#     "qtgui",
#     "soapy",
#     "trellis",
#     "uhd",
#     "video-sdl",
#     "vocoder",
#     "wavelet",
#     "zeromq",
# ]
# for mod in block_mods:
#     import_module(f"gnuradio.{mod.replace('-', '_')}")


filename_bits_to_ignore = [
    "_bb",
    "_bc",
    "_cc",
    "_ff",
    "_fb",
    "_fc",
    "_ccf",
    "_ccc",
    "_ccz",
    "_fff",
    "_blk",
    "_s",
    "_uc",
    "_sb",
    "_bs",
    "_ps",
    "_sp",
    "_ss",
    "_f",
    "_c",
    "_b",
    "_bf",
    "_x",
    "_xx",
    "_xxx",
    "_xb",
    "_vx",
    "_vxx",
]

path_replacements = [
    (" ", "_"),
    ("/", "_"),
    ("\\", "_"),
    ("-", "_"),
    ("(", ""),
    (")", ""),
    ("[", ""),
    ("]", ""),
    (":", ""),
]


def block_to_group_name(block):
    print(block.__name__, end="")
    group_name = f"block_{block.__name__}"
    if group_name == "blocks_probe_signal_vx":
        group_name = "blocks_probe_signal_v"
    for bit in filename_bits_to_ignore:
        group_name = group_name.removesuffix(bit)

    print(f"\t{group_name}")
    return group_name


def fix_path_name(f_name):
    for old, new in path_replacements:
        f_name = f_name.replace(old, new)

    return f_name


def get_block_types(block):
    print(f"{block.__name__}")
    try:
        types = next(param for param in block.parameters_data if param["id"] == "type")
    except StopIteration:
        return []
    try:
        return types["option_attributes"]["fcn"]
    except KeyError:
        return []


def get_block_make_fcns(block):
    types = get_block_types(block)
    if len(types) == 0:
        return []
    make = Template(block.templates["make"].replace("{", "").replace("}", ""))
    funcs = [make.safe_substitute(type=t) for t in types]
    return [re.sub(r"(\w+\..*)\.fcn\(.*\)", r"\1", f) for f in funcs]


def get_block_tree():
    model = platform.Platform(
        version=gr.version(),
        version_parts=(gr.major_version(), gr.api_version(), gr.minor_version()),
        prefs=gr.prefs(),
    )
    model.build_library()

    block_tree = {}
    for block in model.blocks.values():
        if block.category:
            category = block.category[:]
            sub_tree = block_tree
            while category:
                current = category.pop(0)
                if current not in sub_tree:
                    sub_tree[current] = {}
                sub_tree = sub_tree[current]
            sub_tree[block.label] = block

    return block_tree


def _make_doxy_groups(tree, file_handle):
    for k, v in tree.items():
        if isinstance(v, dict):
            group_name = f"blocks_{k.lower().replace(' ', '_').replace('/', '_')}"
            file_handle.write(rf"/*! \defgroup {group_name} {k}")
            file_handle.write("\n")
            file_handle.write(" * @{\n")
            file_handle.write(" */\n\n")
            _make_doxy_groups(v, file_handle)
            file_handle.write("\n/*! @} */\n\n")
        else:
            group_name = block_to_group_name(v)
            file_handle.write(rf"/*! \defgroup {group_name} {k} */")
            file_handle.write("\n")


def make_doxy_groups(tree):
    top_matter = dedent(
        r"""
        # Copyright (C) 2017 Free Software Foundation, Inc.
        #
        # Permission is granted to copy, distribute and/or modify this document
        # under the terms of the GNU Free Documentation License, Version 1.3
        # or any later version published by the Free Software Foundation;
        # with no Invariant Sections, no Front-Cover Texts, and no Back-Cover Texts.
        # A copy of the license is included in the section entitled "GNU
        # Free Documentation License".

        /*! \defgroup blocks GNU Radio Blocks
         * \brief All blocks that can be used in GR graphs are listed here or in
         * the subcategories below.
         * @{ */\n
    """,
    )

    current_dir = Path(__file__)
    doxy_group_defs_path = (
        current_dir / "../../doxygen/other/group_defs.dox"
    ).resolve()
    with doxy_group_defs_path.open("w") as ff:
        ff.write(top_matter)
        _make_doxy_groups(tree["Core"], ff)
        ff.write("\n/*! @} */\n")


def fix_doxy_groups():
    paths = [
        (
            Path("../../") / ("gr-" + x) / "include" / "gnuradio" / x.replace("-", "_")
        ).resolve()
        for x in block_mods
    ]

    for path in paths:
        blocks = [p for p in path.iterdir() if p.suffix == ".h" and p.name != "api.h"]
        for block in blocks:
            group_stem = str(block.stem)
            for bit in filename_bits_to_ignore:
                group_stem = group_stem.removesuffix(bit)

            group_name = f"block_{path.name}_{group_stem}"

            with block.open("r") as ff:
                a = ff.read()
                is_block = re.search(r"\ *\*\ *\\ingroup\ *(\w*)", a) is not None

            if is_block:
                updated = re.sub(r"(\ *\*\ *\\ingroup\ *)(\w*)", rf"\1{group_name}", a)
                with block.open("w") as ff:
                    ff.write(updated)


def _make_rst_files(tree, doc_path):
    for k, v in tree.items():
        if isinstance(v, dict):
            has_children = any(isinstance(v_, dict) for v_ in v.values())
            only_children = all(isinstance(v_, dict) for v_ in v.values())

            path = doc_path / fix_path_name(k)
            path.mkdir(exist_ok=True)

            with (path / "index.rst").open("w") as ff:
                ff.write(f"{'-' * len(k)}" + "\n")
                ff.write(f"{k}" + "\n")
                ff.write(f"{'-' * len(k)}" + "\n\n")
                ff.write(".. toctree::\n")
                ff.write("   :maxdepth: 1\n")
                ff.write("   :glob:\n\n")
                if has_children:
                    ff.write("   */index\n")
                if not only_children:
                    ff.write("   *")

            _make_rst_files(v, path)
        else:

            path = (doc_path / fix_path_name(k)).with_suffix(".rst")
            path.parent.mkdir(parents=True, exist_ok=True)
            wiki_title = k.replace(" ", "_")

            params_table = _make_params_table(tree[k].parameters_data)
            if k == "Python Block":
                params_table = ""

            with path.open("w") as ff:
                # Multiline f-strings cause weird shenanigans with dedent, so
                # have to use string concatenation
                contents = dedent(
                    f"""\
                    {'-' * len(k)}
                    {k}
                    {'-' * len(k)}

                    :gr-wiki-link:`{wiki_title}`

                    Parameters
                    **********

                """,
                )
                contents += f"{params_table}\n"
                contents += "Class Reference\n"
                contents += "*******************\n\n"
                contents += ".. tabs::\n\n"
                contents += "   .. group-tab:: Python\n"
                contents += "      TODO\n\n"
                if hasattr(v, "cpp_templates"):
                    contents += "   .. group-tab:: C++\n\n"
                    contents += f"      .. doxygengroup:: {block_to_group_name(v)}\n"
                    contents += "         :content-only:\n"
                    contents += "         :undoc-members:\n"
                    contents += "         :private-members:\n"
                    contents += "         :members:\n\n"

                ff.write(contents)


def _make_params_table(params: list) -> str:
    cell_w = 25  # Minimimum cell width

    for param in params:
        if "$" in param.get("dtype", ""):
            continue
        if param.get("category", "") == "Advanced":
            continue
        a = str(param.get("label", ""))
        b = str(param.get("id", ""))
        c = str(param.get("dtype", ""))
        d = str(param.get("default", ""))

        m = len(max([a, b, c, d], key=len))
        if m > cell_w:
            cell_w = m

    headers = f"+{'-'*cell_w}+{'-'*cell_w}+{'-'*cell_w}+{'-'*cell_w}+{'-'*cell_w}+\n"
    headers += f"|{'Label':<{cell_w}}|{'ID':<{cell_w}}|{'Description':<{cell_w}}|{'Data Type':<{cell_w}}|{'Default':<{cell_w}}|\n"
    headers += f"+{'='*cell_w}+{'='*cell_w}+{'='*cell_w}+{'='*cell_w}+{'='*cell_w}+\n"

    table = [dedent(headers)]

    for param in params:
        if "$" in param.get("dtype", ""):
            continue
        if param.get("category", "") == "Advanced":
            continue

        row = f"|{param.get('label', '')!s:<{cell_w}}"
        row += f"|{param.get('id', '')!s:<{cell_w}}"
        row += f"|{'TODO'!s:<{cell_w}}"
        row += f"|{param.get('dtype', '')!s:<{cell_w}}"
        row += f"|{param.get('default', '')!s:<{cell_w}}|\n"
        row += f"+{'-'*cell_w}+{'-'*cell_w}+{'-'*cell_w}+{'-'*cell_w}+{'-'*cell_w}+\n"

        table += dedent(row)

    return "".join(table)


def make_rst_files(tree):
    current_dir = Path(__file__).parent.resolve()
    block_docs_path = current_dir / "blocks"
    if not block_docs_path.exists():
        block_docs_path.mkdir()
    with (block_docs_path / "index.rst").open("w") as ff:
        block_root_doc = dedent(
            """\
            Built-in Blocks
            ===============

            .. toctree::
               :maxdepth: 1
               :glob:

               */index
        """,
        )
        ff.write(block_root_doc)
    _make_rst_files(tree["Core"], block_docs_path)


if __name__ == "__main__":
    block_tree = get_block_tree()
    # fix_doxy_groups()
    # make_doxy_groups(block_tree)
    make_rst_files(block_tree)
