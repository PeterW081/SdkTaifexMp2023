#include "boost0/asio/EzV2_TcpBothEndpoint_A.h"
#pragma

namespace nscxx_root = ext::boost_asio0;

/// EzV2_TcpBothEndpoint_A
/*Constructor*/              //
nscxx_root::                 //
    EzV2_TcpBothEndpoint_A:: //
    EzV2_TcpBothEndpoint_A(EumeTcpEndpointSide server_side, std::string_view server_host, std::string_view server_port)
    : m_side(server_side)
{
    using boost::asio::ip::tcp;
    this->m_io_context = std::make_unique<TYPE_asio_io_context>();
    switch (this->m_side)
    {
    case EumeTcpEndpointSide::CLIENT: {
        this->m_socket = std::make_unique<TYPE_asio_socket>(this->m_io_context.operator*());
        this->m_plugin_client.m_resolver = std::make_unique<TYPE_asio_resolver>(this->m_io_context.operator*());
        this->m_plugin_client.m_server_host = server_host;
        this->m_plugin_client.m_server_port = server_port;
    }
    break;
    case EumeTcpEndpointSide::SERVER: {
        auto endpoint = server_host.empty()                                                                            //
                            ? tcp::endpoint(tcp::v4(), std::stoi(server_port.data()))                                  //
                            : tcp::endpoint(boost::asio::ip::make_address(server_host), std::stoi(server_port.data())) //
            ;
        this->m_socket = nullptr;
        this->m_plugin_server.m_acceptor = std::make_unique<TYPE_asio_acceptor>(this->m_io_context.operator*(), endpoint);
    }
    break;
        [[unlikely]] default : throw std::invalid_argument("EXCEPTION_MSG_8277AD35: enum, EumeTcpEndpointType,");
        assert(false);
    }
}
/*Destructor*/               //
nscxx_root::                 //
    EzV2_TcpBothEndpoint_A:: //
    ~EzV2_TcpBothEndpoint_A()
{
    this->m_plugin_client.m_resolver.reset();
    this->m_plugin_server.m_acceptor.reset();
    this->m_socket.reset();
    this->m_io_context.reset();
}
