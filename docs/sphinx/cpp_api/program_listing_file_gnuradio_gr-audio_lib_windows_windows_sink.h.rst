
.. _program_listing_file_gnuradio_gr-audio_lib_windows_windows_sink.h:

Program Listing for File windows_sink.h
=======================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gr-audio_lib_windows_windows_sink.h>` (``gnuradio/gr-audio/lib/windows/windows_sink.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2004-2011,2013 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef INCLUDED_AUDIO_WINDOWS_SINK_H
   #define INCLUDED_AUDIO_WINDOWS_SINK_H
   
   #ifndef WIN32_LEAN_AND_MEAN
   #define WIN32_LEAN_AND_MEAN
   #endif
   #ifndef NOMINMAX
   #define NOMINMAX // stops windef.h defining max/min under cygwin
   #endif
   
   #include <mmsystem.h>
   #include <windows.h>
   
   #include <gnuradio/audio/sink.h>
   #include <gnuradio/logger.h>
   #include <string>
   
   namespace gr {
   namespace audio {
   
   class windows_sink : public sink
   {
       int d_sampling_freq;
       std::string d_device_name;
       int d_fd;
       LPWAVEHDR* d_buffers;
       DWORD d_chunk_size;
       DWORD d_buffer_size;
       bool d_ok_to_block;
       HWAVEOUT d_h_waveout;
       HANDLE d_wave_write_event;
       WAVEFORMATEX wave_format;
   
   protected:
       int string_to_int(const std::string& s);
       int open_waveout_device(void);
       int write_waveout(LPWAVEHDR lp_wave_hdr);
       MMRESULT is_format_supported(LPWAVEFORMATEX pwfx, UINT uDeviceID);
       bool is_number(const std::string& s);
       UINT find_device(std::string szDeviceName);
   
   public:
       windows_sink(int sampling_freq, const std::string device_name, bool ok_to_block);
       ~windows_sink();
   
       int work(int noutput_items,
                gr_vector_const_void_star& input_items,
                gr_vector_void_star& output_items);
   };
   
   } /* namespace audio */
   } /* namespace gr */
   
   #endif /* INCLUDED_AUDIO_WINDOWS_SINK_H */
