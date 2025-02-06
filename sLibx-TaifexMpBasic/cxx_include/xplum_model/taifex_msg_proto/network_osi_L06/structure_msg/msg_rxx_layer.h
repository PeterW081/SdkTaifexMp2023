#pragma once
#include "xplum_model/taifex_msg_proto/network_osi_L06/constant_msg.h"
#include "xplum_model/taifex_msg_proto/network_osi_L06/structure_msg_field/msg_field.h"
#include "xplum_model/taifex_msg_proto/network_osi_L06/structure_msg_field/msg_field_enumerate.h"
#

namespace xplum_model::taifex_msg_proto::message
{
// RxxLayer - 連線狀態維護
struct R04;
struct R05;
struct R11;
struct R12;
// RxxLayer - 期貨交易操作: 普通操作報文
struct R01;
struct R02;
struct R03;
// RxxLayer - 期貨交易操作: 造市操作報文
struct R07; // TODO
struct R08; // TODO
struct R09; // TODO
// RxxLayer - 期貨交易操作: R02 報文的變體報文。
struct R22; // TODO
struct R06; // TODO
}

/// xplum::taifex_msg_proto::message::R04
#define RXX R04
struct xplum_model::taifex_msg_proto::message::RXX
{
    /* R04_FieldNo01 */ message_field::hdr hdr = {
        .msg_length = sizeof(RXX) - msg_sizeof_content::G_size_out_of_msg_length,
        .MsgSeqNum = 0,
        .MessageType = static_cast<message_field::uint8::value_type>(message_field::enumerate::MessageType::RXX),
    };
    /* R04_FieldNo02 */ message_field::uint8 status_code;
    /* R04_FieldNo03 */ message_field::uint8 CheckSum;
};
#undef RXX

/// xplum::taifex_msg_proto::message::R05
#define RXX R05
struct xplum_model::taifex_msg_proto::message::RXX
{
    /* R05_FieldNo01 */ message_field::hdr hdr = {
        .msg_length = sizeof(RXX) - msg_sizeof_content::G_size_out_of_msg_length,
        .MsgSeqNum = 0,
        .MessageType = static_cast<message_field::uint8::value_type>(message_field::enumerate::MessageType::RXX),
    };
    /* R05_FieldNo02 */ message_field::uint8 status_code;
    /* R05_FieldNo03 */ message_field::uint8 CheckSum;
};
#undef RXX

/// xplum::taifex_msg_proto::message::R11
#define RXX R11
struct xplum_model::taifex_msg_proto::message::RXX
{
    /* R11_FieldNo01 */ message_field::hdr hdr = {
        .msg_length = sizeof(RXX) - msg_sizeof_content::G_size_out_of_msg_length,
        .MsgSeqNum = 0,
        .MessageType = static_cast<message_field::uint8::value_type>(message_field::enumerate::MessageType::RXX),
    };
    /* R11_FieldNo02 */ message_field::uint8 status_code;
    /* R11_FieldNo03 */ message_field::uint16 TradeReqID;
    /* R11_FieldNo04 */ message_field::uint8 flow_group_no;
    /* R11_FieldNo05 */ message_field::uint8 SubscriptionRequestType;
    /* R11_FieldNo06 */ message_field::uint8 CheckSum;
};
#undef RXX

/// xplum::taifex_msg_proto::message::R12
#define RXX R12
struct xplum_model::taifex_msg_proto::message::RXX
{
    /* R12_FieldNo01 */ message_field::hdr hdr = {
        .msg_length = sizeof(RXX) - msg_sizeof_content::G_size_out_of_msg_length,
        .MsgSeqNum = 0,
        .MessageType = static_cast<message_field::uint8::value_type>(message_field::enumerate::MessageType::RXX),
    };
    /* R12_FieldNo02 */ message_field::uint8 status_code;
    /* R12_FieldNo03 */ message_field::uint16 TradeReqID;
    /* R12_FieldNo04 */ message_field::uint8 flow_group_no;
    /* R12_FieldNo05 */ message_field::uint8 TradeStatus;
    /* R12_FieldNo06 */ message_field::uint8 CheckSum;
};
#undef RXX

/// xplum::taifex_msg_proto::message::R01
#define RXX R01
struct xplum_model::taifex_msg_proto::message::RXX
{
    /* R01_FieldNo01 */ message_field::hdr hdr = {
        .msg_length = sizeof(RXX) - msg_sizeof_content::G_size_out_of_msg_length,
        .MsgSeqNum = 0,
        .MessageType = static_cast<message_field::uint8::value_type>(message_field::enumerate::MessageType::RXX),
    };
    /* R01_FieldNo02 */ message_field::char0 ExecType;
    /* R01_FieldNo03 */ message_field::uint16 cm_id;
    /* R01_FieldNo04 */ message_field::uint16 fcm_id;
    /* R01_FieldNo05 */ message_field::char0_arr<5> order_no;
    /* R01_FieldNo06 */ message_field::uint32 ord_id;
    /* R01_FieldNo07 */ message_field::char0_arr<8> user_define;
    /* R01_FieldNo08 */ message_field::uint8 symbol_type;
    /* R01_FieldNo09 */ message_field::symbol_x sym;
    /* R01_FieldNo10 */ message_field::int32 Price;
    /* R01_FieldNo11 */ message_field::uint16 qty;
    /* R01_FieldNo12 */ message_field::uint32 investor_acno;
    /* R01_FieldNo13 */ message_field::char0 investor_flag;
    /* R01_FieldNo14 */ message_field::uint8 Side;
    /* R01_FieldNo15 */ message_field::uint8 OrdType;
    /* R01_FieldNo16 */ message_field::uint8 TimeInForce;
    /* R01_FieldNo17 */ message_field::char0 PositionEffect;
    /* R01_FieldNo18 */ message_field::char0 order_source;
    /* R01_FieldNo19 */ message_field::char0_arr<3> info_source = {'9', '9', '9'};
    /* R01_FieldNo20 */ message_field::uint8 CheckSum;
};
#undef RXX

