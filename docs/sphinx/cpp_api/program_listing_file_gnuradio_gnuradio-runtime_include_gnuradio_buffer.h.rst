
.. _program_listing_file_gnuradio_gnuradio-runtime_include_gnuradio_buffer.h:

Program Listing for File buffer.h
=================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_include_gnuradio_buffer.h>` (``gnuradio/gnuradio-runtime/include/gnuradio/buffer.h``)

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
   
   #ifndef INCLUDED_GR_RUNTIME_BUFFER_H
   #define INCLUDED_GR_RUNTIME_BUFFER_H
   
   #include <gnuradio/api.h>
   #include <gnuradio/custom_lock.h>
   #include <gnuradio/logger.h>
   #include <gnuradio/runtime_types.h>
   #include <gnuradio/tags.h>
   #include <gnuradio/thread/thread.h>
   #include <gnuradio/transfer_type.h>
   
   #include <functional>
   #include <iostream>
   #include <map>
   #include <memory>
   
   
   namespace gr {
   
   class vmcircbuf;
   class buffer_reader;
   class buffer_reader_sm;
   
   enum class buffer_mapping_type { double_mapped, single_mapped };
   
   typedef std::function<void*(void*, const void*, std::size_t)> mem_func_t;
   
   GR_RUNTIME_API buffer_sptr make_buffer(int nitems,
                                          size_t sizeof_item,
                                          uint64_t downstream_lcm_nitems,
                                          uint32_t downstream_max_out_mult,
                                          block_sptr link = block_sptr(),
                                          block_sptr buf_owner = block_sptr());
   
   class GR_RUNTIME_API buffer : public custom_lock_if
   {
   public:
       gr::logger_ptr d_logger;
       gr::logger_ptr d_debug_logger;
   
       ~buffer() override;
   
       buffer_mapping_type get_mapping_type() { return d_buf_map_type; }
   
       virtual int space_available() = 0;
   
       unsigned int bufsize() const { return d_bufsize; }
   
       const char* base() const { return static_cast<const char*>(d_base); }
   
       virtual void* write_pointer();
   
       virtual const void* _read_pointer(unsigned int read_index);
   
       void update_write_pointer(int nitems);
   
       void set_done(bool done);
       bool done() const { return d_done; }
   
       block_sptr link() { return block_sptr(d_link); }
   
       size_t nreaders() const { return d_readers.size(); }
       buffer_reader* reader(size_t index) { return d_readers[index]; }
   
       gr::thread::mutex* mutex() { return &d_mutex; }
   
       uint64_t nitems_written() { return d_abs_write_offset; }
   
       void reset_nitem_counter()
       {
           d_write_index = 0;
           d_abs_write_offset = 0;
       }
   
       size_t get_sizeof_item() { return d_sizeof_item; }
   
       uint64_t get_downstream_lcm_nitems() { return d_downstream_lcm_nitems; }
   
       uint32_t get_max_reader_output_multiple() { return d_max_reader_output_multiple; }
   
       virtual void update_reader_block_history(unsigned history, [[maybe_unused]] int delay)
       {
           d_max_reader_history = std::max(d_max_reader_history, history);
           d_has_history = (d_max_reader_history > 1);
       }
   
       void add_item_tag(const tag_t& tag);
   
       void remove_item_tag(const tag_t& tag, long id);
   
       void prune_tags(uint64_t max_time);
   
       std::multimap<uint64_t, tag_t>::iterator get_tags_begin()
       {
           return d_item_tags.begin();
       }
       std::multimap<uint64_t, tag_t>::iterator get_tags_end() { return d_item_tags.end(); }
       std::multimap<uint64_t, tag_t>::iterator get_tags_lower_bound(uint64_t x)
       {
           return d_item_tags.lower_bound(x);
       }
       std::multimap<uint64_t, tag_t>::iterator get_tags_upper_bound(uint64_t x)
       {
           return d_item_tags.upper_bound(x);
       }
   
       virtual void post_work(int nitems) = 0;
   
       virtual bool input_blkd_cb_ready([[maybe_unused]] int items_required,
                                        [[maybe_unused]] unsigned read_index)
       {
           return false;
       }
   
       virtual bool input_blocked_callback([[maybe_unused]] int items_required,
                                           [[maybe_unused]] int items_avail,
                                           [[maybe_unused]] unsigned read_index)
       {
           return false;
       }
   
       virtual bool output_blkd_cb_ready([[maybe_unused]] int output_multiple)
       {
           return false;
       }
   
       virtual bool output_blocked_callback([[maybe_unused]] int output_multiple,
                                            [[maybe_unused]] bool force = false)
       {
           return false;
       }
   
       inline void increment_active()
       {
           gr::thread::scoped_lock lock(d_mutex);
   
           d_cv.wait(lock, [this]() { return d_callback_flag == false; });
           ++d_active_pointer_counter;
       }
   
       inline void decrement_active()
       {
           gr::thread::scoped_lock lock(d_mutex);
   
           if (--d_active_pointer_counter == 0)
               d_cv.notify_all();
       }
   
       void on_lock(gr::thread::scoped_lock& lock) override;
   
       void on_unlock() override;
   
       friend std::ostream& operator<<(std::ostream& os, const buffer& buf);
   
       // -------------------------------------------------------------------------
   
       void set_transfer_type(const transfer_type& type);
   
   private:
       friend class buffer_reader;
       friend class buffer_reader_sm;
   
       friend GR_RUNTIME_API buffer_sptr make_buffer(int nitems,
                                                     size_t sizeof_item,
                                                     uint64_t downstream_lcm_nitems,
                                                     block_sptr link);
       friend GR_RUNTIME_API buffer_reader_sptr buffer_add_reader(buffer_sptr buf,
                                                                  int nzero_preload,
                                                                  block_sptr link,
                                                                  int delay);
   
   protected:
       char* d_base;           // base address of buffer inside d_vmcircbuf.
       unsigned int d_bufsize; // in items
       buffer_mapping_type d_buf_map_type;
   
       // Keep track of maximum sample delay of any reader; Only prune tags past this.
       unsigned d_max_reader_delay;
   
       // Keep track of the maximum sample history requirements of all blocks that
       // consume from this buffer
       unsigned d_max_reader_history;
   
       // Indicates if d_max_reader_history > 1
       bool d_has_history;
   
       size_t d_sizeof_item; // in bytes
       std::vector<buffer_reader*> d_readers;
       std::weak_ptr<block> d_link; // block that writes to this buffer
   
       //
       // The mutex protects d_write_index, d_abs_write_offset, d_done, d_item_tags
       // and the d_read_index's and d_abs_read_offset's in the buffer readers.
       // Also d_callback_flag and d_active_pointer_counter.
       //
       gr::thread::mutex d_mutex;
       unsigned int d_write_index;  // in items [0,d_bufsize)
       uint64_t d_abs_write_offset; // num items written since the start
       bool d_done;
       std::multimap<uint64_t, tag_t> d_item_tags;
       uint64_t d_last_min_items_read;
       //
       gr::thread::condition_variable d_cv;
       bool d_callback_flag;
       uint32_t d_active_pointer_counter;
   
       uint64_t d_downstream_lcm_nitems;
       uint64_t d_write_multiple;
       uint32_t d_max_reader_output_multiple;
   
       transfer_type d_transfer_type;
   
       virtual unsigned index_add(unsigned a, unsigned b) = 0;
   
       virtual unsigned index_sub(unsigned a, unsigned b) = 0;
   
       virtual bool allocate_buffer([[maybe_unused]] int nitems) { return false; };
   
       buffer(buffer_mapping_type buftype,
              int nitems,
              size_t sizeof_item,
              uint64_t downstream_lcm_nitems,
              uint32_t downstream_max_out_mult,
              block_sptr link);
   
       void drop_reader(buffer_reader* reader);
   };
   
   GR_RUNTIME_API long buffer_ncurrently_allocated();
   
   } /* namespace gr */
   
   #endif /* INCLUDED_GR_RUNTIME_BUFFER_H */
