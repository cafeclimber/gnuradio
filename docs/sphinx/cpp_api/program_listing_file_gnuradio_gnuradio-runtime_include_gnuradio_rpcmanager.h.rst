
.. _program_listing_file_gnuradio_gnuradio-runtime_include_gnuradio_rpcmanager.h:

Program Listing for File rpcmanager.h
=====================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_include_gnuradio_rpcmanager.h>` (``gnuradio/gnuradio-runtime/include/gnuradio/rpcmanager.h``)

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
   
   #ifndef RPCMANAGER_H
   #define RPCMANAGER_H
   
   #include <gnuradio/api.h>
   #include <gnuradio/rpcmanager_base.h>
   #include <gnuradio/rpcserver_booter_aggregator.h>
   #include <memory>
   
   class GR_RUNTIME_API rpcmanager : public virtual rpcmanager_base
   {
   public:
       rpcmanager();
       ~rpcmanager();
   
       static rpcserver_booter_base* get();
   
       static void register_booter(rpcserver_booter_base* booter);
   
       template <typename T>
       class rpcserver_booter_register_helper
       {
       public:
           rpcserver_booter_register_helper() { rpcmanager::register_booter(new T()); }
   
           // TODO: unregister
       };
   
   private:
       static bool make_aggregator;
       static bool booter_registered;
       static bool aggregator_registered;
       static void rpcserver_booter_base_sptr_dest(rpcserver_booter_base* b) { (void)b; }
       static std::unique_ptr<rpcserver_booter_base> boot;
       static std::unique_ptr<rpcserver_booter_aggregator> aggregator;
   };
   
   #endif /* RPCMANAGER_H */
