#include "xplum_model/taifex_msg_proto/network_osi_L06/function_msg.h"
#pragma
#include <cstddef>
#include "xplum_model/taifex_msg_proto/_define_cxx.h"
#

namespace nscxx_root = xplum_model::taifex_msg_proto::msg_algorithm;
namespace nscxx
{
}

/// nscxx_root
auto             //
    nscxx_root:: //
    FX_msg_check_sum(const std::byte *msg_data, std::size_t msg_size) -> type::uint08
{
    std::uint8_t result = 0;
    for (std::size_t i = 0, j = (msg_size - sizeof(std::byte)); i < j; i++)
    {
        result += static_cast<std::underlying_type<std::byte>::type>(msg_data[i]);
    }
    return result;
}
auto             //
    nscxx_root:: //
    FX_msg_L40_key_value(type::uint16 session_passwd, type::uint16 append_no) -> type::uint08
{
    std::uint64_t result;
    result = session_passwd * append_no;
    result = (((result % 10000) / 1000) * 10) + ((result % 1000) / 100);
    return result;
}
