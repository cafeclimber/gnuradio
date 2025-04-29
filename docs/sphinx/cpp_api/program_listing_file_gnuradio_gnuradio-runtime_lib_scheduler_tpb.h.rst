
.. _program_listing_file_gnuradio_gnuradio-runtime_lib_scheduler_tpb.h:

Program Listing for File scheduler_tpb.h
========================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_lib_scheduler_tpb.h>` (``gnuradio/gnuradio-runtime/lib/scheduler_tpb.h``)

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
   
   #ifndef INCLUDED_GR_SCHEDULER_TPB_H
   #define INCLUDED_GR_SCHEDULER_TPB_H
   
   #include "scheduler.h"
   #include <gnuradio/api.h>
   #include <gnuradio/thread/thread_group.h>
   
   namespace gr {
   
   class GR_RUNTIME_API scheduler_tpb : public scheduler
   {
       gr::thread::thread_group d_threads;
   
   protected:
       scheduler_tpb(flat_flowgraph_sptr ffg, int max_noutput_items, bool catch_exceptions);
   
   public:
       static scheduler_sptr make(flat_flowgraph_sptr ffg,
                                  int max_noutput_items = 100000,
                                  bool catch_exceptions = true);
   
       ~scheduler_tpb() override;
   
       void stop() override;
   
       void wait() override;
   };
   
   } /* namespace gr */
   
   #endif /* INCLUDED_GR_SCHEDULER_TPB_H */
