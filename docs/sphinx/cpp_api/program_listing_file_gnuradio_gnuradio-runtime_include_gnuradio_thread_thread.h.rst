
.. _program_listing_file_gnuradio_gnuradio-runtime_include_gnuradio_thread_thread.h:

Program Listing for File thread.h
=================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_include_gnuradio_thread_thread.h>` (``gnuradio/gnuradio-runtime/include/gnuradio/thread/thread.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2009-2014 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef INCLUDED_THREAD_H
   #define INCLUDED_THREAD_H
   
   #include <gnuradio/api.h>
   #include <boost/thread/barrier.hpp>
   #include <boost/thread/condition_variable.hpp>
   #include <boost/thread/locks.hpp>
   #include <boost/thread/mutex.hpp>
   #include <boost/thread/thread.hpp>
   #include <memory>
   #include <vector>
   
   #if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
   
   #ifndef WIN32_LEAN_AND_MEAN
   #define WIN32_LEAN_AND_MEAN
   #endif
   
   #include <windows.h>
   
   #endif
   
   namespace gr {
   namespace thread {
   
   typedef boost::thread thread;
   typedef boost::mutex mutex;
   typedef boost::unique_lock<boost::mutex> scoped_lock;
   typedef boost::condition_variable condition_variable;
   typedef boost::barrier barrier;
   typedef std::shared_ptr<barrier> barrier_sptr;
   
   #if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
   typedef HANDLE gr_thread_t;
   #elif defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__)
   typedef pthread_t gr_thread_t;
   #else
   typedef pthread_t gr_thread_t;
   #endif
   
   GR_RUNTIME_API gr_thread_t get_current_thread_id();
   
   GR_RUNTIME_API void thread_bind_to_processor(const std::vector<int>& mask);
   
   GR_RUNTIME_API void thread_bind_to_processor(int n);
   
   GR_RUNTIME_API void thread_bind_to_processor(gr_thread_t thread,
                                                const std::vector<int>& mask);
   
   
   GR_RUNTIME_API void thread_bind_to_processor(gr_thread_t thread, unsigned int n);
   
   GR_RUNTIME_API void thread_unbind();
   
   GR_RUNTIME_API void thread_unbind(gr_thread_t thread);
   
   GR_RUNTIME_API int thread_priority(gr_thread_t thread);
   
   GR_RUNTIME_API int set_thread_priority(gr_thread_t thread, int priority);
   
   GR_RUNTIME_API void set_thread_name(gr_thread_t thread, std::string name);
   
   } /* namespace thread */
   } /* namespace gr */
   
   #endif /* INCLUDED_THREAD_H */
