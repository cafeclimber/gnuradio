/* -*- c++ -*- */
/*
 * Copyright 2005,2006,2012 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#ifndef INCLUDED_GR_FRAMER_SINK_1_H
#define INCLUDED_GR_FRAMER_SINK_1_H

#include <gnuradio/digital/api.h>
#include <gnuradio/msg_queue.h>
#include <gnuradio/sync_block.h>

namespace gr {
namespace digital {

/*!
 * \brief Given a stream of bits and access_code flags, assemble packets.
 * \ingroup block_digital_framer_sink_1
 *
 * \details
 * input: stream of bytes from digital_correlate_access_code_bb
 * output: none. Pushes assembled packet into target queue
 *
 * The framer expects a fixed length header of 2 16-bit shorts
 * containing the payload length, followed by the payload. If the
 * 2 16-bit shorts are not identical, this packet is
 * ignored. Better algs are welcome.
 *
 * The input data consists of bytes that have two bits used. Bit
 * 0, the LSB, contains the data bit. Bit 1 if set, indicates that
 * the corresponding bit is the the first bit of the packet. That
 * is, this bit is the first one after the access code.
 */
class DIGITAL_API framer_sink_1 : virtual public sync_block
{
public:
    // gr::digital::framer_sink_1::sptr
    typedef std::shared_ptr<framer_sink_1> sptr;

    /*!
     * Make a framer_sink_1 block.
     *
     * \param target_queue The message queue where frames go.
     */
    static sptr make(msg_queue::sptr target_queue);
};

} /* namespace digital */
} /* namespace gr */

#endif /* INCLUDED_GR_FRAMER_SINK_1_H */
