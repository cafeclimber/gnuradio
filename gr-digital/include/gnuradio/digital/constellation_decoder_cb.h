/* -*- c++ -*- */
/*
 * Copyright 2011,2012 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#ifndef INCLUDED_DIGITAL_CONSTELLATION_DECODER_CB_H
#define INCLUDED_DIGITAL_CONSTELLATION_DECODER_CB_H

#include <gnuradio/block.h>
#include <gnuradio/digital/api.h>
#include <gnuradio/digital/constellation.h>

namespace gr {
namespace digital {

/*!
 * \brief Constellation Decoder
 * \ingroup block_digital_constellation_decoder_cb
 *
 * \details
 * Decode a constellation's points from a complex space to
 * index of constellation symbol based on the map of the \p constellation
 * object.
 */
class DIGITAL_API constellation_decoder_cb : virtual public block
{
public:
    // gr::digital::constellation_decoder_cb::sptr
    typedef std::shared_ptr<constellation_decoder_cb> sptr;

    /*!
     * \brief Make constellation decoder block.
     *
     * \param constellation A constellation derived from class
     * 'constellation'. Use base() method to get a shared pointer to
     * this base class type.
     */
    static sptr make(constellation_sptr constellation);

    /*!
     * Set a new constellation object for decoding
     *
     * \param constellation A constellation derived from class
     * 'constellation'. Use base() method to get a shared pointer to
     * this base class type.
     */
    virtual void set_constellation(constellation_sptr constellation) = 0;
};

} /* namespace digital */
} /* namespace gr */

#endif /* INCLUDED_DIGITAL_CONSTELLATION_DECODER_CB_H */
