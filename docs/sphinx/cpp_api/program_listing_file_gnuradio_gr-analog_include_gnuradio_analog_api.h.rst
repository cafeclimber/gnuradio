
.. _program_listing_file_gnuradio_gr-analog_include_gnuradio_analog_api.h:

Program Listing for File api.h
==============================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gr-analog_include_gnuradio_analog_api.h>` (``gnuradio/gr-analog/include/gnuradio/analog/api.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /*
    * Copyright 2012 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef INCLUDED_ANALOG_API_H
   #define INCLUDED_ANALOG_API_H
   
   #include <gnuradio/attributes.h>
   
   #ifdef gnuradio_analog_EXPORTS
   #define ANALOG_API __GR_ATTR_EXPORT
   #else
   #define ANALOG_API __GR_ATTR_IMPORT
   #endif
   
   #endif /* INCLUDED_ANALOG_API_H */
