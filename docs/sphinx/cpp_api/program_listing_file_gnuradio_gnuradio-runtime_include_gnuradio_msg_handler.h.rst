
.. _program_listing_file_gnuradio_gnuradio-runtime_include_gnuradio_msg_handler.h:

Program Listing for File msg_handler.h
======================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_include_gnuradio_msg_handler.h>` (``gnuradio/gnuradio-runtime/include/gnuradio/msg_handler.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2005,2013 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef INCLUDED_GR_MSG_HANDLER_H
   #define INCLUDED_GR_MSG_HANDLER_H
   
   #include <gnuradio/api.h>
   #include <gnuradio/message.h>
   
   namespace gr {
   
   class msg_handler;
   typedef std::shared_ptr<msg_handler> msg_handler_sptr;
   
   class GR_RUNTIME_API msg_handler
   {
   public:
       virtual ~msg_handler();
   
       virtual void handle(message::sptr msg) = 0;
   };
   
   } /* namespace gr */
   
   #endif /* INCLUDED_GR_MSG_HANDLER_H */
