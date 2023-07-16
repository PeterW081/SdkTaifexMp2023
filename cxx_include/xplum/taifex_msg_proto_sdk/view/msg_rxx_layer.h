#pragma once
#include "XPLUM_MACRO/MACRO_INITIALIZATION.h"
#include "xplum/taifex_msg_proto/message/msg_rxx_layer.h"
#include "xplum/taifex_msg_proto_sdk/prototype/ViewerMsg.h"
#include "xplum/taifex_msg_proto_sdk/view/msg_field.h"
#include "xplum/taifex_msg_proto_sdk/view/msg_field_enumerate.h"

namespace xplum::taifex_msg_proto_sdk::view::message
{
	namespace define0
	{
		using prototype::ViewerMsgFixSize;
	}
	namespace raw = xplum::taifex_msg_proto::message;

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
class xplum::taifex_msg_proto_sdk::view::message::RXX : public define0::ViewerMsgFixSize<raw::RXX>
{
  public:
	MACRO_XPLUM_PROTOTYPE_VIEWERMSGFIXSIZE_DEPLOY_SUBCLASS(RXX);
	/* R04_FieldNo01 */ MACRO_XPLUM_AUTO_INIT_INSTANCE(message_field::MsgHdr, m_hdr, m_data.hdr);
	/* R04_FieldNo02 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_status_code, m_data.status_code);
	/* R04_FieldNo03 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_check_sum, m_data.CheckSum);
};
#undef RXX

/// xplum::taifex_msg_proto_sdk::view::message::R05
#define RXX R05
class xplum::taifex_msg_proto_sdk::view::message::RXX : public define0::ViewerMsgFixSize<raw::RXX>
{
  public:
	MACRO_XPLUM_PROTOTYPE_VIEWERMSGFIXSIZE_DEPLOY_SUBCLASS(RXX);
	/* R05_FieldNo01 */ MACRO_XPLUM_AUTO_INIT_INSTANCE(message_field::MsgHdr, m_hdr, m_data.hdr);
	/* R05_FieldNo02 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_status_code, m_data.status_code);
	/* R05_FieldNo03 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_check_sum, m_data.CheckSum);
};
#undef RXX

/// xplum::taifex_msg_proto_sdk::view::message::R11
#define RXX R11
class xplum::taifex_msg_proto_sdk::view::message::RXX : public define0::ViewerMsgFixSize<raw::RXX>
{
  public:
	MACRO_XPLUM_PROTOTYPE_VIEWERMSGFIXSIZE_DEPLOY_SUBCLASS(RXX);
	/* R11_FieldNo01 */ MACRO_XPLUM_AUTO_INIT_INSTANCE(message_field::MsgHdr, m_hdr, m_data.hdr);
	/* R11_FieldNo02 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_status_code, m_data.status_code);
	/* R11_FieldNo03 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_trade_req_id, m_data.TradeReqID);
	/* R11_FieldNo04 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_flow_group_no, m_data.flow_group_no);
	/* R11_FieldNo05 */ MACRO_XPLUM_AUTO_INIT_INSTANCE(message_field::enumerate::SubscriptionRequestType, m_subscription_request_type, m_data.SubscriptionRequestType);
	/* R11_FieldNo06 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_check_sum, m_data.CheckSum);
};
#undef RXX

/// xplum::taifex_msg_proto_sdk::view::message::R12
#define RXX R12
class xplum::taifex_msg_proto_sdk::view::message::RXX : public define0::ViewerMsgFixSize<raw::RXX>
{
  public:
	MACRO_XPLUM_PROTOTYPE_VIEWERMSGFIXSIZE_DEPLOY_SUBCLASS(RXX);
	/* R12_FieldNo01 */ MACRO_XPLUM_AUTO_INIT_INSTANCE(message_field::MsgHdr, m_hdr, m_data.hdr);
	/* R12_FieldNo02 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_status_code, m_data.status_code);
	/* R12_FieldNo03 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_trade_req_id, m_data.TradeReqID);
	/* R12_FieldNo04 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_flow_group_no, m_data.flow_group_no);
	/* R12_FieldNo05 */ MACRO_XPLUM_AUTO_INIT_INSTANCE(message_field::enumerate::TradeStatus, m_trade_status, m_data.TradeStatus);
	/* R12_FieldNo06 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_check_sum, m_data.CheckSum);
};
#undef RXX

/// xplum::taifex_msg_proto_sdk::view::message::R01
#define RXX R01
class xplum::taifex_msg_proto_sdk::view::message::RXX : public define0::ViewerMsgFixSize<raw::RXX>
{
  public:
	MACRO_XPLUM_PROTOTYPE_VIEWERMSGFIXSIZE_DEPLOY_SUBCLASS(RXX);
	/* R01_FieldNo01 */ MACRO_XPLUM_AUTO_INIT_INSTANCE(message_field::MsgHdr, m_hdr, m_data.hdr);
	/* R01_FieldNo02 */ MACRO_XPLUM_AUTO_INIT_INSTANCE(message_field::enumerate::ExecType, m_exec_type, m_data.ExecType);
	/* R01_FieldNo03 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_cm_id, m_data.cm_id);
	/* R01_FieldNo04 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_fcm_id, m_data.fcm_id);
	/* R01_FieldNo05 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_ARRAY(m_order_no, m_data.order_no);
	/* R01_FieldNo06 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_order_id, m_data.ord_id);
	/* R01_FieldNo07 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_ARRAY(m_user_define, m_data.user_define);
	/* R01_FieldNo08 */ MACRO_XPLUM_AUTO_INIT_INSTANCE(message_field::enumerate::SymbolType, m_symbol_type, m_data.symbol_type);
	/* R01_FieldNo09 */ MACRO_XPLUM_AUTO_INIT_INSTANCE(message_field::SymbolX, m_sym, message_field::SymbolNum(m_data.sym.num), message_field::SymbolText(m_data.sym.text));
	/* R01_FieldNo10 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_price, m_data.Price);
	/* R01_FieldNo11 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_qty, m_data.qty);
	/* R01_FieldNo12 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_investor_acno, m_data.investor_acno);
	/* R01_FieldNo13 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_investor_flag, m_data.investor_flag);
	/* R01_FieldNo14 */ MACRO_XPLUM_AUTO_INIT_INSTANCE(message_field::enumerate::Side, m_side, m_data.Side);
	/* R01_FieldNo15 */ MACRO_XPLUM_AUTO_INIT_INSTANCE(message_field::enumerate::OrderType, m_order_type, m_data.OrdType);
	/* R01_FieldNo16 */ MACRO_XPLUM_AUTO_INIT_INSTANCE(message_field::enumerate::TimeInForce, m_time_in_force, m_data.TimeInForce);
	/* R01_FieldNo17 */ MACRO_XPLUM_AUTO_INIT_INSTANCE(message_field::enumerate::PositionEffect, m_position_effect, m_data.PositionEffect);
	/* R01_FieldNo18 */ MACRO_XPLUM_AUTO_INIT_INSTANCE(message_field::enumerate::OrderSource, m_order_source, m_data.order_source);
	/* R01_FieldNo19 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_ARRAY(m_info_source, m_data.info_source);
	/* R01_FieldNo20 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_check_sum, m_data.CheckSum);
};
#undef RXX

/// xplum::taifex_msg_proto_sdk::view::message::R02
#define RXX R02
class xplum::taifex_msg_proto_sdk::view::message::RXX : public define0::ViewerMsgFixSize<raw::RXX>
{
  public:
	MACRO_XPLUM_PROTOTYPE_VIEWERMSGFIXSIZE_DEPLOY_SUBCLASS(RXX);
	/* R02_FieldNo01 */ MACRO_XPLUM_AUTO_INIT_INSTANCE(message_field::MsgHdr, m_hdr, m_data.hdr);
	/* R02_FieldNo02 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_status_code, m_data.status_code);
	/* R02_FieldNo03 */ MACRO_XPLUM_AUTO_INIT_INSTANCE(message_field::enumerate::ExecType, m_exec_type, m_data.ExecType);
	/* R02_FieldNo04 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_cm_id, m_data.cm_id);
	/* R02_FieldNo05 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_fcm_id, m_data.fcm_id);
	/* R02_FieldNo06 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_ARRAY(m_order_no, m_data.order_no);
	/* R02_FieldNo07 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_order_id, m_data.ord_id);
	/* R02_FieldNo08 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_ARRAY(m_user_define, m_data.user_define);
	/* R02_FieldNo09 */ MACRO_XPLUM_AUTO_INIT_INSTANCE(message_field::enumerate::SymbolType, m_symbol_type, m_data.symbol_type);
	/* R02_FieldNo10 */ MACRO_XPLUM_AUTO_INIT_INSTANCE(message_field::SymbolX, m_sym, message_field::SymbolNum(m_data.sym.num), message_field::SymbolText(m_data.sym.text));
	/* R02_FieldNo11 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_price, m_data.Price);
	/* R02_FieldNo12 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_qty, m_data.qty);
	/* R02_FieldNo13 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_investor_acno, m_data.investor_acno);
	/* R02_FieldNo14 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_investor_flag, m_data.investor_flag);
	/* R02_FieldNo15 */ MACRO_XPLUM_AUTO_INIT_INSTANCE(message_field::enumerate::Side, m_side, m_data.Side);
	/* R02_FieldNo16 */ MACRO_XPLUM_AUTO_INIT_INSTANCE(message_field::enumerate::OrderType, m_order_type, m_data.OrdType);
	/* R02_FieldNo17 */ MACRO_XPLUM_AUTO_INIT_INSTANCE(message_field::enumerate::TimeInForce, m_time_in_force, m_data.TimeInForce);
	/* R02_FieldNo18 */ MACRO_XPLUM_AUTO_INIT_INSTANCE(message_field::enumerate::PositionEffect, m_position_effect, m_data.PositionEffect);
	/* R02_FieldNo19 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_last_px, m_data.LastPx);
	/* R02_FieldNo20 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_last_qty, m_data.LastQty);
	/* R02_FieldNo21 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_px_subtotal, m_data.px_subtotal);
	/* R02_FieldNo22 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_cum_qty, m_data.CumQty);
	/* R02_FieldNo23 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_leaves_qty, m_data.LeavesQty);
	/* R02_FieldNo24 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_before_qty, m_data.before_qty);
	/* R02_FieldNo25 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_ARRAY(m_leg_side, m_data.leg_side);
	/* R02_FieldNo26 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_ARRAY(m_leg_px, m_data.leg_px);
	/* R02_FieldNo27 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_ARRAY(m_leg_qty, m_data.leg_qty);
	/* R02_FieldNo28 */ MACRO_XPLUM_AUTO_INIT_INSTANCE(message_field::MsgTime, m_org_trans_time, m_data.org_trans_time);
	/* R02_FieldNo29 */ MACRO_XPLUM_AUTO_INIT_INSTANCE(message_field::MsgTime, m_transact_time, m_data.TransactTime);
	/* R02_FieldNo30 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_target_id, m_data.target_id);
	/* R02_FieldNo31 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_uniq_id, m_data.uniq_id);
	/* R02_FieldNo32 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_rpt_seq, m_data.rpt_seq);
	/* R02_FieldNo33 */ MACRO_XPLUM_AUTO_INIT_INSTANCE(message_field::enumerate::ProtocolType, m_protocol_type, m_data.protocol_type);
	/* R02_FieldNo34 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_check_sum, m_data.CheckSum);
};
#undef RXX

/// xplum::taifex_msg_proto_sdk::view::message::R03
#define RXX R03
class xplum::taifex_msg_proto_sdk::view::message::RXX : public define0::ViewerMsgFixSize<raw::RXX>
{
  public:
	MACRO_XPLUM_PROTOTYPE_VIEWERMSGFIXSIZE_DEPLOY_SUBCLASS(RXX);
	/* R03_FieldNo01 */ MACRO_XPLUM_AUTO_INIT_INSTANCE(message_field::MsgHdr, m_hdr, m_data.hdr);
	/* R03_FieldNo02 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_status_code, m_data.status_code);
	/* R03_FieldNo03 */ MACRO_XPLUM_AUTO_INIT_INSTANCE(message_field::enumerate::ExecType, m_exec_type, m_data.ExecType);
	/* R03_FieldNo04 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_fcm_id, m_data.fcm_id);
	/* R03_FieldNo05 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_ARRAY(m_order_no, m_data.order_no);
	/* R03_FieldNo06 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_order_id, m_data.ord_id);
	/* R03_FieldNo07 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_ARRAY(m_user_define, m_data.user_define);
	/* R03_FieldNo08 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_rpt_seq, m_data.rpt_seq);
	/* R03_FieldNo09 */ MACRO_XPLUM_AUTO_INIT_INSTANCE(message_field::enumerate::Side, m_side, m_data.Side);
	/* R03_FieldNo10 */ MACRO_XPLUM_AUTO_INIT_REFERENCE(m_check_sum, m_data.CheckSum);
};
#undef RXX

///
#ifdef LXX
#	error // RXX should undef here.
#endif
#ifdef RXX
#	error // LXX should undef here.
#endif
