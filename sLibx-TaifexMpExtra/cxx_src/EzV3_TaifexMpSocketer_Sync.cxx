#include "xplum_sdkit/taifex_msg_proto/network/EzV3_TaifexMpSocketer_Sync.h"
#pragma
#
#include <spdlog/fmt/bin_to_hex.h>
#include "xplum_model/taifex_msg_proto/network_osi_L06/constant_msg.h"
#include "xplum_sdkit/taifex_msg_proto/static_function_msg.h"
#

namespace nscxx_root = xplum_sdkit::taifex_msg_proto::network;
namespace nscxx::log
{
static auto CS_EXCEPTION_MSG_A05F975A = "EXCEPTION_MSG_A05F975A: tcp_endpoint_reset_failed,";
}
namespace nscxx
{
using ext::boost_asio0::EnumTcpSocketAction;
using ext::boost_asio0::EumeTcpEndpointSide;
using xplum_model::taifex_msg_proto::message_field::enumerate::MessageType;
static auto FX_to_string(MessageType) -> std::string_view;
static auto FX_log_mark01_direction(EumeTcpEndpointSide, EnumTcpSocketAction) -> const std::string_view;
}

/// EzV3_TaifexMpSocketer_Sync
/*Constructor*/                  //
nscxx_root::                     //
    EzV3_TaifexMpSocketer_Sync:: //
    EzV3_TaifexMpSocketer_Sync(EumeTcpEndpointSide tcp_ep_side, std::string_view tcp_ep_host, std::string_view tcp_ep_port)
    : EzV3_TcpSocketerSyncBy_BoostAsio(tcp_ep_side, tcp_ep_host, tcp_ep_port)
{
}
auto                             //
    nscxx_root::                 //
    EzV3_TaifexMpSocketer_Sync:: //
    fv_tcp_action_0_post_log(ext::boost_asio0::EnumTcpSocketAction tcp_action, std::span<std::byte> span) -> void
{
    if (this->m_logger->should_log(spdlog::level::level_enum::info))
    {
        this->m_logger->info(                                                                                                                   //
            "[{:s}][{:s}] {:Xnsp}",                                                                                                             //
            nscxx::FX_log_mark01_direction(this->m_tcp_ep_side, tcp_action),                                                                    //
            nscxx::FX_to_string(span.empty() ? nscxx::MessageType() : ez_view::FX_GET_MSG_TYPE_IN_ORIGIN_MSG_1CONST(span.data()).enum_value()), //
            spdlog::to_hex(span)                                                                                                                //
        );
    }
}

/// EzV3_TaifexMpSocketer_Sync - 02
auto                             //
    nscxx_root::                 //
    EzV3_TaifexMpSocketer_Sync:: //
    fv_tcp_action(ext::boost_asio0::EnumTcpSocketAction tcp_action, std::span<std::byte> span, std::optional<std::chrono::seconds> timeout) -> std::size_t
{
    using ext::boost_asio0::EnumTcpSocketAction;
    auto result = std::size_t();
    if constexpr (true)
    {
        switch (tcp_action)
        {
        case EnumTcpSocketAction::READE:
            result = this->fx_tcp_action_0_reade_msg(span, timeout);
            break;
        case EnumTcpSocketAction::WRITE:
            result = this->fx_tcp_action_0_write_msg(span, timeout);
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
            result = this->fx_tcp_action_0_reade_msg(span, timeout);
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
auto                             //
    nscxx_root::                 //
    EzV3_TaifexMpSocketer_Sync:: //
    fx_tcp_action_0_reade_msg(std::span<std::byte> span, std::optional<std::chrono::seconds> timeout) -> std::size_t
{
    namespace nsfunc = xplum_model::taifex_msg_proto;
    auto sizeof_reade = std::size_t();
    auto msg_length = type::TypeMsgLength();
    //
    assert(span.size() >= nsfunc::msg_sizeof_transfer_buffer::G_size_min_of_read_msg);
    sizeof_reade += this->fv_reade0(span.subspan(0, nsfunc::msg_sizeof_transfer_buffer::G_size_min_of_read_msg), timeout);
    msg_length = (sizeof_reade == 0) ? 0 : static_cast<type::TypeMsgLength>(ez_view::FX_GET_MSG_LENGTH_IN_ORIGIN_MSG_1CONST(span.data()));
    assert(span.size() >= nsfunc::msg_sizeof_transfer_buffer::G_size_min_of_read_msg + msg_length);
    sizeof_reade += this->fv_reade0(span.subspan(nsfunc::msg_sizeof_transfer_buffer::G_size_min_of_read_msg, msg_length), std::nullopt);
    assert(sizeof_reade == 0 || sizeof_reade == nsfunc::msg_sizeof_transfer_buffer::G_size_min_of_read_msg + msg_length);
    return sizeof_reade;
}
auto                             //
    nscxx_root::                 //
    EzV3_TaifexMpSocketer_Sync:: //
    fx_tcp_action_0_write_msg(std::span<std::byte> span, std::optional<std::chrono::seconds> timeout) -> std::size_t
{
    namespace nsfunc = xplum_model::taifex_msg_proto;
    auto sizeof_write = std::size_t();
    //
    assert(span.size() >= nsfunc::msg_sizeof_transfer_buffer::G_size_min_of_read_msg + ez_view::FX_GET_MSG_LENGTH_IN_ORIGIN_MSG_1CONST(span.data()));
    span = span.subspan(0, (nsfunc::msg_sizeof_transfer_buffer::G_size_min_of_read_msg + ez_view::FX_GET_MSG_LENGTH_IN_ORIGIN_MSG_1CONST(span.data())));
    sizeof_write = this->fv_write0(span, timeout);
    assert(span.size() == sizeof_write);
    return sizeof_write;
}

/// namespace nscxx
static auto nscxx::FX_to_string(MessageType enum_msg_type) -> std::string_view
{
    switch (enum_msg_type)
    {
        // clang-format off
#define MACRO_XPLUM_SWITCH_CASE(PARAM01_ENUM_MEMBER) case MessageType::PARAM01_ENUM_MEMBER: return #PARAM01_ENUM_MEMBER;
        // clang-format on
        MACRO_XPLUM_SWITCH_CASE(L10)
        MACRO_XPLUM_SWITCH_CASE(L20)
        MACRO_XPLUM_SWITCH_CASE(L30)
        MACRO_XPLUM_SWITCH_CASE(L40)
        MACRO_XPLUM_SWITCH_CASE(L41)
        MACRO_XPLUM_SWITCH_CASE(L42)
        MACRO_XPLUM_SWITCH_CASE(L50)
        MACRO_XPLUM_SWITCH_CASE(L60)
#undef MACRO_XPLUM_SWITCH_CASE
    [[unlikely]] default:
        return "???";
    }
}
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
