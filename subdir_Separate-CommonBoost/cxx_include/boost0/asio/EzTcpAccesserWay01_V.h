#pragma once
#include <span>
#include "boost0/asio/EzTcpAccesser_A.h"

namespace ext::boost_asio0 {
class EzTcpAccesserWay01_V;
}

class                    //
    ext::boost_asio0 ::  //
    EzTcpAccesserWay01_V //
    : protected EzTcpAccesser_A {
public:
  virtual auto write(std::span<std::byte>) -> void = 0;
  virtual auto reade(std::span<std::byte>) -> void = 0;

public:
  auto write_str(std::string &) -> void;
  auto reade_str(std::string &) -> void;

protected:
  explicit EzTcpAccesserWay01_V(std::string_view, std::string_view); // host, port,
};
