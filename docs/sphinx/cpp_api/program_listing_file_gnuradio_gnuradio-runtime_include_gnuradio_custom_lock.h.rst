
.. _program_listing_file_gnuradio_gnuradio-runtime_include_gnuradio_custom_lock.h:

Program Listing for File custom_lock.h
======================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_include_gnuradio_custom_lock.h>` (``gnuradio/gnuradio-runtime/include/gnuradio/custom_lock.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2021 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef INCLUDED_GR_CUSTOM_LOCK_H
   #define INCLUDED_GR_CUSTOM_LOCK_H
   
   #include <gnuradio/api.h>
   #include <gnuradio/logger.h>
   #include <gnuradio/thread/thread.h>
   
   namespace gr {
   
   class custom_lock_if
   {
   public:
       virtual ~custom_lock_if(){};
   
       virtual void on_lock(gr::thread::scoped_lock& lock) = 0;
   
       virtual void on_unlock() = 0;
   };
   
   class custom_lock
   {
   public:
       explicit custom_lock(gr::thread::mutex& mutex, std::shared_ptr<custom_lock_if> locker)
           : d_lock(mutex), d_locker(locker)
       {
           d_locker->on_lock(d_lock);
       }
   
       ~custom_lock() { d_locker->on_unlock(); }
   
       // Disallow copying and assignment
       custom_lock(custom_lock const&) = delete;
       custom_lock& operator=(custom_lock const&) = delete;
   
   private:
       gr::thread::scoped_lock d_lock;
       std::shared_ptr<custom_lock_if> d_locker;
   };
   
   } /* namespace gr */
   
   #endif /* INCLUDED_GR_CUSTOM_LOCK_H */
