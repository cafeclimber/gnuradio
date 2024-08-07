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
/* BINDTOOL_HEADER_FILE(rail_ff.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(1e594d0fce4408729d2fc5d0c767000e)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/analog/rail_ff.h>
// pydoc.h is automatically generated in the build directory
#include <rail_ff_pydoc.h>

void bind_rail_ff(py::module& m)
{

    using rail_ff = ::gr::analog::rail_ff;


    py::class_<rail_ff,
               gr::sync_block,
               gr::block,
               gr::basic_block,
               std::shared_ptr<rail_ff>>(m, "rail_ff", D(rail_ff))

        .def(py::init(&rail_ff::make), py::arg("lo"), py::arg("hi"), D(rail_ff, make))


        .def("lo", &rail_ff::lo, D(rail_ff, lo))


        .def("hi", &rail_ff::hi, D(rail_ff, hi))


        .def("set_lo", &rail_ff::set_lo, py::arg("lo"), D(rail_ff, set_lo))


        .def("set_hi", &rail_ff::set_hi, py::arg("hi"), D(rail_ff, set_hi))

        ;
}
