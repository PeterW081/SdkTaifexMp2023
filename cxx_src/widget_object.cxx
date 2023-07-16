#include "xplum/taifex_msg_proto_sdk/widget/widget_object.h"
using xplum::taifex_msg_proto_sdk::widget_message_field::AssignerMsgTime;
using xplum::taifex_msg_proto_sdk::widget_message_field::AssignerOrderNo;
using xplum::taifex_msg_proto_sdk::widget_message_field::AssignerSymbol;
using xplum::taifex_msg_proto_sdk::widget_message_field::AssignerUserDefine;
using xplum::taifex_msg_proto_sdk::widget_message_field::ConvertorOrderNo;
using xplum::taifex_msg_proto_sdk::widget_message_field::CounterMsgSeqNumSimple;
using xplum::taifex_msg_proto_sdk::widget_message_field::CounterOrderSeqSimple;

#pragma
#include "xplum/taifex_msg_proto_sdk/define.h"

/// xplum::taifex_msg_proto_sdk::widget_message_field::CounterMsgSeqNum
bool CounterMsgSeqNumSimple::storage_load0(std::nullptr_t melon, ...)
{
	std::unique_ptr<type::uint32>* value;

	va_list(args);
	va_start(args, melon);
	value = va_arg(args, std::unique_ptr<type::uint32>*);
	va_end(args);

	return this->storage_load(value);
}
bool CounterMsgSeqNumSimple::storage_save0(std::nullptr_t melon, ...) const
{
	std::unique_ptr<type::uint32>* value;

	va_list(args);
	va_start(args, melon);
	value = va_arg(args, std::unique_ptr<type::uint32>*);
	va_end(args);

	return this->storage_save(value);
}
bool CounterMsgSeqNumSimple::storage_load(std::unique_ptr<type::uint32>* value)
{
	if(value == nullptr)
	{
		assert(!(value == nullptr));
		return false;
	}

	std::unique_ptr<type::uint32>& value0 = *value;
	if(value0 == nullptr)
	{
		assert(!(value0.get() == nullptr));
		return false;
	}

	auto total_lock = std::unique_lock(m_mutex_read_write);
	this->m_data = *value0;
	return true;
}
bool CounterMsgSeqNumSimple::storage_save(std::unique_ptr<type::uint32>* value) const
{
	if(value == nullptr)
	{
		assert(!(value == nullptr));
		return false;
	}

	std::unique_ptr<type::uint32>& value0 = *value;
	if(value0 == nullptr)
	{
		value0 = std::make_unique<type::uint32>();
	}

	auto total_lock = std::unique_lock(m_mutex_read_write);
	*value0 = this->m_data;
	return true;
}

/// xplum::taifex_msg_proto_sdk::widget_message_field::AssignerMsgTime
void AssignerMsgTime::Assign_Msg_Time(xplum::taifex_msg_proto_sdk::view::message_field::MsgTime lvariable, std::int64_t rvalue_time_since_epoch_microseconds)
{
	// XXXX 取得當前時間：rvalue_time_since_epoch_microseconds = std::chrono::system_clock::now().time_since_epoch().count();
	constexpr auto int_1k = 1000;
	constexpr auto int_1kk = 1000 * 1000;
	lvariable.m_linux_time_stamp_s = static_cast<type::int32>(rvalue_time_since_epoch_microseconds / int_1kk);
	lvariable.m_millisecond = (rvalue_time_since_epoch_microseconds % int_1kk) / int_1k;
}
void AssignerMsgTime::Assign_Msg_Time(xplum::taifex_msg_proto_sdk::view::message_field::MsgTime lvariable, timeval rvalue)
{
	// XXXX 取得當前時間：gettimeofday(&rvalue, nullptr);
	constexpr auto int_1k = 1000;
	lvariable.m_linux_time_stamp_s = static_cast<type::int32>(rvalue.tv_sec);
	lvariable.m_millisecond = rvalue.tv_usec / int_1k;
}
void AssignerMsgTime::Assign_Msg_Time(xplum::taifex_msg_proto_sdk::view::message_field::MsgTime lvariable, std::chrono::time_point<std::chrono::system_clock> rvalue)
{
	// XXXX 取得當前時間：rvalue = std::chrono::system_clock::now();
	constexpr auto int_1k = 1000;
	lvariable.m_linux_time_stamp_s = static_cast<type::int32>(std::chrono::duration_cast<std::chrono::seconds>(rvalue.time_since_epoch()).count());
	lvariable.m_millisecond = std::chrono::duration_cast<std::chrono::milliseconds>(rvalue.time_since_epoch()).count() % int_1k;
}
void AssignerMsgTime::Assign_Msg_Time(xplum::taifex_msg_proto_sdk::view::message_field::MsgTime lvariable, boost::posix_time::ptime rvalue)
{
	// XXXX 取得當前時間：rvalue = boost::posix_time::second_clock::local_time();
	constexpr auto int_1k = 1000;
	constexpr auto linex_timestamp_base = boost::posix_time::ptime(boost::gregorian::date(1970, 1, 1));
	boost::posix_time::time_duration timestamp = rvalue - linex_timestamp_base;
	lvariable.m_linux_time_stamp_s = static_cast<type::int32>(timestamp.total_seconds());
	lvariable.m_millisecond = timestamp.total_milliseconds() % int_1k;
}

