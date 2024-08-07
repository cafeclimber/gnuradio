/* -*- c++ -*- */
/*
 * Copyright 2015,2017 Free Software Foundation, Inc.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#ifndef INCLUDED_DTV_DVBT2_MODULATOR_BC_H
#define INCLUDED_DTV_DVBT2_MODULATOR_BC_H

#include <gnuradio/block.h>
#include <gnuradio/dtv/api.h>
#include <gnuradio/dtv/dvb_config.h>
#include <gnuradio/dtv/dvbt2_config.h>

namespace gr {
namespace dtv {

/*!
 * \brief Modulates DVB-T2 cells.
 * \ingroup block_dtv_dvbt2_modulator
 *
 * Input: Bit interleaved (with column twist and bit to cell word de-multiplexing) cells.
 * \n Output: QPSK, 16QAM, 64QAM or 256QAM modulated complex IQ values (cells).
 */
class DTV_API dvbt2_modulator_bc : virtual public gr::block
{
public:
    typedef std::shared_ptr<dvbt2_modulator_bc> sptr;

    /*!
     * \brief Create a DVB-T2 constellation modulator.
     *
     * \param framesize FEC frame size (normal or short).
     * \param constellation DVB-T2 constellation.
     * \param rotation DVB-T2 constellation rotation (on or off).
     */
    static sptr make(dvb_framesize_t framesize,
                     dvb_constellation_t constellation,
                     dvbt2_rotation_t rotation);
};

} // namespace dtv
} // namespace gr

#endif /* INCLUDED_DTV_DVBT2_MODULATOR_BC_H */
