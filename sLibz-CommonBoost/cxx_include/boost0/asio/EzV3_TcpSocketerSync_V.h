#pragma once
#include <mutex>
#include <spdlog/spdlog.h>
#
#include "boost0/asio/_define_cxx.h"
#include "xplum/ancestor/SocketerSync_V.h"
#

namespace ext::boost_asio0
{
class EzV3_TcpSocketerSync_V;
}

class                  //
    ext::boost_asio0:: //
    EzV3_TcpSocketerSync_V : public xplum::ancestor::SocketerSync_V
{
  public:
    virtual ~EzV3_TcpSocketerSync_V() = default;
    virtual auto fv_reade(std::span<std::byte>, std::optional<std::chrono::seconds>) -> std::size_t final;
    virtual auto fv_write(std::span<std::byte>, std::optional<std::chrono::seconds>) -> std::size_t final;
    virtual auto fv_start(std::optional<std::chrono::seconds>) -> bool final;
    virtual auto fv_close(std::optional<std::chrono::seconds>) -> bool final;
    virtual auto fv_reset(std::optional<std::chrono::seconds>) -> bool final;

  protected:
    bool m_is_tcp_ep_ready = false;
    bool m_is_tcp_server_ought_reset = false;
    std::mutex m_mutex_sync;
    std::unique_ptr<spdlog::logger> m_logger;
    EumeTcpEndpointSide const m_tcp_ep_side;
    explicit EzV3_TcpSocketerSync_V(EumeTcpEndpointSide);
    virtual auto fv_tcp_action(EnumTcpSocketAction tcp_action, std::span<std::byte> span, std::optional<std::chrono::seconds> timeout) -> std::size_t;
    virtual auto fv_tcp_action_0_post_log(EnumTcpSocketAction tcp_action, std::span<std::byte> span) -> void;
    virtual auto fv_reade0(std::span<std::byte>, std::optional<std::chrono::seconds>) -> std::size_t = 0;
    virtual auto fv_write0(std::span<std::byte>, std::optional<std::chrono::seconds>) -> std::size_t = 0;
    virtual auto fv_start0(std::optional<std::chrono::seconds>) -> bool = 0;
    virtual auto fv_close0(std::optional<std::chrono::seconds>) -> bool = 0;
    virtual auto fv_reset0(std::optional<std::chrono::seconds>) -> bool = 0;
};
