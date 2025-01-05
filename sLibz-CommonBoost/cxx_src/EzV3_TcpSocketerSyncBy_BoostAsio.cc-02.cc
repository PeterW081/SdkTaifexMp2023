#include "boost0/asio/EzV3_TcpSocketerSyncBy_BoostAsio.h"
#pragma
#

///
namespace nscxx_root = ext::boost_asio0;
namespace nscxx::log
{
static auto CS_EXCEPTION_MSG_A05F975A = "EXCEPTION_MSG_A05F975A: tcp_endpoint_reset_failed,";
}
namespace nscxx
{
using ext::boost_asio0::EnumTcpSocketAction;
using ext::boost_asio0::EumeTcpEndpointSide;
}

/// EzV3_TcpSocketerSyncBy_BoostAsio
/*Constructor*/                        //
nscxx_root::                           //
    EzV3_TcpSocketerSyncBy_BoostAsio:: //
    EzV3_TcpSocketerSyncBy_BoostAsio(EumeTcpEndpointSide tcp_ep_side, std::string_view tcp_ep_host, std::string_view tcp_ep_port)
    : EzV3_TcpSocketerSync_V(tcp_ep_side)
{
    this->m_tcp_ep_host = tcp_ep_host;
    this->m_tcp_ep_port = tcp_ep_port;
}
/*Destructor*/                         //
nscxx_root::                           //
    EzV3_TcpSocketerSyncBy_BoostAsio:: //
    ~EzV3_TcpSocketerSyncBy_BoostAsio()
{
    this->fv_close0(std::nullopt);
}
auto                                   //
    nscxx_root::                       //
    EzV3_TcpSocketerSyncBy_BoostAsio:: //
    fv_tcp_action(EnumTcpSocketAction tcp_action, std::span<std::byte> span, std::optional<std::chrono::seconds> timeout) -> std::size_t
{
    auto result = std::size_t();
    if constexpr (true)
    {
        switch (tcp_action)
        {
        case EnumTcpSocketAction::READE:
            result = this->fv_reade0(span, timeout);
            break;
        case EnumTcpSocketAction::WRITE:
            result = this->fv_write0(span, timeout);
            break;
        default:
            break;
        }
    }
    if (this->m_is_tcp_server_ought_reset && this->m_tcp_ep_side == EumeTcpEndpointSide::SERVER)
    {
        this->m_is_tcp_server_ought_reset = false;
        this->fv_reset0(timeout);
        if (not this->m_is_tcp_ep_ready)
        {
            throw std::runtime_error(nscxx::log::CS_EXCEPTION_MSG_A05F975A);
        }
        switch (tcp_action)
        {
        case EnumTcpSocketAction::READE:
            result = this->fv_reade0(span, timeout);
            break;
        case EnumTcpSocketAction::WRITE:
            result = 0;
            break;
        default:
            break;
        }
    }
    this->fv_tcp_action_0_post_log(tcp_action, span.subspan(0, result));
    return result;
}

