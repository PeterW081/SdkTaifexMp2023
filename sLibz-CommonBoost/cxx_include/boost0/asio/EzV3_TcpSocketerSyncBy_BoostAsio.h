#pragma once
#include <mutex>
#include <spdlog/spdlog.h>
#
#include "boost0/asio/EzV3_TcpSocketerSync_V.h"
#

namespace ext::boost_asio0
{
class EzV3_TcpSocketerSyncBy_BoostAsio;
}

class                  //
    ext::boost_asio0:: //
    EzV3_TcpSocketerSyncBy_BoostAsio : public ext::boost_asio0::EzV3_TcpSocketerSync_V
{
  public:
    virtual ~EzV3_TcpSocketerSyncBy_BoostAsio();
    explicit EzV3_TcpSocketerSyncBy_BoostAsio(EumeTcpEndpointSide, std::string_view, std::string_view); // side, host, port,

  protected:
    struct TYPE_WRAP_TcpEpMemberBoth;
    struct TYPE_WRAP_TcpEpMemberServer;
    struct TYPE_WRAP_TcpEpMemberClient;
    std::string m_tcp_ep_host;
    std::string m_tcp_ep_port;
    std::unique_ptr<TYPE_WRAP_TcpEpMemberServer> m_tcp_ep_member_server;
    std::unique_ptr<TYPE_WRAP_TcpEpMemberClient> m_tcp_ep_member_client;
    virtual auto fv_tcp_action(EnumTcpSocketAction tcp_action, std::span<std::byte> span, std::optional<std::chrono::seconds> timeout) -> std::size_t override;
    virtual auto fv_reade0(std::span<std::byte>, std::optional<std::chrono::seconds>) -> std::size_t final;
    virtual auto fv_write0(std::span<std::byte>, std::optional<std::chrono::seconds>) -> std::size_t final;
    virtual auto fv_start0(std::optional<std::chrono::seconds>) -> bool final;
    virtual auto fv_close0(std::optional<std::chrono::seconds>) -> bool final;
    virtual auto fv_reset0(std::optional<std::chrono::seconds>) -> bool final;
};
