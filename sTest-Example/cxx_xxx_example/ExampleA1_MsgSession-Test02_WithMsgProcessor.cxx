#include <gtest/gtest.h>
#pragma
#include "xplum_model/taifex_msg_proto/network_osi_L05/constant_tcp.h"
#include "xplum_sdkit/taifex_msg_proto/network_osi_L05/partition_msg_session/msg_util_session_context.h"
#include "xplum_sdkit/taifex_msg_proto/network_osi_L05/partition_msg_session/MsgSocketer_Sync.h"
#include "xplum_sdkit/taifex_msg_proto/network_osi_L05/partition_msg_session/MsgSessionMsgProcessor.h"
#

namespace nscxx
{
using namespace xplum_model::taifex_msg_proto;
using namespace xplum_sdkit::taifex_msg_proto;
static auto const G_test_connection_info = util::MsgSessionConnectionInfo{
    .m_server_host = "127.0.0.1",
    .m_server_port = "8080",
    .m_fcm_id = 1087,
    .m_session_id = 2437,
    .m_secrecy =
        {
            .m_fcm_passwd = 3347,
        },
};
}

TEST(ExampleA1_MsgSession, Test02_WithMsgProcessor)
{
#if (true)
    GTEST_SKIP();
#endif

    ///
    using nscxx::enumerate::EnumMsgType;
    constexpr auto stc_side = ext::boost_asio0::EnumTcpEndpointSide::CLIENT;

    ///
    auto buffer = std::array<std::byte, 1024>();
    // X tcp
    auto tcp_host = nscxx::G_test_connection_info.m_server_host;
    auto tcp_port = nscxx::G_test_connection_info.m_server_port;
    auto tcp_timeout = std::chrono::seconds();
    // X msg_processor
    auto msg_sesion_context = std::make_shared<nscxx::util::MsgSessionContext>();
    auto msg_processor = std::make_shared<nscxx::util::MsgSessionMsgProcessor>(stc_side, msg_sesion_context, nullptr);
    msg_sesion_context->fx_extract(nscxx::G_test_connection_info);

    ///
    auto tcp_socket = nscxx::network::EzV4_MsgSocketer_Sync(stc_side, tcp_host, tcp_port);
    tcp_socket.fv_start_sync(std::nullopt);

    ///
    tcp_timeout = std::chrono::seconds(nscxx::tcp_parament::G_lxx_layer_timeout_s);
    // X L10 - ClientToServer
    {
        msg_processor->fx_msg_process_0_write_prep<EnumMsgType::L10>(buffer);
        tcp_socket.fv_write_sync(buffer, tcp_timeout);
    }
    // X L10 - ServerToClient
    {
        tcp_socket.fv_reade_sync(buffer, tcp_timeout);
        msg_processor->fx_msg_process_0_reade_post<EnumMsgType::L10>(buffer);
    }
    // X L20
    {
        msg_processor->fx_msg_process_0_write_prep<EnumMsgType::L20>(buffer);
        tcp_socket.fv_write_sync(buffer, tcp_timeout);
    }
    // X L30
    {
        tcp_socket.fv_reade_sync(buffer, tcp_timeout);
        msg_processor->fx_msg_process_0_reade_post<EnumMsgType::L30>(buffer);
    }
    // X L40
    {
        msg_processor->fx_msg_process_0_write_prep<EnumMsgType::L40>(buffer);
        tcp_socket.fv_write_sync(buffer, tcp_timeout);
    }
    // X L41, L42, L50,
    {
        tcp_socket.fv_reade_sync(buffer, tcp_timeout);
        while (true)
        {
            switch (nscxx::ez_view::FX_get_msg_type_from_msg_data(buffer.data()).enum_value())
            {
            case EnumMsgType::L41:
                msg_processor->fx_msg_process_0_write_prep<EnumMsgType::L42>(buffer);
                tcp_socket.fv_write_sync(buffer, tcp_timeout);
                tcp_socket.fv_reade_sync(buffer, tcp_timeout);
                goto goto_mark_continue;
                break;
            case EnumMsgType::L50:
                goto goto_mark_break;
                break;
            default:
                assert(false);
                break;
            }
        goto_mark_continue:
            continue;
        goto_mark_break:
            break;
        }
        msg_processor->fx_msg_process_0_reade_post<EnumMsgType::L50>(buffer);
    }
    // X L60
    {
        msg_processor->fx_msg_process_0_write_prep<EnumMsgType::L60>(buffer);
        tcp_socket.fv_write_sync(buffer, tcp_timeout);
    }
}
