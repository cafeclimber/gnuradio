
.. _program_listing_file_gnuradio_gr-audio_lib_oss_oss_sink.h:

Program Listing for File oss_sink.h
===================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gr-audio_lib_oss_oss_sink.h>` (``gnuradio/gr-audio/lib/oss/oss_sink.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2004-2011,2013 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef INCLUDED_AUDIO_OSS_SINK_H
   #define INCLUDED_AUDIO_OSS_SINK_H
   
   #include <gnuradio/audio/sink.h>
   #include <string>
   
   namespace gr {
   namespace audio {
   
   class oss_sink : public sink
   {
       int d_sampling_rate;
       std::string d_device_name;
       int d_fd;
       short* d_buffer;
       int d_chunk_size;
   
   public:
       oss_sink(int sampling_rate,
                const std::string device_name = "",
                bool ok_to_block = true);
       ~oss_sink() override;
   
       int work(int noutput_items,
                gr_vector_const_void_star& input_items,
                gr_vector_void_star& output_items) override;
   };
   
   } /* namespace audio */
   } /* namespace gr */
   
   #endif /* INCLUDED_AUDIO_OSS_SINK_H */
