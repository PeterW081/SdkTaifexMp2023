#pragma once
#include "XPLUM_SDKIT_MACRO/MACRO_INITIALIZATION_OVERLOAD.h"
#include "xplum_model/taifex_msg_proto/structure_message/msg_rxx_layer.h"
#include "xplum_sdkit/taifex_msg_proto/ancestor/ViewerMsg.h"
#include "xplum_sdkit/taifex_msg_proto/view/msg_field.h"
#include "xplum_sdkit/taifex_msg_proto/view/msg_field_enumerate.h"

namespace xplum_sdkit::taifex_msg_proto::view::message::_nshdr
{
using xplum_sdkit::taifex_msg_proto::ancestor::ViewerMsgFixSize;
}

namespace xplum_sdkit::taifex_msg_proto::view::message
{
namespace origin = xplum_model::taifex_msg_proto::message;

// RxxLayer - 連線狀態維護
class R04;
class R05;
class R11;
class R12;

// RxxLayer - 期貨交易操作: 普通操作報文
class R01;
class R02;
class R03;

}

/// xplum::taifex_msg_proto_sdk::view::message::R04
#define RXX R04
class xplum_sdkit::taifex_msg_proto::view::message::RXX : public _nshdr::ViewerMsgFixSize<origin::RXX>
{
  public:
    MACRO_XPLUM_ANCESTOR_VIEWERMSGFIXSIZE_DEPLOY_SUBCLASS(RXX);
    /* R04_FieldNo01 */ MACRO_XPLUM_AUTO_INIT_OBJECT_INSTANCE_OVERLOAD01(m_super_0_data.hdr, m_hdr, message_field::MsgHdr);
    /* R04_FieldNo02 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.status_code, m_status_code);
    /* R04_FieldNo03 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.CheckSum, m_check_sum);
};
#undef RXX

/// xplum::taifex_msg_proto_sdk::view::message::R05
#define RXX R05
class xplum_sdkit::taifex_msg_proto::view::message::RXX : public _nshdr::ViewerMsgFixSize<origin::RXX>
{
  public:
    MACRO_XPLUM_ANCESTOR_VIEWERMSGFIXSIZE_DEPLOY_SUBCLASS(RXX);
    /* R05_FieldNo01 */ MACRO_XPLUM_AUTO_INIT_OBJECT_INSTANCE_OVERLOAD01(m_super_0_data.hdr, m_hdr, message_field::MsgHdr);
    /* R05_FieldNo02 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.status_code, m_status_code);
    /* R05_FieldNo03 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.CheckSum, m_check_sum);
};
#undef RXX

/// xplum::taifex_msg_proto_sdk::view::message::R11
#define RXX R11
class xplum_sdkit::taifex_msg_proto::view::message::RXX : public _nshdr::ViewerMsgFixSize<origin::RXX>
{
  public:
    MACRO_XPLUM_ANCESTOR_VIEWERMSGFIXSIZE_DEPLOY_SUBCLASS(RXX);
    /* R11_FieldNo01 */ MACRO_XPLUM_AUTO_INIT_OBJECT_INSTANCE_OVERLOAD01(m_super_0_data.hdr, m_hdr, message_field::MsgHdr);
    /* R11_FieldNo02 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.status_code, m_status_code);
    /* R11_FieldNo03 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.TradeReqID, m_trade_req_id);
    /* R11_FieldNo04 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.flow_group_no, m_flow_group_no);
    /* R11_FieldNo05 */ MACRO_XPLUM_AUTO_INIT_OBJECT_INSTANCE_OVERLOAD01(m_super_0_data.SubscriptionRequestType, m_subscription_request_type, message_field::enumerate::SubscriptionRequestType);
    /* R11_FieldNo06 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.CheckSum, m_check_sum);
};
#undef RXX

/// xplum::taifex_msg_proto_sdk::view::message::R12
#define RXX R12
class xplum_sdkit::taifex_msg_proto::view::message::RXX : public _nshdr::ViewerMsgFixSize<origin::RXX>
{
  public:
    MACRO_XPLUM_ANCESTOR_VIEWERMSGFIXSIZE_DEPLOY_SUBCLASS(RXX);
    /* R12_FieldNo01 */ MACRO_XPLUM_AUTO_INIT_OBJECT_INSTANCE_OVERLOAD01(m_super_0_data.hdr, m_hdr, message_field::MsgHdr);
    /* R12_FieldNo02 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.status_code, m_status_code);
    /* R12_FieldNo03 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.TradeReqID, m_trade_req_id);
    /* R12_FieldNo04 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.flow_group_no, m_flow_group_no);
    /* R12_FieldNo05 */ MACRO_XPLUM_AUTO_INIT_OBJECT_INSTANCE_OVERLOAD01(m_super_0_data.TradeStatus, m_trade_status, message_field::enumerate::TradeStatus);
    /* R12_FieldNo06 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.CheckSum, m_check_sum);
};
#undef RXX

/// xplum::taifex_msg_proto_sdk::view::message::R01
#define RXX R01
class xplum_sdkit::taifex_msg_proto::view::message::RXX : public _nshdr::ViewerMsgFixSize<origin::RXX>
{
  public:
    MACRO_XPLUM_ANCESTOR_VIEWERMSGFIXSIZE_DEPLOY_SUBCLASS(RXX);
    /* R01_FieldNo01 */ MACRO_XPLUM_AUTO_INIT_OBJECT_INSTANCE_OVERLOAD01(m_super_0_data.hdr, m_hdr, message_field::MsgHdr);
    /* R01_FieldNo02 */ MACRO_XPLUM_AUTO_INIT_OBJECT_INSTANCE_OVERLOAD01(m_super_0_data.ExecType, m_exec_type, message_field::enumerate::ExecType);
    /* R01_FieldNo03 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.cm_id, m_cm_id);
    /* R01_FieldNo04 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.fcm_id, m_fcm_id);
    /* R01_FieldNo05 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_ARRAY_OVERLOAD01(m_super_0_data.order_no, m_order_no);
    /* R01_FieldNo06 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.ord_id, m_order_id);
    /* R01_FieldNo07 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_ARRAY_OVERLOAD01(m_super_0_data.user_define, m_user_define);
    /* R01_FieldNo08 */ MACRO_XPLUM_AUTO_INIT_OBJECT_INSTANCE_OVERLOAD01(m_super_0_data.symbol_type, m_symbol_type, message_field::enumerate::SymbolType);
    /* R01_FieldNo09 */ MACRO_XPLUM_AUTO_INIT_OBJECT_INSTANCE_OVERLOAD99(m_super_0_data.sym.num, m_sym, message_field::SymbolX, /**/ message_field::SymbolNum(m_super_0_data.sym.num), message_field::SymbolText(m_super_0_data.sym.text));
    /* R01_FieldNo10 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.Price, m_price);
    /* R01_FieldNo11 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.qty, m_qty);
    /* R01_FieldNo12 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.investor_acno, m_investor_acno);
    /* R01_FieldNo13 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.investor_flag, m_investor_flag);
    /* R01_FieldNo14 */ MACRO_XPLUM_AUTO_INIT_OBJECT_INSTANCE_OVERLOAD01(m_super_0_data.Side, m_side, message_field::enumerate::Side);
    /* R01_FieldNo15 */ MACRO_XPLUM_AUTO_INIT_OBJECT_INSTANCE_OVERLOAD01(m_super_0_data.OrdType, m_order_type, message_field::enumerate::OrderType);
    /* R01_FieldNo16 */ MACRO_XPLUM_AUTO_INIT_OBJECT_INSTANCE_OVERLOAD01(m_super_0_data.TimeInForce, m_time_in_force, message_field::enumerate::TimeInForce);
    /* R01_FieldNo17 */ MACRO_XPLUM_AUTO_INIT_OBJECT_INSTANCE_OVERLOAD01(m_super_0_data.PositionEffect, m_position_effect, message_field::enumerate::PositionEffect);
    /* R01_FieldNo18 */ MACRO_XPLUM_AUTO_INIT_OBJECT_INSTANCE_OVERLOAD01(m_super_0_data.order_source, m_order_source, message_field::enumerate::OrderSource);
    /* R01_FieldNo19 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_ARRAY_OVERLOAD01(m_super_0_data.info_source, m_info_source);
    /* R01_FieldNo20 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.CheckSum, m_check_sum);
};
#undef RXX

/// xplum::taifex_msg_proto_sdk::view::message::R02
#define RXX R02
class xplum_sdkit::taifex_msg_proto::view::message::RXX : public _nshdr::ViewerMsgFixSize<origin::RXX>
{
  public:
    MACRO_XPLUM_ANCESTOR_VIEWERMSGFIXSIZE_DEPLOY_SUBCLASS(RXX);
    /* R02_FieldNo01 */ MACRO_XPLUM_AUTO_INIT_OBJECT_INSTANCE_OVERLOAD01(m_super_0_data.hdr, m_hdr, message_field::MsgHdr);
    /* R02_FieldNo02 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.status_code, m_status_code);
    /* R02_FieldNo03 */ MACRO_XPLUM_AUTO_INIT_OBJECT_INSTANCE_OVERLOAD01(m_super_0_data.ExecType, m_exec_type, message_field::enumerate::ExecType);
    /* R02_FieldNo04 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.cm_id, m_cm_id);
    /* R02_FieldNo05 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.fcm_id, m_fcm_id);
    /* R02_FieldNo06 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_ARRAY_OVERLOAD01(m_super_0_data.order_no, m_order_no);
    /* R02_FieldNo07 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.ord_id, m_order_id);
    /* R02_FieldNo08 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_ARRAY_OVERLOAD01(m_super_0_data.user_define, m_user_define);
    /* R02_FieldNo09 */ MACRO_XPLUM_AUTO_INIT_OBJECT_INSTANCE_OVERLOAD01(m_super_0_data.symbol_type, m_symbol_type, message_field::enumerate::SymbolType);
    /* R02_FieldNo10 */ MACRO_XPLUM_AUTO_INIT_OBJECT_INSTANCE_OVERLOAD99(m_super_0_data.sym.num, m_sym, message_field::SymbolX, /**/ message_field::SymbolNum(m_super_0_data.sym.num), message_field::SymbolText(m_super_0_data.sym.text));
    /* R02_FieldNo11 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.Price, m_price);
    /* R02_FieldNo12 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.qty, m_qty);
    /* R02_FieldNo13 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.investor_acno, m_investor_acno);
    /* R02_FieldNo14 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.investor_flag, m_investor_flag);
    /* R02_FieldNo15 */ MACRO_XPLUM_AUTO_INIT_OBJECT_INSTANCE_OVERLOAD01(m_super_0_data.Side, m_side, message_field::enumerate::Side);
    /* R02_FieldNo16 */ MACRO_XPLUM_AUTO_INIT_OBJECT_INSTANCE_OVERLOAD01(m_super_0_data.OrdType, m_order_type, message_field::enumerate::OrderType);
    /* R02_FieldNo17 */ MACRO_XPLUM_AUTO_INIT_OBJECT_INSTANCE_OVERLOAD01(m_super_0_data.TimeInForce, m_time_in_force, message_field::enumerate::TimeInForce);
    /* R02_FieldNo18 */ MACRO_XPLUM_AUTO_INIT_OBJECT_INSTANCE_OVERLOAD01(m_super_0_data.PositionEffect, m_position_effect, message_field::enumerate::PositionEffect);
    /* R02_FieldNo19 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.LastPx, m_last_px);
    /* R02_FieldNo20 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.LastQty, m_last_qty);
    /* R02_FieldNo21 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.px_subtotal, m_px_subtotal);
    /* R02_FieldNo22 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.CumQty, m_cum_qty);
    /* R02_FieldNo23 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.LeavesQty, m_leaves_qty);
    /* R02_FieldNo24 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.before_qty, m_before_qty);
    /* R02_FieldNo25 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_ARRAY_OVERLOAD01(m_super_0_data.leg_side, m_leg_side);
    /* R02_FieldNo26 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_ARRAY_OVERLOAD01(m_super_0_data.leg_px, m_leg_px);
    /* R02_FieldNo27 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_ARRAY_OVERLOAD01(m_super_0_data.leg_qty, m_leg_qty);
    /* R02_FieldNo28 */ MACRO_XPLUM_AUTO_INIT_OBJECT_INSTANCE_OVERLOAD01(m_super_0_data.org_trans_time, m_org_trans_time, message_field::MsgTime);
    /* R02_FieldNo29 */ MACRO_XPLUM_AUTO_INIT_OBJECT_INSTANCE_OVERLOAD01(m_super_0_data.TransactTime, m_transact_time, message_field::MsgTime);
    /* R02_FieldNo30 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.target_id, m_target_id);
    /* R02_FieldNo31 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.uniq_id, m_uniq_id);
    /* R02_FieldNo32 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.rpt_seq, m_rpt_seq);
    /* R02_FieldNo33 */ MACRO_XPLUM_AUTO_INIT_OBJECT_INSTANCE_OVERLOAD01(m_super_0_data.protocol_type, m_protocol_type, message_field::enumerate::ProtocolType);
    /* R02_FieldNo34 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.CheckSum, m_check_sum);
};
#undef RXX

/// xplum::taifex_msg_proto_sdk::view::message::R03
#define RXX R03
class xplum_sdkit::taifex_msg_proto::view::message::RXX : public _nshdr::ViewerMsgFixSize<origin::RXX>
{
  public:
    MACRO_XPLUM_ANCESTOR_VIEWERMSGFIXSIZE_DEPLOY_SUBCLASS(RXX);
    /* R03_FieldNo01 */ MACRO_XPLUM_AUTO_INIT_OBJECT_INSTANCE_OVERLOAD01(m_super_0_data.hdr, m_hdr, message_field::MsgHdr);
    /* R03_FieldNo02 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.status_code, m_status_code);
    /* R03_FieldNo03 */ MACRO_XPLUM_AUTO_INIT_OBJECT_INSTANCE_OVERLOAD01(m_super_0_data.ExecType, m_exec_type, message_field::enumerate::ExecType);
    /* R03_FieldNo04 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.fcm_id, m_fcm_id);
    /* R03_FieldNo05 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_ARRAY_OVERLOAD01(m_super_0_data.order_no, m_order_no);
    /* R03_FieldNo06 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.ord_id, m_order_id);
    /* R03_FieldNo07 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_ARRAY_OVERLOAD01(m_super_0_data.user_define, m_user_define);
    /* R03_FieldNo08 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.rpt_seq, m_rpt_seq);
    /* R03_FieldNo09 */ MACRO_XPLUM_AUTO_INIT_OBJECT_INSTANCE_OVERLOAD01(m_super_0_data.Side, m_side, message_field::enumerate::Side);
    /* R03_FieldNo10 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.CheckSum, m_check_sum);
};
#undef RXX

///
///
#if (defined(LXX) || defined(RXX))
#error
#error // RXX should undef here.
#error // LXX should undef here.
#endif
