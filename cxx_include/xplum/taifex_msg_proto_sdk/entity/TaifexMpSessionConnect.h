#pragma once
#include "xplum/taifex_msg_proto_sdk/define.h"
#include "xplum/taifex_msg_proto_sdk/view/msg_field_enumerate.h"
#include "xplum/taifex_msg_proto_sdk/widget/WidgetTaifexMpMessage.h"

namespace xplum::taifex_msg_proto_sdk::entity_process
{
	namespace define0
	{
		using view::message_field::enumerate::SystemType;
	}
	class TaifexMpSessionConnect;
}

class xplum::taifex_msg_proto_sdk::entity_process::TaifexMpSessionConnect
{
	// trade info
	std::chrono::year_month_day trade_date;
	define0::SystemType::EnumType trade_system_type;
	// connect data
	type::TypeFcmId fcm_id;
	type::TypeSessionId session_id;
	widget::WidgetTaifexMpMessage::TypePtrCounterMsgSeqNumV counter_msg_seq_num;
	// connect param
	std::unique_ptr<type::uint08> fcm_passwd;
	std::unique_ptr<type::uint08> msg_field_L40_append_no;

  public:
};
