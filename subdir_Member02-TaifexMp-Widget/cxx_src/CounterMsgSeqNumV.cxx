#include "xplum_sdkit/taifex_msg_proto/ancestor/CounterMsgSeqNumV.h"

#pragma
namespace nscxx_root = xplum_sdkit::taifex_msg_proto::ancestor;

// using xplum_sdkit::taifex_msg_proto::ancestor::CounterMsgSeqNumV;
//
auto nscxx_root::CounterMsgSeqNumV::peek() const -> std::optional<type::uint32> {
  auto read_lock = std::shared_lock(m_mutex_read_write);
  auto var_return = std::optional<type::uint32>();
  if (this->m_data != M_INIT_DATA) {
    var_return = this->m_data;
  }
  return var_return;
}

auto nscxx_root::CounterMsgSeqNumV::next_0_prefix_increment() -> const std::uint32_t & {
  auto write_lock = std::unique_lock(m_mutex_read_write);
  this->m_data++;
  return this->m_data;
}
