
.. _program_listing_file_gnuradio_gnuradio-runtime_include_gnuradio_api.h:

Program Listing for File api.h
==============================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_include_gnuradio_api.h>` (``gnuradio/gnuradio-runtime/include/gnuradio/api.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /*
    * Copyright 2010-2011 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef INCLUDED_GR_RUNTIME_RUNTIME_API_H
   #define INCLUDED_GR_RUNTIME_RUNTIME_API_H
   
   #include <gnuradio/attributes.h>
   
   #ifdef gnuradio_runtime_EXPORTS
   #define GR_RUNTIME_API __GR_ATTR_EXPORT
   #else
   #define GR_RUNTIME_API __GR_ATTR_IMPORT
   #endif
   
   #endif /* INCLUDED_GR_RUNTIME_RUNTIME_API_H */
