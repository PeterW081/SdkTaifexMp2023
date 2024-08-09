#include "boost0/asio/EzV2_TcpBothEndpointWay01SyncSimple.h"
#pragma

#include <iostream>
#include <boost/algorithm/hex.hpp>

namespace nscxx_root = ext::boost_asio0;
namespace nscxx::log
{
static char CS_EXCEPTION_MSG_4903074D[] = "EXCEPTION_MSG_4903074D: boost_asio, tcp_endpoint_is_no_ready,";
}
namespace nscxx
{
using boost::asio::io_context;
using boost::asio::ip::tcp;
using boost::system::error_code;
enum class EnumFuncXXX;
static inline auto BOOST_ASIO_ASYNC_CLIENT_START (std::optional<std::chrono::seconds> &, io_context &, tcp::socket &, tcp::resolver &, std::string_view, std::string_view) -> bool;
static inline auto BOOST_ASIO_ASYNC_SERVER_START (std::optional<std::chrono::seconds> &, io_context &, tcp::acceptor &) -> std::pair<bool, std::unique_ptr<tcp::socket> >;
template <EnumFuncXXX FUNC_XXX> static inline auto BOOST_ASIO_ASYNC_BOTH_FUNC_XXX (std::optional<std::chrono::seconds> &, io_context &, tcp::socket &, std::span<std::byte> &) -> std::size_t;
template <typename T> static inline auto BOOST_ASIO_ASYNC_RUN_ONE_WITH_TIMEOUT (std::optional<std::chrono::seconds> &, io_context &, std::optional<T> &, std::function<void ()>) -> void;
}

/// nscxx - 01
enum class nscxx::EnumFuncXXX
{
  NULL0 = 0,
  WRITE,
  READE,
};

/// EzV2_TcpBothEndpointWay01SyncSimple
/*Constructor*/                           //
nscxx_root::                              //
    EzV2_TcpBothEndpointWay01SyncSimple:: //
    EzV2_TcpBothEndpointWay01SyncSimple (EumeTcpEndpointSide server_side, std::string_view server_host, std::string_view server_port)
    : EzV2_TcpBothEndpoint_A (server_side, server_host, server_port), m_is_done_start (false)
{
}
auto                                      //
    nscxx_root::                          //
    EzV2_TcpBothEndpointWay01SyncSimple:: //
    fv_start (std::optional<std::chrono::seconds> timeout) -> bool
{
  auto lock = std::lock_guard (this->m_mutex_sync);
  if (not this->m_is_done_start)
    {
      switch (this->m_side)
        {
        case EumeTcpEndpointSide::CLIENT:
          {
            this->m_is_done_start = nscxx::BOOST_ASIO_ASYNC_CLIENT_START (                                                            //
                timeout, this->m_io_context.operator* (), this->m_socket.operator* (), this->m_plugin_client.m_resolver.operator* (), //
                this->m_plugin_client.m_server_host, this->m_plugin_client.m_server_port                                              //
            );
          }
          break;
        case EumeTcpEndpointSide::SERVER:
          {
            auto result = nscxx::BOOST_ASIO_ASYNC_SERVER_START (timeout, this->m_io_context.operator* (), this->m_plugin_server.m_acceptor.operator* ());
            this->m_is_done_start = result.first;
            this->m_socket = std::move (result.second);
          }
          break;
          [[unlikely]] default:
          {
            this->m_is_done_start = false;
            assert (false);
          }
          break;
        }
    }
  return this->m_is_done_start;
}
auto                                      //
    nscxx_root::                          //
    EzV2_TcpBothEndpointWay01SyncSimple:: //
    fv_close (std::optional<std::chrono::seconds> timeout) -> bool
{
  // TODO
  auto lock = std::lock_guard (this->m_mutex_sync);
  return true;
}
auto                                      //
    nscxx_root::                          //
    EzV2_TcpBothEndpointWay01SyncSimple:: //
    fv_write (std::span<std::byte> data, std::optional<std::chrono::seconds> timeout) -> std::size_t
{
  auto lock = std::lock_guard (this->m_mutex_sync);
  if (not this->m_is_done_start)
    {
      throw std::runtime_error (nscxx::log::CS_EXCEPTION_MSG_4903074D);
    }
  auto sizeof_xxx = nscxx::BOOST_ASIO_ASYNC_BOTH_FUNC_XXX<nscxx::EnumFuncXXX::WRITE> (timeout, this->m_io_context.operator* (), this->m_socket.operator* (), data);
  if (DEBUG_cfg.is_log_data_hex_content)
    {
      std::cout << boost::algorithm::hex (std::string (reinterpret_cast<char *> (data.data ()), sizeof_xxx)) << std::endl;
    }
  return sizeof_xxx;
}
auto                                      //
    nscxx_root::                          //
    EzV2_TcpBothEndpointWay01SyncSimple:: //
    fv_reade (std::span<std::byte> data, std::optional<std::chrono::seconds> timeout) -> std::size_t
{
  auto lock = std::lock_guard (this->m_mutex_sync);
  if (not this->m_is_done_start)
    {
      throw std::runtime_error (nscxx::log::CS_EXCEPTION_MSG_4903074D);
    }
  auto sizeof_xxx = nscxx::BOOST_ASIO_ASYNC_BOTH_FUNC_XXX<nscxx::EnumFuncXXX::READE> (timeout, this->m_io_context.operator* (), this->m_socket.operator* (), data);
  if (DEBUG_cfg.is_log_data_hex_content)
    {
      std::cout << boost::algorithm::hex (std::string (reinterpret_cast<char *> (data.data ()), sizeof_xxx)) << std::endl;
    }
  return sizeof_xxx;
}

