
.. _program_listing_file_gnuradio_gr-analog_include_gnuradio_analog_noise_source.h:

Program Listing for File noise_source.h
=======================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gr-analog_include_gnuradio_analog_noise_source.h>` (``gnuradio/gr-analog/include/gnuradio/analog/noise_source.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2004,2012,2018 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   
   #ifndef NOISE_SOURCE_H
   #define NOISE_SOURCE_H
   
   #include <gnuradio/analog/api.h>
   #include <gnuradio/analog/noise_type.h>
   #include <gnuradio/sync_block.h>
   
   namespace gr {
   namespace analog {
   
   template <class T>
   class ANALOG_API noise_source : virtual public sync_block
   {
   public:
       // gr::analog::noise_source::sptr
       typedef std::shared_ptr<noise_source<T>> sptr;
   
       static sptr make(noise_type_t type, float ampl, uint64_t seed = 0);
   
       virtual void set_type(noise_type_t type) = 0;
   
       virtual void set_amplitude(float ampl) = 0;
   
       virtual noise_type_t type() const = 0;
       virtual float amplitude() const = 0;
   };
   
   typedef noise_source<std::int16_t> noise_source_s;
   typedef noise_source<std::int32_t> noise_source_i;
   typedef noise_source<float> noise_source_f;
   typedef noise_source<gr_complex> noise_source_c;
   
   } /* namespace analog */
   } /* namespace gr */
   
   #endif /* NOISE_SOURCE_H */
