#include "xplum_sdkit/taifex_msg_proto/fsm/fsm_msg_transfer_flow.h"
#pragma

#include "xplum_sdkit/taifex_msg_proto/view02/msg_all_layer.h"

namespace nscxx_root = xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow;
namespace nscxx
{
using namespace xplum_model::taifex_msg_proto::algorithm;
using xplum_sdkit::taifex_msg_proto::kitbag::UnityTcpSession;
using MsgEnumType = xplum_sdkit::taifex_msg_proto::view::message_field::enumerate::MsgType::EnumType;

template <MsgEnumType, MsgEnumType> static inline auto FX_ASSERT_MSG_TYPE_OR_THROW_RUNTIME_EXCEPTION (void *) -> void;
static inline auto FX_IS_MSG_TYPE_L41 (void *) -> bool;

}
template <nscxx::MsgEnumType VALUE_MsgEnumType01, nscxx::MsgEnumType VALUE_MsgEnumType02 = VALUE_MsgEnumType01>
auto        //
    nscxx:: //
    FX_ASSERT_MSG_TYPE_OR_THROW_RUNTIME_EXCEPTION (void *data) -> void
{
  const auto var = xplum_sdkit::taifex_msg_proto::ez_view::FX_GET_MSG_TYPE_IN_ORIGIN_MSG_1CONST (data).enum_value ();
  auto is_throw_exception = false;
  if constexpr (VALUE_MsgEnumType01 == VALUE_MsgEnumType02)
    {
      is_throw_exception = (VALUE_MsgEnumType01 != var);
    }
  else
    {
      is_throw_exception = (VALUE_MsgEnumType01 != var && VALUE_MsgEnumType02 != var);
    }
  if (is_throw_exception)
    {
      throw std::runtime_error ("EXCEPTION_MSG_8F4C5734: taifex_msg_proto, tcp_reade, msg_type_is_wrong,");
    }
}
auto        //
    nscxx:: //
    FX_IS_MSG_TYPE_L41 (void *data) -> bool
{
  return (MsgEnumType::L41 == xplum_sdkit::taifex_msg_proto::ez_view::FX_GET_MSG_TYPE_IN_ORIGIN_MSG_1CONST (data).enum_value ());
}

/// FsmAction
///

/// DoTransferReady
//- Client
auto                             //
    nscxx_root::element::        //
    FsmAction::DoTransferReady:: //
    fx_operator_tcp_client (CtrlHandle &ctrl) -> void
{
  auto &host = ctrl.m_unity->m_server_host;
  auto &port = ctrl.m_unity->m_server_port;
  ctrl.m_tcp_endpoint = std::make_shared<network::EzV2_TcpClientMsg_Sync> (host, port);

  auto tcp_read_timeout = std::chrono::seconds (nscxx::UnityTcpSession::M_LXX_LAYER_TIMEOUT_S);
  ctrl.m_tcp_endpoint->start (tcp_read_timeout);
}
//- Server
auto                             //
    nscxx_root::element::        //
    FsmAction::DoTransferReady:: //
    fx_operator_tcp_server (CtrlHandle &ctrl) -> void
{
  auto &host = ctrl.m_unity->m_server_host;
  auto &port = ctrl.m_unity->m_server_port;
  ctrl.m_tcp_endpoint = std::make_shared<network::EzV2_TcpServerMsg_Sync> (host, port);

  auto tcp_read_timeout = std::chrono::seconds (nscxx::UnityTcpSession::M_LXX_LAYER_TIMEOUT_S);
  ctrl.m_tcp_endpoint->start (tcp_read_timeout);
}

