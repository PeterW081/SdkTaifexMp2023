#pragma once
#include <shared_mutex>
#include <optional>
#include "xplum/ablething/StorageAbleV.h"
#include "xplum_sdkit/taifex_msg_proto/_define_cxx.h"

namespace xplum_sdkit::taifex_msg_proto::ancestor
{
class CounterMsgSeqNumV;
}

class xplum_sdkit::taifex_msg_proto::ancestor::CounterMsgSeqNumV : public xplum::ablething::StorageAbleV::StorageAbleV
{
public:
  using TypeMsgSeqNum = type::uint32;
  virtual ~CounterMsgSeqNumV () = default;
  virtual auto peek () const -> std::optional<type::uint32> final;
  virtual auto next_0_prefix_increment () -> const type::uint32 & final;

protected:
  static const type::uint32 M_INIT_DATA = 0;
  mutable std::shared_mutex m_mutex_read_write;
  type::uint32 m_data = M_INIT_DATA;
  auto storage_save0 (std::nullptr_t melon, ...) const -> bool override = 0;
  auto storage_load0 (std::nullptr_t melon, ...) -> bool override = 0;
};
