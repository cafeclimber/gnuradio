
.. _program_listing_file_gnuradio_gnuradio-runtime_include_gnuradio_messages_msg_queue.h:

Program Listing for File msg_queue.h
====================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_include_gnuradio_messages_msg_queue.h>` (``gnuradio/gnuradio-runtime/include/gnuradio/messages/msg_queue.h``)

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
   
   #ifndef INCLUDED_MSG_QUEUE_H
   #define INCLUDED_MSG_QUEUE_H
   
   #include <gnuradio/api.h>
   #include <gnuradio/thread/thread.h>
   #include <pmt/pmt.h>
   #include <deque>
   
   namespace gr {
   namespace messages {
   
   class msg_queue;
   typedef std::shared_ptr<msg_queue> msg_queue_sptr;
   
   msg_queue_sptr make_msg_queue(unsigned int limit = 0);
   
   class GR_RUNTIME_API msg_queue
   {
   private:
       gr::thread::mutex d_mutex;
       gr::thread::condition_variable d_not_empty;
       gr::thread::condition_variable d_not_full;
       unsigned int d_limit; // max # of messages in queue.  0 -> unbounded
   
       std::deque<pmt::pmt_t> d_msgs;
   
   public:
       msg_queue(unsigned int limit);
       ~msg_queue();
   
       void insert_tail(pmt::pmt_t msg);
   
       pmt::pmt_t delete_head();
   
       pmt::pmt_t delete_head_nowait();
   
       void flush();
   
       bool empty_p() const { return d_msgs.empty(); }
   
       bool full_p() const { return d_limit != 0 && count() >= d_limit; }
   
       unsigned int count() const { return d_msgs.size(); }
   
       unsigned int limit() const { return d_limit; }
   };
   
   } /* namespace messages */
   } /* namespace gr */
   
   #endif /* INCLUDED_MSG_QUEUE_H */
