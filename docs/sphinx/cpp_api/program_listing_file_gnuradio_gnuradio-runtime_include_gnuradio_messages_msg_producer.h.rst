
.. _program_listing_file_gnuradio_gnuradio-runtime_include_gnuradio_messages_msg_producer.h:

Program Listing for File msg_producer.h
=======================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_include_gnuradio_messages_msg_producer.h>` (``gnuradio/gnuradio-runtime/include/gnuradio/messages/msg_producer.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2012,2013 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef INCLUDED_MSG_PRODUCER_H
   #define INCLUDED_MSG_PRODUCER_H
   
   #include <gnuradio/api.h>
   #include <pmt/pmt.h>
   #include <memory>
   
   namespace gr {
   namespace messages {
   
   class GR_RUNTIME_API msg_producer
   {
   public:
       msg_producer() {}
       virtual ~msg_producer();
   
       virtual pmt::pmt_t retrieve() = 0;
   };
   
   typedef std::shared_ptr<msg_producer> msg_producer_sptr;
   
   } /* namespace messages */
   } /* namespace gr */
   
   #endif /* INCLUDED_MSG_PRODUCER_H */
