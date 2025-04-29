
.. _program_listing_file_gnuradio_gr-analog_include_gnuradio_analog_sig_source_waveform.h:

Program Listing for File sig_source_waveform.h
==============================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gr-analog_include_gnuradio_analog_sig_source_waveform.h>` (``gnuradio/gr-analog/include/gnuradio/analog/sig_source_waveform.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2004,2012 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef INCLUDED_ANALOG_SIG_SOURCE_WAVEFORM_H
   #define INCLUDED_ANALOG_SIG_SOURCE_WAVEFORM_H
   
   namespace gr {
   namespace analog {
   
   typedef enum {
       GR_CONST_WAVE = 100,
       GR_SIN_WAVE,
       GR_COS_WAVE,
       GR_SQR_WAVE,
       GR_TRI_WAVE,
       GR_SAW_WAVE
   } gr_waveform_t;
   
   } /* namespace analog */
   } /* namespace gr */
   
   #endif /* INCLUDED_ANALOG_SIG_SOURCE_WAVEFORM_H */
