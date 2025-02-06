#pragma once
#include <cstdint>
#include "xplum_model/taifex_msg_proto/_define_cxx.h"
#

namespace xplum_model::taifex_msg_proto::msg_algorithm
{
extern auto FX_msg_check_sum(const std::byte *, std::size_t) -> type::uint08; // msg_data, msg_size,
extern auto FX_msg_L40_key_value(type::uint16, type::uint16) -> type::uint08; // session_passwd, append_no,
}
