
.. _program_listing_file_gnuradio_gnuradio-runtime_include_gnuradio_sys_paths.h:

Program Listing for File sys_paths.h
====================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_include_gnuradio_sys_paths.h>` (``gnuradio/gnuradio-runtime/include/gnuradio/sys_paths.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /*
    * Copyright 2011,2013 Free Software Foundation, Inc.
    * Copyright 2024 mboersch, Marcus Müller
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef GR_SYS_PATHS_H
   #define GR_SYS_PATHS_H
   
   #include "api.h"
   #include <gnuradio/api.h>
   #include <filesystem>
   
   namespace gr {
   namespace paths {
   GR_RUNTIME_API std::filesystem::path tmp();
   
   GR_RUNTIME_API std::filesystem::path appdata();
   
   GR_RUNTIME_API std::filesystem::path userconf();
   
   GR_RUNTIME_API std::filesystem::path cache();
   
   GR_RUNTIME_API std::filesystem::path persistent();
   } /* namespace  paths */
   
   [[deprecated("use gr::paths::tmp()")]] GR_RUNTIME_API const char* tmp_path();
   
   [[deprecated("use gr::paths::appdata()")]] GR_RUNTIME_API const char* appdata_path();
   
   [[deprecated("use gr::paths::userconf()")]] GR_RUNTIME_API const char* userconf_path();
   
   } /* namespace gr */
   
   #endif /* GR_SYS_PATHS_H */
