#pragma once
#include "./PlugerMsg_RE_OrderNo.h"
#pragma
#include "xplum_sdkit/taifex_msg_proto/network_osi_L06/function_msg.h"
#

/// namespace
namespace xplum_sdkit::taifex_msg_proto::view::message_plugin::_nshdr
{
// concept
using xplum_sdkit::taifex_msg_proto::util::ConceptAssert_0_fx_convert_order_no_to_text_char_array;
using xplum_sdkit::taifex_msg_proto::util::ConceptAssert_0_fx_convert_order_no_to_value;

// class
using xplum_sdkit::taifex_msg_proto::ancestor::AssignerMsgFieldArrayChar;
using xplum_sdkit::taifex_msg_proto::ancestor::_nshdr::ArrayAlign;
//
using StdExtent_0_order_no = std::extent<xplum_model::taifex_msg_proto::message_field::array::order_no>;
using StdExtent_0_user_define = std::extent<xplum_model::taifex_msg_proto::message_field::array::user_define>;
using StdExtent_0_symbol_text = std::extent<xplum_model::taifex_msg_proto::message_field::array::symbol_text_0_symbol>;
//
using AssignerOrderNo /*----*/ = AssignerMsgFieldArrayChar<StdExtent_0_order_no::value /*----*/, '0', ArrayAlign<StdExtent_0_order_no::value>::ALIGN_RIGHT>;
using AssignerUserDefine /*-*/ = AssignerMsgFieldArrayChar<StdExtent_0_user_define::value /*-*/, '0', ArrayAlign<StdExtent_0_user_define::value>::ALIGN_RIGHT>;
using AssignerSymbol /*-----*/ = AssignerMsgFieldArrayChar<StdExtent_0_symbol_text::value /*-*/, ' ', ArrayAlign<StdExtent_0_symbol_text::value>::ALIGN_LEFT>;
}

/// PlugerMsg_RE_OrderNo
template <typename TYPE_msg_view>
/*Constructor*/                                       //
xplum_sdkit::taifex_msg_proto::view::message_plugin:: //
    PlugerMsg_RE_OrderNo<TYPE_msg_view>::             //
    PlugerMsg_RE_OrderNo()
{
    using MsgFieldChar0 = xplum_model::taifex_msg_proto::message_field::char0;
    static_assert(                      //
        requires(TYPE_msg_view *thiz) { //
            requires(std::is_same_v<MsgFieldChar0(&)[_nshdr::StdExtent_0_order_no::value], decltype(thiz->m_order_no)>);
            requires(std::is_same_v<MsgFieldChar0(&)[_nshdr::StdExtent_0_user_define::value], decltype(thiz->m_user_define)>);
            requires(std::is_same_v<view::message_field::SymbolX_VIEW, decltype(thiz->m_sym)>);
            requires(std::is_same_v<view::message_field::uint32_VIEW, decltype(thiz->m_order_id)>);
            requires(std::is_same_v<view::message_field::enumerate::ExecType_VIEW, decltype(thiz->m_exec_type)>);
        });
}

/// PlugerMsg_RE_OrderNo - fx_virgin_m_order_no()
template <typename TYPE_msg_view>
auto                                                      //
    xplum_sdkit::taifex_msg_proto::view::message_plugin:: //
    PlugerMsg_RE_OrderNo<TYPE_msg_view>::                 //
    fx_virgin_m_order_no_0_string_view() -> std::string_view
{
    auto &arr = this->thiz->m_order_no;
    return std::string_view(arr, sizeof(arr));
}
template <typename TYPE_msg_view>
template <auto FUNCTION>
auto                                                      //
    xplum_sdkit::taifex_msg_proto::view::message_plugin:: //
    PlugerMsg_RE_OrderNo<TYPE_msg_view>::                 //
    fx_virgin_m_order_no_0_int() -> std::optional<std::uint32_t>
{
    // 	static auto FX_convert_order_no_to_value(std::string_view) -> std::optional<std::uint32_t>;
    static_assert(_nshdr::ConceptAssert_0_fx_convert_order_no_to_value<FUNCTION>);
    return FUNCTION(this->fx_virgin_m_order_no_0_string_view());
}

