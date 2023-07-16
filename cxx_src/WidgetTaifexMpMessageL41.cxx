#include "xplum/taifex_msg_proto_sdk/widget/WidgetTaifexMpMessageL41.h"
using xplum::taifex_msg_proto_sdk::widget::WidgetTaifexMpMessageL41;

#pragma
namespace cxx_define0
{
	using xplum::taifex_msg_proto_sdk::view::message_field::enumerate::MsgType;
	auto& SIZE_OUT_OF_MSG_LENGTH = xplum::taifex_msg_proto::message_field::SIZE_OUT_OF_MSG_LENGTH;
	auto& SIZE_OUT_OF_L41_DATA_IN_MSG_LENGTH = xplum::taifex_msg_proto::message_field::SIZE_OUT_OF_L41_DATA_IN_MSG_LENGTH;
}

auto constexpr WidgetTaifexMpMessageL41::Algorithm_L41_Msg_Length_With_L41_File_Size(xplum::taifex_msg_proto::type::uint32 L41_file_size) -> std::size_t
{
	return L41_file_size + cxx_define0::SIZE_OUT_OF_L41_DATA_IN_MSG_LENGTH;
}

auto WidgetTaifexMpMessageL41::Parser_Msg_Field_L41_Data(view::message::L41 view_L41) -> std::vector<TypeMsgViewL41DataMemeber>
{
	std::vector<TypeMsgViewL41DataMemeber> result;
	for(std::intptr_t i = 0, j = view_L41.m_file_size; i < j;)
	{
		void* message = view_L41.m_L41_data.data() + i;
		auto message_head = view::message_field::MsgHdr(message);
		i += static_cast<std::intptr_t>(cxx_define0::SIZE_OUT_OF_MSG_LENGTH) + message_head.m_msg_length;
		switch(message_head.m_message_type.enum_value())
		{
			case cxx_define0::MsgType::EnumType ::R02:
				result.emplace_back(view::message::R02(message));
				break;
			case cxx_define0::MsgType::EnumType ::R03:
				result.emplace_back(view::message::R03(message));
				break;
			default:
				result.emplace_back() = std::span<const std::byte>(reinterpret_cast<const std::byte*>(message), cxx_define0::SIZE_OUT_OF_MSG_LENGTH + message_head.m_msg_length);
				break;
		}
	}
	return result;
}
