
.. _program_listing_file_gnuradio_gnuradio-runtime_include_gnuradio_gr_complex.h:

Program Listing for File gr_complex.h
=====================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_include_gnuradio_gr_complex.h>` (``gnuradio/gnuradio-runtime/include/gnuradio/gr_complex.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2004,2018 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef INCLUDED_GR_COMPLEX_H
   #define INCLUDED_GR_COMPLEX_H
   
   #include <complex>
   typedef std::complex<float> gr_complex;
   typedef std::complex<double> gr_complexd;
   
   inline bool is_complex(gr_complex x)
   {
       (void)x;
       return true;
   }
   inline bool is_complex(gr_complexd x)
   {
       (void)x;
       return true;
   }
   inline bool is_complex(float x)
   {
       (void)x;
       return false;
   }
   inline bool is_complex(double x)
   {
       (void)x;
       return false;
   }
   inline bool is_complex(int x)
   {
       (void)x;
       return false;
   }
   inline bool is_complex(char x)
   {
       (void)x;
       return false;
   }
   inline bool is_complex(short x)
   {
       (void)x;
       return false;
   }
   
   #endif /* INCLUDED_GR_COMPLEX_H */
