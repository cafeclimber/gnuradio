
.. _program_listing_file_gnuradio_gnuradio-runtime_include_gnuradio_block.h:

Program Listing for File block.h
================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_include_gnuradio_block.h>` (``gnuradio/gnuradio-runtime/include/gnuradio/block.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2004,2007,2009,2010,2013,2017 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef INCLUDED_GR_RUNTIME_BLOCK_H
   #define INCLUDED_GR_RUNTIME_BLOCK_H
   
   #include <memory>
   
   #include <gnuradio/api.h>
   #include <gnuradio/basic_block.h>
   #include <gnuradio/buffer_type.h>
   #include <gnuradio/config.h>
   #include <gnuradio/logger.h>
   #include <gnuradio/tags.h>
   #ifdef GR_MPLIB_MPIR
   #include <mpirxx.h>
   #else
   #include <gmpxx.h>
   #endif
   
   namespace gr {
   
   class GR_RUNTIME_API block : public basic_block
   {
   public:
       enum work_return_t { WORK_CALLED_PRODUCE = -2, WORK_DONE = -1 };
   
       enum tag_propagation_policy_t {
           TPP_DONT = 0, 
           TPP_ALL_TO_ALL = 1, 
           TPP_ONE_TO_ONE = 2, 
           TPP_CUSTOM = 3      
       };
   
       ~block() override;
   
       unsigned history() const;
       void set_history(unsigned history);
   
       void declare_sample_delay(int which, unsigned delay);
   
       void declare_sample_delay(unsigned delay);
   
       unsigned sample_delay(int which) const;
   
       bool fixed_rate() const { return d_fixed_rate; }
   
       // ----------------------------------------------------------------
       //      override these to define your behavior
       // ----------------------------------------------------------------
   
       virtual void forecast(int noutput_items, gr_vector_int& ninput_items_required);
   
       virtual int general_work(int noutput_items,
                                gr_vector_int& ninput_items,
                                gr_vector_const_void_star& input_items,
                                gr_vector_void_star& output_items);
   
       virtual bool start();
   
       virtual bool stop();
   
       // ----------------------------------------------------------------
   
       void set_output_multiple(int multiple);
       int output_multiple() const { return d_output_multiple; }
       bool output_multiple_set() const { return d_output_multiple_set; }
   
       void set_alignment(int multiple);
       int alignment() const { return d_output_multiple; }
   
       void set_unaligned(int na);
       int unaligned() const { return d_unaligned; }
       void set_is_unaligned(bool u);
       bool is_unaligned() const { return d_is_unaligned; }
   
       void consume(int which_input, int how_many_items);
   
       void consume_each(int how_many_items);
   
       void produce(int which_output, int how_many_items);
   
       void set_relative_rate(double relative_rate);
   
       void set_inverse_relative_rate(double inverse_relative_rate);
   
       void set_relative_rate(uint64_t interpolation, uint64_t decimation);
   
       double relative_rate() const { return d_relative_rate; }
   
       uint64_t relative_rate_i() const
       {
           return (uint64_t)d_mp_relative_rate.get_num().get_ui();
       }
   
       uint64_t relative_rate_d() const
       {
           return (uint64_t)d_mp_relative_rate.get_den().get_ui();
       }
   
       mpq_class& mp_relative_rate() { return d_mp_relative_rate; }
   
       /*
        * The following two methods provide special case info to the
        * scheduler in the event that a block has a fixed input to output
        * ratio.  sync_block, sync_decimator and
        * sync_interpolator override these.  If you're fixed rate,
        * subclass one of those.
        */
       virtual int fixed_rate_ninput_to_noutput(int ninput);
   
       virtual int fixed_rate_noutput_to_ninput(int noutput);
   
       uint64_t nitems_read(unsigned int which_input);
   
       uint64_t nitems_written(unsigned int which_output);
   
       tag_propagation_policy_t tag_propagation_policy();
   
       void set_tag_propagation_policy(tag_propagation_policy_t p);
   
       int min_noutput_items() const { return d_min_noutput_items; }
   
       void set_min_noutput_items(int m) { d_min_noutput_items = m; }
   
       int max_noutput_items();
   
       void set_max_noutput_items(int m);
   
       void unset_max_noutput_items();
   
       bool is_set_max_noutput_items();
   
       /*
        * Used to expand the vectors that hold the min/max buffer sizes.
        *
        * Specifically, when -1 is used, the vectors are just initialized
        * with 1 value; this is used by the flat_flowgraph to expand when
        * required to add a new value for new ports on these blocks.
        */
       void expand_minmax_buffer(int port);
   
       long max_output_buffer(size_t i);
   
       void set_max_output_buffer(long max_output_buffer);
   
       void set_max_output_buffer(int port, long max_output_buffer);
   
       long min_output_buffer(size_t i);
   
       void set_min_output_buffer(long min_output_buffer);
   
       void set_min_output_buffer(int port, long min_output_buffer);
   
       void set_blkd_input_timer_value(unsigned int timer_value_ms);
   
       unsigned int blkd_input_timer_value();
   
   
       void allocate_detail(int ninputs,
                            int noutputs,
                            const std::vector<int>& downstream_max_nitems_vec,
                            const std::vector<uint64_t>& downstream_lcm_nitems_vec,
                            const std::vector<uint32_t>& downstream_max_out_mult_vec);
   
       // --------------- Custom buffer-related functions -------------
   
       buffer_sptr replace_buffer(size_t src_port, size_t dst_port, block_sptr block_owner);
   
       // --------------- Performance counter functions -------------
   
       float pc_noutput_items();
   
       float pc_noutput_items_avg();
   
       float pc_noutput_items_var();
   
       float pc_nproduced();
   
       float pc_nproduced_avg();
   
       float pc_nproduced_var();
   
       float pc_input_buffers_full(int which);
   
       float pc_input_buffers_full_avg(int which);
   
       float pc_input_buffers_full_var(int which);
   
       std::vector<float> pc_input_buffers_full();
   
       std::vector<float> pc_input_buffers_full_avg();
   
       std::vector<float> pc_input_buffers_full_var();
   
       float pc_output_buffers_full(int which);
   
       float pc_output_buffers_full_avg(int which);
   
       float pc_output_buffers_full_var(int which);
   
       std::vector<float> pc_output_buffers_full();
   
       std::vector<float> pc_output_buffers_full_avg();
   
       std::vector<float> pc_output_buffers_full_var();
   
       float pc_work_time();
   
       float pc_work_time_avg();
   
       float pc_work_time_var();
   
       float pc_work_time_total();
   
       float pc_throughput_avg();
   
       void reset_perf_counters();
   
       void setup_pc_rpc();
   
       bool is_pc_rpc_set() const { return d_pc_rpc_set; }
   
       void no_pc_rpc() { d_pc_rpc_set = true; }
   
   
       // ----------------------------------------------------------------------------
       // Functions to handle thread affinity
   
       void set_processor_affinity(const std::vector<int>& mask) override;
   
       void unset_processor_affinity() override;
   
       std::vector<int> processor_affinity() override { return d_affinity; }
   
       int active_thread_priority();
   
       int thread_priority();
   
       int set_thread_priority(int priority);
   
       bool update_rate() const;
   
       // ----------------------------------------------------------------------------
   
       void system_handler(pmt::pmt_t msg);
   
       void set_log_level(const std::string& level) override;
   
       std::string log_level() override;
   
       bool finished();
   
   private:
       int d_output_multiple;
       bool d_output_multiple_set;
       int d_unaligned;
       bool d_is_unaligned;
       double d_relative_rate; // approx output_rate / input_rate
       mpq_class d_mp_relative_rate;
       block_detail_sptr d_detail; // implementation details
       unsigned d_history;
       unsigned d_attr_delay; // the block's sample delay
       bool d_fixed_rate;
       bool d_max_noutput_items_set; // if d_max_noutput_items is valid
       int d_max_noutput_items;      // value of max_noutput_items for this block
       int d_min_noutput_items;
       tag_propagation_policy_t
           d_tag_propagation_policy; // policy for moving tags downstream
       std::vector<int> d_affinity;  // thread affinity proc. mask
       int d_priority;               // thread priority level
       bool d_pc_rpc_set;
       bool d_update_rate; // should sched update rel rate?
       bool d_finished;    // true if msg ports think we are finished
   
   protected:
       block(void) {} // allows pure virtual interface sub-classes
       block(const std::string& name,
             gr::io_signature::sptr input_signature,
             gr::io_signature::sptr output_signature);
   
       void set_fixed_rate(bool fixed_rate) { d_fixed_rate = fixed_rate; }
   
       inline void add_item_tag(unsigned int which_output,
                                uint64_t abs_offset,
                                const pmt::pmt_t& key,
                                const pmt::pmt_t& value,
                                const pmt::pmt_t& srcid = pmt::PMT_F)
       {
           tag_t tag;
           tag.offset = abs_offset;
           tag.key = key;
           tag.value = value;
           tag.srcid = srcid;
           this->add_item_tag(which_output, tag);
       }
   
       void add_item_tag(unsigned int which_output, const tag_t& tag);
   
       inline void remove_item_tag(unsigned int which_input,
                                   uint64_t abs_offset,
                                   const pmt::pmt_t& key,
                                   const pmt::pmt_t& value,
                                   const pmt::pmt_t& srcid = pmt::PMT_F)
       {
           tag_t tag;
           tag.offset = abs_offset;
           tag.key = key;
           tag.value = value;
           tag.srcid = srcid;
           this->remove_item_tag(which_input, tag);
       }
   
       void remove_item_tag(unsigned int which_input, const tag_t& tag);
   
       void get_tags_in_range(std::vector<tag_t>& v,
                              unsigned int which_input,
                              uint64_t abs_start,
                              uint64_t abs_end);
   
       void get_tags_in_range(std::vector<tag_t>& v,
                              unsigned int which_input,
                              uint64_t abs_start,
                              uint64_t abs_end,
                              const pmt::pmt_t& key);
   
       void get_tags_in_window(std::vector<tag_t>& v,
                               unsigned int which_input,
                               uint64_t rel_start,
                               uint64_t rel_end);
   
       void get_tags_in_window(std::vector<tag_t>& v,
                               unsigned int which_input,
                               uint64_t rel_start,
                               uint64_t rel_end,
                               const pmt::pmt_t& key);
   
       void enable_update_rate(bool en);
   
       buffer_sptr allocate_buffer(size_t port,
                                   int downstream_max_nitems,
                                   uint64_t downstream_lcm_nitems,
                                   uint32_t downstream_max_out_mult);
   
       std::vector<long> d_max_output_buffer;
       std::vector<long> d_min_output_buffer;
   
       unsigned int d_blkd_input_timer_value = 250;
   
       mutable gr::thread::mutex d_setlock;
   
       // These are really only for internal use, but leaving them public avoids
       // having to work up an ever-varying list of friend GR_RUNTIME_APIs
   
       const pmt::pmt_t d_pmt_done;
   
       const pmt::pmt_t d_system_port;
   
   public:
       block_detail_sptr detail() const { return d_detail; }
       void set_detail(block_detail_sptr detail) { d_detail = detail; }
   
       void notify_msg_neighbors();
   
       void clear_finished() { d_finished = false; }
   
       std::string identifier() const;
   };
   
   typedef std::vector<block_sptr> block_vector_t;
   typedef std::vector<block_sptr>::iterator block_viter_t;
   
   inline block_sptr cast_to_block_sptr(basic_block_sptr p)
   {
       return std::dynamic_pointer_cast<block, basic_block>(p);
   }
   
   GR_RUNTIME_API std::ostream& operator<<(std::ostream& os, const block* m);
   
   } /* namespace gr */
   
   #endif /* INCLUDED_GR_RUNTIME_BLOCK_H */
