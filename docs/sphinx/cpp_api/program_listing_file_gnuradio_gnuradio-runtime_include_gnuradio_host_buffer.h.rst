
.. _program_listing_file_gnuradio_gnuradio-runtime_include_gnuradio_host_buffer.h:

Program Listing for File host_buffer.h
======================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_include_gnuradio_host_buffer.h>` (``gnuradio/gnuradio-runtime/include/gnuradio/host_buffer.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2021 BlackLynx Inc.
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    */
   
   #ifndef INCLUDED_HOST_BUFFER_H
   #define INCLUDED_HOST_BUFFER_H
   
   #include <gnuradio/buffer_single_mapped.h>
   #include <gnuradio/buffer_type.h>
   #include <cstddef>
   
   namespace gr {
   
   
   class GR_RUNTIME_API host_buffer : public buffer_single_mapped
   {
   public:
       static void* device_memcpy(void* dest, const void* src, std::size_t count);
       static void* device_memmove(void* dest, const void* src, std::size_t count);
   
       static buffer_type type;
   
       static buffer_sptr make_buffer(int nitems,
                                      size_t sizeof_item,
                                      uint64_t downstream_lcm_nitems,
                                      uint32_t downstream_max_out_mult,
                                      block_sptr link = block_sptr(),
                                      block_sptr buf_owner = block_sptr());
   
       ~host_buffer() override;
   
       void post_work(int nitems) override;
   
       bool do_allocate_buffer(size_t final_nitems, size_t sizeof_item) override;
   
       void* write_pointer() override;
   
       const void* _read_pointer(unsigned int read_index) override;
   
       bool input_blocked_callback(int items_required,
                                   int items_avail,
                                   unsigned read_index) override;
   
       bool output_blocked_callback(int output_multiple, bool force) override;
   
       static buffer_sptr make_host_buffer(int nitems,
                                           std::size_t sizeof_item,
                                           uint64_t downstream_lcm_nitems,
                                           uint32_t downstream_max_out_mult,
                                           block_sptr link,
                                           block_sptr buf_owner);
   
   private:
       // This is the simulated device buffer
       std::unique_ptr<char[]> d_device_buf;
       char* d_device_base;
   
       host_buffer(int nitems,
                   size_t sizeof_item,
                   uint64_t downstream_lcm_nitems,
                   uint32_t downstream_max_out_mult,
                   block_sptr link,
                   block_sptr buf_owner);
   };
   
   } // namespace gr
   
   #endif /* INCLUDED_HOST_BUFFER_H */
