
.. _program_listing_file_gnuradio_gnuradio-runtime_include_gnuradio_buffer_double_mapped.h:

Program Listing for File buffer_double_mapped.h
===============================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_include_gnuradio_buffer_double_mapped.h>` (``gnuradio/gnuradio-runtime/include/gnuradio/buffer_double_mapped.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2020 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef INCLUDED_GR_RUNTIME_BUFFER_DOUBLE_MAPPED_H
   #define INCLUDED_GR_RUNTIME_BUFFER_DOUBLE_MAPPED_H
   
   #include <gnuradio/api.h>
   #include <gnuradio/buffer.h>
   #include <gnuradio/buffer_type.h>
   #include <gnuradio/logger.h>
   #include <gnuradio/runtime_types.h>
   
   namespace gr {
   
   class vmcircbuf;
   
   class GR_RUNTIME_API buffer_double_mapped : public buffer
   {
   public:
       static buffer_type type;
   
       static buffer_sptr make_buffer(int nitems,
                                      size_t sizeof_item,
                                      uint64_t downstream_lcm_nitems,
                                      uint32_t downstream_max_out_mult,
                                      block_sptr link = block_sptr(),
                                      block_sptr buf_owner = block_sptr());
   
       gr::logger_ptr d_logger;
       gr::logger_ptr d_debug_logger;
   
       ~buffer_double_mapped() override;
   
       int space_available() override;
   
       void post_work([[maybe_unused]] int nitems) override {}
   
   protected:
       bool allocate_buffer(int nitems) override;
   
       unsigned index_add(unsigned a, unsigned b) override
       {
           unsigned s = a + b;
   
           if (s >= d_bufsize)
               s -= d_bufsize;
   
           assert(s < d_bufsize);
           return s;
       }
   
       unsigned index_sub(unsigned a, unsigned b) override
       {
           int s = a - b;
   
           if (s < 0)
               s += d_bufsize;
   
           assert((unsigned)s < d_bufsize);
           return s;
       }
   
   private:
       friend class buffer_reader;
   
       friend GR_RUNTIME_API buffer_sptr make_buffer(int nitems,
                                                     size_t sizeof_item,
                                                     uint64_t downstream_lcm_nitems,
                                                     block_sptr link,
                                                     block_sptr buf_owner);
       friend GR_RUNTIME_API buffer_sptr
       make_buffer_double_mapped(int nitems,
                                 size_t sizeof_item,
                                 uint64_t downstream_lcm_nitems,
                                 uint32_t downstream_max_out_mult,
                                 block_sptr link,
                                 block_sptr buf_owner);
   
       std::unique_ptr<gr::vmcircbuf> d_vmcircbuf;
   
       buffer_double_mapped(int nitems,
                            size_t sizeof_item,
                            uint64_t downstream_lcm_nitems,
                            uint32_t downstream_max_out_mult,
                            block_sptr link);
   };
   
   } /* namespace gr */
   
   
   #endif /* INCLUDED_GR_RUNTIME_BUFFER_DOUBLE_MAPPED_H */
