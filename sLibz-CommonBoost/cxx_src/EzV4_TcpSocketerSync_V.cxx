#include "boost0/asio/EzV4_TcpSocketerSync_V.h"
#pragma
#
#include <spdlog/fmt/bin_to_hex.h>
#include "spdlog0/logger_factory.h"
#

///
namespace nscxx_root = ext::boost_asio0;
namespace nscxx::log
{
static auto CS_EXCEPTION_MSG_0B16CF5C = "EXCEPTION_MSG_0B16CF5C: tcp_endpoint_is_no_ready,";
static auto CS_EXCEPTION_MSG_A05F975A = "EXCEPTION_MSG_A05F975A: tcp_endpoint_reset_failed,";
}
namespace nscxx
{
using ext::boost_asio0::EnumTcpEndpointSide;
using ext::boost_asio0::EnumTcpSocketAction;
}

/// EzV4_TcpSocketerSync_V
/*Constructor*/              //
nscxx_root::                 //
    EzV4_TcpSocketerSync_V:: //
    EzV4_TcpSocketerSync_V(std::unique_ptr<Underlying_V> socketer_underlying)
    : m_underlying0(std::move(socketer_underlying)), thiz_underlying(m_underlying0.get()), fxptr_write0_with_msg_logic(nullptr), fxptr_reade0_with_msg_logic(nullptr)
{
    assert(thiz_underlying != nullptr);
    this->m_logger = ext::spdlog0::FX_logger_factory(this);
}
/*Constructor*/              //
nscxx_root::                 //
    EzV4_TcpSocketerSync_V:: //
    EzV4_TcpSocketerSync_V(std::unique_ptr<Underlying_V> socketer_underlying, FxptrActionWithMsgLogic func_write0_with_msg_logic, FxptrActionWithMsgLogic func_reade0_with_msg_logic)
    : m_underlying0(std::move(socketer_underlying)), thiz_underlying(m_underlying0.get()), fxptr_write0_with_msg_logic(func_write0_with_msg_logic), fxptr_reade0_with_msg_logic(func_reade0_with_msg_logic)
{
    assert(thiz_underlying != nullptr);
    assert(false                                                                                             //
           || (this->fxptr_write0_with_msg_logic == nullptr && this->fxptr_reade0_with_msg_logic != nullptr) //
           || (this->fxptr_write0_with_msg_logic != nullptr && this->fxptr_reade0_with_msg_logic != nullptr) //
    );
    this->m_logger = ext::spdlog0::FX_logger_factory(this);
}

