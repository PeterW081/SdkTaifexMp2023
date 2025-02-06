#pragma once
#include "./PlugerMsg_SP_L40.h"
#pragma
#include "xplum/ancestor/Pluginer.h"
#include "xplum_sdkit/taifex_msg_proto/_define_cxx.h"
#

/// namespace
namespace xplum_sdkit::taifex_msg_proto::view::message_plugin
{
template <typename TYPE_msg_view>
class PlugerMsg_SP_L40;
}

/// class - PlugerMsg_SP_L40
template <typename TYPE_msg_view>
class                                                     //
    xplum_sdkit::taifex_msg_proto::view::message_plugin:: //
    PlugerMsg_SP_L40                                      //
    : public xplum::ancestor::Pluginer<PlugerMsg_SP_L40<TYPE_msg_view>, TYPE_msg_view>
{
  protected:
    explicit PlugerMsg_SP_L40();

  public:
    auto fx_assert_m_key_value(type::uint16, type::uint16) const -> bool;                      // session_passwd, append_no,
    auto fx_assign_m_key_value_0_algorithm [[nodiscard]] (type::uint16, type::uint16) -> bool; // session_passwd, append_no, -> is_ok
};
