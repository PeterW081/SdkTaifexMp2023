#pragma once
#include "xplum/taifex_msg_proto_sdk/widget/widget_object.h"

namespace xplum::taifex_msg_proto_sdk::widget
{
	namespace define0
	{
		using xplum::taifex_msg_proto_sdk::prototype::CounterOrderSeqV;
		using xplum::taifex_msg_proto_sdk::widget_message_field::CounterOrderSeqSimple;
	}
	struct WidgetTaifexMpOrder;
}

struct xplum::taifex_msg_proto_sdk::widget::WidgetTaifexMpOrder
	: public xplum::taifex_msg_proto_sdk::widget_message_field::AssignerOrderNo
	, public xplum::taifex_msg_proto_sdk::widget_message_field::AssignerSymbol
	, public xplum::taifex_msg_proto_sdk::widget_message_field::AssignerUserDefine
	, public xplum::taifex_msg_proto_sdk::widget_message_field::ConvertorOrderNo
{
	// Type
	using TypePtrCounterOrderSeqV = std::unique_ptr<define0::CounterOrderSeqV>;
	using TypePtrCounterOrderSeqSimple = std::unique_ptr<define0::CounterOrderSeqSimple>;
	static_assert(std::is_base_of<TypePtrCounterOrderSeqV::element_type, TypePtrCounterOrderSeqSimple::element_type>::value);

	// Method
	static std::size_t Assign_Order_No(char (&lvariable)[AssignerOrderNo::M_SIZE], std::uint32_t rvalue_int_order_no);
};
