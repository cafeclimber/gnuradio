/* -*- c++ -*- */
/*
 * Copyright 2015,2017 Free Software Foundation, Inc.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#ifndef INCLUDED_DTV_DVBT2_MISO_CC_H
#define INCLUDED_DTV_DVBT2_MISO_CC_H

#include <gnuradio/dtv/api.h>
#include <gnuradio/dtv/dvb_config.h>
#include <gnuradio/dtv/dvbt2_config.h>
#include <gnuradio/sync_block.h>

namespace gr {
namespace dtv {

/*!
 * \brief Splits the stream for MISO (Multiple Input Single Output).
 * \ingroup block_dtv_dvbt2_miso
 *
 * Input: Frequency interleaved T2 frame. \n
 * Output1: Frequency interleaved T2 frame (copy of input). \n
 * Output2: Frequency interleaved T2 frame with modified Alamouti processing.
 */
class DTV_API dvbt2_miso_cc : virtual public gr::sync_block
{
public:
    typedef std::shared_ptr<dvbt2_miso_cc> sptr;

    /*!
     * \brief Create a MISO processor.
     *
     * \param carriermode number of carriers (normal or extended).
     * \param fftsize OFDM IFFT size.
     * \param pilotpattern DVB-T2 pilot pattern (PP1 - PP8).
     * \param guardinterval OFDM ISI guard interval.
     * \param numdatasyms number of OFDM symbols in a T2 frame.
     * \param paprmode PAPR reduction mode.
     */
    static sptr make(dvbt2_extended_carrier_t carriermode,
                     dvbt2_fftsize_t fftsize,
                     dvbt2_pilotpattern_t pilotpattern,
                     dvb_guardinterval_t guardinterval,
                     int numdatasyms,
                     dvbt2_papr_t paprmode);
};

} // namespace dtv
} // namespace gr

#endif /* INCLUDED_DTV_DVBT2_MISO_CC_H */
