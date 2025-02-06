#pragma once
#include "./PlugerMsg_SP_L41.h"
#pragma
#include <list>
#include "xplum/ancestor/Pluginer.h"
#include "xplum_sdkit/taifex_msg_proto/network_osi_L06/partition_msg/msg_util_SP_L41.h"
#

/// namespace
namespace xplum_sdkit::taifex_msg_proto::view::message_plugin
{
template <typename TYPE_msg_view>
class PlugerMsg_SP_L41;
}

/// class - PlugerMsg_SP_L41
template <typename TYPE_msg_view>
class                                                     //
    xplum_sdkit::taifex_msg_proto::view::message_plugin:: //
    PlugerMsg_SP_L41                                      //
    : public xplum::ancestor::Pluginer<PlugerMsg_SP_L41<TYPE_msg_view>, TYPE_msg_view>
{
  protected:
    explicit PlugerMsg_SP_L41();

  public:
    auto fx_virgin_m_data() -> std::list<util::UnionL41DataMember>;
};
