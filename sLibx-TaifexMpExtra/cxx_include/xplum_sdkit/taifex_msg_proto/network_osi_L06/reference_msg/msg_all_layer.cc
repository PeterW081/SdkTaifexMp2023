#pragma once
#include "./msg_all_layer.h"
#pragma
#include "xplum_sdkit/taifex_msg_proto/network_osi_L06/reference_msg_view/msg_lxx_layer.h"
#include "xplum_sdkit/taifex_msg_proto/network_osi_L06/reference_msg_view/msg_rxx_layer.h"
#

namespace xplum_sdkit::taifex_msg_proto::view
{
template <enumerate::EnumMsgType>                                                   // ENUM_msg_type
extern auto FX_load_msg_on_span(std::span<std::byte>) -> auto;                      // data
template <enumerate::EnumMsgType>                                                   // ENUM_msg_type
extern auto FX_init_msg_to_span(std::span<std::byte>) -> auto;                      // data
template <enumerate::EnumMsgType>                                                   // ENUM_msg_type
extern auto FX_init_msg_to_span(std::span<std::byte>, type::TypeMsgLength) -> auto; // data, msg_length,
}
