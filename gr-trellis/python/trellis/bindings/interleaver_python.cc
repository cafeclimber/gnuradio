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
/* BINDTOOL_HEADER_FILE(interleaver.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(b155bd0221ef42a2b318552b5c608dd8)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/trellis/interleaver.h>
// pydoc.h is automatically generated in the build directory
#include <interleaver_pydoc.h>

void bind_interleaver(py::module& m)
{

    using interleaver = ::gr::trellis::interleaver;


    py::class_<interleaver, std::shared_ptr<interleaver>>(
        m, "interleaver", D(interleaver))

        .def(py::init<>(), D(interleaver, interleaver, 0))
        .def(py::init<gr::trellis::interleaver const&>(),
             py::arg("INTERLEAVER"),
             D(interleaver, interleaver, 1))
        .def(py::init<unsigned int, std::vector<int, std::allocator<int>> const&>(),
             py::arg("K"),
             py::arg("INTER"),
             D(interleaver, interleaver, 2))
        .def(py::init<char const*>(), py::arg("name"), D(interleaver, interleaver, 3))
        .def(py::init<unsigned int, int>(),
             py::arg("K"),
             py::arg("seed"),
             D(interleaver, interleaver, 4))


        .def("K", &interleaver::K, D(interleaver, K))


        .def("INTER", &interleaver::INTER, D(interleaver, INTER))


        .def("DEINTER", &interleaver::DEINTER, D(interleaver, DEINTER))


        .def("write_interleaver_txt",
             &interleaver::write_interleaver_txt,
             py::arg("filename"),
             D(interleaver, write_interleaver_txt))

        ;
}
