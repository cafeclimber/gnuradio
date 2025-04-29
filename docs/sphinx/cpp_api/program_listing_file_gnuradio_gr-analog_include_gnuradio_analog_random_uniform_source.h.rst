
.. _program_listing_file_gnuradio_gr-analog_include_gnuradio_analog_random_uniform_source.h:

Program Listing for File random_uniform_source.h
================================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gr-analog_include_gnuradio_analog_random_uniform_source.h>` (``gnuradio/gr-analog/include/gnuradio/analog/random_uniform_source.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2015,2018 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   
   #ifndef RANDOM_UNIFORM_SOURCE_H
   #define RANDOM_UNIFORM_SOURCE_H
   
   #include <gnuradio/analog/api.h>
   #include <gnuradio/sync_block.h>
   
   namespace gr {
   namespace analog {
   
   template <class T>
   class ANALOG_API random_uniform_source : virtual public sync_block
   {
   public:
       // gr::analog::random_uniform_source::sptr
       typedef std::shared_ptr<random_uniform_source<T>> sptr;
   
       static sptr make(int minimum, int maximum, int seed);
   };
   
   typedef random_uniform_source<std::uint8_t> random_uniform_source_b;
   typedef random_uniform_source<std::int16_t> random_uniform_source_s;
   typedef random_uniform_source<std::int32_t> random_uniform_source_i;
   } /* namespace analog */
   } /* namespace gr */
   
   #endif /* RANDOM_UNIFORM_SOURCE_H */
