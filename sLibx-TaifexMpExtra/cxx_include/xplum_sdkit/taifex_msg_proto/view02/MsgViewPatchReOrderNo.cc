#pragma once
#include "./MsgViewPatchReOrderNo.h"
#pragma

#include "xplum/ancestor/Pluginer.h"
#include "xplum_sdkit/taifex_msg_proto/ancestor/AssignerMsgFieldArrayChar.h"
#include "xplum_sdkit/taifex_msg_proto/kitbag/msg_kitbag_re_orderno.h"

namespace xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nshdr
{
// concept
using xplum_sdkit::taifex_msg_proto::kitbag::FX_CONCEPT_0_FX_CONVERT_ORDER_NO_TO_TEXT_CHAR_ARRAY;
using xplum_sdkit::taifex_msg_proto::kitbag::FX_CONCEPT_0_FX_CONVERT_ORDER_NO_TO_VALUE;

// class
using xplum_sdkit::taifex_msg_proto::ancestor::AssignerMsgFieldArrayChar;
using xplum_sdkit::taifex_msg_proto::ancestor::_nshdr::ArrayAlign;
using xplum_sdkit::taifex_msg_proto::kitbag::ConvertorOrderNo;
using MsgFieldChar0 = xplum_model::taifex_msg_proto::message_field::char0;

// class - 02
using StdExtent_0_order_no = std::extent<xplum_model::taifex_msg_proto::message_field::array::order_no>;
using StdExtent_0_user_define = std::extent<xplum_model::taifex_msg_proto::message_field::array::user_define>;
using StdExtent_0_symbol_text = std::extent<xplum_model::taifex_msg_proto::message_field::array::symbol_text_0_symbol>;

}
namespace xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign
{
template <typename TYPE_MSG_VIEW01>
concept MsgViewPatchReOrderNo_Concept = //
    requires(TYPE_MSG_VIEW01 *thiz) {   //
        requires(std::is_same_v<_nshdr::MsgFieldChar0(&)[_nshdr::StdExtent_0_order_no::value], decltype(thiz->m_order_no)>);
        requires(std::is_same_v<_nshdr::MsgFieldChar0(&)[_nshdr::StdExtent_0_user_define::value], decltype(thiz->m_user_define)>);
        requires(std::is_same_v<view::message_field::SymbolX, decltype(thiz->m_sym)>);
        requires(std::is_same_v<view::message_field::uint32, decltype(thiz->m_order_id)>);
        requires(std::is_same_v<view::message_field::enumerate::ExecType, decltype(thiz->m_exec_type)>);
    };
template <typename>
class MsgViewPatchReOrderNo;
}

namespace xplum_sdkit::taifex_msg_proto::view02::msg_view_element
{
template <typename TYPE_MSG_VIEW01, typename TYPE_MSG_VIEW02_PANEL>
using MsgViewPatchReOrderNo = std::conditional<_nsign::MsgViewPatchReOrderNo_Concept<TYPE_MSG_VIEW01>, _nsign::MsgViewPatchReOrderNo<TYPE_MSG_VIEW02_PANEL>, typename _nsign::MsgViewPatchReOrderNo<TYPE_MSG_VIEW02_PANEL>::ClassMock>::type;
}

