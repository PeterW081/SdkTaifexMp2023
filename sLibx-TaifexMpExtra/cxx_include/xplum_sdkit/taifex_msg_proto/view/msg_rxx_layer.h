#pragma once
#include "xplum_model/taifex_msg_proto/network_osi_L06/structure_msg/msg_rxx_layer.h"
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
struct R04;
struct R05;
struct R11;
struct R12;

// RxxLayer - 期貨交易操作: 普通操作報文
struct R01;
struct R02;
struct R03;

}

/// xplum::taifex_msg_proto_sdk::view::message::R04
#define RXX R04
struct xplum_sdkit::taifex_msg_proto::view::message::RXX : _nshdr::ViewerMsgFixSize<origin::RXX>
{
    MACRO_XPLUM_ANCESTOR_VIEWERMSGFIXSIZE_DEPLOY_SUBCLASS(RXX);
    /* R04_FieldNo01 */ view::message_field::MsgHdr m_hdr = view::message_field::MsgHdr(m_super_0_data.hdr);
    /* R04_FieldNo02 */ view::message_field::uint08 m_status_code = m_super_0_data.status_code;
    /* R04_FieldNo03 */ view::message_field::uint08 m_check_sum = m_super_0_data.CheckSum;
};
#undef RXX

/// xplum::taifex_msg_proto_sdk::view::message::R05
#define RXX R05
struct xplum_sdkit::taifex_msg_proto::view::message::RXX : _nshdr::ViewerMsgFixSize<origin::RXX>
{
    MACRO_XPLUM_ANCESTOR_VIEWERMSGFIXSIZE_DEPLOY_SUBCLASS(RXX);
    /* R05_FieldNo01 */ view::message_field::MsgHdr m_hdr = view::message_field::MsgHdr(m_super_0_data.hdr);
    /* R05_FieldNo02 */ view::message_field::uint08 m_status_code = m_super_0_data.status_code;
    /* R05_FieldNo03 */ view::message_field::uint08 m_check_sum = m_super_0_data.CheckSum;
};
#undef RXX

/// xplum::taifex_msg_proto_sdk::view::message::R11
#define RXX R11
struct xplum_sdkit::taifex_msg_proto::view::message::RXX : _nshdr::ViewerMsgFixSize<origin::RXX>
{
    MACRO_XPLUM_ANCESTOR_VIEWERMSGFIXSIZE_DEPLOY_SUBCLASS(RXX);
    /* R11_FieldNo01 */ view::message_field::MsgHdr m_hdr = view::message_field::MsgHdr(m_super_0_data.hdr);
    /* R11_FieldNo02 */ view::message_field::uint08 m_status_code = m_super_0_data.status_code;
    /* R11_FieldNo03 */ view::message_field::uint16 m_trade_req_id = m_super_0_data.TradeReqID;
    /* R11_FieldNo04 */ view::message_field::uint08 m_flow_group_no = m_super_0_data.flow_group_no;
    /* R11_FieldNo05 */ view::message_field::enumerate::SubscriptionRequestType m_subscription_request_type = view::message_field::enumerate::SubscriptionRequestType(m_super_0_data.SubscriptionRequestType);
    /* R11_FieldNo06 */ view::message_field::uint08 m_check_sum = m_super_0_data.CheckSum;
};
#undef RXX

/// xplum::taifex_msg_proto_sdk::view::message::R12
#define RXX R12
struct xplum_sdkit::taifex_msg_proto::view::message::RXX : _nshdr::ViewerMsgFixSize<origin::RXX>
{
    MACRO_XPLUM_ANCESTOR_VIEWERMSGFIXSIZE_DEPLOY_SUBCLASS(RXX);
    /* R12_FieldNo01 */ view::message_field::MsgHdr m_hdr = view::message_field::MsgHdr(m_super_0_data.hdr);
    /* R12_FieldNo02 */ view::message_field::uint08 m_status_code = m_super_0_data.status_code;
    /* R12_FieldNo03 */ view::message_field::uint16 m_trade_req_id = m_super_0_data.TradeReqID;
    /* R12_FieldNo04 */ view::message_field::uint08 m_flow_group_no = m_super_0_data.flow_group_no;
    /* R12_FieldNo05 */ view::message_field::enumerate::TradeStatus m_trade_status = view::message_field::enumerate::TradeStatus(m_super_0_data.TradeStatus);
    /* R12_FieldNo06 */ view::message_field::uint08 m_check_sum = m_super_0_data.CheckSum;
};
#undef RXX