/// DoTransfer_L10_FromClient
//- Client
auto                                       //
    nscxx_root::element::                  //
    FsmAction::DoTransfer_L10_FromClient:: //
    fx_operator_tcp_client (CtrlHandle &ctrl) -> void
{
  /// note: tcp write L10

  auto &unity = ctrl.m_unity.operator* ();
  auto msg_view = view02::message::L10::FX_ASSIGN_MSG (std::span (ctrl.m_tcp_buffer_for_write));

  // meta: tcp write msg
  msg_view.m_hdr.m_fcm_id = unity.m_fcm_id;
  msg_view.m_hdr.m_session_id = unity.m_session_id;
  msg_view.fx_assign_m_msg_time_0_time_now ();
  msg_view.fx_assign_m_check_sum_0_algorithm ();
  ctrl.m_tcp_endpoint->write_msg (ctrl.m_tcp_buffer_for_write);
}
//- Server
auto                                       //
    nscxx_root::element::                  //
    FsmAction::DoTransfer_L10_FromClient:: //
    fx_operator_tcp_server (CtrlHandle &ctrl) -> void
{
  /// note: tcp reade L10

  // meta: tcp reade msg
  auto tcp_read_timeout = std::chrono::seconds (nscxx::UnityTcpSession::M_LXX_LAYER_TIMEOUT_S);
  ctrl.m_tcp_endpoint->reade_msg (ctrl.m_tcp_buffer_for_reade, tcp_read_timeout);
  nscxx::FX_ASSERT_MSG_TYPE_OR_THROW_RUNTIME_EXCEPTION<nscxx::MsgEnumType::L10> (ctrl.m_tcp_buffer_for_reade.data ());

  //
  auto &unity = ctrl.m_unity.operator* ();
  auto msg_view = view02::message::L10 (std::span (ctrl.m_tcp_buffer_for_reade));
  unity.m_fcm_id = msg_view.m_hdr.m_fcm_id;
  unity.m_session_id = msg_view.m_hdr.m_session_id;
}

/// DoTransfer_L10_FromServer
//- Client
auto                                       //
    nscxx_root::element::                  //
    FsmAction::DoTransfer_L10_FromServer:: //
    fx_operator_tcp_client (CtrlHandle &ctrl) -> void
{
  /// note: tcp reade L10

  // meta: tcp reade msg
  auto tcp_read_timeout = std::chrono::seconds (nscxx::UnityTcpSession::M_LXX_LAYER_TIMEOUT_S);
  ctrl.m_tcp_endpoint->reade_msg (ctrl.m_tcp_buffer_for_reade, tcp_read_timeout);
  nscxx::FX_ASSERT_MSG_TYPE_OR_THROW_RUNTIME_EXCEPTION<nscxx::MsgEnumType::L10> (ctrl.m_tcp_buffer_for_reade.data ());

  // fsm: ctrl flag
  ctrl.m_is_done_transfer_L10_from_server = true;
}
//- Server
auto                                       //
    nscxx_root::element::                  //
    FsmAction::DoTransfer_L10_FromServer:: //
    fx_operator_tcp_server (CtrlHandle &ctrl) -> void
{
  /// note: tcp write L10

  auto &unity = ctrl.m_unity.operator* ();
  auto msg_view = view02::message::L10::FX_ASSIGN_MSG (std::span (ctrl.m_tcp_buffer_for_write));

  // meta: tcp write msg
  msg_view.m_hdr.m_fcm_id = unity.m_fcm_id;
  msg_view.m_hdr.m_session_id = unity.m_session_id;
  msg_view.fx_assign_m_msg_time_0_time_now ();
  msg_view.fx_assign_m_check_sum_0_algorithm ();
  ctrl.m_tcp_endpoint->write_msg (ctrl.m_tcp_buffer_for_write);

  // fsm: ctrl flag
  ctrl.m_is_done_transfer_L10_from_server = true;
}

