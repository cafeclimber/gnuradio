
.. _program_listing_file_gnuradio_gr-analog_lib_rail_ff_impl.h:

Program Listing for File rail_ff_impl.h
=======================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gr-analog_lib_rail_ff_impl.h>` (``gnuradio/gr-analog/lib/rail_ff_impl.h``)

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
   
   #ifndef INCLUDED_ANALOG_RAIL_FF_IMPL_H
   #define INCLUDED_ANALOG_RAIL_FF_IMPL_H
   
   #include <gnuradio/analog/rail_ff.h>
   
   namespace gr {
   namespace analog {
   
   class rail_ff_impl : public rail_ff
   {
   private:
       float d_lo, d_hi;
       float d_mid, d_clip;
   
       void set_clipping();
   
   public:
       rail_ff_impl(float lo, float hi);
       ~rail_ff_impl() override;
   
       float lo() const override { return d_lo; }
       float hi() const override { return d_hi; }
   
       void set_lo(float lo) override;
       void set_hi(float hi) override;
   
       int work(int noutput_items,
                gr_vector_const_void_star& input_items,
                gr_vector_void_star& output_items) override;
   };
   
   } /* namespace analog */
   } /* namespace gr */
   
   #endif /* INCLUDED_ANALOG_RAIL_FF_IMPL_H */
