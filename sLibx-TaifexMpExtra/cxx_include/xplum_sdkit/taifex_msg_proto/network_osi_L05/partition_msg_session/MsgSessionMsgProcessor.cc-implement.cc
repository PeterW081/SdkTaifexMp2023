#pragma once
#include "./MsgSessionMsgProcessor.h"
#pragma
#include "xplum_sdkit/taifex_msg_proto/network_osi_L06/reference_msg_view_plugin/PlugerMsg_Common.h"
#

///
#define nshdr_root xplum_sdkit::taifex_msg_proto
#

/// MsgSessionMsgProcessor - fx_msg_process_0_write_prep()
template <nshdr_root::enumerate::EnumMsgType ENUM_msg_type>
auto                         //
    nshdr_root::util::       //
    MsgSessionMsgProcessor:: //
    fx_msg_process_0_write_prep(std::span<std::byte> data) -> void
{
    auto msg_view = view::FX_init_msg_to_span<ENUM_msg_type>(data);
    this->fxUnit_msg_process<decltype(msg_view), EnumMsgSocketAction::WRITE_PREP>(msg_view);
    {
        static_assert(std::is_base_of_v<view::message_plugin::PlugerMsg_Common<decltype(msg_view)>, decltype(msg_view)>);
        auto &msg_view0 = static_cast<view::message_plugin::PlugerMsg_Common<decltype(msg_view)> &>(msg_view);
        msg_view0.fx_assign_m_fcm_id_session_id(this->m_msg_session_context->m_fcm_id, this->m_msg_session_context->m_session_id);
        msg_view0.fx_assign_m_msg_time_0_time_now();
        msg_view0.fx_assign_m_check_sum_0_algorithm();
    }
}
template <>
inline auto                  //
    nshdr_root::util::       //
    MsgSessionMsgProcessor:: //
    fx_msg_process_0_write_prep<nshdr_root::enumerate::EnumMsgType::L41>(std::span<std::byte> data) -> void
{
    namespace nsfunc_msg_sizeof_content = xplum_model::taifex_msg_proto::msg_sizeof_content;
    //
    assert(this->m_msg_session_context_re_server != nullptr);
    auto msg_length = this->m_msg_session_context_re_server->fx_get_msg_L41Data_size_MOCK() + nsfunc_msg_sizeof_content::G_value_min_of_msg_length_L41;
    //
    auto msg_view = view::FX_init_msg_to_span<nshdr_root::enumerate::EnumMsgType::L41>(data, msg_length);
    this->fxUnit_msg_process_0_L41_write_prep(msg_view);
    {
        static_assert(std::is_base_of_v<view::message_plugin::PlugerMsg_Common<decltype(msg_view)>, decltype(msg_view)>);
        auto &msg_view0 = static_cast<view::message_plugin::PlugerMsg_Common<decltype(msg_view)> &>(msg_view);
        msg_view0.fx_assign_m_msg_time_0_time_now();
        msg_view0.fx_assign_m_check_sum_0_algorithm();
    }
}

/// MsgSessionMsgProcessor - fx_msg_process_0_reade_post()
template <nshdr_root::enumerate::EnumMsgType ENUM_msg_type>
auto                         //
    nshdr_root::util::       //
    MsgSessionMsgProcessor:: //
    fx_msg_process_0_reade_post(std::span<std::byte> data) -> void
{
    auto msg_view = view::FX_load_msg_on_span<ENUM_msg_type>(data);
    assert(msg_view.m_hdr.m_message_type.enum_value() == ENUM_msg_type);
    {
        static_assert(std::is_base_of_v<view::message_plugin::PlugerMsg_Common<decltype(msg_view)>, decltype(msg_view)>);
        auto &msg_view0 = static_cast<view::message_plugin::PlugerMsg_Common<decltype(msg_view)> &>(msg_view);
        assert(msg_view0.fx_assert_m_check_sum());
    }
    this->fxUnit_msg_process<decltype(msg_view), EnumMsgSocketAction::READE_POST>(msg_view);
}

///
#
#undef nshdr_root
