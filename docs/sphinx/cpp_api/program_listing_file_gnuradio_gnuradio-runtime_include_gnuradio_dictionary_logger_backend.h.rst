
.. _program_listing_file_gnuradio_gnuradio-runtime_include_gnuradio_dictionary_logger_backend.h:

Program Listing for File dictionary_logger_backend.h
====================================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_include_gnuradio_dictionary_logger_backend.h>` (``gnuradio/gnuradio-runtime/include/gnuradio/dictionary_logger_backend.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2022 Marcus Müller
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   #ifndef INCLUDED_DICTIONARY_LOGGER_BACKEND_H
   #define INCLUDED_DICTIONARY_LOGGER_BACKEND_H
   #include <spdlog/common.h>
   #include <spdlog/details/null_mutex.h>
   #include <spdlog/sinks/base_sink.h>
   #include <unordered_map>
   #include <memory>
   #include <mutex>
   #include <regex>
   #include <set>
   #include <utility>
   
   #include <gnuradio/api.h>
   namespace gr {
   class GR_RUNTIME_API dictionary_logger_backend final
       : public spdlog::sinks::base_sink<spdlog::details::null_mutex>
   {
   public:
       using log_entry = std::pair<spdlog::log_clock::time_point, std::string>;
       using log_map = std::unordered_map<std::string, std::set<log_entry>>;
   
       dictionary_logger_backend();
   
       dictionary_logger_backend(std::regex src_regex);
   
       /* \brief retrieve a copy of the map containing all logs
        * The individual logs are accessible through the names! of the respective loggers.
        */
       log_map get_map() const { return log_entries; };
   
       ~dictionary_logger_backend() override{};
   
   protected:
       void sink_it_(const spdlog::details::log_msg& message) override;
       void flush_() override{};
   
   private:
       mutable std::mutex map_mutex;
       bool has_regex = false;
       std::regex src_regex;
       log_map log_entries;
   };
   } // namespace gr
   #endif
