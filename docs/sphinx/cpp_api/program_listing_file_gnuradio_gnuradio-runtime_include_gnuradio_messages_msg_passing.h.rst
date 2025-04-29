
.. _program_listing_file_gnuradio_gnuradio-runtime_include_gnuradio_messages_msg_passing.h:

Program Listing for File msg_passing.h
======================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_include_gnuradio_messages_msg_passing.h>` (``gnuradio/gnuradio-runtime/include/gnuradio/messages/msg_passing.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2009,2013 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef INCLUDED_MSG_PASSING_H
   #define INCLUDED_MSG_PASSING_H
   
   #include <gnuradio/api.h>
   #include <gnuradio/messages/msg_accepter.h>
   #include <pmt/pmt.h>
   
   namespace gr {
   namespace messages {
   
   static inline pmt::pmt_t
   send(msg_accepter_sptr accepter, const pmt::pmt_t& which_port, const pmt::pmt_t& msg)
   {
       accepter->post(which_port, msg);
       return msg;
   }
   
   static inline pmt::pmt_t
   send(msg_accepter* accepter, const pmt::pmt_t& which_port, const pmt::pmt_t& msg)
   {
       accepter->post(which_port, msg);
       return msg;
   }
   
   static inline pmt::pmt_t
   send(msg_accepter& accepter, const pmt::pmt_t& which_port, const pmt::pmt_t& msg)
   {
       accepter.post(which_port, msg);
       return msg;
   }
   
   static inline pmt::pmt_t
   send(pmt::pmt_t accepter, const pmt::pmt_t& which_port, const pmt::pmt_t& msg)
   {
       return send(pmt::msg_accepter_ref(accepter), which_port, msg);
   }
   
   } /* namespace messages */
   } /* namespace gr */
   
   #endif /* INCLUDED_MSG_PASSING_H */
