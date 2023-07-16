#pragma once
#include "xplum/taifex_msg_proto_sdk/define.h"
#include "xplum/taifex_msg_proto_sdk/view/msg_field_enumerate.h"
#include "xplum/taifex_msg_proto_sdk/widget/WidgetTaifexMpOrder.h"

namespace xplum::taifex_msg_proto_sdk::entity_process
{
	namespace define0
	{
		using view::message_field::enumerate::SystemType;
	}
	class TaifexMpSessionTrade;
}

class xplum::taifex_msg_proto_sdk::entity_process::TaifexMpSessionTrade
{
	// trade info
	std::chrono::year_month_day trade_date;
	define0::SystemType::EnumType trade_system_type;
	// trade data
	std::map<type::TypeFcmId, type::TypeSessionId> map_K_fcm_id_V_session_id;
	std::map<type::TypeFcmId, widget::WidgetTaifexMpOrder::TypePtrCounterOrderSeqV> map_K_fcm_id_V_counter_order_seq;
  public:
	// bool is_pass_fcm_passwd(type::typeof_fcm_id fcm_id, type::uint08 fcm_passwd); // TODO
};
