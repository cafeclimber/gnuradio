/*
 * Copyright 2020 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

/***********************************************************************************/
/* This file is automatically generated using bindtool and can be manually edited  */
/* The following lines can be configured to regenerate this file during cmake      */
/* If manual edits are made, the following tags should be modified accordingly.    */
/* BINDTOOL_GEN_AUTOMATIC(0)                                                       */
/* BINDTOOL_USE_PYGCCXML(0)                                                        */
/* BINDTOOL_HEADER_FILE(and_blk.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(1a9d1759cd3ef02dcfa3521494600ad3)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/blocks/and_blk.h>

template <typename T>
void bind_and_blk_template(py::module& m, const char* classname)
{
    using and_blk = gr::blocks::and_blk<T>;

    py::class_<and_blk,
               gr::sync_block,
               gr::block,
               gr::basic_block,
               std::shared_ptr<and_blk>>(m, classname)
        .def(py::init(&gr::blocks::and_blk<T>::make), py::arg("vlen") = 1);
}

void bind_and_blk(py::module& m)
{
    bind_and_blk_template<std::uint8_t>(m, "and_bb");
    bind_and_blk_template<std::int16_t>(m, "and_ss");
    bind_and_blk_template<std::int32_t>(m, "and_ii");
}
