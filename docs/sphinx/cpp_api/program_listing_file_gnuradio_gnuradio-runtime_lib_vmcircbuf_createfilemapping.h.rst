
.. _program_listing_file_gnuradio_gnuradio-runtime_lib_vmcircbuf_createfilemapping.h:

Program Listing for File vmcircbuf_createfilemapping.h
======================================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_lib_vmcircbuf_createfilemapping.h>` (``gnuradio/gnuradio-runtime/lib/vmcircbuf_createfilemapping.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2003,2005,2013 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef GR_VMCIRCBUF_CREATEFILEMAPPING_H
   #define GR_VMCIRCBUF_CREATEFILEMAPPING_H
   
   #include "vmcircbuf.h"
   #include <gnuradio/api.h>
   
   #ifdef HAVE_CREATEFILEMAPPING
   #include <windows.h>
   #endif
   
   namespace gr {
   
   class GR_RUNTIME_API vmcircbuf_createfilemapping : public gr::vmcircbuf
   {
   public:
       // CREATORS
       vmcircbuf_createfilemapping(size_t size);
       ~vmcircbuf_createfilemapping() override;
   #ifdef HAVE_CREATEFILEMAPPING
   private:
       HANDLE d_handle;
       LPVOID d_first_copy;
       LPVOID d_second_copy;
   #endif
   };
   
   class GR_RUNTIME_API vmcircbuf_createfilemapping_factory : public gr::vmcircbuf_factory
   {
   private:
       static gr::vmcircbuf_factory* s_the_factory;
   
   public:
       static gr::vmcircbuf_factory* singleton();
   
       const char* name() const override
       {
           return "gr::vmcircbuf_createfilemapping_factory";
       }
   
       int granularity() override;
   
       gr::vmcircbuf* make(size_t size) override;
   };
   
   } /* namespace gr */
   
   #endif /* GR_VMCIRCBUF_CREATEFILEMAPPING_H */
