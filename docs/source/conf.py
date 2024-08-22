import sys
from pathlib import Path
from textwrap import dedent

# -- Project information -----------------------------------------------------

project = "GNU Radio"
copyright = "2024, The GNU Radio Project"
author = "The GNU Radio Project"
release = "3.10.11.0"

# -- General configuration ---------------------------------------------------

sys.path.insert(0, str(Path("/usr/local/lib/python3.10/dist-packages/").resolve()))
sys.path.insert(
    0, str(Path("/usr/local/lib/python3.10/dist-packages/gnuradio/").resolve())
)
sys.path.append(str(Path("./_extensions").resolve()))

extensions = [
    "breathe",
    # "exhale",
    "gr_wiki_link",
    "sphinx.ext.autodoc",
    "sphinx.ext.autosummary",
    "sphinx_tabs.tabs",
]

templates_path = ["_templates"]
exclude_patterns = ["_build"]
autosummary_generate = False

# -- Options for HTML output -------------------------------------------------

base_url = "https://gnuradio.org/docs"

html_theme = "gr_sphinx_theme"
html_static_path = ["_static"]
html_theme_options = {
    "versions": {
        "stable": f"{base_url}/stable",
        "3.10.10.0": f"{base_url}/3.10.10.0",
        "3.10.10.0-rc1": f"{base_url}/3.10.10.0-rc1",
        "3.10.9.2": f"{base_url}/3.10.9.2",
        "3.9.7.0": f"{base_url}/3.9.7.0",
    },
}

# -- Options for Breath / Exhale (C++ documentation generation) --------------

this_file_dir = Path(__file__).parent.resolve()
doxygen_xml_dir = this_file_dir / "../build/xml"

breathe_projects = {"gnuradio": str(doxygen_xml_dir)}
breathe_default_project = "gnuradio"

exhale_args = {
    "containmentFolder": "./cpp_api",
    "rootFileName": "library_root.rst",
    "rootFileTitle": "C++ API",
    "doxygenStripFromPath": "../../",
    "createTreeView": True,
    "exhaleExecutesDoxygen": True,
    "exhaleUseDoxyfile": True,
    "minifyTreeView": False,  # Default is true and makes docutils complain and break
    "contentsTitle": "Page Contents",
    "kindsWithContentsDirectives": ["class", "file", "namespace", "struct"],
    "includeTemplateParamOrderList": True,
    "verboseBuild": True,
}


primary_domain = "cpp"
highlight_language = "cpp"


def setup(_):
    from breathe.renderer.sphinxrenderer import CMacroObject, DomainDirectiveFactory

    DomainDirectiveFactory.cpp_classes["property"] = (CMacroObject, "macro")
