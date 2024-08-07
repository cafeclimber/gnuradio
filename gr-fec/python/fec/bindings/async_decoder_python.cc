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
/* BINDTOOL_HEADER_FILE(async_decoder.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(32908df82b4560ceabb920e76c0d7781)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/fec/async_decoder.h>
// pydoc.h is automatically generated in the build directory
#include <async_decoder_pydoc.h>

void bind_async_decoder(py::module& m)
{

    using async_decoder = ::gr::fec::async_decoder;


    py::class_<async_decoder, gr::block, gr::basic_block, std::shared_ptr<async_decoder>>(
        m, "async_decoder", D(async_decoder))

        .def(py::init(&async_decoder::make),
             py::arg("my_decoder"),
             py::arg("packed") = false,
             py::arg("rev_pack") = true,
             py::arg("mtu") = 1500,
             D(async_decoder, make))


        .def("general_work",
             &async_decoder::general_work,
             py::arg("noutput_items"),
             py::arg("ninput_items"),
             py::arg("input_items"),
             py::arg("output_items"),
             D(async_decoder, general_work))

        ;
}
