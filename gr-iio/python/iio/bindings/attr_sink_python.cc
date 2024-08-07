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
/* BINDTOOL_HEADER_FILE(attr_sink.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(f9181716255e7d7dcdb2ee5e349012d7)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/iio/attr_sink.h>
// pydoc.h is automatically generated in the build directory
#include <attr_sink_pydoc.h>

void bind_attr_sink(py::module& m)
{

    using attr_sink = gr::iio::attr_sink;


    py::class_<attr_sink, gr::block, gr::basic_block, std::shared_ptr<attr_sink>>(
        m, "attr_sink", D(attr_sink))

        .def(py::init(&attr_sink::make),
             py::arg("uri"),
             py::arg("device"),
             py::arg("channel"),
             py::arg("type"),
             py::arg("output"),
             D(attr_sink, make))

        ;
}
