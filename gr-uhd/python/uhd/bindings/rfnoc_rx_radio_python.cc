/*
 * Copyright 2024 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

/***********************************************************************************/
/* This file is automatically generated using bindtool and can be manually
 * edited  */
/* The following lines can be configured to regenerate this file during cmake */
/* If manual edits are made, the following tags should be modified accordingly.
 */
/* BINDTOOL_GEN_AUTOMATIC(0) */
/* BINDTOOL_USE_PYGCCXML(0) */
/* BINDTOOL_HEADER_FILE(rfnoc_rx_radio.h) */
/* BINDTOOL_HEADER_FILE_HASH(3eaa2fb52966de4e4a9ff93c94975101) */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/uhd/rfnoc_rx_radio.h>
// pydoc.h is automatically generated in the build directory
#include <rfnoc_rx_radio_pydoc.h>

void bind_rfnoc_rx_radio(py::module& m)
{

    using rfnoc_rx_radio = ::gr::uhd::rfnoc_rx_radio;

    py::class_<rfnoc_rx_radio,
               gr::uhd::rfnoc_block,
               gr::block,
               gr::basic_block,
               std::shared_ptr<rfnoc_rx_radio>>(m, "rfnoc_rx_radio", D(rfnoc_rx_radio))

        .def(py::init(&rfnoc_rx_radio::make),
             py::arg("graph"),
             py::arg("block_args"),
             py::arg("device_select"),
             py::arg("instance"),
             D(rfnoc_rx_radio, make))

        .def("set_rate",
             &rfnoc_rx_radio::set_rate,
             py::arg("rate"),
             D(rfnoc_rx_radio, set_rate))

        .def("set_antenna",
             &rfnoc_rx_radio::set_antenna,
             py::arg("antenna"),
             py::arg("chan"),
             D(rfnoc_rx_radio, set_antenna))

        .def("set_frequency",
             &rfnoc_rx_radio::set_frequency,
             py::arg("frequency"),
             py::arg("chan"),
             D(rfnoc_rx_radio, set_frequency))

        .def("set_tune_args",
             &rfnoc_rx_radio::set_tune_args,
             py::arg("args"),
             py::arg("chan"),
             D(rfnoc_rx_radio, set_tune_args))

        .def("set_gain",
             (double(rfnoc_rx_radio::*)(double const, size_t const)) &
                 rfnoc_rx_radio::set_gain,
             py::arg("gain"),
             py::arg("chan"),
             D(rfnoc_rx_radio, set_gain, 0))

        .def("set_gain",
             (double(rfnoc_rx_radio::*)(double const, std::string const&, size_t const)) &
                 rfnoc_rx_radio::set_gain,
             py::arg("gain"),
             py::arg("name"),
             py::arg("chan"),
             D(rfnoc_rx_radio, set_gain, 1))

        .def("set_agc",
             &rfnoc_rx_radio::set_agc,
             py::arg("enable"),
             py::arg("chan"),
             D(rfnoc_rx_radio, set_agc))

        .def("set_gain_profile",
             &rfnoc_rx_radio::set_gain_profile,
             py::arg("profile"),
             py::arg("chan"),
             D(rfnoc_rx_radio, set_gain_profile))

        .def("set_bandwidth",
             &rfnoc_rx_radio::set_bandwidth,
             py::arg("bandwidth"),
             py::arg("chan"),
             D(rfnoc_rx_radio, set_bandwidth))

        .def("set_lo_source",
             &rfnoc_rx_radio::set_lo_source,
             py::arg("source"),
             py::arg("name"),
             py::arg("chan"),
             D(rfnoc_rx_radio, set_lo_source))

        .def("set_lo_export_enabled",
             &rfnoc_rx_radio::set_lo_export_enabled,
             py::arg("enabled"),
             py::arg("name"),
             py::arg("chan"),
             D(rfnoc_rx_radio, set_lo_export_enabled))

        .def("set_lo_freq",
             &rfnoc_rx_radio::set_lo_freq,
             py::arg("freq"),
             py::arg("name"),
             py::arg("chan"),
             D(rfnoc_rx_radio, set_lo_freq))

        .def("set_dc_offset",
             (void(rfnoc_rx_radio::*)(bool const, size_t const)) &
                 rfnoc_rx_radio::set_dc_offset,
             py::arg("enable"),
             py::arg("chan"),
             D(rfnoc_rx_radio, set_dc_offset, 0))

        .def("set_dc_offset",
             (void(rfnoc_rx_radio::*)(std::complex<double> const&, size_t const)) &
                 rfnoc_rx_radio::set_dc_offset,
             py::arg("offset"),
             py::arg("chan"),
             D(rfnoc_rx_radio, set_dc_offset, 1))

        .def("set_iq_balance",
             (void(rfnoc_rx_radio::*)(bool const, size_t const)) &
                 rfnoc_rx_radio::set_iq_balance,
             py::arg("enable"),
             py::arg("chan"),
             D(rfnoc_rx_radio, set_iq_balance, 0))

        .def("set_iq_balance",
             (void(rfnoc_rx_radio::*)(std::complex<double> const&, size_t const)) &
                 rfnoc_rx_radio::set_iq_balance,
             py::arg("correction"),
             py::arg("chan"),
             D(rfnoc_rx_radio, set_iq_balance, 1))

        .def("issue_stream_cmd",
             &rfnoc_rx_radio::issue_stream_cmd,
             py::arg("cmd"),
             py::arg("chan"),
             D(rfnoc_rx_radio, issue_stream_cmd))

        .def("enable_rx_timestamps",
             &rfnoc_rx_radio::enable_rx_timestamps,
             py::arg("enable"),
             py::arg("chan"),
             D(rfnoc_rx_radio, enable_rx_timestamps))

        ;
}
