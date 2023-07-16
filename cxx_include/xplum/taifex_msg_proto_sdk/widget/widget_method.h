#pragma once
#include <span>
#include "xplum/taifex_msg_proto_sdk/define.h"

namespace xplum::taifex_msg_proto_sdk::widget_message_field
{
	struct Algorithm;
}

// ******************************** ******************************** ******************************** ******************************** //
struct xplum::taifex_msg_proto_sdk::widget_message_field::Algorithm
{
	template<std::size_t VALUE_BUFFER_SIZE>
	static type::uint08 constexpr Algorithm_Msg_Check_Sum(std::span<const std::byte, VALUE_BUFFER_SIZE> buffer);
	static type::uint08 constexpr Algorithm_Msg_L40_Key_Value(type::uint16 append_no, type::uint16 session_passwd);
};

// ******************************** ******************************** ******************************** ******************************** //
template<std::size_t VALUE_BUFFER_SIZE>
auto constexpr xplum::taifex_msg_proto_sdk::widget_message_field::Algorithm::Algorithm_Msg_Check_Sum(std::span<const std::byte, VALUE_BUFFER_SIZE> buffer) -> type::uint08
{
	std::size_t j;
	if constexpr(VALUE_BUFFER_SIZE != std::dynamic_extent)
	{
		constexpr std::size_t j0 = VALUE_BUFFER_SIZE - 1;
		j = j0;
	} else
	{
		j = buffer.size() - 1;
	}

	type::uint08 checksum = 0;
	for(std::size_t i = 0; i < j; i++)
	{
		checksum += static_cast<std::underlying_type<std::byte>::type>(buffer[i]);
	}
	return checksum;
}
