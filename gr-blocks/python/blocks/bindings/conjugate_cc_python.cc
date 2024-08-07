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
/* BINDTOOL_HEADER_FILE(conjugate_cc.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(cd81447fd6bc680a0cc55e20e5a6e70a)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/blocks/conjugate_cc.h>
// pydoc.h is automatically generated in the build directory
#include <conjugate_cc_pydoc.h>

void bind_conjugate_cc(py::module& m)
{

    using conjugate_cc = ::gr::blocks::conjugate_cc;


    py::class_<conjugate_cc,
               gr::sync_block,
               gr::block,
               gr::basic_block,
               std::shared_ptr<conjugate_cc>>(m, "conjugate_cc", D(conjugate_cc))

        .def(py::init(&conjugate_cc::make), D(conjugate_cc, make))


        ;
}
