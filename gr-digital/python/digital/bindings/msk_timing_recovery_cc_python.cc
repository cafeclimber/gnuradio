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
/* BINDTOOL_HEADER_FILE(msk_timing_recovery_cc.h) */
/* BINDTOOL_HEADER_FILE_HASH(e6c619a716ad48e3f9dc699ce9332cd1)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/digital/msk_timing_recovery_cc.h>
// pydoc.h is automatically generated in the build directory
#include <msk_timing_recovery_cc_pydoc.h>

void bind_msk_timing_recovery_cc(py::module& m)
{

    using msk_timing_recovery_cc = ::gr::digital::msk_timing_recovery_cc;


    py::class_<msk_timing_recovery_cc,
               gr::block,
               gr::basic_block,
               std::shared_ptr<msk_timing_recovery_cc>>(
        m, "msk_timing_recovery_cc", D(msk_timing_recovery_cc))

        .def(py::init(&msk_timing_recovery_cc::make),
             py::arg("sps"),
             py::arg("gain"),
             py::arg("limit"),
             py::arg("osps"),
             D(msk_timing_recovery_cc, make))


        .def("set_gain",
             &msk_timing_recovery_cc::set_gain,
             py::arg("gain"),
             D(msk_timing_recovery_cc, set_gain))


        .def("get_gain",
             &msk_timing_recovery_cc::get_gain,
             D(msk_timing_recovery_cc, get_gain))


        .def("set_limit",
             &msk_timing_recovery_cc::set_limit,
             py::arg("limit"),
             D(msk_timing_recovery_cc, set_limit))


        .def("get_limit",
             &msk_timing_recovery_cc::get_limit,
             D(msk_timing_recovery_cc, get_limit))


        .def("set_sps",
             &msk_timing_recovery_cc::set_sps,
             py::arg("sps"),
             D(msk_timing_recovery_cc, set_sps))


        .def("get_sps",
             &msk_timing_recovery_cc::get_sps,
             D(msk_timing_recovery_cc, get_sps))

        ;
}
