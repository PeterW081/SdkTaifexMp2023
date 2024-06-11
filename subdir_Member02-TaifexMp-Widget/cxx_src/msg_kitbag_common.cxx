#include "xplum_sdkit/taifex_msg_proto/kitbag/msg_kitbag_common.h"
#pragma

#include <cassert>
namespace nscxx_root = xplum_sdkit::taifex_msg_proto::kitbag;

// using xplum_sdkit::taifex_msg_proto::kitbag::CounterMsgSeqNumSimple;
//
auto nscxx_root::CounterMsgSeqNumSimple::storage_load0(std::nullptr_t melon, ...) -> bool {
  std::unique_ptr<type::uint32> *value;

  va_list(args);
  va_start(args, melon);
  value = va_arg(args, std::unique_ptr<type::uint32> *);
  va_end(args);

  return this->storage_load(value);
}
auto nscxx_root::CounterMsgSeqNumSimple::storage_save0(std::nullptr_t melon, ...) const -> bool {
  std::unique_ptr<type::uint32> *value;

  va_list(args);
  va_start(args, melon);
  value = va_arg(args, std::unique_ptr<type::uint32> *);
  va_end(args);

  return this->storage_save(value);
}
auto nscxx_root::CounterMsgSeqNumSimple::storage_load(std::unique_ptr<type::uint32> *value) -> bool {
  if (value == nullptr) {
    assert(!(value == nullptr));
    return false;
  }

  std::unique_ptr<type::uint32> &value0 = *value;
  if (value0 == nullptr) {
    assert(!(value0.get() == nullptr));
    return false;
  }

  auto total_lock = std::unique_lock(m_mutex_read_write);
  this->m_data = *value0;
  return true;
}
auto nscxx_root::CounterMsgSeqNumSimple::storage_save(std::unique_ptr<type::uint32> *value) const -> bool {
  if (value == nullptr) {
    assert(!(value == nullptr));
    return false;
  }

  std::unique_ptr<type::uint32> &value0 = *value;
  if (value0 == nullptr) {
    value0 = std::make_unique<type::uint32>();
  }

  auto total_lock = std::unique_lock(m_mutex_read_write);
  *value0 = this->m_data;
  return true;
}
