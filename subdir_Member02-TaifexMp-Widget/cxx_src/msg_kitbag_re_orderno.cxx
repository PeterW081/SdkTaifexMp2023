#include "xplum_sdkit/taifex_msg_proto/kitbag/msg_kitbag_re_orderno.h"
#pragma

namespace nscxx_root = xplum_sdkit::taifex_msg_proto::kitbag;

// using xplum_sdkit::taifex_msg_proto::kitbag::CounterOrderSeqSimple;
//
auto
nscxx_root::CounterOrderSeqSimple::storage_load0 (std::nullptr_t melon, ...) -> bool
{
  std::unique_ptr<type::uint32> *order_no;
  std::map<type::uint32, type::uint32> *map_K_order_no_V_order_id;

  using TypeParam02 = std::map<type::uint32, type::uint32> *;
  va_list (args);
  va_start (args, melon);
  order_no = va_arg (args, std::unique_ptr<type::uint32> *);
  map_K_order_no_V_order_id = va_arg (args, TypeParam02);
  va_end (args);

  return this->storage_load (order_no, map_K_order_no_V_order_id);
}
auto
nscxx_root::CounterOrderSeqSimple::storage_save0 (std::nullptr_t melon, ...) const -> bool
{
  std::unique_ptr<type::uint32> *order_no;
  std::map<type::uint32, type::uint32> *map_K_order_no_V_order_id;

  using TypeParam02 = std::map<type::uint32, type::uint32> *;
  va_list (args);
  va_start (args, melon);
  order_no = va_arg (args, std::unique_ptr<type::uint32> *);
  map_K_order_no_V_order_id = va_arg (args, TypeParam02);
  va_end (args);

  return this->storage_save (order_no, map_K_order_no_V_order_id);
}
auto
nscxx_root::CounterOrderSeqSimple::storage_load (std::unique_ptr<type::uint32> *order_no, std::map<type::uint32, type::uint32> *map_K_order_no_V_order_id) -> bool
{
  if (order_no == nullptr || map_K_order_no_V_order_id == nullptr)
    {
      assert (!(order_no == nullptr));
      assert (!(map_K_order_no_V_order_id == nullptr));
      return false;
    }

  std::unique_ptr<type::uint32> &order_no0 = *order_no;
  std::map<type::uint32, type::uint32> &map_K_order_no_V_order_id0 = *map_K_order_no_V_order_id;
  if (order_no0 == nullptr)
    {
      assert (!(order_no0.get () == nullptr));
      return false;
    }

  auto total_lock = std::unique_lock (m_mutex_read_write);
  this->m_order_no = *order_no0;
  this->m_map_K_order_no_V_order_id.clear ();
  for (auto &var : map_K_order_no_V_order_id0)
    {
      this->m_map_K_order_no_V_order_id.insert (var);
    }
  return true;
}
auto
nscxx_root::CounterOrderSeqSimple::storage_save (std::unique_ptr<type::uint32> *order_no, std::map<type::uint32, type::uint32> *map_K_order_no_V_order_id) const -> bool
{
  if (order_no == nullptr || map_K_order_no_V_order_id == nullptr)
    {
      assert (!(order_no == nullptr));
      assert (!(map_K_order_no_V_order_id == nullptr));
      return false;
    }

  std::unique_ptr<type::uint32> &order_no0 = *order_no;
  std::map<type::uint32, type::uint32> &map_K_order_no_V_order_id0 = *map_K_order_no_V_order_id;
  if (order_no0 == nullptr)
    {
      order_no0 = std::make_unique<type::uint32> ();
    }

  auto total_lock = std::unique_lock (m_mutex_read_write);
  *order_no0 = this->m_order_no;
  map_K_order_no_V_order_id0.clear ();
  for (auto &var : this->m_map_K_order_no_V_order_id)
    {
      map_K_order_no_V_order_id0.insert (var);
    }
  return true;
}

// using xplum_sdkit::taifex_msg_proto::kitbag::CounterOrderSeqSimple;
using xplum_sdkit::taifex_msg_proto::kitbag::ConvertorOrderNo;
//
auto
ConvertorOrderNo::FX_CONVERT_ORDER_NO_TO_VALUE (std::string_view txt_value) -> std::optional<std::uint32_t>
{
  return To_Value (txt_value);
}
auto
ConvertorOrderNo::FX_CONVERT_ORDER_NO_TO_TEXT_STRING (std::uint32_t int_value) -> std::string
{
  return To_String (int_value);
}