/// EzV4_TcpSocketerSync_V - 02
// X EzV4_TcpSocketerSync_V - fv_is_ready(), fv_break_sync_block(),
auto                         //
    nscxx_root::             //
    EzV4_TcpSocketerSync_V:: //
    fv_is_ready() const -> bool
{
    return thiz_underlying->m_is_ready;
}
auto                         //
    nscxx_root::             //
    EzV4_TcpSocketerSync_V:: //
    fv_xxxxx_sync_cancel() -> void
{
    auto lock = std::lock_guard(this->m_mutex_sync_break_only);
    thiz_underlying->fv_xxxxx_sync_cancel_0_without_mutex();
}
// X EzV4_TcpSocketerSync_V - fv_write(), fv_reade(),
auto                         //
    nscxx_root::             //
    EzV4_TcpSocketerSync_V:: //
    fv_write_sync(std::span<std::byte> span, std::optional<std::chrono::seconds> timeout) -> std::size_t
{
    auto lock = std::lock_guard(this->m_mutex_sync);
    auto result = std::size_t();
    if (not thiz_underlying->m_is_ready)
    {
        throw std::runtime_error(nscxx::log::CS_EXCEPTION_MSG_0B16CF5C);
    }
    if (this->fxptr_write0_with_msg_logic == nullptr)
    {
        result = thiz_underlying->fv_write_sync_0_without_mutex(span, timeout);
    }
    else
    {
        result = this->fxptr_write0_with_msg_logic(*thiz_underlying, span, timeout);
    }
    this->fv_hook_log_0_action_post(EnumTcpSocketAction::WRITE, span.subspan(0, result));
    return result;
}
auto                         //
    nscxx_root::             //
    EzV4_TcpSocketerSync_V:: //
    fv_reade_sync(std::span<std::byte> span, std::optional<std::chrono::seconds> timeout) -> std::size_t
{
    auto lock = std::lock_guard(this->m_mutex_sync);
    auto result = std::size_t();
    if (not thiz_underlying->m_is_ready)
    {
        throw std::runtime_error(nscxx::log::CS_EXCEPTION_MSG_0B16CF5C);
    }
    if (this->fxptr_reade0_with_msg_logic == nullptr)
    {
        result = thiz_underlying->fv_reade_sync_0_without_mutex(span, timeout);
    }
    else
    {
        result = this->fxptr_reade0_with_msg_logic(*thiz_underlying, span, timeout);
    }
    this->fv_hook_log_0_action_post(EnumTcpSocketAction::READE, span.subspan(0, result));
    return result;
}
// X EzV4_TcpSocketerSync_V - fv_start(), fv_close(), fv_reset(),
auto                         //
    nscxx_root::             //
    EzV4_TcpSocketerSync_V:: //
    fv_start_sync(std::optional<std::chrono::seconds> timeout) -> bool
{
    auto lock = std::lock_guard(this->m_mutex_sync);
    auto result = bool();
    if (not thiz_underlying->m_is_ready)
    {
        result = thiz_underlying->fv_start_sync_0_without_mutex(timeout);
    }
    else
    {
        result = false;
    }
    return result;
}
auto                         //
    nscxx_root::             //
    EzV4_TcpSocketerSync_V:: //
    fv_close_sync(std::optional<std::chrono::seconds> timeout) -> bool
{
    auto lock = std::lock_guard(this->m_mutex_sync);
    auto result = bool();
    if (not thiz_underlying->m_is_ready)
    {
        result = false;
    }
    else
    {
        result = thiz_underlying->fv_close_sync_0_without_mutex(timeout);
    }
    return result;
}
auto                         //
    nscxx_root::             //
    EzV4_TcpSocketerSync_V:: //
    fv_reset_sync(std::optional<std::chrono::seconds> timeout) -> bool
{
    auto lock = std::lock_guard(this->m_mutex_sync);
    auto result = bool();
    if (not thiz_underlying->m_is_ready)
    {
        result = thiz_underlying->fv_start_sync_0_without_mutex(timeout);
    }
    else
    {
        result = thiz_underlying->fv_reset_sync_0_without_mutex(timeout);
    }
    return result;
}

/// EzV4_TcpSocketerSync_V - 03
auto                         //
    nscxx_root::             //
    EzV4_TcpSocketerSync_V:: //
    fv_hook_log_0_action_post(EnumTcpSocketAction tcp_action, std::span<std::byte> span) -> void
{
    static auto const func_make_logmark01_direction = [](EnumTcpEndpointSide tcp_side, EnumTcpSocketAction tcp_action) -> std::string_view {
        auto strv = std::string_view();
        if constexpr (false)
        {
            ;
        }
        else if (tcp_side == EnumTcpEndpointSide::SERVER && tcp_action == EnumTcpSocketAction::READE)
        {
            strv = "#->S";
        }
        else if (tcp_side == EnumTcpEndpointSide::SERVER && tcp_action == EnumTcpSocketAction::WRITE)
        {
            strv = "#<-S";
        }
        else if (tcp_side == EnumTcpEndpointSide::CLIENT && tcp_action == EnumTcpSocketAction::READE)
        {
            strv = "C<-#";
        }
        else if (tcp_side == EnumTcpEndpointSide::CLIENT && tcp_action == EnumTcpSocketAction::WRITE)
        {
            strv = "C->#";
        }
        else
        {
            strv = "####";
        }
        return strv;
    };
    if (this->m_logger->should_log(spdlog::level::level_enum::info))
    {
        this->m_logger->info("[{:s}] {:Xnsp}", func_make_logmark01_direction(thiz_underlying->m_tcp_ep_side, tcp_action), spdlog::to_hex(span));
    }
}

/// EzV4_TcpSocketerSync_V::Underlying_V
/*Constructor*/                            //
nscxx_root::                               //
    EzV4_TcpSocketerSync_V::Underlying_V:: //
    Underlying_V(EnumTcpEndpointSide tcp_ep_side)
    : m_tcp_ep_side(tcp_ep_side)
{
}
