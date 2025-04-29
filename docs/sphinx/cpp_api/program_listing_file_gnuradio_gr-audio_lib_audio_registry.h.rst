
.. _program_listing_file_gnuradio_gr-audio_lib_audio_registry.h:

Program Listing for File audio_registry.h
=========================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gr-audio_lib_audio_registry.h>` (``gnuradio/gr-audio/lib/audio_registry.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /*
    * Copyright 2011-2014 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef INCLUDED_GR_AUDIO_REGISTRY_H
   #define INCLUDED_GR_AUDIO_REGISTRY_H
   
   #include <gnuradio/audio/sink.h>
   #include <gnuradio/audio/source.h>
   #include <string>
   
   namespace gr {
   namespace audio {
   
   typedef source::sptr (*source_factory_t)(int, const std::string&, bool);
   typedef sink::sptr (*sink_factory_t)(int, const std::string&, bool);
   
   enum reg_prio_type { REG_PRIO_LOW = 100, REG_PRIO_MED = 200, REG_PRIO_HIGH = 300 };
   
   struct source_entry_t {
       reg_prio_type prio;
       std::string arch;
       source_factory_t source;
   };
   
   struct sink_entry_t {
       reg_prio_type prio;
       std::string arch;
       sink_factory_t sink;
   };
   
   source_entry_t
   register_source(reg_prio_type prio, const std::string& arch, source_factory_t source);
   sink_entry_t
   register_sink(reg_prio_type prio, const std::string& arch, sink_factory_t sink);
   
   #ifdef ALSA_FOUND
   source::sptr
   alsa_source_fcn(int sampling_rate, const std::string& device_name, bool ok_to_block);
   sink::sptr
   alsa_sink_fcn(int sampling_rate, const std::string& device_name, bool ok_to_block);
   #endif /* ALSA_FOUND */
   
   #ifdef OSS_FOUND
   source::sptr
   oss_source_fcn(int sampling_rate, const std::string& device_name, bool ok_to_block);
   sink::sptr
   oss_sink_fcn(int sampling_rate, const std::string& device_name, bool ok_to_block);
   #endif /* OSS_FOUND */
   
   #ifdef PORTAUDIO_FOUND
   source::sptr
   portaudio_source_fcn(int sampling_rate, const std::string& device_name, bool ok_to_block);
   sink::sptr
   portaudio_sink_fcn(int sampling_rate, const std::string& device_name, bool ok_to_block);
   #endif /* PORTAUDIO_FOUND */
   
   #ifdef JACK_FOUND
   source::sptr
   jack_source_fcn(int sampling_rate, const std::string& device_name, bool ok_to_block);
   sink::sptr
   jack_sink_fcn(int sampling_rate, const std::string& device_name, bool ok_to_block);
   #endif /* JACK_FOUND */
   
   #ifdef OSX_FOUND
   source::sptr
   osx_source_fcn(int sampling_rate, const std::string& device_name, bool ok_to_block);
   sink::sptr
   osx_sink_fcn(int sampling_rate, const std::string& device_name, bool ok_to_block);
   #endif /* OSX_FOUND */
   
   #ifdef WIN32_FOUND
   source::sptr
   windows_source_fcn(int sampling_rate, const std::string& device_name, bool ok_to_block);
   sink::sptr
   windows_sink_fcn(int sampling_rate, const std::string& device_name, bool ok_to_block);
   #endif /* WIN32_FOUND */
   
   } /* namespace audio */
   } /* namespace gr */
   
   #endif /* INCLUDED_GR_AUDIO_REGISTRY_H */
