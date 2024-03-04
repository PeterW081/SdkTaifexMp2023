#include_next "xplum_sdkit/taifex_msg_proto/view02/MsgViewPatchSpL41.h"
#pragma once

// using xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign::MsgViewPatchSpL41;
//
template <typename TYPE_MSG_VIEW02_PANEL>
auto xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign:: //
    MsgViewPatchSpL41<TYPE_MSG_VIEW02_PANEL>::fx_virgin_m_data() -> std::list<kitbag::UnionL41DataMember> {
  namespace ns0_origin_mt_sizeof_msg_content = xplum_model::taifex_msg_proto::mt_sizeof_msg_content;
  std::list<kitbag::UnionL41DataMember> result;

  const auto L41_data_size = this->thiz->m_file_size;
  const auto L41_data_data = this->thiz->m_data.data();
  for (std::intptr_t i = 0, j = L41_data_size; i < j;) {
    void *message = L41_data_data + i;
    auto message_head = view::message_field::MsgHdr(message);
    i += static_cast<std::intptr_t>(ns0_origin_mt_sizeof_msg_content::SIZE_OUT_OF_MSG_LENGTH) + message_head.m_msg_length;
    switch (message_head.m_message_type.enum_value()) {
    case view::message_field::enumerate::MsgType::EnumType::R02:
      result.emplace_back(reinterpret_cast<view::message::origin::R02 *>(message));
      break;
    case view::message_field::enumerate::MsgType::EnumType::R03:
      result.emplace_back(reinterpret_cast<view::message::origin::R03 *>(message));
      break;
    default:
      result.emplace_back() = std::span<const std::byte>(reinterpret_cast<const std::byte *>(message), ns0_origin_mt_sizeof_msg_content::SIZE_OUT_OF_MSG_LENGTH + message_head.m_msg_length);
      break;
    }
  }
  return result;
}
