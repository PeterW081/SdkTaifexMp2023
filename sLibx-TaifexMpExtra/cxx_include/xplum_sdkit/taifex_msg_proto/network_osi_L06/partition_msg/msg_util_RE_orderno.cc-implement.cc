#pragma once
#include "./msg_util_RE_orderno.h"
#pragma
#include "xplum/ancestor_algorithm/ConvertorBtwStrIntByCustomDigit.h"
#include "xplum_sdkit/taifex_msg_proto/ancestor/CounterOrderSeq_V.h"
#include "xplum_model/taifex_msg_proto/network_osi_L06/structure_msg_field/msg_field_array.h"
#

/// ConvertorOrderNo
template <std::size_t VALUE_string_size>
auto                                      //
    xplum_sdkit::taifex_msg_proto::util:: //
    ConvertorOrderNo::                    //
    FX_convert_order_no_to_text_char_array(std::uint32_t int_value) -> std::unique_ptr<std::array<char, VALUE_string_size>>
{
    return To_Char_Array<VALUE_string_size>(int_value);
}
