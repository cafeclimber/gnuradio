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
/* BINDTOOL_HEADER_FILE(cc_encoder.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(a7b4cda4c3724547c452db7d8d3b8e90)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/fec/cc_encoder.h>
// pydoc.h is automatically generated in the build directory
#include <cc_encoder_pydoc.h>

void bind_cc_encoder(py::module& m)
{
    py::module m_code = m.def_submodule("code");

    using cc_encoder = ::gr::fec::code::cc_encoder;

    py::class_<cc_encoder, gr::fec::generic_encoder, std::shared_ptr<cc_encoder>>(
        m_code, "cc_encoder", D(code, cc_encoder))

        .def_static("make",
                    &cc_encoder::make,
                    py::arg("frame_size"),
                    py::arg("k"),
                    py::arg("rate"),
                    py::arg("polys"),
                    py::arg("start_state") = 0,
                    py::arg("mode") = ::_cc_mode_t::CC_STREAMING,
                    py::arg("padded") = false,
                    D(code, cc_encoder, make))

        .def("set_frame_size",
             &cc_encoder::set_frame_size,
             py::arg("frame_size"),
             D(code, cc_encoder, set_frame_size))

        .def("rate", &cc_encoder::rate, D(code, cc_encoder, rate))

        ;
}
