#pragma once
#include "boost0/asio/EzV3_TcpSocketerSyncBy_BoostAsio.h"
#

namespace xplum_sdkit::taifex_msg_proto::network
{
using ext::boost_asio0::EumeTcpEndpointSide;
class EzV3_TaifexMpSocketer_Sync;
}

class                                        //
    xplum_sdkit::taifex_msg_proto::network:: //
    EzV3_TaifexMpSocketer_Sync final : public ext::boost_asio0::EzV3_TcpSocketerSyncBy_BoostAsio
{
  public:
    explicit EzV3_TaifexMpSocketer_Sync(ext::boost_asio0::EumeTcpEndpointSide, std::string_view, std::string_view); // side, host, port,

  protected:
    virtual auto fv_tcp_action(ext::boost_asio0::EnumTcpSocketAction tcp_action, std::span<std::byte> span, std::optional<std::chrono::seconds> timeout) -> std::size_t override;
    virtual auto fv_tcp_action_0_post_log(ext::boost_asio0::EnumTcpSocketAction tcp_action, std::span<std::byte> span) -> void override;
    auto fx_tcp_action_0_reade_msg(std::span<std::byte>, std::optional<std::chrono::seconds> = std::nullopt) -> std::size_t;
    auto fx_tcp_action_0_write_msg(std::span<std::byte>, std::optional<std::chrono::seconds> = std::nullopt) -> std::size_t;
};
