
.. _program_listing_file_gnuradio_gr-audio_lib_portaudio_portaudio_impl.h:

Program Listing for File portaudio_impl.h
=========================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gr-audio_lib_portaudio_portaudio_impl.h>` (``gnuradio/gr-audio/lib/portaudio/portaudio_impl.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2006,2013 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef INCLUDED_AUDIO_PORTAUDIO_IMPL_H
   #define INCLUDED_AUDIO_PORTAUDIO_IMPL_H
   
   #include <gnuradio/logger.h>
   #include <portaudio.h>
   
   namespace gr {
   namespace audio {
   
   PaDeviceIndex pa_find_device_by_name(const char* name);
   void print_devices(const gr::logger_ptr& logger);
   
   } /* namespace audio */
   } /* namespace gr */
   
   #endif /* INCLUDED_AUDIO_PORTAUDIO_IMPL_H */
