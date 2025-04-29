
.. _program_listing_file_gnuradio_gnuradio-runtime_include_gnuradio_messages_msg_accepter.h:

Program Listing for File msg_accepter.h
=======================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_include_gnuradio_messages_msg_accepter.h>` (``gnuradio/gnuradio-runtime/include/gnuradio/messages/msg_accepter.h``)

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
   
   #ifndef INCLUDED_MSG_ACCEPTER_H
   #define INCLUDED_MSG_ACCEPTER_H
   
   #include <gnuradio/api.h>
   #include <pmt/pmt.h>
   #include <memory>
   
   namespace gr {
   namespace messages {
   
   class GR_RUNTIME_API msg_accepter
   {
   public:
       msg_accepter(){};
       virtual ~msg_accepter();
   
       virtual void post(pmt::pmt_t which_port, pmt::pmt_t msg) = 0;
   };
   
   typedef std::shared_ptr<msg_accepter> msg_accepter_sptr;
   
   } /* namespace messages */
   } /* namespace gr */
   
   #endif /* INCLUDED_MSG_ACCEPTER_H */
