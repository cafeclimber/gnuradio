
.. _program_listing_file_gnuradio_gnuradio-runtime_lib_vmcircbuf.h:

Program Listing for File vmcircbuf.h
====================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_lib_vmcircbuf.h>` (``gnuradio/gnuradio-runtime/lib/vmcircbuf.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2003,2013 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef GR_VMCIRCBUF_H
   #define GR_VMCIRCBUF_H
   
   #include <gnuradio/api.h>
   #include <gnuradio/logger.h>
   #include <gnuradio/prefs.h>
   #include <gnuradio/thread/thread.h>
   #include <vector>
   
   extern gr::thread::mutex s_vm_mutex;
   
   namespace gr {
   
   class GR_RUNTIME_API vmcircbuf
   {
   protected:
       size_t d_size;
       char* d_base;
       logger_ptr d_logger;
       logger_ptr d_debug_logger;
   
       // CREATORS
       vmcircbuf(size_t size) : d_size(size), d_base(0)
       {
           gr::configure_default_loggers(d_logger, d_debug_logger, "gr::vmcircbuf");
       };
   
   public:
       virtual ~vmcircbuf();
   
       // ACCESSORS
       void* pointer_to_first_copy() const { return d_base; }
       void* pointer_to_second_copy() const { return d_base + d_size; }
   };
   
   class GR_RUNTIME_API vmcircbuf_factory
   {
   protected:
       vmcircbuf_factory(){};
       virtual ~vmcircbuf_factory();
   
   public:
       virtual const char* name() const = 0;
   
       virtual int granularity() = 0;
   
       virtual vmcircbuf* make(size_t size) = 0;
   };
   
   /*
    * \brief pulls together all implementations of gr::vmcircbuf
    */
   class GR_RUNTIME_API vmcircbuf_sysconfig
   {
   public:
       /*
        * \brief return the single instance of the default factory.
        *
        * returns the default factory to use if it's already defined,
        * else find the first working factory and use it.
        */
       static vmcircbuf_factory* get_default_factory();
   
       static int granularity() { return get_default_factory()->granularity(); }
       static vmcircbuf* make(size_t size) { return get_default_factory()->make(size); }
   
       // N.B. not all factories are guaranteed to work.
       // It's too hard to check everything at config time, so we check at runtime
       static std::vector<vmcircbuf_factory*> all_factories();
   
       // make this factory the default
       static void set_default_factory(vmcircbuf_factory* f);
   
       static bool test_factory(vmcircbuf_factory* f, int verbose);
   
       static bool test_all_factories(int verbose);
   };
   
   } /* namespace gr */
   
   #endif /* GR_VMCIRCBUF_H */
