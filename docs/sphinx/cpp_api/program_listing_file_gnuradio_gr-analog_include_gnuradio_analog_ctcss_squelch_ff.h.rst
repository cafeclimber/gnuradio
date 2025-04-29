
.. _program_listing_file_gnuradio_gr-analog_include_gnuradio_analog_ctcss_squelch_ff.h:

Program Listing for File ctcss_squelch_ff.h
===========================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gr-analog_include_gnuradio_analog_ctcss_squelch_ff.h>` (``gnuradio/gr-analog/include/gnuradio/analog/ctcss_squelch_ff.h``)

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
   
   #ifndef INCLUDED_ANALOG_CTCSS_SQUELCH_FF_H
   #define INCLUDED_ANALOG_CTCSS_SQUELCH_FF_H
   
   #include <gnuradio/analog/api.h>
   #include <gnuradio/analog/squelch_base_ff.h>
   #include <gnuradio/block.h>
   
   namespace gr {
   namespace analog {
   
   class ANALOG_API ctcss_squelch_ff : public squelch_base_ff, virtual public block
   {
   protected:
       void update_state(const float& in) override = 0;
       bool mute() const override = 0;
   
   public:
       // gr::analog::ctcss_squelch_ff::sptr
       typedef std::shared_ptr<ctcss_squelch_ff> sptr;
   
       static sptr make(int rate, float freq, float level, int len, int ramp, bool gate);
   
       std::vector<float> squelch_range() const override = 0;
       virtual float level() const = 0;
       virtual void set_level(float level) = 0;
       virtual int len() const = 0;
       virtual float frequency() const = 0;
       virtual void set_frequency(float frequency) = 0;
   
       int ramp() const override = 0;
       void set_ramp(int ramp) override = 0;
       bool gate() const override = 0;
       void set_gate(bool gate) override = 0;
       bool unmuted() const override = 0;
   };
   
   } /* namespace analog */
   } /* namespace gr */
   
   #endif /* INCLUDED_ANALOG_CTCSS_SQUELCH_FF_H */