template <typename TYPE_MSG_VIEW02_PANEL>                               //
class xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign:: //
    MsgViewPatchReOrderNo                                               //
    : public xplum::ancestor::PluginerWay02<MsgViewPatchReOrderNo<TYPE_MSG_VIEW02_PANEL>, TYPE_MSG_VIEW02_PANEL>,
      _nshdr::ConvertorOrderNo
{
    using AssignerOrderNo = _nshdr::AssignerMsgFieldArrayChar<_nshdr::StdExtent_0_order_no::value, '0', _nshdr::ArrayAlign<_nshdr::StdExtent_0_order_no::value>::ALIGN_RIGHT>;
    using AssignerUserDefine = _nshdr::AssignerMsgFieldArrayChar<_nshdr::StdExtent_0_user_define::value, '0', _nshdr::ArrayAlign<_nshdr::StdExtent_0_user_define::value>::ALIGN_RIGHT>;
    using AssignerSymbol = _nshdr::AssignerMsgFieldArrayChar<_nshdr::StdExtent_0_symbol_text::value, ' ', _nshdr::ArrayAlign<_nshdr::StdExtent_0_symbol_text::value>::ALIGN_LEFT>;

  public:
    ///
    // fx_virgin_m_order_no();
    auto fx_virgin_m_order_no_0_string_view() -> std::string_view;
    template <auto FUNCTION = FX_CONVERT_ORDER_NO_TO_VALUE>
        requires _nshdr::FX_CONCEPT_0_FX_CONVERT_ORDER_NO_TO_VALUE<FUNCTION>
    auto fx_virgin_m_order_no_0_int() -> std::optional<std::uint32_t>;

    ///
    // fx_assign_m_order_seq();
    template <std::size_t RVALUE_ARRAY_SIZE>                                                              // order_no, order_id,
    auto fx_assign_m_order_seq(const std::span<char, RVALUE_ARRAY_SIZE>, type::uint32) -> std::size_t;    // ^^^
    template <std::size_t RVALUE_ARRAY_SIZE>                                                              // ^^^
    auto fx_assign_m_order_seq(const std::array<char, RVALUE_ARRAY_SIZE> &, type::uint32) -> std::size_t; // ^^^
    auto fx_assign_m_order_seq(const std::string_view, type::uint32) -> std::size_t;                      // ^^^
    // fx_assign_m_order_seq_0_int();
    template <auto FUNCTION = FX_CONVERT_ORDER_NO_TO_TEXT_CHAR_ARRAY<>>                // order_no, order_id,
        requires _nshdr::FX_CONCEPT_0_FX_CONVERT_ORDER_NO_TO_TEXT_CHAR_ARRAY<FUNCTION> // ^^^
    auto fx_assign_m_order_seq_0_int(std::uint32_t, type::uint32) -> std::size_t;      // ^^^
    // fx_assign_m_order_seq_0_seed();
    template <auto FUNCTION = FX_CONVERT_ORDER_NO_TO_TEXT_CHAR_ARRAY<>>                                                          // seed, order_no,
        requires _nshdr::FX_CONCEPT_0_FX_CONVERT_ORDER_NO_TO_TEXT_CHAR_ARRAY<FUNCTION>                                           // ^^^
    auto fx_assign_m_order_seq_0_seed(ancestor::CounterOrderSeqV &, std::optional<std::uint32_t> = std::nullopt) -> std::size_t; // ^^^
    template <auto FUNCTION01 = FX_CONVERT_ORDER_NO_TO_VALUE, auto FUNCTION02 = FX_CONVERT_ORDER_NO_TO_TEXT_CHAR_ARRAY<>>
        requires true && _nshdr::FX_CONCEPT_0_FX_CONVERT_ORDER_NO_TO_VALUE<FUNCTION01> && _nshdr::FX_CONCEPT_0_FX_CONVERT_ORDER_NO_TO_TEXT_CHAR_ARRAY<FUNCTION02>
    auto fx_assign_m_order_seq_0_seed(ancestor::CounterOrderSeqV &, std::optional<std::string>) -> std::size_t; // ^^^

    ///
    // fx_assign_m_user_define(), fx_virgin_m_user_define(),
    auto fx_virgin_m_user_define_0_string_view() -> std::string_view;
    template <std::size_t RVALUE_ARRAY_SIZE>
    auto fx_assign_m_user_define(const std::span<char, RVALUE_ARRAY_SIZE>) -> std::size_t;
    template <std::size_t RVALUE_ARRAY_SIZE>
    auto fx_assign_m_user_define(const std::array<char, RVALUE_ARRAY_SIZE> &) -> std::size_t;
    auto fx_assign_m_user_define(const std::string_view) -> std::size_t;

    ///
    // fx_assign_m_sym_0_text(), fx_virgin_m_sym_0_text(),
    auto fx_virgin_m_sym_0_text_0_string_view() -> std::string_view;
    template <std::size_t RVALUE_ARRAY_SIZE>
    auto fx_assign_m_sym_0_text(const std::span<char, RVALUE_ARRAY_SIZE>) -> std::size_t;    // rvalue,
    template <std::size_t RVALUE_ARRAY_SIZE>                                                 // ^^^
    auto fx_assign_m_sym_0_text(const std::array<char, RVALUE_ARRAY_SIZE> &) -> std::size_t; // ^^^
    auto fx_assign_m_sym_0_text(const std::string_view) -> std::size_t;                      // ^^^
};
