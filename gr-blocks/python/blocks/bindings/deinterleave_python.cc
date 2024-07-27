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
/* BINDTOOL_HEADER_FILE(deinterleave.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(fcaf101f0dde823aa682b39599e6856d)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/blocks/deinterleave.h>
// pydoc.h is automatically generated in the build directory
#include <deinterleave_pydoc.h>

void bind_deinterleave(py::module& m)
{

    using deinterleave = ::gr::blocks::deinterleave;


    py::class_<deinterleave, gr::block, gr::basic_block, std::shared_ptr<deinterleave>>(
        m, "deinterleave", D(deinterleave))

        .def(py::init(&deinterleave::make),
             py::arg("itemsize"),
             py::arg("blocksize") = 1,
             D(deinterleave, make))


        ;
}
