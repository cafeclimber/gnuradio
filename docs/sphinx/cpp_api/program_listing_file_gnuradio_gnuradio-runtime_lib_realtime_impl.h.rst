
.. _program_listing_file_gnuradio_gnuradio-runtime_lib_realtime_impl.h:

Program Listing for File realtime_impl.h
========================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_lib_realtime_impl.h>` (``gnuradio/gnuradio-runtime/lib/realtime_impl.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2006,2008,2013 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef INCLUDED_GNURADIO_REALTIME_H
   #define INCLUDED_GNURADIO_REALTIME_H
   
   #include <gnuradio/api.h>
   #include <gnuradio/realtime.h>
   #include <stdexcept>
   
   namespace gr {
   namespace realtime {
   /*
    * Define the range for our virtual priorities (don't change
    * these)
    *
    * Processes (or threads) with numerically higher priority values
    * are scheduled before processes with numerically lower priority
    * values. Thus, the value returned by s_rt_priority_max will be
    * greater than the value returned by s_rt_priority_min.
    */
   static const int s_rt_priority_min = 0;
   static const int s_rt_priority_max = 15;
   static const int s_rt_priority_default = 1;
   
   struct GR_RUNTIME_API rt_sched_param {
       int priority;
       rt_sched_policy policy;
   
       rt_sched_param() : priority(s_rt_priority_default), policy(RT_SCHED_RR) {}
   
       rt_sched_param(int priority_, rt_sched_policy policy_ = RT_SCHED_RR)
       {
           if (priority_ < s_rt_priority_min || priority_ > s_rt_priority_max)
               throw std::invalid_argument("rt_sched_param: priority out of range");
   
           priority = priority_;
           policy = policy_;
       }
   };
   
   GR_RUNTIME_API rt_status_t enable_realtime_scheduling(rt_sched_param = rt_sched_param());
   
   } /* namespace realtime */
   } /* namespace gr */
   
   #endif /* INCLUDED_GNURADIO_REALTIME_H */
