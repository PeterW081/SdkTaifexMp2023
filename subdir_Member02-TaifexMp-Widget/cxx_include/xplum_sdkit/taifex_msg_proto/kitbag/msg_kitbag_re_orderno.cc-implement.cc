#pragma once
#include "./msg_kitbag_re_orderno.h"
#pragma

// using xplum_sdkit::taifex_msg_proto::kitbag::ConvertorOrderNo;
//
template <std::size_t VALUE_STRING_SIZE>
auto xplum_sdkit::taifex_msg_proto::kitbag:: //
    ConvertorOrderNo::FX_CONVERT_ORDER_NO_TO_TEXT_CHAR_ARRAY(std::uint32_t int_value) -> std::unique_ptr<std::array<char, VALUE_STRING_SIZE>>
{
    return To_Char_Array<VALUE_STRING_SIZE>(int_value);
}
