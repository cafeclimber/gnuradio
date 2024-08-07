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
/* BINDTOOL_HEADER_FILE(dvbt_energy_descramble.h)                                  */
/* BINDTOOL_HEADER_FILE_HASH(d0730e0b3f583bd330165e7c0ec3776a)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/dtv/dvbt_energy_descramble.h>
// pydoc.h is automatically generated in the build directory
#include <dvbt_energy_descramble_pydoc.h>

void bind_dvbt_energy_descramble(py::module& m)
{

    using dvbt_energy_descramble = ::gr::dtv::dvbt_energy_descramble;


    py::class_<dvbt_energy_descramble,
               gr::block,
               gr::basic_block,
               std::shared_ptr<dvbt_energy_descramble>>(
        m, "dvbt_energy_descramble", D(dvbt_energy_descramble))

        .def(py::init(&dvbt_energy_descramble::make),
             py::arg("nblocks"),
             D(dvbt_energy_descramble, make))


        ;
}
