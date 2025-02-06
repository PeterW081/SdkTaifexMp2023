#pragma once
#include <mutex>
#include <spdlog/spdlog.h>
#
#include "boost0/asio/_define_cxx.h"
#include "xplum/ancestor/SocketerSync_V.h"
#

namespace ext::boost_asio0
{
class EzV4_TcpSocketerSync_V;
}

/// EzV4_TcpSocketerSync_V
class                  //
    ext::boost_asio0:: //
    EzV4_TcpSocketerSync_V : public xplum::ancestor::SocketerSync_V
{
  public:
    class Underlying_V;
    using FxptrActionWithMsgLogic = std::size_t (*)(Underlying_V &, std::span<std::byte>, std::optional<std::chrono::seconds>);

  public:
    virtual auto fv_is_ready() const -> bool final;
    virtual auto fv_write_sync(std::span<std::byte>, std::optional<std::chrono::seconds>) -> std::size_t final;
    virtual auto fv_reade_sync(std::span<std::byte>, std::optional<std::chrono::seconds>) -> std::size_t final;
    virtual auto fv_start_sync(std::optional<std::chrono::seconds>) -> bool final;
    virtual auto fv_close_sync(std::optional<std::chrono::seconds>) -> bool final;
    virtual auto fv_reset_sync(std::optional<std::chrono::seconds>) -> bool final;
    virtual auto fv_xxxxx_sync_cancel() -> void final;

  protected:
    virtual auto fv_hook_log_0_action_post(EnumTcpSocketAction, std::span<std::byte>) -> void;

  protected:
    std::unique_ptr<Underlying_V> const m_underlying0;
    Underlying_V *const thiz_underlying;
    std::mutex m_mutex_sync;
    std::mutex m_mutex_sync_break_only;
    std::unique_ptr<spdlog::logger> m_logger;
    explicit EzV4_TcpSocketerSync_V(std::unique_ptr<Underlying_V>);                                                   // socketer_underlying,
    explicit EzV4_TcpSocketerSync_V(std::unique_ptr<Underlying_V>, FxptrActionWithMsgLogic, FxptrActionWithMsgLogic); // socketer_underlying, func_write0_with_msg_logic, func_reade0_with_msg_logic,

  private:
    FxptrActionWithMsgLogic const fxptr_write0_with_msg_logic;
    FxptrActionWithMsgLogic const fxptr_reade0_with_msg_logic;
};

/// EzV4_TcpSocketerSync_V::Underlying_V
class                  //
    ext::boost_asio0:: //
    EzV4_TcpSocketerSync_V::Underlying_V
{
  public:
    virtual ~Underlying_V() = default;
    explicit Underlying_V(const Underlying_V &) = delete;
    auto operator=(const Underlying_V &) -> Underlying_V & = delete;

  public:
    virtual auto fv_write_sync_0_without_mutex(std::span<std::byte>, std::optional<std::chrono::seconds>) -> std::size_t = 0;
    virtual auto fv_reade_sync_0_without_mutex(std::span<std::byte>, std::optional<std::chrono::seconds>) -> std::size_t = 0;
    virtual auto fv_start_sync_0_without_mutex(std::optional<std::chrono::seconds>) -> bool = 0;
    virtual auto fv_close_sync_0_without_mutex(std::optional<std::chrono::seconds>) -> bool = 0;
    virtual auto fv_reset_sync_0_without_mutex(std::optional<std::chrono::seconds>) -> bool = 0;
    virtual auto fv_xxxxx_sync_cancel_0_without_mutex() -> void = 0;

  public:
    EnumTcpEndpointSide const m_tcp_ep_side;
    bool m_is_ready = false;
    Underlying_V(EnumTcpEndpointSide);
};
