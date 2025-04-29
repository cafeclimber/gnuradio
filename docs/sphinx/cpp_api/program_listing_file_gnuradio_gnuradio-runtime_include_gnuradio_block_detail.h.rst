
.. _program_listing_file_gnuradio_gnuradio-runtime_include_gnuradio_block_detail.h:

Program Listing for File block_detail.h
=======================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_include_gnuradio_block_detail.h>` (``gnuradio/gnuradio-runtime/include/gnuradio/block_detail.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2004,2009,2010,2013 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef INCLUDED_GR_RUNTIME_BLOCK_DETAIL_H
   #define INCLUDED_GR_RUNTIME_BLOCK_DETAIL_H
   
   #include <gnuradio/api.h>
   #include <gnuradio/buffer.h>
   #include <gnuradio/buffer_reader.h>
   #include <gnuradio/high_res_timer.h>
   #include <gnuradio/logger.h>
   #include <gnuradio/runtime_types.h>
   #include <gnuradio/tags.h>
   #include <gnuradio/tpb_detail.h>
   #include <stdexcept>
   
   namespace gr {
   
   class GR_RUNTIME_API block_detail
   {
   public:
       ~block_detail();
   
       int ninputs() const { return d_ninputs; }
       int noutputs() const { return d_noutputs; }
       bool sink_p() const { return d_noutputs == 0; }
       bool source_p() const { return d_ninputs == 0; }
   
       void set_done(bool done);
       bool done() const { return d_done; }
   
       void set_input(unsigned int which, buffer_reader_sptr reader);
       buffer_reader_sptr input(unsigned int which)
       {
           if (which >= d_ninputs)
               throw std::invalid_argument("block_detail::input");
           return d_input[which];
       }
   
       void set_output(unsigned int which, buffer_sptr buffer);
       buffer_sptr output(unsigned int which)
       {
           if (which >= d_noutputs)
               throw std::invalid_argument("block_detail::output");
           return d_output[which];
       }
   
       void consume(int which_input, int how_many_items);
   
       void consume_each(int how_many_items);
   
       void produce(int which_output, int how_many_items);
   
       void produce_each(int how_many_items);
   
       // Return the number of items read on input stream which_input
       uint64_t nitems_read(unsigned int which_input);
   
       // Return the number of items written on output stream which_output
       uint64_t nitems_written(unsigned int which_output);
   
       // sets nitems_read and nitems_written to 0 for all input/output
       // buffers.
       void reset_nitem_counters();
   
       // Clears all tags from the input buffers.
       void clear_tags();
   
       void add_item_tag(unsigned int which_output, const tag_t& tag);
   
       void remove_item_tag(unsigned int which_input, const tag_t& tag, long id);
   
       void get_tags_in_range(std::vector<tag_t>& v,
                              unsigned int which_input,
                              uint64_t abs_start,
                              uint64_t abs_end,
                              long id);
   
       void get_tags_in_range(std::vector<tag_t>& v,
                              unsigned int which_input,
                              uint64_t abs_start,
                              uint64_t abs_end,
                              const pmt::pmt_t& key,
                              long id);
   
       void set_processor_affinity(const std::vector<int>& mask);
   
       void unset_processor_affinity();
   
       int thread_priority();
   
       int set_thread_priority(int priority);
   
       void post_work_cleanup()
       {
           // Decrement active counts for all inputs and outputs
           for (int i = 0; i < noutputs(); i++)
               output(i)->decrement_active();
           for (int i = 0; i < ninputs(); i++)
               input(i)->buffer()->decrement_active();
       }
   
       bool threaded;                  // set if thread is currently running.
       gr::thread::gr_thread_t thread; // portable thread handle
   
       void start_perf_counters();
       void stop_perf_counters(int noutput_items, int nproduced);
       void reset_perf_counters();
   
       // Calls to get performance counter items
       float pc_noutput_items();
       float pc_nproduced();
       float pc_input_buffers_full(size_t which);
       std::vector<float> pc_input_buffers_full();
       float pc_output_buffers_full(size_t which);
       std::vector<float> pc_output_buffers_full();
       float pc_work_time();
   
       float pc_noutput_items_avg();
       float pc_nproduced_avg();
       float pc_input_buffers_full_avg(size_t which);
       std::vector<float> pc_input_buffers_full_avg();
       float pc_output_buffers_full_avg(size_t which);
       std::vector<float> pc_output_buffers_full_avg();
       float pc_work_time_avg();
       float pc_throughput_avg();
   
       float pc_noutput_items_var();
       float pc_nproduced_var();
       float pc_input_buffers_full_var(size_t which);
       std::vector<float> pc_input_buffers_full_var();
       float pc_output_buffers_full_var(size_t which);
       std::vector<float> pc_output_buffers_full_var();
       float pc_work_time_var();
   
       float pc_work_time_total();
   
       tpb_detail d_tpb; // used by thread-per-block scheduler
       int d_produce_or;
   
       int consumed() const;
   
       // necessary because stupidly block_executor.cc's "propagate_tags" is a function, not
       // any class member
       gr::logger_ptr d_logger, d_debug_logger;
   
       // ----------------------------------------------------------------------------
   
   private:
       unsigned int d_ninputs;
       unsigned int d_noutputs;
       std::vector<buffer_reader_sptr> d_input;
       std::vector<buffer_sptr> d_output;
       bool d_done;
       int d_consumed;
   
       // Performance counters
       float d_ins_noutput_items;
       float d_avg_noutput_items;
       float d_var_noutput_items;
       float d_total_noutput_items;
       gr::high_res_timer_type d_pc_start_time;
       gr::high_res_timer_type d_pc_last_work_time;
       float d_ins_nproduced;
       float d_avg_nproduced;
       float d_var_nproduced;
       std::vector<float> d_ins_input_buffers_full;
       std::vector<float> d_avg_input_buffers_full;
       std::vector<float> d_var_input_buffers_full;
       std::vector<float> d_ins_output_buffers_full;
       std::vector<float> d_avg_output_buffers_full;
       std::vector<float> d_var_output_buffers_full;
       gr::high_res_timer_type d_start_of_work, d_end_of_work;
       float d_ins_work_time;
       float d_avg_work_time;
       float d_var_work_time;
       float d_total_work_time;
       float d_avg_throughput;
       float d_pc_counter;
   
       block_detail(unsigned int ninputs, unsigned int noutputs);
   
       friend struct tpb_detail;
   
       friend GR_RUNTIME_API block_detail_sptr make_block_detail(unsigned int ninputs,
                                                                 unsigned int noutputs);
   };
   
   GR_RUNTIME_API block_detail_sptr make_block_detail(unsigned int ninputs,
                                                      unsigned int noutputs);
   
   GR_RUNTIME_API long block_detail_ncurrently_allocated();
   
   } /* namespace gr */
   
   #endif /* INCLUDED_GR_RUNTIME_BLOCK_DETAIL_H */
