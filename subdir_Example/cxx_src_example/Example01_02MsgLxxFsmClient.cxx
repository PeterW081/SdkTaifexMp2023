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

TEST (Example01_MsgLxx, Example01_02MsgLxxFsmClient)
{
#if (true)
  return;
  GTEST_SKIP ();
#endif

  using FsmMsgTransferFlowClient = nscxx::fsm::usage::FsmMsgTransferFlowClient;
  using FsmEvent = nscxx::fsm::usage::FsmMsgTransferFlowClient::Event;

  auto unity = std::make_shared<nscxx::kitbag::UnityTcpSession> (nscxx::G_PATTERN_UNITY_TCP_SESSION);
  auto counter_msg_seq = std::make_shared<nscxx::kitbag::CounterMsgSeqNumSimple> ();
  unity->m_counter_msg_seq = counter_msg_seq;
  unity->m_request_start_seq = counter_msg_seq->peek ().value_or (0);

  auto fsm = FsmMsgTransferFlowClient (unity);
  fsm.start ();
  try
    {
      fsm.process_event (FsmEvent::CallTransferReady ());
      fsm.process_event (FsmEvent::StartFsm_MsgTransferFlow_Transfer_L10 ());
      {
        fsm.process_event (FsmEvent::CallTransfer_L10_FromClient ());
        fsm.process_event (FsmEvent::CallTransfer_L10_FromServer ());
      }
      fsm.process_event (FsmEvent::CloseFsm_MsgTransferFlow_Transfer_L10 ());
      fsm.process_event (FsmEvent::CallTransfer_L20 ());
      fsm.process_event (FsmEvent::CallTransfer_L30 ());
      fsm.process_event (FsmEvent::CallTransfer_L40 ());
      fsm.process_event (FsmEvent::StartFsm_MsgTransferFlow_Transfer_L41_L42_L50 ());
      {
        fsm.process_event (FsmEvent::CallTransfer_OR_L41_L50 ());
        for (; fsm.fx_is_hold_L41 (); fsm.process_event (FsmEvent::CallTransfer_OR_L41_L50 ()))
          {
            fsm.process_event (FsmEvent::GotoState_DoneTransfer_L41 ());
            fsm.process_event (FsmEvent::CallTransfer_L42 ());
          }
        fsm.process_event (FsmEvent::GotoState_DoneTransfer_L50 ());
      }
      fsm.process_event (FsmEvent::CloseFsm_MsgTransferFlow_Transfer_L41_L42_L50 ());
      fsm.process_event (FsmEvent::CallTransfer_L60 ());
    }
  catch (...)
    {
      std::rethrow_exception (std::current_exception ());
    }
}
