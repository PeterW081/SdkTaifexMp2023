#include "xplum_sdkit/taifex_msg_proto/ancestor/CounterOrderSeqV.h"

#pragma
namespace nscxx_root = xplum_sdkit::taifex_msg_proto::ancestor;

// using xplum_sdkit::taifex_msg_proto::ancestor::CounterOrderSeqV;
//
auto nscxx_root::CounterOrderSeqV::peek_order_no() const -> std::optional<type::uint32> {
  auto read_lock = std::shared_lock(m_mutex_read_write);

  if (this->m_order_no == M_INIT_ORDER_NO) {
    return std::nullopt;
  }
  return this->m_order_no;
}

auto nscxx_root::CounterOrderSeqV::next_order_no_0_prefix_increment() -> const type::uint32 & {
  auto write_lock = std::unique_lock(m_mutex_read_write);
  this->m_order_no++;
  while (this->m_map_K_order_no_V_order_id.contains(this->m_order_no)) {
    this->m_order_no++;
  }
  this->m_map_K_order_no_V_order_id[this->m_order_no] = M_INIT_ORDER_ID;
  return this->m_order_no;
}

auto nscxx_root::CounterOrderSeqV::peek_order_id(type::uint32 order_no) const -> std::optional<type::uint32> {
  auto read_lock = std::shared_lock(m_mutex_read_write);

  if (not this->m_map_K_order_no_V_order_id.contains(order_no)) {
    return std::nullopt;
  }
  auto var = this->m_map_K_order_no_V_order_id.at(order_no);
  if (var == M_INIT_ORDER_ID) {
    return std::nullopt;
  }
  return var;
}

auto nscxx_root::CounterOrderSeqV::next_order_id_0_prefix_increment(type::uint32 order_no) -> const type::uint32 & {
  auto write_lock = std::unique_lock(m_mutex_read_write);
  if (not m_map_K_order_no_V_order_id.contains(order_no)) {
    this->m_map_K_order_no_V_order_id[order_no] = M_INIT_ORDER_ID;
  }
  type::uint32 &order_id = this->m_map_K_order_no_V_order_id[order_no];
  order_id++;
  return order_id;
}
