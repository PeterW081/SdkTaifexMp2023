#pragma once
#include "xplum/expanded_cast/enumerate_cast.h"
#include "xplum/taifex_msg_proto/message/msg_common.h"
#include "xplum/taifex_msg_proto/message_field/msg_field.h"
#include "xplum/taifex_msg_proto/message_field/msg_field_enumerate.h"

namespace xplum::taifex_msg_proto::message
{
	// LxxLayer
	struct L10;
	struct L20;
	struct L30;
	struct L40;
	template<type::uint16 MSG_LENGTH>
	struct L41;
	struct L42;
	struct L50;
	struct L60;

	// LxxLayer - TemplateExpand
	using L41WithMaxMsgLength = L41<message_field::VALUE_MAX_OF_MSG_LENGTH>;
	using L41WithMinMsgLength = L41<message_field::VALUE_MIN_OF_MSG_LENGTH_L41>;
}

/// xplum::taifex_msg_proto::message::L10
#define LXX L10
struct xplum::taifex_msg_proto::message::LXX
{
	/* L10_FieldNo01 */ message_field::hdr hdr = {
		.msg_length = sizeof(LXX) - message_field::SIZE_OUT_OF_MSG_LENGTH,
		.MsgSeqNum = 0,
		.MessageType = xplum::ToEnumUnderlyingValue(message_field::enumerate::MessageType::LXX),
	};
	/* L10_FieldNo02 */ message_field::uint8 status_code;
	/* L10_FieldNo03 */ message_field::uint32 start_in_bound_num = 0;
	/* L10_FieldNo04 */ message_field::uint8 CheckSum;
};
#undef LXX

/// xplum::taifex_msg_proto::message::L20
#define LXX L20
struct xplum::taifex_msg_proto::message::LXX
{
	/* L20_FieldNo01 */ message_field::hdr hdr = {
		.msg_length = sizeof(LXX) - message_field::SIZE_OUT_OF_MSG_LENGTH,
		.MsgSeqNum = 0,
		.MessageType = xplum::ToEnumUnderlyingValue(message_field::enumerate::MessageType::LXX),
	};
	/* L20_FieldNo02 */ message_field::uint8 status_code;
	/* L20_FieldNo03 */ message_field::uint8 CheckSum;
};
#undef LXX

/// xplum::taifex_msg_proto::message::L30
#define LXX L30
struct xplum::taifex_msg_proto::message::LXX
{
	/* L30_FieldNo01 */ message_field::hdr hdr = {
		.msg_length = sizeof(LXX) - message_field::SIZE_OUT_OF_MSG_LENGTH,
		.MsgSeqNum = 0,
		.MessageType = xplum::ToEnumUnderlyingValue(message_field::enumerate::MessageType::LXX),
	};
	/* L30_FieldNo02 */ message_field::uint8 status_code;
	/* L30_FieldNo03 */ message_field::uint16 append_no;
	/* L30_FieldNo04 */ message_field::uint32 end_out_bound_num;
	/* L30_FieldNo05 */ message_field::uint8 system_type;
	/* L30_FieldNo06 */ message_field::uint8 EncryptMethod;
	/* L30_FieldNo07 */ message_field::uint8 CheckSum;
};
#undef LXX

/// xplum::taifex_msg_proto::message::L40
#define LXX L40
struct xplum::taifex_msg_proto::message::LXX
{
	/* L40_FieldNo01 */ message_field::hdr hdr = {
		.msg_length = sizeof(LXX) - message_field::SIZE_OUT_OF_MSG_LENGTH,
		.MsgSeqNum = 0,
		.MessageType = xplum::ToEnumUnderlyingValue(message_field::enumerate::MessageType::LXX),
	};
	/* L40_FieldNo02 */ message_field::uint8 status_code;
	/* L40_FieldNo03 */ message_field::uint16 append_no;
	/* L40_FieldNo04 */ message_field::uint16 fcm_id;
	/* L40_FieldNo05 */ message_field::uint16 session_id;
	/* L40_FieldNo06 */ message_field::uint8 system_type;
	/* L40_FieldNo07 */ message_field::uint8 ap_code;
	/* L40_FieldNo08 */ message_field::uint8 key_value;
	/* L40_FieldNo09 */ message_field::uint32 request_start_seq;
	/* L40_FieldNo10 */ message_field::uint8 cancel_order_sec;
	/* L40_FieldNo11 */ message_field::uint8 CheckSum;
};
#undef LXX