/// PlugerMsg_RE_OrderNo - fx_assign_m_order_seq()
template <typename TYPE_msg_view>
template <std::size_t RVALUE_array_size>
auto                                                      //
    xplum_sdkit::taifex_msg_proto::view::message_plugin:: //
    PlugerMsg_RE_OrderNo<TYPE_msg_view>::                 //
    fx_assign_m_order_seq(std::span<char, RVALUE_array_size> order_no, type::uint32 order_id) -> std::size_t
{
    this->thiz->m_order_id = order_id;
    return _nshdr::AssignerOrderNo::FX_assign(this->thiz->m_order_no, order_no);
}
template <typename TYPE_msg_view>
template <std::size_t RVALUE_array_size>
auto                                                      //
    xplum_sdkit::taifex_msg_proto::view::message_plugin:: //
    PlugerMsg_RE_OrderNo<TYPE_msg_view>::                 //
    fx_assign_m_order_seq(const std::array<char, RVALUE_array_size> &order_no, type::uint32 order_id) -> std::size_t
{
    this->thiz->m_order_id = order_id;
    return _nshdr::AssignerOrderNo::FX_assign(this->thiz->m_order_no, order_no);
}
template <typename TYPE_msg_view>
auto                                                      //
    xplum_sdkit::taifex_msg_proto::view::message_plugin:: //
    PlugerMsg_RE_OrderNo<TYPE_msg_view>::                 //
    fx_assign_m_order_seq(std::string_view order_no, type::uint32 order_id) -> std::size_t
{
    this->thiz->m_order_id = order_id;
    return _nshdr::AssignerOrderNo::FX_assign(this->thiz->m_order_no, order_no);
}

/// PlugerMsg_RE_OrderNo - fx_assign_m_order_seq_0_int()
template <typename TYPE_msg_view>
template <auto FUNCTION>
auto                                                      //
    xplum_sdkit::taifex_msg_proto::view::message_plugin:: //
    PlugerMsg_RE_OrderNo<TYPE_msg_view>::                 //
    fx_assign_m_order_seq_0_int(std::uint32_t order_no, type::uint32 order_id) -> std::size_t
{
    static_assert(_nshdr::ConceptAssert_0_fx_convert_order_no_to_text_char_array<FUNCTION>);
    this->thiz->m_order_id = order_id;
    auto arr = FUNCTION(order_no);
    return _nshdr::AssignerOrderNo::FX_assign(this->thiz->m_order_no, *arr);
}

/// PlugerMsg_RE_OrderNo - fx_assign_m_order_seq_0_seed()
template <typename TYPE_msg_view>
template <auto FUNCTION>
auto                                                      //
    xplum_sdkit::taifex_msg_proto::view::message_plugin:: //
    PlugerMsg_RE_OrderNo<TYPE_msg_view>::                 //
    fx_assign_m_order_seq_0_seed(ancestor::CounterOrderSeq_V &seed, std::optional<std::uint32_t> order_no0) -> std::size_t
{
    static_assert(_nshdr::ConceptAssert_0_fx_convert_order_no_to_text_char_array<FUNCTION>);
    type::uint32 order_no = order_no0.has_value() ? order_no0.value() : seed.fv_next_order_no_0_prefix_increment();
    type::uint32 order_id = seed.fv_next_order_id_0_prefix_increment(order_no);
    return this->fx_assign_m_order_seq_0_int<FUNCTION>(order_no, order_id);
}
template <typename TYPE_msg_view>
template <auto FUNCTION01, auto FUNCTION02>
auto                                                                                                                     //
    xplum_sdkit::taifex_msg_proto::view::message_plugin::                                                                //
    PlugerMsg_RE_OrderNo<TYPE_msg_view>::                                                                                //
    fx_assign_m_order_seq_0_seed(ancestor::CounterOrderSeq_V &seed, std::optional<std::string> order_no0) -> std::size_t // seed, order_no,
{
    static_assert(_nshdr::ConceptAssert_0_fx_convert_order_no_to_value<FUNCTION01>);
    static_assert(_nshdr::ConceptAssert_0_fx_convert_order_no_to_text_char_array<FUNCTION02>);
    type::uint32 order_no = order_no0.has_value() ? FUNCTION01(order_no0.value()).value() : seed.fv_next_order_no_0_prefix_increment();
    type::uint32 order_id = seed.fv_next_order_id_0_prefix_increment(order_no);
    return this->fx_assign_m_order_seq_0_int<FUNCTION02>(order_no, order_id);
}

