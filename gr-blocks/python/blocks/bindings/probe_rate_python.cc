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
/* BINDTOOL_HEADER_FILE(probe_rate.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(2519d5da64e4dc744cbd4c8370aadf01)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/blocks/probe_rate.h>
// pydoc.h is automatically generated in the build directory
#include <probe_rate_pydoc.h>

void bind_probe_rate(py::module& m)
{

    using probe_rate = ::gr::blocks::probe_rate;


    py::class_<probe_rate,
               gr::sync_block,
               gr::block,
               gr::basic_block,
               std::shared_ptr<probe_rate>>(m, "probe_rate", D(probe_rate))

        .def(py::init(&probe_rate::make),
             py::arg("itemsize"),
             py::arg("update_rate_ms") = 500.,
             py::arg("alpha") = 1.0E-4,
             py::arg("name") = "",
             D(probe_rate, make))


        .def("set_alpha",
             &probe_rate::set_alpha,
             py::arg("alpha"),
             D(probe_rate, set_alpha))

        .def("set_name", &probe_rate::set_name, py::arg("name"), D(probe_rate, set_name))


        .def("rate", &probe_rate::rate, D(probe_rate, rate))


        .def("start", &probe_rate::start, D(probe_rate, start))


        .def("stop", &probe_rate::stop, D(probe_rate, stop))

        ;
}
