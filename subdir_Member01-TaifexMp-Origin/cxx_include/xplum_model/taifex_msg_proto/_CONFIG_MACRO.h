#pragma once
#include <cstddef>
#include "_define_cxx.h"

namespace xplum_model::taifex_msg_proto::cfg
{
extern const type::TypeMsgLength SIZE_MAX_OF_MSG_READ_BUFFER;
}

#if (!defined(MACRO_XPLUM_0_TAIFEX_MSG_PROTO_0_SIZE_MAX_OF_MSG_READ_BUFFER))
inline const auto xplum_model::taifex_msg_proto::cfg::SIZE_MAX_OF_MSG_READ_BUFFER = type::TypeMsgLength (1 * 1024);
#else
#warning "defined(MACRO_XPLUM_0_TAIFEX_MSG_PROTO_0_SIZE_MAX_OF_MSG_READ_BUFFER) == true"
inline const auto xplum_model::taifex_msg_proto::cfg::SIZE_MAX_OF_MSG_READ_BUFFER = type::TypeMsgLength (MACRO_XPLUM_0_TAIFEX_MSG_PROTO_0_SIZE_MAX_OF_MSG_READ_BUFFER);
#endif
