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
/* BINDTOOL_HEADER_FILE(multiply.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(2dfd9a46bc68db58075877b81e919402)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/blocks/multiply.h>

template <typename T>
void bind_multiply_template(py::module& m, const char* classname)
{
    using multiply = gr::blocks::multiply<T>;

    py::class_<multiply,
               gr::sync_block,
               gr::block,
               gr::basic_block,
               std::shared_ptr<multiply>>(m, classname)
        .def(py::init(&gr::blocks::multiply<T>::make), py::arg("vlen") = 1);
}

void bind_multiply(py::module& m)
{
    bind_multiply_template<std::int16_t>(m, "multiply_ss");
    bind_multiply_template<std::int32_t>(m, "multiply_ii");
    bind_multiply_template<float>(m, "multiply_ff");
    bind_multiply_template<gr_complex>(m, "multiply_cc");
}
