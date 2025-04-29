
.. _program_listing_file_gnuradio_gnuradio-runtime_lib_vmcircbuf_prefs.h:

Program Listing for File vmcircbuf_prefs.h
==========================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_lib_vmcircbuf_prefs.h>` (``gnuradio/gnuradio-runtime/lib/vmcircbuf_prefs.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2003,2013 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef GR_VMCIRCBUF_PREFS_H
   #define GR_VMCIRCBUF_PREFS_H
   
   #include <gnuradio/api.h>
   #include <string_view>
   #include <string>
   
   namespace gr {
   
   class GR_RUNTIME_API vmcircbuf_prefs
   {
   public:
       static std::string get(std::string_view key);
       static void set(std::string_view key, std::string_view value);
   };
   
   } /* namespace gr */
   
   #endif /* GR_VMCIRCBUF_PREFS_H */
