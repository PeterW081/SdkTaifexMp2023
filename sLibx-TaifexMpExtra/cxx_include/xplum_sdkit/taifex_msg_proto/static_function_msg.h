#pragma once
#include "xplum_sdkit/taifex_msg_proto/view/msg_field.h"
#include "xplum_sdkit/taifex_msg_proto/kitbag/msg_kitbag_re_orderno.h"
#

namespace xplum_sdkit::taifex_msg_proto::ez_view
{
extern auto FX_GET_MSG_LENGTH_IN_ORIGIN_MSG(void *data) -> view::message_field::uint16;
extern auto FX_GET_MSG_LENGTH_IN_ORIGIN_MSG_1CONST(void const *data) -> view::message_field::origin::uint16 const &;
extern auto FX_GET_MSG_TYPE_IN_ORIGIN_MSG_1CONST(void *data) -> const view::message_field::enumerate::MsgType;
extern auto FX_GET_SYMBOL_TEXT_IN_VIEW_MSG_FIELD(view::message_field::SymbolX &symbol_x) -> decltype(view::message_field::SymbolText::m_symbol);
}

namespace xplum_sdkit::taifex_msg_proto::algorithm
{
// ConvertorOrderNo
const auto FX_CONVERT_ORDER_NO_TO_TEXT_STRING = xplum_sdkit::taifex_msg_proto::kitbag::ConvertorOrderNo::FX_CONVERT_ORDER_NO_TO_TEXT_STRING;
const auto FX_CONVERT_ORDER_NO_TO_VALUE = xplum_sdkit::taifex_msg_proto::kitbag::ConvertorOrderNo::FX_CONVERT_ORDER_NO_TO_VALUE;
}
