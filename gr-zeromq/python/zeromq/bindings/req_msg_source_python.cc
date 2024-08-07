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
/* BINDTOOL_HEADER_FILE(req_msg_source.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(e0e68f5fee2adba88e71f29d157933df)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/zeromq/req_msg_source.h>
// pydoc.h is automatically generated in the build directory
#include <req_msg_source_pydoc.h>

void bind_req_msg_source(py::module& m)
{

    using req_msg_source = ::gr::zeromq::req_msg_source;


    py::class_<req_msg_source,
               gr::block,
               gr::basic_block,
               std::shared_ptr<req_msg_source>>(m, "req_msg_source", D(req_msg_source))

        .def(py::init(&req_msg_source::make),
             py::arg("address"),
             py::arg("timeout") = 100,
             py::arg("bind") = false,
             D(req_msg_source, make))


        .def("last_endpoint",
             &req_msg_source::last_endpoint,
             D(req_msg_source, last_endpoint))

        ;
}
