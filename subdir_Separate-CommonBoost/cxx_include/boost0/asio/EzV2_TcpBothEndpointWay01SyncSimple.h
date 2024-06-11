#pragma once
#include "boost0/asio/EzV2_TcpBothEndpointWay01_V.h"
#include "boost0/asio/EzV2_TcpBothEndpointWay01_V2.h"

namespace ext::boost_asio0 {
class EzV2_TcpBothEndpointWay01SyncSimple;
using EzV2_TcpClientWay01SyncSimple = EzV2_TcpBothEndpointWay01_V2<EumeTcpEndpointSide::CLIENT, EzV2_TcpBothEndpointWay01SyncSimple>;
using EzV2_TcpServerWay01SyncSimple = EzV2_TcpBothEndpointWay01_V2<EumeTcpEndpointSide::SERVER, EzV2_TcpBothEndpointWay01SyncSimple>;
}

class                                   //
    ext::boost_asio0 ::                 //
    EzV2_TcpBothEndpointWay01SyncSimple //
    : public EzV2_TcpBothEndpointWay01_V {
public:
  struct {
    bool is_log_data_hex_content = true;
  } DEBUG_cfg;
  explicit EzV2_TcpBothEndpointWay01SyncSimple() = delete;

public:
  virtual auto fv_start(std::optional<std::chrono::seconds> = std::nullopt) -> bool override final;
  virtual auto fv_close [[deprecated("TODO")]] (std::optional<std::chrono::seconds> = std::nullopt) -> bool override final;
  virtual auto fv_write(std::span<std::byte>, std::optional<std::chrono::seconds> = std::nullopt) -> std::size_t override final;
  virtual auto fv_reade(std::span<std::byte>, std::optional<std::chrono::seconds> = std::nullopt) -> std::size_t override final;

protected:
  bool m_is_done_start;
  std::mutex m_mutex_sync;
  explicit EzV2_TcpBothEndpointWay01SyncSimple(EumeTcpEndpointSide, std::string_view, std::string_view);
};
