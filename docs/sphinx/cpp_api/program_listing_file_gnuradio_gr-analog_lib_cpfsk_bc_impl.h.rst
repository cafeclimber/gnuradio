
.. _program_listing_file_gnuradio_gr-analog_lib_cpfsk_bc_impl.h:

Program Listing for File cpfsk_bc_impl.h
========================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gr-analog_lib_cpfsk_bc_impl.h>` (``gnuradio/gr-analog/lib/cpfsk_bc_impl.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2008,2012 Free Software Foundation, Inc.
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef INCLUDED_ANALOG_CPFSK_BC_IMPL_H
   #define INCLUDED_ANALOG_CPFSK_BC_IMPL_H
   
   #include <gnuradio/analog/cpfsk_bc.h>
   
   namespace gr {
   namespace analog {
   
   class cpfsk_bc_impl : public cpfsk_bc
   {
   private:
       int d_samples_per_sym; // Samples per symbol, square pulse
       float d_freq;          // Modulation index*pi/samples_per_sym
       float d_ampl;          // Output amplitude
       float d_phase;         // Current phase
   
   public:
       cpfsk_bc_impl(float k, float ampl, int samples_per_sym);
       ~cpfsk_bc_impl() override;
   
       void set_amplitude(float amplitude) override { d_ampl = amplitude; }
       float amplitude() override { return d_ampl; }
       float freq() override { return d_freq; }
       float phase() override { return d_phase; }
   
       int work(int noutput_items,
                gr_vector_const_void_star& input_items,
                gr_vector_void_star& output_items) override;
   };
   
   } /* namespace analog */
   } /* namespace gr */
   
   #endif /* INCLUDED_ANALOG_CPFSK_BC_IMPL_H */
