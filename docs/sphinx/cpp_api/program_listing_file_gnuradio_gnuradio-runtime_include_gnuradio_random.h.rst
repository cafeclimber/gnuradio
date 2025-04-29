
.. _program_listing_file_gnuradio_gnuradio-runtime_include_gnuradio_random.h:

Program Listing for File random.h
=================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_include_gnuradio_random.h>` (``gnuradio/gnuradio-runtime/include/gnuradio/random.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2002, 2015 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef INCLUDED_GR_RANDOM_H
   #define INCLUDED_GR_RANDOM_H
   
   #include <gnuradio/api.h>
   #include <gnuradio/gr_complex.h>
   #include <gnuradio/xoroshiro128p.h>
   
   #include <limits>
   #include <random>
   
   namespace gr {
   
   class GR_RUNTIME_API xoroshiro128p_prng
   {
   public:
       using result_type = uint64_t; 
   
   private:
       result_type state[2];
   
   public:
       static constexpr result_type min() { return std::numeric_limits<result_type>::min(); }
       static constexpr result_type max() { return std::numeric_limits<result_type>::max(); }
   
       xoroshiro128p_prng(uint64_t init) { seed(init); }
   
   
       result_type operator()() { return xoroshiro128p_next(state); }
   
       void seed(uint64_t seed) { xoroshiro128p_seed(state, seed); }
   };
   class GR_RUNTIME_API random
   {
   protected:
       long d_seed;
       bool d_gauss_stored;
       float d_gauss_value;
   
       xoroshiro128p_prng d_rng; // mersenne twister as random number generator
       std::uniform_real_distribution<float>
           d_uniform; // choose uniform distribution, default is [0,1)
       std::uniform_int_distribution<int64_t> d_integer_dis;
   
   public:
       random(uint64_t seed = 0, int64_t min_integer = 0, int64_t max_integer = 2);
       ~random();
   
       void reseed(uint64_t seed);
   
       void set_integer_limits(int64_t minimum, int64_t maximum);
   
       int64_t ran_int();
   
       float ran1();
   
       float gasdev();
   
       float laplacian();
   
       float rayleigh();
   
       float impulse(float factor);
   
       gr_complex rayleigh_complex();
   };
   
   } /* namespace gr */
   
   #endif /* INCLUDED_GR_RANDOM_H */
