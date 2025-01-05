#pragma once
#include "boost0/asio/_define_cxx.h"
#include "xplum/ancestor/SocketerSync_V.h"
#include "xplum_sdkit/taifex_msg_proto/kitbag/action_kitbag_tcp_contact.h"
#

namespace xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::ctrl_handle
{
struct FsmCtrlHandleTcpTransfer;
struct FsmCtrlHandleTcpSession;
}

struct                                                                  //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::ctrl_handle:: //
    FsmCtrlHandleTcpTransfer
{
    ext::boost_asio0::EumeTcpEndpointSide m_side;
    std::array<std::byte, 1024> m_tcp_buffer_for_write;
    std::array<std::byte, 1024> m_tcp_buffer_for_reade;
    std::shared_ptr<xplum::ancestor::SocketerSync_V> m_tcp_endpoint; // tcp_server, tcp_client,
};

struct                                                                  //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::ctrl_handle:: //
    FsmCtrlHandleTcpSession
{
    std::shared_ptr<xplum_sdkit::taifex_msg_proto::kitbag::UnityTcpSession> m_unity;
    std::shared_ptr<xplum_sdkit::taifex_msg_proto::kitbag::UnityTcpSessionPluginReServer_MOCK> m_unity_re_server;
    bool m_is_done_transfer_L10_from_server;
    bool m_is_done_transfer_L50;
    bool m_is_hold_L41;
};
