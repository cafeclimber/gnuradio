/*
 * Copyright 2021 Free Software Foundation, Inc.
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
/* BINDTOOL_HEADER_FILE(tagged_stream_to_pdu.h)                                    */
/* BINDTOOL_HEADER_FILE_HASH(379bc821d6bf8968805bb7281cfe0765)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/pdu/tagged_stream_to_pdu.h>
// pydoc.h is automatically generated in the build directory
#include <tagged_stream_to_pdu_pydoc.h>

void bind_tagged_stream_to_pdu(py::module& m)
{

    using tagged_stream_to_pdu = ::gr::pdu::tagged_stream_to_pdu;


    py::class_<tagged_stream_to_pdu,
               gr::tagged_stream_block,
               gr::block,
               gr::basic_block,
               std::shared_ptr<tagged_stream_to_pdu>>(
        m, "tagged_stream_to_pdu", D(tagged_stream_to_pdu))

        .def(py::init(&tagged_stream_to_pdu::make),
             py::arg("type"),
             py::arg("lengthtagname") = "packet_len",
             D(tagged_stream_to_pdu, make))


        ;
}
