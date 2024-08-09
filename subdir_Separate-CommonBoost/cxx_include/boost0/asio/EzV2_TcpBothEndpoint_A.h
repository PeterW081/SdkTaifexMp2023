#pragma once
#include <boost/asio.hpp>

namespace ext::boost_asio0
{
enum class EumeTcpEndpointSide;
class EzV2_TcpBothEndpoint_A;
}

enum class             //
    ext::boost_asio0:: //
    EumeTcpEndpointSide
{
  NULL0 = 0,
  CLIENT,
  SERVER,
};

class                  //
    ext::boost_asio0:: //
    EzV2_TcpBothEndpoint_A
{
public:
  explicit EzV2_TcpBothEndpoint_A () = delete;
  explicit EzV2_TcpBothEndpoint_A (const EzV2_TcpBothEndpoint_A &inctance) = delete;
  auto operator= (const EzV2_TcpBothEndpoint_A &inctance) -> EzV2_TcpBothEndpoint_A & = delete;

protected:
  // Both
  using TYPE_asio_io_context = boost::asio::io_context;
  using TYPE_asio_socket = boost::asio::ip::tcp::socket;
  // Client
  using TYPE_asio_resolver = boost::asio::ip::tcp::resolver;
  // Server
  using TYPE_asio_acceptor = boost::asio::ip::tcp::acceptor;

protected:
  const EumeTcpEndpointSide m_side;
  std::unique_ptr<TYPE_asio_io_context> m_io_context;
  std::unique_ptr<TYPE_asio_socket> m_socket;
  struct
  {
    std::unique_ptr<TYPE_asio_resolver> m_resolver;
    std::string m_server_host;
    std::string m_server_port;
  } m_plugin_client;
  struct
  {
    std::unique_ptr<TYPE_asio_acceptor> m_acceptor;
  } m_plugin_server;
  explicit EzV2_TcpBothEndpoint_A (EumeTcpEndpointSide, std::string_view, std::string_view); // side, host, port,
  ~EzV2_TcpBothEndpoint_A ();
};
