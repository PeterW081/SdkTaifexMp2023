#include "xplum/taifex_msg_proto_sdk/widget/WidgetTaifexMpMessage.h"
using xplum::taifex_msg_proto_sdk::widget::WidgetTaifexMpMessage;

/// xplum::taifex_msg_proto_sdk::widget::WidgetTaifexMpMessage
void WidgetTaifexMpMessage::Assign_Msg_Time(xplum::taifex_msg_proto_sdk::view::message_field::MsgTime lvariable)
{
	constexpr auto int_1k = 1000;
	timeval value = timeval();
	gettimeofday(&value, nullptr);
	lvariable.m_linux_time_stamp_s = static_cast<type::int32>(value.tv_sec);
	lvariable.m_millisecond = value.tv_usec / int_1k;
}
