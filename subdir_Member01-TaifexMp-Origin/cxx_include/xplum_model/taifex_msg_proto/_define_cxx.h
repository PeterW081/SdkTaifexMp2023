#pragma once
#include "boost0/big_endian_integer.h"

namespace xplum_model::taifex_msg_proto::type
{
// message field
using char0 = char;
using int08 = ext::boost0::big_endian_int08::value_type;
using int16 = ext::boost0::big_endian_int16::value_type;
using int32 = ext::boost0::big_endian_int32::value_type;
using int64 = ext::boost0::big_endian_int64::value_type;
using uint08 = ext::boost0::big_endian_uint08::value_type;
using uint16 = ext::boost0::big_endian_uint16::value_type;
using uint32 = ext::boost0::big_endian_uint32::value_type;

// message field 02
using TypeMsgLength = uint16;
using TypeFcmId = uint16;
using TypeSessionId = uint16;
}
