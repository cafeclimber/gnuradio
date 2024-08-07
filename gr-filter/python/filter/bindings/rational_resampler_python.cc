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
/* BINDTOOL_HEADER_FILE(rational_resampler.h) */
/* BINDTOOL_HEADER_FILE_HASH(1e4bc366c6308dc3d737dad78413a8f3)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/filter/rational_resampler.h>

template <class IN_T, class OUT_T, class TAP_T>
void bind_rational_resampler_template(py::module& m, const char* classname)
{
    using rational_resampler = gr::filter::rational_resampler<IN_T, OUT_T, TAP_T>;

    py::class_<rational_resampler,
               gr::block,
               gr::basic_block,
               std::shared_ptr<rational_resampler>>(m, classname)
        .def(py::init(&gr::filter::rational_resampler<IN_T, OUT_T, TAP_T>::make),
             py::arg("interpolation"),
             py::arg("decimation"),
             py::arg("taps") = std::vector<TAP_T>(),
             py::arg("fractional_bw") = 0.0)

        .def("set_taps", &rational_resampler::set_taps, py::arg("taps"))
        .def("taps", &rational_resampler::taps)
        .def("interpolation", &rational_resampler::interpolation)
        .def("decimation", &rational_resampler::decimation);
}

void bind_rational_resampler(py::module& m)
{
    bind_rational_resampler_template<gr_complex, gr_complex, gr_complex>(
        m, "rational_resampler_ccc");
    bind_rational_resampler_template<gr_complex, gr_complex, float>(
        m, "rational_resampler_ccf");
    bind_rational_resampler_template<float, gr_complex, gr_complex>(
        m, "rational_resampler_fcc");
    bind_rational_resampler_template<float, float, float>(m, "rational_resampler_fff");
    bind_rational_resampler_template<float, std::int16_t, float>(
        m, "rational_resampler_fsf");
    bind_rational_resampler_template<std::int16_t, gr_complex, gr_complex>(
        m, "rational_resampler_scc");
}
