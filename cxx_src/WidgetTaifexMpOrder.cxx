#include "xplum/taifex_msg_proto_sdk/widget/WidgetTaifexMpOrder.h"
using xplum::taifex_msg_proto_sdk::widget::WidgetTaifexMpOrder;

#pragma
using xplum::taifex_msg_proto_sdk::widget_message_field::AssignerOrderNo;

auto WidgetTaifexMpOrder::Assign_Order_No(char (&lvariable)[AssignerOrderNo::M_SIZE], std::uint32_t rvalue_int_order_no) -> std::size_t
{
	auto char_array = Convert_Order_No_To_Text_Char_Array(rvalue_int_order_no);
	return AssignerOrderNo::Assign_Order_No(lvariable, *char_array);
}
