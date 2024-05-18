#pragma once
#include <span>
#include "boost0/asio/EzTcpClient_A.h"

namespace ext::boost_asio0 {
class EzTcpClientWay01_V;
}

class                   //
    ext::boost_asio0 :: //
    EzTcpClientWay01_V  //
    : protected EzTcpClient_A {
public:
  virtual auto write(std::span<std::byte>, std::optional<std::chrono::seconds> = std::nullopt) -> std::size_t = 0;
  virtual auto reade(std::span<std::byte>, std::optional<std::chrono::seconds> = std::nullopt) -> std::size_t = 0;

public:
  auto write_str(std::string &, std::optional<std::chrono::seconds> = std::nullopt) -> std::size_t;
  auto reade_str(std::string &, std::optional<std::chrono::seconds> = std::nullopt) -> std::size_t;

protected:
  explicit EzTcpClientWay01_V(std::string_view, std::string_view); // host, port,
};
