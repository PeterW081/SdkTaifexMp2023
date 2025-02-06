#pragma once
#include "msg_field.h"
#

namespace xplum_model::taifex_msg_proto::message_field::array
{
/// Order
using order_no = message_field::char0_arr<5>;
using user_define = message_field::char0_arr<8>;
using info_source = message_field::char0_arr<3>;

/// Symbol
using symbol_num_0_leg_side = message_field::uint8_arr<2>;
using symbol_num_0_filler = message_field::uint8_arr<13>;
using symbol_text_0_symbol = message_field::char0_arr<20>;

/// LongSymbol
using long_symbol_num_0_leg_side = message_field::uint8_arr<2>;
using long_symbol_num_0_filler = message_field::uint8_arr<33>;
using long_symbol_text_0_symbol = message_field::char0_arr<40>;

/// R02MsgField
using R02_0_leg_side = message_field::uint8_arr<2>;
using R02_0_leg_px = message_field::int32_arr<2>;
using R02_0_leg_qty = message_field::uint16_arr<2>;

}