/// xplum::taifex_msg_proto_sdk::widget_message_field::CounterOrderSimple
bool CounterOrderSeqSimple::storage_load0(std::nullptr_t melon, ...)
{
	std::unique_ptr<type::uint32>* order_no;
	std::map<type::uint32, type::uint32>* map_K_order_no_V_order_id;

	using TypeParam02 = std::map<type::uint32, type::uint32>*;
	va_list(args);
	va_start(args, melon);
	order_no = va_arg(args, std::unique_ptr<type::uint32>*);
	map_K_order_no_V_order_id = va_arg(args, TypeParam02);
	va_end(args);

	return this->storage_load(order_no, map_K_order_no_V_order_id);
}
bool CounterOrderSeqSimple::storage_save0(std::nullptr_t melon, ...) const
{
	std::unique_ptr<type::uint32>* order_no;
	std::map<type::uint32, type::uint32>* map_K_order_no_V_order_id;

	using TypeParam02 = std::map<type::uint32, type::uint32>*;
	va_list(args);
	va_start(args, melon);
	order_no = va_arg(args, std::unique_ptr<type::uint32>*);
	map_K_order_no_V_order_id = va_arg(args, TypeParam02);
	va_end(args);

	return this->storage_save(order_no, map_K_order_no_V_order_id);
}
bool CounterOrderSeqSimple::storage_load(std::unique_ptr<type::uint32>* order_no, std::map<type::uint32, type::uint32>* map_K_order_no_V_order_id)
{
	if(order_no == nullptr || map_K_order_no_V_order_id == nullptr)
	{
		assert(!(order_no == nullptr));
		assert(!(map_K_order_no_V_order_id == nullptr));
		return false;
	}

	std::unique_ptr<type::uint32>& order_no0 = *order_no;
	std::map<type::uint32, type::uint32>& map_K_order_no_V_order_id0 = *map_K_order_no_V_order_id;
	if(order_no0 == nullptr)
	{
		assert(!(order_no0.get() == nullptr));
		return false;
	}

	auto total_lock = std::unique_lock(m_mutex_read_write);
	this->m_order_no = *order_no0;
	this->m_map_K_order_no_V_order_id.clear();
	for(auto& var : map_K_order_no_V_order_id0)
	{
		this->m_map_K_order_no_V_order_id.insert(var);
	}
	return true;
}
bool CounterOrderSeqSimple::storage_save(std::unique_ptr<type::uint32>* order_no, std::map<type::uint32, type::uint32>* map_K_order_no_V_order_id) const
{
	if(order_no == nullptr || map_K_order_no_V_order_id == nullptr)
	{
		assert(!(order_no == nullptr));
		assert(!(map_K_order_no_V_order_id == nullptr));
		return false;
	}

	std::unique_ptr<type::uint32>& order_no0 = *order_no;
	std::map<type::uint32, type::uint32>& map_K_order_no_V_order_id0 = *map_K_order_no_V_order_id;
	if(order_no0 == nullptr)
	{
		order_no0 = std::make_unique<type::uint32>();
	}

	auto total_lock = std::unique_lock(m_mutex_read_write);
	*order_no0 = this->m_order_no;
	map_K_order_no_V_order_id0.clear();
	for(auto& var : this->m_map_K_order_no_V_order_id)
	{
		map_K_order_no_V_order_id0.insert(var);
	}
	return true;
}

/// xplum::taifex_msg_proto_sdk::widget_message_field::AssignerOrderNo
auto AssignerOrderNo::Assign_Order_No(char (&lvariable)[M_SIZE], std::string_view rvalue) -> std::size_t
{
	return SUPER::Assign(lvariable, rvalue);
}

/// xplum::taifex_msg_proto_sdk::widget_message_field::AssignerUserDefine
auto AssignerUserDefine::Assign_User_Define(char (&lvariable)[M_SIZE], std::string_view rvalue) -> std::size_t
{
	return SUPER::Assign(lvariable, rvalue);
}

/// xplum::taifex_msg_proto_sdk::widget_message_field::AssignerSymbol
auto AssignerSymbol::Get_Symbol_Text(view::message_field::SymbolX& symbol_x) -> char (&)[define0::Symbol::M_TEXT_SYMBOL]
{
	return std::get<view::message_field::SymbolText>(symbol_x).m_symbol;
}
auto AssignerSymbol::Assign_Symbol_Text(view::message_field::SymbolX& lvariable_symbol_x, std::string_view rvalue) -> std::size_t
{
	return SUPER::Assign(Get_Symbol_Text(lvariable_symbol_x), rvalue);
}

/// xplum::taifex_msg_proto_sdk::widget_message_field::ConvertorOrderNo
auto ConvertorOrderNo::Convert_Order_No_To_Value(std::string_view txt_value) -> std::optional<std::uint32_t>
{
	return To_Value(txt_value);
}
auto ConvertorOrderNo::Convert_Order_No_To_Text_String(std::uint32_t int_value) -> std::string
{
	return To_String(int_value);
}
