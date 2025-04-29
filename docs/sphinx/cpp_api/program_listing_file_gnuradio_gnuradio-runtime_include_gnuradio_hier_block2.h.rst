
.. _program_listing_file_gnuradio_gnuradio-runtime_include_gnuradio_hier_block2.h:

Program Listing for File hier_block2.h
======================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_include_gnuradio_hier_block2.h>` (``gnuradio/gnuradio-runtime/include/gnuradio/hier_block2.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2006-2009,2013 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef INCLUDED_GR_RUNTIME_HIER_BLOCK2_H
   #define INCLUDED_GR_RUNTIME_HIER_BLOCK2_H
   
   #include <gnuradio/api.h>
   #include <gnuradio/basic_block.h>
   
   namespace gr {
   
   GR_RUNTIME_API hier_block2_sptr make_hier_block2(const std::string& name,
                                                    gr::io_signature::sptr input_signature,
                                                    gr::io_signature::sptr output_signature);
   
   class hier_block2_detail;
   
   class GR_RUNTIME_API hier_block2 : public basic_block
   {
   private:
       friend class hier_block2_detail;
       template <typename T, typename... Args>
       friend std::shared_ptr<T> gnuradio::make_block_sptr(Args&&... args);
   
       std::unique_ptr<hier_block2_detail> d_detail;
   
   
   protected:
       hier_block2(); // allows pure virtual interface sub-classes
       hier_block2(const std::string& name,
                   gr::io_signature::sptr input_signature,
                   gr::io_signature::sptr output_signature);
   
   public:
       ~hier_block2() override;
   
       typedef basic_block_sptr opaque_self;
   
       opaque_self self();
   
       void connect(basic_block_sptr block);
   
       void connect(basic_block_sptr src, int src_port, basic_block_sptr dst, int dst_port);
   
       void msg_connect(basic_block_sptr src,
                        pmt::pmt_t srcport,
                        basic_block_sptr dst,
                        pmt::pmt_t dstport);
       void msg_connect(basic_block_sptr src,
                        std::string srcport,
                        basic_block_sptr dst,
                        std::string dstport);
       void msg_disconnect(basic_block_sptr src,
                           pmt::pmt_t srcport,
                           basic_block_sptr dst,
                           pmt::pmt_t dstport);
       void msg_disconnect(basic_block_sptr src,
                           std::string srcport,
                           basic_block_sptr dst,
                           std::string dstport);
   
       void disconnect(basic_block_sptr block);
   
       void
       disconnect(basic_block_sptr src, int src_port, basic_block_sptr dst, int dst_port);
   
       void disconnect_all();
   
       virtual void lock();
   
       virtual void unlock();
   
       int max_output_buffer(size_t port = 0);
   
       void set_max_output_buffer(int max_output_buffer);
   
       void set_max_output_buffer(size_t port, int max_output_buffer);
   
       int min_output_buffer(size_t port = 0);
   
       void set_min_output_buffer(int min_output_buffer);
   
       void set_min_output_buffer(size_t port, int min_output_buffer);
   
   
       // This is a public method for ease of code organization, but should be
       // ignored by the user.
       flat_flowgraph_sptr flatten() const;
   
       hier_block2_sptr to_hier_block2(); // Needed for Python type coercion
   
       bool has_msg_port(pmt::pmt_t which_port) override
       {
           return message_port_is_hier(which_port) || basic_block::has_msg_port(which_port);
       }
   
       bool message_port_is_hier(pmt::pmt_t port_id) override
       {
           return message_port_is_hier_in(port_id) || message_port_is_hier_out(port_id);
       }
   
       bool message_port_is_hier_in(pmt::pmt_t port_id) override
       {
           return pmt::list_has(hier_message_ports_in, port_id);
       }
   
       bool message_port_is_hier_out(pmt::pmt_t port_id) override
       {
           return pmt::list_has(hier_message_ports_out, port_id);
       }
   
       pmt::pmt_t hier_message_ports_in;
       pmt::pmt_t hier_message_ports_out;
   
       void message_port_register_hier_in(pmt::pmt_t port_id)
       {
           if (pmt::list_has(hier_message_ports_in, port_id))
               throw std::invalid_argument(
                   "hier msg in port by this name already registered");
           if (msg_queue.find(port_id) != msg_queue.end())
               throw std::invalid_argument(
                   "block already has a primitive input port by this name");
           hier_message_ports_in = pmt::list_add(hier_message_ports_in, port_id);
       }
   
       void message_port_register_hier_out(pmt::pmt_t port_id)
       {
           if (pmt::list_has(hier_message_ports_out, port_id))
               throw std::invalid_argument(
                   "hier msg out port by this name already registered");
           if (pmt::dict_has_key(d_message_subscribers, port_id))
               throw std::invalid_argument(
                   "block already has a primitive output port by this name");
           hier_message_ports_out = pmt::list_add(hier_message_ports_out, port_id);
       }
   
       void set_processor_affinity(const std::vector<int>& mask) override;
   
       void unset_processor_affinity() override;
   
       std::vector<int> processor_affinity() override;
   
       void set_log_level(const std::string& level) override;
   
       std::string log_level() override;
   
       bool all_min_output_buffer_p(void);
   
       bool all_max_output_buffer_p(void);
   };
   
   GR_RUNTIME_API std::string dot_graph(hier_block2_sptr hierblock2);
   
   inline hier_block2_sptr cast_to_hier_block2_sptr(basic_block_sptr block)
   {
       return std::dynamic_pointer_cast<hier_block2, basic_block>(block);
   }
   
   } /* namespace gr */
   
   #endif /* INCLUDED_GR_RUNTIME_HIER_BLOCK2_H */
