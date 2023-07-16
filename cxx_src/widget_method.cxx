#include "xplum/taifex_msg_proto_sdk/widget/widget_method.h"
using xplum::taifex_msg_proto_sdk::widget_message_field::Algorithm;

auto constexpr Algorithm::Algorithm_Msg_L40_Key_Value(type::uint16 append_no, type::uint16 session_passwd) -> type::uint08
{
	std::uint64_t product;
	product = append_no * session_passwd;
	product = ((((product % 10000) / 1000)) * 10) + ((product % 1000) / 100);
	return product;
}
