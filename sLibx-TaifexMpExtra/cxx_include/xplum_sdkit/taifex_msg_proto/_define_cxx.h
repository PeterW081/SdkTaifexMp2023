#pragma once
#include "xplum_model/taifex_msg_proto/_define_cxx.h"
#include "xplum_model/taifex_msg_proto/network_osi_L06/structure_msg_field/msg_field_enumerate.h"
#

namespace xplum_sdkit::taifex_msg_proto
{
namespace type = xplum_model::taifex_msg_proto::type;
namespace enumerate
{
using EnumMsgType = xplum_model::taifex_msg_proto::message_field::enumerate::MessageType;
using EnumSystemType = xplum_model::taifex_msg_proto::message_field::enumerate::system_type;
}
namespace ancestor
{
class CounterMsgSeqNum_V;
class CounterOrderSeq_V;
}
namespace util
{
// Counter: MsgSeqNum
using CounterMsgSeqNumV = ancestor::CounterMsgSeqNum_V;
class CounterMsgSeqNumSimple;
// Counter: OrderNo_VIEW、OrderId
using CounterOrderSeq_V = ancestor::CounterOrderSeq_V;
class CounterOrderSeqSimple;
// Convertor: OrderNo_VIEW
struct ConvertorOrderNo;
}
}
