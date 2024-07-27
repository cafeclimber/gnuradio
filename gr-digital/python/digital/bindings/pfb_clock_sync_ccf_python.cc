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
/* BINDTOOL_HEADER_FILE(pfb_clock_sync_ccf.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(4fd8084ccdd90df6c34dd8ba5d98ac0b)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/digital/pfb_clock_sync_ccf.h>
// pydoc.h is automatically generated in the build directory
#include <pfb_clock_sync_ccf_pydoc.h>

void bind_pfb_clock_sync_ccf(py::module& m)
{

    using pfb_clock_sync_ccf = ::gr::digital::pfb_clock_sync_ccf;


    py::class_<pfb_clock_sync_ccf,
               gr::block,
               gr::basic_block,
               std::shared_ptr<pfb_clock_sync_ccf>>(
        m, "pfb_clock_sync_ccf", D(pfb_clock_sync_ccf))

        .def(py::init(&pfb_clock_sync_ccf::make),
             py::arg("sps"),
             py::arg("loop_bw"),
             py::arg("taps"),
             py::arg("filter_size") = 32,
             py::arg("init_phase") = 0,
             py::arg("max_rate_deviation") = 1.5,
             py::arg("osps") = 1,
             D(pfb_clock_sync_ccf, make))


        .def("update_gains",
             &pfb_clock_sync_ccf::update_gains,
             D(pfb_clock_sync_ccf, update_gains))


        .def("update_taps",
             &pfb_clock_sync_ccf::update_taps,
             py::arg("taps"),
             D(pfb_clock_sync_ccf, update_taps))


        .def("taps", &pfb_clock_sync_ccf::taps, D(pfb_clock_sync_ccf, taps))


        .def(
            "diff_taps", &pfb_clock_sync_ccf::diff_taps, D(pfb_clock_sync_ccf, diff_taps))


        .def("channel_taps",
             &pfb_clock_sync_ccf::channel_taps,
             py::arg("channel"),
             D(pfb_clock_sync_ccf, channel_taps))


        .def("diff_channel_taps",
             &pfb_clock_sync_ccf::diff_channel_taps,
             py::arg("channel"),
             D(pfb_clock_sync_ccf, diff_channel_taps))


        .def("taps_as_string",
             &pfb_clock_sync_ccf::taps_as_string,
             D(pfb_clock_sync_ccf, taps_as_string))


        .def("diff_taps_as_string",
             &pfb_clock_sync_ccf::diff_taps_as_string,
             D(pfb_clock_sync_ccf, diff_taps_as_string))


        .def("set_loop_bandwidth",
             &pfb_clock_sync_ccf::set_loop_bandwidth,
             py::arg("bw"),
             D(pfb_clock_sync_ccf, set_loop_bandwidth))


        .def("set_damping_factor",
             &pfb_clock_sync_ccf::set_damping_factor,
             py::arg("df"),
             D(pfb_clock_sync_ccf, set_damping_factor))


        .def("set_alpha",
             &pfb_clock_sync_ccf::set_alpha,
             py::arg("alpha"),
             D(pfb_clock_sync_ccf, set_alpha))


        .def("set_beta",
             &pfb_clock_sync_ccf::set_beta,
             py::arg("beta"),
             D(pfb_clock_sync_ccf, set_beta))


        .def("set_max_rate_deviation",
             &pfb_clock_sync_ccf::set_max_rate_deviation,
             py::arg("m"),
             D(pfb_clock_sync_ccf, set_max_rate_deviation))


        .def("loop_bandwidth",
             &pfb_clock_sync_ccf::loop_bandwidth,
             D(pfb_clock_sync_ccf, loop_bandwidth))


        .def("damping_factor",
             &pfb_clock_sync_ccf::damping_factor,
             D(pfb_clock_sync_ccf, damping_factor))


        .def("alpha", &pfb_clock_sync_ccf::alpha, D(pfb_clock_sync_ccf, alpha))


        .def("beta", &pfb_clock_sync_ccf::beta, D(pfb_clock_sync_ccf, beta))


        .def("clock_rate",
             &pfb_clock_sync_ccf::clock_rate,
             D(pfb_clock_sync_ccf, clock_rate))


        .def("error", &pfb_clock_sync_ccf::error, D(pfb_clock_sync_ccf, error))


        .def("rate", &pfb_clock_sync_ccf::rate, D(pfb_clock_sync_ccf, rate))


        .def("phase", &pfb_clock_sync_ccf::phase, D(pfb_clock_sync_ccf, phase))

        ;
}
