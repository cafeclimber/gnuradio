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
/* BINDTOOL_HEADER_FILE(fmdet_cf.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(595067477630007f7f39bb888463a5ff)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/analog/fmdet_cf.h>
// pydoc.h is automatically generated in the build directory
#include <fmdet_cf_pydoc.h>

void bind_fmdet_cf(py::module& m)
{

    using fmdet_cf = ::gr::analog::fmdet_cf;


    py::class_<fmdet_cf,
               gr::sync_block,
               gr::block,
               gr::basic_block,
               std::shared_ptr<fmdet_cf>>(m, "fmdet_cf", D(fmdet_cf))

        .def(py::init(&fmdet_cf::make),
             py::arg("samplerate"),
             py::arg("freq_low"),
             py::arg("freq_high"),
             py::arg("scl"),
             D(fmdet_cf, make))


        .def("set_scale", &fmdet_cf::set_scale, py::arg("scl"), D(fmdet_cf, set_scale))


        .def("set_freq_range",
             &fmdet_cf::set_freq_range,
             py::arg("freq_low"),
             py::arg("freq_high"),
             D(fmdet_cf, set_freq_range))


        .def("freq", &fmdet_cf::freq, D(fmdet_cf, freq))


        .def("freq_high", &fmdet_cf::freq_high, D(fmdet_cf, freq_high))


        .def("freq_low", &fmdet_cf::freq_low, D(fmdet_cf, freq_low))


        .def("scale", &fmdet_cf::scale, D(fmdet_cf, scale))


        .def("bias", &fmdet_cf::bias, D(fmdet_cf, bias))

        ;
}
