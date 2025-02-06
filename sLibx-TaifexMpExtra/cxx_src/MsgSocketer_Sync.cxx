#include "xplum_sdkit/taifex_msg_proto/network_osi_L05/partition_msg_session/MsgSocketer_Sync.h"
#pragma
#
#include <spdlog/fmt/bin_to_hex.h>
#include "xplum_model/taifex_msg_proto/network_osi_L06/constant_msg.h"
#include "xplum_sdkit/taifex_msg_proto/network_osi_L06/function_msg.h"
#

namespace nscxx_root = xplum_sdkit::taifex_msg_proto::network;
namespace nscxx::log
{
static auto CS_EXCEPTION_MSG_A05F975A = "EXCEPTION_MSG_A05F975A: tcp_endpoint_reset_failed,";
}
namespace nscxx
{
using ext::boost_asio0::EnumTcpEndpointSide;
using ext::boost_asio0::EnumTcpSocketAction;
using ext::boost_asio0::EzV4_TcpSocketerSync_V;
using ext::boost_asio0::EzV4_TcpSocketerSyncBoostAsio;
using xplum_model::taifex_msg_proto::message_field::enumerate::MessageType;
}

/// EzV4_MsgSocketer_Sync - static
auto                        //
    nscxx_root::            //
    EzV4_MsgSocketer_Sync:: //
    FX_tcp_action_0_write_msg(Underlying_V &thiz_underlying, std::span<std::byte> span, std::optional<std::chrono::seconds> timeout) -> std::size_t
{
    namespace nsfunc = xplum_model::taifex_msg_proto;
    auto sizeof_write = std::size_t();
    //
    assert(span.size() >= nsfunc::msg_sizeof_transfer_buffer::G_size_min_of_read_msg + ez_view::FX_get_msg_length_from_msg_data(span.data()));
    span = span.subspan(0, (nsfunc::msg_sizeof_transfer_buffer::G_size_min_of_read_msg + ez_view::FX_get_msg_length_from_msg_data(span.data())));
    sizeof_write = thiz_underlying.fv_write_sync_0_without_mutex(span, timeout);
    assert(sizeof_write == 0 || sizeof_write == span.size());
    return sizeof_write;
}
auto                        //
    nscxx_root::            //
    EzV4_MsgSocketer_Sync:: //
    FX_tcp_action_0_reade_msg(Underlying_V &thiz_underlying, std::span<std::byte> span, std::optional<std::chrono::seconds> timeout) -> std::size_t
{
    namespace nsfunc = xplum_model::taifex_msg_proto;
    auto sizeof_reade = std::size_t();
    auto msg_length = type::TypeMsgLength();
    //
    assert(span.size() >= nsfunc::msg_sizeof_transfer_buffer::G_size_min_of_read_msg);
    sizeof_reade += thiz_underlying.fv_reade_sync_0_without_mutex(span.subspan(0, nsfunc::msg_sizeof_transfer_buffer::G_size_min_of_read_msg), timeout);
    msg_length = (sizeof_reade == 0) ? 0 : static_cast<type::TypeMsgLength>(ez_view::FX_get_msg_length_from_msg_data(span.data()));
    assert(span.size() >= nsfunc::msg_sizeof_transfer_buffer::G_size_min_of_read_msg + msg_length);
    sizeof_reade += thiz_underlying.fv_reade_sync_0_without_mutex(span.subspan(nsfunc::msg_sizeof_transfer_buffer::G_size_min_of_read_msg, msg_length), std::nullopt);
    assert(sizeof_reade == 0 || sizeof_reade == nsfunc::msg_sizeof_transfer_buffer::G_size_min_of_read_msg + msg_length);
    return sizeof_reade;
}

/// EzV4_MsgSocketer_Sync
/*Constructor*/             //
nscxx_root::                //
    EzV4_MsgSocketer_Sync:: //
    EzV4_MsgSocketer_Sync(nscxx::EnumTcpEndpointSide tcp_ep_side, std::string_view tcp_ep_host, std::string_view tcp_ep_port)
    : nscxx::EzV4_TcpSocketerSync_V( //
          std::make_unique<Underlying_IMPL>(tcp_ep_side, tcp_ep_host, tcp_ep_port), FX_tcp_action_0_write_msg, FX_tcp_action_0_reade_msg)
{
}
auto                        //
    nscxx_root::            //
    EzV4_MsgSocketer_Sync:: //
    fv_hook_log_0_action_post(ext::boost_asio0::EnumTcpSocketAction tcp_action, std::span<std::byte> span) -> void
{
    static auto const func_make_logmark01_direction = [](nscxx::EnumTcpEndpointSide tcp_side, nscxx::EnumTcpSocketAction tcp_action) -> std::string_view {
        auto strv = std::string_view();
        if constexpr (false)
        {
            ;
        }
        else if (tcp_side == nscxx::EnumTcpEndpointSide::SERVER && tcp_action == nscxx::EnumTcpSocketAction::READE)
        {
            strv = "#->S";
        }
        else if (tcp_side == nscxx::EnumTcpEndpointSide::SERVER && tcp_action == nscxx::EnumTcpSocketAction::WRITE)
        {
            strv = "#<-S";
        }
        else if (tcp_side == nscxx::EnumTcpEndpointSide::CLIENT && tcp_action == nscxx::EnumTcpSocketAction::READE)
        {
            strv = "C<-#";
        }
        else if (tcp_side == nscxx::EnumTcpEndpointSide::CLIENT && tcp_action == nscxx::EnumTcpSocketAction::WRITE)
        {
            strv = "C->#";
        }
        else
        {
            strv = "####";
        }
        return strv;
    };
    static auto const func_make_logmark02_msg_type = [](nscxx::MessageType enum_msg_type) -> std::string_view {
        switch (enum_msg_type)
        {
            // clang-format off
#define MACRO_XPLUM_SWITCH_CASE(PARAM01_ENUM_MEMBER) case nscxx::MessageType::PARAM01_ENUM_MEMBER: return #PARAM01_ENUM_MEMBER;
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
    };
    if (this->m_logger->should_log(spdlog::level::level_enum::info))
    {
        this->m_logger->info(                                                                                                                     //
            "[{:s}][{:s}] {:Xnsp}",                                                                                                               //
            func_make_logmark01_direction(thiz_underlying->m_tcp_ep_side, tcp_action),                                                            //
            func_make_logmark02_msg_type(span.empty() ? nscxx::MessageType() : ez_view::FX_get_msg_type_from_msg_data(span.data()).enum_value()), //
            spdlog::to_hex(span)                                                                                                                  //
        );
    }
}
