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
/* BINDTOOL_HEADER_FILE(not_blk.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(ab19592281e539de3f72f11d11738218)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/blocks/not_blk.h>

template <typename T>
void bind_not_template(py::module& m, const char* classname)
{
    using not_blk = gr::blocks::not_blk<T>;

    py::class_<not_blk,
               gr::sync_block,
               gr::block,
               gr::basic_block,
               std::shared_ptr<not_blk>>(m, classname)
        .def(py::init(&gr::blocks::not_blk<T>::make), py::arg("vlen") = 1);
}

void bind_not_blk(py::module& m)
{
    bind_not_template<std::uint8_t>(m, "not_bb");
    bind_not_template<std::int16_t>(m, "not_ss");
    bind_not_template<std::int32_t>(m, "not_ii");
}
