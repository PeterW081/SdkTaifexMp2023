#include "boost0/asio/EzV3_TcpSocketerSync_V.h"
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
using ext::boost_asio0::EnumTcpSocketAction;
using ext::boost_asio0::EumeTcpEndpointSide;
static auto FX_log_mark01_direction(EumeTcpEndpointSide, EnumTcpSocketAction) -> const std::string_view;
}

/// EzV3_TcpSocketerSync_V
/*Constructor*/              //
nscxx_root::                 //
    EzV3_TcpSocketerSync_V:: //
    EzV3_TcpSocketerSync_V(EumeTcpEndpointSide tcp_ep_side)
    : m_tcp_ep_side(tcp_ep_side)
{
    this->m_logger = ext::spdlog0::FX_logger_factory(this);
}
auto                         //
    nscxx_root::             //
    EzV3_TcpSocketerSync_V:: //
    fv_reade(std::span<std::byte> span, std::optional<std::chrono::seconds> timeout) -> std::size_t
{
    auto lock = std::lock_guard(this->m_mutex_sync);
    if (not this->m_is_tcp_ep_ready)
    {
        throw std::runtime_error(nscxx::log::CS_EXCEPTION_MSG_0B16CF5C);
    }
    return this->fv_tcp_action(EnumTcpSocketAction::READE, span, timeout);
}
auto                         //
    nscxx_root::             //
    EzV3_TcpSocketerSync_V:: //
    fv_write(std::span<std::byte> span, std::optional<std::chrono::seconds> timeout) -> std::size_t
{
    auto lock = std::lock_guard(this->m_mutex_sync);
    if (not this->m_is_tcp_ep_ready)
    {
        throw std::runtime_error(nscxx::log::CS_EXCEPTION_MSG_0B16CF5C);
    }
    return this->fv_tcp_action(EnumTcpSocketAction::WRITE, span, timeout);
}
auto                         //
    nscxx_root::             //
    EzV3_TcpSocketerSync_V:: //
    fv_start(std::optional<std::chrono::seconds> timeout) -> bool
{
    auto lock = std::lock_guard(this->m_mutex_sync);
    auto result = bool();
    if (not this->m_is_tcp_ep_ready)
    {
        result = this->fv_start0(timeout);
    }
    else
    {
        result = false;
    }
    return result;
}
auto                         //
    nscxx_root::             //
    EzV3_TcpSocketerSync_V:: //
    fv_close(std::optional<std::chrono::seconds> timeout) -> bool
{
    auto lock = std::lock_guard(this->m_mutex_sync);
    auto result = bool();
    if (not this->m_is_tcp_ep_ready)
    {
        result = false;
    }
    else
    {
        result = this->fv_close0(timeout);
    }
    return result;
}
auto                         //
    nscxx_root::             //
    EzV3_TcpSocketerSync_V:: //
    fv_reset(std::optional<std::chrono::seconds> timeout) -> bool
{
    auto lock = std::lock_guard(this->m_mutex_sync);
    auto result = bool();
    if (not this->m_is_tcp_ep_ready)
    {
        result = this->fv_start0(timeout);
    }
    else
    {
        result = this->fv_reset0(timeout);
    }
    return result;
}

/// EzV3_TcpSocketerSync_V - 02
auto                         //
    nscxx_root::             //
    EzV3_TcpSocketerSync_V:: //
    fv_tcp_action(EnumTcpSocketAction tcp_action, std::span<std::byte> span, std::optional<std::chrono::seconds> timeout) -> std::size_t
{
    auto result = std::size_t();
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
    if (this->m_is_tcp_server_ought_reset && this->m_tcp_ep_side == EumeTcpEndpointSide::SERVER)
    {
        this->m_is_tcp_server_ought_reset = false;
        this->fv_reset0(timeout);
        if (not this->m_is_tcp_ep_ready)
        {
            throw std::runtime_error(nscxx::log::CS_EXCEPTION_MSG_A05F975A);
        }
    }
    this->fv_tcp_action_0_post_log(tcp_action, span.subspan(0, result));
    return result;
}
auto                         //
    nscxx_root::             //
    EzV3_TcpSocketerSync_V:: //
    fv_tcp_action_0_post_log(EnumTcpSocketAction tcp_action, std::span<std::byte> span) -> void
{
    if (this->m_logger->should_log(spdlog::level::level_enum::info))
    {
        this->m_logger->info("[{:s}] {:Xnsp}", nscxx::FX_log_mark01_direction(this->m_tcp_ep_side, tcp_action), spdlog::to_hex(span));
    }
}

/// namespace nscxx
static auto nscxx::FX_log_mark01_direction(EumeTcpEndpointSide tcp_side, EnumTcpSocketAction tcp_action) -> const std::string_view
{
    auto strv = std::string_view();
    if constexpr (false)
    {
        ;
    }
    else if (tcp_side == EumeTcpEndpointSide::SERVER && tcp_action == EnumTcpSocketAction::READE)
    {
        strv = "#->S";
    }
    else if (tcp_side == EumeTcpEndpointSide::SERVER && tcp_action == EnumTcpSocketAction::WRITE)
    {
        strv = "#<-S";
    }
    else if (tcp_side == EumeTcpEndpointSide::CLIENT && tcp_action == EnumTcpSocketAction::READE)
    {
        strv = "C<-#";
    }
    else if (tcp_side == EumeTcpEndpointSide::CLIENT && tcp_action == EnumTcpSocketAction::WRITE)
    {
        strv = "C->#";
    }
    else
    {
        strv = "####";
    }
    return strv;
}