/// xplum::taifex_msg_proto::message::R02
#define RXX R02
struct xplum_model::taifex_msg_proto::message::RXX
{
    /* R02_FieldNo01 */ message_field::hdr hdr = {
        .msg_length = sizeof(RXX) - msg_sizeof_content::G_size_out_of_msg_length,
        .MsgSeqNum = 0,
        .MessageType = static_cast<message_field::uint8::value_type>(message_field::enumerate::MessageType::RXX),
    };
    /* R02_FieldNo02 */ message_field::uint8 status_code;
    /* R02_FieldNo03 */ message_field::char0 ExecType;
    /* R02_FieldNo04 */ message_field::uint16 cm_id;
    /* R02_FieldNo05 */ message_field::uint16 fcm_id;
    /* R02_FieldNo06 */ message_field::char0_arr<5> order_no;
    /* R02_FieldNo07 */ message_field::uint32 ord_id;
    /* R02_FieldNo08 */ message_field::char0_arr<8> user_define;
    /* R02_FieldNo09 */ message_field::uint8 symbol_type;
    /* R02_FieldNo10 */ message_field::symbol_x sym;
    /* R02_FieldNo11 */ message_field::int32 Price;
    /* R02_FieldNo12 */ message_field::uint16 qty;
    /* R02_FieldNo13 */ message_field::uint32 investor_acno;
    /* R02_FieldNo14 */ message_field::char0 investor_flag;
    /* R02_FieldNo15 */ message_field::uint8 Side;
    /* R02_FieldNo16 */ message_field::uint8 OrdType;
    /* R02_FieldNo17 */ message_field::uint8 TimeInForce;
    /* R02_FieldNo18 */ message_field::char0 PositionEffect;
    /* R02_FieldNo19 */ message_field::int32 LastPx;
    /* R02_FieldNo20 */ message_field::uint16 LastQty;
    /* R02_FieldNo21 */ message_field::int64 px_subtotal;
    /* R02_FieldNo22 */ message_field::uint16 CumQty;
    /* R02_FieldNo23 */ message_field::uint16 LeavesQty;
    /* R02_FieldNo24 */ message_field::uint16 before_qty;
    /* R02_FieldNo25 */ message_field::uint8_arr<2> leg_side;
    /* R02_FieldNo26 */ message_field::int32_arr<2> leg_px;
    /* R02_FieldNo27 */ message_field::uint16_arr<2> leg_qty;
    /* R02_FieldNo28 */ message_field::msg_time org_trans_time;
    /* R02_FieldNo29 */ message_field::msg_time TransactTime;
    /* R02_FieldNo30 */ message_field::uint8 target_id;
    /* R02_FieldNo31 */ message_field::uint32 uniq_id;
    /* R02_FieldNo32 */ message_field::uint32 rpt_seq;
    /* R02_FieldNo33 */ message_field::uint8 protocol_type;
    /* R02_FieldNo34 */ message_field::uint8 CheckSum;
};
#undef RXX

/// xplum::taifex_msg_proto::message::R03
#define RXX R03
struct xplum_model::taifex_msg_proto::message::RXX
{
    /* R03_FieldNo01 */ message_field::hdr hdr = {
        .msg_length = sizeof(RXX) - msg_sizeof_content::G_size_out_of_msg_length,
        .MsgSeqNum = 0,
        .MessageType = static_cast<message_field::uint8::value_type>(message_field::enumerate::MessageType::RXX),
    };
    /* R03_FieldNo02 */ message_field::uint8 status_code;
    /* R03_FieldNo03 */ message_field::char0 ExecType;
    /* R03_FieldNo04 */ message_field::uint16 fcm_id;
    /* R03_FieldNo05 */ message_field::char0_arr<5> order_no;
    /* R03_FieldNo06 */ message_field::uint32 ord_id;
    /* R03_FieldNo07 */ message_field::char0_arr<8> user_define;
    /* R03_FieldNo08 */ message_field::uint32 rpt_seq;
    /* R03_FieldNo09 */ message_field::uint8 Side;
    /* R03_FieldNo10 */ message_field::uint8 CheckSum;
};
#undef RXX

///
///
#if (defined(LXX) || defined(RXX))
#error
#error // RXX should undef here.
#error // LXX should undef here.
#endif
