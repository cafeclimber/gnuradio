
.. _program_listing_file_gnuradio_gnuradio-runtime_include_gnuradio_rpcmanager_base.h:

Program Listing for File rpcmanager_base.h
==========================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_include_gnuradio_rpcmanager_base.h>` (``gnuradio/gnuradio-runtime/include/gnuradio/rpcmanager_base.h``)

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
   
   #ifndef RPCMANAGER_BASE_H
   #define RPCMANAGER_BASE_H
   
   #include <memory>
   
   class rpcserver_booter_base;
   // class rpcserver_booter_aggregator;
   
   class rpcmanager_base
   {
   public:
       typedef std::shared_ptr<rpcserver_booter_base> rpcserver_booter_base_sptr;
   
       rpcmanager_base() { ; }
       ~rpcmanager_base() { ; }
   
       // static rpcserver_booter_base* get();
   
       // static void register_booter(rpcserver_booter_base_sptr booter);
   
   private:
   };
   
   #endif /* RPCMANAGER_BASE_H */
