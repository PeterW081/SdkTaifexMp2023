#include "boost0/asio/EzTcpClientWay01SyncSimple.h"

#pragma
#include <iostream>
#include <boost/algorithm/hex.hpp>

#pragma
namespace nscxx_root = ext::boost_asio0;
namespace nscxx {
using boost::asio::io_context;
using boost::asio::ip::tcp;
enum class EnumFuncXXX;
template <EnumFuncXXX FUNC_XXX> inline auto BOOST_ASIO_ASYNC_FUNC_XXX(tcp::socket &, io_context &, std::span<std::byte> &, std::optional<std::chrono::seconds> &) -> std::size_t;
}

// using namespace nsccxx::inline_func
//
enum class nscxx::EnumFuncXXX {
  WRITE,
  READE,
};
template <nscxx::EnumFuncXXX FUNC_XXX> inline auto nscxx::BOOST_ASIO_ASYNC_FUNC_XXX(tcp::socket &fp_socket, io_context &fp_io_context, std::span<std::byte> &data, std::optional<std::chrono::seconds> &timeout) -> std::size_t {
  static_assert(                        //
      false                             //
      || FUNC_XXX == EnumFuncXXX::WRITE //
      || FUNC_XXX == EnumFuncXXX::READE //
  );

  std::optional<std::size_t> sizeof_xxx = std::nullopt;
  if (FUNC_XXX == EnumFuncXXX::WRITE) {
    boost::asio::async_write(fp_socket, boost::asio::buffer(data.data(), data.size()), [&sizeof_xxx](boost::system::error_code ec, size_t fp_sizeof_write) -> void { sizeof_xxx = fp_sizeof_write; });
  }
  if (FUNC_XXX == EnumFuncXXX::READE) {
    boost::asio::async_read(fp_socket, boost::asio::buffer(data.data(), data.size()), [&sizeof_xxx](boost::system::error_code ec, size_t fp_sizeof_write) -> void { sizeof_xxx = fp_sizeof_write; });
  }
  if (not timeout.has_value()) {
    fp_io_context.reset();
    fp_io_context.run_one();
  } else {
    fp_io_context.reset();
    fp_io_context.run_one_for(std::chrono::seconds(timeout.value()));
    if (not sizeof_xxx.has_value()) {
      fp_socket.cancel();
      fp_io_context.poll_one();
    }
  }

  assert(sizeof_xxx.has_value());
  return sizeof_xxx.value();
}

// using ext::boost_asio0::EzTcpAccessWay01Simple;
//
nscxx_root::EzTcpClientWay01SyncSimple::EzTcpClientWay01SyncSimple(std::string_view server_host, std::string_view server_port) : EzTcpClientWay01_V(server_host, server_port) {}
auto nscxx_root::EzTcpClientWay01SyncSimple::write(std::span<std::byte> data, std::optional<std::chrono::seconds> timeout) -> std::size_t {
  using namespace nscxx;
  auto lock = std::lock_guard(this->m_mutex_sync);
  auto sizeof_write = BOOST_ASIO_ASYNC_FUNC_XXX<EnumFuncXXX::WRITE>(m_socket.operator*(), m_io_context.operator*(), data, timeout);
  if (DEBUG_cfg.is_log_data_hex_content) {
    std::cout << boost::algorithm::hex(std::string(reinterpret_cast<char *>(data.data()), sizeof_write)) << std::endl;
  }
  return sizeof_write;
}
auto nscxx_root::EzTcpClientWay01SyncSimple::reade(std::span<std::byte> data, std::optional<std::chrono::seconds> timeout) -> std::size_t {
  using namespace nscxx;
  auto lock = std::lock_guard(this->m_mutex_sync);
  auto sizeof_reade = BOOST_ASIO_ASYNC_FUNC_XXX<EnumFuncXXX::READE>(m_socket.operator*(), m_io_context.operator*(), data, timeout);
  if (DEBUG_cfg.is_log_data_hex_content) {
    std::cout << boost::algorithm::hex(std::string(reinterpret_cast<char *>(data.data()), sizeof_reade)) << std::endl;
  }
  return sizeof_reade;
}
