
.. _program_listing_file_gnuradio_gr-analog_include_gnuradio_analog_phase_modulator_fc.h:

Program Listing for File phase_modulator_fc.h
=============================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gr-analog_include_gnuradio_analog_phase_modulator_fc.h>` (``gnuradio/gr-analog/include/gnuradio/analog/phase_modulator_fc.h``)

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
   
   #ifndef INCLUDED_ANALOG_PHASE_MODULATOR_FC_H
   #define INCLUDED_ANALOG_PHASE_MODULATOR_FC_H
   
   #include <gnuradio/analog/api.h>
   #include <gnuradio/sync_block.h>
   
   namespace gr {
   namespace analog {
   
   class ANALOG_API phase_modulator_fc : virtual public sync_block
   {
   public:
       // gr::analog::phase_modulator_fc::sptr
       typedef std::shared_ptr<phase_modulator_fc> sptr;
   
       /* \brief Make a phase modulator block.
        *
        * \param sensitivity Phase change sensitivity of input amplitude.
        */
       static sptr make(double sensitivity);
   
       virtual double sensitivity() const = 0;
       virtual double phase() const = 0;
   
       virtual void set_sensitivity(double s) = 0;
       virtual void set_phase(double p) = 0;
   };
   
   } /* namespace analog */
   } /* namespace gr */
   
   #endif /* INCLUDED_ANALOG_PHASE_MODULATOR_FC_H */
