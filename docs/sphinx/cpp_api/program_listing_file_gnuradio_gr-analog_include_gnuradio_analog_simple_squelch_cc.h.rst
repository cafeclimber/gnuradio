
.. _program_listing_file_gnuradio_gr-analog_include_gnuradio_analog_simple_squelch_cc.h:

Program Listing for File simple_squelch_cc.h
============================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gr-analog_include_gnuradio_analog_simple_squelch_cc.h>` (``gnuradio/gr-analog/include/gnuradio/analog/simple_squelch_cc.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2005,2012 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef INCLUDED_ANALOG_SIMPLE_SQUELCH_CC_H
   #define INCLUDED_ANALOG_SIMPLE_SQUELCH_CC_H
   
   #include <gnuradio/analog/api.h>
   #include <gnuradio/sync_block.h>
   
   namespace gr {
   namespace analog {
   
   class ANALOG_API simple_squelch_cc : virtual public sync_block
   {
   public:
       // gr::analog::simple_squelch_cc::sptr
       typedef std::shared_ptr<simple_squelch_cc> sptr;
   
       static sptr make(double threshold_db, double alpha);
   
       virtual bool unmuted() const = 0;
   
       virtual void set_alpha(double alpha) = 0;
       virtual void set_threshold(double decibels) = 0;
   
       virtual double threshold() const = 0;
       virtual std::vector<float> squelch_range() const = 0;
   };
   
   } /* namespace analog */
   } /* namespace gr */
   
   #endif /* INCLUDED_ANALOG_SIMPLE_SQUELCH_CC_H */
