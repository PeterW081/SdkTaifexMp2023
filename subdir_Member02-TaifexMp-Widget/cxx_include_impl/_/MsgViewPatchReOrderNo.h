#pragma once
#include_next "xplum_sdkit/taifex_msg_proto/view02/MsgViewPatchReOrderNo.h"
#pragma

#include "xplum_sdkit/taifex_msg_proto/static_function_msg.h"

// using xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign::MsgViewPatchReOrderNo;
// > fx_virgin_m_order_no();
//
template <typename TYPE_MSG_VIEW02_PANEL>
auto xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign:: //
    MsgViewPatchReOrderNo<TYPE_MSG_VIEW02_PANEL>::fx_virgin_m_order_no_0_string_view() -> std::string_view {
  auto &arr = this->thiz->m_order_no;
  return std::string_view(arr, sizeof(arr));
}
template <typename TYPE_MSG_VIEW02_PANEL>
template <auto FUNCTION>
  requires xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nshdr::FX_CONCEPT_0_FX_CONVERT_ORDER_NO_TO_VALUE<FUNCTION>
auto xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign:: //
    MsgViewPatchReOrderNo<TYPE_MSG_VIEW02_PANEL>::fx_virgin_m_order_no_0_int() -> std::optional<std::uint32_t> {
  // 	static auto FX_CONVERT_ORDER_NO_TO_VALUE(std::string_view) -> std::optional<std::uint32_t>;
  return FUNCTION(this->fx_virgin_m_order_no_0_string_view());
}

// using xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign::MsgViewPatchReOrderNo;
// > fx_virgin_m_order_no();
//
template <typename TYPE_MSG_VIEW02_PANEL>
template <std::size_t RVALUE_ARRAY_SIZE>
auto xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign:: //
    MsgViewPatchReOrderNo<TYPE_MSG_VIEW02_PANEL>::fx_assign_m_order_seq(std::span<char, RVALUE_ARRAY_SIZE> order_no, type::uint32 order_id) -> std::size_t {
  this->thiz->m_order_id = order_id;
  return AssignerOrderNo::Assign(this->thiz->m_order_no, order_no);
}
template <typename TYPE_MSG_VIEW02_PANEL>
template <std::size_t RVALUE_ARRAY_SIZE>
auto xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign:: //
    MsgViewPatchReOrderNo<TYPE_MSG_VIEW02_PANEL>::fx_assign_m_order_seq(const std::array<char, RVALUE_ARRAY_SIZE> &order_no, type::uint32 order_id) -> std::size_t {
  this->thiz->m_order_id = order_id;
  return AssignerOrderNo::Assign(this->thiz->m_order_no, order_no);
}
template <typename TYPE_MSG_VIEW02_PANEL>
auto xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign:: //
    MsgViewPatchReOrderNo<TYPE_MSG_VIEW02_PANEL>::fx_assign_m_order_seq(std::string_view order_no, type::uint32 order_id) -> std::size_t {
  this->thiz->m_order_id = order_id;
  return AssignerOrderNo::Assign(this->thiz->m_order_no, order_no);
}
// > fx_assign_m_order_seq_0_int();
//
template <typename TYPE_MSG_VIEW02_PANEL>
template <auto FUNCTION>
  requires xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nshdr::FX_CONCEPT_0_FX_CONVERT_ORDER_NO_TO_TEXT_CHAR_ARRAY<FUNCTION>
auto xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign::                                                                      //
    MsgViewPatchReOrderNo<TYPE_MSG_VIEW02_PANEL>::fx_assign_m_order_seq_0_int(std::uint32_t order_no, type::uint32 order_id) -> std::size_t // seed, order_no, order_id
{
  this->thiz->m_order_id = order_id;
  auto arr = FUNCTION(order_no);
  return AssignerOrderNo::Assign(this->thiz->m_order_no, *arr);
}
// > fx_assign_m_order_seq_0_seed();
//
template <typename TYPE_MSG_VIEW02_PANEL>
template <auto FUNCTION>
  requires xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nshdr::FX_CONCEPT_0_FX_CONVERT_ORDER_NO_TO_TEXT_CHAR_ARRAY<FUNCTION>
auto xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign::                                                                                                  //
    MsgViewPatchReOrderNo<TYPE_MSG_VIEW02_PANEL>::fx_assign_m_order_seq_0_seed(ancestor::CounterOrderSeqV &seed, std::optional<std::uint32_t> order_no0) -> std::size_t // seed, order_no,
{
  type::uint32 order_no = order_no0.has_value() ? order_no0.value() : seed.next_order_no_0_prefix_increment();
  type::uint32 order_id = seed.next_order_id_0_prefix_increment(order_no);
  return this->fx_assign_m_order_seq_0_int<FUNCTION>(order_no, order_id);
}
template <typename TYPE_MSG_VIEW02_PANEL>
template <auto FUNCTION01, auto FUNCTION02>
  requires true                                                                                                                                                       //
           && xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nshdr::FX_CONCEPT_0_FX_CONVERT_ORDER_NO_TO_VALUE<FUNCTION01>                                  //
           && xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nshdr::FX_CONCEPT_0_FX_CONVERT_ORDER_NO_TO_TEXT_CHAR_ARRAY<FUNCTION02>                        //
