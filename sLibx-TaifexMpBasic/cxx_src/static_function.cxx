#include "xplum_model/taifex_msg_proto/static_function_msg.h"

#pragma
#include <cstddef>
#include "xplum_model/taifex_msg_proto/_define_cxx.h"

#pragma
namespace nscxx_root = xplum_model::taifex_msg_proto::algorithm;

auto nscxx_root::FX_MSG_CHECK_SUM(const std::byte *msg_data, std::size_t msg_size) -> type::uint08
{
    std::uint8_t result = 0;
    for (std::size_t i = 0, j = msg_size; i < j; i++)
    {
        result += static_cast<std::underlying_type<std::byte>::type>(msg_data[i]);
    }
    return result;
}

auto nscxx_root::FX_MSG_L40_KEY_VALUE(type::uint16 session_passwd, type::uint16 append_no) -> type::uint08
{
    std::uint64_t result;
    result = session_passwd * append_no;
    result = (((result % 10000) / 1000) * 10) + ((result % 1000) / 100);
    return result;
}
