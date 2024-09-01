#pragma once
#include "xplum_model/taifex_msg_proto/_CONFIG_MACRO.h"
#include "xplum_model/taifex_msg_proto/structure_message_field/msg_field.h"

namespace xplum_model::taifex_msg_proto::mt_sizeof_msg_content
{
// message whole
const type::TypeMsgLength SIZE_MAX_OF_MSG = cfg::SIZE_MAX_OF_MSG_READ_BUFFER;

// message inside
const type::TypeMsgLength SIZEOF_MSG_LENGTH = sizeof(message_field::uint16);
const type::TypeMsgLength SIZEOF_MSG_CHECK_SUM = sizeof(message_field::uint8);
const type::TypeMsgLength SIZE_OUT_OF_MSG_LENGTH = SIZEOF_MSG_LENGTH + SIZEOF_MSG_CHECK_SUM;
const type::TypeMsgLength SIZE_OUT_OF_L41_DATA_IN_MSG_LENGTH = (sizeof(message_field::hdr) - SIZEOF_MSG_LENGTH) + (sizeof(message_field::uint8) + sizeof(message_field::uint8) + sizeof(message_field::uint32));

// message inside
const type::TypeMsgLength VALUE_MAX_OF_MSG_LENGTH = SIZE_MAX_OF_MSG - SIZE_OUT_OF_MSG_LENGTH;
const type::TypeMsgLength VALUE_MIN_OF_MSG_LENGTH_L41 = SIZE_OUT_OF_L41_DATA_IN_MSG_LENGTH;
const std::size_t SIZE_MAX_OF_L41_DATA = VALUE_MAX_OF_MSG_LENGTH - SIZE_OUT_OF_L41_DATA_IN_MSG_LENGTH;
const std::ptrdiff_t OFFSETOF_MSG_LENGTH = (0) + offsetof(message_field::hdr, msg_length);
const std::ptrdiff_t OFFSETOF_MSG_TYPE = (0) + offsetof(message_field::hdr, MessageType);
}

namespace xplum_model::taifex_msg_proto::mt_sizeof_msg_read_buffer
{
// message tcp read
const type::TypeMsgLength SIZE_MIN_OF_READ_MSG = mt_sizeof_msg_content::SIZE_OUT_OF_MSG_LENGTH;
}
