/* -*- c++ -*- */
/*
 * Copyright 2015 Free Software Foundation, Inc.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#ifndef INCLUDED_DTV_DVBT_SYMBOL_INNER_INTERLEAVER_H
#define INCLUDED_DTV_DVBT_SYMBOL_INNER_INTERLEAVER_H

#include <gnuradio/block.h>
#include <gnuradio/dtv/api.h>
#include <gnuradio/dtv/dvbt_config.h>

namespace gr {
namespace dtv {

/*!
 * \brief Symbol interleaver.
 * \ingroup block_dtv_dvbt_symbol_inner_interleaver
 *
 * ETSI EN 300 744 Clause 4.3.4.2 \n
 * One block is 12 groups x 126 datawords = 1512 datawords.
 *
 * Data Input format: \n
 * 000000I0I1 - QPSK. \n
 * 0000I0I1I2I3 - 16QAM. \n
 * 00I0I1I2I3I4I5 - 64QAM. \n
 * Data Output format: \n
 * 000000Y0Y1 - QPSK. \n
 * 0000Y0Y1Y2Y3 - 16QAM. \n
 * 00Y0Y1Y2Y3Y4Y5 - 64QAM.
 */
class DTV_API dvbt_symbol_inner_interleaver : virtual public block
{
public:
    typedef std::shared_ptr<dvbt_symbol_inner_interleaver> sptr;

    /*!
     * \brief Create a Symbol interleaver.
     *
     * \param ninput length of input stream. \n
     * \param transmission transmission mode used \n
     * \param direction interleave or deinterleave. \n
     */
    static sptr make(int ninput, dvbt_transmission_mode_t transmission, int direction);
};

} // namespace dtv
} // namespace gr

#endif /* INCLUDED_DTV_DVBT_SYMBOL_INNER_INTERLEAVER_H */
