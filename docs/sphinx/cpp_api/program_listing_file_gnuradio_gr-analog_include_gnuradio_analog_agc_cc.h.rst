
.. _program_listing_file_gnuradio_gr-analog_include_gnuradio_analog_agc_cc.h:

Program Listing for File agc_cc.h
=================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gr-analog_include_gnuradio_analog_agc_cc.h>` (``gnuradio/gr-analog/include/gnuradio/analog/agc_cc.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2006,2012 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef INCLUDED_ANALOG_AGC_CC_H
   #define INCLUDED_ANALOG_AGC_CC_H
   
   #include <gnuradio/analog/agc.h>
   #include <gnuradio/analog/api.h>
   #include <gnuradio/sync_block.h>
   
   namespace gr {
   namespace analog {
   
   class ANALOG_API agc_cc : virtual public sync_block
   {
   public:
       // gr::analog::agc_cc::sptr
       typedef std::shared_ptr<agc_cc> sptr;
   
       static sptr make(float rate = 1e-4,
                        float reference = 1.0,
                        float gain = 1.0,
                        float max_gain = 0.0);
   
       virtual float rate() const = 0;
       virtual float reference() const = 0;
       virtual float gain() const = 0;
       virtual float max_gain() const = 0;
   
       virtual void set_rate(float rate) = 0;
       virtual void set_reference(float reference) = 0;
       virtual void set_gain(float gain) = 0;
       virtual void set_max_gain(float max_gain) = 0;
   };
   
   } /* namespace analog */
   } /* namespace gr */
   
   #endif /* INCLUDED_ANALOG_AGC_CC_H */
