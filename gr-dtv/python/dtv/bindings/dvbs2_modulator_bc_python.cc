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
/* BINDTOOL_GEN_AUTOMATIC(1)                                                       */
/* BINDTOOL_USE_PYGCCXML(0)                                                        */
/* BINDTOOL_HEADER_FILE(dvbs2_modulator_bc.h)                                      */
/* BINDTOOL_HEADER_FILE_HASH(6e030d3b0dc4cac6a9e4465854ee8aad)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/dtv/dvbs2_modulator_bc.h>
// pydoc.h is automatically generated in the build directory
#include <dvbs2_modulator_bc_pydoc.h>

void bind_dvbs2_modulator_bc(py::module& m)
{

    using dvbs2_modulator_bc = ::gr::dtv::dvbs2_modulator_bc;


    py::class_<dvbs2_modulator_bc,
               gr::block,
               gr::basic_block,
               std::shared_ptr<dvbs2_modulator_bc>>(
        m, "dvbs2_modulator_bc", D(dvbs2_modulator_bc))

        .def(py::init(&dvbs2_modulator_bc::make),
             py::arg("framesize"),
             py::arg("rate"),
             py::arg("constellation"),
             py::arg("interpolation"),
             D(dvbs2_modulator_bc, make))


        ;
}
