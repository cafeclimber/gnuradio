
.. _program_listing_file_gnuradio_gr-analog_include_gnuradio_analog_frequency_modulator_fc.h:

Program Listing for File frequency_modulator_fc.h
=================================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gr-analog_include_gnuradio_analog_frequency_modulator_fc.h>` (``gnuradio/gr-analog/include/gnuradio/analog/frequency_modulator_fc.h``)

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
   
   #ifndef INCLUDED_ANALOG_FREQUENCY_MODULATOR_FC_H
   #define INCLUDED_ANALOG_FREQUENCY_MODULATOR_FC_H
   
   #include <gnuradio/analog/api.h>
   #include <gnuradio/sync_block.h>
   
   namespace gr {
   namespace analog {
   
   class ANALOG_API frequency_modulator_fc : virtual public sync_block
   {
   public:
       // gr::analog::frequency_modulator_fc::sptr
       typedef std::shared_ptr<frequency_modulator_fc> sptr;
   
       static sptr make(float sensitivity);
   
       virtual void set_sensitivity(float sens) = 0;
       virtual float sensitivity() const = 0;
   };
   
   } /* namespace analog */
   } /* namespace gr */
   
   #endif /* INCLUDED_ANALOG_FREQUENCY_MODULATOR_FC_H */
