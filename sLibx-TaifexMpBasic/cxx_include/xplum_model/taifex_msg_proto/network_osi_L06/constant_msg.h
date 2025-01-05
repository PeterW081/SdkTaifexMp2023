#pragma once
#include "xplum_model/taifex_msg_proto/_CONFIG_MACRO.h"
#include "xplum_model/taifex_msg_proto/_define_cxx.h"
#include "xplum_model/taifex_msg_proto/network_osi_L06/structure_msg_field/msg_field.h"
#

namespace xplum_model::taifex_msg_proto::msg_sizeof_content
{
// message whole
extern inline const type::TypeMsgLength G_size_max_of_msg = cfg::G_size_max_of_msg_read_buffer;

// message inside
extern inline const type::TypeMsgLength G_sizeof_msg_length = sizeof(message_field::uint16);
extern inline const type::TypeMsgLength G_sizeof_msg_check_sum = sizeof(message_field::uint8);
extern inline const type::TypeMsgLength G_size_out_of_msg_length = G_sizeof_msg_length + G_sizeof_msg_check_sum;
extern inline const type::TypeMsgLength G_size_out_of_L41_data_in_msg_length = (sizeof(message_field::hdr) - G_sizeof_msg_length) + (sizeof(message_field::uint8) + sizeof(message_field::uint8) + sizeof(message_field::uint32));

// message inside
extern inline const type::TypeMsgLength G_value_max_of_msg_length = G_size_max_of_msg - G_size_out_of_msg_length;
extern inline const type::TypeMsgLength G_value_min_of_msg_length_L41 = G_size_out_of_L41_data_in_msg_length;
extern inline const std::size_t G_size_max_of_l41_data = G_value_max_of_msg_length - G_size_out_of_L41_data_in_msg_length;
extern inline const std::ptrdiff_t G_offsetof_msg_length = (0 /* 所有 Mxx 開始以 MsgHdr，故此 offset 為零。 */) + offsetof(message_field::hdr, msg_length);
extern inline const std::ptrdiff_t G_offsetof_msg_type = (0 /* 所有 Mxx 開始以 MsgHdr，故此 offset 為零。 */) + offsetof(message_field::hdr, MessageType);
}

namespace xplum_model::taifex_msg_proto::msg_sizeof_transfer_buffer
{
// message tcp read
// extern const type::TypeMsgLength G_size_max_of_read_msg = msg_sizeof_content::G_size_max_of_msg;
extern inline const type::TypeMsgLength G_size_min_of_read_msg = msg_sizeof_content::G_size_out_of_msg_length;
}
