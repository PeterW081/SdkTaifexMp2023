#pragma once
#include "xplum_model/taifex_msg_proto/network_osi_L06/structure_msg/msg_rxx_layer.h"
#

namespace xplum_sdkit::taifex_msg_proto::util
{
using UnionL41DataMember = std::variant<std::nullptr_t, std::span<const std::byte>, xplum_model::taifex_msg_proto::message::R02 *, xplum_model::taifex_msg_proto::message::R03 *>;
}
