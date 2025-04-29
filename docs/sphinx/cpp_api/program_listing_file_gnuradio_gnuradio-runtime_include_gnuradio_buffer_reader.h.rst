
.. _program_listing_file_gnuradio_gnuradio-runtime_include_gnuradio_buffer_reader.h:

Program Listing for File buffer_reader.h
========================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_include_gnuradio_buffer_reader.h>` (``gnuradio/gnuradio-runtime/include/gnuradio/buffer_reader.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2004,2009-2011,2013 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef INCLUDED_GR_RUNTIME_BUFFER_READER_H
   #define INCLUDED_GR_RUNTIME_BUFFER_READER_H
   
   #include <gnuradio/api.h>
   #include <gnuradio/buffer.h>
   #include <gnuradio/logger.h>
   #include <gnuradio/runtime_types.h>
   #include <gnuradio/tags.h>
   #include <gnuradio/thread/thread.h>
   #include <memory>
   
   namespace gr {
   
   class buffer_reader_sm;
   
   GR_RUNTIME_API buffer_reader_sptr buffer_add_reader(buffer_sptr buf,
                                                       int nzero_preload,
                                                       block_sptr link = block_sptr(),
                                                       int delay = 0);
   
   GR_RUNTIME_API long buffer_ncurrently_allocated();
   
   
   // ---------------------------------------------------------------------------
   
   class GR_RUNTIME_API buffer_reader
   {
   public:
   #ifdef BUFFER_DEBUG
       gr::logger_ptr d_logger;
       gr::logger_ptr d_debug_logger;
   #endif
   
       virtual ~buffer_reader();
   
       void declare_sample_delay(unsigned delay);
   
       unsigned sample_delay() const;
   
       virtual int items_available() const;
   
       buffer_sptr buffer() const { return d_buffer; }
   
       int max_possible_items_available() const { return d_buffer->bufsize() - 1; }
   
       const void* read_pointer();
   
       /*
        * \brief tell buffer we read \p items from it
        */
       void update_read_pointer(int nitems);
   
       void set_done(bool done) { d_buffer->set_done(done); }
       bool done() const { return d_buffer->done(); }
   
       gr::thread::mutex* mutex() { return d_buffer->mutex(); }
   
       uint64_t nitems_read() const { return d_abs_read_offset; }
   
       void reset_nitem_counter()
       {
           d_read_index = 0;
           d_abs_read_offset = 0;
       }
   
       size_t get_sizeof_item() { return d_buffer->get_sizeof_item(); }
   
       block_sptr link() const { return block_sptr(d_link); }
   
       void get_tags_in_range(std::vector<tag_t>& v,
                              uint64_t abs_start,
                              uint64_t abs_end,
                              long id);
   
       virtual bool input_blkd_cb_ready(int items_required) const { return false; }
   
       virtual bool input_blocked_callback(int items_required, int items_avail)
       {
           return false;
       }
   
       // -------------------------------------------------------------------------
       unsigned int get_read_index() const { return d_read_index; }
       uint64_t get_abs_read_offset() const { return d_abs_read_offset; }
   
   protected:
       friend class buffer;
       friend class buffer_double_mapped;
       friend class buffer_single_mapped;
       friend class buffer_reader_sm;
   
       friend GR_RUNTIME_API buffer_reader_sptr buffer_add_reader(buffer_sptr buf,
                                                                  int nzero_preload,
                                                                  block_sptr link,
                                                                  int delay);
   
       buffer_sptr d_buffer;
       unsigned int d_read_index;   // in items [0,d->buffer.d_bufsize) ** see NB
       uint64_t d_abs_read_offset;  // num items seen since the start   ** see NB
       std::weak_ptr<block> d_link; // block that reads via this buffer reader
       unsigned d_attr_delay;       // sample delay attribute for tag propagation
       // ** NB: buffer::d_mutex protects d_read_index and d_abs_read_offset
   
       buffer_reader(buffer_sptr buffer, unsigned int read_index, block_sptr link);
   };
   
   GR_RUNTIME_API long buffer_reader_ncurrently_allocated();
   
   } /* namespace gr */
   
   #endif /* INCLUDED_GR_RUNTIME_BUFFER_READER_H */
