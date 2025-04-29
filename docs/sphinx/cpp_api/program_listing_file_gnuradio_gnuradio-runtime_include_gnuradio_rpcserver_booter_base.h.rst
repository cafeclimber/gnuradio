
.. _program_listing_file_gnuradio_gnuradio-runtime_include_gnuradio_rpcserver_booter_base.h:

Program Listing for File rpcserver_booter_base.h
================================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_include_gnuradio_rpcserver_booter_base.h>` (``gnuradio/gnuradio-runtime/include/gnuradio/rpcserver_booter_base.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2012 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef RPCSERVER_BOOTER_BASE
   #define RPCSERVER_BOOTER_BASE
   
   #include <string>
   #include <vector>
   
   class rpcserver_base;
   
   class rpcserver_booter_base
   {
   public:
       rpcserver_booter_base() { ; }
       virtual ~rpcserver_booter_base() { ; }
   
       virtual rpcserver_base* i() = 0;
       virtual const std::vector<std::string> endpoints() = 0;
       virtual const std::string& type() = 0;
   
   private:
   };
   
   #endif /* RPCSERVER_BOOTER_BASE */
