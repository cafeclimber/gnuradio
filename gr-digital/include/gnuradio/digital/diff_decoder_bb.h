/* -*- c++ -*- */
/*
 * Copyright 2006,2012 Free Software Foundation, Inc.
 * Copyright 2021 Daniel Estevez <daniel@destevez.net>
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#ifndef INCLUDED_GR_DIFF_DECODER_BB_H
#define INCLUDED_GR_DIFF_DECODER_BB_H

#include <gnuradio/digital/api.h>
#include <gnuradio/digital/diff_coding_type.h>
#include <gnuradio/sync_block.h>

namespace gr {
namespace digital {

/*!
 * \brief Differential encoder: y[0] = (x[0] - x[-1]) % M
 * \ingroup block_digital_diff_decoder
 *
 * \details
 * Uses current and previous symbols and the alphabet modulus to
 * perform differential decoding.
 */
class DIGITAL_API diff_decoder_bb : virtual public sync_block
{
public:
    // gr::digital::diff_decoder_bb::sptr
    typedef std::shared_ptr<diff_decoder_bb> sptr;

    /*!
     * Make a differential decoder block.
     *
     * \param modulus Modulus of code's alphabet
     * \param coding Differential coding type
     */
    static sptr make(unsigned int modulus,
                     enum diff_coding_type coding = DIFF_DIFFERENTIAL);
};

} /* namespace digital */
} /* namespace gr */

#endif /* INCLUDED_GR_DIFF_DECODER_BB_H */
