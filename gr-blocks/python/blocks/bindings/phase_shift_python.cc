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
/* BINDTOOL_HEADER_FILE(phase_shift.h)                                             */
/* BINDTOOL_HEADER_FILE_HASH(b82854232760baeed04f70f564f771d5)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/blocks/phase_shift.h>
// pydoc.h is automatically generated in the build directory
#include <phase_shift_pydoc.h>

void bind_phase_shift(py::module& m)
{

    using phase_shift = ::gr::blocks::phase_shift;


    py::class_<phase_shift,
               gr::sync_block,
               gr::block,
               gr::basic_block,
               std::shared_ptr<phase_shift>>(m, "phase_shift", D(phase_shift))

        .def(py::init(&phase_shift::make),
             py::arg("shift"),
             py::arg("is_radians"),
             D(phase_shift, make))


        .def("get_shift", &phase_shift::get_shift, D(phase_shift, get_shift))


        .def("set_shift",
             &phase_shift::set_shift,
             py::arg("new_value"),
             D(phase_shift, set_shift))

        ;
}
