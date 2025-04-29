
.. _program_listing_file_gnuradio_gr-analog_include_gnuradio_analog_cpfsk_bc.h:

Program Listing for File cpfsk_bc.h
===================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gr-analog_include_gnuradio_analog_cpfsk_bc.h>` (``gnuradio/gr-analog/include/gnuradio/analog/cpfsk_bc.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2008,2012 Free Software Foundation, Inc.
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef INCLUDED_ANALOG_CPFSK_BC_H
   #define INCLUDED_ANALOG_CPFSK_BC_H
   
   #include <gnuradio/analog/api.h>
   #include <gnuradio/sync_interpolator.h>
   
   namespace gr {
   namespace analog {
   
   class ANALOG_API cpfsk_bc : virtual public sync_interpolator
   {
   public:
       // gr::analog::cpfsk_bc::sptr
       typedef std::shared_ptr<cpfsk_bc> sptr;
   
       static sptr make(float k, float ampl, int samples_per_sym);
   
       virtual void set_amplitude(float amplitude) = 0;
       virtual float amplitude() = 0;
       virtual float freq() = 0;
       virtual float phase() = 0;
   };
   
   } /* namespace analog */
   } /* namespace gr */
   
   #endif /* INCLUDED_ANALOG_CPFSK_BC_H */
