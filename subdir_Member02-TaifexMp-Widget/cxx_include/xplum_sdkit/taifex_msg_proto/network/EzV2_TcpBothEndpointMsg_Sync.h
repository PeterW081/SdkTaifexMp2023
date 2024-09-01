#pragma once
#include "boost0/asio/EzV2_TcpBothEndpointWay01SyncSimple.h"
#include "xplum_sdkit/taifex_msg_proto/_define_cxx.h"

namespace xplum_sdkit::taifex_msg_proto::network
{
using ext::boost_asio0::EumeTcpEndpointSide;

class EzV2_TcpBothEndpointMsg_Sync;
using EzV2_TcpClientMsg_Sync = ext::boost_asio0::EzV2_TcpBothEndpointWay01_V2<ext::boost_asio0::EumeTcpEndpointSide::CLIENT, EzV2_TcpBothEndpointMsg_Sync>;
using EzV2_TcpServerMsg_Sync = ext::boost_asio0::EzV2_TcpBothEndpointWay01_V2<ext::boost_asio0::EumeTcpEndpointSide::SERVER, EzV2_TcpBothEndpointMsg_Sync>;
}

class                                        //
    xplum_sdkit::taifex_msg_proto::network:: //
    EzV2_TcpBothEndpointMsg_Sync             //
    : private ext::boost_asio0::EzV2_TcpBothEndpointWay01SyncSimple
{
  public:
    template <ext::boost_asio0::EumeTcpEndpointSide V, typename T>
    friend class ext::boost_asio0::EzV2_TcpBothEndpointWay01_V2;

  public:
    struct
    {
        bool is_log_data_hex_content = true;
    } DEBUG_cfg;

  public:
    explicit EzV2_TcpBothEndpointMsg_Sync(ext::boost_asio0::EumeTcpEndpointSide, std::string_view, std::string_view); // server_side, server_host, server_port
    auto start(std::optional<std::chrono::seconds> = std::nullopt) -> bool;
    auto write_msg(std::span<std::byte>, std::optional<std::chrono::seconds> = std::nullopt) -> type::TypeMsgLength;
    auto reade_msg(std::span<std::byte>, std::optional<std::chrono::seconds> = std::nullopt) -> type::TypeMsgLength;
};