/// PlugerMsg_RE_OrderNo - fx_assign_m_user_define()
template <typename TYPE_msg_view>
template <std::size_t RVALUE_array_size>
auto                                                      //
    xplum_sdkit::taifex_msg_proto::view::message_plugin:: //
    PlugerMsg_RE_OrderNo<TYPE_msg_view>::                 //
    fx_assign_m_user_define(std::span<char, RVALUE_array_size> rvalue) -> std::size_t
{
    return _nshdr::AssignerUserDefine::FX_assign(this->thiz->m_user_define, rvalue);
}
template <typename TYPE_msg_view>
template <std::size_t RVALUE_array_size>
auto                                                      //
    xplum_sdkit::taifex_msg_proto::view::message_plugin:: //
    PlugerMsg_RE_OrderNo<TYPE_msg_view>::                 //
    fx_assign_m_user_define(const std::array<char, RVALUE_array_size> &rvalue) -> std::size_t
{
    return _nshdr::AssignerUserDefine::FX_assign(this->thiz->m_user_define, rvalue);
}
template <typename TYPE_msg_view>
auto                                                      //
    xplum_sdkit::taifex_msg_proto::view::message_plugin:: //
    PlugerMsg_RE_OrderNo<TYPE_msg_view>::                 //
    fx_assign_m_user_define(std::string_view rvalue) -> std::size_t
{
    return _nshdr::AssignerUserDefine::FX_assign(this->thiz->m_user_define, rvalue);
}
template <typename TYPE_msg_view>
auto                                                      //
    xplum_sdkit::taifex_msg_proto::view::message_plugin:: //
    PlugerMsg_RE_OrderNo<TYPE_msg_view>::                 //
    fx_virgin_m_user_define_0_string_view() -> std::string_view
{
    auto &arr = this->thiz->m_user_define;
    return std::string_view(arr, sizeof(arr));
}

/// PlugerMsg_RE_OrderNo - fx_assign_m_sym_0_text()
template <typename TYPE_msg_view>
template <std::size_t RVALUE_array_size>
auto                                                      //
    xplum_sdkit::taifex_msg_proto::view::message_plugin:: //
    PlugerMsg_RE_OrderNo<TYPE_msg_view>::                 //
    fx_assign_m_sym_0_text(std::span<char, RVALUE_array_size> rvalue) -> std::size_t
{
    return _nshdr::AssignerSymbol::FX_assign(ez_view::FX_get_symbol_text(this->thiz->m_sym), rvalue);
}
template <typename TYPE_msg_view>
template <std::size_t RVALUE_array_size>
auto                                                      //
    xplum_sdkit::taifex_msg_proto::view::message_plugin:: //
    PlugerMsg_RE_OrderNo<TYPE_msg_view>::                 //
    fx_assign_m_sym_0_text(const std::array<char, RVALUE_array_size> &rvalue) -> std::size_t
{
    return _nshdr::AssignerSymbol::FX_assign(ez_view::FX_get_symbol_text(this->thiz->m_sym), rvalue);
}
template <typename TYPE_msg_view>
auto                                                      //
    xplum_sdkit::taifex_msg_proto::view::message_plugin:: //
    PlugerMsg_RE_OrderNo<TYPE_msg_view>::                 //
    fx_assign_m_sym_0_text(std::string_view rvalue) -> std::size_t
{
    return _nshdr::AssignerSymbol::FX_assign(ez_view::FX_get_symbol_text(this->thiz->m_sym), rvalue);
}
template <typename TYPE_msg_view>
auto                                                      //
    xplum_sdkit::taifex_msg_proto::view::message_plugin:: //
    PlugerMsg_RE_OrderNo<TYPE_msg_view>::                 //
    fx_virgin_m_sym_0_text_0_string_view() -> std::string_view
{
    auto &arr = ez_view::FX_get_symbol_text(this->thiz->m_sym);
    return std::string_view(arr, sizeof(arr));
}
