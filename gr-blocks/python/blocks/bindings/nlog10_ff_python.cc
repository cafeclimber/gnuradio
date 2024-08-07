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
/* BINDTOOL_HEADER_FILE(nlog10_ff.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(a85a6131e6efa399128ff18d7782a930)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/blocks/nlog10_ff.h>
// pydoc.h is automatically generated in the build directory
#include <nlog10_ff_pydoc.h>

void bind_nlog10_ff(py::module& m)
{

    using nlog10_ff = ::gr::blocks::nlog10_ff;


    py::class_<nlog10_ff,
               gr::sync_block,
               gr::block,
               gr::basic_block,
               std::shared_ptr<nlog10_ff>>(m, "nlog10_ff", D(nlog10_ff))

        .def(py::init(&nlog10_ff::make),
             py::arg("n") = 1.,
             py::arg("vlen") = 1,
             py::arg("k") = 0.,
             D(nlog10_ff, make))


        ;
}
