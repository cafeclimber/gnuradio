
.. _program_listing_file_gnuradio_gnuradio-runtime_include_gnuradio_prefs.h:

Program Listing for File prefs.h
================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_include_gnuradio_prefs.h>` (``gnuradio/gnuradio-runtime/include/gnuradio/prefs.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2006,2013,2015 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef INCLUDED_GR_PREFS_H
   #define INCLUDED_GR_PREFS_H
   
   #include <gnuradio/api.h>
   #include <gnuradio/thread/thread.h>
   #include <map>
   #include <mutex>
   #include <string>
   
   namespace gr {
   
   class GR_RUNTIME_API prefs
   {
   public:
       static prefs* singleton();
   
       prefs();
   
       void add_config_file(const std::string& configfile);
   
       std::string to_string();
   
       void save();
   
       bool has_section(const std::string& section);
   
       bool has_option(const std::string& section, const std::string& option);
   
       const std::string get_string(const std::string& section,
                                    const std::string& option,
                                    const std::string& default_val);
   
       void set_string(const std::string& section,
                       const std::string& option,
                       const std::string& val);
   
       bool
       get_bool(const std::string& section, const std::string& option, bool default_val);
   
       void set_bool(const std::string& section, const std::string& option, bool val);
   
       long
       get_long(const std::string& section, const std::string& option, long default_val);
   
       void set_long(const std::string& section, const std::string& option, long val);
   
       double
       get_double(const std::string& section, const std::string& option, double default_val);
   
       void set_double(const std::string& section, const std::string& option, double val);
   
   protected:
       std::vector<std::string> _sys_prefs_filenames();
       void _read_files(const std::vector<std::string>& filenames);
       char* option_to_env(std::string section, std::string option);
       template <typename T>
       T get_general(const std::string& section,
                     const std::string& option,
                     const T& default_val);
       template <typename T>
       void set_general(const std::string& section, const std::string& option, const T& val);
   
   private:
       std::mutex d_mutex;
       std::map<std::string, std::map<std::string, std::string>> d_config_map;
   };
   
   } /* namespace gr */
   
   #endif /* INCLUDED_GR_PREFS_H */
