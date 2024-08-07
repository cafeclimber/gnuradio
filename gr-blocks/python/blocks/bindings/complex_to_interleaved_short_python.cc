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
/* BINDTOOL_HEADER_FILE(complex_to_interleaved_short.h) */
/* BINDTOOL_HEADER_FILE_HASH(28daa7d618eadb8becd35bf9753a16fc)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/blocks/complex_to_interleaved_short.h>
// pydoc.h is automatically generated in the build directory
#include <complex_to_interleaved_short_pydoc.h>

void bind_complex_to_interleaved_short(py::module& m)
{

    using complex_to_interleaved_short = ::gr::blocks::complex_to_interleaved_short;


    py::class_<complex_to_interleaved_short,
               gr::sync_interpolator,
               gr::sync_block,
               gr::block,
               gr::basic_block,
               std::shared_ptr<complex_to_interleaved_short>>(
        m, "complex_to_interleaved_short", D(complex_to_interleaved_short))

        .def(py::init(&complex_to_interleaved_short::make),
             py::arg("vector") = false,
             py::arg("scale_factor") = 1.F,
             D(complex_to_interleaved_short, make))


        .def("set_scale_factor",
             &complex_to_interleaved_short::set_scale_factor,
             py::arg("new_value"),
             D(complex_to_interleaved_short, set_scale_factor))

        ;
}
