#pragma once
#include <typeindex>
#include <span>
#include "xplum/taifex_msg_proto_sdk/define.h"
#include "xplum/taifex_msg_proto_sdk/view/msg_lxx_layer.h"
#include "xplum/taifex_msg_proto_sdk/view/msg_rxx_layer.h"

namespace xplum::taifex_msg_proto_sdk::widget
{
	struct WidgetTaifexMpMessageL41;
}

struct xplum::taifex_msg_proto_sdk::widget::WidgetTaifexMpMessageL41
{

  public:
	using TypeMsgViewL41DataMemeber = std::variant<std::nullptr_t, std::span<const std::byte>, view::message::R02, view::message::R03>;

  public:
	static std::size_t constexpr Algorithm_L41_Msg_Length_With_L41_File_Size(type::uint32 L41_file_size);
	static std::vector<TypeMsgViewL41DataMemeber> Parser_Msg_Field_L41_Data(view::message::L41 view_L41);
	// static auto Maker_Msg_L41(...);	// TODO
};
