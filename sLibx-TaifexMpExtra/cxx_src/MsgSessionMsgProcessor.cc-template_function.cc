#include "xplum_sdkit/taifex_msg_proto/network_osi_L05/partition_msg_session/MsgSessionMsgProcessor.h"
#pragma
#

///
#define MACRO_EnumMsgSocketAction xplum_sdkit::taifex_msg_proto::util::MsgSessionMsgProcessor::EnumMsgSocketAction
#
namespace nscxx_root = xplum_sdkit::taifex_msg_proto::util;
namespace nscxx
{
using namespace xplum_sdkit::taifex_msg_proto::view::message;
}

/// MsgSessionMsgProcessor - fxUnit_msg_process() - Lxx
// X MsgSessionMsgProcessor - fxUnit_msg_process() - L10
template <>
auto                         //
    nscxx_root::             //
    MsgSessionMsgProcessor:: //
    fxUnit_msg_process<nscxx::MsgL10_VIEW, MACRO_EnumMsgSocketAction::WRITE_PREP>(nscxx::MsgL10_VIEW &msg_view) -> void
{
    msg_view.fx_assign_m_fcm_id_session_id(this->m_msg_session_context->m_fcm_id, this->m_msg_session_context->m_session_id);
}
template <>
auto                         //
    nscxx_root::             //
    MsgSessionMsgProcessor:: //
    fxUnit_msg_process<nscxx::MsgL10_VIEW, MACRO_EnumMsgSocketAction::READE_POST>(nscxx::MsgL10_VIEW &msg_view) -> void
{
    switch (this->m_msg_ep_side)
    {
    case decltype(this->m_msg_ep_side)::SERVER:
        this->m_msg_session_context->m_fcm_id = msg_view.m_hdr.m_fcm_id;
        this->m_msg_session_context->m_session_id = msg_view.m_hdr.m_session_id;
        break;
    case decltype(this->m_msg_ep_side)::CLIENT:
        break;
    default:
        break;
    }
}
// X MsgSessionMsgProcessor - fxUnit_msg_process() - L20
template <>
auto                         //
    nscxx_root::             //
    MsgSessionMsgProcessor:: //
    fxUnit_msg_process<nscxx::MsgL20_VIEW, MACRO_EnumMsgSocketAction::WRITE_PREP>(nscxx::MsgL20_VIEW &) -> void
{
    // NOOP
}
template <>
auto                         //
    nscxx_root::             //
    MsgSessionMsgProcessor:: //
    fxUnit_msg_process<nscxx::MsgL20_VIEW, MACRO_EnumMsgSocketAction::READE_POST>(nscxx::MsgL20_VIEW &) -> void
{
    // NOOP
}
// X MsgSessionMsgProcessor - fxUnit_msg_process() - L30
template <>
auto                         //
    nscxx_root::             //
    MsgSessionMsgProcessor:: //
    fxUnit_msg_process<nscxx::MsgL30_VIEW, MACRO_EnumMsgSocketAction::WRITE_PREP>(nscxx::MsgL30_VIEW &msg_view) -> void
{
    // trade_system_type
    msg_view.m_system_type.operator_assign(this->m_msg_session_context->m_trade_system_type);
    // secrecy: append_no
    auto append_no = this->m_msg_session_context_re_server->fx_mk_append_no_with_random();
    this->m_msg_session_context->m_secrecy.m_append_no = append_no;
    msg_view.m_append_no = append_no;
}
template <>
auto                         //
    nscxx_root::             //
    MsgSessionMsgProcessor:: //
    fxUnit_msg_process<nscxx::MsgL30_VIEW, MACRO_EnumMsgSocketAction::READE_POST>(nscxx::MsgL30_VIEW &msg_view) -> void
{
    // trade_system_type
    this->m_msg_session_context->m_trade_system_type = msg_view.m_system_type.enum_value();
    // secrecy: append_no
    this->m_msg_session_context->m_secrecy.m_append_no = msg_view.m_append_no;
}
// X MsgSessionMsgProcessor - fxUnit_msg_process() - L40
template <>
auto                         //
    nscxx_root::             //
    MsgSessionMsgProcessor:: //
    fxUnit_msg_process<nscxx::MsgL40_VIEW, MACRO_EnumMsgSocketAction::WRITE_PREP>(nscxx::MsgL40_VIEW &msg_view) -> void
{
    auto &msg_sesion_context = this->m_msg_session_context.operator*();

    /// MsgL40
    // X MsgL40 - 1/3
    auto is_ok = false;
    msg_view.m_append_no = msg_sesion_context.m_secrecy.m_append_no.value();
    is_ok = msg_view.fx_assign_m_key_value_0_algorithm(msg_sesion_context.m_secrecy.m_fcm_passwd.value(), msg_sesion_context.m_secrecy.m_append_no.value());
    msg_sesion_context.m_secrecy.m_fcm_passwd = std::nullopt;
    msg_sesion_context.m_secrecy.m_append_no = std::nullopt;
    assert(is_ok);
    // X MsgL40 - 2/3
    msg_view.m_system_type.operator_assign(msg_sesion_context.m_trade_system_type);
    msg_view.m_request_start_seq = msg_sesion_context.m_request_start_seq;
    msg_view.m_ap_code = msg_sesion_context.m_ap_code;
    msg_view.m_cancel_order_sec = msg_sesion_context.m_cancel_order_sec;
    // X MsgL40 - 3/3
    msg_view.m_fcm_id = msg_sesion_context.m_fcm_id;
    msg_view.m_session_id = msg_sesion_context.m_session_id;
}
template <>
auto                         //
    nscxx_root::             //
    MsgSessionMsgProcessor:: //
    fxUnit_msg_process<nscxx::MsgL40_VIEW, MACRO_EnumMsgSocketAction::READE_POST>(nscxx::MsgL40_VIEW &msg_view) -> void
{
    namespace nsfunc0_msg_algorithm = xplum_model::taifex_msg_proto::msg_algorithm;
    auto &msg_sesion_context = this->m_msg_session_context.operator*();
    auto &msg_sesion_context_re_server = this->m_msg_session_context_re_server.operator*();

    /// MsgL40
    // X MsgL40 - 1/2
    msg_sesion_context.m_request_start_seq = msg_view.m_request_start_seq;
    // X MsgL40 - 2/2
    auto is_ok = true;
    auto fcm_passwd = msg_sesion_context_re_server.fx_get_fcm_passwd_MOCK(msg_view.m_fcm_id, msg_sesion_context.m_secrecy.m_fcm_passwd.value_or(0));
    msg_sesion_context.m_secrecy.m_fcm_passwd = fcm_passwd;
    is_ok &= is_ok && msg_sesion_context.m_secrecy.m_append_no.has_value();
    is_ok &= is_ok && msg_sesion_context.m_secrecy.m_fcm_passwd.has_value();
    is_ok &= is_ok && msg_sesion_context_re_server.fx_is_allow_login_fcm_session_MOCK(msg_view.m_fcm_id, msg_view.m_session_id);
    is_ok &= is_ok && (msg_view.m_append_no == msg_sesion_context.m_secrecy.m_append_no.value());
    is_ok &= is_ok && msg_view.fx_assert_m_key_value(msg_sesion_context.m_secrecy.m_fcm_passwd.value(), msg_sesion_context.m_secrecy.m_append_no.value());
    if (not is_ok)
    {
        throw std::runtime_error("EXCEPTION_MSG_3EF33BB6: taifex_msg_proto, tcp_work_flow, business_wrong,");
    }
    msg_sesion_context.m_secrecy.m_append_no = std::nullopt;
    msg_sesion_context.m_secrecy.m_fcm_passwd = std::nullopt;
}
// X MsgSessionMsgProcessor - fxUnit_msg_process() - L41
template <>
auto                         //
    nscxx_root::             //
    MsgSessionMsgProcessor:: //
    fxUnit_msg_process<nscxx::MsgL41_VIEW, MACRO_EnumMsgSocketAction::WRITE_PREP>(nscxx::MsgL41_VIEW &) -> void
{
    throw std::logic_error("EXCEPTION_MSG_5218545A: not_yet_implemented, write_L41,");
}
template <>
auto                         //
    nscxx_root::             //
    MsgSessionMsgProcessor:: //
    fxUnit_msg_process<nscxx::MsgL41_VIEW, MACRO_EnumMsgSocketAction::READE_POST>(nscxx::MsgL41_VIEW &) -> void
{
    // NOOP
}
// X MsgSessionMsgProcessor - fxUnit_msg_process() - L42
template <>
auto                         //
    nscxx_root::             //
    MsgSessionMsgProcessor:: //
    fxUnit_msg_process<nscxx::MsgL42_VIEW, MACRO_EnumMsgSocketAction::WRITE_PREP>(nscxx::MsgL42_VIEW &) -> void
{
    // NOOP
}
template <>
auto                         //
    nscxx_root::             //
    MsgSessionMsgProcessor:: //
    fxUnit_msg_process<nscxx::MsgL42_VIEW, MACRO_EnumMsgSocketAction::READE_POST>(nscxx::MsgL42_VIEW &) -> void
{
    // NOOP
}
// X MsgSessionMsgProcessor - fxUnit_msg_process() - L50
template <>
auto                         //
    nscxx_root::             //
    MsgSessionMsgProcessor:: //
    fxUnit_msg_process<nscxx::MsgL50_VIEW, MACRO_EnumMsgSocketAction::WRITE_PREP>(nscxx::MsgL50_VIEW &) -> void
{
    // NOOP
}
template <>
auto                         //
    nscxx_root::             //
    MsgSessionMsgProcessor:: //
    fxUnit_msg_process<nscxx::MsgL50_VIEW, MACRO_EnumMsgSocketAction::READE_POST>(nscxx::MsgL50_VIEW &) -> void
{
    // NOOP
}
// X MsgSessionMsgProcessor - fxUnit_msg_process() - L60
template <>
auto                         //
    nscxx_root::             //
    MsgSessionMsgProcessor:: //
    fxUnit_msg_process<nscxx::MsgL60_VIEW, MACRO_EnumMsgSocketAction::WRITE_PREP>(nscxx::MsgL60_VIEW &) -> void
{
    this->m_msg_session_context->m_secrecy.fx_scrap();
}
template <>
auto                         //
    nscxx_root::             //
    MsgSessionMsgProcessor:: //
    fxUnit_msg_process<nscxx::MsgL60_VIEW, MACRO_EnumMsgSocketAction::READE_POST>(nscxx::MsgL60_VIEW &) -> void
{
    this->m_msg_session_context->m_secrecy.fx_scrap();
}
