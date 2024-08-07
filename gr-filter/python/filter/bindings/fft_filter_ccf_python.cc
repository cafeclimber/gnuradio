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
/* BINDTOOL_HEADER_FILE(fft_filter_ccf.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(0b2c0981b542a2fec30ffa8243a1af22)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/filter/fft_filter_ccf.h>
// pydoc.h is automatically generated in the build directory
#include <fft_filter_ccf_pydoc.h>

void bind_fft_filter_ccf(py::module& m)
{
    using fft_filter_ccf = gr::filter::fft_filter_ccf;


    py::class_<fft_filter_ccf,
               gr::sync_decimator,
               gr::sync_block,
               gr::block,
               gr::basic_block,
               std::shared_ptr<fft_filter_ccf>>(m, "fft_filter_ccf", D(fft_filter_ccf))

        .def(py::init(&fft_filter_ccf::make),
             py::arg("decimation"),
             py::arg("taps"),
             py::arg("nthreads") = 1,
             D(fft_filter_ccf, make))


        .def("set_taps",
             &fft_filter_ccf::set_taps,
             py::arg("taps"),
             D(fft_filter_ccf, set_taps))


        .def("taps", &fft_filter_ccf::taps, D(fft_filter_ccf, taps))


        .def("set_nthreads",
             &fft_filter_ccf::set_nthreads,
             py::arg("n"),
             D(fft_filter_ccf, set_nthreads))


        .def("nthreads", &fft_filter_ccf::nthreads, D(fft_filter_ccf, nthreads))

        ;
}
