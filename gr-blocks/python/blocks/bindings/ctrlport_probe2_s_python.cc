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
/* BINDTOOL_HEADER_FILE(ctrlport_probe2_s.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(fa594d080c6bedf14819d7a378e55e2e)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/blocks/ctrlport_probe2_s.h>
// pydoc.h is automatically generated in the build directory
#include <ctrlport_probe2_s_pydoc.h>

void bind_ctrlport_probe2_s(py::module& m)
{

    using ctrlport_probe2_s = ::gr::blocks::ctrlport_probe2_s;


    py::class_<ctrlport_probe2_s,
               gr::sync_block,
               gr::block,
               gr::basic_block,
               std::shared_ptr<ctrlport_probe2_s>>(
        m, "ctrlport_probe2_s", D(ctrlport_probe2_s))

        .def(py::init(&ctrlport_probe2_s::make),
             py::arg("id"),
             py::arg("desc"),
             py::arg("len"),
             py::arg("disp_mask"),
             D(ctrlport_probe2_s, make))


        .def("get", &ctrlport_probe2_s::get, D(ctrlport_probe2_s, get))


        .def("set_length",
             &ctrlport_probe2_s::set_length,
             py::arg("len"),
             D(ctrlport_probe2_s, set_length))

        ;
}
