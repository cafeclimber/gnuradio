
.. _program_listing_file_gnuradio_gnuradio-runtime_lib_scheduler.h:

Program Listing for File scheduler.h
====================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_lib_scheduler.h>` (``gnuradio/gnuradio-runtime/lib/scheduler.h``)

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
   
   #ifndef INCLUDED_GR_SCHEDULER_H
   #define INCLUDED_GR_SCHEDULER_H
   
   #include "flat_flowgraph.h"
   #include <gnuradio/api.h>
   #include <gnuradio/block.h>
   
   namespace gr {
   
   class scheduler;
   typedef std::shared_ptr<scheduler> scheduler_sptr;
   
   class GR_RUNTIME_API scheduler
   {
   public:
       scheduler(flat_flowgraph_sptr ffg, int max_noutput_items, bool catch_exceptions);
   
       virtual ~scheduler();
   
       scheduler(const scheduler&) = delete;
       scheduler& operator=(const scheduler&) = delete;
   
       virtual void stop() = 0;
   
       virtual void wait() = 0;
   };
   
   } /* namespace gr */
   
   #endif /* INCLUDED_GR_SCHEDULER_H */
