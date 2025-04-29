
.. _program_listing_file_gnuradio_gnuradio-runtime_include_gnuradio_io_signature.h:

Program Listing for File io_signature.h
=======================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_include_gnuradio_io_signature.h>` (``gnuradio/gnuradio-runtime/include/gnuradio/io_signature.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2004,2007 Free Software Foundation, Inc.
    * Copyright 2023 Marcus Müller
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef INCLUDED_IO_SIGNATURE_H
   #define INCLUDED_IO_SIGNATURE_H
   /* ensure that tweakme.h is included before the bundled spdlog/fmt header, see
    * https://github.com/gabime/spdlog/issues/2922 */
   #include <spdlog/tweakme.h>
   
   #include <gnuradio/api.h>
   #include <spdlog/fmt/fmt.h>
   #include <string_view>
   #include <memory>
   
   #include <gnuradio/buffer_type.h>
   // For testing purposes, force single mapped buffers to make all QA use them
   // #define FORCE_SINGLE_MAPPED
   #ifdef FORCE_SINGLE_MAPPED
   #include <gnuradio/host_buffer.h>
   #else
   #include <gnuradio/buffer_double_mapped.h>
   #endif
   
   
   namespace gr {
   
   class GR_RUNTIME_API io_signature
   {
       int d_min_streams;
       int d_max_streams;
       std::vector<size_t> d_sizeof_stream_item;
       gr_vector_buffer_type d_stream_buffer_type;
   
       io_signature(int min_streams,
                    int max_streams,
                    const std::vector<size_t>& sizeof_stream_items,
                    const gr_vector_buffer_type& buftypes);
   
   public:
       typedef std::shared_ptr<io_signature> sptr;
   
   #ifdef FORCE_SINGLE_MAPPED
       using default_buftype = host_buffer;
   #else
       using default_buftype = buffer_double_mapped;
   #endif
   
       static constexpr int IO_INFINITE = -1;
   
       ~io_signature();
   
       static sptr make(int min_streams,
                        int max_streams,
                        int sizeof_stream_item,
                        buffer_type buftype = default_buftype::type);
   
   
       static sptr make(int min_streams,
                        int max_streams,
                        const std::vector<size_t>& sizeof_stream_items,
                        const gr::gr_vector_buffer_type& buftypes =
                            gr::gr_vector_buffer_type(1, default_buftype::type));
   
       //[[deprecated("Use generic make(min, max, {…})")]]
       static sptr make2(int min_streams,
                         int max_streams,
                         int sizeof_stream_item1,
                         int sizeof_stream_item2,
                         buffer_type buftype1 = default_buftype::type,
                         buffer_type buftype2 = default_buftype::type);
   
       //[[deprecated("Use generic make(min, max, {…})")]]
       static sptr make3(int min_streams,
                         int max_streams,
                         int sizeof_stream_item1,
                         int sizeof_stream_item2,
                         int sizeof_stream_item3,
                         buffer_type buftype1 = default_buftype::type,
                         buffer_type buftype2 = default_buftype::type,
                         buffer_type buftype3 = default_buftype::type);
   
       //[[deprecated("Use generic make(min, max, {…})")]]
       static sptr
       makev(int min_streams, int max_streams, const std::vector<int>& sizeof_stream_items);
   
       //[[deprecated("Use generic make(min, max, {…})")]]
       static sptr makev(int min_streams,
                         int max_streams,
                         const std::vector<int>& sizeof_stream_items,
                         const gr_vector_buffer_type& buftypes);
   
       int min_streams() const { return d_min_streams; }
       int max_streams() const { return d_max_streams; }
       int sizeof_stream_item(int index) const;
       // TODO: convert API to <size_t>
       std::vector<int> sizeof_stream_items() const;
       buffer_type stream_buffer_type(size_t index) const;
       gr_vector_buffer_type stream_buffer_types() const;
       friend bool operator==(const io_signature& lhs, const io_signature& rhs);
   };
   
   bool operator==(const io_signature& lhs, const io_signature& rhs);
   } /* namespace gr */
   
   template <>
   struct GR_RUNTIME_API fmt::formatter<gr::io_signature> : formatter<std::string_view> {
       fmt::format_context::iterator format(const gr::io_signature& iosig,
                                            format_context& ctx) const;
   };
   #endif /* INCLUDED_IO_SIGNATURE_H */
