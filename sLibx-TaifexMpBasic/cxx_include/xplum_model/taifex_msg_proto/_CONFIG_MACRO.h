#pragma once
#include <cstdint>
#

namespace xplum_model::taifex_msg_proto::cfg
{
extern const std::uint16_t G_size_max_of_msg_read_buffer;
}

inline const auto xplum_model::taifex_msg_proto::cfg::G_size_max_of_msg_read_buffer =
#if (not defined(MACRO_XPLUM_0_TAIFEX_MSG_PROTO_0_SIZE_MAX_OF_MSG_READ_BUFFER))
    std::uint16_t(1024 * 1)
#else
#warning "defined(MACRO_XPLUM_0_TAIFEX_MSG_PROTO_0_SIZE_MAX_OF_MSG_READ_BUFFER) == true"
    std::uint16_t(MACRO_XPLUM_0_TAIFEX_MSG_PROTO_0_SIZE_MAX_OF_MSG_READ_BUFFER)
#endif
    ;
