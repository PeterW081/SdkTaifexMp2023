#pragma once
#include "xplum_model/taifex_msg_proto/_define_cxx.h"

namespace xplum_model::taifex_msg_proto::message_field::enumerate
{
enum class MessageType : type::uint08;
enum class system_type : type::uint08;
enum class EncryptMethod : type::uint08;
enum class is_eof : type::uint08;
enum class SubscriptionRequestType : type::uint08;
enum class TradeStatus : type::uint08;

// Re: Order
enum class ExecType : type::char0;
enum class symbol_type : type::uint08;
enum class Side : type::uint08;
enum class OrdType : type::uint08;
enum class TimeInForce : type::uint08;
enum class PositionEffect : type::char0;
enum class order_source : type::char0;
// Re: Order - R02
enum class leg_side : type::uint08;
enum class target_id : type::uint08;
enum class protocol_type : type::uint08;
}

enum class xplum_model::taifex_msg_proto::message_field::enumerate::MessageType : xplum_model::taifex_msg_proto::type::uint08
{
    // LxxLayer
    L10 = 10,
    L20 = 20,
    L30 = 30,
    L40 = 40,
    L41 = 41,
    L42 = 42,
    L50 = 50,
    L60 = 60,
    // RxxLayer - 連線狀態維護
    R04 = 104,
    R05 = 105,
    R11 = 111,
    R12 = 112,
    // RxxLayer - 期貨交易操作: 普通操作報文
    R01 = 101,
    R02 = 102,
    R03 = 103,
    // RxxLayer - 期貨交易操作: 造市操作報文
    R07 = 107,
    R08 = 108,
    R09 = 109,
    // RxxLayer - 期貨交易操作: R02 報文的變體報文。
    R22 = 122,
    R06 = 106,
};

enum class xplum_model::taifex_msg_proto::message_field::enumerate::system_type : xplum_model::taifex_msg_proto::type::uint08
{
    INT_10_OPTIONS_REGULAR_MARKET_HOURS = 10,
    INT_11_OPTIONS_AFTER_MARKET_HOURS = 11,
    INT_20_FUTURES_REGULAR_MARKET_HOURS = 20,
    INT_21_FUTURES_AFTER_MARKET_HOURS = 21,
};

enum class xplum_model::taifex_msg_proto::message_field::enumerate::EncryptMethod : xplum_model::taifex_msg_proto::type::uint08
{
    UNENCRYPTED = 0,
};

enum class xplum_model::taifex_msg_proto::message_field::enumerate::is_eof : xplum_model::taifex_msg_proto::type::uint08
{
    NO = 0,
    END_OF_FILE = 1,
};

enum class xplum_model::taifex_msg_proto::message_field::enumerate::SubscriptionRequestType : xplum_model::taifex_msg_proto::type::uint08
{
    CURRENT_STATUS = 0,
    CURRENT_SUBSEQUENT_CHANGES = 1,
    CANCEL_STATUS_SUBSCRIPTION = 2,
};

enum class xplum_model::taifex_msg_proto::message_field::enumerate::TradeStatus : xplum_model::taifex_msg_proto::type::uint08
{
    UNKNOWN = 0,
    HALTED = 1,
    OPEN = 2,
    CLOSED = 3,
    PRE_OPEN = 4,
    NON_CANCEL_PERIOD = 5,
};

enum class xplum_model::taifex_msg_proto::message_field::enumerate::ExecType : xplum_model::taifex_msg_proto::type::char0
{
    CHAR_0_NEW = '0',
    CHAR_4_CANCEL = '4',
    CHAR_5_DECREASE = '5',
    CHAR_M_MODIFY_PRICE = 'M',
    CHAR_m_MODIFY_PRICE = 'm',
    CHAR_I_QUERY = 'I',
};

enum class xplum_model::taifex_msg_proto::message_field::enumerate::symbol_type : xplum_model::taifex_msg_proto::type::uint08
{
    R01_NUM = 1,
    R01_TEXT = 2,
    R31_NUM = 3,
    R31_TEXT = 4,
};

enum class xplum_model::taifex_msg_proto::message_field::enumerate::Side : xplum_model::taifex_msg_proto::type::uint08
{
    BUY = 1,
    SELL = 2,
};

enum class xplum_model::taifex_msg_proto::message_field::enumerate::OrdType : xplum_model::taifex_msg_proto::type::uint08
{
    MARKET = 1,
    LIMIT = 2,
    MWP = 3,
};

enum class xplum_model::taifex_msg_proto::message_field::enumerate::TimeInForce : xplum_model::taifex_msg_proto::type::uint08
{
    FOK = 4,
    IOC = 3,
    ROD = 0,
    QUOTE_AUTOMATICALLY_CANCELLED_AFTER_A_PERIOD_OF_TIME = 8,
};

enum class xplum_model::taifex_msg_proto::message_field::enumerate::PositionEffect : xplum_model::taifex_msg_proto::type::char0
{
    CHAR_O_OPEN = 'O',
    CHAR_C_CLOSE = 'C',
    CHAR_D_DAYTRADE = 'D',
    CHAR_9_QUOTE = '9',
    CHAR_A_OPEN_SPECIFIED_POSITION_OFFSETS = 'A',
    CHAR_7_OFFSET_BY_FCM = '7',
};

enum class xplum_model::taifex_msg_proto::message_field::enumerate::order_source : xplum_model::taifex_msg_proto::type::char0
{
    CHAR_D_Leased_Line_or_VPN_or_Closed_private_network = 'D',
    CHAR_A_API = 'A',
    CHAR_M_Mobile_device = 'M',
    CHAR_W_Web_site = 'W',
    CHAR_P_Personal_computer = 'P',
    CHAR_V_Voice = 'V',
    CHAR_G_writing_telephone_telegram = 'G',
};

enum class xplum_model::taifex_msg_proto::message_field::enumerate::leg_side : xplum_model::taifex_msg_proto::type::uint08
{
    SINGLE_ORDER = 0,
    BUY = 1,
    SELL = 2,
};

enum class xplum_model::taifex_msg_proto::message_field::enumerate::target_id : xplum_model::taifex_msg_proto::type::uint08
{
    INT_04_FCM = 4,
    INT_08_CLEARING_MEMBER_ORDER_STATUS_REPORT = 8,
    INT_18_CLEARING_MEMBER_ORDER_STATUS_REPORT = 18,
    INT_09_CLEARING_MEMBER_ORDER_EXECUTION_REPORT = 9,
    INT_19_CLEARING_MEMBER_ORDER_EXECUTION_REPORT = 19,
    INT_03_EXECUTION_REPORT_INCLUDING_HEAD_OFFICE_AND_BRANCH_OFFICES = 3,
    INT_13_EXECUTION_REPORT_INCLUDING_HEAD_OFFICE_AND_BRANCH_OFFICES = 13,
};

enum class xplum_model::taifex_msg_proto::message_field::enumerate::protocol_type : xplum_model::taifex_msg_proto::type::uint08
{
    RESERVED = 0,
    TMP = 1,
    FIX = 2,
};
