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
/* BINDTOOL_HEADER_FILE(atsc_fs_checker.h)                                         */
/* BINDTOOL_HEADER_FILE_HASH(2cc2bab498066d5548bc5716a842b6d0)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/dtv/atsc_fs_checker.h>
// pydoc.h is automatically generated in the build directory
#include <atsc_fs_checker_pydoc.h>

void bind_atsc_fs_checker(py::module& m)
{

    using atsc_fs_checker = ::gr::dtv::atsc_fs_checker;


    py::class_<atsc_fs_checker,
               gr::block,
               gr::basic_block,
               std::shared_ptr<atsc_fs_checker>>(m, "atsc_fs_checker", D(atsc_fs_checker))

        .def(py::init(&atsc_fs_checker::make), D(atsc_fs_checker, make))


        ;
}
