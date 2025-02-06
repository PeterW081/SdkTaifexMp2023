#pragma once
#include <span>
#include "xplum/ancestor/Viewer.h"
#include "xplum_model/taifex_msg_proto/network_osi_L06/structure_msg_field/msg_field.h"
#include "xplum_sdkit/taifex_msg_proto/network_osi_L06/reference_msg_view/msg_field_array.h"
#include "xplum_sdkit/taifex_msg_proto/network_osi_L06/reference_msg_view/msg_field_enumerate.h"
#

namespace xplum_sdkit::taifex_msg_proto::view::message_field::_nshdr
{
using xplum::ancestor::Viewer;
}

namespace xplum_sdkit::taifex_msg_proto::view::message_field
{
namespace model = xplum_model::taifex_msg_proto::message_field;

// type
using char0_VIEW = model::char0 &;
using int08_VIEW = model::int8 &;
using int16_VIEW = model::int16 &;
using int32_VIEW = model::int32 &;
using int64_VIEW = model::int64 &;
using uint08_VIEW = model::uint8 &;
using uint16_VIEW = model::uint16 &;
using uint32_VIEW = model::uint32 &;

// struct
struct MsgHdr_VIEW;
struct MsgTime_VIEW;
struct SymbolNum_VIEW;
struct SymbolText_VIEW;
struct LongSymbolNum_VIEW;
struct LongSymbolText_VIEW;

// struct - union
using SymbolX_VIEW = std::tuple<SymbolNum_VIEW, SymbolText_VIEW>;
using LongSymbolX_VIEW = std::tuple<LongSymbolNum_VIEW, LongSymbolText_VIEW>;

}

struct xplum_sdkit::taifex_msg_proto::view::message_field::MsgTime_VIEW : _nshdr::Viewer<model::msg_time>
{
    MACRO_XPLUM_ANCESTOR_VIEWER_DEPLOY_SUBCLASS(MsgTime_VIEW);
    /* FieldXX_FieldNo01 */ view::message_field::int32_VIEW m_linux_time_stamp_s = m_super_0_data.epoch_s;
    /* FieldXX_FieldNo02 */ view::message_field::uint16_VIEW m_millisecond = m_super_0_data.ms;
};

struct xplum_sdkit::taifex_msg_proto::view::message_field::MsgHdr_VIEW : _nshdr::Viewer<model::hdr>
{
    MACRO_XPLUM_ANCESTOR_VIEWER_DEPLOY_SUBCLASS(MsgHdr_VIEW);
    /* FieldXX_FieldNo01 */ view::message_field::uint16_VIEW m_msg_length = m_super_0_data.msg_length;
    /* FieldXX_FieldNo02 */ view::message_field::uint32_VIEW m_msg_seq_num = m_super_0_data.MsgSeqNum;
    /* FieldXX_FieldNo03 */ view::message_field::MsgTime_VIEW m_msg_time = MsgTime_VIEW(m_super_0_data.msg_time);
    /* FieldXX_FieldNo04 */ view::message_field::enumerate::MsgType_VIEW m_message_type = enumerate::MsgType_VIEW(m_super_0_data.MessageType);
    /* FieldXX_FieldNo05 */ view::message_field::uint16_VIEW m_fcm_id = m_super_0_data.fcm_id;
    /* FieldXX_FieldNo06 */ view::message_field::uint16_VIEW m_session_id = m_super_0_data.session_id;
};

struct xplum_sdkit::taifex_msg_proto::view::message_field::SymbolNum_VIEW : _nshdr::Viewer<model::symbol_num>
{
    MACRO_XPLUM_ANCESTOR_VIEWER_DEPLOY_SUBCLASS(SymbolNum_VIEW);
    /* FieldXX_FieldNo01 */ view::message_field::uint16_VIEW m_pseq1 = m_super_0_data.pseq1;
    /* FieldXX_FieldNo02 */ view::message_field::uint16_VIEW m_pseq2 = m_super_0_data.pseq2;
    /* FieldXX_FieldNo03 */ view::message_field::array::SymbolNum_LegSide_VIEW m_leg_side = m_super_0_data.leg_side;
    /* FieldXX_FieldNo04 */ view::message_field::uint08_VIEW m_comb_op = m_super_0_data.comb_op;
    /* FieldXX_FieldNo05 */ view::message_field::array::SymbolNum_Filler_VIEW m_filler = m_super_0_data.filler;
};

struct xplum_sdkit::taifex_msg_proto::view::message_field::SymbolText_VIEW : _nshdr::Viewer<model::symbol_text>
{
    MACRO_XPLUM_ANCESTOR_VIEWER_DEPLOY_SUBCLASS(SymbolText_VIEW);
    /* FieldXX_FieldNo01 */ view::message_field::array::SymbolText_Symbol_VIEW m_symbol = m_super_0_data.symbol;
};

struct xplum_sdkit::taifex_msg_proto::view::message_field::LongSymbolNum_VIEW : _nshdr::Viewer<model::long_symbol_num>
{
    MACRO_XPLUM_ANCESTOR_VIEWER_DEPLOY_SUBCLASS(LongSymbolNum_VIEW);
    /* FieldXX_FieldNo01 */ view::message_field::uint16_VIEW m_pseq1 = m_super_0_data.pseq1;
    /* FieldXX_FieldNo02 */ view::message_field::uint16_VIEW m_pseq2 = m_super_0_data.pseq2;
    /* FieldXX_FieldNo03 */ view::message_field::array::LongSymbolNum_LegSide_VIEW m_leg_side = m_super_0_data.leg_side;
    /* FieldXX_FieldNo04 */ view::message_field::uint08_VIEW m_comb_op = m_super_0_data.comb_op;
    /* FieldXX_FieldNo05 */ view::message_field::array::LongSymbolNum_Filler_VIEW m_filler = m_super_0_data.filler;
};

struct xplum_sdkit::taifex_msg_proto::view::message_field::LongSymbolText_VIEW : _nshdr::Viewer<model::long_symbol_text>
{
    MACRO_XPLUM_ANCESTOR_VIEWER_DEPLOY_SUBCLASS(LongSymbolText_VIEW);
    /* FieldXX_FieldNo01 */ view::message_field::array::LongSymbolText_Symbol_VIEW m_symbol = m_super_0_data.symbol;
};
