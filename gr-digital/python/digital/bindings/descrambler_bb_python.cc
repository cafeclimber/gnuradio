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
/* BINDTOOL_HEADER_FILE(descrambler_bb.h)                                          */
/* BINDTOOL_HEADER_FILE_HASH(d6459b219335b2d0d041e75284e69577)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/digital/descrambler_bb.h>
// pydoc.h is automatically generated in the build directory
#include <descrambler_bb_pydoc.h>

void bind_descrambler_bb(py::module& m)
{

    using descrambler_bb = ::gr::digital::descrambler_bb;


    py::class_<descrambler_bb,
               gr::sync_block,
               gr::block,
               gr::basic_block,
               std::shared_ptr<descrambler_bb>>(m, "descrambler_bb", D(descrambler_bb))

        .def(py::init(&descrambler_bb::make),
             py::arg("mask"),
             py::arg("seed"),
             py::arg("len"),
             D(descrambler_bb, make))


        ;
}
