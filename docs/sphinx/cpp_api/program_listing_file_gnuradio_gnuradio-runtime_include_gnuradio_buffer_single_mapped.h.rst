
.. _program_listing_file_gnuradio_gnuradio-runtime_include_gnuradio_buffer_single_mapped.h:

Program Listing for File buffer_single_mapped.h
===============================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_include_gnuradio_buffer_single_mapped.h>` (``gnuradio/gnuradio-runtime/include/gnuradio/buffer_single_mapped.h``)

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
   
   #ifndef INCLUDED_GR_RUNTIME_BUFFER_SINGLE_MAPPED_H
   #define INCLUDED_GR_RUNTIME_BUFFER_SINGLE_MAPPED_H
   
   #include <cstddef>
   
   #include <gnuradio/api.h>
   #include <gnuradio/buffer.h>
   #include <gnuradio/buffer_reader.h>
   #include <gnuradio/logger.h>
   #include <gnuradio/runtime_types.h>
   
   namespace gr {
   
   class GR_RUNTIME_API buffer_single_mapped : public buffer
   {
   public:
       gr::logger_ptr d_logger;
       gr::logger_ptr d_debug_logger;
   
       ~buffer_single_mapped() override;
   
       block_sptr buf_owner() { return d_buf_owner; }
   
       int space_available() override;
   
       void update_reader_block_history(unsigned history, int delay) override;
   
       bool input_blkd_cb_ready(int items_required, unsigned read_index) override;
   
       bool input_blocked_callback(int items_required,
                                   int items_avail,
                                   unsigned read_index) override = 0;
   
       bool output_blkd_cb_ready(int output_multiple) override;
   
       bool output_blocked_callback(int output_multiple, bool force) override = 0;
   
   protected:
       bool allocate_buffer(int nitems) override;
   
       virtual bool do_allocate_buffer(size_t final_nitems, size_t sizeof_item) = 0;
   
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
           // NOTE: a is writer ptr and b is read ptr
           int s = a - b;
   
           if (s < 0)
               s = d_bufsize - b;
   
           assert((unsigned)s < d_bufsize);
           return s;
       }
   
   
       friend class buffer_reader;
   
       friend GR_RUNTIME_API buffer_sptr make_buffer(int nitems,
                                                     size_t sizeof_item,
                                                     uint64_t downstream_lcm_nitems,
                                                     block_sptr link,
                                                     block_sptr buf_owner);
   
       block_sptr d_buf_owner; // block that "owns" this buffer
   
       std::unique_ptr<char[]> d_buffer;
   
       buffer_single_mapped(int nitems,
                            size_t sizeof_item,
                            uint64_t downstream_lcm_nitems,
                            uint32_t downstream_max_out_mult,
                            block_sptr link,
                            block_sptr buf_owner);
   
       virtual bool input_blocked_callback_logic(int items_required,
                                                 int items_avail,
                                                 unsigned read_index,
                                                 char* buffer_ptr,
                                                 mem_func_t const& memcpy_func,
                                                 mem_func_t const& memmove_func);
   
       virtual bool output_blocked_callback_logic(int output_multiple,
                                                  bool force,
                                                  char* buffer_ptr,
                                                  mem_func_t const& memmove_func);
   };
   
   } /* namespace gr */
   
   
   #endif /* INCLUDED_GR_RUNTIME_BUFFER_SINGLE_MAPPED_H */
