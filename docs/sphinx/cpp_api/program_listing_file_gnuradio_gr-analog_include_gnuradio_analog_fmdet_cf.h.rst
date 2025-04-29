
.. _program_listing_file_gnuradio_gr-analog_include_gnuradio_analog_fmdet_cf.h:

Program Listing for File fmdet_cf.h
===================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gr-analog_include_gnuradio_analog_fmdet_cf.h>` (``gnuradio/gr-analog/include/gnuradio/analog/fmdet_cf.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2008,2012 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef INCLUDED_ANALOG_FMDET_CF_H
   #define INCLUDED_ANALOG_FMDET_CF_H
   
   #include <gnuradio/analog/api.h>
   #include <gnuradio/sync_block.h>
   
   namespace gr {
   namespace analog {
   
   class ANALOG_API fmdet_cf : virtual public sync_block
   {
   public:
       // gr::analog::fmdet_cf::sptr
       typedef std::shared_ptr<fmdet_cf> sptr;
   
       static sptr make(float samplerate, float freq_low, float freq_high, float scl);
   
       virtual void set_scale(float scl) = 0;
       virtual void set_freq_range(float freq_low, float freq_high) = 0;
   
       virtual float freq() const = 0;
       virtual float freq_high() const = 0;
       virtual float freq_low() const = 0;
       virtual float scale() const = 0;
       virtual float bias() const = 0;
   };
   
   } /* namespace analog */
   } /* namespace gr */
   
   #endif /* INCLUDED_ANALOG_FMDET_CF_H */
