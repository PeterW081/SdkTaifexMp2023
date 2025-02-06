#pragma once
#include "boost0/asio/EzV4_TcpSocketerSync_V.h"
#include "boost0/asio/EzV4_TcpSocketerSyncBoostAsio.h"
#

namespace xplum_sdkit::taifex_msg_proto
{
namespace enumerate
{
using ext::boost_asio0::EnumTcpEndpointSide;
}
}
namespace xplum_sdkit::taifex_msg_proto::network
{
class EzV4_MsgSocketer_Sync;
}

/// EzV4_MsgSocketer_Sync
class                                        //
    xplum_sdkit::taifex_msg_proto::network:: //
    EzV4_MsgSocketer_Sync final : public ext::boost_asio0::EzV4_TcpSocketerSync_V
{
  protected:
    virtual auto fv_hook_log_0_action_post(ext::boost_asio0::EnumTcpSocketAction, std::span<std::byte>) -> void override; // tcp_action, span,

  public:
    explicit EzV4_MsgSocketer_Sync(enumerate::EnumTcpEndpointSide, std::string_view, std::string_view); // side, host, port,

  protected:
    using Underlying_IMPL = ext::boost_asio0::EzV4_TcpSocketerSyncBoostAsio::UnderlyingBoostAsio;
    static auto FX_tcp_action_0_write_msg(Underlying_V &, std::span<std::byte>, std::optional<std::chrono::seconds> = std::nullopt) -> std::size_t;
    static auto FX_tcp_action_0_reade_msg(Underlying_V &, std::span<std::byte>, std::optional<std::chrono::seconds> = std::nullopt) -> std::size_t;
};
