#pragma once
#include "XPLUM_MACRO/MACRO_INITIALIZATION.h"
#include "xplum/taifex_msg_proto/message/msg_lxx_layer.h"
#include "xplum/taifex_msg_proto_sdk/prototype/ViewerMsg.h"
#include "xplum/taifex_msg_proto_sdk/view/msg_field.h"
#include "xplum/taifex_msg_proto_sdk/view/msg_field_enumerate.h"


namespace xplum::taifex_msg_proto_sdk::view::message
{
	namespace define0
	{
		using prototype::ViewerMsgFixSize;
		using prototype::ViewerMsgZipSize;
	}
	namespace raw = xplum::taifex_msg_proto::message;

	// LxxLayer - MsgFixSize
	class L10;
	class L20;
	class L30;
	class L40;
	class L42;
	class L50;
	class L60;

	// LxxLayer - MsgZipSize
	class L41;
}

/// xplum::taifex_msg_proto_sdk::view::message::L10
#define LXX L10
class xplum::taifex_msg_proto_sdk::view::message::LXX : public define0::ViewerMsgFixSize<raw::LXX>
{
  public:
	MACRO_XPLUM_PROTOTYPE_VIEWERMSGFIXSIZE_DEPLOY_SUBCLASS(LXX);
	/* L10_FieldNo01 */ MACRO_XPLUM_AUTO_INIT_INSTANCE(message_field::MsgHdr, m_hdr, m_data.hdr);
	/* L10_FieldNo02 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_status_code, m_data.status_code);
	/* L10_FieldNo03 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_start_in_bound_num, m_data.start_in_bound_num);
	/* L10_FieldNo04 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_check_sum, m_data.CheckSum);
};
#undef LXX

/// xplum::taifex_msg_proto_sdk::view::message::L20
#define LXX L20
class xplum::taifex_msg_proto_sdk::view::message::LXX : public define0::ViewerMsgFixSize<raw::LXX>
{
  public:
	MACRO_XPLUM_PROTOTYPE_VIEWERMSGFIXSIZE_DEPLOY_SUBCLASS(LXX);
	/* L20_FieldNo01 */ MACRO_XPLUM_AUTO_INIT_INSTANCE(message_field::MsgHdr, m_hdr, m_data.hdr);
	/* L20_FieldNo02 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_status_code, m_data.status_code);
	/* L20_FieldNo03 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_check_sum, m_data.CheckSum);
};
#undef LXX

/// xplum::taifex_msg_proto_sdk::view::message::L30
#define LXX L30
class xplum::taifex_msg_proto_sdk::view::message::LXX : public define0::ViewerMsgFixSize<raw::LXX>
{
  public:
	MACRO_XPLUM_PROTOTYPE_VIEWERMSGFIXSIZE_DEPLOY_SUBCLASS(LXX);
	/* L30_FieldNo01 */ MACRO_XPLUM_AUTO_INIT_INSTANCE(message_field::MsgHdr, m_hdr, m_data.hdr);
	/* L30_FieldNo02 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_status_code, m_data.status_code);
	/* L30_FieldNo03 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_append_no, m_data.append_no);
	/* L30_FieldNo04 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_end_out_bound_num, m_data.end_out_bound_num);
	/* L30_FieldNo05 */ MACRO_XPLUM_AUTO_INIT_INSTANCE(message_field::enumerate::SystemType, m_system_type, m_data.system_type);
	/* L30_FieldNo06 */ MACRO_XPLUM_AUTO_INIT_INSTANCE(message_field::enumerate::EncryptMethod, m_encrypt_method, m_data.EncryptMethod);
	/* L30_FieldNo07 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_check_sum, m_data.CheckSum);
};
#undef LXX

/// xplum::taifex_msg_proto_sdk::view::message::L40
#define LXX L40
class xplum::taifex_msg_proto_sdk::view::message::LXX : public define0::ViewerMsgFixSize<raw::LXX>
{
  public:
	MACRO_XPLUM_PROTOTYPE_VIEWERMSGFIXSIZE_DEPLOY_SUBCLASS(LXX);
	/* L40_FieldNo01 */ MACRO_XPLUM_AUTO_INIT_INSTANCE(message_field::MsgHdr, m_hdr, m_data.hdr);
	/* L40_FieldNo02 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_status_code, m_data.status_code);
	/* L40_FieldNo03 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_append_no, m_data.append_no);
	/* L40_FieldNo04 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_fcm_id, m_data.fcm_id);
	/* L40_FieldNo05 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_session_id, m_data.session_id);
	/* L40_FieldNo06 */ MACRO_XPLUM_AUTO_INIT_INSTANCE(message_field::enumerate::SystemType, m_system_type, m_data.system_type);
	/* L40_FieldNo07 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_ap_code, m_data.ap_code);
	/* L40_FieldNo08 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_key_value, m_data.key_value);
	/* L40_FieldNo09 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_request_start_seq, m_data.request_start_seq);
	/* L40_FieldNo10 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_cancel_order_sec, m_data.cancel_order_sec);
	/* L40_FieldNo11 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_check_sum, m_data.CheckSum);
};
#undef LXX

/// xplum::taifex_msg_proto_sdk::view::message::L42
#define LXX L42
class xplum::taifex_msg_proto_sdk::view::message::LXX : public define0::ViewerMsgFixSize<raw::LXX>
{
  public:
	MACRO_XPLUM_PROTOTYPE_VIEWERMSGFIXSIZE_DEPLOY_SUBCLASS(LXX);
	/* L42_FieldNo01 */ MACRO_XPLUM_AUTO_INIT_INSTANCE(message_field::MsgHdr, m_hdr, m_data.hdr);
	/* L42_FieldNo02 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_status_code, m_data.status_code);
	/* L42_FieldNo03 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_check_sum, m_data.CheckSum);
};
#undef LXX

/// xplum::taifex_msg_proto_sdk::view::message::L50
#define LXX L50
class xplum::taifex_msg_proto_sdk::view::message::LXX : public define0::ViewerMsgFixSize<raw::LXX>
{
  public:
	MACRO_XPLUM_PROTOTYPE_VIEWERMSGFIXSIZE_DEPLOY_SUBCLASS(LXX);
	/* L50_FieldNo01 */ MACRO_XPLUM_AUTO_INIT_INSTANCE(message_field::MsgHdr, m_hdr, m_data.hdr);
	/* L50_FieldNo02 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_status_code, m_data.status_code);
	/* L50_FieldNo03 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_heart_bt_int, m_data.HeartBtInt);
	/* L50_FieldNo04 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_max_flow_ctrl_cnt, m_data.max_flow_ctrl_cnt);
	/* L50_FieldNo05 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_check_sum, m_data.CheckSum);
};
#undef LXX

/// xplum::taifex_msg_proto_sdk::view::message::L60
#define LXX L60
class xplum::taifex_msg_proto_sdk::view::message::LXX : public define0::ViewerMsgFixSize<raw::LXX>
{
  public:
	MACRO_XPLUM_PROTOTYPE_VIEWERMSGFIXSIZE_DEPLOY_SUBCLASS(LXX);
	/* L60_FieldNo01 */ MACRO_XPLUM_AUTO_INIT_INSTANCE(message_field::MsgHdr, m_hdr, m_data.hdr);
	/* L60_FieldNo02 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_status_code, m_data.status_code);
	/* L60_FieldNo03 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_check_sum, m_data.CheckSum);
};
#undef LXX

/// xplum::taifex_msg_proto_sdk::view::message::L41
class xplum::taifex_msg_proto_sdk::view::message::L41 : public define0::ViewerMsgZipSize<raw::L41WithMaxMsgLength>
{
	using L41MaxSize = T;
	using L41MinSize = raw::L41WithMinMsgLength;
	const std::size_t m0_sizeof_L41_data;
	std::byte* const m0_data_ptr_offset00; // L41 Field: hdr, status_code, is_eof, file_size, data,
	std::byte* const m0_data_ptr_offset01; // L41 Field: CheckSum,

  public:
	using DataType = raw::L41WithMaxMsgLength;
	L41(T& data, std::size_t msg_length);

  public:
	/* L41_FieldNo01 */ /* offset00 */ message_field::MsgHdr m_hdr = message_field::MsgHdr(*reinterpret_cast<decltype(L41MinSize::hdr)*>(m0_data_ptr_offset00 + offsetof(L41MinSize, hdr)));
	/* L41_FieldNo02 */ /* offset00 */ message_field::raw::uint8& m_status_code = *reinterpret_cast<decltype(L41MinSize::status_code)*>(m0_data_ptr_offset00 + offsetof(L41MinSize, status_code));
	/* L41_FieldNo03 */ /* offset00 */ message_field::enumerate::IsEof m_is_eof = message_field::enumerate::IsEof(*reinterpret_cast<decltype(L41MinSize::is_eof)*>(m0_data_ptr_offset00 + offsetof(L41MinSize, is_eof)));
	/* L41_FieldNo04 */ /* offset00 */ message_field::raw::uint32& m_file_size = *reinterpret_cast<decltype(L41MinSize::file_size)*>(m0_data_ptr_offset00 + offsetof(L41MinSize, file_size));
	/* L41_FieldNo05 */ /* offset00 */ std::span<message_field::raw::uint8> m_L41_data = std::span(reinterpret_cast<message_field::raw::uint8*>(m0_data_ptr_offset00 + offsetof(L41MinSize, data)), m0_sizeof_L41_data);
	/* L41_FieldNo06 */ /* offset01 */ message_field::raw::uint8& m_check_sum = *reinterpret_cast<decltype(L41MinSize::CheckSum)*>(m0_data_ptr_offset01 + offsetof(L41MinSize, CheckSum));
};
inline xplum::taifex_msg_proto_sdk::view::message::L41::L41(T& data, std::size_t msg_length)
	: ViewerMsgZipSize(data, msg_length + message_field::raw::SIZE_OUT_OF_MSG_LENGTH)
	, m0_sizeof_L41_data(msg_length - message_field::raw::SIZE_OUT_OF_L41_DATA_IN_MSG_LENGTH)
	, m0_data_ptr_offset00(reinterpret_cast<std::byte*>(&this->m_data))
	, m0_data_ptr_offset01(reinterpret_cast<std::byte*>(&this->m_data) + m0_sizeof_L41_data)
{
	assert(msg_length >= message_field::raw::SIZE_OUT_OF_L41_DATA_IN_MSG_LENGTH);
	assert(msg_length <= sizeof(T) - message_field::raw::SIZE_OUT_OF_MSG_LENGTH);
	assert(msg_length == m_hdr.m_msg_length);
}

///
#ifdef LXX
#	error // RXX should undef here.
#endif
#ifdef RXX
#	error // LXX should undef here.
#endif
