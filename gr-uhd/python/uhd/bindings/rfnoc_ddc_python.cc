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
/* BINDTOOL_HEADER_FILE(rfnoc_ddc.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(0f463a360d2ee5f3a46f1780da674153)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/uhd/rfnoc_ddc.h>
// pydoc.h is automatically generated in the build directory
#include <rfnoc_ddc_pydoc.h>

void bind_rfnoc_ddc(py::module& m)
{

    using rfnoc_ddc = ::gr::uhd::rfnoc_ddc;


    py::class_<rfnoc_ddc,
               gr::uhd::rfnoc_block,
               gr::block,
               gr::basic_block,
               std::shared_ptr<rfnoc_ddc>>(m, "rfnoc_ddc", D(rfnoc_ddc))

        .def(py::init(&rfnoc_ddc::make),
             py::arg("graph"),
             py::arg("block_args"),
             py::arg("device_select"),
             py::arg("instance"),
             D(rfnoc_ddc, make))


        .def("set_freq",
             &rfnoc_ddc::set_freq,
             py::arg("freq"),
             py::arg("chan"),
             py::arg("time") = uhd::time_spec_t::ASAP,
             D(rfnoc_ddc, set_freq))


        .def("set_output_rate",
             &rfnoc_ddc::set_output_rate,
             py::arg("rate"),
             py::arg("chan"),
             D(rfnoc_ddc, set_output_rate))

        ;
}
