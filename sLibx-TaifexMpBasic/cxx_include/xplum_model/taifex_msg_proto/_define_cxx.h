#pragma once
#include <boost/endian/arithmetic.hpp>
#

namespace xplum_model::taifex_msg_proto::type
{
// message field
using char0 = char;
using int08 = boost::endian::big_int8_t::value_type;
using int16 = boost::endian::big_int16_t::value_type;
using int32 = boost::endian::big_int32_t::value_type;
using int64 = boost::endian::big_int64_t::value_type;
using uint08 = boost::endian::big_uint8_t::value_type;
using uint16 = boost::endian::big_uint16_t::value_type;
using uint32 = boost::endian::big_uint32_t::value_type;

// message field 02
using TypeMsgLength = boost::endian::big_uint16_t::value_type;
using TypeFcmId = boost::endian::big_uint16_t::value_type;
using TypeSessionId = boost::endian::big_uint16_t::value_type;
}