auto xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign::                                                                                                //
    MsgViewPatchReOrderNo<TYPE_MSG_VIEW02_PANEL>::fx_assign_m_order_seq_0_seed(ancestor::CounterOrderSeqV &seed, std::optional<std::string> order_no0) -> std::size_t // seed, order_no,
{
  type::uint32 order_no = order_no0.has_value() ? FUNCTION01(order_no0.value()).value() : seed.next_order_no_0_prefix_increment();
  type::uint32 order_id = seed.next_order_id_0_prefix_increment(order_no);
  return this->fx_assign_m_order_seq_0_int<FUNCTION02>(order_no, order_id);
}

// using xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign::MsgViewPatchReOrderNo;
// > fx_assign_m_user_define();
//
template <typename TYPE_MSG_VIEW02_PANEL>
template <std::size_t RVALUE_ARRAY_SIZE>
auto xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign:: //
    MsgViewPatchReOrderNo<TYPE_MSG_VIEW02_PANEL>::fx_assign_m_user_define(std::span<char, RVALUE_ARRAY_SIZE> rvalue) -> std::size_t {
  return AssignerUserDefine::Assign(this->thiz->m_user_define, rvalue);
}
template <typename TYPE_MSG_VIEW02_PANEL>
template <std::size_t RVALUE_ARRAY_SIZE>
auto xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign:: //
    MsgViewPatchReOrderNo<TYPE_MSG_VIEW02_PANEL>::fx_assign_m_user_define(const std::array<char, RVALUE_ARRAY_SIZE> &rvalue) -> std::size_t {
  return AssignerUserDefine::Assign(this->thiz->m_user_define, rvalue);
}
template <typename TYPE_MSG_VIEW02_PANEL>
auto xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign:: //
    MsgViewPatchReOrderNo<TYPE_MSG_VIEW02_PANEL>::fx_assign_m_user_define(std::string_view rvalue) -> std::size_t {
  return AssignerUserDefine::Assign(this->thiz->m_user_define, rvalue);
}
template <typename TYPE_MSG_VIEW02_PANEL>
auto xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign:: //
    MsgViewPatchReOrderNo<TYPE_MSG_VIEW02_PANEL>::fx_virgin_m_user_define_0_string_view() -> std::string_view {
  auto &arr = this->thiz->m_user_define;
  return std::string_view(arr, sizeof(arr));
}

// using xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign::MsgViewPatchReOrderNo;
// > fx_assign_m_sym_0_text()
//
template <typename TYPE_MSG_VIEW02_PANEL>
template <std::size_t RVALUE_ARRAY_SIZE>
auto xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign:: //
    MsgViewPatchReOrderNo<TYPE_MSG_VIEW02_PANEL>::fx_assign_m_sym_0_text(std::span<char, RVALUE_ARRAY_SIZE> rvalue) -> std::size_t {
  return AssignerSymbol::Assign(ez_view::FX_GET_SYMBOL_TEXT_IN_VIEW_MSG_FIELD(this->thiz->m_sym), rvalue);
}
template <typename TYPE_MSG_VIEW02_PANEL>
template <std::size_t RVALUE_ARRAY_SIZE>
auto xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign:: //
    MsgViewPatchReOrderNo<TYPE_MSG_VIEW02_PANEL>::fx_assign_m_sym_0_text(const std::array<char, RVALUE_ARRAY_SIZE> &rvalue) -> std::size_t {
  return AssignerSymbol::Assign(ez_view::FX_GET_SYMBOL_TEXT_IN_VIEW_MSG_FIELD(this->thiz->m_sym), rvalue);
}
template <typename TYPE_MSG_VIEW02_PANEL>
auto xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign:: //
    MsgViewPatchReOrderNo<TYPE_MSG_VIEW02_PANEL>::fx_assign_m_sym_0_text(std::string_view rvalue) -> std::size_t {
  return AssignerSymbol::Assign(ez_view::FX_GET_SYMBOL_TEXT_IN_VIEW_MSG_FIELD(this->thiz->m_sym), rvalue);
}
template <typename TYPE_MSG_VIEW02_PANEL>
auto xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign:: //
    MsgViewPatchReOrderNo<TYPE_MSG_VIEW02_PANEL>::fx_virgin_m_sym_0_text_0_string_view() -> std::string_view {
  auto &arr = ez_view::FX_GET_SYMBOL_TEXT_IN_VIEW_MSG_FIELD(this->thiz->m_sym);
  return std::string_view(arr, sizeof(arr));
}
