/* -*- c++ -*- */
/*
 * Copyright 2017 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#ifndef INCLUDED_BLOCKS_TAG_SHARE_H
#define INCLUDED_BLOCKS_TAG_SHARE_H

#include <gnuradio/blocks/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
namespace blocks {

/*!
 * \brief Adds tags from Input 1 onto Input 0's stream.
 * \ingroup block_blocks_tag_share
 *
 * \details
 * This block utilizes the GNU Radio runtime's tag propagation policy
 * to transfer or share Input 1's tags to Input 0's stream. This is
 * useful when a signal is detected via a correlate_access_code_bb or
 * a threshold crossing from a complex_to_mag_squared block. The tag from
 * that detection is on the alternate stream, either bytes or floats.
 * Often there is further signal processing that should be done on the
 * complex stream. This block allows the detection tags to be added to
 * the complex stream to trigger downstream processing without the need of
 * redundant trigger inputs on all subsequent blocks.
 */
class BLOCKS_API tag_share : virtual public gr::sync_block
{
public:
    typedef std::shared_ptr<tag_share> sptr;

    /*!
     * \param sizeof_io_item The size of the Input 0/Output 0 stream type. Input 0
     * stream items will be directly copied to Output 0.
     * \param sizeof_share_item The size of the Input 1 (tag share) stream type. This
     * stream type does not have to match the input/output stream type. Tags from
     * Input 1's items will be combined with Input 0's item tags and outputted on
     * Output 0.
     * \param vlen The vector size of the input and output stream items
     */
    static sptr make(size_t sizeof_io_item, size_t sizeof_share_item, size_t vlen = 1);
};

} // namespace blocks
} // namespace gr

#endif /* INCLUDED_BLOCKS_TAG_SHARE_H */
