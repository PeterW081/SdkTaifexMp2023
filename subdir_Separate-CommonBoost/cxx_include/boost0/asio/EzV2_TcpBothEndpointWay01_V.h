#pragma once
#include <span>
#include "boost0/asio/EzV2_TcpBothEndpoint_A.h"

namespace ext::boost_asio0
{
class EzV2_TcpBothEndpointWay01_V;
}

class                           //
    ext::boost_asio0 ::         //
    EzV2_TcpBothEndpointWay01_V //
    : virtual protected EzV2_TcpBothEndpoint_A
{
public:
  virtual auto fv_start (std::optional<std::chrono::seconds> = std::nullopt) -> bool = 0;
  virtual auto fv_close (std::optional<std::chrono::seconds> = std::nullopt) -> bool = 0;
  virtual auto fv_write (std::span<std::byte>, std::optional<std::chrono::seconds> = std::nullopt) -> std::size_t = 0;
  virtual auto fv_reade (std::span<std::byte>, std::optional<std::chrono::seconds> = std::nullopt) -> std::size_t = 0;

public:
  auto write_str (std::string &, std::optional<std::chrono::seconds> = std::nullopt) -> std::size_t;
  auto reade_str (std::string &, std::optional<std::chrono::seconds> = std::nullopt) -> std::size_t;
};
