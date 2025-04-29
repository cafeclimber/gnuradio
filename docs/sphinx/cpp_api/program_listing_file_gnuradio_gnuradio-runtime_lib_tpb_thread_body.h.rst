
.. _program_listing_file_gnuradio_gnuradio-runtime_lib_tpb_thread_body.h:

Program Listing for File tpb_thread_body.h
==========================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_lib_tpb_thread_body.h>` (``gnuradio/gnuradio-runtime/lib/tpb_thread_body.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2008,2013 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   #ifndef INCLUDED_GR_TPB_THREAD_BODY_H
   #define INCLUDED_GR_TPB_THREAD_BODY_H
   
   #include "block_executor.h"
   #include <gnuradio/api.h>
   #include <gnuradio/block.h>
   #include <gnuradio/block_detail.h>
   #include <gnuradio/thread/thread.h>
   
   namespace gr {
   
   class GR_RUNTIME_API tpb_thread_body
   {
       block_executor d_exec;
   
   public:
       tpb_thread_body(block_sptr block,
                       thread::barrier_sptr start_sync,
                       int max_noutput_items = 100000);
       ~tpb_thread_body();
   };
   
   } /* namespace gr */
   
   #endif /* INCLUDED_GR_TPB_THREAD_BODY_H */
