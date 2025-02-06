#pragma once
#include <map>
#include <set>
#include <shared_mutex>
#include "xplum/ablething/StorageAble_V.h"
#include "xplum_sdkit/taifex_msg_proto/_define_cxx.h"
#

namespace xplum_sdkit::taifex_msg_proto::ancestor
{
class CounterOrderSeq_V;
}

class xplum_sdkit::taifex_msg_proto::ancestor::CounterOrderSeq_V : public xplum::ablething::StorageAble_V::StorageAble_V
{
  public:
    using TypeOrderNo = type::uint32;
    using TypeOrderId = type::uint32;
    virtual ~CounterOrderSeq_V() = default;
    virtual auto fv_peek_order_no() const -> std::optional<type::uint32> final;
    virtual auto fv_next_order_no_0_prefix_increment() -> const type::uint32 & final;
    virtual auto fv_peek_order_id(type::uint32 order_no) const -> std::optional<type::uint32> final;
    virtual auto fv_next_order_id_0_prefix_increment(type::uint32 order_no) -> const type::uint32 & final;

  protected:
    static const type::uint32 M_init_order_no = type::uint32(-1);
    static const type::uint32 M_init_order_id = 0;
    mutable std::shared_mutex m_mutex_read_write;
    type::uint32 m_order_no = M_init_order_no;
    std::map<type::uint32, type::uint32> m_map_K_order_no_V_order_id;
    virtual auto fv_storage_save0(std::nullptr_t melon, ...) const -> bool override = 0;
    virtual auto fv_storage_load0(std::nullptr_t melon, ...) -> bool override = 0;
};
