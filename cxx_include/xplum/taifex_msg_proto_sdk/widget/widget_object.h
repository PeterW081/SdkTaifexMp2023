#pragma once

#include <shared_mutex>
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#include <boost/date_time/posix_time/posix_time.hpp>
#pragma GCC diagnostic pop

#include "xplum/taifex_msg_proto_sdk/define.h"
#include "xplum/taifex_msg_proto_sdk/view/msg_field.h"
#include "xplum/taifex_msg_proto_sdk/prototype/AssignerMsgFieldArrayChar.h"
#include "xplum/taifex_msg_proto_sdk/prototype/CounterMsgSeqNumV.h"
#include "xplum/taifex_msg_proto_sdk/prototype/CounterOrderSeqV.h"
#include "xplum/prototype_algorithm/ConvertorBtwStrIntByCustomDigit.h"

namespace xplum::taifex_msg_proto_sdk::widget_message_field
{
	namespace define0
	{
		using xplum::taifex_msg_proto_sdk::prototype::define0::ArrayAlign;

		using xplum::prototype::ConvertorBtwStrIntByCustomDigit;
		using xplum::taifex_msg_proto::message_field::sizeof_array::Order;
		using xplum::taifex_msg_proto::message_field::sizeof_array::Symbol;
		using xplum::taifex_msg_proto_sdk::prototype::AssignerMsgFieldArrayChar;
		using xplum::taifex_msg_proto_sdk::prototype::CounterMsgSeqNumV;
		using xplum::taifex_msg_proto_sdk::prototype::CounterOrderSeqV;

		static constexpr char DIGIT_TABLE_ORDER_NO[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	}

	// General
	class CounterMsgSeqNumSimple;
	struct AssignerMsgTime;

	// Order
	class CounterOrderSeqSimple; // OrderNo、OrderId
	struct AssignerOrderNo;
	struct AssignerUserDefine;
	struct ConvertorOrderNo;

	// OrderSymbol
	struct AssignerSymbol;
}

// ******************************** ******************************** ******************************** ******************************** //
/// class
class xplum::taifex_msg_proto_sdk::widget_message_field::CounterMsgSeqNumSimple : public define0::CounterMsgSeqNumV
{
  public:
	bool storage_load(std::unique_ptr<type::uint32>* value);
	bool storage_save(std::unique_ptr<type::uint32>* value) const;

  protected:
	bool storage_load0(std::nullptr_t melon, ...) override;
	bool storage_save0(std::nullptr_t melon, ...) const override;
};

class xplum::taifex_msg_proto_sdk::widget_message_field::CounterOrderSeqSimple : public define0::CounterOrderSeqV
{
  public:
	bool storage_load(std::unique_ptr<type::uint32>* order_no, std::map<type::uint32, type::uint32>* map_K_order_no_V_order_id);
	bool storage_save(std::unique_ptr<type::uint32>* order_no, std::map<type::uint32, type::uint32>* map_K_order_no_V_order_id) const;

  protected:
	bool storage_load0(std::nullptr_t melon, ...) override;
	bool storage_save0(std::nullptr_t melon, ...) const override;
};


/// struct
struct xplum::taifex_msg_proto_sdk::widget_message_field::AssignerMsgTime
{
	static void Assign_Msg_Time(view::message_field::MsgTime lvariable, std::int64_t rvalue_time_since_epoch_microseconds);
	static void Assign_Msg_Time(view::message_field::MsgTime lvariable, timeval rvalue);                                            // C
	static void Assign_Msg_Time(view::message_field::MsgTime lvariable, std::chrono::time_point<std::chrono::system_clock> rvalue); // Std
	static void Assign_Msg_Time(view::message_field::MsgTime lvariable, boost::posix_time::ptime rvalue);                           // Boost
};

struct xplum::taifex_msg_proto_sdk::widget_message_field::AssignerOrderNo
{
  protected:
	static constexpr auto& M_SIZE = define0::Order::M_ORDER_NO;
	using SUPER = define0::AssignerMsgFieldArrayChar<M_SIZE, '0', define0::ArrayAlign<M_SIZE>::ALIGN_RIGHT>;

  public:
	template<std::size_t RVALUE_ARRAY_SIZE>
	static std::size_t Assign_Order_No(char (&lvariable)[M_SIZE], std::span<char, RVALUE_ARRAY_SIZE> rvalue);
	template<std::size_t RVALUE_ARRAY_SIZE>
	static std::size_t Assign_Order_No(char (&lvariable)[M_SIZE], const std::array<char, RVALUE_ARRAY_SIZE>& rvalue);
	static std::size_t Assign_Order_No(char (&lvariable)[M_SIZE], std::string_view rvalue);
};

struct xplum::taifex_msg_proto_sdk::widget_message_field::AssignerUserDefine
{
  protected:
	static constexpr auto& M_SIZE = define0::Order::M_USER_DEFINE;
	using SUPER = define0::AssignerMsgFieldArrayChar<M_SIZE, '0', define0::ArrayAlign<M_SIZE>::ALIGN_RIGHT>;

