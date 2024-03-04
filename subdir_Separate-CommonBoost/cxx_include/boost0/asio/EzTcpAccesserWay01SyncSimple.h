#pragma once
#include <span>
#include "boost0/asio/EzTcpAccesserWay01_V.h"

namespace ext::boost_asio0 {
class EzTcpAccesserWay01SyncSimple;
}

class                            //
    ext::boost_asio0 ::          //
    EzTcpAccesserWay01SyncSimple //
    : public EzTcpAccesserWay01_V {
public:
  struct {
    bool is_log_data_hex_content = true;
  } DEBUG_cfg;

public:
  virtual auto write(std::span<std::byte>) -> void final;
  virtual auto reade(std::span<std::byte>) -> void final;

public:
  explicit EzTcpAccesserWay01SyncSimple(std::string_view, std::string_view);
};
