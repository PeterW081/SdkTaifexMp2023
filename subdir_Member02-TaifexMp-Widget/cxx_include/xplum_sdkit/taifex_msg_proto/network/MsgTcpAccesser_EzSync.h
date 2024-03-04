#pragma once
#include "boost0/asio/EzTcpAccesserWay01SyncSimple.h"
#include "xplum_sdkit/taifex_msg_proto/_define_cxx.h"

namespace xplum_sdkit::taifex_msg_proto::network {
class MsgTcpAccesser_EzSync;
}

class xplum_sdkit::taifex_msg_proto::network::MsgTcpAccesser_EzSync : private ext::boost_asio0::EzTcpAccesserWay01SyncSimple {
public:
  struct {
    bool is_log_data_hex_content = true;
  } DEBUG_cfg;

public:
  explicit MsgTcpAccesser_EzSync(std::string_view, std::string_view); // server_host, server_port
  auto write_msg(std::span<std::byte>) -> type::TypeMsgLength;
  auto reade_msg(std::span<std::byte>) -> type::TypeMsgLength;
};
