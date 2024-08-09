#pragma once
#include <map>
#include <set>
#include <shared_mutex>
#include "xplum/ablething/StorageAbleV.h"
#include "xplum_sdkit/taifex_msg_proto/_define_cxx.h"

namespace xplum_sdkit::taifex_msg_proto::ancestor
{
class CounterOrderSeqV;
}

class xplum_sdkit::taifex_msg_proto::ancestor::CounterOrderSeqV : public xplum::ablething::StorageAbleV::StorageAbleV
{
public:
  using TypeOrderNo = type::uint32;
  using TypeOrderId = type::uint32;
  virtual ~CounterOrderSeqV () = default;
  virtual auto peek_order_no () const -> std::optional<type::uint32> final;
  virtual auto next_order_no_0_prefix_increment () -> const type::uint32 & final;
  virtual auto peek_order_id (type::uint32 order_no) const -> std::optional<type::uint32> final;
  virtual auto next_order_id_0_prefix_increment (type::uint32 order_no) -> const type::uint32 & final;

protected:
  static const type::uint32 M_INIT_ORDER_NO = type::uint32 (-1);
  static const type::uint32 M_INIT_ORDER_ID = 0;
  mutable std::shared_mutex m_mutex_read_write;
  type::uint32 m_order_no = M_INIT_ORDER_NO;
  std::map<type::uint32, type::uint32> m_map_K_order_no_V_order_id;
  auto storage_save0 (std::nullptr_t melon, ...) const -> bool override = 0;
  auto storage_load0 (std::nullptr_t melon, ...) -> bool override = 0;
};
