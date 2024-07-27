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
/* BINDTOOL_HEADER_FILE(decision_feedback_equalizer.h) */
/* BINDTOOL_HEADER_FILE_HASH(2ecb0454515d1319c7ea0c2e8f965069)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/digital/decision_feedback_equalizer.h>
// pydoc.h is automatically generated in the build directory
#include <decision_feedback_equalizer_pydoc.h>

void bind_decision_feedback_equalizer(py::module& m)
{

    using decision_feedback_equalizer = ::gr::digital::decision_feedback_equalizer;


    py::class_<decision_feedback_equalizer,
               gr::sync_decimator,
               std::shared_ptr<decision_feedback_equalizer>>(
        m, "decision_feedback_equalizer", D(decision_feedback_equalizer))

        .def(py::init(&decision_feedback_equalizer::make),
             py::arg("num_taps_forward"),
             py::arg("num_taps_feedback"),
             py::arg("sps"),
             py::arg("alg"),
             py::arg("adapt_after_training") = true,
             py::arg("training_sequence") = std::vector<gr_complex>(),
             py::arg("training_start_tag") = "",
             D(decision_feedback_equalizer, make))


        .def("set_taps",
             &decision_feedback_equalizer::set_taps,
             py::arg("taps"),
             D(decision_feedback_equalizer, set_taps))


        .def("taps",
             &decision_feedback_equalizer::taps,
             D(decision_feedback_equalizer, taps))


        .def("equalize",
             &decision_feedback_equalizer::equalize,
             py::arg("input_samples"),
             py::arg("output_symbols"),
             py::arg("num_inputs"),
             py::arg("max_num_outputs"),
             py::arg("training_start_samples") = std::vector<unsigned int>(0),
             py::arg("history_included") = false,
             py::arg("taps") = nullptr,
             py::arg("state") = nullptr,
             D(decision_feedback_equalizer, equalize))

        ;
}
