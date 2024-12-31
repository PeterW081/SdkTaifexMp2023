#pragma once
#include "xplum_sdkit/taifex_msg_proto/view/msg_rxx_layer.h"

namespace xplum_sdkit::taifex_msg_proto::kitbag
{
using UnionL41DataMember = std::variant<std::nullptr_t, std::span<const std::byte>, view::message::origin::R02 *, view::message::origin::R03 *>;
}
