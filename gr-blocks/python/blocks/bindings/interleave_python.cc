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
/* BINDTOOL_HEADER_FILE(interleave.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(47ac40c154b96995ccaf7fd9bfc967d8)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/blocks/interleave.h>
// pydoc.h is automatically generated in the build directory
#include <interleave_pydoc.h>

void bind_interleave(py::module& m)
{

    using interleave = ::gr::blocks::interleave;


    py::class_<interleave, gr::block, gr::basic_block, std::shared_ptr<interleave>>(
        m, "interleave", D(interleave))

        .def(py::init(&interleave::make),
             py::arg("itemsize"),
             py::arg("blocksize") = 1,
             D(interleave, make))


        ;
}