/// xplum::taifex_msg_proto_sdk::view::message::R01
#define RXX R01
struct xplum_sdkit::taifex_msg_proto::view::message::RXX : _nshdr::ViewerMsgFixSize<origin::RXX>
{
    MACRO_XPLUM_ANCESTOR_VIEWERMSGFIXSIZE_DEPLOY_SUBCLASS(RXX);
    /* R01_FieldNo01 */ view::message_field::MsgHdr m_hdr = view::message_field::MsgHdr(m_super_0_data.hdr);
    /* R01_FieldNo02 */ view::message_field::enumerate::ExecType m_exec_type = view::message_field::enumerate::ExecType(m_super_0_data.ExecType);
    /* R01_FieldNo03 */ view::message_field::uint16 m_cm_id = m_super_0_data.cm_id;
    /* R01_FieldNo04 */ view::message_field::uint16 m_fcm_id = m_super_0_data.fcm_id;
    /* R01_FieldNo05 */ view::message_field::array::OrderNo m_order_no = m_super_0_data.order_no;
    /* R01_FieldNo06 */ view::message_field::uint32 m_order_id = m_super_0_data.ord_id;
    /* R01_FieldNo07 */ view::message_field::array::UserDefine m_user_define = m_super_0_data.user_define;
    /* R01_FieldNo08 */ view::message_field::enumerate::SymbolType m_symbol_type = view::message_field::enumerate::SymbolType(m_super_0_data.symbol_type);
    /* R01_FieldNo09 */ view::message_field::SymbolX m_sym = std::tuple{
        view::message_field::SymbolNum(m_super_0_data.sym.num),
        view::message_field::SymbolText(m_super_0_data.sym.text),
    };
    /* R01_FieldNo10 */ view::message_field::int32 m_price = m_super_0_data.Price;
    /* R01_FieldNo11 */ view::message_field::uint16 m_qty = m_super_0_data.qty;
    /* R01_FieldNo12 */ view::message_field::uint32 m_investor_acno = m_super_0_data.investor_acno;
    /* R01_FieldNo13 */ view::message_field::char0 m_investor_flag = m_super_0_data.investor_flag;
    /* R01_FieldNo14 */ view::message_field::enumerate::Side m_side = view::message_field::enumerate::Side(m_super_0_data.Side);
    /* R01_FieldNo15 */ view::message_field::enumerate::OrderType m_order_type = view::message_field::enumerate::OrderType(m_super_0_data.OrdType);
    /* R01_FieldNo16 */ view::message_field::enumerate::TimeInForce m_time_in_force = view::message_field::enumerate::TimeInForce(m_super_0_data.TimeInForce);
    /* R01_FieldNo17 */ view::message_field::enumerate::PositionEffect m_position_effect = view::message_field::enumerate::PositionEffect(m_super_0_data.PositionEffect);
    /* R01_FieldNo18 */ view::message_field::enumerate::OrderSource m_order_source = view::message_field::enumerate::OrderSource(m_super_0_data.order_source);
    /* R01_FieldNo19 */ view::message_field::array::InfoSource m_info_source = m_super_0_data.info_source;
    /* R01_FieldNo20 */ view::message_field::uint08 m_check_sum = m_super_0_data.CheckSum;
};
#undef RXX

