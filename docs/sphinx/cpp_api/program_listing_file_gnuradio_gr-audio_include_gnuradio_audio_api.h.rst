
.. _program_listing_file_gnuradio_gr-audio_include_gnuradio_audio_api.h:

Program Listing for File api.h
==============================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gr-audio_include_gnuradio_audio_api.h>` (``gnuradio/gr-audio/include/gnuradio/audio/api.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /*
    * Copyright 2011 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef INCLUDED_GR_AUDIO_API_H
   #define INCLUDED_GR_AUDIO_API_H
   
   #include <gnuradio/attributes.h>
   
   #ifdef gnuradio_audio_EXPORTS
   #define GR_AUDIO_API __GR_ATTR_EXPORT
   #else
   #define GR_AUDIO_API __GR_ATTR_IMPORT
   #endif
   
   #endif /* INCLUDED_GR_AUDIO_API_H */
