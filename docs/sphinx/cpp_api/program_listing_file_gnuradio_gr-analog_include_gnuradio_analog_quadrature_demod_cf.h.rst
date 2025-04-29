
.. _program_listing_file_gnuradio_gr-analog_include_gnuradio_analog_quadrature_demod_cf.h:

Program Listing for File quadrature_demod_cf.h
==============================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gr-analog_include_gnuradio_analog_quadrature_demod_cf.h>` (``gnuradio/gr-analog/include/gnuradio/analog/quadrature_demod_cf.h``)

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
   
   #ifndef INCLUDED_ANALOG_QUADRATURE_DEMOD_CF_H
   #define INCLUDED_ANALOG_QUADRATURE_DEMOD_CF_H
   
   #include <gnuradio/analog/api.h>
   #include <gnuradio/sync_block.h>
   
   namespace gr {
   namespace analog {
   
   class ANALOG_API quadrature_demod_cf : virtual public sync_block
   {
   public:
       // gr::analog::quadrature_demod_cf::sptr
       typedef std::shared_ptr<quadrature_demod_cf> sptr;
   
       /* \brief Make a quadrature demodulator block.
        *
        * \param gain Gain setting to adjust the output amplitude. Set
        *             based on converting the phase difference between
        *             samples to a nominal output value.
        */
       static sptr make(float gain);
   
       virtual void set_gain(float gain) = 0;
       virtual float gain() const = 0;
   };
   
   } /* namespace analog */
   } /* namespace gr */
   
   #endif /* INCLUDED_ANALOG_QUADRATURE_DEMOD_CF_H */
