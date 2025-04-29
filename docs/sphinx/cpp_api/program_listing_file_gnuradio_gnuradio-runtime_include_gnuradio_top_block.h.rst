
.. _program_listing_file_gnuradio_gnuradio-runtime_include_gnuradio_top_block.h:

Program Listing for File top_block.h
====================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_include_gnuradio_top_block.h>` (``gnuradio/gnuradio-runtime/include/gnuradio/top_block.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2007-2009,2013 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef INCLUDED_GR_TOP_BLOCK_H
   #define INCLUDED_GR_TOP_BLOCK_H
   
   #include <gnuradio/api.h>
   #include <gnuradio/hier_block2.h>
   
   namespace gr {
   
   class top_block_impl;
   
   GR_RUNTIME_API top_block_sptr make_top_block(const std::string& name,
                                                bool catch_exceptions = true);
   
   class GR_RUNTIME_API top_block : public hier_block2
   {
   private:
       template <typename T, typename... Args>
       friend std::shared_ptr<T> gnuradio::make_block_sptr(Args&&... args);
   
   
       std::unique_ptr<top_block_impl> d_impl;
   
   protected:
       top_block(const std::string& name, bool catch_exceptions = true);
   
   public:
       ~top_block() override;
   
       void run(int max_noutput_items = 100000000);
   
       void start(int max_noutput_items = 100000000);
   
       void stop();
   
       void wait();
   
       void lock() override;
   
       void unlock() override;
   
       std::string edge_list();
   
       std::string msg_edge_list();
   
       void dump();
   
       int max_noutput_items();
   
       void set_max_noutput_items(int nmax);
   
       top_block_sptr to_top_block(); // Needed for Python type coercion
   
       void setup_rpc() override;
   };
   
   inline top_block_sptr cast_to_top_block_sptr(basic_block_sptr block)
   {
       return std::dynamic_pointer_cast<top_block, basic_block>(block);
   }
   
   } // namespace gr
   
   #endif /* INCLUDED_GR_TOP_BLOCK_H */
