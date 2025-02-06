#pragma once
#include <cstdint>

namespace ext::boost_asio0
{
enum class EnumTcpEndpointSide : std::uint8_t;
enum class EnumTcpSocketAction : std::uint8_t;
enum class EnumTcpTransferDirection : std::uint8_t;
}

enum class             //
    ext::boost_asio0:: //
    EnumTcpEndpointSide : std::uint8_t
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
    WRITE_PREP,
    WRITE,
    READE,
    READE_POST,
};

enum class             //
    ext::boost_asio0:: //
    EnumTcpTransferDirection : std::uint8_t
{
    NULL0 = 0,
    SERVER_TO_CLIENT,
    CLIENT_TO_SERVER,
};
