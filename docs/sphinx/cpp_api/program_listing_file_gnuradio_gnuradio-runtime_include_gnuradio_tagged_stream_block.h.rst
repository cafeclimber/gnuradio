
.. _program_listing_file_gnuradio_gnuradio-runtime_include_gnuradio_tagged_stream_block.h:

Program Listing for File tagged_stream_block.h
==============================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_include_gnuradio_tagged_stream_block.h>` (``gnuradio/gnuradio-runtime/include/gnuradio/tagged_stream_block.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2013 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef INCLUDED_GR_RUNTIME_TAGGED_STREAM_BLOCK_H
   #define INCLUDED_GR_RUNTIME_TAGGED_STREAM_BLOCK_H
   
   #include <gnuradio/api.h>
   #include <gnuradio/block.h>
   
   namespace gr {
   
   class GR_RUNTIME_API tagged_stream_block : public block
   {
   private:
       pmt::pmt_t
           d_length_tag_key; 
       gr_vector_int
           d_n_input_items_reqd; 
   
   protected:
       std::string d_length_tag_key_str;
       tagged_stream_block(void) {} // allows pure virtual interface sub-classes
       tagged_stream_block(const std::string& name,
                           gr::io_signature::sptr input_signature,
                           gr::io_signature::sptr output_signature,
                           const std::string& length_tag_key);
   
       virtual void parse_length_tags(const std::vector<std::vector<tag_t>>& tags,
                                      gr_vector_int& n_input_items_reqd);
   
       virtual int calculate_output_stream_length(const gr_vector_int& ninput_items);
   
       virtual void update_length_tags(int n_produced, int n_ports);
   
   public:
       void /* final */ forecast(int noutput_items,
                                 gr_vector_int& ninput_items_required) override;
   
       bool check_topology(int ninputs, int /* noutputs */) override;
   
       int general_work(int noutput_items,
                        gr_vector_int& ninput_items,
                        gr_vector_const_void_star& input_items,
                        gr_vector_void_star& output_items) override;
   
       virtual int work(int noutput_items,
                        gr_vector_int& ninput_items,
                        gr_vector_const_void_star& input_items,
                        gr_vector_void_star& output_items) = 0;
   };
   
   } /* namespace gr */
   
   #endif /* INCLUDED_GR_RUNTIME_TAGGED_STREAM_BLOCK_H */
