
.. _program_listing_file_gnuradio_gnuradio-runtime_include_gnuradio_rpcbufferedget.h:

Program Listing for File rpcbufferedget.h
=========================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_include_gnuradio_rpcbufferedget.h>` (``gnuradio/gnuradio-runtime/include/gnuradio/rpcbufferedget.h``)

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
   
   #ifndef RPCBUFFEREDGET_H
   #define RPCBUFFEREDGET_H
   
   #include <condition_variable>
   #include <mutex>
   
   template <typename TdataType>
   class rpcbufferedget
   {
   public:
       rpcbufferedget(const unsigned int init_buffer_size = 4096)
           : d_data_needed(false),
             d_data_ready(),
             d_buffer_lock(),
             d_buffer(init_buffer_size)
       {
           ;
       }
   
       ~rpcbufferedget() { d_data_ready.notify_all(); }
   
       void offer_data(const TdataType& data)
       {
           if (!d_data_needed)
               return;
           {
               std::scoped_lock lock(d_buffer_lock);
               d_buffer = data;
               d_data_needed = false;
           }
           d_data_ready.notify_one();
       }
   
       TdataType get()
       {
           std::unique_lock lock(d_buffer_lock);
           d_data_needed = true;
           d_data_ready.wait(lock);
           return d_buffer;
       }
   
   private:
       bool d_data_needed;
       std::condition_variable d_data_ready;
       std::mutex d_buffer_lock;
       TdataType d_buffer;
   };
   
   #endif
