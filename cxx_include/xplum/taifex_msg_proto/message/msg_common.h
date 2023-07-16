#pragma once
#include "xplum/taifex_msg_proto/message_field/msg_field.h"

namespace xplum::taifex_msg_proto::cfg
{
	const std::size_t SIZE_MAX_OF_READ_MSG = 1 * 1024;
}

namespace xplum::taifex_msg_proto::tcp
{
	const std::size_t LXX_LAYER_TIMEOUT_S = 10; // 單位為秒。
	const std::size_t RXX_LAYER_TIMEOUT_S = 30; // ^^^
	const std::size_t R04_LAYER_TIMEOUT_S = 5;  // ^^^
	extern const std::size_t SIZE_MIN_OF_READ_RXX_MSG;
}

namespace xplum::taifex_msg_proto::message_field
{
	const std::size_t SIZEOF_MSG_LENGTH = sizeof(uint16);
	const std::size_t SIZEOF_MSG_CHECK_SUM = sizeof(uint8);
	const std::size_t SIZE_OUT_OF_MSG_LENGTH = SIZEOF_MSG_LENGTH + SIZEOF_MSG_CHECK_SUM;
	const std::size_t SIZE_OUT_OF_L41_DATA_IN_MSG_LENGTH = (sizeof(hdr) - SIZEOF_MSG_LENGTH) + (sizeof(uint8) + sizeof(uint8) + sizeof(uint32));
	const std::size_t VALUE_MAX_OF_MSG_LENGTH = cfg::SIZE_MAX_OF_READ_MSG - message_field::SIZE_OUT_OF_MSG_LENGTH;
	const std::size_t VALUE_MIN_OF_MSG_LENGTH_L41 = SIZE_OUT_OF_L41_DATA_IN_MSG_LENGTH;
}

inline const std::size_t xplum::taifex_msg_proto::tcp::SIZE_MIN_OF_READ_RXX_MSG = message_field::SIZE_OUT_OF_MSG_LENGTH;
