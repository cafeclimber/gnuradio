/* -*- c++ -*- */
/*
 * Copyright 2015 Free Software Foundation, Inc.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#ifndef INCLUDED_DTV_DVBT_DVBT_DEMAP_H
#define INCLUDED_DTV_DVBT_DVBT_DEMAP_H

#include <gnuradio/block.h>
#include <gnuradio/dtv/api.h>
#include <gnuradio/dtv/dvb_config.h>
#include <gnuradio/dtv/dvbt_config.h>

namespace gr {
namespace dtv {

/*!
 * \brief DVB-T demapper.
 * \ingroup block_dtv_dvbt_demap
 *
 * ETSI EN 300 744 Clause 4.3.5. \n
 * Data input format: \n
 * complex(real(float), imag(float)). \n
 * Data output format: \n
 * 000000Y0Y1 - QPSK. \n
 * 0000Y0Y1Y2Y3 - 16QAM. \n
 * 00Y0Y1Y2Y3Y4Y5 - 64QAM.
 */
class DTV_API dvbt_demap : virtual public block
{
public:
    typedef std::shared_ptr<dvbt_demap> sptr;

    /*!
     * \brief Create a DVB-T demapper.
     *
     * \param nsize length of input stream. \n
     * \param constellation constellation used. \n
     * \param hierarchy hierarchy used. \n
     * \param transmission transmission mode used. \n
     * \param gain gain of complex input stream.
     */
    static sptr make(int nsize,
                     dvb_constellation_t constellation,
                     dvbt_hierarchy_t hierarchy,
                     dvbt_transmission_mode_t transmission,
                     float gain);
};

} // namespace dtv
} // namespace gr

#endif /* INCLUDED_DTV_DVBT_DVBT_DEMAP_H */
