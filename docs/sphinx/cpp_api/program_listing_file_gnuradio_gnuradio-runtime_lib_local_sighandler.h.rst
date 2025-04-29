
.. _program_listing_file_gnuradio_gnuradio-runtime_lib_local_sighandler.h:

Program Listing for File local_sighandler.h
===========================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_lib_local_sighandler.h>` (``gnuradio/gnuradio-runtime/lib/local_sighandler.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2004,2013 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef INCLUDED_GR_LOCAL_SIGHANDLER_H
   #define INCLUDED_GR_LOCAL_SIGHANDLER_H
   
   #ifdef HAVE_SIGNAL_H
   #include <csignal>
   #endif
   
   #include <gnuradio/api.h>
   #include <gnuradio/logger.h>
   #include <string>
   
   namespace gr {
   
   class GR_RUNTIME_API local_sighandler
   {
   private:
       int d_signum;
   #ifdef HAVE_SIGACTION
       struct sigaction d_old_action;
   #endif
   
   public:
       gr::logger_ptr d_logger;
       gr::logger_ptr d_debug_logger;
       local_sighandler(int signum, void (*new_handler)(int));
       ~local_sighandler() noexcept(false);
   
       /* throw gr_signal (signum) */
       static void throw_signal(int signum);
   };
   
   class GR_RUNTIME_API signal
   {
   private:
       int d_signum;
   
   public:
       signal(int signum) : d_signum(signum) {}
       int signum() const { return d_signum; }
       std::string name() const;
   };
   
   } /* namespace gr */
   
   #endif /* INCLUDED_GR_LOCAL_SIGHANDLER_H */
