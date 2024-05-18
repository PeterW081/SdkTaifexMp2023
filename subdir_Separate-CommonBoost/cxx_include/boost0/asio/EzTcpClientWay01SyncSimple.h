#pragma once
#include <span>
#include "boost0/asio/EzTcpClientWay01_V.h"

namespace ext::boost_asio0 {
class EzTcpClientWay01SyncSimple;
}

class                          //
    ext::boost_asio0 ::        //
    EzTcpClientWay01SyncSimple //
    : public EzTcpClientWay01_V {
public:
  struct {
    bool is_log_data_hex_content = true;
  } DEBUG_cfg;

public:
  virtual auto write(std::span<std::byte>, std::optional<std::chrono::seconds> = std::nullopt) -> std::size_t final;
  virtual auto reade(std::span<std::byte>, std::optional<std::chrono::seconds> = std::nullopt) -> std::size_t final;

public:
  explicit EzTcpClientWay01SyncSimple(std::string_view, std::string_view);

protected:
  std::mutex m_mutex_sync;
};
