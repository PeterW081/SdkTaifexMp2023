#include "boost0/asio/EzTcpClient_A.h"

#pragma
namespace nscxx_root = ext::boost_asio0;

// using ext::boost_asio0::EzTcpClient_A;
//
nscxx_root::EzTcpClient_A::EzTcpClient_A(std::string_view server_host, std::string_view server_port) {
  m_io_context = std::make_unique<TYPE_io_context>();
  m_resolver = std::make_unique<TYPE_resolver>(m_io_context.operator*());
  m_socket = std::make_unique<TYPE_socket>(m_io_context.operator*());
  boost::asio::connect(m_socket.operator*(), m_resolver->resolve(server_host, server_port));
}
nscxx_root::EzTcpClient_A::~EzTcpClient_A() {
  m_socket.reset();
  m_resolver.reset();
  m_io_context.reset();
}
