
.. _program_listing_file_gnuradio_gr-analog_lib_feedforward_agc_cc_impl.h:

Program Listing for File feedforward_agc_cc_impl.h
==================================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gr-analog_lib_feedforward_agc_cc_impl.h>` (``gnuradio/gr-analog/lib/feedforward_agc_cc_impl.h``)

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
   
   #ifndef INCLUDED_ANALOG_FEEDFORWARD_AGC_CC_IMPL_H
   #define INCLUDED_ANALOG_FEEDFORWARD_AGC_CC_IMPL_H
   
   #include <gnuradio/analog/feedforward_agc_cc.h>
   
   namespace gr {
   namespace analog {
   
   class feedforward_agc_cc_impl : public feedforward_agc_cc
   {
   private:
       int d_nsamples;
       float d_reference;
   
   public:
       feedforward_agc_cc_impl(int nsamples, float reference);
       ~feedforward_agc_cc_impl() override;
   
       int work(int noutput_items,
                gr_vector_const_void_star& input_items,
                gr_vector_void_star& output_items) override;
   };
   
   } /* namespace analog */
   } /* namespace gr */
   
   #endif /* INCLUDED_ANALOG_FEEDFORWARD_AGC_CC_IMPL_H */
