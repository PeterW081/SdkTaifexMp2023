#include "xplum_sdkit/taifex_msg_proto/network/EzTcpClientMsg_Sync.h"

#pragma
#include <iostream>
#include "boost/algorithm/hex.hpp"
#include "xplum_model/taifex_msg_proto/static_constant.h"
#include "xplum_sdkit/taifex_msg_proto/static_function_msg.h"

#pragma
namespace nscxx_root = xplum_sdkit::taifex_msg_proto::network;
inline namespace nscxx {
using namespace xplum_model::taifex_msg_proto;
}

// using xplum_sdkit::taifex_msg_proto::network::EzTcpClientMsg_Sync;
//
nscxx_root::EzTcpClientMsg_Sync::EzTcpClientMsg_Sync(std::string_view server_host, std::string_view server_port) : ext::boost_asio0::EzTcpClientWay01SyncSimple(server_host, server_port) {
  dynamic_cast<EzTcpClientWay01SyncSimple *>(this)->DEBUG_cfg.is_log_data_hex_content = false;
}
auto nscxx_root::EzTcpClientMsg_Sync::write_msg(std::span<std::byte> buffer, std::optional<std::chrono::seconds> timeout) -> xplum_model::taifex_msg_proto::type::TypeMsgLength {
  // assert(buffer.size() == ez_view::FX_GET_MSG_LENGTH_IN_ORIGIN_MSG_1CONST(buffer.data()) + mt_sizeof_msg_content::SIZE_OUT_OF_MSG_LENGTH);
  assert(buffer.size() >= mt_sizeof_msg_read_buffer::SIZE_MIN_OF_READ_MSG + ez_view::FX_GET_MSG_LENGTH_IN_ORIGIN_MSG_1CONST(buffer.data()));
  buffer = buffer.subspan(0, (mt_sizeof_msg_read_buffer::SIZE_MIN_OF_READ_MSG + ez_view::FX_GET_MSG_LENGTH_IN_ORIGIN_MSG_1CONST(buffer.data())));
  this->write(buffer, timeout);

  if (this->DEBUG_cfg.is_log_data_hex_content) {
    std::cout << boost::algorithm::hex(std::string(reinterpret_cast<char *>(buffer.data()), buffer.size())) << std::endl;
  }
  return buffer.size();
}
auto nscxx_root::EzTcpClientMsg_Sync::reade_msg(std::span<std::byte> buffer, std::optional<std::chrono::seconds> timeout) -> xplum_model::taifex_msg_proto::type::TypeMsgLength {
  type::TypeMsgLength msg_length;

  assert(buffer.size() >= mt_sizeof_msg_read_buffer::SIZE_MIN_OF_READ_MSG);
  this->reade(buffer.subspan(0, mt_sizeof_msg_read_buffer::SIZE_MIN_OF_READ_MSG), timeout);
  msg_length = ez_view::FX_GET_MSG_LENGTH_IN_ORIGIN_MSG_1CONST(buffer.data());

  assert(buffer.size() >= mt_sizeof_msg_read_buffer::SIZE_MIN_OF_READ_MSG + msg_length);
  this->reade(buffer.subspan(mt_sizeof_msg_read_buffer::SIZE_MIN_OF_READ_MSG, msg_length), std::nullopt);

  if (this->DEBUG_cfg.is_log_data_hex_content) {
    std::cout << boost::algorithm::hex(std::string(reinterpret_cast<char *>(buffer.data()), mt_sizeof_msg_read_buffer::SIZE_MIN_OF_READ_MSG + msg_length)) << std::endl;
  }
  return mt_sizeof_msg_read_buffer::SIZE_MIN_OF_READ_MSG + msg_length;
}
