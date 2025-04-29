
.. _program_listing_file_gnuradio_gnuradio-runtime_include_gnuradio_realtime.h:

Program Listing for File realtime.h
===================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_include_gnuradio_realtime.h>` (``gnuradio/gnuradio-runtime/include/gnuradio/realtime.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2006,2013 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef INCLUDED_GR_REALTIME_H
   #define INCLUDED_GR_REALTIME_H
   
   #include <gnuradio/api.h>
   
   namespace gr {
   
   typedef enum { RT_OK = 0, RT_NOT_IMPLEMENTED, RT_NO_PRIVS, RT_OTHER_ERROR } rt_status_t;
   
   enum rt_sched_policy {
       RT_SCHED_RR = 0,   // round robin
       RT_SCHED_FIFO = 1, // first in first out
   };
   
   GR_RUNTIME_API rt_status_t enable_realtime_scheduling();
   
   } /* namespace gr */
   
   #endif /* INCLUDED_GR_REALTIME_H */