/// DoTransfer_L20
//- Client
auto                            //
    nscxx_root::element::       //
    FsmAction::DoTransfer_L20:: //
    fx_operator_tcp_client (CtrlHandle &ctrl) -> void
{
  /// note: tcp write L20

  auto &unity = ctrl.m_unity.operator* ();
  auto msg_view = view02::message::L20::FX_ASSIGN_MSG (std::span (ctrl.m_tcp_buffer_for_write));

  // meta: tcp write msg
  msg_view.m_hdr.m_fcm_id = unity.m_fcm_id;
  msg_view.m_hdr.m_session_id = unity.m_session_id;
  msg_view.fx_assign_m_msg_time_0_time_now ();
  msg_view.fx_assign_m_check_sum_0_algorithm ();
  ctrl.m_tcp_endpoint->write_msg (ctrl.m_tcp_buffer_for_write);
}
//- Server
auto                            //
    nscxx_root::element::       //
    FsmAction::DoTransfer_L20:: //
    fx_operator_tcp_server (CtrlHandle &ctrl) -> void
{
  /// note: tcp reade L20

  // meta: tcp reade msg
  auto tcp_read_timeout = std::chrono::seconds (nscxx::UnityTcpSession::M_LXX_LAYER_TIMEOUT_S);
  ctrl.m_tcp_endpoint->reade_msg (ctrl.m_tcp_buffer_for_reade, tcp_read_timeout);
  nscxx::FX_ASSERT_MSG_TYPE_OR_THROW_RUNTIME_EXCEPTION<nscxx::MsgEnumType::L20> (ctrl.m_tcp_buffer_for_reade.data ());
}

/// DoTransfer_L30
//- Client
auto                            //
    nscxx_root::element::       //
    FsmAction::DoTransfer_L30:: //
    fx_operator_tcp_client (CtrlHandle &ctrl) -> void
{
  /// note: tcp reade L30

  // meta: tcp reade msg
  auto tcp_read_timeout = std::chrono::seconds (nscxx::UnityTcpSession::M_LXX_LAYER_TIMEOUT_S);
  ctrl.m_tcp_endpoint->reade_msg (ctrl.m_tcp_buffer_for_reade, tcp_read_timeout);
  nscxx::FX_ASSERT_MSG_TYPE_OR_THROW_RUNTIME_EXCEPTION<nscxx::MsgEnumType::L30> (ctrl.m_tcp_buffer_for_reade.data ());

  auto &unity = ctrl.m_unity.operator* ();
  auto msg_view = view02::message::L30 (ctrl.m_tcp_buffer_for_reade);

  unity.m_secrecy.m_append_no = msg_view.m_append_no;
  unity.m_trade_system_type = msg_view.m_system_type.enum_value ();
}
//- Server
auto                            //
    nscxx_root::element::       //
    FsmAction::DoTransfer_L30:: //
    fx_operator_tcp_server (CtrlHandle &ctrl) -> void
{
  /// note: tcp write L30

  auto &unity = ctrl.m_unity.operator* ();
  auto &unity_re_server = ctrl.m_unity_re_server.operator* ();
  auto msg_view = view02::message::L30::FX_ASSIGN_MSG (std::span (ctrl.m_tcp_buffer_for_write));

  //
  msg_view.m_append_no = unity_re_server.fx_mk_append_no_with_random ();
  unity.m_secrecy.m_append_no = msg_view.m_append_no;

  // meta: tcp write msg
  msg_view.m_hdr.m_fcm_id = unity.m_fcm_id;
  msg_view.m_hdr.m_session_id = unity.m_session_id;
  msg_view.fx_assign_m_msg_time_0_time_now ();
  msg_view.fx_assign_m_check_sum_0_algorithm ();
  ctrl.m_tcp_endpoint->write_msg (ctrl.m_tcp_buffer_for_write);
}

