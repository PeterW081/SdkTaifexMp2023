#include "boost0/asio/EzV4_TcpSocketerSyncBoostAsio.h"
#pragma
#include <boost/asio.hpp>
#

///
namespace nscxx_root = ext::boost_asio0;
namespace nscxx
{
using ext::boost_asio0::EnumTcpEndpointSide;
using ext::boost_asio0::EnumTcpSocketAction;
}

/// EzV4_TcpSocketerSyncBoostAsio
/*Constructor*/                     //
nscxx_root::                        //
    EzV4_TcpSocketerSyncBoostAsio:: //
    EzV4_TcpSocketerSyncBoostAsio(EnumTcpEndpointSide side, std::string_view host, std::string_view port)
    : EzV4_TcpSocketerSync_V(std::make_unique<UnderlyingBoostAsio>(side, host, port))
{
}

/// EzV4_TcpSocketerSyncBoostAsio::UnderlyingBoostAsio
// X EzV4_TcpSocketerSyncBoostAsio::UnderlyingBoostAsio - 01
struct                                                                    //
    nscxx_root::                                                          //
    EzV4_TcpSocketerSyncBoostAsio::UnderlyingBoostAsio::TcpEpMemberServer //
    : nscxx::BoostAsioAsync::TcpEpMemberServer
{
};
struct                                                                    //
    nscxx_root::                                                          //
    EzV4_TcpSocketerSyncBoostAsio::UnderlyingBoostAsio::TcpEpMemberClient //
    : nscxx::BoostAsioAsync::TcpEpMemberClient
{
};
// X EzV4_TcpSocketerSyncBoostAsio::UnderlyingBoostAsio - 02
/*Constructor*/                                          //
nscxx_root::                                             //
    EzV4_TcpSocketerSyncBoostAsio::UnderlyingBoostAsio:: //
    UnderlyingBoostAsio(EnumTcpEndpointSide tcp_ep_side, std::string_view tcp_ep_host, std::string_view tcp_ep_port)
    : EzV4_TcpSocketerSync_V::Underlying_V(tcp_ep_side)
{
    this->m_tcp_ep_host = tcp_ep_host;
    this->m_tcp_ep_port = tcp_ep_port;
}
/*Destructor*/                                           //
nscxx_root::                                             //
    EzV4_TcpSocketerSyncBoostAsio::UnderlyingBoostAsio:: //
    ~UnderlyingBoostAsio()
{
    this->fv_close_sync_0_without_mutex(std::nullopt);
}
// X EzV4_TcpSocketerSyncBoostAsio::UnderlyingBoostAsio - 03
auto                                                     //
    nscxx_root::                                         //
    EzV4_TcpSocketerSyncBoostAsio::UnderlyingBoostAsio:: //
    fv_start_sync_0_without_mutex(std::optional<std::chrono::seconds> timeout) -> bool
{
    this->m_is_ready = false;
    switch (this->m_tcp_ep_side)
    {
    case EnumTcpEndpointSide::SERVER:
        this->m_tcp_ep_member_server = std::make_unique<TcpEpMemberServer>();
        this->m_tcp_ep_member_server->m_is_ought_init = true;
        this->m_is_ready = nscxx::BoostAsioAsync::FX_tcp_ep_start<EnumTcpEndpointSide::SERVER, nscxx::BoostAsioAsync::TcpEpMemberServer>( //
            this->m_tcp_ep_member_server.operator*(), this->m_tcp_ep_host, this->m_tcp_ep_port, timeout);
        break;
    case EnumTcpEndpointSide::CLIENT:
        this->m_tcp_ep_member_client = std::make_unique<TcpEpMemberClient>();
        this->m_tcp_ep_member_client->m_is_ought_init = true;
        this->m_is_ready = nscxx::BoostAsioAsync::FX_tcp_ep_start<EnumTcpEndpointSide::CLIENT, nscxx::BoostAsioAsync::TcpEpMemberClient>( //
            this->m_tcp_ep_member_client.operator*(), this->m_tcp_ep_host, this->m_tcp_ep_port, timeout);
        break;
    [[unlikely]] default:
        this->m_is_ready = false;
        assert(false);
        break;
    }
    return this->m_is_ready;
}
auto                                                     //
    nscxx_root::                                         //
    EzV4_TcpSocketerSyncBoostAsio::UnderlyingBoostAsio:: //
    fv_reset_sync_0_without_mutex(std::optional<std::chrono::seconds> timeout) -> bool
{
    this->m_is_ready = false;
    switch (this->m_tcp_ep_side)
    {
    case EnumTcpEndpointSide::SERVER:
        this->m_tcp_ep_member_server->m_is_ought_init = false;
        this->m_is_ready = nscxx::BoostAsioAsync::FX_tcp_ep_start<EnumTcpEndpointSide::SERVER, nscxx::BoostAsioAsync::TcpEpMemberServer>( //
            this->m_tcp_ep_member_server.operator*(), this->m_tcp_ep_host, this->m_tcp_ep_port, timeout);
        break;
    case EnumTcpEndpointSide::CLIENT:
        this->m_tcp_ep_member_client->m_is_ought_init = false;
        this->m_is_ready = nscxx::BoostAsioAsync::FX_tcp_ep_start<EnumTcpEndpointSide::CLIENT, nscxx::BoostAsioAsync::TcpEpMemberClient>( //
            this->m_tcp_ep_member_client.operator*(), this->m_tcp_ep_host, this->m_tcp_ep_port, timeout);
        break;
    [[unlikely]] default:
        this->m_is_ready = false;
        assert(false);
        break;
    }
    return this->m_is_ready;
}
auto                                                     //
    nscxx_root::                                         //
    EzV4_TcpSocketerSyncBoostAsio::UnderlyingBoostAsio:: //
    fv_close_sync_0_without_mutex(std::optional<std::chrono::seconds> timeout) -> bool
{
    auto result = bool();
    this->m_is_ready = false;
    switch (this->m_tcp_ep_side)
    {
    case EnumTcpEndpointSide::SERVER:
        result = nscxx::BoostAsioAsync::FX_tcp_ep_close<EnumTcpEndpointSide::SERVER, TcpEpMemberServer>( //
            this->m_tcp_ep_member_server.operator*());
        break;
    case EnumTcpEndpointSide::CLIENT:
        result = nscxx::BoostAsioAsync::FX_tcp_ep_close<EnumTcpEndpointSide::CLIENT, TcpEpMemberClient>( //
            this->m_tcp_ep_member_client.operator*());
        break;
    [[unlikely]] default:
        result = false;
        assert(false);
        break;
    }
    return result;
}
auto                                                     //
    nscxx_root::                                         //
    EzV4_TcpSocketerSyncBoostAsio::UnderlyingBoostAsio:: //
    fv_write_sync_0_without_mutex(std::span<std::byte> data, std::optional<std::chrono::seconds> timeout) -> std::size_t
{
    auto *tcp_ep_member = static_cast<nscxx::BoostAsioAsync::TcpEpMemberBoth *>(nullptr);
    switch (this->m_tcp_ep_side)
    {
    case EnumTcpEndpointSide::SERVER:
        tcp_ep_member = this->m_tcp_ep_member_server.get();
        break;
    case EnumTcpEndpointSide::CLIENT:
        tcp_ep_member = this->m_tcp_ep_member_client.get();
        break;
    [[unlikely]] default:
        assert(false);
        break;
    }
    //
    auto result = nscxx::BoostAsioAsync::FX_tcp_ep_action<EnumTcpSocketAction::WRITE>(*tcp_ep_member, data, timeout);
    if (result.first.value() == 2)
    {
        this->m_is_ready = false;
    }
    return result.second;
}
auto                                                     //
    nscxx_root::                                         //
    EzV4_TcpSocketerSyncBoostAsio::UnderlyingBoostAsio:: //
    fv_reade_sync_0_without_mutex(std::span<std::byte> data, std::optional<std::chrono::seconds> timeout) -> std::size_t
{
    auto *tcp_ep_member = static_cast<nscxx::BoostAsioAsync::TcpEpMemberBoth *>(nullptr);
    switch (this->m_tcp_ep_side)
    {
    case EnumTcpEndpointSide::SERVER:
        tcp_ep_member = this->m_tcp_ep_member_server.get();
        break;
    case EnumTcpEndpointSide::CLIENT:
        tcp_ep_member = this->m_tcp_ep_member_client.get();
        break;
    [[unlikely]] default:
        assert(false);
        break;
    }
    //
    auto result = nscxx::BoostAsioAsync::FX_tcp_ep_action<EnumTcpSocketAction::READE>(*tcp_ep_member, data, timeout);
    if (result.first.value() == 2)
    {
        this->m_is_ready = false;
    }
    return result.second;
}
auto                                                     //
    nscxx_root::                                         //
    EzV4_TcpSocketerSyncBoostAsio::UnderlyingBoostAsio:: //
    fv_xxxxx_sync_cancel_0_without_mutex() -> void
{
    auto *tcp_ep_member = static_cast<nscxx::BoostAsioAsync::TcpEpMemberBoth *>(nullptr);
    switch (this->m_tcp_ep_side)
    {
    case EnumTcpEndpointSide::SERVER:
        tcp_ep_member = this->m_tcp_ep_member_server.get();
        break;
    case EnumTcpEndpointSide::CLIENT:
        tcp_ep_member = this->m_tcp_ep_member_client.get();
        break;
    [[unlikely]] default:
        assert(false);
        break;
    }
    //
    nscxx::BoostAsioAsync::FX_tcp_ep_action_0_cancel(*tcp_ep_member);
}
