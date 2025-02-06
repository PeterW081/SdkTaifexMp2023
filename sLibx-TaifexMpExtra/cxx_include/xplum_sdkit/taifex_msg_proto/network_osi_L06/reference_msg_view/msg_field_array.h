#pragma once
#include "xplum_model/taifex_msg_proto/network_osi_L06/structure_msg_field/msg_field_array.h"
#

namespace xplum_sdkit::taifex_msg_proto::view::message_field::array
{
namespace model = xplum_model::taifex_msg_proto::message_field::array;

/// Order
using OrderNo_VIEW = model::order_no &;
using UserDefine_VIEW = model::user_define &;
using InfoSource_VIEW = model::info_source &;

/// Symbol
using SymbolNum_LegSide_VIEW = model::symbol_num_0_leg_side &;
using SymbolNum_Filler_VIEW = model::symbol_num_0_filler &;
using SymbolText_Symbol_VIEW = model::symbol_text_0_symbol &;

/// LongSymbol
using LongSymbolNum_LegSide_VIEW = model::long_symbol_num_0_leg_side &;
using LongSymbolNum_Filler_VIEW = model::long_symbol_num_0_filler &;
using LongSymbolText_Symbol_VIEW = model::long_symbol_text_0_symbol &;

/// R02MsgField
using R02_LegSide_VIEW = model::R02_0_leg_side &;
using R02_LegPx_VIEW = model::R02_0_leg_px &;
using R02_LegQty_VIEW = model::R02_0_leg_qty &;

/// L41MsgField
using L41_Data_SPAN = std::span<xplum_model::taifex_msg_proto::message_field::uint8>;
}
