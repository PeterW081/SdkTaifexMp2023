#pragma once
#include <span>
#include "xplum/ancestor/Viewer.h"
#include "xplum_model/taifex_msg_proto/network_osi_L06/structure_msg_field/msg_field.h"
#include "xplum_sdkit/taifex_msg_proto/view/msg_field_array.h"
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

// array
using uint08_span = std::span<origin::uint8>;

// struct
struct MsgHdr;
struct MsgTime;
struct SymbolNum;
struct SymbolText;
struct LongSymbolNum;
struct LongSymbolText;

// struct - union
using SymbolX = std::tuple<SymbolNum, SymbolText>;
using LongSymbolX = std::tuple<LongSymbolNum, LongSymbolText>;

}

struct xplum_sdkit::taifex_msg_proto::view::message_field::MsgTime : _nshdr::Viewer<origin::msg_time>
{
    MACRO_XPLUM_ANCESTOR_VIEWER_DEPLOY_SUBCLASS(MsgTime);
    /* FieldXX_FieldNo01 */ view::message_field::int32 m_linux_time_stamp_s = m_super_0_data.epoch_s;
    /* FieldXX_FieldNo02 */ view::message_field::uint16 m_millisecond = m_super_0_data.ms;
};

struct xplum_sdkit::taifex_msg_proto::view::message_field::MsgHdr : _nshdr::Viewer<origin::hdr>
{
    MACRO_XPLUM_ANCESTOR_VIEWER_DEPLOY_SUBCLASS(MsgHdr);
    /* FieldXX_FieldNo01 */ view::message_field::uint16 m_msg_length = m_super_0_data.msg_length;
    /* FieldXX_FieldNo02 */ view::message_field::uint32 m_msg_seq_num = m_super_0_data.MsgSeqNum;
    /* FieldXX_FieldNo03 */ view::message_field::MsgTime m_msg_time = MsgTime(m_super_0_data.msg_time);
    /* FieldXX_FieldNo04 */ view::message_field::enumerate::MsgType m_message_type = enumerate::MsgType(m_super_0_data.MessageType);
    /* FieldXX_FieldNo05 */ view::message_field::uint16 m_fcm_id = m_super_0_data.fcm_id;
    /* FieldXX_FieldNo06 */ view::message_field::uint16 m_session_id = m_super_0_data.session_id;
};

struct xplum_sdkit::taifex_msg_proto::view::message_field::SymbolNum : _nshdr::Viewer<origin::symbol_num>
{
    MACRO_XPLUM_ANCESTOR_VIEWER_DEPLOY_SUBCLASS(SymbolNum);
    /* FieldXX_FieldNo01 */ view::message_field::uint16 m_pseq1 = m_super_0_data.pseq1;
    /* FieldXX_FieldNo02 */ view::message_field::uint16 m_pseq2 = m_super_0_data.pseq2;
    /* FieldXX_FieldNo03 */ view::message_field::array::SymbolNum_LegSide m_leg_side = m_super_0_data.leg_side;
    /* FieldXX_FieldNo04 */ view::message_field::uint08 m_comb_op = m_super_0_data.comb_op;
    /* FieldXX_FieldNo05 */ view::message_field::array::SymbolNum_Filler m_filler = m_super_0_data.filler;
};

struct xplum_sdkit::taifex_msg_proto::view::message_field::SymbolText : _nshdr::Viewer<origin::symbol_text>
{
    MACRO_XPLUM_ANCESTOR_VIEWER_DEPLOY_SUBCLASS(SymbolText);
    /* FieldXX_FieldNo01 */ view::message_field::array::SymbolText_Symbol m_symbol = m_super_0_data.symbol;
};

struct xplum_sdkit::taifex_msg_proto::view::message_field::LongSymbolNum : _nshdr::Viewer<origin::long_symbol_num>
{
    MACRO_XPLUM_ANCESTOR_VIEWER_DEPLOY_SUBCLASS(LongSymbolNum);
    /* FieldXX_FieldNo01 */ view::message_field::uint16 m_pseq1 = m_super_0_data.pseq1;
    /* FieldXX_FieldNo02 */ view::message_field::uint16 m_pseq2 = m_super_0_data.pseq2;
    /* FieldXX_FieldNo03 */ view::message_field::array::LongSymbolNum_LegSide m_leg_side = m_super_0_data.leg_side;
    /* FieldXX_FieldNo04 */ view::message_field::uint08 m_comb_op = m_super_0_data.comb_op;
    /* FieldXX_FieldNo05 */ view::message_field::array::LongSymbolNum_Filler m_filler = m_super_0_data.filler;
};

struct xplum_sdkit::taifex_msg_proto::view::message_field::LongSymbolText : _nshdr::Viewer<origin::long_symbol_text>
{
    MACRO_XPLUM_ANCESTOR_VIEWER_DEPLOY_SUBCLASS(LongSymbolText);
    /* FieldXX_FieldNo01 */ view::message_field::array::LongSymbolText_Symbol m_symbol = m_super_0_data.symbol;
};
