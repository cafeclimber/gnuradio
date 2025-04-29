
.. _program_listing_file_gnuradio_gnuradio-runtime_include_gnuradio_tpb_detail.h:

Program Listing for File tpb_detail.h
=====================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_include_gnuradio_tpb_detail.h>` (``gnuradio/gnuradio-runtime/include/gnuradio/tpb_detail.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2008,2009,2013 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef INCLUDED_GR_TPB_DETAIL_H
   #define INCLUDED_GR_TPB_DETAIL_H
   
   #include <gnuradio/api.h>
   #include <gnuradio/thread/thread.h>
   #include <pmt/pmt.h>
   #include <deque>
   
   namespace gr {
   
   class block_detail;
   
   struct GR_RUNTIME_API tpb_detail {
       gr::thread::mutex mutex; //< protects all vars
       bool input_changed;
       gr::thread::condition_variable input_cond;
       bool output_changed;
       gr::thread::condition_variable output_cond;
   
   public:
       tpb_detail() : input_changed(false), output_changed(false) {}
   
       void notify_upstream(block_detail* d);
   
       void notify_downstream(block_detail* d);
   
       void notify_neighbors(block_detail* d);
   
       void notify_msg()
       {
           gr::thread::scoped_lock guard(mutex);
           input_changed = true;
           input_cond.notify_one();
           output_changed = true;
           output_cond.notify_one();
       }
   
       void clear_changed()
       {
           gr::thread::scoped_lock guard(mutex);
           input_changed = false;
           output_changed = false;
       }
   
   private:
       void set_input_changed()
       {
           gr::thread::scoped_lock guard(mutex);
           input_changed = true;
           input_cond.notify_one();
       }
   
       void set_output_changed()
       {
           gr::thread::scoped_lock guard(mutex);
           output_changed = true;
           output_cond.notify_one();
       }
   };
   
   } /* namespace gr */
   
   #endif /* INCLUDED_GR_TPB_DETAIL_H */
