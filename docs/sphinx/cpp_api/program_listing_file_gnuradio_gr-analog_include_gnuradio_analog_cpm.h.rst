
.. _program_listing_file_gnuradio_gr-analog_include_gnuradio_analog_cpm.h:

Program Listing for File cpm.h
==============================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gr-analog_include_gnuradio_analog_cpm.h>` (``gnuradio/gr-analog/include/gnuradio/analog/cpm.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2010,2012 Free Software Foundation, Inc.
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   
   #ifndef INCLUDED_ANALOG_CPM_H
   #define INCLUDED_ANALOG_CPM_H
   
   #include <gnuradio/analog/api.h>
   #include <vector>
   
   namespace gr {
   namespace analog {
   
   class ANALOG_API cpm
   {
   public:
       enum cpm_type { LRC, LSRC, LREC, TFM, GAUSSIAN, GENERIC = 999 };
   
       static std::vector<float> phase_response(cpm_type type,
                                                unsigned samples_per_sym,
                                                unsigned L,
                                                double beta = 0.3);
   };
   } // namespace analog
   } // namespace gr
   
   #endif /* INCLUDED_ANALOG_CPM_H */
