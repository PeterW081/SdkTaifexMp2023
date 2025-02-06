#pragma once
#include "./msg_util_RE_orderno.h"
#pragma
#include "xplum/ancestor_algorithm/ConvertorBtwStrIntByCustomDigit.h"
#include "xplum_sdkit/taifex_msg_proto/ancestor/CounterOrderSeq_V.h"
#include "xplum_model/taifex_msg_proto/network_osi_L06/structure_msg_field/msg_field_array.h"
#

///
namespace xplum_sdkit::taifex_msg_proto::util::_nshdr
{
using xplum::ancestor::ConvertorBtwStrIntByCustomDigit;
using xplum_model::taifex_msg_proto::message_field::array::order_no;
extern inline constexpr char G_digit_table_order_no[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
}
namespace xplum_sdkit::taifex_msg_proto::util
{
// Counter: OrderNo、OrderId
using CounterOrderSeqV = ancestor::CounterOrderSeq_V;
class CounterOrderSeqSimple;

// Convertor: OrderNo
struct ConvertorOrderNo;

// ---
template <auto FUNCTION>
concept ConceptAssert_0_fx_convert_order_no_to_value = std::is_same<typename std::invoke_result<decltype(FUNCTION), std::string_view>::type, std::optional<std::uint32_t>>::value;
template <auto FUNCTION>
concept ConceptAssert_0_fx_convert_order_no_to_text_char_array = //
    requires(typename std::invoke_result<decltype(FUNCTION), std::uint32_t>::type::element_type func_return_0_ptr_element_type) {
        requires std::extent<decltype(func_return_0_ptr_element_type)>::value <= std::extent<_nshdr::order_no>::value;
        requires std::is_same<decltype(func_return_0_ptr_element_type), std::array<char, std::tuple_size<decltype(func_return_0_ptr_element_type)>::value>>::value;
    };
}

/// CounterOrderSeqSimple
class                                     //
    xplum_sdkit::taifex_msg_proto::util:: //
    CounterOrderSeqSimple                 //
    : public CounterOrderSeq_V
{
  public:
    auto fx_storage_load(std::unique_ptr<type::uint32> *order_no, std::map<type::uint32, type::uint32> *map_K_order_no_V_order_id) -> bool;
    auto fx_storage_save(std::unique_ptr<type::uint32> *order_no, std::map<type::uint32, type::uint32> *map_K_order_no_V_order_id) const -> bool;

  protected:
    auto fv_storage_load0(std::nullptr_t melon, ...) -> bool override;
    auto fv_storage_save0(std::nullptr_t melon, ...) const -> bool override;
};

/// ConvertorOrderNo
struct                                    //
    xplum_sdkit::taifex_msg_proto::util:: //
    ConvertorOrderNo                      //
    : protected _nshdr::ConvertorBtwStrIntByCustomDigit<_nshdr::G_digit_table_order_no, std::extent<_nshdr::order_no>::value, std::uint32_t>
{
  public:
    static auto FX_convert_order_no_to_value(std::string_view) -> std::optional<std::uint32_t>;
    static auto FX_convert_order_no_to_text_string(std::uint32_t) -> std::string;
    template <std::size_t VALUE_string_size = M_STRING_MAX_SIZE>
    static auto FX_convert_order_no_to_text_char_array(std::uint32_t) -> std::unique_ptr<std::array<char, VALUE_string_size>>;

  private:
    static_assert(ConceptAssert_0_fx_convert_order_no_to_value<FX_convert_order_no_to_value>);                       // int -> opt<int/*解析錯誤則無數值*/>
    static_assert(ConceptAssert_0_fx_convert_order_no_to_text_char_array<FX_convert_order_no_to_text_char_array<>>); // int -> cs[VALUE_STRING_SIZE]
};