  public:
	template<std::size_t RVALUE_ARRAY_SIZE>
	static std::size_t Assign_User_Define(char (&lvariable)[M_SIZE], std::span<char, RVALUE_ARRAY_SIZE> rvalue);
	template<std::size_t RVALUE_ARRAY_SIZE>
	static std::size_t Assign_User_Define(char (&lvariable)[M_SIZE], const std::array<char, RVALUE_ARRAY_SIZE>& rvalue);
	static std::size_t Assign_User_Define(char (&lvariable)[M_SIZE], std::string_view rvalue);
};

struct xplum::taifex_msg_proto_sdk::widget_message_field::AssignerSymbol
{
  protected:
	static constexpr auto& M_SIZE = define0::Symbol::M_TEXT_SYMBOL;
	using SUPER = define0::AssignerMsgFieldArrayChar<M_SIZE, ' ', define0::ArrayAlign<M_SIZE>::ALIGN_LEFT>;
	static auto Get_Symbol_Text(view::message_field::SymbolX& symbol_x) -> char (&)[define0::Symbol::M_TEXT_SYMBOL];

  public:
	template<std::size_t RVALUE_ARRAY_SIZE>
	static std::size_t Assign_Symbol_Text(view::message_field::SymbolX& lvariable_symbol_x, std::span<char, RVALUE_ARRAY_SIZE> rvalue);
	template<std::size_t RVALUE_ARRAY_SIZE>
	static std::size_t Assign_Symbol_Text(view::message_field::SymbolX& lvariable_symbol_x, const std::array<char, RVALUE_ARRAY_SIZE>& rvalue);
	static std::size_t Assign_Symbol_Text(view::message_field::SymbolX& lvariable_symbol_x, std::string_view rvalue);
};

struct xplum::taifex_msg_proto_sdk::widget_message_field::ConvertorOrderNo : protected define0::ConvertorBtwStrIntByCustomDigit<define0::DIGIT_TABLE_ORDER_NO, define0::Order::M_ORDER_NO, std::uint32_t>
{
  public:
	static std::optional<std::uint32_t> Convert_Order_No_To_Value(std::string_view txt_value);
	static std::string Convert_Order_No_To_Text_String(std::uint32_t int_value);
	template<std::size_t VALUE_STRING_SIZE = M_STRING_MAX_SIZE>
	static std::unique_ptr<std::array<char, VALUE_STRING_SIZE>> Convert_Order_No_To_Text_Char_Array(std::uint32_t int_value);
};

// ******************************** ******************************** ******************************** ******************************** //
/// xplum::taifex_msg_proto_sdk::widget_message_field::AssignerOrderNo
template<std::size_t RVALUE_ARRAY_SIZE>
auto xplum::taifex_msg_proto_sdk::widget_message_field::AssignerOrderNo::Assign_Order_No(char (&lvariable)[M_SIZE], std::span<char, RVALUE_ARRAY_SIZE> rvalue) -> std::size_t
{
	return SUPER::Assign(lvariable, rvalue);
}
template<std::size_t RVALUE_ARRAY_SIZE>
auto xplum::taifex_msg_proto_sdk::widget_message_field::AssignerOrderNo::Assign_Order_No(char (&lvariable)[M_SIZE], const std::array<char, RVALUE_ARRAY_SIZE>& rvalue) -> std::size_t
{
	return SUPER::Assign(lvariable, rvalue);
}

/// xplum::taifex_msg_proto_sdk::widget_message_field::AssignerUserDefine
template<std::size_t RVALUE_ARRAY_SIZE>
auto xplum::taifex_msg_proto_sdk::widget_message_field::AssignerUserDefine::Assign_User_Define(char (&lvariable)[M_SIZE], std::span<char, RVALUE_ARRAY_SIZE> rvalue) -> std::size_t
{
	return SUPER::Assign(lvariable, rvalue);
}
template<std::size_t RVALUE_ARRAY_SIZE>
auto xplum::taifex_msg_proto_sdk::widget_message_field::AssignerUserDefine::Assign_User_Define(char (&lvariable)[M_SIZE], const std::array<char, RVALUE_ARRAY_SIZE>& rvalue) -> std::size_t
{
	return SUPER::Assign(lvariable, rvalue);
}

/// xplum::taifex_msg_proto_sdk::widget_message_field::AssignerSymbol
template<std::size_t RVALUE_ARRAY_SIZE>
auto xplum::taifex_msg_proto_sdk::widget_message_field::AssignerSymbol::Assign_Symbol_Text(view::message_field::SymbolX& lvariable_symbol_x, std::span<char, RVALUE_ARRAY_SIZE> rvalue) -> std::size_t
{
	return SUPER::Assign(Get_Symbol_Text(lvariable_symbol_x), rvalue);
}
template<std::size_t RVALUE_ARRAY_SIZE>
auto xplum::taifex_msg_proto_sdk::widget_message_field::AssignerSymbol::Assign_Symbol_Text(view::message_field::SymbolX& lvariable_symbol_x, const std::array<char, RVALUE_ARRAY_SIZE>& rvalue) -> std::size_t
{
	return SUPER::Assign(Get_Symbol_Text(lvariable_symbol_x), rvalue);
}

/// xplum::taifex_msg_proto_sdk::widget_message_field::ConvertorOrderNo
template<std::size_t VALUE_STRING_SIZE>
auto xplum::taifex_msg_proto_sdk::widget_message_field::ConvertorOrderNo::Convert_Order_No_To_Text_Char_Array(std::uint32_t int_value) -> std::unique_ptr<std::array<char, VALUE_STRING_SIZE>>
{
	return To_Char_Array(int_value);
}
