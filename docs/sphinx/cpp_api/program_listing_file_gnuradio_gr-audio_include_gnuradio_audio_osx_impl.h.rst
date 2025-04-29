
.. _program_listing_file_gnuradio_gr-audio_include_gnuradio_audio_osx_impl.h:

Program Listing for File osx_impl.h
===================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gr-audio_include_gnuradio_audio_osx_impl.h>` (``gnuradio/gr-audio/include/gnuradio/audio/osx_impl.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2006, 2013-2014 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio.
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef INCLUDED_AUDIO_OSX_IMPL_H
   #define INCLUDED_AUDIO_OSX_IMPL_H
   
   #include <gnuradio/audio/api.h>
   
   #include <vector>
   
   #include <string.h>
   
   #include <AudioToolbox/AudioToolbox.h>
   #include <AudioUnit/AudioUnit.h>
   
   // helper function to print an ASBD
   
   std::ostream& GR_AUDIO_API operator<<(std::ostream& s,
                                         const AudioStreamBasicDescription& asbd);
   
   namespace gr {
   namespace audio {
   namespace osx {
   
   // returns the number of channels for the provided AudioDeviceID,
   // input and/or output depending on if the pointer is valid.
   
   void GR_AUDIO_API get_num_channels_for_audio_device_id(AudioDeviceID ad_id,
                                                          UInt32* n_input,
                                                          UInt32* n_output);
   
   // search all known audio devices, input or output, for all that
   // match the provided device_name string (in part or in whole).
   // Returns a vector of all matching IDs, and another of all
   // matching names.  If the device name is empty, then match all
   // input or output devices.
   
   void GR_AUDIO_API find_audio_devices(const std::string& device_name,
                                        bool is_input,
                                        std::vector<AudioDeviceID>* all_ad_ids,
                                        std::vector<std::string>* all_names);
   
   } /* namespace osx */
   } /* namespace audio */
   } /* namespace gr */
   
   #endif /* INCLUDED_AUDIO_OSX_IMPL_H */
