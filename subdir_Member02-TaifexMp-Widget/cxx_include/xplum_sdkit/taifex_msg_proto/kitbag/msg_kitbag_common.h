#pragma once
#include "xplum_sdkit/taifex_msg_proto/ancestor/CounterMsgSeqNumV.h"

namespace xplum_sdkit::taifex_msg_proto::kitbag {
// Counter: MsgSeqNum
using CounterMsgSeqNumV = ancestor::CounterMsgSeqNumV;
class CounterMsgSeqNumSimple;
}

class xplum_sdkit::taifex_msg_proto::kitbag:: //
    CounterMsgSeqNumSimple                    //
    : public CounterMsgSeqNumV {
public:
  auto storage_load(std::unique_ptr<type::uint32> *value) -> bool;
  auto storage_save(std::unique_ptr<type::uint32> *value) const -> bool;

protected:
  auto storage_load0(std::nullptr_t melon, ...) -> bool override;
  auto storage_save0(std::nullptr_t melon, ...) const -> bool override;
};
