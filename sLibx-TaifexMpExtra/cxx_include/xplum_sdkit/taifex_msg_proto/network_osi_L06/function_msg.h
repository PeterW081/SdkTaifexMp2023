#pragma once
#include "xplum_sdkit/taifex_msg_proto/_define_cxx.h"
#include "xplum_sdkit/taifex_msg_proto/network_osi_L06/reference_msg_view/msg_field.h"
#include "xplum_sdkit/taifex_msg_proto/network_osi_L06/partition_msg/msg_util_RE_orderno.h"
#

namespace xplum_sdkit::taifex_msg_proto::ez_view
{
extern auto FX_get_msg_length_from_msg_data(void *data) -> view::message_field::uint16_VIEW;
extern auto FX_get_msg_type_from_msg_data(void *data) -> view::message_field::enumerate::MsgType_VIEW;
extern auto FX_get_symbol_text(view::message_field::SymbolX_VIEW &symbol_x) -> decltype(view::message_field::SymbolText_VIEW::m_symbol);
}
namespace xplum_sdkit::taifex_msg_proto::algorithm
{
// ConvertorOrderNo
const auto FX_convert_order_no_to_text_string = xplum_sdkit::taifex_msg_proto::util::ConvertorOrderNo::FX_convert_order_no_to_text_string;
const auto FX_convert_order_no_to_value = xplum_sdkit::taifex_msg_proto::util::ConvertorOrderNo::FX_convert_order_no_to_value;
}
