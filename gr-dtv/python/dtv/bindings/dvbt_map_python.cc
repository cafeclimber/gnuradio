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
/* BINDTOOL_HEADER_FILE(dvbt_map.h)                                                */
/* BINDTOOL_HEADER_FILE_HASH(a54cf17f181e3ba59e643c77bfd14d14)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/dtv/dvbt_map.h>
// pydoc.h is automatically generated in the build directory
#include <dvbt_map_pydoc.h>

void bind_dvbt_map(py::module& m)
{

    using dvbt_map = ::gr::dtv::dvbt_map;


    py::class_<dvbt_map, gr::block, gr::basic_block, std::shared_ptr<dvbt_map>>(
        m, "dvbt_map", D(dvbt_map))

        .def(py::init(&dvbt_map::make),
             py::arg("nsize"),
             py::arg("constellation"),
             py::arg("hierarchy"),
             py::arg("transmission"),
             py::arg("gain"),
             D(dvbt_map, make))


        ;
}
