
.. _program_listing_file_gnuradio_gnuradio-runtime_include_pmt_pmt_pool.h:

Program Listing for File pmt_pool.h
===================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_include_pmt_pmt_pool.h>` (``gnuradio/gnuradio-runtime/include/pmt/pmt_pool.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2007,2009,2013 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   #ifndef INCLUDED_PMT_POOL_H
   #define INCLUDED_PMT_POOL_H
   
   #include <condition_variable>
   #include <pmt/api.h>
   #include <cstddef>
   #include <mutex>
   #include <vector>
   
   namespace pmt {
   
   class PMT_API pmt_pool
   {
   
       struct PMT_API item {
           struct item* d_next;
       };
   
       using scoped_lock = std::unique_lock<std::mutex>;
       mutable std::mutex d_mutex;
       std::condition_variable d_cond;
   
       size_t d_itemsize;
       size_t d_alignment;
       size_t d_allocation_size;
       size_t d_max_items;
       size_t d_n_items;
       item* d_freelist;
       std::vector<char*> d_allocations;
   
   public:
       pmt_pool(size_t itemsize,
                size_t alignment = 16,
                size_t allocation_size = 4096,
                size_t max_items = 0);
       ~pmt_pool();
   
       void* malloc();
       void free(void* p);
   };
   
   } /* namespace pmt */
   
   #endif /* INCLUDED_PMT_POOL_H */
