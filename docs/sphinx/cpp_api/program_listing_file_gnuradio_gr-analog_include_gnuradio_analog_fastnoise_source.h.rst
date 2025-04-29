
.. _program_listing_file_gnuradio_gr-analog_include_gnuradio_analog_fastnoise_source.h:

Program Listing for File fastnoise_source.h
===========================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gr-analog_include_gnuradio_analog_fastnoise_source.h>` (``gnuradio/gr-analog/include/gnuradio/analog/fastnoise_source.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2013,2018 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   
   #ifndef FASTNOISE_SOURCE_H
   #define FASTNOISE_SOURCE_H
   
   #include <gnuradio/analog/api.h>
   #include <gnuradio/analog/noise_type.h>
   #include <gnuradio/sync_block.h>
   #include <cstdint>
   #include <vector>
   
   namespace gr {
   namespace analog {
   
   template <class T>
   class ANALOG_API fastnoise_source : virtual public sync_block
   {
   public:
       // gr::analog::fastnoise_source::sptr
       typedef std::shared_ptr<fastnoise_source<T>> sptr;
   
       static sptr
       make(noise_type_t type, float ampl, uint64_t seed = 0, size_t samples = 1024 * 16);
       virtual T sample() = 0;
       virtual T sample_unbiased() = 0;
       virtual const std::vector<T>& samples() const = 0;
   
       virtual void set_type(noise_type_t type) = 0;
   
       virtual void set_amplitude(float ampl) = 0;
   
       virtual noise_type_t type() const = 0;
       virtual float amplitude() const = 0;
   };
   
   typedef fastnoise_source<float> fastnoise_source_f;
   typedef fastnoise_source<std::int32_t> fastnoise_source_i;
   typedef fastnoise_source<std::int16_t> fastnoise_source_s;
   typedef fastnoise_source<gr_complex> fastnoise_source_c;
   } /* namespace analog */
   } /* namespace gr */
   
   
   #endif /* FASTNOISE_SOURCE_H */
