#pragma once
#include "xplum_model/taifex_msg_proto/structure_message_field/msg_field.h"
#include "xplum_model/taifex_msg_proto/structure_message_field/msg_field_sizeof_array.h"
#include "xplum_sdkit/taifex_msg_proto/view/msg_field.h"
#include "xplum_sdkit/taifex_msg_proto/kitbag/msg_kitbag_re_orderno.h"

namespace xplum_sdkit::taifex_msg_proto::ez_view
{
extern auto FX_GET_MSG_LENGTH_IN_ORIGIN_MSG (void *data) -> xplum_model::taifex_msg_proto::message_field::uint16 &;
extern auto FX_GET_MSG_LENGTH_IN_ORIGIN_MSG_1CONST (void *data) -> const xplum_model::taifex_msg_proto::message_field::uint16 &;
extern auto FX_GET_MSG_TYPE_IN_ORIGIN_MSG_1CONST (void *data) -> const view::message_field::enumerate::MsgType;
extern auto FX_GET_SYMBOL_TEXT_IN_VIEW_MSG_FIELD (view::message_field::SymbolX &symbol_x) -> view::message_field::origin::char0 (&)[xplum_model::taifex_msg_proto::message_field::sizeof_array::Symbol::M_SIZEOF_ARR_0_TEXT_SYMBOL];
}

namespace xplum_sdkit::taifex_msg_proto::algorithm
{
// ConvertorOrderNo
const auto FX_CONVERT_ORDER_NO_TO_TEXT_STRING = xplum_sdkit::taifex_msg_proto::kitbag::ConvertorOrderNo::FX_CONVERT_ORDER_NO_TO_TEXT_STRING;
const auto FX_CONVERT_ORDER_NO_TO_VALUE = xplum_sdkit::taifex_msg_proto::kitbag::ConvertorOrderNo::FX_CONVERT_ORDER_NO_TO_VALUE;
}
