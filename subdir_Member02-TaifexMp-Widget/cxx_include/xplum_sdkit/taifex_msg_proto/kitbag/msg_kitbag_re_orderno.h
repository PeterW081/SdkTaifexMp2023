#pragma once
#include "xplum/ancestor_algorithm/ConvertorBtwStrIntByCustomDigit.h"
#include "xplum_model/taifex_msg_proto/structure_message_field/msg_field_sizeof_array.h"
#include "xplum_sdkit/taifex_msg_proto/ancestor/CounterOrderSeqV.h"

namespace xplum_sdkit::taifex_msg_proto::kitbag::_nshdr {
using xplum::ancestor::ConvertorBtwStrIntByCustomDigit;
using xplum_model::taifex_msg_proto::message_field::sizeof_array::Order;
static constexpr char DIGIT_TABLE_ORDER_NO[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
}

namespace xplum_sdkit::taifex_msg_proto::kitbag::_nsign {
template <auto FUNCTION>
concept FX_CONCEPT_0_FX_CONVERT_ORDER_NO_TO_VALUE = std::is_same<typename std::invoke_result<decltype(FUNCTION), std::string_view>::type, std::optional<std::uint32_t>>::value;
template <auto FUNCTION>
concept FX_CONCEPT_0_FX_CONVERT_ORDER_NO_TO_TEXT_CHAR_ARRAY = //
    requires(typename std::invoke_result<decltype(FUNCTION), std::uint32_t>::type::element_type func_return_0_ptr_element_type) {
      requires std::tuple_size<decltype(func_return_0_ptr_element_type)>::value <= _nshdr::Order::M_SIZEOF_ARR_0_ORDER_NO;
      requires std::is_same<decltype(func_return_0_ptr_element_type), std::array<char, std::tuple_size<decltype(func_return_0_ptr_element_type)>::value>>::value;
    };
}

namespace xplum_sdkit::taifex_msg_proto::kitbag {
// Counter: OrderNo、OrderId
using CounterOrderSeqV = ancestor::CounterOrderSeqV;
class CounterOrderSeqSimple;

// Convertor: OrderNo
struct ConvertorOrderNo;
using _nsign::FX_CONCEPT_0_FX_CONVERT_ORDER_NO_TO_TEXT_CHAR_ARRAY;
using _nsign::FX_CONCEPT_0_FX_CONVERT_ORDER_NO_TO_VALUE;
}

class xplum_sdkit::taifex_msg_proto::kitbag:: //
    CounterOrderSeqSimple                     //
    : public CounterOrderSeqV {
public:
  auto storage_load(std::unique_ptr<type::uint32> *order_no, std::map<type::uint32, type::uint32> *map_K_order_no_V_order_id) -> bool;
  auto storage_save(std::unique_ptr<type::uint32> *order_no, std::map<type::uint32, type::uint32> *map_K_order_no_V_order_id) const -> bool;

protected:
  auto storage_load0(std::nullptr_t melon, ...) -> bool override;
  auto storage_save0(std::nullptr_t melon, ...) const -> bool override;
};

struct xplum_sdkit::taifex_msg_proto::kitbag:: //
    ConvertorOrderNo                           //
    : protected _nshdr::ConvertorBtwStrIntByCustomDigit<_nshdr::DIGIT_TABLE_ORDER_NO, _nshdr::Order::M_SIZEOF_ARR_0_ORDER_NO, std::uint32_t> {
public:
  static auto FX_CONVERT_ORDER_NO_TO_VALUE(std::string_view) -> std::optional<std::uint32_t>;
  static auto FX_CONVERT_ORDER_NO_TO_TEXT_STRING(std::uint32_t) -> std::string;
  template <std::size_t VALUE_STRING_SIZE = M_STRING_MAX_SIZE> static auto FX_CONVERT_ORDER_NO_TO_TEXT_CHAR_ARRAY(std::uint32_t int_value) -> std::unique_ptr<std::array<char, VALUE_STRING_SIZE>>;

private:
  static_assert(_nsign::FX_CONCEPT_0_FX_CONVERT_ORDER_NO_TO_VALUE<FX_CONVERT_ORDER_NO_TO_VALUE>);                       // int -> opt<int/*解析錯誤則無數值*/>
  static_assert(_nsign::FX_CONCEPT_0_FX_CONVERT_ORDER_NO_TO_TEXT_CHAR_ARRAY<FX_CONVERT_ORDER_NO_TO_TEXT_CHAR_ARRAY<>>); // int -> cs[VALUE_STRING_SIZE]
};
