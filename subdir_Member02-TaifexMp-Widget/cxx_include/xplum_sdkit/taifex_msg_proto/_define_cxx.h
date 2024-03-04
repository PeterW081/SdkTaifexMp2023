#pragma once
#include "xplum_model/taifex_msg_proto/_define_cxx.h"

namespace xplum_sdkit::taifex_msg_proto {
namespace type = xplum_model::taifex_msg_proto::type;
namespace ancestor {
class CounterMsgSeqNumV;
class CounterOrderSeqV;
} // namespace ancestor
namespace kitbag {
// Counter: MsgSeqNum
using CounterMsgSeqNumV = ancestor::CounterMsgSeqNumV;
class CounterMsgSeqNumSimple;
// Counter: OrderNo、OrderId
using CounterOrderSeqV = ancestor::CounterOrderSeqV;
class CounterOrderSeqSimple;
// Convertor: OrderNo
struct ConvertorOrderNo;
} // namespace kitbag
} // namespace xplum_sdkit::taifex_msg_proto
