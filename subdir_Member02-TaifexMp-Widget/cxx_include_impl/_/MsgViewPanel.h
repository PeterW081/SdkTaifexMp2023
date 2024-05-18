#include_next "xplum_sdkit/taifex_msg_proto/view02/MsgViewPanel.h"
#pragma once

// using xplum_sdkit::taifex_msg_proto::view02::msg_view_element::MsgViewPanel;
//
template <typename TYPE_MSG_VIEW01>
template <std::size_t VAL_BUFFER_SIZE>
auto                                                                                                                            //
    xplum_sdkit::taifex_msg_proto::view02::msg_view_element::                                                                   //
    MsgViewPanel<TYPE_MSG_VIEW01>::FX_ASSIGN_MSG(std::span<std::byte, VAL_BUFFER_SIZE> buffer) -> MsgViewPanel<TYPE_MSG_VIEW01> //
{
  TYPE_MSG_VIEW01::FX_ASSIGN_MSG(buffer);
  return MsgViewPanel<TYPE_MSG_VIEW01>(buffer);
}
//
template <typename TYPE_MSG_VIEW01>
template <std::size_t VAL_BUFFER_SIZE>
  requires std::derived_from<TYPE_MSG_VIEW01, xplum_sdkit::taifex_msg_proto::ancestor::ViewerMsgZipSize<typename TYPE_MSG_VIEW01::T, TYPE_MSG_VIEW01::M_MSG_LENGTH_MAX_VALUE, TYPE_MSG_VIEW01::M_MSG_LENGTH_MIN_VALUE>>
auto                                                                                                                                                            //
    xplum_sdkit::taifex_msg_proto::view02::msg_view_element::                                                                                                   //
    MsgViewPanel<TYPE_MSG_VIEW01>::FX_ASSIGN_MSG(std::span<std::byte, VAL_BUFFER_SIZE> buffer, type::TypeMsgLength msg_length) -> MsgViewPanel<TYPE_MSG_VIEW01> //
{
  TYPE_MSG_VIEW01::FX_ASSIGN_MSG(buffer, msg_length);
  return MsgViewPanel<TYPE_MSG_VIEW01>(buffer);
}
