
.. _program_listing_file_gnuradio_gnuradio-runtime_lib_vmcircbuf_sysv_shm.h:

Program Listing for File vmcircbuf_sysv_shm.h
=============================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_lib_vmcircbuf_sysv_shm.h>` (``gnuradio/gnuradio-runtime/lib/vmcircbuf_sysv_shm.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2003 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef GR_VMCIRCBUF_SYSV_SHM_H
   #define GR_VMCIRCBUF_SYSV_SHM_H
   
   #include "vmcircbuf.h"
   #include <gnuradio/api.h>
   
   namespace gr {
   
   class GR_RUNTIME_API vmcircbuf_sysv_shm : public gr::vmcircbuf
   {
   public:
       vmcircbuf_sysv_shm(size_t size);
       ~vmcircbuf_sysv_shm() override;
   };
   
   class GR_RUNTIME_API vmcircbuf_sysv_shm_factory : public gr::vmcircbuf_factory
   {
   private:
       static gr::vmcircbuf_factory* s_the_factory;
   
   public:
       static gr::vmcircbuf_factory* singleton();
   
       const char* name() const override { return "gr::vmcircbuf_sysv_shm_factory"; }
   
       int granularity() override;
   
       gr::vmcircbuf* make(size_t size) override;
   };
   
   } /* namespace gr */
   
   #endif /* GR_VMCIRCBUF_SYSV_SHM_H */
