
.. _program_listing_file_gnuradio_gnuradio-runtime_include_pmt_pmt.h:

Program Listing for File pmt.h
==============================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_include_pmt_pmt.h>` (``gnuradio/gnuradio-runtime/include/pmt/pmt.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2006,2009,2010,2013 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef INCLUDED_PMT_H
   #define INCLUDED_PMT_H
   
   #include <pmt/api.h>
   
   #include <string_view>
   #include <any>
   #include <complex>
   #include <cstdint>
   #include <iosfwd>
   #include <memory>
   #include <stdexcept>
   #include <string>
   #include <vector>
   
   namespace gr {
   namespace messages {
   class msg_accepter;
   }
   } // namespace gr
   
   namespace pmt {
   
   class PMT_API pmt_base
   {
   
   public:
       pmt_base(){};
       pmt_base(const pmt_base&) = delete;
       virtual ~pmt_base();
   
       virtual bool is_bool() const { return false; }
       virtual bool is_symbol() const { return false; }
       virtual bool is_number() const { return false; }
       virtual bool is_integer() const { return false; }
       virtual bool is_uint64() const { return false; }
       virtual bool is_real() const { return false; }
       virtual bool is_complex() const { return false; }
       virtual bool is_null() const { return false; }
       virtual bool is_pair() const { return false; }
       virtual bool is_tuple() const { return false; }
       virtual bool is_vector() const { return false; }
       virtual bool is_dict() const { return false; }
       virtual bool is_any() const { return false; }
   
       virtual bool is_uniform_vector() const { return false; }
       virtual bool is_u8vector() const { return false; }
       virtual bool is_s8vector() const { return false; }
       virtual bool is_u16vector() const { return false; }
       virtual bool is_s16vector() const { return false; }
       virtual bool is_u32vector() const { return false; }
       virtual bool is_s32vector() const { return false; }
       virtual bool is_u64vector() const { return false; }
       virtual bool is_s64vector() const { return false; }
       virtual bool is_f32vector() const { return false; }
       virtual bool is_f64vector() const { return false; }
       virtual bool is_c32vector() const { return false; }
       virtual bool is_c64vector() const { return false; }
   };
   
   typedef std::shared_ptr<pmt_base> pmt_t;
   
   class PMT_API exception : public std::logic_error
   {
   public:
       exception(const std::string& msg, pmt_t obj);
   };
   
   class PMT_API wrong_type : public std::invalid_argument
   {
   public:
       wrong_type(const std::string& msg, pmt_t obj);
   };
   
   class PMT_API out_of_range : public exception
   {
   public:
       out_of_range(const std::string& msg, pmt_t obj);
   };
   
   class PMT_API notimplemented : public exception
   {
   public:
       notimplemented(const std::string& msg, pmt_t obj);
   };
   
   
   /*
    * ------------------------------------------------------------------------
    * Constants
    * ------------------------------------------------------------------------
    */
   
   PMT_API pmt_t get_PMT_NIL();
   PMT_API pmt_t get_PMT_T();
   PMT_API pmt_t get_PMT_F();
   PMT_API pmt_t get_PMT_EOF();
   
   #define PMT_NIL get_PMT_NIL()
   #define PMT_T get_PMT_T()
   #define PMT_F get_PMT_F()
   #define PMT_EOF get_PMT_EOF()
   
   
   /*
    * ------------------------------------------------------------------------
    * Booleans.  Two constants, #t and #f.
    *
    * In predicates, anything that is not #f is considered true.
    * I.e., there is a single false value, #f.
    * ------------------------------------------------------------------------
    */
   
   PMT_API bool is_bool(pmt_t obj);
   
   PMT_API bool is_true(pmt_t obj);
   
   PMT_API bool is_false(pmt_t obj);
   
   PMT_API pmt_t from_bool(bool val);
   
   // else raise wrong_type exception.
   PMT_API bool to_bool(pmt_t val);
   
   /*
    * ------------------------------------------------------------------------
    *                 Symbols
    * ------------------------------------------------------------------------
    */
   
   PMT_API bool is_symbol(const pmt_t& obj);
   
   PMT_API pmt_t string_to_symbol(std::string_view s);
   
   PMT_API pmt_t intern(std::string_view s);
   
   
   PMT_API const std::string symbol_to_string(const pmt_t& sym);
   
   /*
    * ------------------------------------------------------------------------
    *           Numbers: we support integer, real and complex
    * ------------------------------------------------------------------------
    */
   
   PMT_API bool is_number(pmt_t obj);
   
   /*
    * ------------------------------------------------------------------------
    *                 Integers
    * ------------------------------------------------------------------------
    */
   
   PMT_API bool is_integer(pmt_t x);
   
   PMT_API pmt_t from_long(long x);
   
   PMT_API long to_long(pmt_t x);
   
   /*
    * ------------------------------------------------------------------------
    *                 uint64_t
    * ------------------------------------------------------------------------
    */
   
   PMT_API bool is_uint64(pmt_t x);
   
   PMT_API pmt_t from_uint64(uint64_t x);
   
   PMT_API uint64_t to_uint64(pmt_t x);
   
   /*
    * ------------------------------------------------------------------------
    *              Reals
    * ------------------------------------------------------------------------
    */
   
   /*
    * \brief Return true if \p obj is a real number, else false.
    */
   PMT_API bool is_real(pmt_t obj);
   
   PMT_API pmt_t from_double(double x);
   PMT_API pmt_t from_float(float x);
   
   PMT_API double to_double(pmt_t x);
   
   PMT_API float to_float(pmt_t x);
   
   /*
    * ------------------------------------------------------------------------
    *                 Complex
    * ------------------------------------------------------------------------
    */
   
   PMT_API bool is_complex(pmt_t obj);
   
   PMT_API pmt_t make_rectangular(double re, double im);
   
   PMT_API pmt_t from_complex(double re, double im);
   
   PMT_API pmt_t from_complex(const std::complex<double>& z);
   
   PMT_API pmt_t pmt_from_complex(double re, double im);
   
   PMT_API pmt_t pmt_from_complex(const std::complex<double>& z);
   
   PMT_API std::complex<double> to_complex(pmt_t z);
   
   /*
    * ------------------------------------------------------------------------
    *              Pairs
    * ------------------------------------------------------------------------
    */
   
   PMT_API bool is_null(const pmt_t& x);
   
   PMT_API bool is_pair(const pmt_t& obj);
   
   PMT_API pmt_t cons(const pmt_t& x, const pmt_t& y);
   
   PMT_API pmt_t car(const pmt_t& pair);
   
   PMT_API pmt_t cdr(const pmt_t& pair);
   
   PMT_API void set_car(pmt_t pair, pmt_t value);
   
   PMT_API void set_cdr(pmt_t pair, pmt_t value);
   
   PMT_API pmt_t caar(pmt_t pair);
   PMT_API pmt_t cadr(pmt_t pair);
   PMT_API pmt_t cdar(pmt_t pair);
   PMT_API pmt_t cddr(pmt_t pair);
   PMT_API pmt_t caddr(pmt_t pair);
   PMT_API pmt_t cadddr(pmt_t pair);
   
   /*
    * ------------------------------------------------------------------------
    *                    Tuples
    *
    * Store a fixed number of objects.  Tuples are not modifiable, and thus
    * are excellent for use as messages.  Indexing is zero based.
    * Access time to an element is O(1).
    * ------------------------------------------------------------------------
    */
   
   PMT_API bool is_tuple(pmt_t x);
   
   PMT_API pmt_t make_tuple();
   PMT_API pmt_t make_tuple(const pmt_t& e0);
   PMT_API pmt_t make_tuple(const pmt_t& e0, const pmt_t& e1);
   PMT_API pmt_t make_tuple(const pmt_t& e0, const pmt_t& e1, const pmt_t& e2);
   PMT_API pmt_t make_tuple(const pmt_t& e0,
                            const pmt_t& e1,
                            const pmt_t& e2,
                            const pmt_t& e3);
   PMT_API pmt_t make_tuple(
       const pmt_t& e0, const pmt_t& e1, const pmt_t& e2, const pmt_t& e3, const pmt_t& e4);
   PMT_API pmt_t make_tuple(const pmt_t& e0,
                            const pmt_t& e1,
                            const pmt_t& e2,
                            const pmt_t& e3,
                            const pmt_t& e4,
                            const pmt_t& e5);
   PMT_API pmt_t make_tuple(const pmt_t& e0,
                            const pmt_t& e1,
                            const pmt_t& e2,
                            const pmt_t& e3,
                            const pmt_t& e4,
                            const pmt_t& e5,
                            const pmt_t& e6);
   PMT_API pmt_t make_tuple(const pmt_t& e0,
                            const pmt_t& e1,
                            const pmt_t& e2,
                            const pmt_t& e3,
                            const pmt_t& e4,
                            const pmt_t& e5,
                            const pmt_t& e6,
                            const pmt_t& e7);
   PMT_API pmt_t make_tuple(const pmt_t& e0,
                            const pmt_t& e1,
                            const pmt_t& e2,
                            const pmt_t& e3,
                            const pmt_t& e4,
                            const pmt_t& e5,
                            const pmt_t& e6,
                            const pmt_t& e7,
                            const pmt_t& e8);
   PMT_API pmt_t make_tuple(const pmt_t& e0,
                            const pmt_t& e1,
                            const pmt_t& e2,
                            const pmt_t& e3,
                            const pmt_t& e4,
                            const pmt_t& e5,
                            const pmt_t& e6,
                            const pmt_t& e7,
                            const pmt_t& e8,
                            const pmt_t& e9);
   
   PMT_API pmt_t to_tuple(const pmt_t& x);
   
   PMT_API pmt_t tuple_ref(const pmt_t& tuple, size_t k);
   
   /*
    * ------------------------------------------------------------------------
    *                 Vectors
    *
    * These vectors can hold any kind of objects.  Indexing is zero based.
    * ------------------------------------------------------------------------
    */
   
   PMT_API bool is_vector(pmt_t x);
   
   PMT_API pmt_t make_vector(size_t k, pmt_t fill);
   
   PMT_API pmt_t vector_ref(pmt_t vector, size_t k);
   
   PMT_API void vector_set(pmt_t vector, size_t k, pmt_t obj);
   
   PMT_API void vector_fill(pmt_t vector, pmt_t fill);
   
   /*
    * ------------------------------------------------------------------------
    *            Binary Large Objects (BLOBs)
    *
    * Handy for passing around uninterpreted chunks of memory.
    * ------------------------------------------------------------------------
    */
   
   PMT_API bool is_blob(pmt_t x);
   
   PMT_API pmt_t make_blob(const void* buf, size_t len);
   
   PMT_API const void* blob_data(pmt_t blob);
   
   PMT_API size_t blob_length(pmt_t blob);
   
   PMT_API bool is_uniform_vector(pmt_t x);
   
   PMT_API bool is_u8vector(pmt_t x);
   PMT_API bool is_s8vector(pmt_t x);
   PMT_API bool is_u16vector(pmt_t x);
   PMT_API bool is_s16vector(pmt_t x);
   PMT_API bool is_u32vector(pmt_t x);
   PMT_API bool is_s32vector(pmt_t x);
   PMT_API bool is_u64vector(pmt_t x);
   PMT_API bool is_s64vector(pmt_t x);
   PMT_API bool is_f32vector(pmt_t x);
   PMT_API bool is_f64vector(pmt_t x);
   PMT_API bool is_c32vector(pmt_t x);
   PMT_API bool is_c64vector(pmt_t x);
   
   PMT_API size_t uniform_vector_itemsize(pmt_t x);
   
   PMT_API pmt_t make_u8vector(size_t k, uint8_t fill);
   PMT_API pmt_t make_s8vector(size_t k, int8_t fill);
   PMT_API pmt_t make_u16vector(size_t k, uint16_t fill);
   PMT_API pmt_t make_s16vector(size_t k, int16_t fill);
   PMT_API pmt_t make_u32vector(size_t k, uint32_t fill);
   PMT_API pmt_t make_s32vector(size_t k, int32_t fill);
   PMT_API pmt_t make_u64vector(size_t k, uint64_t fill);
   PMT_API pmt_t make_s64vector(size_t k, int64_t fill);
   PMT_API pmt_t make_f32vector(size_t k, float fill);
   PMT_API pmt_t make_f64vector(size_t k, double fill);
   PMT_API pmt_t make_c32vector(size_t k, std::complex<float> fill);
   PMT_API pmt_t make_c64vector(size_t k, std::complex<double> fill);
   
   PMT_API pmt_t init_u8vector(size_t k, const uint8_t* data);
   PMT_API pmt_t init_u8vector(size_t k, const std::vector<uint8_t>& data);
   PMT_API pmt_t init_s8vector(size_t k, const int8_t* data);
   PMT_API pmt_t init_s8vector(size_t k, const std::vector<int8_t>& data);
   PMT_API pmt_t init_u16vector(size_t k, const uint16_t* data);
   PMT_API pmt_t init_u16vector(size_t k, const std::vector<uint16_t>& data);
   PMT_API pmt_t init_s16vector(size_t k, const int16_t* data);
   PMT_API pmt_t init_s16vector(size_t k, const std::vector<int16_t>& data);
   PMT_API pmt_t init_u32vector(size_t k, const uint32_t* data);
   PMT_API pmt_t init_u32vector(size_t k, const std::vector<uint32_t>& data);
   PMT_API pmt_t init_s32vector(size_t k, const int32_t* data);
   PMT_API pmt_t init_s32vector(size_t k, const std::vector<int32_t>& data);
   PMT_API pmt_t init_u64vector(size_t k, const uint64_t* data);
   PMT_API pmt_t init_u64vector(size_t k, const std::vector<uint64_t>& data);
   PMT_API pmt_t init_s64vector(size_t k, const int64_t* data);
   PMT_API pmt_t init_s64vector(size_t k, const std::vector<int64_t>& data);
   PMT_API pmt_t init_f32vector(size_t k, const float* data);
   PMT_API pmt_t init_f32vector(size_t k, const std::vector<float>& data);
   PMT_API pmt_t init_f64vector(size_t k, const double* data);
   PMT_API pmt_t init_f64vector(size_t k, const std::vector<double>& data);
   PMT_API pmt_t init_c32vector(size_t k, const std::complex<float>* data);
   PMT_API pmt_t init_c32vector(size_t k, const std::vector<std::complex<float>>& data);
   PMT_API pmt_t init_c64vector(size_t k, const std::complex<double>* data);
   PMT_API pmt_t init_c64vector(size_t k, const std::vector<std::complex<double>>& data);
   
   PMT_API uint8_t u8vector_ref(pmt_t v, size_t k);
   PMT_API int8_t s8vector_ref(pmt_t v, size_t k);
   PMT_API uint16_t u16vector_ref(pmt_t v, size_t k);
   PMT_API int16_t s16vector_ref(pmt_t v, size_t k);
   PMT_API uint32_t u32vector_ref(pmt_t v, size_t k);
   PMT_API int32_t s32vector_ref(pmt_t v, size_t k);
   PMT_API uint64_t u64vector_ref(pmt_t v, size_t k);
   PMT_API int64_t s64vector_ref(pmt_t v, size_t k);
   PMT_API float f32vector_ref(pmt_t v, size_t k);
   PMT_API double f64vector_ref(pmt_t v, size_t k);
   PMT_API std::complex<float> c32vector_ref(pmt_t v, size_t k);
   PMT_API std::complex<double> c64vector_ref(pmt_t v, size_t k);
   
   PMT_API void u8vector_set(pmt_t v, size_t k, uint8_t x); //< v[k] = x
   PMT_API void s8vector_set(pmt_t v, size_t k, int8_t x);
   PMT_API void u16vector_set(pmt_t v, size_t k, uint16_t x);
   PMT_API void s16vector_set(pmt_t v, size_t k, int16_t x);
   PMT_API void u32vector_set(pmt_t v, size_t k, uint32_t x);
   PMT_API void s32vector_set(pmt_t v, size_t k, int32_t x);
   PMT_API void u64vector_set(pmt_t v, size_t k, uint64_t x);
   PMT_API void s64vector_set(pmt_t v, size_t k, int64_t x);
   PMT_API void f32vector_set(pmt_t v, size_t k, float x);
   PMT_API void f64vector_set(pmt_t v, size_t k, double x);
   PMT_API void c32vector_set(pmt_t v, size_t k, std::complex<float> x);
   PMT_API void c64vector_set(pmt_t v, size_t k, std::complex<double> x);
   
   // Return const pointers to the elements
   
   PMT_API const void*
   uniform_vector_elements(pmt_t v, size_t& len); //< works with any; len is in bytes
   
   PMT_API const uint8_t* u8vector_elements(pmt_t v, size_t& len);   //< len is in elements
   PMT_API const int8_t* s8vector_elements(pmt_t v, size_t& len);    //< len is in elements
   PMT_API const uint16_t* u16vector_elements(pmt_t v, size_t& len); //< len is in elements
   PMT_API const int16_t* s16vector_elements(pmt_t v, size_t& len);  //< len is in elements
   PMT_API const uint32_t* u32vector_elements(pmt_t v, size_t& len); //< len is in elements
   PMT_API const int32_t* s32vector_elements(pmt_t v, size_t& len);  //< len is in elements
   PMT_API const uint64_t* u64vector_elements(pmt_t v, size_t& len); //< len is in elements
   PMT_API const int64_t* s64vector_elements(pmt_t v, size_t& len);  //< len is in elements
   PMT_API const float* f32vector_elements(pmt_t v, size_t& len);    //< len is in elements
   PMT_API const double* f64vector_elements(pmt_t v, size_t& len);   //< len is in elements
   PMT_API const std::complex<float>* c32vector_elements(pmt_t v,
                                                         size_t& len); //< len is in elements
   PMT_API const std::complex<double>*
   c64vector_elements(pmt_t v, size_t& len); //< len is in elements
   
   // len is in elements
   PMT_API const std::vector<uint8_t> u8vector_elements(pmt_t v);
   PMT_API const std::vector<int8_t> s8vector_elements(pmt_t v);
   PMT_API const std::vector<uint16_t> u16vector_elements(pmt_t v);
   PMT_API const std::vector<int16_t> s16vector_elements(pmt_t v);
   PMT_API const std::vector<uint32_t> u32vector_elements(pmt_t v);
   PMT_API const std::vector<int32_t> s32vector_elements(pmt_t v);
   PMT_API const std::vector<uint64_t> u64vector_elements(pmt_t v);
   PMT_API const std::vector<int64_t> s64vector_elements(pmt_t v);
   PMT_API const std::vector<float> f32vector_elements(pmt_t v);
   PMT_API const std::vector<double> f64vector_elements(pmt_t v);
   PMT_API const std::vector<std::complex<float>> c32vector_elements(pmt_t v);
   PMT_API const std::vector<std::complex<double>> c64vector_elements(pmt_t v);
   
   // Return non-const pointers to the elements
   
   PMT_API void*
   uniform_vector_writable_elements(pmt_t v,
                                    size_t& len); //< works with any; len is in bytes
   
   PMT_API uint8_t* u8vector_writable_elements(pmt_t v, size_t& len); //< len is in elements
   PMT_API int8_t* s8vector_writable_elements(pmt_t v, size_t& len);  //< len is in elements
   PMT_API uint16_t* u16vector_writable_elements(pmt_t v,
                                                 size_t& len);         //< len is in elements
   PMT_API int16_t* s16vector_writable_elements(pmt_t v, size_t& len); //< len is in elements
   PMT_API uint32_t* u32vector_writable_elements(pmt_t v,
                                                 size_t& len);         //< len is in elements
   PMT_API int32_t* s32vector_writable_elements(pmt_t v, size_t& len); //< len is in elements
   PMT_API uint64_t* u64vector_writable_elements(pmt_t v,
                                                 size_t& len);         //< len is in elements
   PMT_API int64_t* s64vector_writable_elements(pmt_t v, size_t& len); //< len is in elements
   PMT_API float* f32vector_writable_elements(pmt_t v, size_t& len);   //< len is in elements
   PMT_API double* f64vector_writable_elements(pmt_t v, size_t& len);  //< len is in elements
   PMT_API std::complex<float>*
   c32vector_writable_elements(pmt_t v, size_t& len); //< len is in elements
   PMT_API std::complex<double>*
   c64vector_writable_elements(pmt_t v, size_t& len); //< len is in elements
   
   /*
    * ------------------------------------------------------------------------
    *     Dictionary (a.k.a associative array, hash, map)
    *
    * This is a functional data structure that is persistent.  Updating a
    * functional data structure does not destroy the existing version, but
    * rather creates a new version that coexists with the old.
    * ------------------------------------------------------------------------
    */
   
   PMT_API bool is_dict(const pmt_t& obj);
   
   PMT_API pmt_t dcons(const pmt_t& x, const pmt_t& y);
   
   PMT_API pmt_t make_dict();
   
   template <typename map_t>
   pmt_t dict_from_mapping(const map_t& prototype)
   {
       pmt_t protodict = make_dict();
       for (const auto& [key, value] : prototype) {
           protodict = dict_add(protodict, key, value);
       }
       return protodict;
   }
   
   PMT_API pmt_t dict_add(const pmt_t& dict, const pmt_t& key, const pmt_t& value);
   
   PMT_API pmt_t dict_delete(const pmt_t& dict, const pmt_t& key);
   
   PMT_API bool dict_has_key(const pmt_t& dict, const pmt_t& key);
   
   PMT_API pmt_t dict_ref(const pmt_t& dict, const pmt_t& key, const pmt_t& not_found);
   
   PMT_API pmt_t dict_items(pmt_t dict);
   
   PMT_API pmt_t dict_keys(pmt_t dict);
   
   PMT_API pmt_t dict_update(const pmt_t& dict1, const pmt_t& dict2);
   
   PMT_API pmt_t dict_values(pmt_t dict);
   
   /*
    * ------------------------------------------------------------------------
    *   Any (wraps std::any -- can be used to wrap pretty much anything)
    *
    * Cannot be serialized or used across process boundaries.
    * See http://www.boost.org/doc/html/any.html
    * ------------------------------------------------------------------------
    */
   
   PMT_API bool is_any(pmt_t obj);
   
   PMT_API pmt_t make_any(const std::any& any);
   
   PMT_API std::any any_ref(pmt_t obj);
   
   PMT_API void any_set(pmt_t obj, const std::any& any);
   
   
   /*
    * ------------------------------------------------------------------------
    *    msg_accepter -- pmt representation of pmt::msg_accepter
    * ------------------------------------------------------------------------
    */
   PMT_API bool is_msg_accepter(const pmt_t& obj);
   
   PMT_API pmt_t make_msg_accepter(std::shared_ptr<gr::messages::msg_accepter> ma);
   
   PMT_API std::shared_ptr<gr::messages::msg_accepter> msg_accepter_ref(const pmt_t& obj);
   
   /*
    * ------------------------------------------------------------------------
    *            General functions
    * ------------------------------------------------------------------------
    */
   
   PMT_API bool is_pdu(const pmt_t& obj);
   
   PMT_API bool eq(const pmt_t& x, const pmt_t& y);
   
   PMT_API bool eqv(const pmt_t& x, const pmt_t& y);
   
   PMT_API bool equal(const pmt_t& x, const pmt_t& y);
   
   
   PMT_API size_t length(const pmt_t& v);
   
   PMT_API pmt_t assq(pmt_t obj, pmt_t alist);
   
   PMT_API pmt_t assv(pmt_t obj, pmt_t alist);
   
   PMT_API pmt_t assoc(pmt_t obj, pmt_t alist);
   
   PMT_API pmt_t map(pmt_t proc(const pmt_t&), pmt_t list);
   
   PMT_API pmt_t reverse(pmt_t list);
   
   PMT_API pmt_t reverse_x(pmt_t list);
   
   inline static pmt_t acons(pmt_t x, pmt_t y, pmt_t a) { return dcons(cons(x, y), a); }
   
   PMT_API pmt_t nth(size_t n, pmt_t list);
   
   PMT_API pmt_t nthcdr(size_t n, pmt_t list);
   
   PMT_API pmt_t memq(pmt_t obj, pmt_t list);
   
   PMT_API pmt_t memv(pmt_t obj, pmt_t list);
   
   PMT_API pmt_t member(pmt_t obj, pmt_t list);
   
   PMT_API bool subsetp(pmt_t list1, pmt_t list2);
   
   PMT_API pmt_t list1(const pmt_t& x1);
   
   PMT_API pmt_t list2(const pmt_t& x1, const pmt_t& x2);
   
   PMT_API pmt_t list3(const pmt_t& x1, const pmt_t& x2, const pmt_t& x3);
   
   PMT_API pmt_t list4(const pmt_t& x1, const pmt_t& x2, const pmt_t& x3, const pmt_t& x4);
   
   PMT_API pmt_t list5(
       const pmt_t& x1, const pmt_t& x2, const pmt_t& x3, const pmt_t& x4, const pmt_t& x5);
   
   PMT_API pmt_t list6(const pmt_t& x1,
                       const pmt_t& x2,
                       const pmt_t& x3,
                       const pmt_t& x4,
                       const pmt_t& x5,
                       const pmt_t& x6);
   
   PMT_API pmt_t list_add(pmt_t list, const pmt_t& item);
   
   PMT_API pmt_t list_rm(pmt_t list, const pmt_t& item);
   
   PMT_API bool list_has(pmt_t list, const pmt_t& item);
   
   
   /*
    * ------------------------------------------------------------------------
    *               read / write
    * ------------------------------------------------------------------------
    */
   
   PMT_API bool is_eof_object(pmt_t obj);
   
   PMT_API pmt_t read(std::istream& port);
   
   PMT_API void write(pmt_t obj, std::ostream& port);
   
   PMT_API std::string write_string(pmt_t obj);
   
   
   PMT_API std::ostream& operator<<(std::ostream& os, pmt_t obj);
   
   PMT_API void print(pmt_t v);
   
   
   /*
    * ------------------------------------------------------------------------
    *            portable byte stream representation
    * ------------------------------------------------------------------------
    */
   PMT_API bool serialize(pmt_t obj, std::streambuf& sink);
   
   PMT_API pmt_t deserialize(std::streambuf& source);
   
   
   PMT_API void dump_sizeof(); // debugging
   
   PMT_API std::string serialize_str(pmt_t obj);
   
   PMT_API pmt_t deserialize_str(std::string str);
   
   class comparator
   {
   public:
       bool operator()(pmt::pmt_t const& p1, pmt::pmt_t const& p2) const
       {
           return pmt::eqv(p1, p2) ? false : p1.get() > p2.get();
       }
   };
   
   } /* namespace pmt */
   
   #include <pmt/pmt_sugar.h>
   
   #endif /* INCLUDED_PMT_H */
