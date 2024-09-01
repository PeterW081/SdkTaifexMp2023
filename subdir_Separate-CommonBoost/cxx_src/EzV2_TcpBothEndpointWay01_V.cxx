#include "boost0/asio/EzV2_TcpBothEndpointWay01_V.h"
#pragma

namespace nscxx_root = ext::boost_asio0;

/// EzV2_TcpBothEndpointWay01_V
auto                              //
    nscxx_root::                  //
    EzV2_TcpBothEndpointWay01_V:: //
    write_str(std::string &data, std::optional<std::chrono::seconds> timeout) -> std::size_t
{
    return this->fv_write(std::span(reinterpret_cast<std::byte *>(data.data()), data.size()), timeout);
}
auto                              //
    nscxx_root::                  //
    EzV2_TcpBothEndpointWay01_V:: //
    reade_str(std::string &data, std::optional<std::chrono::seconds> timeout) -> std::size_t
{
    return this->fv_reade(std::span(reinterpret_cast<std::byte *>(data.data()), data.size()), timeout);
}
