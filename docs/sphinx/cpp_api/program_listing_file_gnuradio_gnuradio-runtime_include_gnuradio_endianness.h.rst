
.. _program_listing_file_gnuradio_gnuradio-runtime_include_gnuradio_endianness.h:

Program Listing for File endianness.h
=====================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_include_gnuradio_endianness.h>` (``gnuradio/gnuradio-runtime/include/gnuradio/endianness.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2004,2013 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef INCLUDED_GR_ENDIANNESS_H
   #define INCLUDED_GR_ENDIANNESS_H
   
   namespace gr {
   
   typedef enum { GR_MSB_FIRST, GR_LSB_FIRST } endianness_t;
   
   } /* namespace gr */
   
   #endif /* INCLUDED_GR_ENDIANNESS_H */
