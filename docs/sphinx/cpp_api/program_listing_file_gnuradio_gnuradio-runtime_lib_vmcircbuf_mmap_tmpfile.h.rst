
.. _program_listing_file_gnuradio_gnuradio-runtime_lib_vmcircbuf_mmap_tmpfile.h:

Program Listing for File vmcircbuf_mmap_tmpfile.h
=================================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_lib_vmcircbuf_mmap_tmpfile.h>` (``gnuradio/gnuradio-runtime/lib/vmcircbuf_mmap_tmpfile.h``)

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
   
   #ifndef GR_VMCIRCBUF_MMAP_TMPFILE_H
   #define GR_VMCIRCBUF_MMAP_TMPFILE_H
   
   #include "vmcircbuf.h"
   #include <gnuradio/api.h>
   
   namespace gr {
   
   class GR_RUNTIME_API vmcircbuf_mmap_tmpfile : public gr::vmcircbuf
   {
   public:
       vmcircbuf_mmap_tmpfile(size_t size);
       ~vmcircbuf_mmap_tmpfile() override;
   };
   
   class GR_RUNTIME_API vmcircbuf_mmap_tmpfile_factory : public gr::vmcircbuf_factory
   {
   private:
       static gr::vmcircbuf_factory* s_the_factory;
   
   public:
       static gr::vmcircbuf_factory* singleton();
   
       const char* name() const override { return "gr::vmcircbuf_mmap_tmpfile_factory"; }
   
       int granularity() override;
   
       gr::vmcircbuf* make(size_t size) override;
   };
   
   } /* namespace gr */
   
   #endif /* GR_VMCIRCBUF_MMAP_TMPFILE_H */
