#pragma once
#include <cstddef>

namespace xplum_model::taifex_msg_proto::network_agreement
{
struct TcpContact;
}

struct xplum_model::taifex_msg_proto::network_agreement::TcpContact
{
  // protocol define
  static const std::size_t M_LXX_LAYER_TIMEOUT_S = 10; // 單位為秒。
  static const std::size_t M_RXX_LAYER_TIMEOUT_S = 30; // ^^^
  static const std::size_t M_R04_LAYER_TIMEOUT_S = 5;  // ^^^
};
