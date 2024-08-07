/* -*- c++ -*- */
/*
 * Copyright 2013 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#ifndef INCLUDED_ZEROMQ_REQ_SOURCE_H
#define INCLUDED_ZEROMQ_REQ_SOURCE_H

#include <gnuradio/sync_block.h>
#include <gnuradio/zeromq/api.h>

namespace gr {
namespace zeromq {

/*!
 * \brief Receive messages on ZMQ REQ socket and source stream
 * \ingroup block_zeromq_req_source
 *
 * \details
 * This block will connect to a ZMQ REP socket, then produce all
 * incoming messages as streaming output.
 */
class ZEROMQ_API req_source : virtual public gr::sync_block
{
public:
    typedef std::shared_ptr<req_source> sptr;

    /*!
     * \brief Return a shared_ptr to a new instance of zeromq::req_source.
     *
     * \param itemsize Size of a stream item in bytes.
     * \param vlen Vector length of the input items. Note that one vector is one item.
     * \param address  ZMQ socket address specifier.
     * \param timeout  Receive timeout in milliseconds, default is 100ms, 1us increments.
     * \param pass_tags Whether source will look for and deserialize tags.
     * \param hwm High Watermark to configure the socket to (-1 => zmq's default)
     * \param bind If true this block will bind to the address, otherwise it will
     * connect; the default is to connect
     */
    static sptr make(size_t itemsize,
                     size_t vlen,
                     char* address,
                     int timeout = 100,
                     bool pass_tags = false,
                     int hwm = -1,
                     bool bind = false);

    /*!
     * \brief Return a std::string of ZMQ_LAST_ENDPOINT from the underlying ZMQ socket.
     */
    virtual std::string last_endpoint() = 0;
};

} // namespace zeromq
} // namespace gr

#endif /* INCLUDED_ZEROMQ_SOURCE_REQREP_H */
