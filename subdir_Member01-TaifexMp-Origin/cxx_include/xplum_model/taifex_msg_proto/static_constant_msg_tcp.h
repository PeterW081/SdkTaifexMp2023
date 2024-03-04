#pragma once
#include <cstddef>

namespace xplum_model::taifex_msg_proto::tcp {
// protocol define
const std::size_t LXX_LAYER_TIMEOUT_S = 10; // 單位為秒。
const std::size_t RXX_LAYER_TIMEOUT_S = 30; // ^^^
const std::size_t R04_LAYER_TIMEOUT_S = 5;  // ^^^
} // namespace xplum_model::taifex_msg_proto::tcp
