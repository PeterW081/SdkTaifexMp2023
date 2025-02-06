#include <gtest/gtest.h>
#pragma
#include "xplum_model/taifex_msg_proto/network_osi_L05/constant_tcp.h"
#include "xplum_sdkit/taifex_msg_proto/network_osi_L05/partition_msg_session/msg_util_session_context.h"
#include "xplum_sdkit/taifex_msg_proto/network_osi_L05/partition_msg_session/MsgSocketer_Sync.h"
#include "xplum_sdkit/taifex_msg_proto/network_osi_L05/partition_msg_session_fsm/MkV3_MsgSessionLayerALL_FsmSchema.h"
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

TEST(ExampleA1_MsgSession, Test03_WithFsm)
{
#if (true)
    GTEST_SKIP();
#endif

    ///
    using FsmEvent = nscxx::fsm::MkV3_MsgSessionLayerALL_FsmSchema::FsmEvent;
    using FsmState = nscxx::fsm::MkV3_MsgSessionLayerALL_FsmSchema::FsmState;
    constexpr auto stc_side = ext::boost_asio0::EnumTcpEndpointSide::CLIENT;

    ///
    auto buffer = std::array<std::byte, 1024>();
    // X tcp
    auto tcp_host = nscxx::G_test_connection_info.m_server_host;
    auto tcp_port = nscxx::G_test_connection_info.m_server_port;
    auto tcp_timeout = std::chrono::seconds();
    // X fsm, msg_processor,
    auto msg_sesion_context = std::make_shared<nscxx::util::MsgSessionContext>();
    auto msg_processor = std::make_shared<nscxx::util::MsgSessionMsgProcessor>(stc_side, msg_sesion_context, nullptr);
    msg_sesion_context->fx_extract(nscxx::G_test_connection_info);

    ///
    auto tcp_socket = nscxx::network::EzV4_MsgSocketer_Sync(stc_side, tcp_host, tcp_port);
    auto fsm = nscxx::fsm::MkV3_MsgSessionLayerALL_FsmSchema::FsmBack();
    // X
    tcp_socket.fv_start_sync(std::nullopt);
    fsm.fx_init(msg_processor);
    fsm.start();

    /// MsgLayerLxx
    tcp_timeout = std::chrono::seconds(nscxx::tcp_parament::G_lxx_layer_timeout_s);
    // X L10 - ClientToServer
    {
        fsm.process_event(FsmEvent::S01_MsgL10_BEGING_ClientToServer(buffer));
        tcp_socket.fv_write_sync(buffer, tcp_timeout);
        fsm.process_event(FsmEvent::S02_MsgL10_ENDxxx_ClientToServer(buffer));
        fsm.process_event(FsmEvent::Sxx_MsgLxx_MsgSeq_NEXT());
    }
    // X L10 - ServerToClient
    {
        fsm.process_event(FsmEvent::S03_MsgL10_BEGING_ServerToClient(buffer));
        tcp_socket.fv_reade_sync(buffer, tcp_timeout);
        fsm.process_event(FsmEvent::S04_MsgL10_ENDxxx_ServerToClient(buffer));
        fsm.process_event(FsmEvent::Sxx_MsgLxx_MsgSeq_NEXT());
    }
    // X L20
    {
        fsm.process_event(FsmEvent::S05_MsgL20_BEGING(buffer));
        tcp_socket.fv_write_sync(buffer, tcp_timeout);
        fsm.process_event(FsmEvent::S06_MsgL20_ENDxxx(buffer));
        fsm.process_event(FsmEvent::Sxx_MsgLxx_MsgSeq_NEXT());
    }
    // X L30
    {
        fsm.process_event(FsmEvent::S07_MsgL30_BEGING(buffer));
        tcp_socket.fv_reade_sync(buffer, tcp_timeout);
        fsm.process_event(FsmEvent::S08_MsgL30_ENDxxx(buffer));
        fsm.process_event(FsmEvent::Sxx_MsgLxx_MsgSeq_NEXT());
    }
    // X L40
    {
        fsm.process_event(FsmEvent::S09_MsgL40_BEGING(buffer));
        tcp_socket.fv_write_sync(buffer, tcp_timeout);
        fsm.process_event(FsmEvent::S10_MsgL40_ENDxxx(buffer));
        fsm.process_event(FsmEvent::Sxx_MsgLxx_MsgSeq_NEXT());
    }
    // X L41, L42, L50,
    {
        while (true)
        {
            // X L41, L50,
            fsm.process_event(FsmEvent::S11_MsgL41_BEGING(buffer));
            fsm.process_event(FsmEvent::S15_MsgL50_BEGING(buffer));
            tcp_socket.fv_reade_sync(buffer, tcp_timeout);
            fsm.process_event(FsmEvent::S12_MsgL41_ENDxxx(buffer));
            fsm.process_event(FsmEvent::S16_MsgL50_ENDxxx(buffer));
            fsm.process_event(FsmEvent::Sxx_MsgLxx_MsgSeq_NEXT());
            if (not fsm.fx_assert_current_state<FsmState::MsgLayerLxx, FsmState::MsgL42_WILLx>())
            {
                break;
            }
            // X L42,
            fsm.process_event(FsmEvent::S13_MsgL42_BEGING(buffer));
            tcp_socket.fv_write_sync(buffer, tcp_timeout);
            fsm.process_event(FsmEvent::S14_MsgL42_ENDxxx(buffer));
            fsm.process_event(FsmEvent::Sxx_MsgLxx_MsgSeq_NEXT());
        }
    }
    // X L60
    {
        fsm.process_event(FsmEvent::S17_MsgL60_BEGING(buffer));
        tcp_socket.fv_write_sync(buffer, tcp_timeout);
        fsm.process_event(FsmEvent::S18_MsgL60_ENDxxx(buffer));
        fsm.process_event(FsmEvent::Sxx_MsgLxx_MsgSeq_NEXT());
        fsm.process_event(FsmEvent::Sxx_MsgLayer_NEXT());
    }

    /// MsgLayerRxx - TODO...
    tcp_timeout = std::chrono::seconds(nscxx::tcp_parament::G_rxx_layer_timeout_s);
}
