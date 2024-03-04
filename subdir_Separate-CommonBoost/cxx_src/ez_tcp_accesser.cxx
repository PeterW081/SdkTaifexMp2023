#include "boost0/asio/EzTcpAccesser_A.h"
#include "boost0/asio/EzTcpAccesserWay01_V.h"
namespace nscxx_root = ext::boost_asio0;
#pragma

// using ext::boost_asio0::EzTcpAccesser_A;
//
nscxx_root::EzTcpAccesser_A::EzTcpAccesser_A(std::string_view server_host, std::string_view server_port) {
  m_io_context = std::make_unique<TYPE_io_context>();
  m_resolver = std::make_unique<TYPE_resolver>(m_io_context.operator*());
  m_socket = std::make_unique<TYPE_socket>(m_io_context.operator*());
  boost::asio::connect(m_socket.operator*(), m_resolver->resolve(server_host, server_port));
}
nscxx_root::EzTcpAccesser_A::~EzTcpAccesser_A() {
  m_socket.reset();
  m_resolver.reset();
  m_io_context.reset();
}

// using ext::boost_asio0::EzTcpAccesserSyncWay01_V;
//
nscxx_root::EzTcpAccesserWay01_V::EzTcpAccesserWay01_V(std::string_view server_host, std::string_view server_port) : EzTcpAccesser_A(server_host, server_port) {}
auto nscxx_root::EzTcpAccesserWay01_V::write_str(std::string &data) -> void { this->write(std::span(reinterpret_cast<std::byte *>(data.data()), data.size())); }
auto nscxx_root::EzTcpAccesserWay01_V::reade_str(std::string &data) -> void { this->reade(std::span(reinterpret_cast<std::byte *>(data.data()), data.size())); }
