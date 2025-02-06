#pragma once
#include <mutex>
#include <spdlog/spdlog.h>
#
#include "boost0/asio/EzV4_TcpSocketerSync_V.h"
#

namespace ext::boost_asio0
{
class EzV4_TcpSocketerSyncBoostAsio;
}

/// EzV4_TcpSocketerSyncBoostAsio
class                  //
    ext::boost_asio0:: //
    EzV4_TcpSocketerSyncBoostAsio final : public ext::boost_asio0::EzV4_TcpSocketerSync_V
{
  public:
    class UnderlyingBoostAsio;
    virtual ~EzV4_TcpSocketerSyncBoostAsio() = default;
    explicit EzV4_TcpSocketerSyncBoostAsio(EnumTcpEndpointSide, std::string_view, std::string_view); // side, host, port,
};

/// EzV4_TcpSocketerSyncBoostAsio::EzV4_TcpSocketerSyncBoostAsio
class                  //
    ext::boost_asio0:: //
    EzV4_TcpSocketerSyncBoostAsio::UnderlyingBoostAsio final : public EzV4_TcpSocketerSync_V::Underlying_V
{
  public:
    virtual ~UnderlyingBoostAsio();
    virtual auto fv_write_sync_0_without_mutex(std::span<std::byte>, std::optional<std::chrono::seconds>) -> std::size_t final;
    virtual auto fv_reade_sync_0_without_mutex(std::span<std::byte>, std::optional<std::chrono::seconds>) -> std::size_t final;
    virtual auto fv_start_sync_0_without_mutex(std::optional<std::chrono::seconds>) -> bool final;
    virtual auto fv_close_sync_0_without_mutex(std::optional<std::chrono::seconds>) -> bool final;
    virtual auto fv_reset_sync_0_without_mutex(std::optional<std::chrono::seconds>) -> bool final;
    virtual auto fv_xxxxx_sync_cancel_0_without_mutex() -> void final;

  public:
    explicit UnderlyingBoostAsio(EnumTcpEndpointSide, std::string_view, std::string_view); // side, host, port,

  protected:
    struct TcpEpMemberServer;
    struct TcpEpMemberClient;
    std::string m_tcp_ep_host;
    std::string m_tcp_ep_port;
    std::unique_ptr<TcpEpMemberServer> m_tcp_ep_member_server;
    std::unique_ptr<TcpEpMemberClient> m_tcp_ep_member_client;
};
