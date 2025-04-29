
.. _program_listing_file_gnuradio_gr-analog_include_gnuradio_analog_pll_refout_cc.h:

Program Listing for File pll_refout_cc.h
========================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gr-analog_include_gnuradio_analog_pll_refout_cc.h>` (``gnuradio/gr-analog/include/gnuradio/analog/pll_refout_cc.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2004,2011,2012 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef INCLUDED_ANALOG_PLL_REFOUT_CC_H
   #define INCLUDED_ANALOG_PLL_REFOUT_CC_H
   
   #include <gnuradio/analog/api.h>
   #include <gnuradio/blocks/control_loop.h>
   #include <gnuradio/sync_block.h>
   
   namespace gr {
   namespace analog {
   
   class ANALOG_API pll_refout_cc : virtual public sync_block,
                                    virtual public blocks::control_loop
   {
   public:
       // gr::analog::pll_refout_cc::sptr
       typedef std::shared_ptr<pll_refout_cc> sptr;
   
       /* \brief Make PLL block that outputs the tracked carrier signal.
        *
        * \param loop_bw: control loop's bandwidth parameter.
        * \param max_freq: maximum (normalized) frequency PLL will lock to.
        * \param min_freq: minimum (normalized) frequency PLL will lock to.
        */
       static sptr make(float loop_bw, float max_freq, float min_freq);
   };
   
   } /* namespace analog */
   } /* namespace gr */
   
   #endif /* INCLUDED_ANALOG_PLL_REFOUT_CC_H */
