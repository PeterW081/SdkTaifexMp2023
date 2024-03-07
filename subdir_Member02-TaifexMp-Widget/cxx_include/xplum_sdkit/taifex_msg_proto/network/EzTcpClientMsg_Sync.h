#pragma once
#include "boost0/asio/EzTcpClientWay01SyncSimple.h"
#include "xplum_sdkit/taifex_msg_proto/_define_cxx.h"

namespace xplum_sdkit::taifex_msg_proto::network {
class EzTcpClientMsg_Sync;
}

class xplum_sdkit::taifex_msg_proto::network::EzTcpClientMsg_Sync : private ext::boost_asio0::EzTcpClientWay01SyncSimple {
public:
  struct {
    bool is_log_data_hex_content = true;
  } DEBUG_cfg;

public:
  explicit EzTcpClientMsg_Sync(std::string_view, std::string_view); // server_host, server_port
  auto write_msg(std::span<std::byte>, std::optional<std::chrono::seconds> = std::nullopt) -> type::TypeMsgLength;
  auto reade_msg(std::span<std::byte>, std::optional<std::chrono::seconds> = std::nullopt) -> type::TypeMsgLength;
};
