#pragma once
#include <cstdint>

namespace ext::boost_asio0
{
enum class EumeTcpEndpointSide : std::uint8_t;
enum class EnumTcpSocketAction : std::uint8_t;
}

enum class             //
    ext::boost_asio0:: //
    EumeTcpEndpointSide : std::uint8_t
{
    NULL0 = 0,
    SERVER,
    CLIENT,
};

enum class             //
    ext::boost_asio0:: //
    EnumTcpSocketAction : std::uint8_t
{
    NULL0 = 0,
    READE,
    WRITE,
};
