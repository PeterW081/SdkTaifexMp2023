#pragma once
#include <boost/endian/arithmetic.hpp>

namespace xplum::boost0
{
	// big endian integer
	using big_endian_int08 = boost::endian::big_int8_t;
	using big_endian_int16 = boost::endian::big_int16_t;
	using big_endian_int32 = boost::endian::big_int32_t;
	using big_endian_int64 = boost::endian::big_int64_t;
	using big_endian_uint08 = boost::endian::big_uint8_t;
	using big_endian_uint16 = boost::endian::big_uint16_t;
	using big_endian_uint32 = boost::endian::big_uint32_t;
}

namespace xplum::taifex_msg_proto::type
{
	// message field
	using char0 = char;
	using int08 = xplum::boost0::big_endian_int08::value_type;
	using int16 = xplum::boost0::big_endian_int16::value_type;
	using int32 = xplum::boost0::big_endian_int32::value_type;
	using int64 = xplum::boost0::big_endian_int64::value_type;
	using uint08 = xplum::boost0::big_endian_uint08::value_type;
	using uint16 = xplum::boost0::big_endian_uint16::value_type;
	using uint32 = xplum::boost0::big_endian_uint32::value_type;

	// message field 02
	using TypeFcmId = int16;
	using TypeSessionId = int16;
}