/// DoTransfer_L40
//- Client
auto                            //
    nscxx_root::element::       //
    FsmAction::DoTransfer_L40:: //
    fx_operator_tcp_client (CtrlHandle &ctrl) -> void
{
  /// note: tcp write L40

  auto &unity = ctrl.m_unity.operator* ();
  auto msg_view = view02::message::L40::FX_ASSIGN_MSG (std::span (ctrl.m_tcp_buffer_for_write));

  // TaifexMp: L40 1/3
  auto is_ok = false;
  is_ok = msg_view.fx_assign_m_key_value_0_algorithm (unity.m_secrecy.m_fcm_passwd.value (), unity.m_secrecy.m_append_no.value ());
  msg_view.m_append_no = unity.m_secrecy.m_append_no.value ();
  unity.m_secrecy.m_fcm_passwd = std::nullopt;
  unity.m_secrecy.m_append_no = std::nullopt;
  if (not is_ok)
    {
      // TODO
    }

  // TaifexMp: L40 2/3
  msg_view.m_system_type.operator_assign (unity.m_trade_system_type);
  msg_view.m_request_start_seq = unity.m_request_start_seq;
  msg_view.m_ap_code = unity.m_ap_code;
  msg_view.m_cancel_order_sec = unity.m_cancel_order_sec;

  // TaifexMp: L40 3/3
  msg_view.m_fcm_id = unity.m_fcm_id;
  msg_view.m_session_id = unity.m_session_id;

  // meta: tcp write msg
  msg_view.m_hdr.m_fcm_id = unity.m_fcm_id;
  msg_view.m_hdr.m_session_id = unity.m_session_id;
  msg_view.fx_assign_m_msg_time_0_time_now ();
  msg_view.fx_assign_m_check_sum_0_algorithm ();
  ctrl.m_tcp_endpoint->write_msg (ctrl.m_tcp_buffer_for_write);
}
//- Server
auto                            //
    nscxx_root::element::       //
    FsmAction::DoTransfer_L40:: //
    fx_operator_tcp_server (CtrlHandle &ctrl) -> void
{
  /// note: tcp reade L40

  // meta: tcp reade msg
  auto tcp_read_timeout = std::chrono::seconds (nscxx::UnityTcpSession::M_LXX_LAYER_TIMEOUT_S);
  ctrl.m_tcp_endpoint->reade_msg (ctrl.m_tcp_buffer_for_reade, tcp_read_timeout);
  nscxx::FX_ASSERT_MSG_TYPE_OR_THROW_RUNTIME_EXCEPTION<nscxx::MsgEnumType::L40> (ctrl.m_tcp_buffer_for_reade.data ());

  //
  auto &unity = ctrl.m_unity.operator* ();
  auto &unity_re_server = ctrl.m_unity_re_server.operator* ();
  auto msg_view = view02::message::L40 (std::span (ctrl.m_tcp_buffer_for_reade));

  // TaifexMp: L40 1/2
  unity.m_request_start_seq = msg_view.m_request_start_seq;

  // TaifexMp: L40 2/2
  auto is_ok = true;
  unity.m_secrecy.m_fcm_passwd = unity_re_server.fx_get_fcm_passwd (unity.m_secrecy.m_fcm_passwd.value_or (0));
  is_ok &= is_ok && unity.m_secrecy.m_append_no.has_value ();
  is_ok &= is_ok && unity.m_secrecy.m_fcm_passwd.has_value ();
  is_ok &= is_ok && unity_re_server.fx_is_allow_login_fcm_session (msg_view.m_fcm_id, msg_view.m_session_id);
  is_ok &= is_ok && (msg_view.m_append_no == unity.m_secrecy.m_append_no.value ());
  is_ok &= is_ok && (msg_view.m_key_value == nscxx::FX_MSG_L40_KEY_VALUE (unity.m_secrecy.m_fcm_passwd.value (), unity.m_secrecy.m_append_no.value ()));
  if (not is_ok)
    {
      throw std::runtime_error ("EXCEPTION_MSG_3EF33BB6: taifex_msg_proto, tcp_work_flow, business_wrong,");
    }
  unity.m_secrecy.m_append_no = std::nullopt;
  unity.m_secrecy.m_fcm_passwd = std::nullopt;
}

