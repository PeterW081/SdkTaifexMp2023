#pragma once
#include "xplum_model/taifex_msg_proto/static_constant_msg_tcp.h"
#include "xplum_sdkit/taifex_msg_proto/view/msg_field_enumerate.h"
#include "xplum_sdkit/taifex_msg_proto/kitbag/msg_kitbag_common.h"

namespace xplum_sdkit::taifex_msg_proto::kitbag::_nshdr {
using kitbag::CounterMsgSeqNumV;
using view::message_field::enumerate::SystemType;
}
namespace xplum_sdkit::taifex_msg_proto::kitbag {
struct UnityTcpSession;
}

struct                                                             //
    xplum_sdkit::taifex_msg_proto::kitbag::                        //
    UnityTcpSession                                                //
    : xplum_model::taifex_msg_proto::network_agreement::TcpContact //
{
  // tcp contact
  std::string m_server_host;
  std::string m_server_port;

  // msg layer
  type::TypeFcmId m_fcm_id;
  type::TypeSessionId m_session_id;

  // msg layer - Lxx
  const std::uint8_t m_ap_code = 4;                 // L40<
  const std::uint8_t m_cancel_order_sec = 0;        // L40<
  _nshdr::SystemType::EnumType m_trade_system_type; // L40<、L30>。
  std::uint32_t m_request_start_seq;                // L40<。

  // msg layer - Rxx
  std::shared_ptr<_nshdr::CounterMsgSeqNumV> m_counter_msg_seq;

  // secrecy
  struct {
    std::optional<type::uint16> m_fcm_passwd;
    std::optional<type::uint16> m_append_no;
    void fx_scrap() {
      this->m_fcm_passwd = std::nullopt;
      this->m_append_no = std::nullopt;
    };
  } m_secrecy;
};
