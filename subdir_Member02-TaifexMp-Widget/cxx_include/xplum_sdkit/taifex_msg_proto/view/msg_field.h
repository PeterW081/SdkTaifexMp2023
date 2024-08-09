#pragma once
#include <span>
#include "XPLUM_SDKIT_MACRO/MACRO_INITIALIZATION_OVERLOAD.h"
#include "xplum/ancestor/Viewer.h"
#include "xplum_model/taifex_msg_proto/structure_message_field/msg_field.h"
#include "xplum_sdkit/taifex_msg_proto/view/msg_field_enumerate.h"

namespace xplum_sdkit::taifex_msg_proto::view::message_field::_nshdr
{
using xplum::ancestor::Viewer;
}

namespace xplum_sdkit::taifex_msg_proto::view::message_field
{
namespace origin = xplum_model::taifex_msg_proto::message_field;

// type
using char0 = origin::char0 &;
using int08 = origin::int8 &;
using int16 = origin::int16 &;
using int32 = origin::int32 &;
using int64 = origin::int64 &;
using uint08 = origin::uint8 &;
using uint16 = origin::uint16 &;
using uint32 = origin::uint32 &;

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

class xplum_sdkit::taifex_msg_proto::view::message_field::MsgTime : public _nshdr::Viewer<origin::msg_time>
{
public:
  MACRO_XPLUM_ANCESTOR_VIEWER_DEPLOY_SUBCLASS (MsgTime);
  /* FieldXX_FieldNo01 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01 (m_super_0_data.epoch_s, m_linux_time_stamp_s);
  /* FieldXX_FieldNo02 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01 (m_super_0_data.ms, m_millisecond);
};

class xplum_sdkit::taifex_msg_proto::view::message_field::MsgHdr : public _nshdr::Viewer<origin::hdr>
{
public:
  MACRO_XPLUM_ANCESTOR_VIEWER_DEPLOY_SUBCLASS (MsgHdr);
  /* FieldXX_FieldNo01 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01 (m_super_0_data.msg_length, m_msg_length);
  /* FieldXX_FieldNo02 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01 (m_super_0_data.MsgSeqNum, m_msg_seq_num);
  /* FieldXX_FieldNo03 */ MACRO_XPLUM_AUTO_INIT_OBJECT_INSTANCE_OVERLOAD01 (m_super_0_data.msg_time, m_msg_time, MsgTime);
  /* FieldXX_FieldNo04 */ MACRO_XPLUM_AUTO_INIT_OBJECT_INSTANCE_OVERLOAD01 (m_super_0_data.MessageType, m_message_type, enumerate::MsgType);
  /* FieldXX_FieldNo05 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01 (m_super_0_data.fcm_id, m_fcm_id);
  /* FieldXX_FieldNo06 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01 (m_super_0_data.session_id, m_session_id);
};

class xplum_sdkit::taifex_msg_proto::view::message_field::SymbolNum : public _nshdr::Viewer<origin::symbol_num>
{
public:
  MACRO_XPLUM_ANCESTOR_VIEWER_DEPLOY_SUBCLASS (SymbolNum);
  /* FieldXX_FieldNo01 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01 (m_super_0_data.pseq1, m_pseq1);
  /* FieldXX_FieldNo02 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01 (m_super_0_data.pseq2, m_pseq2);
  /* FieldXX_FieldNo03 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_ARRAY_OVERLOAD01 (m_super_0_data.leg_side, m_leg_side);
  /* FieldXX_FieldNo04 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01 (m_super_0_data.comb_op, m_comb_op);
  /* FieldXX_FieldNo05 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_ARRAY_OVERLOAD01 (m_super_0_data.filler, m_filler);
};

class xplum_sdkit::taifex_msg_proto::view::message_field::SymbolText : public _nshdr::Viewer<origin::symbol_text>
{
public:
  MACRO_XPLUM_ANCESTOR_VIEWER_DEPLOY_SUBCLASS (SymbolText);
  /* FieldXX_FieldNo01 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_ARRAY_OVERLOAD01 (m_super_0_data.symbol, m_symbol);
};

class xplum_sdkit::taifex_msg_proto::view::message_field::LongSymbolNum : public _nshdr::Viewer<origin::long_symbol_num>
{
public:
  MACRO_XPLUM_ANCESTOR_VIEWER_DEPLOY_SUBCLASS (LongSymbolNum);
  /* FieldXX_FieldNo01 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01 (m_super_0_data.pseq1, m_pseq1);
  /* FieldXX_FieldNo02 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01 (m_super_0_data.pseq2, m_pseq2);
  /* FieldXX_FieldNo03 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_ARRAY_OVERLOAD01 (m_super_0_data.leg_side, m_leg_side);
  /* FieldXX_FieldNo04 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01 (m_super_0_data.comb_op, m_comb_op);
  /* FieldXX_FieldNo05 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_ARRAY_OVERLOAD01 (m_super_0_data.filler, m_filler);
};

class xplum_sdkit::taifex_msg_proto::view::message_field::LongSymbolText : public _nshdr::Viewer<origin::long_symbol_text>
{
public:
  MACRO_XPLUM_ANCESTOR_VIEWER_DEPLOY_SUBCLASS (LongSymbolText);
  /* FieldXX_FieldNo01 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_ARRAY_OVERLOAD01 (m_super_0_data.symbol, m_symbol);
};