/// DoTransfer_L42
//- Client
auto                            //
    nscxx_root::element::       //
    FsmAction::DoTransfer_L42:: //
    fx_operator_tcp_client (CtrlHandle &ctrl) -> void
{
  /// note: tcp write L42

  auto &unity = ctrl.m_unity.operator* ();
  auto msg_view = view02::message::L42::FX_ASSIGN_MSG (std::span (ctrl.m_tcp_buffer_for_write));

  // meta: tcp write msg
  msg_view.m_hdr.m_fcm_id = unity.m_fcm_id;
  msg_view.m_hdr.m_session_id = unity.m_session_id;
  msg_view.fx_assign_m_msg_time_0_time_now ();
  msg_view.fx_assign_m_check_sum_0_algorithm ();
  ctrl.m_tcp_endpoint->write_msg (ctrl.m_tcp_buffer_for_write);
}
//- Server
auto                            //
    nscxx_root::element::       //
    FsmAction::DoTransfer_L42:: //
    fx_operator_tcp_server (CtrlHandle &ctrl) -> void
{
  /// note: tcp reade L42

  // meta: tcp reade msg
  auto tcp_read_timeout = std::chrono::seconds (nscxx::UnityTcpSession::M_LXX_LAYER_TIMEOUT_S);
  ctrl.m_tcp_endpoint->reade_msg (ctrl.m_tcp_buffer_for_reade, tcp_read_timeout);
  nscxx::FX_ASSERT_MSG_TYPE_OR_THROW_RUNTIME_EXCEPTION<nscxx::MsgEnumType::L42> (ctrl.m_tcp_buffer_for_reade.data ());
}

/// DoTransfer_L60
//- Client
auto                            //
    nscxx_root::element::       //
    FsmAction::DoTransfer_L60:: //
    fx_operator_tcp_client (CtrlHandle &ctrl) -> void
{
  /// note: tcp write L60

  auto &unity = ctrl.m_unity.operator* ();
  auto msg_view = view02::message::L60::FX_ASSIGN_MSG (std::span (ctrl.m_tcp_buffer_for_write));

  // meta: tcp write msg
  msg_view.m_hdr.m_fcm_id = unity.m_fcm_id;
  msg_view.m_hdr.m_session_id = unity.m_session_id;
  msg_view.fx_assign_m_msg_time_0_time_now ();
  msg_view.fx_assign_m_check_sum_0_algorithm ();
  ctrl.m_tcp_endpoint->write_msg (ctrl.m_tcp_buffer_for_write);

  //
  ctrl.m_unity->m_secrecy.fx_scrap ();
}
//- Server
auto                            //
    nscxx_root::element::       //
    FsmAction::DoTransfer_L60:: //
    fx_operator_tcp_server (CtrlHandle &ctrl) -> void
{
  /// note: tcp reade L60

  // meta: tcp reade msg
  auto tcp_read_timeout = std::chrono::seconds (nscxx::UnityTcpSession::M_LXX_LAYER_TIMEOUT_S);
  ctrl.m_tcp_endpoint->reade_msg (ctrl.m_tcp_buffer_for_reade, tcp_read_timeout);
  nscxx::FX_ASSERT_MSG_TYPE_OR_THROW_RUNTIME_EXCEPTION<nscxx::MsgEnumType::L60> (ctrl.m_tcp_buffer_for_reade.data ());

  //
  ctrl.m_unity->m_secrecy.fx_scrap ();
}