/// xplum::taifex_msg_proto::message::L41
#define LXX L41
template<xplum::taifex_msg_proto::type::uint16 VALUE_MSG_LENGTH>
struct xplum::taifex_msg_proto::message::LXX
{
	static_assert(VALUE_MSG_LENGTH >= message_field::SIZE_OUT_OF_L41_DATA_IN_MSG_LENGTH);
	/* L41_FieldNo01 */ message_field::hdr hdr = {
		.msg_length = VALUE_MSG_LENGTH,
		.MsgSeqNum = 0,
		.MessageType = xplum::ToEnumUnderlyingValue(message_field::enumerate::MessageType::LXX),
	};
	/* L41_FieldNo02 */ message_field::uint8 status_code;
	/* L41_FieldNo03 */ message_field::uint8 is_eof;
	/* L41_FieldNo04 */ message_field::uint32 file_size;
	/* L41_FieldNo05 */ message_field::uint8 data[VALUE_MSG_LENGTH - message_field::SIZE_OUT_OF_L41_DATA_IN_MSG_LENGTH];
	/* L41_FieldNo06 */ message_field::uint8 CheckSum;
};
#undef LXX

/// xplum::taifex_msg_proto::message::L42
#define LXX L42
struct xplum::taifex_msg_proto::message::LXX
{
	/* L42_FieldNo01 */ message_field::hdr hdr = {
		.msg_length = sizeof(LXX) - message_field::SIZE_OUT_OF_MSG_LENGTH,
		.MsgSeqNum = 0,
		.MessageType = xplum::ToEnumUnderlyingValue(message_field::enumerate::MessageType::LXX),
	};
	/* L42_FieldNo02 */ message_field::uint8 status_code;
	/* L42_FieldNo03 */ message_field::uint8 CheckSum;
};
#undef LXX


/// xplum::taifex_msg_proto::message::L50
#define LXX L50
struct xplum::taifex_msg_proto::message::LXX
{
	/* L50_FieldNo01 */ message_field::hdr hdr = {
		.msg_length = sizeof(LXX) - message_field::SIZE_OUT_OF_MSG_LENGTH,
		.MsgSeqNum = 0,
		.MessageType = xplum::ToEnumUnderlyingValue(message_field::enumerate::MessageType::LXX),
	};
	/* L50_FieldNo02 */ message_field::uint8 status_code;
	/* L50_FieldNo03 */ message_field::uint8 HeartBtInt = 30;
	/* L50_FieldNo04 */ message_field::uint16 max_flow_ctrl_cnt;
	/* L50_FieldNo05 */ message_field::uint8 CheckSum;
};
#undef LXX

/// xplum::taifex_msg_proto::message::L60
#define LXX L60
struct xplum::taifex_msg_proto::message::LXX
{
	/* L60_FieldNo01 */ message_field::hdr hdr = {
		.msg_length = sizeof(LXX) - message_field::SIZE_OUT_OF_MSG_LENGTH,
		.MsgSeqNum = 0,
		.MessageType = xplum::ToEnumUnderlyingValue(message_field::enumerate::MessageType::LXX),
	};
	/* L60_FieldNo02 */ message_field::uint8 status_code;
	/* L60_FieldNo03 */ message_field::uint8 CheckSum;
};
#undef LXX

///
///
#ifdef LXX
#	error // RXX should undef here.
#endif
#ifdef RXX
#	error // LXX should undef here.
#endif
