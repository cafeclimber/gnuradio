
.. _program_listing_file_gnuradio_gnuradio-runtime_include_gnuradio_rpcserver_booter_thrift.h:

Program Listing for File rpcserver_booter_thrift.h
==================================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_include_gnuradio_rpcserver_booter_thrift.h>` (``gnuradio/gnuradio-runtime/include/gnuradio/rpcserver_booter_thrift.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2015 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef RPCSERVER_BOOTER_THRIFT_H
   #define RPCSERVER_BOOTER_THRIFT_H
   
   #include "thrift/ControlPort.h"
   #include <gnuradio/rpcserver_booter_base.h>
   #include <gnuradio/thrift_server_template.h>
   
   class rpcserver_base;
   class rpcserver_thrift;
   
   class rpcserver_booter_thrift
       : public virtual rpcserver_booter_base,
         public virtual thrift_server_template<rpcserver_base,
                                               rpcserver_thrift,
                                               rpcserver_booter_thrift>
   {
   public:
       rpcserver_booter_thrift();
       ~rpcserver_booter_thrift();
   
       rpcserver_base* i();
       const std::string& type() { return d_type; }
       const std::vector<std::string> endpoints();
   
   private:
       std::string d_type;
   };
   
   #endif /* RPCSERVER_BOOTER_THRIFT_H */