/// nscxx - 02
auto        //
    nscxx:: //
    BOOST_ASIO_ASYNC_CLIENT_START (std::optional<std::chrono::seconds> &timeout, io_context &fp_io_context, tcp::socket &fp_socket, tcp::resolver &fp_resolver, std::string_view server_host, std::string_view server_port) -> bool
{
  auto error_code = std::optional<boost::system::error_code> ();
  auto async_func = [&error_code] (const nscxx::error_code &fp_error_code, const nscxx::tcp::endpoint &) {
    error_code = fp_error_code;
    if (static_cast<bool> (fp_error_code))
      {
        std::cout << fp_error_code.message () << std::endl;
      }
  };
  auto func_when_done_mark_false = [&fp_socket] () -> void { fp_socket.cancel (); };
  boost::asio::async_connect (fp_socket, fp_resolver.resolve (server_host, server_port), async_func);
  nscxx::BOOST_ASIO_ASYNC_RUN_ONE_WITH_TIMEOUT (timeout, fp_io_context, error_code, func_when_done_mark_false);
  return error_code.has_value () && not static_cast<bool> (error_code.value ());
}
auto        //
    nscxx:: //
    BOOST_ASIO_ASYNC_SERVER_START (std::optional<std::chrono::seconds> &timeout, io_context &fp_io_context, tcp::acceptor &fp_acceptor) -> std::pair<bool, std::unique_ptr<tcp::socket> >
{
  auto error_code = std::optional<boost::system::error_code> ();
  auto ptr_socket = std::unique_ptr<tcp::socket> ();
  auto async_func = [&error_code, &ptr_socket] (const nscxx::error_code &fp_error_code, tcp::socket f2p_socket) {
    error_code = fp_error_code;
    ptr_socket = std::make_unique<tcp::socket> (std::move (f2p_socket));
  };
  fp_acceptor.async_accept (async_func);
  nscxx::BOOST_ASIO_ASYNC_RUN_ONE_WITH_TIMEOUT (timeout, fp_io_context, error_code, nullptr);
  return std::pair{ error_code.has_value () && not static_cast<bool> (error_code.value ()), std::move (ptr_socket) };
}
template <nscxx::EnumFuncXXX FUNC_XXX>
auto        //
    nscxx:: //
    BOOST_ASIO_ASYNC_BOTH_FUNC_XXX (std::optional<std::chrono::seconds> &timeout, io_context &fp_io_context, tcp::socket &fp_socket, std::span<std::byte> &data) -> std::size_t
{
  static_assert (                       //
      false                             //
      || FUNC_XXX == EnumFuncXXX::WRITE //
      || FUNC_XXX == EnumFuncXXX::READE //
  );

  std::optional<std::size_t> sizeof_xxx = std::nullopt;
  auto async_func = [&sizeof_xxx] (boost::system::error_code ec, size_t fp_sizeof_write) -> void { sizeof_xxx = fp_sizeof_write; };
  auto func_when_done_mark_false = [&fp_socket] () -> void { fp_socket.cancel (); };
  if constexpr (FUNC_XXX == EnumFuncXXX::WRITE)
    {
      boost::asio::async_write (fp_socket, boost::asio::buffer (data.data (), data.size ()), async_func);
    }
  if constexpr (FUNC_XXX == EnumFuncXXX::READE)
    {
      boost::asio::async_read (fp_socket, boost::asio::buffer (data.data (), data.size ()), async_func);
    }
  nscxx::BOOST_ASIO_ASYNC_RUN_ONE_WITH_TIMEOUT (timeout, fp_io_context, sizeof_xxx, func_when_done_mark_false);
  return sizeof_xxx.value ();
}
template <typename T>
auto        //
    nscxx:: //
    BOOST_ASIO_ASYNC_RUN_ONE_WITH_TIMEOUT (std::optional<std::chrono::seconds> &timeout, io_context &fp_io_context, std::optional<T> &done_mark, const std::function<void ()> func_when_done_mark_false) -> void
{
  if (not timeout.has_value ())
    {
      fp_io_context.restart ();
      fp_io_context.run_one ();
    }
  else
    {
      fp_io_context.restart ();
      fp_io_context.run_one_for (timeout.value ());
      if (not done_mark.has_value ())
        {
          if (func_when_done_mark_false != nullptr)
            {
              func_when_done_mark_false ();
            }
          fp_io_context.poll_one ();
        }
    }
}
