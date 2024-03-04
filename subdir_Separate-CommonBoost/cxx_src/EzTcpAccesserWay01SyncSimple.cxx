#include "boost0/asio/EzTcpAccesserWay01SyncSimple.h"
namespace nscxx_root = ext::boost_asio0;

#pragma
#include <iostream>
#include <boost/algorithm/hex.hpp>

// using ext::boost_asio0::EzTcpAccessWay01Simple;
//
nscxx_root::EzTcpAccesserWay01SyncSimple::EzTcpAccesserWay01SyncSimple(std::string_view server_host, std::string_view server_port) : EzTcpAccesserWay01_V(server_host, server_port) {}
auto nscxx_root::EzTcpAccesserWay01SyncSimple::write(std::span<std::byte> data) -> void {
  if (DEBUG_cfg.is_log_data_hex_content) {
    std::cout << boost::algorithm::hex(std::string(reinterpret_cast<char *>(data.data()), data.size())) << std::endl;
  }
  boost::asio::write(m_socket.operator*(), boost::asio::buffer(data.data(), data.size_bytes()));
}
auto nscxx_root::EzTcpAccesserWay01SyncSimple::reade(std::span<std::byte> data) -> void {
  boost::asio::read(m_socket.operator*(), boost::asio::buffer(data.data(), data.size_bytes()));
  if (DEBUG_cfg.is_log_data_hex_content) {
    std::cout << boost::algorithm::hex(std::string(reinterpret_cast<char *>(data.data()), data.size())) << std::endl;
  }
}