/// DoTransfer_OR_L41_L50
//- Client
auto                                   //
    nscxx_root::element::              //
    FsmAction::DoTransfer_OR_L41_L50:: //
    fx_operator_tcp_client (CtrlHandle &ctrl) -> void
{
  /// note: tcp reade L40,L50,

  // meta: tcp reade msg
  auto tcp_read_timeout = std::chrono::seconds (nscxx::UnityTcpSession::M_LXX_LAYER_TIMEOUT_S);
  ctrl.m_tcp_endpoint->reade_msg (ctrl.m_tcp_buffer_for_reade, tcp_read_timeout);
  nscxx::FX_ASSERT_MSG_TYPE_OR_THROW_RUNTIME_EXCEPTION<nscxx::MsgEnumType::L41, nscxx::MsgEnumType::L50> (ctrl.m_tcp_buffer_for_reade.data ());

  //
  auto msg_type = ez_view::FX_GET_MSG_TYPE_IN_ORIGIN_MSG_1CONST (ctrl.m_tcp_buffer_for_reade.data ()).enum_value ();
  switch (msg_type)
    {
    case decltype (msg_type)::L41:
      this->fx_transfer_L41_reade_postwork (ctrl);
      break;
    case decltype (msg_type)::L50:
      this->fx_transfer_L50_reade_postwork (ctrl);
      break;
    [[unlikely]] default:
      break;
    }

  // fsm: ctrl flag
  switch (msg_type)
    {
    case decltype (msg_type)::L41:
      ctrl.m_is_hold_L41 = true;
      break;
    case decltype (msg_type)::L50:
      ctrl.m_is_hold_L41 = false;
      ctrl.m_is_done_transfer_L50 = true;
      break;
    [[unlikely]] default:
      break;
    }
}
auto                                   //
    nscxx_root::element::              //
    FsmAction::DoTransfer_OR_L41_L50:: //
    fx_transfer_L41_reade_postwork (CtrlHandle &ctrl) -> void
{
  /// note: tcp reade L41
  nscxx::FX_ASSERT_MSG_TYPE_OR_THROW_RUNTIME_EXCEPTION<nscxx::MsgEnumType::L41> (ctrl.m_tcp_buffer_for_reade.data ());
}
auto                                   //
    nscxx_root::element::              //
    FsmAction::DoTransfer_OR_L41_L50:: //
    fx_transfer_L50_reade_postwork (CtrlHandle &ctrl) -> void
{
  /// note: tcp reade L50
  nscxx::FX_ASSERT_MSG_TYPE_OR_THROW_RUNTIME_EXCEPTION<nscxx::MsgEnumType::L50> (ctrl.m_tcp_buffer_for_reade.data ());
}
//- Server
auto                                   //
    nscxx_root::element::              //
    FsmAction::DoTransfer_OR_L41_L50:: //
    fx_operator_tcp_server (CtrlHandle &ctrl) -> void
{
  /// note: tcp write L41,L50,

  auto &unity = ctrl.m_unity.operator* ();
  auto &unity_re_server = ctrl.m_unity_re_server.operator* ();

  auto msg_type = unity_re_server.fx_is_have_L41 (unity.m_request_start_seq) ? nscxx::MsgEnumType::L41 : nscxx::MsgEnumType::L50;
  switch (msg_type)
    {
    case decltype (msg_type)::L41:
      this->fx_transfer_L41_write_prepwork (ctrl);
      break;
    case decltype (msg_type)::L50:
      this->fx_transfer_L50_write_prepwork (ctrl);
      break;
    [[unlikely]] default:
      break;
    }
  ctrl.m_tcp_endpoint->write_msg (ctrl.m_tcp_buffer_for_write);

  // fsm: ctrl flag
  switch (msg_type)
    {
    case decltype (msg_type)::L41:
      ctrl.m_is_hold_L41 = true;
      break;
    case decltype (msg_type)::L50:
      ctrl.m_is_hold_L41 = false;
      ctrl.m_is_done_transfer_L50 = true;
      break;
    [[unlikely]] default:
      break;
    }
}
auto                                   //
    nscxx_root::element::              //
    FsmAction::DoTransfer_OR_L41_L50:: //
    fx_transfer_L41_write_prepwork (CtrlHandle &ctrl) -> void
{
  /// note: tcp write L41
  throw std::logic_error ("EXCEPTION_MSG_5218545A: not_yet_implemented, write_L41,");
}
auto                                   //
    nscxx_root::element::              //
    FsmAction::DoTransfer_OR_L41_L50:: //
    fx_transfer_L50_write_prepwork (CtrlHandle &ctrl) -> void
{
  /// note: tcp write L50

  auto &unity = ctrl.m_unity.operator* ();
  auto msg_view = view02::message::L50::FX_ASSIGN_MSG (std::span (ctrl.m_tcp_buffer_for_write));

  // xxxx: tcp write msg - without write operate
  msg_view.m_hdr.m_fcm_id = unity.m_fcm_id;
  msg_view.m_hdr.m_session_id = unity.m_session_id;
  msg_view.fx_assign_m_msg_time_0_time_now ();
  msg_view.fx_assign_m_check_sum_0_algorithm ();
}
