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
/* BINDTOOL_HEADER_FILE(correlate_access_code_tag_ff.h) */
/* BINDTOOL_HEADER_FILE_HASH(820993c1f3500d450d517027a3a664bc)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/digital/correlate_access_code_tag_ff.h>
// pydoc.h is automatically generated in the build directory
#include <correlate_access_code_tag_ff_pydoc.h>

void bind_correlate_access_code_tag_ff(py::module& m)
{

    using correlate_access_code_tag_ff = ::gr::digital::correlate_access_code_tag_ff;


    py::class_<correlate_access_code_tag_ff,
               gr::sync_block,
               gr::block,
               gr::basic_block,
               std::shared_ptr<correlate_access_code_tag_ff>>(
        m, "correlate_access_code_tag_ff", D(correlate_access_code_tag_ff))

        .def(py::init(&correlate_access_code_tag_ff::make),
             py::arg("access_code"),
             py::arg("threshold"),
             py::arg("tag_name"),
             D(correlate_access_code_tag_ff, make))


        .def("set_access_code",
             &correlate_access_code_tag_ff::set_access_code,
             py::arg("access_code"),
             D(correlate_access_code_tag_ff, set_access_code))


        .def("set_threshold",
             &correlate_access_code_tag_ff::set_threshold,
             py::arg("threshold"),
             D(correlate_access_code_tag_ff, set_threshold))


        .def("set_tagname",
             &correlate_access_code_tag_ff::set_tagname,
             py::arg("tagname"),
             D(correlate_access_code_tag_ff, set_tagname))

        ;
}
