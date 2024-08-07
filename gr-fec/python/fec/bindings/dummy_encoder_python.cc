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
/* BINDTOOL_HEADER_FILE(dummy_encoder.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(1d9651622ef130c051bee232ad7a5be1)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/fec/dummy_encoder.h>
// pydoc.h is automatically generated in the build directory
#include <dummy_encoder_pydoc.h>

void bind_dummy_encoder(py::module& m)
{


    py::module m_code = m.def_submodule("code");

    using dummy_encoder = ::gr::fec::code::dummy_encoder;


    py::class_<dummy_encoder, gr::fec::generic_encoder, std::shared_ptr<dummy_encoder>>(
        m_code, "dummy_encoder", D(code, dummy_encoder))

        .def_static("make",
                    &dummy_encoder::make,
                    py::arg("frame_size"),
                    py::arg("pack") = false,
                    py::arg("packed_bits") = false,
                    D(code, dummy_encoder, make))


        .def("set_frame_size",
             &dummy_encoder::set_frame_size,
             py::arg("frame_size"),
             D(code, dummy_encoder, set_frame_size))


        .def("rate", &dummy_encoder::rate, D(code, dummy_encoder, rate))

        ;
}
