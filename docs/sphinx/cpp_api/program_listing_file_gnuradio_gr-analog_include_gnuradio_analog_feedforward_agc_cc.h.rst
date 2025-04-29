
.. _program_listing_file_gnuradio_gr-analog_include_gnuradio_analog_feedforward_agc_cc.h:

Program Listing for File feedforward_agc_cc.h
=============================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gr-analog_include_gnuradio_analog_feedforward_agc_cc.h>` (``gnuradio/gr-analog/include/gnuradio/analog/feedforward_agc_cc.h``)

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
   
   #ifndef INCLUDED_ANALOG_FEEDFORWARD_AGC_CC_H
   #define INCLUDED_ANALOG_FEEDFORWARD_AGC_CC_H
   
   #include <gnuradio/analog/api.h>
   #include <gnuradio/sync_block.h>
   
   namespace gr {
   namespace analog {
   
   class ANALOG_API feedforward_agc_cc : virtual public sync_block
   {
   public:
       // gr::analog::feedforward_agc_cc::sptr
       typedef std::shared_ptr<feedforward_agc_cc> sptr;
   
       static sptr make(int nsamples, float reference);
   };
   
   } /* namespace analog */
   } /* namespace gr */
   
   #endif /* INCLUDED_GR_FEEDFORWARD_AGC_CC_H */
