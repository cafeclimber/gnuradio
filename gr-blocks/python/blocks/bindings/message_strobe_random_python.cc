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
/* BINDTOOL_HEADER_FILE(message_strobe_random.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(e4b35af4d4d9398b3ba8a438f7807bdc)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/blocks/message_strobe_random.h>
// pydoc.h is automatically generated in the build directory
#include <message_strobe_random_pydoc.h>

void bind_message_strobe_random(py::module& m)
{

    using message_strobe_random = ::gr::blocks::message_strobe_random;


    py::class_<message_strobe_random,
               gr::block,
               gr::basic_block,
               std::shared_ptr<message_strobe_random>>(
        m, "message_strobe_random", D(message_strobe_random))

        .def(py::init(&message_strobe_random::make),
             py::arg("msg"),
             py::arg("dist"),
             py::arg("mean_ms"),
             py::arg("std_ms"),
             D(message_strobe_random, make))


        .def("set_msg",
             &message_strobe_random::set_msg,
             py::arg("msg"),
             D(message_strobe_random, set_msg))


        .def("msg", &message_strobe_random::msg, D(message_strobe_random, msg))


        .def("set_dist",
             &message_strobe_random::set_dist,
             py::arg("dist"),
             D(message_strobe_random, set_dist))


        .def("dist", &message_strobe_random::dist, D(message_strobe_random, dist))


        .def("set_mean",
             &message_strobe_random::set_mean,
             py::arg("mean"),
             D(message_strobe_random, set_mean))


        .def("mean", &message_strobe_random::mean, D(message_strobe_random, mean))


        .def("set_std",
             &message_strobe_random::set_std,
             py::arg("std"),
             D(message_strobe_random, set_std))


        .def("std", &message_strobe_random::std, D(message_strobe_random, std))

        ;

    py::enum_<::gr::blocks::message_strobe_random_distribution_t>(
        m, "message_strobe_random_distribution_t")
        .value("STROBE_POISSON", ::gr::blocks::STROBE_POISSON)         // 1
        .value("STROBE_GAUSSIAN", ::gr::blocks::STROBE_GAUSSIAN)       // 2
        .value("STROBE_UNIFORM", ::gr::blocks::STROBE_UNIFORM)         // 3
        .value("STROBE_EXPONENTIAL", ::gr::blocks::STROBE_EXPONENTIAL) // 4
        .export_values();

    py::implicitly_convertible<int, ::gr::blocks::message_strobe_random_distribution_t>();
}
