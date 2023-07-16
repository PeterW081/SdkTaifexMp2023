#pragma once
#include "xplum/taifex_msg_proto_sdk/widget/widget_method.h"
#include "xplum/taifex_msg_proto_sdk/widget/widget_object.h"

namespace xplum::taifex_msg_proto_sdk::widget
{
	namespace define0
	{
		using xplum::taifex_msg_proto_sdk::prototype::CounterMsgSeqNumV;
		using xplum::taifex_msg_proto_sdk::widget_message_field::CounterMsgSeqNumSimple;
	}
	struct WidgetTaifexMpMessage;
}

struct xplum::taifex_msg_proto_sdk::widget::WidgetTaifexMpMessage
	: public xplum::taifex_msg_proto_sdk::widget_message_field::Algorithm
	, public xplum::taifex_msg_proto_sdk::widget_message_field::AssignerMsgTime
{
	// Type
	using TypePtrCounterMsgSeqNumV = std::unique_ptr<define0::CounterMsgSeqNumV>;
	using TypePtrCounterMsgSeqNumSimple = std::unique_ptr<define0::CounterMsgSeqNumSimple>;
	static_assert(std::is_base_of<TypePtrCounterMsgSeqNumV::element_type, TypePtrCounterMsgSeqNumSimple::element_type>::value);

	// Method
	static void Assign_Msg_Time(view::message_field::MsgTime lvariable);
};
