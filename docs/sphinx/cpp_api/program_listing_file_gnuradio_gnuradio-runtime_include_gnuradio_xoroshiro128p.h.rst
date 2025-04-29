
.. _program_listing_file_gnuradio_gnuradio-runtime_include_gnuradio_xoroshiro128p.h:

Program Listing for File xoroshiro128p.h
========================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_include_gnuradio_xoroshiro128p.h>` (``gnuradio/gnuradio-runtime/include/gnuradio/xoroshiro128p.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /*
    * Copyright 2018 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   // Built on XOROSHIRO128+ by David Blackman and Sebastiano Vigna who put this
   // under CC-0, colloquially known as "public domain (or as close you get to that
   // in your local legislation)" see
   // http://xoroshiro.di.unimi.it/xoroshiro128plus.c
   // Conversion to a local state (original used global state) done by Marcus
   // Müller, 2018.
   #ifndef INCLUDED_XOROSHIRO128P_H
   #define INCLUDED_XOROSHIRO128P_H
   #ifdef __cplusplus
   #include <cstdint>
   extern "C" {
   #else
   #include <stdint.h>
   #endif
   
   
   static inline uint64_t rotl(const uint64_t x, const int k)
   {
       return (x << k) | (x >> (64 - k));
   }
   
   
   static inline uint64_t xoroshiro128p_next(uint64_t* state)
   {
       const uint64_t s0 = state[0];
       uint64_t s1 = state[1];
       const uint64_t result = s0 + s1;
   
       s1 ^= s0;
       state[0] = rotl(s0, 55) ^ s1 ^ (s1 << 14); // a, b
       state[1] = rotl(s1, 36);                   // c
   
       return result;
   }
   
   
   static inline void xoroshiro128p_jump(uint64_t* state)
   {
       static const uint64_t JUMP[] = { 0xbeac0467eba5facb, 0xd86b048b86aa9922 };
   
       uint64_t s0 = 0;
       uint64_t s1 = 0;
       for (unsigned int i = 0; i < sizeof(JUMP) / sizeof(*JUMP); ++i) {
           for (unsigned int b = 0; b < 64; ++b) {
               if (JUMP[i] & UINT64_C(1) << b) {
                   s0 ^= state[0];
                   s1 ^= state[1];
               }
               xoroshiro128p_next(state);
           }
       }
   
       state[0] = s0;
       state[1] = s1;
   }
   
   static inline uint64_t splitmix64_next(uint64_t* state)
   {
       uint64_t z = (*state += 0x9e3779b97f4a7c15);
       z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9;
       z = (z ^ (z >> 27)) * 0x94d049bb133111eb;
       return z ^ (z >> 31);
   }
   
   static inline void xoroshiro128p_seed(uint64_t* state, const uint64_t seed)
   {
       state[0] = seed;
       state[1] = splitmix64_next(state);
       xoroshiro128p_jump(state);
   }
   #ifdef __cplusplus
   }
   #endif
   #endif // Include guard
