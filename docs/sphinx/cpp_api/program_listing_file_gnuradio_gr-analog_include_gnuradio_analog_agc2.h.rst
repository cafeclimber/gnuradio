
.. _program_listing_file_gnuradio_gr-analog_include_gnuradio_analog_agc2.h:

Program Listing for File agc2.h
===============================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gr-analog_include_gnuradio_analog_agc2.h>` (``gnuradio/gr-analog/include/gnuradio/analog/agc2.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2006,2012 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef INCLUDED_ANALOG_AGC2_H
   #define INCLUDED_ANALOG_AGC2_H
   
   #include <gnuradio/analog/api.h>
   #include <gnuradio/gr_complex.h>
   #include <cmath>
   
   namespace gr {
   namespace analog {
   namespace kernel {
   
   class ANALOG_API agc2_cc
   {
   public:
       agc2_cc(float attack_rate = 1e-1,
               float decay_rate = 1e-2,
               float reference = 1.0,
               float gain = 1.0,
               float max_gain = 0.0)
           : _attack_rate(attack_rate),
             _decay_rate(decay_rate),
             _reference(reference),
             _gain(gain),
             _max_gain(max_gain){};
   
       float decay_rate() const { return _decay_rate; }
       float attack_rate() const { return _attack_rate; }
       float reference() const { return _reference; }
       float gain() const { return _gain; }
       float max_gain() const { return _max_gain; }
   
       void set_decay_rate(float rate) { _decay_rate = rate; }
       void set_attack_rate(float rate) { _attack_rate = rate; }
       void set_reference(float reference) { _reference = reference; }
       void set_gain(float gain) { _gain = gain; }
       void set_max_gain(float max_gain) { _max_gain = max_gain; }
   
       gr_complex scale(gr_complex input)
       {
           gr_complex output = input * _gain;
   
           float tmp = -_reference +
                       sqrt(output.real() * output.real() + output.imag() * output.imag());
           float rate = _decay_rate;
           if ((tmp) > _gain) {
               rate = _attack_rate;
           }
           _gain -= tmp * rate;
   
           // Not sure about this; will blow up if _gain < 0 (happens
           // when rates are too high), but is this the solution?
           if (_gain < 0.0)
               _gain = 10e-5;
   
           if (_max_gain > 0.0 && _gain > _max_gain) {
               _gain = _max_gain;
           }
           return output;
       }
   
       void scaleN(gr_complex output[], const gr_complex input[], unsigned n)
       {
           for (unsigned i = 0; i < n; i++)
               output[i] = scale(input[i]);
       }
   
   protected:
       float _attack_rate; // attack rate for fast changing signals
       float _decay_rate;  // decay rate for slow changing signals
       float _reference;   // reference value
       float _gain;        // current gain
       float _max_gain;    // max allowable gain
   };
   
   
   class ANALOG_API agc2_ff
   {
   public:
       agc2_ff(float attack_rate = 1e-1,
               float decay_rate = 1e-2,
               float reference = 1.0,
               float gain = 1.0,
               float max_gain = 0.0)
           : _attack_rate(attack_rate),
             _decay_rate(decay_rate),
             _reference(reference),
             _gain(gain),
             _max_gain(max_gain){};
   
       float attack_rate() const { return _attack_rate; }
       float decay_rate() const { return _decay_rate; }
       float reference() const { return _reference; }
       float gain() const { return _gain; }
       float max_gain() const { return _max_gain; }
   
       void set_attack_rate(float rate) { _attack_rate = rate; }
       void set_decay_rate(float rate) { _decay_rate = rate; }
       void set_reference(float reference) { _reference = reference; }
       void set_gain(float gain) { _gain = gain; }
       void set_max_gain(float max_gain) { _max_gain = max_gain; }
   
       float scale(float input)
       {
           float output = input * _gain;
   
           float tmp = (fabsf(output)) - _reference;
           float rate = _decay_rate;
           if (fabsf(tmp) > _gain) {
               rate = _attack_rate;
           }
           _gain -= tmp * rate;
   
           // Not sure about this
           if (_gain < 0.0)
               _gain = 10e-5;
   
           if (_max_gain > 0.0 && _gain > _max_gain) {
               _gain = _max_gain;
           }
           return output;
       }
   
       void scaleN(float output[], const float input[], unsigned n)
       {
           for (unsigned i = 0; i < n; i++)
               output[i] = scale(input[i]);
       }
   
   protected:
       float _attack_rate; // attack_rate for fast changing signals
       float _decay_rate;  // decay rate for slow changing signals
       float _reference;   // reference value
       float _gain;        // current gain
       float _max_gain;    // maximum gain
   };
   
   } /* namespace kernel */
   } /* namespace analog */
   } /* namespace gr */
   
   #endif /* INCLUDED_ANALOG_AGC2_H */
