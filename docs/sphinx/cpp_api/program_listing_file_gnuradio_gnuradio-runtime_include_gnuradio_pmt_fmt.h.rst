
.. _program_listing_file_gnuradio_gnuradio-runtime_include_gnuradio_pmt_fmt.h:

Program Listing for File pmt_fmt.h
==================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_include_gnuradio_pmt_fmt.h>` (``gnuradio/gnuradio-runtime/include/gnuradio/pmt_fmt.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2023 Marcus Müller
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   #ifndef INCLUDED_GNURADIO_PMT_FMT_H
   #define INCLUDED_GNURADIO_PMT_FMT_H
   /* ensure that tweakme.h is included before the bundled spdlog/fmt header, see
    * https://github.com/gabime/spdlog/issues/2922 */
   #include <spdlog/tweakme.h>
   
   #include <gnuradio/api.h>
   #include <pmt/pmt.h>
   #include <spdlog/fmt/fmt.h>
   #include <string_view>
   
   template <>
   struct GR_RUNTIME_API fmt::formatter<pmt::pmt_t> : formatter<std::string_view> {
       fmt::format_context::iterator format(const pmt::pmt_t& obj,
                                            format_context& ctx) const;
   };
   #endif
