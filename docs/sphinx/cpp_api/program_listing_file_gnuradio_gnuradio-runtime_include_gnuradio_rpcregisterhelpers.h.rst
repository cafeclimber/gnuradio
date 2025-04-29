
.. _program_listing_file_gnuradio_gnuradio-runtime_include_gnuradio_rpcregisterhelpers.h:

Program Listing for File rpcregisterhelpers.h
=============================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_include_gnuradio_rpcregisterhelpers.h>` (``gnuradio/gnuradio-runtime/include/gnuradio/rpcregisterhelpers.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2012,2014 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef RPCREGISTERHELPERS_H
   #define RPCREGISTERHELPERS_H
   
   #include <gnuradio/rpcmanager.h>
   #include <gnuradio/rpcserver_base.h>
   #include <gnuradio/rpcserver_booter_base.h>
   #include <gnuradio/rpcserver_selector.h>
   #include <sstream>
   
   // Fixes circular dependency issue before including block_registry.h
   class rpcbasic_base;
   typedef std::shared_ptr<rpcbasic_base> rpcbasic_sptr;
   
   #include <gnuradio/block_registry.h>
   
   
   /*********************************************************************
    *   RPC Extractor Base Classes
    ********************************************************************/
   
   template <typename T, typename Tto>
   class rpcextractor_base : public virtual gr::messages::msg_accepter
   {
   public:
       rpcextractor_base(T* source, void (T::*func)(Tto)) : _source(source), _func(func)
       {
           ;
       }
       ~rpcextractor_base() override { ; }
   
       void post(pmt::pmt_t which_port, pmt::pmt_t msg) override
       {
           (void)which_port;
           (void)msg;
           throw std::runtime_error(
               "rpcextractor_base: no post defined for this data type.");
       }
   
   protected:
       T* _source;
       void (T::*_func)(Tto);
   };
   
   template <typename T>
   class rpcextractor_base<T, void> : public virtual gr::messages::msg_accepter
   {
   public:
       rpcextractor_base(T* source, void (T::*func)()) : _source(source), _func(func) { ; }
       ~rpcextractor_base() override { ; }
   
       void post(pmt::pmt_t which_port, pmt::pmt_t msg) override
       {
           (void)which_port;
           (void)msg;
           throw std::runtime_error(
               "rpcextractor_base: no post defined for this data type.");
       }
   
   protected:
       T* _source;
       void (T::*_func)();
   };
   
   template <typename T, typename Tto>
   class rpcbasic_extractor : public virtual rpcextractor_base<T, Tto>
   {
   public:
       rpcbasic_extractor(T* source, void (T::*func)(Tto))
           : rpcextractor_base<T, Tto>(source, func)
       {
           ;
       }
   };
   
   
   /*********************************************************************
    *   RPC Inserter Base Classes
    ********************************************************************/
   
   template <typename T, typename Tfrom>
   class rpcinserter_base : public virtual gr::messages::msg_producer
   {
   public:
       rpcinserter_base(T* source, Tfrom (T::*func)()) : _source(source), _func(func) { ; }
       rpcinserter_base() { ; }
   
       pmt::pmt_t retrieve() override
       {
           assert(0);
           return pmt::pmt_t();
       }
   
   protected:
       T* _source;
       Tfrom (T::*_func)();
   };
   
   
   template <typename T, typename Tfrom>
   class rpcbasic_inserter : public virtual rpcinserter_base<T, Tfrom>
   {
   public:
       rpcbasic_inserter(T* source, Tfrom (T::*func)() const)
           : rpcinserter_base<T, Tfrom>(source, func)
       {
           ;
       }
   
       rpcbasic_inserter(T* source, Tfrom (T::*func)())
           : rpcinserter_base<T, Tfrom>(source, func)
       {
           ;
       }
   
       pmt::pmt_t retrieve()
       {
           return pmt::mp(
               (rpcinserter_base<T, Tfrom>::_source->*rpcinserter_base<T, Tfrom>::_func)());
       }
   };
   
   
   /*********************************************************************
    *   RPC Handler Base Classes
    ********************************************************************/
   
   template <typename T>
   class rpchandler_base : public virtual gr::messages::msg_accepter
   {
   public:
       rpchandler_base(T* source, const char* handler) : _source(source), _handler(handler)
       {
           ;
       }
       ~rpchandler_base() override { ; }
   
       void post(pmt::pmt_t which_port, pmt::pmt_t msg) override
       {
           _source->post(which_port, msg);
       }
   
   protected:
       T* _source;
       const char* _handler;
   };
   
   
   template <typename T>
   class rpcbasic_handler : public virtual rpchandler_base<T>
   {
   public:
       rpcbasic_handler(T* source, const char* handler) : rpchandler_base<T>(source, handler)
       {
           ;
       }
   };
   
   
   /*********************************************************************
    *   RPC Specialized Extractors
    ********************************************************************/
   
   template <typename T>
   class rpcbasic_extractor<T, void> : public virtual rpcextractor_base<T, void>
   {
   public:
       rpcbasic_extractor(T* source, void (T::*func)())
           : rpcextractor_base<T, void>(source, func)
       {
           ;
       }
   
       void post(pmt::pmt_t which_port, pmt::pmt_t msg)
       {
           (void)which_port;
           (void)msg;
           (rpcextractor_base<T, void>::_source->*rpcextractor_base<T, void>::_func)();
       }
   };
   
   template <typename T>
   class rpcbasic_extractor<T, char> : public virtual rpcextractor_base<T, char>
   {
   public:
       rpcbasic_extractor(T* source, void (T::*func)(char))
           : rpcextractor_base<T, char>(source, func)
       {
           ;
       }
   
       void post(pmt::pmt_t which_port, pmt::pmt_t msg)
       {
           (void)which_port;
           (rpcextractor_base<T, char>::_source->*rpcextractor_base<T, char>::_func)(
               static_cast<char>(pmt::to_long(msg)));
       }
   };
   
   template <typename T>
   class rpcbasic_extractor<T, short> : public virtual rpcextractor_base<T, short>
   {
   public:
       rpcbasic_extractor(T* source, void (T::*func)(short))
           : rpcextractor_base<T, short>(source, func)
       {
           ;
       }
   
       void post(pmt::pmt_t which_port, pmt::pmt_t msg)
       {
           (void)which_port;
           (rpcextractor_base<T, short>::_source->*rpcextractor_base<T, short>::_func)(
               static_cast<short>(pmt::to_long(msg)));
       }
   };
   
   template <typename T>
   class rpcbasic_extractor<T, double> : public virtual rpcextractor_base<T, double>
   {
   public:
       rpcbasic_extractor(T* source, void (T::*func)(double))
           : rpcextractor_base<T, double>(source, func)
       {
           ;
       }
   
       void post(pmt::pmt_t which_port, pmt::pmt_t msg)
       {
           (void)which_port;
           (rpcextractor_base<T, double>::_source->*rpcextractor_base<T, double>::_func)(
               pmt::to_double(msg));
       }
   };
   
   template <typename T>
   class rpcbasic_extractor<T, float> : public virtual rpcextractor_base<T, float>
   {
   public:
       rpcbasic_extractor(T* source, void (T::*func)(float))
           : rpcextractor_base<T, float>(source, func)
       {
           ;
       }
   
       void post(pmt::pmt_t which_port, pmt::pmt_t msg)
       {
           (void)which_port;
           (rpcextractor_base<T, float>::_source->*rpcextractor_base<T, float>::_func)(
               pmt::to_double(msg));
       }
   };
   
   template <typename T>
   class rpcbasic_extractor<T, long> : public virtual rpcextractor_base<T, long>
   {
   public:
       rpcbasic_extractor(T* source, void (T::*func)(long))
           : rpcextractor_base<T, long>(source, func)
       {
           ;
       }
   
       void post(pmt::pmt_t which_port, pmt::pmt_t msg)
       {
           (void)which_port;
           (rpcextractor_base<T, long>::_source->*rpcextractor_base<T, long>::_func)(
               pmt::to_long(msg));
       }
   };
   
   template <typename T>
   class rpcbasic_extractor<T, int> : public virtual rpcextractor_base<T, int>
   {
   public:
       rpcbasic_extractor(T* source, void (T::*func)(int))
           : rpcextractor_base<T, int>(source, func)
       {
           ;
       }
   
       void post(pmt::pmt_t which_port, pmt::pmt_t msg)
       {
           (void)which_port;
           (rpcextractor_base<T, int>::_source->*rpcextractor_base<T, int>::_func)(
               pmt::to_long(msg));
       }
   };
   
   template <typename T>
   class rpcbasic_extractor<T, bool> : public virtual rpcextractor_base<T, bool>
   {
   public:
       rpcbasic_extractor(T* source, void (T::*func)(bool))
           : rpcextractor_base<T, bool>(source, func)
       {
           ;
       }
   
       void post(pmt::pmt_t which_port, pmt::pmt_t msg)
       {
           (void)which_port;
           (rpcextractor_base<T, bool>::_source->*rpcextractor_base<T, bool>::_func)(
               pmt::to_bool(msg));
       }
   };
   
   template <typename T>
   class rpcbasic_extractor<T, std::complex<float>>
       : public virtual rpcextractor_base<T, std::complex<float>>
   {
   public:
       rpcbasic_extractor(T* source, void (T::*func)(std::complex<float>))
           : rpcextractor_base<T, std::complex<float>>(source, func)
       {
           ;
       }
   
       void post(pmt::pmt_t which_port, pmt::pmt_t msg)
       {
           (void)which_port;
           std::complex<float> k = static_cast<std::complex<float>>(pmt::to_complex(msg));
           (rpcextractor_base<T, std::complex<float>>::_source
                ->*rpcextractor_base<T, std::complex<float>>::_func)(k);
       }
   };
   
   template <typename T>
   class rpcbasic_extractor<T, std::complex<double>>
       : public virtual rpcextractor_base<T, std::complex<double>>
   {
   public:
       rpcbasic_extractor(T* source, void (T::*func)(std::complex<double>))
           : rpcextractor_base<T, std::complex<double>>(source, func)
       {
           ;
       }
   
       void post(pmt::pmt_t which_port, pmt::pmt_t msg)
       {
           (void)which_port;
           (rpcextractor_base<T, std::complex<double>>::_source
                ->*rpcextractor_base<T, std::complex<double>>::_func)(pmt::to_complex(msg));
       }
   };
   
   template <typename T>
   class rpcbasic_extractor<T, std::string>
       : public virtual rpcextractor_base<T, std::string>
   {
   public:
       rpcbasic_extractor(T* source, void (T::*func)(std::string))
           : rpcextractor_base<T, std::string>(source, func)
       {
           ;
       }
   
       void post(pmt::pmt_t which_port, pmt::pmt_t msg)
       {
           (void)which_port;
           (rpcextractor_base<T, std::string>::_source
                ->*rpcextractor_base<T, std::string>::_func)(pmt::symbol_to_string(msg));
       }
   };
   
   
   /*********************************************************************
    *   RPC Specialized Inserters
    ********************************************************************/
   
   template <typename T>
   class rpcbasic_inserter<T, uint64_t> : public virtual rpcinserter_base<T, uint64_t>
   {
   public:
       rpcbasic_inserter(T* source, uint64_t (T::*func)() const)
           : rpcinserter_base<T, uint64_t>(source, func)
       {
           ;
       }
   
       rpcbasic_inserter(T* source, uint64_t (T::*func)())
           : rpcinserter_base<T, uint64_t>(source, func)
       {
           ;
       }
   
       pmt::pmt_t retrieve()
       {
           return pmt::from_uint64((rpcinserter_base<T, uint64_t>::_source
                                        ->*rpcinserter_base<T, uint64_t>::_func)());
       }
   };
   
   template <typename T>
   class rpcbasic_inserter<T, std::vector<signed char>>
       : public virtual rpcinserter_base<T, std::vector<signed char>>
   {
   public:
       rpcbasic_inserter(T* source, std::vector<signed char> (T::*func)() const)
           : rpcinserter_base<T, std::vector<signed char>>(source, func)
       {
           ;
       }
   
       rpcbasic_inserter(T* source, std::vector<signed char> (T::*func)())
           : rpcinserter_base<T, std::vector<signed char>>(source, func)
       {
           ;
       }
   
       pmt::pmt_t retrieve()
       {
           std::vector<signed char> vec(
               (rpcinserter_base<T, std::vector<signed char>>::_source
                    ->*rpcinserter_base<T, std::vector<signed char>>::_func)());
           return pmt::init_s8vector(vec.size(), &vec[0]);
       }
   };
   
   template <typename T>
   class rpcbasic_inserter<T, std::vector<short>>
       : public virtual rpcinserter_base<T, std::vector<short>>
   {
   public:
       rpcbasic_inserter(T* source, std::vector<short> (T::*func)() const)
           : rpcinserter_base<T, std::vector<short>>(source, func)
       {
           ;
       }
   
       rpcbasic_inserter(T* source, std::vector<short> (T::*func)())
           : rpcinserter_base<T, std::vector<short>>(source, func)
       {
           ;
       }
   
       pmt::pmt_t retrieve()
       {
           std::vector<short> vec((rpcinserter_base<T, std::vector<short>>::_source
                                       ->*rpcinserter_base<T, std::vector<short>>::_func)());
           return pmt::init_s16vector(vec.size(), &vec[0]);
       }
   };
   
   template <typename T>
   class rpcbasic_inserter<T, std::vector<int>>
       : public virtual rpcinserter_base<T, std::vector<int>>
   {
   public:
       rpcbasic_inserter(T* source, std::vector<int> (T::*func)() const)
           : rpcinserter_base<T, std::vector<int>>(source, func)
       {
           ;
       }
   
       rpcbasic_inserter(T* source, std::vector<int> (T::*func)())
           : rpcinserter_base<T, std::vector<int>>(source, func)
       {
           ;
       }
   
       pmt::pmt_t retrieve()
       {
           std::vector<int> vec((rpcinserter_base<T, std::vector<int>>::_source
                                     ->*rpcinserter_base<T, std::vector<int>>::_func)());
           return pmt::init_s32vector(vec.size(), &vec[0]);
       }
   };
   
   template <typename T>
   class rpcbasic_inserter<T, std::vector<int64_t>>
       : public virtual rpcinserter_base<T, std::vector<int64_t>>
   {
   public:
       rpcbasic_inserter(T* source, std::vector<int64_t> (T::*func)() const)
           : rpcinserter_base<T, std::vector<int64_t>>(source, func)
       {
           ;
       }
   
       rpcbasic_inserter(T* source, std::vector<int64_t> (T::*func)())
           : rpcinserter_base<T, std::vector<int64_t>>(source, func)
       {
           ;
       }
   
       pmt::pmt_t retrieve()
       {
           std::vector<int64_t> vec(
               (rpcinserter_base<T, std::vector<int64_t>>::_source
                    ->*rpcinserter_base<T, std::vector<int64_t>>::_func)());
           return pmt::init_s64vector(vec.size(), &vec[0]);
       }
   };
   
   template <typename T>
   class rpcbasic_inserter<T, std::vector<std::complex<float>>>
       : public virtual rpcinserter_base<T, std::vector<std::complex<float>>>
   {
   public:
       rpcbasic_inserter(T* source, std::vector<std::complex<float>> (T::*func)() const)
           : rpcinserter_base<T, std::vector<std::complex<float>>>(source, func)
       {
           ;
       }
   
       rpcbasic_inserter(T* source, std::vector<std::complex<float>> (T::*func)())
           : rpcinserter_base<T, std::vector<std::complex<float>>>(source, func)
       {
           ;
       }
   
       pmt::pmt_t retrieve()
       {
           std::vector<std::complex<float>> vec(
               (rpcinserter_base<T, std::vector<std::complex<float>>>::_source
                    ->*rpcinserter_base<T, std::vector<std::complex<float>>>::_func)());
           return pmt::init_c32vector(vec.size(), &vec[0]);
       }
   };
   
   template <typename T>
   class rpcbasic_inserter<T, std::vector<float>>
       : public virtual rpcinserter_base<T, std::vector<float>>
   {
   public:
       rpcbasic_inserter(T* source, std::vector<float> (T::*func)() const)
           : rpcinserter_base<T, std::vector<float>>(source, func)
       {
           ;
       }
   
       rpcbasic_inserter(T* source, std::vector<float> (T::*func)())
           : rpcinserter_base<T, std::vector<float>>(source, func)
       {
           ;
       }
   
       pmt::pmt_t retrieve()
       {
           std::vector<float> vec((rpcinserter_base<T, std::vector<float>>::_source
                                       ->*rpcinserter_base<T, std::vector<float>>::_func)());
           return pmt::init_f32vector(vec.size(), &vec[0]);
       }
   };
   
   template <typename T>
   class rpcbasic_inserter<T, std::vector<uint8_t>>
       : public virtual rpcinserter_base<T, std::vector<uint8_t>>
   {
   public:
       rpcbasic_inserter(T* source, std::vector<uint8_t> (T::*func)() const)
           : rpcinserter_base<T, std::vector<uint8_t>>(source, func)
       {
           ;
       }
   
       rpcbasic_inserter(T* source, std::vector<uint8_t> (T::*func)())
           : rpcinserter_base<T, std::vector<uint8_t>>(source, func)
       {
           ;
       }
   
       pmt::pmt_t retrieve()
       {
           std::vector<uint8_t> vec(
               (rpcinserter_base<T, std::vector<uint8_t>>::_source
                    ->*rpcinserter_base<T, std::vector<uint8_t>>::_func)());
           return pmt::init_u8vector(vec.size(), &vec[0]);
       }
   };
   
   template <typename T>
   class rpcbasic_inserter<T, std::complex<float>>
       : public virtual rpcinserter_base<T, std::complex<float>>
   {
   public:
       rpcbasic_inserter(T* source, std::complex<float> (T::*func)() const)
           : rpcinserter_base<T, std::complex<float>>(source, func)
       {
           ;
       }
   
       rpcbasic_inserter(T* source, std::complex<float> (T::*func)())
           : rpcinserter_base<T, std::complex<float>>(source, func)
       {
           ;
       }
   
       pmt::pmt_t retrieve()
       {
           std::complex<float> k((rpcinserter_base<T, std::complex<float>>::_source
                                      ->*rpcinserter_base<T, std::complex<float>>::_func)());
           return pmt::from_complex(k);
       }
   };
   
   template <typename T>
   class rpcbasic_inserter<T, std::complex<double>>
       : public virtual rpcinserter_base<T, std::complex<double>>
   {
   public:
       rpcbasic_inserter(T* source, std::complex<double> (T::*func)() const)
           : rpcinserter_base<T, std::complex<double>>(source, func)
       {
           ;
       }
   
       rpcbasic_inserter(T* source, std::complex<double> (T::*func)())
           : rpcinserter_base<T, std::complex<double>>(source, func)
       {
           ;
       }
   
       pmt::pmt_t retrieve()
       {
           std::complex<double> k(
               (rpcinserter_base<T, std::complex<double>>::_source
                    ->*rpcinserter_base<T, std::complex<double>>::_func)());
           return pmt::from_complex(k);
       }
   };
   
   template <typename T>
   struct rpc_register_base {
       rpc_register_base() { count++; }
   
   protected:
       static int count;
   };
   
   class rpcbasic_base
   {
   public:
       rpcbasic_base() {}
       virtual ~rpcbasic_base(){};
   };
   
   
   /*********************************************************************
    *   RPC Register Set Classes
    ********************************************************************/
   
   template <typename T, typename Tto>
   struct rpcbasic_register_set : public rpcbasic_base {
       rpcbasic_register_set(const std::string& block_alias,
                             [[maybe_unused]] const char* functionbase,
                             [[maybe_unused]] void (T::*function)(Tto),
                             const pmt::pmt_t& min,
                             const pmt::pmt_t& max,
                             const pmt::pmt_t& def,
                             const char* units_ = "",
                             const char* desc_ = "",
                             priv_lvl_t minpriv_ = RPC_PRIVLVL_MIN,
                             DisplayType display_ = DISPNULL)
       {
           d_min = min;
           d_max = max;
           d_def = def;
           d_units = units_;
           d_desc = desc_;
           d_minpriv = minpriv_;
           d_display = display_;
           d_object = dynamic_cast<T*>(
               global_block_registry.block_lookup(pmt::intern(block_alias)).get());
   #ifdef GR_RPCSERVER_ENABLED
           callbackregister_base::configureCallback_t extractor(
               new rpcbasic_extractor<T, Tto>(d_object, function),
               minpriv_,
               std::string(units_),
               display_,
               std::string(desc_),
               min,
               max,
               def);
           std::ostringstream oss(std::ostringstream::out);
           oss << block_alias << "::" << functionbase;
           d_id = oss.str();
           // std::cerr << "REGISTERING SET: " << d_id << "  " << desc_ << std::endl;
           rpcmanager::get()->i()->registerConfigureCallback(d_id, extractor);
   #endif
       }
   
       rpcbasic_register_set([[maybe_unused]] const std::string& name,
                             [[maybe_unused]] const char* functionbase,
                             T* obj,
                             [[maybe_unused]] void (T::*function)(Tto),
                             const pmt::pmt_t& min,
                             const pmt::pmt_t& max,
                             const pmt::pmt_t& def,
                             const char* units_ = "",
                             const char* desc_ = "",
                             priv_lvl_t minpriv_ = RPC_PRIVLVL_MIN,
                             DisplayType display_ = DISPNULL)
       {
           d_min = min;
           d_max = max;
           d_def = def;
           d_units = units_;
           d_desc = desc_;
           d_minpriv = minpriv_;
           d_display = display_;
           d_object = obj;
   #ifdef GR_RPCSERVER_ENABLED
           callbackregister_base::configureCallback_t extractor(
               new rpcbasic_extractor<T, Tto>(d_object, function),
               minpriv_,
               std::string(units_),
               display_,
               std::string(desc_),
               min,
               max,
               def);
           std::ostringstream oss(std::ostringstream::out);
           oss << name << "::" << functionbase;
           d_id = oss.str();
           // std::cerr << "REGISTERING SET: " << d_id << "  " << desc_ << std::endl;
           rpcmanager::get()->i()->registerConfigureCallback(d_id, extractor);
   #endif
       }
   
       ~rpcbasic_register_set() override
       {
   #ifdef GR_RPCSERVER_ENABLED
           rpcmanager::get()->i()->unregisterConfigureCallback(d_id);
   #endif
       }
   
   
       pmt::pmt_t min() const { return d_min; }
       pmt::pmt_t max() const { return d_max; }
       pmt::pmt_t def() const { return d_def; }
       std::string units() const { return d_units; }
       std::string description() const { return d_desc; }
       priv_lvl_t privilege_level() const { return d_minpriv; }
       DisplayType default_display() const { return d_display; }
   
       void set_min(pmt::pmt_t p) { d_min = p; }
       void set_max(pmt::pmt_t p) { d_max = p; }
       void set_def(pmt::pmt_t p) { d_def = p; }
       void units(std::string u) { d_units = u; }
       void description(std::string d) { d_desc = d; }
       void privilege_level(priv_lvl_t p) { d_minpriv = p; }
       void default_display(DisplayType d) { d_display = d; }
   
   private:
       std::string d_id;
       pmt::pmt_t d_min, d_max, d_def;
       std::string d_units, d_desc;
       priv_lvl_t d_minpriv;
       DisplayType d_display;
       T* d_object;
   };
   
   
   /*********************************************************************
    *   RPC Register Trigger Classes
    ********************************************************************/
   
   template <typename T>
   struct rpcbasic_register_trigger : public rpcbasic_base {
       rpcbasic_register_trigger(const std::string& block_alias,
                                 [[maybe_unused]] const char* functionbase,
                                 [[maybe_unused]] void (T::*function)(),
                                 const char* desc_ = "",
                                 priv_lvl_t minpriv_ = RPC_PRIVLVL_MIN)
       {
           d_desc = desc_;
           d_minpriv = minpriv_;
           d_object = dynamic_cast<T*>(
               global_block_registry.block_lookup(pmt::intern(block_alias)).get());
   #ifdef GR_RPCSERVER_ENABLED
           callbackregister_base::configureCallback_t extractor(
               new rpcbasic_extractor<T, void>(d_object, function),
               minpriv_,
               std::string(desc_));
           std::ostringstream oss(std::ostringstream::out);
           oss << block_alias << "::" << functionbase;
           d_id = oss.str();
           // std::cerr << "REGISTERING TRIGGER: " << d_id << "  " << desc_ << std::endl;
           rpcmanager::get()->i()->registerConfigureCallback(d_id, extractor);
   #endif
       }
   
       rpcbasic_register_trigger([[maybe_unused]] const std::string& name,
                                 [[maybe_unused]] const char* functionbase,
                                 T* obj,
                                 [[maybe_unused]] void (T::*function)(),
                                 const char* desc_ = "",
                                 priv_lvl_t minpriv_ = RPC_PRIVLVL_MIN)
       {
           d_desc = desc_;
           d_minpriv = minpriv_;
           d_object = obj;
   #ifdef GR_RPCSERVER_ENABLED
           callbackregister_base::configureCallback_t extractor(
               new rpcbasic_extractor<T, void>(d_object, function),
               minpriv_,
               std::string(desc_));
           std::ostringstream oss(std::ostringstream::out);
           oss << name << "::" << functionbase;
           d_id = oss.str();
           // std::cerr << "REGISTERING TRIGGER: " << d_id << "  " << desc_ << std::endl;
           rpcmanager::get()->i()->registerConfigureCallback(d_id, extractor);
   #endif
       }
   
       ~rpcbasic_register_trigger() override
       {
   #ifdef GR_RPCSERVER_ENABLED
           rpcmanager::get()->i()->unregisterConfigureCallback(d_id);
   #endif
       }
   
   
       std::string description() const { return d_desc; }
       priv_lvl_t privilege_level() const { return d_minpriv; }
   
       void description(std::string d) { d_desc = d; }
       void privilege_level(priv_lvl_t p) { d_minpriv = p; }
   
   private:
       std::string d_id;
       std::string d_desc;
       priv_lvl_t d_minpriv;
       T* d_object;
   };
   
   
   /*********************************************************************
    *   RPC Register Get Classes
    ********************************************************************/
   
   template <typename T, typename Tfrom>
   class rpcbasic_register_get : public rpcbasic_base
   {
   public:
       rpcbasic_register_get(const std::string& block_alias,
                             [[maybe_unused]] const char* functionbase,
                             [[maybe_unused]] Tfrom (T::*function)(),
                             const pmt::pmt_t& min,
                             const pmt::pmt_t& max,
                             const pmt::pmt_t& def,
                             const char* units_ = "",
                             const char* desc_ = "",
                             priv_lvl_t minpriv_ = RPC_PRIVLVL_MIN,
                             DisplayType display_ = DISPNULL)
       {
           d_min = min;
           d_max = max;
           d_def = def;
           d_units = units_;
           d_desc = desc_;
           d_minpriv = minpriv_;
           d_display = display_;
           d_object = dynamic_cast<T*>(
               global_block_registry.block_lookup(pmt::intern(block_alias)).get());
   #ifdef GR_RPCSERVER_ENABLED
           callbackregister_base::queryCallback_t inserter(
               new rpcbasic_inserter<T, Tfrom>(d_object, function),
               minpriv_,
               std::string(units_),
               display_,
               std::string(desc_),
               min,
               max,
               def);
           std::ostringstream oss(std::ostringstream::out);
           oss << block_alias << "::" << functionbase;
           d_id = oss.str();
           // std::cerr << "REGISTERING GET: " << d_id << "  " << desc_ << std::endl;
           rpcmanager::get()->i()->registerQueryCallback(d_id, inserter);
   #endif
       }
   
   
       rpcbasic_register_get(const std::string& block_alias,
                             [[maybe_unused]] const char* functionbase,
                             [[maybe_unused]] Tfrom (T::*function)() const,
                             const pmt::pmt_t& min,
                             const pmt::pmt_t& max,
                             const pmt::pmt_t& def,
                             const char* units_ = "",
                             const char* desc_ = "",
                             priv_lvl_t minpriv_ = RPC_PRIVLVL_MIN,
                             DisplayType display_ = DISPNULL)
       {
           d_min = min;
           d_max = max;
           d_def = def;
           d_units = units_;
           d_desc = desc_;
           d_minpriv = minpriv_;
           d_display = display_;
           d_object = dynamic_cast<T*>(
               global_block_registry.block_lookup(pmt::intern(block_alias)).get());
   #ifdef GR_RPCSERVER_ENABLED
           callbackregister_base::queryCallback_t inserter(
               new rpcbasic_inserter<T, Tfrom>(d_object, (Tfrom(T::*)())function),
               minpriv_,
               std::string(units_),
               display_,
               std::string(desc_),
               min,
               max,
               def);
           std::ostringstream oss(std::ostringstream::out);
           oss << block_alias << "::" << functionbase;
           d_id = oss.str();
           // std::cerr << "REGISTERING GET CONST: " << d_id << "   " << desc_ << "   " <<
           // display_ << std::endl;
           rpcmanager::get()->i()->registerQueryCallback(d_id, inserter);
   #endif
       }
   
   
       rpcbasic_register_get([[maybe_unused]] const std::string& name,
                             [[maybe_unused]] const char* functionbase,
                             T* obj,
                             [[maybe_unused]] Tfrom (T::*function)(),
                             const pmt::pmt_t& min,
                             const pmt::pmt_t& max,
                             const pmt::pmt_t& def,
                             const char* units_ = "",
                             const char* desc_ = "",
                             priv_lvl_t minpriv_ = RPC_PRIVLVL_MIN,
                             DisplayType display_ = DISPNULL)
       {
           d_min = min;
           d_max = max;
           d_def = def;
           d_units = units_;
           d_desc = desc_;
           d_minpriv = minpriv_;
           d_display = display_;
           d_object = obj;
   #ifdef GR_RPCSERVER_ENABLED
           callbackregister_base::queryCallback_t inserter(
               new rpcbasic_inserter<T, Tfrom>(d_object, function),
               minpriv_,
               std::string(units_),
               display_,
               std::string(desc_),
               min,
               max,
               def);
           std::ostringstream oss(std::ostringstream::out);
           oss << name << "::" << functionbase;
           d_id = oss.str();
           // std::cerr << "REGISTERING GET: " << d_id << "  " << desc_ << std::endl;
           rpcmanager::get()->i()->registerQueryCallback(d_id, inserter);
   #endif
       }
   
   
       rpcbasic_register_get([[maybe_unused]] const std::string& name,
                             [[maybe_unused]] const char* functionbase,
                             T* obj,
                             [[maybe_unused]] Tfrom (T::*function)() const,
                             const pmt::pmt_t& min,
                             const pmt::pmt_t& max,
                             const pmt::pmt_t& def,
                             const char* units_ = "",
                             const char* desc_ = "",
                             priv_lvl_t minpriv_ = RPC_PRIVLVL_MIN,
                             DisplayType display_ = DISPNULL)
       {
           d_min = min;
           d_max = max;
           d_def = def;
           d_units = units_;
           d_desc = desc_;
           d_minpriv = minpriv_;
           d_display = display_;
           d_object = obj;
   #ifdef GR_RPCSERVER_ENABLED
           callbackregister_base::queryCallback_t inserter(
               new rpcbasic_inserter<T, Tfrom>(d_object, (Tfrom(T::*)())function),
               minpriv_,
               std::string(units_),
               display_,
               std::string(desc_),
               min,
               max,
               def);
           std::ostringstream oss(std::ostringstream::out);
           oss << name << "::" << functionbase;
           d_id = oss.str();
           // std::cerr << "REGISTERING GET CONST: " << d_id << "   " << desc_ << "   " <<
           // display_ << std::endl;
           rpcmanager::get()->i()->registerQueryCallback(d_id, inserter);
   #endif
       }
   
       ~rpcbasic_register_get() override
       {
   #ifdef GR_RPCSERVER_ENABLED
           rpcmanager::get()->i()->unregisterQueryCallback(d_id);
   #endif
       }
   
       pmt::pmt_t min() const { return d_min; }
       pmt::pmt_t max() const { return d_max; }
       pmt::pmt_t def() const { return d_def; }
       std::string units() const { return d_units; }
       std::string description() const { return d_desc; }
       priv_lvl_t privilege_level() const { return d_minpriv; }
       DisplayType default_display() const { return d_display; }
   
       void set_min(pmt::pmt_t p) { d_min = p; }
       void set_max(pmt::pmt_t p) { d_max = p; }
       void set_def(pmt::pmt_t p) { d_def = p; }
       void units(std::string u) { d_units = u; }
       void description(std::string d) { d_desc = d; }
       void privilege_level(priv_lvl_t p) { d_minpriv = p; }
       void default_display(DisplayType d) { d_display = d; }
   
   private:
       std::string d_id;
       pmt::pmt_t d_min, d_max, d_def;
       std::string d_units, d_desc;
       priv_lvl_t d_minpriv;
       DisplayType d_display;
       T* d_object;
   };
   
   
   /*********************************************************************
    *   RPC Register Variable Classes
    ********************************************************************/
   
   template <typename Tfrom>
   class rpcbasic_register_variable : public rpcbasic_base
   {
   protected:
       rpcbasic_register_get<rpcbasic_register_variable<Tfrom>, Tfrom> d_rpc_reg;
       Tfrom* d_variable;
       Tfrom get() { return *d_variable; }
   
   public:
       void setptr(Tfrom* _variable)
       {
           rpcbasic_register_variable<Tfrom>::d_variable = _variable;
       }
   
       rpcbasic_register_variable()
           : d_rpc_reg("FAIL",
                       "FAIL",
                       this,
                       &rpcbasic_register_variable::get,
                       pmt::PMT_NIL,
                       pmt::PMT_NIL,
                       pmt::PMT_NIL,
                       DISPNULL,
                       "FAIL",
                       "FAIL",
                       RPC_PRIVLVL_MIN),
             d_variable(NULL)
       {
           throw std::runtime_error(
               "ERROR: rpcbasic_register_variable called with no args. If this happens, "
               "someone has tried to use rpcbasic_register_variable incorrectly.");
       };
   
       rpcbasic_register_variable(const std::string& namebase,
                                  const char* functionbase,
                                  Tfrom* variable,
                                  const pmt::pmt_t& min,
                                  const pmt::pmt_t& max,
                                  const pmt::pmt_t& def,
                                  const char* units_ = "",
                                  const char* desc_ = "",
                                  priv_lvl_t minpriv_ = RPC_PRIVLVL_MIN,
                                  DisplayType display_ = DISPNULL)
           : d_rpc_reg(namebase,
                       functionbase,
                       this,
                       &rpcbasic_register_variable::get,
                       min,
                       max,
                       def,
                       units_,
                       desc_,
                       minpriv_,
                       display_),
             d_variable(variable)
       {
           // std::cerr << "REGISTERING VAR: " << " " << desc_ << std::endl;
       }
   };
   
   
   template <typename Tfrom>
   class rpcbasic_register_variable_rw : public rpcbasic_register_variable<Tfrom>
   {
   private:
       rpcbasic_register_set<rpcbasic_register_variable_rw<Tfrom>, Tfrom> d_rpc_regset;
   
   public:
       rpcbasic_register_variable_rw()
           : d_rpc_regset("FAIL",
                          "FAIL",
                          this,
                          &rpcbasic_register_variable<Tfrom>::get,
                          pmt::PMT_NIL,
                          pmt::PMT_NIL,
                          pmt::PMT_NIL,
                          DISPNULL,
                          "FAIL",
                          "FAIL",
                          RPC_PRIVLVL_MIN)
       {
           throw std::runtime_error(
               "ERROR: rpcbasic_register_variable_rw called with no args. if this happens "
               "someone used rpcbasic_register_variable_rw incorrectly.");
       };
   
       void set(Tfrom _variable)
       {
           *(rpcbasic_register_variable<Tfrom>::d_variable) = _variable;
       }
   
       rpcbasic_register_variable_rw(const std::string& namebase,
                                     const char* functionbase,
                                     Tfrom* variable,
                                     const pmt::pmt_t& min,
                                     const pmt::pmt_t& max,
                                     const pmt::pmt_t& def,
                                     const char* units_ = "",
                                     const char* desc_ = "",
                                     priv_lvl_t minpriv = RPC_PRIVLVL_MIN,
                                     DisplayType display_ = DISPNULL)
           : rpcbasic_register_variable<Tfrom>(
                 namebase, functionbase, variable, min, max, def, units_, desc_),
             d_rpc_regset(namebase,
                          functionbase,
                          this,
                          &rpcbasic_register_variable_rw::set,
                          min,
                          max,
                          def,
                          units_,
                          desc_,
                          minpriv,
                          display_)
       {
           // no action
       }
   };
   
   
   template <typename T>
   class rpcbasic_register_handler : public rpcbasic_base
   {
   public:
       rpcbasic_register_handler(const std::string& block_alias,
                                 [[maybe_unused]] const char* handler,
                                 const char* units_ = "",
                                 const char* desc_ = "",
                                 priv_lvl_t minpriv_ = RPC_PRIVLVL_MIN,
                                 DisplayType display_ = DISPNULL)
       {
           d_units = units_;
           d_desc = desc_;
           d_minpriv = minpriv_;
           d_display = display_;
           d_object = dynamic_cast<T*>(
               global_block_registry.block_lookup(pmt::intern(block_alias)).get());
   #ifdef GR_RPCSERVER_ENABLED
           callbackregister_base::handlerCallback_t inserter(
               new rpcbasic_handler<T>(d_object, handler),
               minpriv_,
               std::string(units_),
               display_,
               std::string(desc_),
               0,
               0,
               0);
           std::ostringstream oss(std::ostringstream::out);
           oss << block_alias << "::" << handler;
           d_id = oss.str();
           // std::cerr << "REGISTERING GET: " << d_id << "  " << desc_ << std::endl;
           rpcmanager::get()->i()->registerHandlerCallback(d_id, inserter);
   #endif
       }
   
       ~rpcbasic_register_handler() override
       {
   #ifdef GR_RPCSERVER_ENABLED
           rpcmanager::get()->i()->unregisterHandlerCallback(d_id);
   #endif
       }
   
       std::string units() const { return d_units; }
       std::string description() const { return d_desc; }
       priv_lvl_t privilege_level() const { return d_minpriv; }
       DisplayType default_display() const { return d_display; }
   
       void units(std::string u) { d_units = u; }
       void description(std::string d) { d_desc = d; }
       void privilege_level(priv_lvl_t p) { d_minpriv = p; }
       void default_display(DisplayType d) { d_display = d; }
   
   private:
       std::string d_id;
       std::string d_units, d_desc;
       priv_lvl_t d_minpriv;
       DisplayType d_display;
       T* d_object;
   };
   
   
   #endif
