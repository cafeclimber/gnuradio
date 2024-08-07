/* -*- c++ -*- */
/*
 * Copyright 2012 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#ifndef INCLUDED_BLOCKS_COMPLEX_TO_ARG_H
#define INCLUDED_BLOCKS_COMPLEX_TO_ARG_H

#include <gnuradio/blocks/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
namespace blocks {

/*!
 * \brief complex in, arg (arctan) out (float)
 * \ingroup block_blocks_complex_to_arg
 */
class BLOCKS_API complex_to_arg : virtual public sync_block
{
public:
    // gr::blocks::complex_to_arg_ff::sptr
    typedef std::shared_ptr<complex_to_arg> sptr;

    /*!
     * Build a complex to arg block.
     *
     * \param vlen vector len (default 1)
     */
    static sptr make(size_t vlen = 1);
};

} /* namespace blocks */
} /* namespace gr */

#endif /* INCLUDED_BLOCKS_COMPLEX_TO_ARG_H */
