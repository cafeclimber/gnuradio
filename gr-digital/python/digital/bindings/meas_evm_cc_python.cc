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
/* BINDTOOL_HEADER_FILE(meas_evm_cc.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(499557b6dde2f087e19b0f3b104a392f)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/digital/meas_evm_cc.h>
// pydoc.h is automatically generated in the build directory
#include <meas_evm_cc_pydoc.h>

void bind_meas_evm_cc(py::module& m)
{

    using meas_evm_cc = ::gr::digital::meas_evm_cc;

    py::enum_<::gr::digital::evm_measurement_t>(m, "evm_measurement_t")
        .value("EVM_PERCENT", ::gr::digital::evm_measurement_t::EVM_PERCENT) // 0
        .value("EVM_DB", ::gr::digital::evm_measurement_t::EVM_DB)           // 1
        .export_values();

    py::implicitly_convertible<int, ::gr::digital::evm_measurement_t>();

    py::class_<meas_evm_cc,
               gr::sync_block,
               gr::block,
               gr::basic_block,
               std::shared_ptr<meas_evm_cc>>(m, "meas_evm_cc", D(meas_evm_cc))

        .def(py::init(&meas_evm_cc::make),
             py::arg("cons"),
             py::arg("meas_type") = ::gr::digital::evm_measurement_t::EVM_PERCENT,
             D(meas_evm_cc, make))


        ;
}
