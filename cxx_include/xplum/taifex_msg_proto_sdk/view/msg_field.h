#pragma once
#include <span>
#include "XPLUM_MACRO/MACRO_INITIALIZATION.h"
#include "xplum/prototype/Viewer.h"
#include "xplum/taifex_msg_proto/message_field/msg_field.h"
#include "xplum/taifex_msg_proto_sdk/view/msg_field_enumerate.h"

namespace xplum::taifex_msg_proto_sdk::view::message_field
{
	namespace define0
	{
		using xplum::prototype::Viewer;
	}
	namespace raw = xplum::taifex_msg_proto::message_field;

	// struct
	class MsgHdr;
	class MsgTime;
	class SymbolNum;
	class SymbolText;
	class LongSymbolNum;
	class LongSymbolText;

	// struct - union
	using SymbolX = std::tuple<SymbolNum, SymbolText>;
	using LongSymbolX = std::tuple<LongSymbolNum, LongSymbolText>;

}

class xplum::taifex_msg_proto_sdk::view::message_field::MsgTime : public define0::Viewer<raw::msg_time>
{
  public:
	MACRO_XPLUM_PROTOTYPE_VIEWER_DEPLOY_SUBCLASS(MsgTime);
	/* FieldXX_FieldNo01 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_linux_time_stamp_s, m_data.epoch_s);
	/* FieldXX_FieldNo02 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_millisecond, m_data.ms);
};

class xplum::taifex_msg_proto_sdk::view::message_field::MsgHdr : public define0::Viewer<raw::hdr>
{
  public:
	MACRO_XPLUM_PROTOTYPE_VIEWER_DEPLOY_SUBCLASS(MsgHdr);
	/* FieldXX_FieldNo01 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_msg_length, m_data.msg_length);
	/* FieldXX_FieldNo02 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_msg_seq_num, m_data.MsgSeqNum);
	/* FieldXX_FieldNo03 */ MACRO_XPLUM_AUTO_INIT_INSTANCE(MsgTime, m_msg_time, m_data.msg_time);
	/* FieldXX_FieldNo04 */ MACRO_XPLUM_AUTO_INIT_INSTANCE(enumerate::MsgType, m_message_type, m_data.MessageType);
	/* FieldXX_FieldNo05 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_fcm_id, m_data.fcm_id);
	/* FieldXX_FieldNo06 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_session_id, m_data.session_id);
};

class xplum::taifex_msg_proto_sdk::view::message_field::SymbolNum : public define0::Viewer<raw::symbol_num>
{
  public:
	MACRO_XPLUM_PROTOTYPE_VIEWER_DEPLOY_SUBCLASS(SymbolNum);
	/* FieldXX_FieldNo01 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_pseq1, m_data.pseq1);
	/* FieldXX_FieldNo02 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_pseq2, m_data.pseq2);
	/* FieldXX_FieldNo03 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_ARRAY(m_leg_side, m_data.leg_side);
	/* FieldXX_FieldNo04 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_comb_op, m_data.comb_op);
	/* FieldXX_FieldNo05 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_ARRAY(m_filler, m_data.filler);
};

class xplum::taifex_msg_proto_sdk::view::message_field::SymbolText : public define0::Viewer<raw::symbol_text>
{
  public:
	MACRO_XPLUM_PROTOTYPE_VIEWER_DEPLOY_SUBCLASS(SymbolText);
	/* FieldXX_FieldNo01 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_ARRAY(m_symbol, m_data.symbol);
};

class xplum::taifex_msg_proto_sdk::view::message_field::LongSymbolNum : public define0::Viewer<raw::long_symbol_num>
{
  public:
	MACRO_XPLUM_PROTOTYPE_VIEWER_DEPLOY_SUBCLASS(LongSymbolNum);
	/* FieldXX_FieldNo01 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_pseq1, m_data.pseq1);
	/* FieldXX_FieldNo02 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_pseq2, m_data.pseq2);
	/* FieldXX_FieldNo03 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_ARRAY(m_leg_side, m_data.leg_side);
	/* FieldXX_FieldNo04 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_comb_op, m_data.comb_op);
	/* FieldXX_FieldNo05 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_ARRAY(m_filler, m_data.filler);
};

class xplum::taifex_msg_proto_sdk::view::message_field::LongSymbolText : public define0::Viewer<raw::long_symbol_text>
{
  public:
	MACRO_XPLUM_PROTOTYPE_VIEWER_DEPLOY_SUBCLASS(LongSymbolText);
	/* FieldXX_FieldNo01 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_ARRAY(m_symbol, m_data.symbol);
};
