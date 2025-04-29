
.. _program_listing_file_gnuradio_gnuradio-runtime_include_gnuradio_logger.h:

Program Listing for File logger.h
=================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_include_gnuradio_logger.h>` (``gnuradio/gnuradio-runtime/include/gnuradio/logger.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2012-2013 Free Software Foundation, Inc.
    * Copyright 2021,2022 Marcus Müller
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef INCLUDED_GR_LOGGER_H
   #define INCLUDED_GR_LOGGER_H
   
   #ifdef DISABLE_LOGGER_H
   // pygccxml as of v2.2.1 has a difficult time parsing headers that
   // include spdlog or format
   // Since it only needs the top level header info, this is a hack to not
   // transitively include anything logger related when parsing the
   // headers
   #include <memory>
   namespace gr {
   using logger_ptr = std::shared_ptr<void>;
   }
   #else
   
   // Since this file is included in *all* gr::blocks, please make sure this list of includes
   // keeps as short as possible; if anything is needed only by the implementation in
   // buffer.cc, then only include it there
   #include <gnuradio/api.h>
   #include <spdlog/common.h> /* important to include before spdlog/fmt/anything.h,
                               * see https://github.com/gabime/spdlog/issues/2922 */
   #include <spdlog/fmt/fmt.h>
   #include <spdlog/fmt/ostr.h>
   #include <spdlog/version.h>
   #include <memory>
   
   #include <spdlog/spdlog.h>
   
   #include <spdlog/sinks/dist_sink.h>
   
   namespace gr {
   using log_level = spdlog::level::level_enum;
   
   class GR_RUNTIME_API logging
   {
   public:
       /* \brief deleted copy constructor
        * get your own logging system, or, more likely, use the singleton.
        */
       logging(logging const&) = delete;
   
       // \brief deleted assignment operator
       void operator=(logging const&) = delete;
   
       // \brief singleton to access the one logging system
       static logging& singleton();
   
       inline log_level default_level() const { return _default_backend->level(); }
   
       inline log_level debug_level() const { return _debug_backend->level(); }
   
       void set_default_level(log_level level);
   
       void set_debug_level(log_level level);
   
       spdlog::sink_ptr default_backend() const;
       void add_default_sink(const spdlog::sink_ptr& sink);
       void add_debug_sink(const spdlog::sink_ptr& sink);
       void add_default_console_sink();
       void add_debug_console_sink();
   
       static constexpr const char* default_pattern = "%n :%l: %v";
   
   private:
       logging();
       std::shared_ptr<spdlog::sinks::dist_sink_mt> _default_backend, _debug_backend;
   };
   
   /********************* Start  Classes and Methods for Python ******************/
   class GR_RUNTIME_API logger
   {
   private:
       std::string _name;
       using underlying_logger_ptr = std::shared_ptr<spdlog::logger>;
   
   #if SPDLOG_VERSION >= 11000
       // spdlog 1.10 onwards can depend either on fmt or std format, so it defined
       // its own alias for format strings
       template <typename... Args>
       using format_string_t = spdlog::format_string_t<Args...>;
   #elif SPDLOG_VERSION >= 10910
       // spdlog 1.9.1 supported/enforced fmt compile time format string validation
       // in c++20 by using fmt::format_string in its logging functions
       template <typename... Args>
       using format_string_t = fmt::format_string<Args...>;
   #else
       // lower versions of spdlog did not support compile time validation
       template <typename... Args>
       using format_string_t = const spdlog::string_view_t&;
   #endif
   
   public:
       logger(const std::string& logger_name);
   
       // FIXME implement or = default
       ~logger() = default;
   
       underlying_logger_ptr d_logger;
   
       // Wrappers for logging macros
       void set_level(const std::string& level);
       void set_level(const log_level level);
   
       void get_level(std::string& level) const;
       const std::string get_string_level() const;
       log_level get_level() const;
   
       const std::string& name() const;
       void set_name(const std::string& name);
   
       template <typename... Args>
       inline void trace(format_string_t<Args...> msg, Args&&... args)
       {
           d_logger->trace(msg, std::forward<Args>(args)...);
       }
   
       template <typename... Args>
       inline void debug(format_string_t<Args...> msg, Args&&... args)
       {
           d_logger->debug(msg, std::forward<Args>(args)...);
       }
   
       template <typename... Args>
       inline void info(format_string_t<Args...> msg, Args&&... args)
       {
           d_logger->info(msg, std::forward<Args>(args)...);
       }
   
       template <typename... Args>
       inline void notice(format_string_t<Args...> msg, Args&&... args)
       {
           d_logger->info(msg, std::forward<Args>(args)...);
       }
   
       template <typename... Args>
       inline void warn(format_string_t<Args...> msg, Args&&... args)
       {
           d_logger->warn(msg, std::forward<Args>(args)...);
       }
   
       template <typename... Args>
       inline void error(format_string_t<Args...> msg, Args&&... args)
       {
           d_logger->error(msg, std::forward<Args>(args)...);
       }
   
       template <typename... Args>
       inline void crit(format_string_t<Args...> msg, Args&&... args)
       {
           d_logger->critical(msg, std::forward<Args>(args)...);
       }
   
       template <typename... Args>
       inline void alert(format_string_t<Args...> msg, Args&&... args)
       {
           d_logger->critical(msg, std::forward<Args>(args)...);
       }
   
       template <typename... Args>
       inline void fatal(format_string_t<Args...> msg, Args&&... args)
       {
           d_logger->critical(msg, std::forward<Args>(args)...);
       }
   
       template <typename... Args>
       inline void emerg(format_string_t<Args...> msg, Args&&... args)
       {
           d_logger->critical(msg, std::forward<Args>(args)...);
       }
       template <typename... Args>
       inline void
       log(spdlog::level::level_enum level, format_string_t<Args...> msg, Args&&... args)
       {
           d_logger->log(level, msg, std::forward<Args>(args)...);
       }
   };
   using logger_ptr = std::shared_ptr<logger>;
   
   GR_RUNTIME_API bool
   configure_default_loggers(gr::logger_ptr& l, gr::logger_ptr& d, const std::string& name);
   
   } /* namespace gr */
   
   // global logging shorthands
   
   #define GR_LOG_TRACE(log, msg)     \
       {                              \
           log->d_logger->trace(msg); \
       }
   
   #define GR_LOG_DEBUG(log, msg)     \
       {                              \
           log->d_logger->debug(msg); \
       }
   
   #define GR_LOG_INFO(log, msg)     \
       {                             \
           log->d_logger->info(msg); \
       }
   
   #define GR_LOG_NOTICE(log, msg)   \
       {                             \
           log->d_logger->info(msg); \
       }
   
   
   #define GR_LOG_WARN(log, msg)     \
       {                             \
           log->d_logger->warn(msg); \
       }
   
   #define GR_LOG_ERROR(log, msg)     \
       {                              \
           log->d_logger->error(msg); \
       }
   
   #define GR_LOG_CRIT(log, msg)         \
       {                                 \
           log->d_logger->critical(msg); \
       }
   
   #define GR_LOG_ALERT(log, msg)        \
       {                                 \
           log->d_logger->critical(msg); \
       }
   
   #define GR_LOG_FATAL(log, msg)        \
       {                                 \
           log->d_logger->critical(msg); \
       }
   
   #define GR_LOG_EMERG(log, msg)        \
       {                                 \
           log->d_logger->critical(msg); \
       }
   
   #endif
   
   #endif /* INCLUDED_GR_LOGGER_H */
