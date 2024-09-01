#pragma once
#include <cstddef>
#include "xplum_model/taifex_msg_proto/_define_cxx.h"

namespace xplum_model::taifex_msg_proto::algorithm
{
extern auto FX_MSG_CHECK_SUM(const std::byte *, std::size_t) -> type::uint08; // msg_data, msg_size,
extern auto FX_MSG_L40_KEY_VALUE(type::uint16, type::uint16) -> type::uint08; // session_passwd, append_no,
}
