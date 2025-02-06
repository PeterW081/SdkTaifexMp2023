#pragma once
#include <shared_mutex>
#include "xplum/ablething/StorageAble_V.h"
#include "xplum_sdkit/taifex_msg_proto/_define_cxx.h"
#

namespace xplum_sdkit::taifex_msg_proto::ancestor
{
class CounterMsgSeqNum_V;
}

class xplum_sdkit::taifex_msg_proto::ancestor::CounterMsgSeqNum_V : public xplum::ablething::StorageAble_V::StorageAble_V
{
  public:
    using TypeMsgSeqNum = type::uint32;
    virtual ~CounterMsgSeqNum_V() = default;
    virtual auto fv_peek() const -> std::optional<type::uint32> final;
    virtual auto fv_next_0_prefix_increment() -> const type::uint32 & final;

  protected:
    static const type::uint32 M_init_data = 0;
    mutable std::shared_mutex m_mutex_read_write;
    type::uint32 m_data = M_init_data;
    virtual auto fv_storage_save0(std::nullptr_t melon, ...) const -> bool override = 0;
    virtual auto fv_storage_load0(std::nullptr_t melon, ...) -> bool override = 0;
};
