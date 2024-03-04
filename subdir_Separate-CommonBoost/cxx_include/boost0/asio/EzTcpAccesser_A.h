#pragma once
#include <boost/asio.hpp>

namespace ext::boost_asio0 {
class EzTcpAccesser_A;
}

class                  //
    ext::boost_asio0:: //
    EzTcpAccesser_A    //
{
public:
  EzTcpAccesser_A(const EzTcpAccesser_A &inctance) = delete;
  EzTcpAccesser_A operator=(const EzTcpAccesser_A &inctance) = delete;

protected:
  using TYPE_io_context = boost::asio::io_context;
  using TYPE_resolver = boost::asio::ip::tcp::resolver;
  using TYPE_socket = boost::asio::ip::tcp::socket;

protected:
  std::unique_ptr<TYPE_io_context> m_io_context;
  std::unique_ptr<TYPE_resolver> m_resolver;
  std::unique_ptr<TYPE_socket> m_socket;
  explicit EzTcpAccesser_A(std::string_view, std::string_view); // host, port,
  ~EzTcpAccesser_A();
};
