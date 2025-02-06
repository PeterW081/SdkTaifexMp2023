#pragma once
#include "./PlugerMsg_RE_OrderNo.h"
#pragma
#include "xplum/ancestor/Pluginer.h"
#include "xplum_sdkit/taifex_msg_proto/ancestor/AssignerMsgFieldArrayChar.h"
#include "xplum_sdkit/taifex_msg_proto/network_osi_L06/partition_msg/msg_util_RE_orderno.h"
#

/// namespace
namespace xplum_sdkit::taifex_msg_proto::view::message_plugin
{
template <typename TYPE_msg_view>
class PlugerMsg_RE_OrderNo;
}

/// class - PlugerMsg_RE_OrderNo
template <typename TYPE_msg_view>
class                                                     //
    xplum_sdkit::taifex_msg_proto::view::message_plugin:: //
    PlugerMsg_RE_OrderNo                                  //
    : public xplum::ancestor::Pluginer<PlugerMsg_RE_OrderNo<TYPE_msg_view>, TYPE_msg_view>,
      private xplum_sdkit::taifex_msg_proto::util::ConvertorOrderNo
{
  protected:
    explicit PlugerMsg_RE_OrderNo();

  public:
    // ---
    // fx_virgin_m_order_no();
    auto fx_virgin_m_order_no_0_string_view() -> std::string_view;
    template <auto FUNCTION = FX_convert_order_no_to_value>
    auto fx_virgin_m_order_no_0_int() -> std::optional<std::uint32_t>;

    // ---
    // fx_assign_m_order_seq();
    template <std::size_t RVALUE_array_size>                                                              // order_no, order_id,
    auto fx_assign_m_order_seq(const std::span<char, RVALUE_array_size>, type::uint32) -> std::size_t;    // ^^^
    template <std::size_t RVALUE_array_size>                                                              // ^^^
    auto fx_assign_m_order_seq(const std::array<char, RVALUE_array_size> &, type::uint32) -> std::size_t; // ^^^
    auto fx_assign_m_order_seq(const std::string_view, type::uint32) -> std::size_t;                      // ^^^
    // fx_assign_m_order_seq_0_int();
    template <auto FUNCTION = FX_convert_order_no_to_text_char_array<>>           // order_no, order_id,
    auto fx_assign_m_order_seq_0_int(std::uint32_t, type::uint32) -> std::size_t; // ^^^
    // fx_assign_m_order_seq_0_seed();
    template <auto FUNCTION = FX_convert_order_no_to_text_char_array<>>                                                           // seed, order_no,
    auto fx_assign_m_order_seq_0_seed(ancestor::CounterOrderSeq_V &, std::optional<std::uint32_t> = std::nullopt) -> std::size_t; // ^^^
    template <auto FUNCTION01 = FX_convert_order_no_to_value, auto FUNCTION02 = FX_convert_order_no_to_text_char_array<>>
    auto fx_assign_m_order_seq_0_seed(ancestor::CounterOrderSeq_V &, std::optional<std::string>) -> std::size_t; // ^^^

    // ---
    // fx_assign_m_user_define(), fx_virgin_m_user_define(),
    auto fx_virgin_m_user_define_0_string_view() -> std::string_view;
    template <std::size_t RVALUE_array_size>
    auto fx_assign_m_user_define(const std::span<char, RVALUE_array_size>) -> std::size_t;
    template <std::size_t RVALUE_array_size>
    auto fx_assign_m_user_define(const std::array<char, RVALUE_array_size> &) -> std::size_t;
    auto fx_assign_m_user_define(const std::string_view) -> std::size_t;

    // ---
    // fx_assign_m_sym_0_text(), fx_virgin_m_sym_0_text(),
    auto fx_virgin_m_sym_0_text_0_string_view() -> std::string_view;
    template <std::size_t RVALUE_array_size>
    auto fx_assign_m_sym_0_text(const std::span<char, RVALUE_array_size>) -> std::size_t;    // rvalue,
    template <std::size_t RVALUE_array_size>                                                 // ^^^
    auto fx_assign_m_sym_0_text(const std::array<char, RVALUE_array_size> &) -> std::size_t; // ^^^
    auto fx_assign_m_sym_0_text(const std::string_view) -> std::size_t;                      // ^^^
};
