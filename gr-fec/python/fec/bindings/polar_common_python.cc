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
/* BINDTOOL_HEADER_FILE(polar_common.h)                                            */
/* BINDTOOL_HEADER_FILE_HASH(260a056f1558c510b45dfdfcac558667)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/fec/polar_common.h>
// pydoc.h is automatically generated in the build directory
#include <polar_common_pydoc.h>

void bind_polar_common(py::module& m)
{


    py::module m_code = m.def_submodule("code");

    using polar_common = ::gr::fec::code::polar_common;


    py::class_<polar_common, std::shared_ptr<polar_common>>(
        m_code, "polar_common", D(code, polar_common))

        .def(py::init<int,
                      int,
                      std::vector<int, std::allocator<int>>,
                      std::vector<uint8_t, std::allocator<uint8_t>>>(),
             py::arg("block_size"),
             py::arg("num_info_bits"),
             py::arg("frozen_bit_positions"),
             py::arg("frozen_bit_values"),
             D(code, polar_common, polar_common, 0))
        .def(py::init<gr::fec::code::polar_common const&>(),
             py::arg("arg0"),
             D(code, polar_common, polar_common, 1))

        ;
}
