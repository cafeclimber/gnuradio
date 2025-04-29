
.. _program_listing_file_gnuradio_gnuradio-runtime_include_gnuradio_buffer_reader_sm.h:

Program Listing for File buffer_reader_sm.h
===========================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_include_gnuradio_buffer_reader_sm.h>` (``gnuradio/gnuradio-runtime/include/gnuradio/buffer_reader_sm.h``)

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
   
   #ifndef INCLUDED_GR_RUNTIME_BUFFER_READER_SM_H
   #define INCLUDED_GR_RUNTIME_BUFFER_READER_SM_H
   
   #include <gnuradio/api.h>
   #include <gnuradio/buffer.h>
   #include <gnuradio/buffer_reader.h>
   #include <gnuradio/runtime_types.h>
   
   namespace gr {
   
   class GR_RUNTIME_API buffer_reader_sm : public buffer_reader
   {
   public:
       ~buffer_reader_sm();
   
       virtual int items_available() const;
   
       virtual bool input_blkd_cb_ready(int items_required) const;
   
       virtual bool input_blocked_callback(int items_required, int items_avail);
   
   private:
       friend class buffer;
       friend class buffer_single_mapped;
   
       friend GR_RUNTIME_API buffer_reader_sptr buffer_add_reader(buffer_sptr buf,
                                                                  int nzero_preload,
                                                                  block_sptr link,
                                                                  int delay);
   
       buffer_reader_sm(buffer_sptr buffer, unsigned int read_index, block_sptr link);
   };
   
   } // namespace gr
   
   #endif /* INCLUDED_GR_RUNTIME_BUFFER_READER_SM_H */
