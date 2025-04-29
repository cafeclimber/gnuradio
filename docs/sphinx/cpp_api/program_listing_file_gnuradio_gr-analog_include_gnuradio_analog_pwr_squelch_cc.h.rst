
.. _program_listing_file_gnuradio_gr-analog_include_gnuradio_analog_pwr_squelch_cc.h:

Program Listing for File pwr_squelch_cc.h
=========================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gr-analog_include_gnuradio_analog_pwr_squelch_cc.h>` (``gnuradio/gr-analog/include/gnuradio/analog/pwr_squelch_cc.h``)

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
   
   #ifndef INCLUDED_ANALOG_PWR_SQUELCH_CC_H
   #define INCLUDED_ANALOG_PWR_SQUELCH_CC_H
   
   #include <gnuradio/analog/api.h>
   #include <gnuradio/analog/squelch_base_cc.h>
   #include <cmath>
   
   namespace gr {
   namespace analog {
   
   class ANALOG_API pwr_squelch_cc : public squelch_base_cc, virtual public block
   {
   protected:
       void update_state(const gr_complex& in) override = 0;
       bool mute() const override = 0;
   
   public:
       // gr::analog::pwr_squelch_cc::sptr
       typedef std::shared_ptr<pwr_squelch_cc> sptr;
   
       static sptr make(double db, double alpha = 0.0001, int ramp = 0, bool gate = false);
   
       std::vector<float> squelch_range() const override = 0;
   
       virtual double threshold() const = 0;
       virtual void set_threshold(double db) = 0;
       virtual void set_alpha(double alpha) = 0;
   
       int ramp() const override = 0;
       void set_ramp(int ramp) override = 0;
       bool gate() const override = 0;
       void set_gate(bool gate) override = 0;
       bool unmuted() const override = 0;
   };
   
   } /* namespace analog */
   } /* namespace gr */
   
   #endif /* INCLUDED_ANALOG_PWR_SQUELCH_CC_H */
