#include <gtest/gtest.h>
#pragma

#include "xplum_sdkit/taifex_msg_proto/fsm/fsm_msg_transfer_flow.h"

namespace nscxx
{
using namespace xplum_sdkit::taifex_msg_proto;
static const auto G_PATTERN_UNITY_TCP_SESSION = kitbag::UnityTcpSession{
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
namespace nscxx::thread_main
{
static auto MAIN_SERFER() -> void;
static auto MAIN_CLIENT() -> void;
template <typename Fsm>
static auto FX_COMMON_FRAGMENT01_FSM(Fsm &) -> void;
}

TEST(Example01_MsgLxx, Example01_03MsgLxxFsmBothEndpoint)
{
    auto arr_thread = std::vector<std::thread>();
    arr_thread.emplace_back(nscxx::thread_main::MAIN_SERFER);
    arr_thread.emplace_back(nscxx::thread_main::MAIN_CLIENT);

    for (auto &var_thread : arr_thread)
    {
        var_thread.join();
    }
}

/// nscxx
auto                     //
    nscxx::thread_main:: //
    MAIN_SERFER() -> void
{
    auto unity = std::make_shared<nscxx::kitbag::UnityTcpSession>(nscxx::G_PATTERN_UNITY_TCP_SESSION);
    auto unity_re_server = std::make_shared<nscxx::kitbag::UnityTcpSessionPluginReServer_MOCK>();
    auto fsm = nscxx::fsm::usage::FsmMsgTransferFlowServer(unity, unity_re_server);
    FX_COMMON_FRAGMENT01_FSM(fsm);
}
auto                     //
    nscxx::thread_main:: //
    MAIN_CLIENT() -> void
{
    auto unity = std::make_shared<nscxx::kitbag::UnityTcpSession>(nscxx::G_PATTERN_UNITY_TCP_SESSION);
    auto counter_msg_seq = std::make_shared<nscxx::kitbag::CounterMsgSeqNumSimple>();
    unity->m_counter_msg_seq = counter_msg_seq;
    unity->m_request_start_seq = counter_msg_seq->peek().value_or(0);
    auto fsm = nscxx::fsm::usage::FsmMsgTransferFlowClient(unity);
    FX_COMMON_FRAGMENT01_FSM(fsm);
}
template <typename Fsm>
auto                     //
    nscxx::thread_main:: //
    FX_COMMON_FRAGMENT01_FSM(Fsm &fsm) -> void
{
    using FsmEvent = nscxx::fsm_msg_transfer_flow::element::FsmEvent;
    static_assert(std::is_same_v<FsmEvent, typename Fsm::Event>);

    fsm.start();
    try
    {
        fsm.process_event(FsmEvent::CallTransferReady());
        fsm.process_event(FsmEvent::StartFsm_MsgTransferFlow_Transfer_L10());
        {
            fsm.process_event(FsmEvent::CallTransfer_L10_FromClient());
            fsm.process_event(FsmEvent::CallTransfer_L10_FromServer());
        }
        fsm.process_event(FsmEvent::CloseFsm_MsgTransferFlow_Transfer_L10());
        fsm.process_event(FsmEvent::CallTransfer_L20());
        fsm.process_event(FsmEvent::CallTransfer_L30());
        fsm.process_event(FsmEvent::CallTransfer_L40());
        fsm.process_event(FsmEvent::StartFsm_MsgTransferFlow_Transfer_L41_L42_L50());
        {
            fsm.process_event(FsmEvent::CallTransfer_OR_L41_L50());
            for (; fsm.fx_is_hold_L41(); fsm.process_event(FsmEvent::CallTransfer_OR_L41_L50()))
            {
                fsm.process_event(FsmEvent::GotoState_DoneTransfer_L41());
                fsm.process_event(FsmEvent::CallTransfer_L42());
            }
            fsm.process_event(FsmEvent::GotoState_DoneTransfer_L50());
        }
        fsm.process_event(FsmEvent::CloseFsm_MsgTransferFlow_Transfer_L41_L42_L50());
        fsm.process_event(FsmEvent::CallTransfer_L60());
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
