
.. _program_listing_file_gnuradio_gnuradio-runtime_include_gnuradio_tags.h:

Program Listing for File tags.h
===============================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_include_gnuradio_tags.h>` (``gnuradio/gnuradio-runtime/include/gnuradio/tags.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2011,2013 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef INCLUDED_GR_TAGS_H
   #define INCLUDED_GR_TAGS_H
   
   #include <gnuradio/api.h>
   #include <pmt/pmt.h>
   
   namespace gr {
   
   struct GR_RUNTIME_API tag_t {
       uint64_t offset;
   
       pmt::pmt_t key;
   
       pmt::pmt_t value;
   
       pmt::pmt_t srcid;
   
       std::vector<long> marked_deleted;
   
       friend inline bool operator<(const tag_t& x, const tag_t& y)
       {
           return x.offset < y.offset;
       }
       static inline bool offset_compare(const tag_t& x, const tag_t& y) { return x < y; }
   
       inline bool operator==(const tag_t& t) const
       {
           return (t.key == key) && (t.value == value) && (t.srcid == srcid) &&
                  (t.offset == offset);
       }
   
       tag_t()
           : offset(0),
             key(pmt::PMT_NIL),
             value(pmt::PMT_NIL),
             srcid(pmt::PMT_F) // consistent with default srcid value in block::add_item_tag
       {
       }
   
       tag_t(const tag_t& rhs)
           : offset(rhs.offset), key(rhs.key), value(rhs.value), srcid(rhs.srcid)
       {
       }
       tag_t& operator=(const tag_t& rhs)
       {
           if (this != &rhs) {
               offset = rhs.offset;
               key = rhs.key;
               value = rhs.value;
               srcid = rhs.srcid;
           }
           return (*this);
       }
   
       ~tag_t() {}
   };
   
   } /* namespace gr */
   
   #endif /*INCLUDED_GR_TAGS_H*/