/// EzV3_TcpSocketerSyncBy_BoostAsio - 02
auto                                   //
    nscxx_root::                       //
    EzV3_TcpSocketerSyncBy_BoostAsio:: //
    fv_start0(std::optional<std::chrono::seconds> timeout) -> bool
{
    this->m_is_tcp_ep_ready = false;
    switch (this->m_tcp_ep_side)
    {
    case EumeTcpEndpointSide::SERVER:
        this->m_tcp_ep_member_server = std::make_unique<TYPE_WRAP_TcpEpMemberServer>();
        this->m_tcp_ep_member_server->m_is_ought_init = true;
        this->m_is_tcp_ep_ready = nscxx::BoostAsioAsync::FX_tcp_ep_start<EumeTcpEndpointSide::SERVER, TYPE_WRAP_TcpEpMemberServer>( //
            this->m_tcp_ep_member_server.operator*(), this->m_tcp_ep_host, this->m_tcp_ep_port, timeout);
        break;
    case EumeTcpEndpointSide::CLIENT:
        this->m_tcp_ep_member_client = std::make_unique<TYPE_WRAP_TcpEpMemberClient>();
        this->m_tcp_ep_member_client->m_is_ought_init = true;
        this->m_is_tcp_ep_ready = nscxx::BoostAsioAsync::FX_tcp_ep_start<EumeTcpEndpointSide::CLIENT, TYPE_WRAP_TcpEpMemberClient>( //
            this->m_tcp_ep_member_client.operator*(), this->m_tcp_ep_host, this->m_tcp_ep_port, timeout);
        break;
    [[unlikely]] default:
        this->m_is_tcp_ep_ready = false;
        assert(false);
        break;
    }
    return this->m_is_tcp_ep_ready;
}
auto                                   //
    nscxx_root::                       //
    EzV3_TcpSocketerSyncBy_BoostAsio:: //
    fv_reset0(std::optional<std::chrono::seconds> timeout) -> bool
{
    this->m_is_tcp_ep_ready = false;
    switch (this->m_tcp_ep_side)
    {
    case EumeTcpEndpointSide::SERVER:
        this->m_tcp_ep_member_server->m_is_ought_init = false;
        this->m_is_tcp_ep_ready = nscxx::BoostAsioAsync::FX_tcp_ep_start<EumeTcpEndpointSide::SERVER, TYPE_WRAP_TcpEpMemberServer>( //
            this->m_tcp_ep_member_server.operator*(), this->m_tcp_ep_host, this->m_tcp_ep_port, timeout);
        break;
    case EumeTcpEndpointSide::CLIENT:
        this->m_tcp_ep_member_client->m_is_ought_init = false;
        this->m_is_tcp_ep_ready = nscxx::BoostAsioAsync::FX_tcp_ep_start<EumeTcpEndpointSide::CLIENT, TYPE_WRAP_TcpEpMemberClient>( //
            this->m_tcp_ep_member_client.operator*(), this->m_tcp_ep_host, this->m_tcp_ep_port, timeout);
        break;
    [[unlikely]] default:
        this->m_is_tcp_ep_ready = false;
        assert(false);
        break;
    }
    return this->m_is_tcp_ep_ready;
}
auto                                   //
    nscxx_root::                       //
    EzV3_TcpSocketerSyncBy_BoostAsio:: //
    fv_close0(std::optional<std::chrono::seconds> timeout) -> bool
{
    auto result = bool();
    this->m_is_tcp_ep_ready = false;
    switch (this->m_tcp_ep_side)
    {
    case EumeTcpEndpointSide::SERVER:
        result = nscxx::BoostAsioAsync::FX_tcp_ep_close<EumeTcpEndpointSide::SERVER, TYPE_WRAP_TcpEpMemberServer>( //
            this->m_tcp_ep_member_server.operator*());
        break;
    case EumeTcpEndpointSide::CLIENT:
        result = nscxx::BoostAsioAsync::FX_tcp_ep_close<EumeTcpEndpointSide::CLIENT, TYPE_WRAP_TcpEpMemberClient>( //
            this->m_tcp_ep_member_client.operator*());
        break;
    [[unlikely]] default:
        result = false;
        assert(false);
        break;
    }
    return result;
}
auto                                   //
    nscxx_root::                       //
    EzV3_TcpSocketerSyncBy_BoostAsio:: //
    fv_write0(std::span<std::byte> data, std::optional<std::chrono::seconds> timeout) -> std::size_t
{
    auto result = std::pair<boost::system::error_code, std::size_t>();
    switch (this->m_tcp_ep_side)
    {
    case EumeTcpEndpointSide::SERVER:
        result = nscxx::BoostAsioAsync::FX_tcp_ep_action<EnumTcpSocketAction::WRITE>(this->m_tcp_ep_member_server.operator*(), data, timeout);
        if (result.first.value() == 2)
        {
            this->m_is_tcp_ep_ready = false;
            this->m_is_tcp_server_ought_reset = true;
        }
        break;
    case EumeTcpEndpointSide::CLIENT:
        result = nscxx::BoostAsioAsync::FX_tcp_ep_action<EnumTcpSocketAction::WRITE>(this->m_tcp_ep_member_client.operator*(), data, timeout);
        break;
    default:
        break;
    }
    return result.second;
}
auto                                   //
    nscxx_root::                       //
    EzV3_TcpSocketerSyncBy_BoostAsio:: //
    fv_reade0(std::span<std::byte> data, std::optional<std::chrono::seconds> timeout) -> std::size_t
{
    auto result = std::pair<boost::system::error_code, std::size_t>();
    switch (this->m_tcp_ep_side)
    {
    case EumeTcpEndpointSide::SERVER:
        result = nscxx::BoostAsioAsync::FX_tcp_ep_action<EnumTcpSocketAction::READE>(this->m_tcp_ep_member_server.operator*(), data, timeout);
        if (result.first.value() == 2)
        {
            this->m_is_tcp_ep_ready = false;
            this->m_is_tcp_server_ought_reset = true;
        }
        break;
    case EumeTcpEndpointSide::CLIENT:
        result = nscxx::BoostAsioAsync::FX_tcp_ep_action<EnumTcpSocketAction::READE>(this->m_tcp_ep_member_client.operator*(), data, timeout);
        break;
    default:
        break;
    }
    return result.second;
}
