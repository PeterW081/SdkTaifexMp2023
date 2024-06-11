#include "xplum_sdkit/taifex_msg_proto/network/EzV2_TcpBothEndpointMsg_Sync.h"
#pragma

#include <iostream>
#include "boost/algorithm/hex.hpp"
#include "xplum_model/taifex_msg_proto/static_constant.h"
#include "xplum_sdkit/taifex_msg_proto/static_function_msg.h"

namespace nscxx_root = xplum_sdkit::taifex_msg_proto::network; // typename EzV2_TcpBothEndpointMsg_Sync
namespace nscxx {
using namespace xplum_model::taifex_msg_proto;
using message_field::enumerate::MessageType;
static inline auto FX_CASE_TO_STRING(MessageType) -> std::string;
}

/// nscxx
auto        //
    nscxx:: //
    FX_CASE_TO_STRING(MessageType enum_msg_type) -> std::string {
  switch (enum_msg_type) {
    // clang-format off
#define MACRO_XPLUM_SWITCH_CASE(PARAM01_ENUM_MEMBER) case MessageType::PARAM01_ENUM_MEMBER: return #PARAM01_ENUM_MEMBER;
    // clang-format on
    MACRO_XPLUM_SWITCH_CASE(L10)
    MACRO_XPLUM_SWITCH_CASE(L20)
    MACRO_XPLUM_SWITCH_CASE(L30)
    MACRO_XPLUM_SWITCH_CASE(L40)
    MACRO_XPLUM_SWITCH_CASE(L41)
    MACRO_XPLUM_SWITCH_CASE(L42)
    MACRO_XPLUM_SWITCH_CASE(L50)
    MACRO_XPLUM_SWITCH_CASE(L60)
#undef MACRO_XPLUM_SWITCH_CASE
  [[unlikely]] default:
    return "???";
  }
}

/// EzV2_TcpBothEndpointMsg_Sync
/*Constructor*/                    //
nscxx_root::                       //
    EzV2_TcpBothEndpointMsg_Sync:: //
    EzV2_TcpBothEndpointMsg_Sync(ext::boost_asio0::EumeTcpEndpointSide server_side, std::string_view server_host, std::string_view server_port)
    : EzV2_TcpBothEndpointWay01SyncSimple(server_side, server_host, server_port), EzV2_TcpBothEndpoint_A(server_side, server_host, server_port) {
  this->EzV2_TcpBothEndpointWay01SyncSimple::DEBUG_cfg.is_log_data_hex_content = false;
}
auto                               //
    nscxx_root::                   //
    EzV2_TcpBothEndpointMsg_Sync:: //
    start(std::optional<std::chrono::seconds> timeout) -> bool {
  return this->fv_start(timeout);
}
auto                               //
    nscxx_root::                   //
    EzV2_TcpBothEndpointMsg_Sync:: //
    write_msg(std::span<std::byte> buffer, std::optional<std::chrono::seconds> timeout) -> xplum_model::taifex_msg_proto::type::TypeMsgLength {
  assert(buffer.size() >= nscxx::mt_sizeof_msg_read_buffer::SIZE_MIN_OF_READ_MSG + ez_view::FX_GET_MSG_LENGTH_IN_ORIGIN_MSG_1CONST(buffer.data()));
  buffer = buffer.subspan(0, (nscxx::mt_sizeof_msg_read_buffer::SIZE_MIN_OF_READ_MSG + ez_view::FX_GET_MSG_LENGTH_IN_ORIGIN_MSG_1CONST(buffer.data())));
  this->fv_write(buffer, timeout);

  if (this->DEBUG_cfg.is_log_data_hex_content) {
    auto str01 = std::string() + nscxx::FX_CASE_TO_STRING(ez_view::FX_GET_MSG_TYPE_IN_ORIGIN_MSG_1CONST(buffer.data()).enum_value());
    auto str02 = std::string() + boost::algorithm::hex(std::string(reinterpret_cast<char *>(buffer.data()), buffer.size()));
    switch (this->m_side) {
    case decltype(this->m_side)::CLIENT:
      std::printf("[C->#][%s]: %s\n", str01.c_str(), str02.c_str());
      break;
    case decltype(this->m_side)::SERVER:
      std::printf("[#<-S][%s]: %s\n", str01.c_str(), str02.c_str());
      break;
    [[unlikely]] default:
      std::printf("[####][%s]: %s\n", str01.c_str(), str02.c_str());
      break;
    }
  }
  return buffer.size();
}
auto                               //
    nscxx_root::                   //
    EzV2_TcpBothEndpointMsg_Sync:: //
    reade_msg(std::span<std::byte> buffer, std::optional<std::chrono::seconds> timeout) -> xplum_model::taifex_msg_proto::type::TypeMsgLength {
  type::TypeMsgLength msg_length;
  type::TypeMsgLength read_size = 0;

  assert(buffer.size() >= nscxx::mt_sizeof_msg_read_buffer::SIZE_MIN_OF_READ_MSG);
  read_size += this->fv_reade(buffer.subspan(0, nscxx::mt_sizeof_msg_read_buffer::SIZE_MIN_OF_READ_MSG), timeout);
  msg_length = (read_size == 0) ? 0 : static_cast<type::TypeMsgLength>(ez_view::FX_GET_MSG_LENGTH_IN_ORIGIN_MSG_1CONST(buffer.data()));

  assert(buffer.size() >= nscxx::mt_sizeof_msg_read_buffer::SIZE_MIN_OF_READ_MSG + msg_length);
  read_size += this->fv_reade(buffer.subspan(nscxx::mt_sizeof_msg_read_buffer::SIZE_MIN_OF_READ_MSG, msg_length), std::nullopt);
  assert(read_size == 0 || read_size == nscxx::mt_sizeof_msg_read_buffer::SIZE_MIN_OF_READ_MSG + msg_length);

  if (this->DEBUG_cfg.is_log_data_hex_content) {
    auto msg_type = (read_size == 0) ? static_cast<nscxx::MessageType>(0) : ez_view::FX_GET_MSG_TYPE_IN_ORIGIN_MSG_1CONST(buffer.data()).enum_value();
    auto str01 = std::string() + nscxx::FX_CASE_TO_STRING(msg_type);
    auto str02 = std::string() + boost::algorithm::hex(std::string(reinterpret_cast<char *>(buffer.data()), read_size));
    switch (this->m_side) {
    case decltype(this->m_side)::CLIENT:
      std::printf("[C<-#][%s]: %s\n", str01.c_str(), str02.c_str());
      break;
    case decltype(this->m_side)::SERVER:
      std::printf("[#->S][%s]: %s\n", str01.c_str(), str02.c_str());
      break;
    [[unlikely]] default:
      std::printf("[####][%s]: %s\n", str01.c_str(), str02.c_str());
      break;
    }
  }
  return read_size;
}