/// xplum::taifex_msg_proto_sdk::view::message::R02
#define RXX R02
struct xplum_sdkit::taifex_msg_proto::view::message::RXX : _nshdr::ViewerMsgFixSize<origin::RXX>
{
    MACRO_XPLUM_ANCESTOR_VIEWERMSGFIXSIZE_DEPLOY_SUBCLASS(RXX);
    /* R02_FieldNo01 */ view::message_field::MsgHdr m_hdr = view::message_field::MsgHdr(m_super_0_data.hdr);
    /* R02_FieldNo02 */ view::message_field::uint08 m_status_code = m_super_0_data.status_code;
    /* R02_FieldNo03 */ view::message_field::enumerate::ExecType m_exec_type = view::message_field::enumerate::ExecType(m_super_0_data.ExecType);
    /* R02_FieldNo04 */ view::message_field::uint16 m_cm_id = m_super_0_data.cm_id;
    /* R02_FieldNo05 */ view::message_field::uint16 m_fcm_id = m_super_0_data.fcm_id;
    /* R02_FieldNo06 */ view::message_field::array::OrderNo m_order_no = m_super_0_data.order_no;
    /* R02_FieldNo07 */ view::message_field::uint32 m_order_id = m_super_0_data.ord_id;
    /* R02_FieldNo08 */ view::message_field::array::UserDefine m_user_define = m_super_0_data.user_define;
    /* R02_FieldNo09 */ view::message_field::enumerate::SymbolType m_symbol_type = view::message_field::enumerate::SymbolType(m_super_0_data.symbol_type);
    /* R02_FieldNo10 */ view::message_field::SymbolX m_sym = std::tuple{
        view::message_field::SymbolNum(m_super_0_data.sym.num),
        view::message_field::SymbolText(m_super_0_data.sym.text),
    };
    /* R02_FieldNo11 */ view::message_field::int32 m_price = m_super_0_data.Price;
    /* R02_FieldNo12 */ view::message_field::uint16 m_qty = m_super_0_data.qty;
    /* R02_FieldNo13 */ view::message_field::uint32 m_investor_acno = m_super_0_data.investor_acno;
    /* R02_FieldNo14 */ view::message_field::char0 m_investor_flag = m_super_0_data.investor_flag;
    /* R02_FieldNo15 */ view::message_field::enumerate::Side m_side = view::message_field::enumerate::Side(m_super_0_data.Side);
    /* R02_FieldNo16 */ view::message_field::enumerate::OrderType m_order_type = view::message_field::enumerate::OrderType(m_super_0_data.OrdType);
    /* R02_FieldNo17 */ view::message_field::enumerate::TimeInForce m_time_in_force = view::message_field::enumerate::TimeInForce(m_super_0_data.TimeInForce);
    /* R02_FieldNo18 */ view::message_field::enumerate::PositionEffect m_position_effect = view::message_field::enumerate::PositionEffect(m_super_0_data.PositionEffect);
    /* R02_FieldNo19 */ view::message_field::int32 m_last_px = m_super_0_data.LastPx;
    /* R02_FieldNo20 */ view::message_field::uint16 m_last_qty = m_super_0_data.LastQty;
    /* R02_FieldNo21 */ view::message_field::int64 m_px_subtotal = m_super_0_data.px_subtotal;
    /* R02_FieldNo22 */ view::message_field::uint16 m_cum_qty = m_super_0_data.CumQty;
    /* R02_FieldNo23 */ view::message_field::uint16 m_leaves_qty = m_super_0_data.LeavesQty;
    /* R02_FieldNo24 */ view::message_field::uint16 m_before_qty = m_super_0_data.before_qty;
    /* R02_FieldNo25 */ view::message_field::array::R02_LegSide m_leg_side = m_super_0_data.leg_side;
    /* R02_FieldNo26 */ view::message_field::array::R02_LegPx m_leg_px = m_super_0_data.leg_px;
    /* R02_FieldNo27 */ view::message_field::array::R02_LegQty m_leg_qty = m_super_0_data.leg_qty;
    /* R02_FieldNo28 */ view::message_field::MsgTime m_org_trans_time = view::message_field::MsgTime(m_super_0_data.org_trans_time);
    /* R02_FieldNo29 */ view::message_field::MsgTime m_transact_time = view::message_field::MsgTime(m_super_0_data.TransactTime);
    /* R02_FieldNo30 */ view::message_field::uint08 m_target_id = m_super_0_data.target_id;
    /* R02_FieldNo31 */ view::message_field::uint32 m_uniq_id = m_super_0_data.uniq_id;
    /* R02_FieldNo32 */ view::message_field::uint32 m_rpt_seq = m_super_0_data.rpt_seq;
    /* R02_FieldNo33 */ view::message_field::enumerate::ProtocolType m_protocol_type = view::message_field::enumerate::ProtocolType(m_super_0_data.protocol_type);
    /* R02_FieldNo34 */ view::message_field::uint08 m_check_sum = m_super_0_data.CheckSum;
};
#undef RXX

/// xplum::taifex_msg_proto_sdk::view::message::R03
#define RXX R03
struct xplum_sdkit::taifex_msg_proto::view::message::RXX : _nshdr::ViewerMsgFixSize<origin::RXX>
{
    MACRO_XPLUM_ANCESTOR_VIEWERMSGFIXSIZE_DEPLOY_SUBCLASS(RXX);
    /* R03_FieldNo01 */ view::message_field::MsgHdr m_hdr = view::message_field::MsgHdr(m_super_0_data.hdr);
    /* R03_FieldNo02 */ view::message_field::uint08 m_status_code = m_super_0_data.status_code;
    /* R03_FieldNo03 */ view::message_field::enumerate::ExecType m_exec_type = view::message_field::enumerate::ExecType(m_super_0_data.ExecType);
    /* R03_FieldNo04 */ view::message_field::uint16 m_fcm_id = m_super_0_data.fcm_id;
    /* R03_FieldNo05 */ view::message_field::array::OrderNo m_order_no = m_super_0_data.order_no;
    /* R03_FieldNo06 */ view::message_field::uint32 m_order_id = m_super_0_data.ord_id;
    /* R03_FieldNo07 */ view::message_field::array::UserDefine m_user_define = m_super_0_data.user_define;
    /* R03_FieldNo08 */ view::message_field::uint32 m_rpt_seq = m_super_0_data.rpt_seq;
    /* R03_FieldNo09 */ view::message_field::enumerate::Side m_side = view::message_field::enumerate::Side(m_super_0_data.Side);
    /* R03_FieldNo10 */ view::message_field::uint08 m_check_sum = m_super_0_data.CheckSum;
};
#undef RXX

///
///
#if (defined(LXX) || defined(RXX))
#error
#error // RXX should undef here.
#error // LXX should undef here.
#endif
