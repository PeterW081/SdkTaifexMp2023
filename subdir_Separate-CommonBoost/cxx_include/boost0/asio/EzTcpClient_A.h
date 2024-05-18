#pragma once
#include <boost/asio.hpp>

namespace ext::boost_asio0 {
class EzTcpClient_A;
}

class                  //
    ext::boost_asio0:: //
    EzTcpClient_A      //
{
public:
  EzTcpClient_A(const EzTcpClient_A &inctance) = delete;
  EzTcpClient_A operator=(const EzTcpClient_A &inctance) = delete;

protected:
  using TYPE_io_context = boost::asio::io_context;
  using TYPE_resolver = boost::asio::ip::tcp::resolver;
  using TYPE_socket = boost::asio::ip::tcp::socket;

protected:
  std::unique_ptr<TYPE_io_context> m_io_context;
  std::unique_ptr<TYPE_resolver> m_resolver;
  std::unique_ptr<TYPE_socket> m_socket;
  explicit EzTcpClient_A(std::string_view, std::string_view); // host, port,
  ~EzTcpClient_A();
};
