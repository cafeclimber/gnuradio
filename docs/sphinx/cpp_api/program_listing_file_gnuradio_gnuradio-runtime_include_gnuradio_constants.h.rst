
.. _program_listing_file_gnuradio_gnuradio-runtime_include_gnuradio_constants.h:

Program Listing for File constants.h
====================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_include_gnuradio_constants.h>` (``gnuradio/gnuradio-runtime/include/gnuradio/constants.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2006,2009,2013 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef INCLUDED_GR_CONSTANTS_H
   #define INCLUDED_GR_CONSTANTS_H
   
   #include <gnuradio/api.h>
   #include <string>
   
   namespace gr {
   
   GR_RUNTIME_API const std::string prefix();
   
   GR_RUNTIME_API const std::string sysconfdir();
   
   GR_RUNTIME_API const std::string prefsdir();
   
   GR_RUNTIME_API const std::string build_date();
   
   GR_RUNTIME_API const std::string version();
   
   GR_RUNTIME_API const std::string major_version();
   
   GR_RUNTIME_API const std::string api_version();
   
   GR_RUNTIME_API const std::string minor_version();
   
   GR_RUNTIME_API const std::string c_compiler();
   
   GR_RUNTIME_API const std::string cxx_compiler();
   
   GR_RUNTIME_API const std::string compiler_flags();
   
   GR_RUNTIME_API const std::string build_time_enabled_components();
   
   GR_RUNTIME_API const std::string pybind_version();
   
   
   } /* namespace gr */
   
   #endif /* INCLUDED_GR_CONSTANTS_H */
