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
/* BINDTOOL_HEADER_FILE(header_format_counter.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(55b7bbd7022c623545be3f0ca234a504)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/digital/header_format_counter.h>
// pydoc.h is automatically generated in the build directory
#include <header_format_counter_pydoc.h>

void bind_header_format_counter(py::module& m)
{

    using header_format_counter = ::gr::digital::header_format_counter;

    py::class_<header_format_counter,
               gr::digital::header_format_default,
               std::shared_ptr<header_format_counter>>(
        m, "header_format_counter", D(header_format_counter))

        // The make function returns a _base pointer, which is incompatible according to
        // pybind11
        .def(py::init(&header_format_counter::make),
             py::arg("access_code"),
             py::arg("threshold"),
             py::arg("bps"),
             D(header_format_counter, make))

        .def_static("make",
                    &header_format_counter::make,
                    py::arg("access_code"),
                    py::arg("threshold"),
                    py::arg("bps"),
                    D(header_format_counter, make))


        .def("format",
             &header_format_counter::format,
             py::arg("nbytes_in"),
             py::arg("input"),
             py::arg("output"),
             py::arg("info"),
             D(header_format_counter, format))


        .def("header_nbits",
             &header_format_counter::header_nbits,
             D(header_format_counter, header_nbits))


        ;
}
