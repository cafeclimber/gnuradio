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
/* BINDTOOL_HEADER_FILE(correlate_access_code_bb_ts.h) */
/* BINDTOOL_HEADER_FILE_HASH(5312e41bd64837fb60561903c78ecfda)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/digital/correlate_access_code_bb_ts.h>
// pydoc.h is automatically generated in the build directory
#include <correlate_access_code_bb_ts_pydoc.h>

void bind_correlate_access_code_bb_ts(py::module& m)
{

    using correlate_access_code_bb_ts = ::gr::digital::correlate_access_code_bb_ts;


    py::class_<correlate_access_code_bb_ts,
               gr::block,
               gr::basic_block,
               std::shared_ptr<correlate_access_code_bb_ts>>(
        m, "correlate_access_code_bb_ts", D(correlate_access_code_bb_ts))

        .def(py::init(&correlate_access_code_bb_ts::make),
             py::arg("access_code"),
             py::arg("threshold"),
             py::arg("tag_name"),
             D(correlate_access_code_bb_ts, make))


        .def("set_access_code",
             &correlate_access_code_bb_ts::set_access_code,
             py::arg("access_code"),
             D(correlate_access_code_bb_ts, set_access_code))


        .def("access_code",
             &correlate_access_code_bb_ts::access_code,
             D(correlate_access_code_bb_ts, access_code))

        ;
}
