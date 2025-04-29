
.. _program_listing_file_gnuradio_gr-analog_lib_phase_modulator_fc_impl.h:

Program Listing for File phase_modulator_fc_impl.h
==================================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gr-analog_lib_phase_modulator_fc_impl.h>` (``gnuradio/gr-analog/lib/phase_modulator_fc_impl.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2005,2006,2012 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef INCLUDED_ANALOG_PHASE_MODULATOR_FC_IMPL_H
   #define INCLUDED_ANALOG_PHASE_MODULATOR_FC_IMPL_H
   
   #include <gnuradio/analog/phase_modulator_fc.h>
   
   namespace gr {
   namespace analog {
   
   class phase_modulator_fc_impl : public phase_modulator_fc
   {
   private:
       double d_sensitivity;
       double d_phase;
   
   public:
       phase_modulator_fc_impl(double sensitivity);
       ~phase_modulator_fc_impl() override;
   
       double sensitivity() const override { return d_sensitivity; }
       double phase() const override { return d_phase; }
   
       void set_sensitivity(double s) override { d_sensitivity = s; }
       void set_phase(double p) override { d_phase = p; }
   
       int work(int noutput_items,
                gr_vector_const_void_star& input_items,
                gr_vector_void_star& output_items) override;
   };
   
   } /* namespace analog */
   } /* namespace gr */
   
   #endif /* INCLUDED_ANALOG_PHASE_MODULATOR_FC_IMPL_H */
