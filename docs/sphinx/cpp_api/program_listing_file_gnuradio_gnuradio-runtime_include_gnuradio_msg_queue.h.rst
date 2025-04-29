
.. _program_listing_file_gnuradio_gnuradio-runtime_include_gnuradio_msg_queue.h:

Program Listing for File msg_queue.h
====================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_include_gnuradio_msg_queue.h>` (``gnuradio/gnuradio-runtime/include/gnuradio/msg_queue.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2005,2009 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef INCLUDED_GR_MSG_QUEUE_H
   #define INCLUDED_GR_MSG_QUEUE_H
   
   #include <gnuradio/api.h>
   #include <gnuradio/msg_handler.h>
   #include <gnuradio/thread/thread.h>
   
   namespace gr {
   
   class GR_RUNTIME_API msg_queue : public msg_handler
   {
       gr::thread::mutex d_mutex;
       gr::thread::condition_variable d_not_empty;
       gr::thread::condition_variable d_not_full;
       message::sptr d_head;
       message::sptr d_tail;
       unsigned int d_count; // # of messages in queue.
       unsigned int d_limit; // max # of messages in queue.  0 -> unbounded
   
   public:
       typedef std::shared_ptr<msg_queue> sptr;
   
       static sptr make(unsigned int limit = 0);
   
       msg_queue(unsigned int limit);
       ~msg_queue() override;
   
       void handle(message::sptr msg) override { insert_tail(msg); }
   
       void insert_tail(message::sptr msg);
   
       message::sptr delete_head();
   
       message::sptr delete_head_nowait();
   
       void flush();
   
       bool empty_p() const { return d_count == 0; }
   
       bool full_p() const { return d_limit != 0 && d_count >= d_limit; }
   
       unsigned int count() const { return d_count; }
   
       unsigned int limit() const { return d_limit; }
   };
   
   } /* namespace gr */
   
   #endif /* INCLUDED_GR_MSG_QUEUE_H */
