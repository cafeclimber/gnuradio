/* -*- c++ -*- */
/*
 * Copyright 2011,2013 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#ifndef INCLUDED_VOCODER_G723_24_DECODE_BS_H
#define INCLUDED_VOCODER_G723_24_DECODE_BS_H

#include <gnuradio/sync_block.h>
#include <gnuradio/vocoder/api.h>

namespace gr {
namespace vocoder {

/*!
 * \brief This block performs g723_24 audio decoding.
 * \ingroup block_vocoder_g723_24_decode
 */
class VOCODER_API g723_24_decode_bs : virtual public sync_block
{
public:
    // gr::vocoder::g723_24_decode_bs::sptr
    typedef std::shared_ptr<g723_24_decode_bs> sptr;

    /*!
     * \brief Make G722_24 decoder block.
     */
    static sptr make();
};

} /* namespace vocoder */
} /* namespace gr */

#endif /* INCLUDED_VOCODER_G723_24_DECODE_BS_H */
