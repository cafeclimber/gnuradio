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
/* BINDTOOL_HEADER_FILE(correctiq_man.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(97a71360f1cdb9d80d7ec89263171995)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/blocks/correctiq_man.h>
// pydoc.h is automatically generated in the build directory
#include <correctiq_man_pydoc.h>

void bind_correctiq_man(py::module& m)
{

    using correctiq_man = ::gr::blocks::correctiq_man;


    py::class_<correctiq_man,
               gr::sync_block,
               gr::block,
               gr::basic_block,
               std::shared_ptr<correctiq_man>>(m, "correctiq_man", D(correctiq_man))

        .def(py::init(&correctiq_man::make),
             py::arg("real"),
             py::arg("imag"),
             D(correctiq_man, make))


        .def("get_real", &correctiq_man::get_real, D(correctiq_man, get_real))


        .def("get_imag", &correctiq_man::get_imag, D(correctiq_man, get_imag))


        .def("set_real",
             &correctiq_man::set_real,
             py::arg("newValue"),
             D(correctiq_man, set_real))


        .def("set_imag",
             &correctiq_man::set_imag,
             py::arg("newValue"),
             D(correctiq_man, set_imag))


        ;
}
