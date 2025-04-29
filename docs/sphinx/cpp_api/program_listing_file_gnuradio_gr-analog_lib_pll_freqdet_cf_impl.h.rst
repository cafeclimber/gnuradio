
.. _program_listing_file_gnuradio_gr-analog_lib_pll_freqdet_cf_impl.h:

Program Listing for File pll_freqdet_cf_impl.h
==============================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gr-analog_lib_pll_freqdet_cf_impl.h>` (``gnuradio/gr-analog/lib/pll_freqdet_cf_impl.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2004,2011,2012 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef INCLUDED_ANALOG_PLL_FREQDET_CF_IMPL_H
   #define INCLUDED_ANALOG_PLL_FREQDET_CF_IMPL_H
   
   #include <gnuradio/analog/pll_freqdet_cf.h>
   
   namespace gr {
   namespace analog {
   
   class pll_freqdet_cf_impl : public pll_freqdet_cf
   {
   public:
       pll_freqdet_cf_impl(float loop_bw, float max_freq, float min_freq);
       ~pll_freqdet_cf_impl() override;
   
       int work(int noutput_items,
                gr_vector_const_void_star& input_items,
                gr_vector_void_star& output_items) override;
   };
   
   } /* namespace analog */
   } /* namespace gr */
   
   #endif /* INCLUDED_ANALOG_PLL_FREQDET_CF_IMPL_H */
