
.. _program_listing_file_gnuradio_gr-audio_include_gnuradio_audio_source.h:

Program Listing for File source.h
=================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gr-audio_include_gnuradio_audio_source.h>` (``gnuradio/gr-audio/include/gnuradio/audio/source.h``)

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
   
   #ifndef INCLUDED_GR_AUDIO_SOURCE_H
   #define INCLUDED_GR_AUDIO_SOURCE_H
   
   #include <gnuradio/audio/api.h>
   #include <gnuradio/sync_block.h>
   
   namespace gr {
   namespace audio {
   
   class GR_AUDIO_API source : virtual public sync_block
   {
   public:
       typedef std::shared_ptr<source> sptr;
   
       static sptr
       make(int sampling_rate, const std::string device_name = "", bool ok_to_block = true);
   };
   
   } /* namespace audio */
   } /* namespace gr */
   
   #endif /* INCLUDED_GR_AUDIO_SOURCE_H */
