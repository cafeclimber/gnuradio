/* -*- c++ -*- */
/*
 * Copyright 2012 Free Software Foundation, Inc.
 * Copyright 2024 Daniel Estevez <daniel@destevez.net>
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#ifndef INCLUDED_BLOCKS_FLOAT_TO_UCHAR_H
#define INCLUDED_BLOCKS_FLOAT_TO_UCHAR_H

#include <gnuradio/blocks/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
namespace blocks {

/*!
 * \brief Convert stream of floats to a stream of unsigned chars
 * \ingroup block_blocks_float_to_uchar
 */
class BLOCKS_API float_to_uchar : virtual public sync_block
{
public:
    // gr::blocks::float_to_uchar_ff::sptr
    typedef std::shared_ptr<float_to_uchar> sptr;

    /*!
     * Build a float to uchar block.
     *
     * \param vlen vector length of data streams.
     * \param scale a scalar multiplier to change the output signal scale.
     * \param bias a scalar additive value to change the output signal offset.
     */
    static sptr make(size_t vlen = 1, float scale = 1.0, float bias = 0.0);

    /*!
     * Get the scalar multiplier value.
     */
    virtual float scale() const = 0;

    /*!
     * Get the scalar bias value.
     */
    virtual float bias() const = 0;

    /*!
     * Set the scalar multiplier value.
     */
    virtual void set_scale(float scale) = 0;

    /*!
     * Set the scalar bias value.
     */
    virtual void set_bias(float scale) = 0;
};

} /* namespace blocks */
} /* namespace gr */

#endif /* INCLUDED_BLOCKS_FLOAT_TO_UCHAR_H */
