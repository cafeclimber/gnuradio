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
/* BINDTOOL_HEADER_FILE(fmcomms2_source.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(90c04501a92c0bbb63282dd0fca7e435)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/iio/fmcomms2_source.h>
// pydoc.h is automatically generated in the build directory
#include <fmcomms2_source_pydoc.h>

template <typename T>
void bind_fmcomms2_source_template(py::module& m, const char* classname)
{

    using fmcomms2_source = gr::iio::fmcomms2_source<T>;


    py::class_<fmcomms2_source,
               gr::sync_block,
               gr::block,
               gr::basic_block,
               std::shared_ptr<fmcomms2_source>>(m, classname, D(fmcomms2_source))

        .def(py::init(&fmcomms2_source::make),
             py::arg("uri"),
             py::arg("ch_en"),
             py::arg("buffer_size"),
             D(fmcomms2_source, make))
        .def("set_frequency", &fmcomms2_source::set_frequency, py::arg("longfrequency"))
        .def("set_samplerate", &fmcomms2_source::set_samplerate, py::arg("samplerate"))
        .def("set_gain_mode",
             &fmcomms2_source::set_gain_mode,
             py::arg("chan"),
             py::arg("mode"))
        .def("set_gain",
             &fmcomms2_source::set_gain,
             py::arg("chan"),
             py::arg("gain_value"))
        .def("set_quadrature", &fmcomms2_source::set_quadrature, py::arg("quadrature"))
        .def("set_rfdc", &fmcomms2_source::set_rfdc, py::arg("rfdc"))
        .def("set_bbdc", &fmcomms2_source::set_bbdc, py::arg("bbdc"))
        .def("set_filter_params", &fmcomms2_source::set_filter_params)
        .def(
            "set_len_tag_key", &fmcomms2_source::set_len_tag_key, py::arg("len_tag_key"));
    ;
}

void bind_fmcomms2_source(py::module& m)
{
    bind_fmcomms2_source_template<int16_t>(m, "fmcomms2_source_s");
    bind_fmcomms2_source_template<std::complex<int16_t>>(m, "fmcomms2_source_sc16");
    bind_fmcomms2_source_template<gr_complex>(m, "fmcomms2_source_fc32");
}
