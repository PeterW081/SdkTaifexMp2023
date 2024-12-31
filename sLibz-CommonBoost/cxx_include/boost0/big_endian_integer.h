#pragma once
#include <boost/endian/arithmetic.hpp>

namespace ext::boost0
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
