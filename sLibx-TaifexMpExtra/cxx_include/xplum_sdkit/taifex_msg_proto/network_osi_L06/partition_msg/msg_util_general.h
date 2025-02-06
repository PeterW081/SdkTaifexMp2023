#pragma once
#include "xplum_sdkit/taifex_msg_proto/ancestor/CounterMsgSeqNum_V.h"
#

namespace xplum_sdkit::taifex_msg_proto::util
{
// Counter: MsgSeqNum
using CounterMsgSeqNum_V = ancestor::CounterMsgSeqNum_V;
class CounterMsgSeqNumSimple;
}

class xplum_sdkit::taifex_msg_proto::util:: //
    CounterMsgSeqNumSimple                  //
    : public CounterMsgSeqNum_V
{
  public:
    auto fx_storage_load(std::unique_ptr<type::uint32> *value) -> bool;
    auto fx_storage_save(std::unique_ptr<type::uint32> *value) const -> bool;

  protected:
    auto fv_storage_load0(std::nullptr_t melon, ...) -> bool override;
    auto fv_storage_save0(std::nullptr_t melon, ...) const -> bool override;
};
