#pragma once
#include "xplum/prototype/AssignerArray.h"

namespace xplum::taifex_msg_proto_sdk::prototype
{
	namespace define0
	{
		using xplum::prototype::AssignerArrayChar;
		template<std::size_t VALUE_ARRAY_SIZE>
		using ArrayAlign = typename xplum::prototype::AssignerArrayChar<VALUE_ARRAY_SIZE>::Align;
	}
	template<std::size_t VALUE_ARRAY_SIZE, char VALUE_ARRAY_FILL, define0::ArrayAlign<VALUE_ARRAY_SIZE> VALUE_ARRAY_ALIGN>
	class AssignerMsgFieldArrayChar;
}

template<std::size_t VALUE_ARRAY_SIZE, char VALUE_ARRAY_FILL, typename xplum::prototype::AssignerArrayChar<VALUE_ARRAY_SIZE>::Align VALUE_ARRAY_ALIGN>
class xplum::taifex_msg_proto_sdk::prototype::AssignerMsgFieldArrayChar : protected define0::AssignerArrayChar<VALUE_ARRAY_SIZE>
{
	using SUPER = define0::AssignerArrayChar<VALUE_ARRAY_SIZE>;
	static const inline typename SUPER::AdvancedOption M_Advanced_Option = {
		.align = VALUE_ARRAY_ALIGN,
		.filler = VALUE_ARRAY_FILL,
	};
  public:
	using Type = typename SUPER::Type;
	static inline const auto& M_SIZE = SUPER::M_SIZE;
	static const auto M_FILL = VALUE_ARRAY_FILL;
	static const auto M_ALIGN = VALUE_ARRAY_ALIGN;

	template<std::size_t RVALUE_ARRAY_SIZE>
	static std::size_t Assign(Type (&lvariable)[M_SIZE], std::span<Type, RVALUE_ARRAY_SIZE> rvalue);
	template<std::size_t RVALUE_ARRAY_SIZE>
	static std::size_t Assign(Type (&lvariable)[M_SIZE], const std::array<Type, RVALUE_ARRAY_SIZE>& rvalue);
	static std::size_t Assign(Type (&lvariable)[M_SIZE], std::string_view rvalue);
};

// ******************************** ******************************** ******************************** ******************************** //
template<std::size_t TP01, char TP02, typename xplum::prototype::AssignerArrayChar<TP01>::Align TP03>
template<std::size_t RVALUE_ARRAY_SIZE>
auto xplum::taifex_msg_proto_sdk::prototype::AssignerMsgFieldArrayChar<TP01, TP02, TP03>::Assign(Type (&lvariable)[M_SIZE], std::span<Type, RVALUE_ARRAY_SIZE> rvalue) -> std::size_t
{
	if constexpr(RVALUE_ARRAY_SIZE == M_SIZE)
	{
		return SUPER::Assign(lvariable, rvalue);
	}
	if constexpr(RVALUE_ARRAY_SIZE == std::dynamic_extent)
	{
		if(rvalue.size() == M_SIZE)
		{
			return SUPER::Assign(lvariable, rvalue);
		}
	}
	return SUPER::Advanced_Assign(static_cast<const typename SUPER::AdvancedOption&&>(M_Advanced_Option), lvariable, rvalue);
}

// ******************************** ******************************** ******************************** ******************************** //
template<std::size_t TP01, char TP02, typename xplum::prototype::AssignerArrayChar<TP01>::Align TP03>
template<std::size_t RVALUE_ARRAY_SIZE>
auto xplum::taifex_msg_proto_sdk::prototype::AssignerMsgFieldArrayChar<TP01, TP02, TP03>::Assign(Type (&lvariable)[M_SIZE], const std::array<Type, RVALUE_ARRAY_SIZE>& rvalue) -> std::size_t
{
	return Assign(lvariable, std::span<Type, RVALUE_ARRAY_SIZE>(const_cast<Type*>(rvalue.data()), RVALUE_ARRAY_SIZE));
}

template<std::size_t TP01, char TP02, typename xplum::prototype::AssignerArrayChar<TP01>::Align TP03>
auto xplum::taifex_msg_proto_sdk::prototype::AssignerMsgFieldArrayChar<TP01, TP02, TP03>::Assign(Type (&lvariable)[M_SIZE], std::string_view rvalue) -> std::size_t
{
	return Assign(lvariable, std::span(const_cast<Type*>(rvalue.data()), rvalue.size()));
}
