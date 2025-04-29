
.. _program_listing_file_gnuradio_gnuradio-runtime_include_gnuradio_basic_block.h:

Program Listing for File basic_block.h
======================================

|exhale_lsh| :ref:`Return to documentation for file <file_gnuradio_gnuradio-runtime_include_gnuradio_basic_block.h>` (``gnuradio/gnuradio-runtime/include/gnuradio/basic_block.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* -*- c++ -*- */
   /*
    * Copyright 2006,2008,2009,2011,2013 Free Software Foundation, Inc.
    *
    * This file is part of GNU Radio
    *
    * SPDX-License-Identifier: GPL-3.0-or-later
    *
    */
   
   #ifndef INCLUDED_GR_BASIC_BLOCK_H
   #define INCLUDED_GR_BASIC_BLOCK_H
   
   #include <gnuradio/api.h>
   #include <gnuradio/io_signature.h>
   #include <gnuradio/logger.h>
   #include <gnuradio/msg_accepter.h>
   #include <gnuradio/runtime_types.h>
   #include <gnuradio/sptr_magic.h>
   #include <gnuradio/thread/thread.h>
   #include <boost/thread/condition_variable.hpp>
   #include <deque>
   #include <functional>
   #include <map>
   #include <string>
   
   #include <gnuradio/rpcregisterhelpers.h>
   
   namespace gr {
   
   class msg_queue_comparator
   {
   private:
       const pmt::pmt_t d_system_port = pmt::intern("system");
   
   public:
       bool operator()(pmt::pmt_t const& queue_key1, pmt::pmt_t const& queue_key2) const
       {
           if (pmt::eqv(queue_key2, d_system_port))
               return false;
           else if (pmt::eqv(queue_key1, d_system_port))
               return true;
           else {
               pmt::comparator cmp;
               return cmp(queue_key1, queue_key2);
           }
       }
   };
   
   class GR_RUNTIME_API basic_block : public msg_accepter,
                                      public std::enable_shared_from_this<basic_block>
   {
       typedef std::function<void(pmt::pmt_t)> msg_handler_t;
   
   private:
       typedef std::map<pmt::pmt_t, msg_handler_t, pmt::comparator> d_msg_handlers_t;
       d_msg_handlers_t d_msg_handlers;
   
       typedef std::deque<pmt::pmt_t> msg_queue_t;
       typedef std::map<pmt::pmt_t, msg_queue_t, msg_queue_comparator> msg_queue_map_t;
       typedef std::map<pmt::pmt_t, msg_queue_t, msg_queue_comparator>::iterator
           msg_queue_map_itr;
   
       gr::thread::mutex mutex; //< protects all vars
   
   protected:
       friend class flowgraph;
       friend class flat_flowgraph; // TODO: will be redundant
       friend class tpb_thread_body;
   
       enum vcolor { WHITE, GREY, BLACK };
   
       std::string d_name;
       gr::io_signature::sptr d_input_signature;
       gr::io_signature::sptr d_output_signature;
       long d_unique_id;
       long d_symbolic_id;
       std::string d_symbol_name;
       std::string d_symbol_alias;
       vcolor d_color;
       bool d_rpc_set;
   
       gr::logger_ptr d_logger;       
       gr::logger_ptr d_debug_logger; 
   
       msg_queue_map_t msg_queue;
       std::vector<rpcbasic_sptr> d_rpc_vars; // container for all RPC variables
   
       basic_block(void) {} // allows pure virtual interface sub-classes
   
       basic_block(const std::string& name,
                   gr::io_signature::sptr input_signature,
                   gr::io_signature::sptr output_signature);
   
       void set_input_signature(gr::io_signature::sptr iosig) { d_input_signature = iosig; }
   
       void set_output_signature(gr::io_signature::sptr iosig)
       {
           d_output_signature = iosig;
       }
   
       void set_color(vcolor color) { d_color = color; }
       vcolor color() const { return d_color; }
   
       virtual bool has_msg_handler(pmt::pmt_t which_port)
       {
           return (d_msg_handlers.find(which_port) != d_msg_handlers.end());
       }
   
       /*
        * This function is called by the runtime system to dispatch messages.
        *
        * The thread-safety guarantees mentioned in set_msg_handler are
        * implemented by the callers of this method.
        */
       virtual void dispatch_msg(pmt::pmt_t which_port, pmt::pmt_t msg)
       {
           // AA Update this
           if (has_msg_handler(which_port)) {   // Is there a handler?
               d_msg_handlers[which_port](msg); // Yes, invoke it.
           }
       }
   
       // Message passing interface
       pmt::pmt_t d_message_subscribers;
   
       template <typename Derived>
       std::shared_ptr<Derived> shared_from_base()
       {
           return std::static_pointer_cast<Derived>(shared_from_this());
       }
   
   public:
       pmt::pmt_t message_subscribers(pmt::pmt_t port);
       ~basic_block() override;
       long unique_id() const { return d_unique_id; }
       long symbolic_id() const { return d_symbolic_id; }
   
       std::string name() const { return d_name; }
   
       std::string symbol_name() const { return d_symbol_name; }
       std::string identifier() const
       {
           return this->name() + "(" + std::to_string(this->unique_id()) + ")";
       }
   
       gr::io_signature::sptr input_signature() const { return d_input_signature; }
       gr::io_signature::sptr output_signature() const { return d_output_signature; }
       basic_block_sptr to_basic_block(); // Needed for Python type coercion
   
       bool alias_set() const { return !d_symbol_alias.empty(); }
   
       std::string alias() const { return alias_set() ? d_symbol_alias : symbol_name(); }
   
       pmt::pmt_t alias_pmt() const { return pmt::intern(alias()); }
   
       void set_block_alias(std::string name);
   
       // ** Message passing interface **
       void message_port_register_in(pmt::pmt_t port_id);
       void message_port_register_out(pmt::pmt_t port_id);
       void message_port_pub(pmt::pmt_t port_id, pmt::pmt_t msg);
       void message_port_sub(pmt::pmt_t port_id, pmt::pmt_t target);
       void message_port_unsub(pmt::pmt_t port_id, pmt::pmt_t target);
   
       virtual bool message_port_is_hier(pmt::pmt_t port_id)
       {
           (void)port_id;
           return false;
       }
       virtual bool message_port_is_hier_in(pmt::pmt_t port_id)
       {
           (void)port_id;
           return false;
       }
       virtual bool message_port_is_hier_out(pmt::pmt_t port_id)
       {
           (void)port_id;
           return false;
       }
   
       pmt::pmt_t message_ports_in();
   
       pmt::pmt_t message_ports_out();
   
       void _post(pmt::pmt_t which_port, pmt::pmt_t msg);
   
       bool empty_p(pmt::pmt_t which_port)
       {
           if (msg_queue.find(which_port) == msg_queue.end())
               throw std::runtime_error("port does not exist!");
           return msg_queue[which_port].empty();
       }
       bool empty_p()
       {
           bool rv = true;
           for (const auto& i : msg_queue) {
               rv &= msg_queue[i.first].empty();
           }
           return rv;
       }
   
       bool empty_handled_p(pmt::pmt_t which_port)
       {
           return (empty_p(which_port) || !has_msg_handler(which_port));
       }
       bool empty_handled_p()
       {
           bool rv = true;
           for (const auto& i : msg_queue) {
               rv &= empty_handled_p(i.first);
           }
           return rv;
       }
   
       size_t nmsgs(pmt::pmt_t which_port)
       {
           if (msg_queue.find(which_port) == msg_queue.end())
               throw std::runtime_error("port does not exist!");
           return msg_queue[which_port].size();
       }
   
       //| Acquires and release the mutex
       void insert_tail(pmt::pmt_t which_port, pmt::pmt_t msg);
       pmt::pmt_t delete_head_nowait(pmt::pmt_t which_port);
   
       msg_queue_t::iterator get_iterator(pmt::pmt_t which_port)
       {
           return msg_queue[which_port].begin();
       }
   
       void erase_msg(pmt::pmt_t which_port, msg_queue_t::iterator it)
       {
           msg_queue[which_port].erase(it);
       }
   
       virtual bool has_msg_port(pmt::pmt_t which_port)
       {
           if (msg_queue.find(which_port) != msg_queue.end()) {
               return true;
           }
           if (pmt::dict_has_key(d_message_subscribers, which_port)) {
               return true;
           }
           return false;
       }
   
       const msg_queue_map_t& get_msg_map(void) const { return msg_queue; }
   
   #ifdef GR_CTRLPORT
       void add_rpc_variable(rpcbasic_sptr s) { d_rpc_vars.push_back(s); }
   #endif /* GR_CTRLPORT */
   
       virtual void setup_rpc(){};
   
       bool is_rpc_set() { return d_rpc_set; }
   
       void rpc_set() { d_rpc_set = true; }
   
       virtual bool check_topology(int ninputs, int noutputs)
       {
           (void)ninputs;
           (void)noutputs;
           return true;
       }
   
       template <typename T>
       void set_msg_handler(pmt::pmt_t which_port, T msg_handler)
       {
           if (msg_queue.find(which_port) == msg_queue.end()) {
               throw std::runtime_error(
                   "attempt to set_msg_handler() on bad input message port!");
           }
           d_msg_handlers[which_port] = msg_handler_t(msg_handler);
       }
   
       virtual void set_processor_affinity(const std::vector<int>& mask) = 0;
   
       virtual void unset_processor_affinity() = 0;
   
       virtual std::vector<int> processor_affinity() = 0;
   
       virtual void set_log_level(const std::string& level) = 0;
   
       virtual std::string log_level() = 0;
   };
   
   inline bool operator<(basic_block_sptr lhs, basic_block_sptr rhs)
   {
       return lhs->unique_id() < rhs->unique_id();
   }
   
   typedef std::vector<basic_block_sptr> basic_block_vector_t;
   typedef std::vector<basic_block_sptr>::iterator basic_block_viter_t;
   
   GR_RUNTIME_API long basic_block_ncurrently_allocated();
   
   inline std::ostream& operator<<(std::ostream& os, basic_block_sptr basic_block)
   {
       os << basic_block->identifier();
       return os;
   }
   
   } /* namespace gr */
   
   #endif /* INCLUDED_GR_BASIC_BLOCK_H */
