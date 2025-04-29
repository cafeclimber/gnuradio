
.. _program_listing_file_gnuradio_gnuradio-runtime_include_gnuradio_rpcserver_booter_aggregator.h:

Program Listing for File rpcserver_booter_aggregator.h
======================================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_include_gnuradio_rpcserver_booter_aggregator.h>` (``gnuradio/gnuradio-runtime/include/gnuradio/rpcserver_booter_aggregator.h``)

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
   
   #ifndef RPCSERVER_BOOTER_AGGREGATOR
   #define RPCSERVER_BOOTER_AGGREGATOR
   
   #include <gnuradio/api.h>
   #include <gnuradio/rpcserver_aggregator.h>
   #include <gnuradio/rpcserver_booter_base.h>
   #include <memory>
   #include <string>
   
   class rpcserver_server;
   
   class GR_RUNTIME_API rpcserver_booter_aggregator : public virtual rpcserver_booter_base
   {
   public:
       rpcserver_booter_aggregator();
       ~rpcserver_booter_aggregator() override;
   
       rpcserver_base* i() override;
       const std::string& type() override;
       const std::vector<std::string> endpoints() override;
   
       const std::vector<std::string>& registeredServers();
   
   protected:
       friend class rpcmanager;
       rpcserver_aggregator* agg();
   
   private:
       std::string d_type;
       std::shared_ptr<rpcserver_aggregator> server;
   };
   
   #endif /* RPCSERVER_BOOTER_AGGREGATOR */
