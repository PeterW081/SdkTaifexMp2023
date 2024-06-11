#pragma once
#include <boost/msm/front/functor_row.hpp>
#include <boost/msm/front/state_machine_def.hpp>

namespace xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::element {
struct FsmState;
struct FsmStateIsSubMachine;
struct FsmEvent;
struct FsmGuard;
struct FsmAction;
}

namespace xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::construction {
struct FsmTransitionTable;
struct FsmFactory;
struct FsmBack;
}

/// fsm_element
///

struct                                                              //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::element:: //
    FsmState {
  struct Head;
  struct Tail;
  struct DoneTransferReady;
  struct DoneTransfer_L10_FromClient;
  struct DoneTransfer_L10_FromServer;
  struct DoneTransfer_L20;
  struct DoneTransfer_L30;
  struct DoneTransfer_L40;
  struct DoneTransfer_L41;
  struct DoneTransfer_L42;
  struct DoneTransfer_L50;
  struct DoneTransfer_L60;
  struct DoneTransfer_OR_L41_L50;
};

struct                                                              //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::element:: //
    FsmStateIsSubMachine {
  using FsmFactory = construction::FsmFactory;
  struct MsgTransferFlow_Transfer_L10;
  struct MsgTransferFlow_Transfer_L41_L42_L50;
};

struct                                                              //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::element:: //
    FsmEvent {
  struct CallTransferReady;
  struct CallTransfer_L10_FromClient;
  struct CallTransfer_L10_FromServer;
  struct CallTransfer_L20;
  struct CallTransfer_L30;
  struct CallTransfer_L40;
  struct CallTransfer_L42;
  struct CallTransfer_L60;
  struct CallTransfer_OR_L41_L50;
  struct GotoState_DoneTransfer_L41;
  struct GotoState_DoneTransfer_L50;
  struct StartFsm_MsgTransferFlow_Transfer_L10;
  struct CloseFsm_MsgTransferFlow_Transfer_L10;
  struct StartFsm_MsgTransferFlow_Transfer_L41_L42_L50;
  struct CloseFsm_MsgTransferFlow_Transfer_L41_L42_L50;
};

struct                                                              //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::element:: //
    FsmGuard {};

struct                                                              //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::element:: //
    FsmAction {
  struct AssertFsmStateOrFsmNoTransition;
  struct DoTransferReady;
  struct DoTransfer_L10_FromClient;
  struct DoTransfer_L10_FromServer;
  struct DoTransfer_L20;
  struct DoTransfer_L30;
  struct DoTransfer_L40;
  struct DoTransfer_L42;
  struct DoTransfer_L60;
  struct DoTransfer_OR_L41_L50;
};

/// fsm_construction
///

struct                                                                   //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::construction:: //
    FsmTransitionTable {
private:
  using FsmState = element::FsmState;
  using FsmStateIsSubMachine = element::FsmStateIsSubMachine;
  using FsmEvent = element::FsmEvent;
  using FsmGuard = element::FsmGuard;
  using FsmAction = element::FsmAction;

public:
  using MsgTransferFlow = boost::mpl::vector<
      // clang-format off
      //##                    FsmStateSource,                                             FsmEvent,                                                FsmStateTarget,                                             FsmAction,
      boost::msm::front::Row< FsmState::Head,                                             FsmEvent::CallTransferReady,                             FsmState::DoneTransferReady,                                FsmAction::DoTransferReady                 >,
      boost::msm::front::Row< FsmState::DoneTransferReady,                                FsmEvent::StartFsm_MsgTransferFlow_Transfer_L10,         FsmStateIsSubMachine::MsgTransferFlow_Transfer_L10,         boost::msm::front::none                    >,
      boost::msm::front::Row< FsmStateIsSubMachine::MsgTransferFlow_Transfer_L10,         FsmEvent::CloseFsm_MsgTransferFlow_Transfer_L10,         FsmState::DoneTransfer_L10_FromServer,                      FsmAction::AssertFsmStateOrFsmNoTransition >,
      boost::msm::front::Row< FsmState::DoneTransfer_L10_FromServer,                      FsmEvent::CallTransfer_L20,                              FsmState::DoneTransfer_L20,                                 FsmAction::DoTransfer_L20                  >,
      boost::msm::front::Row< FsmState::DoneTransfer_L20,                                 FsmEvent::CallTransfer_L30,                              FsmState::DoneTransfer_L30,                                 FsmAction::DoTransfer_L30                  >,
      boost::msm::front::Row< FsmState::DoneTransfer_L30,                                 FsmEvent::CallTransfer_L40,                              FsmState::DoneTransfer_L40,                                 FsmAction::DoTransfer_L40                  >,
      boost::msm::front::Row< FsmState::DoneTransfer_L40,                                 FsmEvent::StartFsm_MsgTransferFlow_Transfer_L41_L42_L50, FsmStateIsSubMachine::MsgTransferFlow_Transfer_L41_L42_L50, boost::msm::front::none                    >,
      boost::msm::front::Row< FsmStateIsSubMachine::MsgTransferFlow_Transfer_L41_L42_L50, FsmEvent::CloseFsm_MsgTransferFlow_Transfer_L41_L42_L50, FsmState::DoneTransfer_L50,                                 FsmAction::AssertFsmStateOrFsmNoTransition >,
      boost::msm::front::Row< FsmState::DoneTransfer_L50,                                 FsmEvent::CallTransfer_L60,                              FsmState::DoneTransfer_L60,                                 FsmAction::DoTransfer_L60                  >
      // clang-format on
      >;
  using MsgTransferFlow_Transfer_L10 = boost::mpl::vector<
      // clang-format off
      //##                    FsmStateSource,                        FsmEvent,                              FsmStateTarget,                        FsmAction,
      boost::msm::front::Row< FsmState::Head,                        FsmEvent::CallTransfer_L10_FromClient, FsmState::DoneTransfer_L10_FromClient, FsmAction::DoTransfer_L10_FromClient >,
      boost::msm::front::Row< FsmState::DoneTransfer_L10_FromClient, FsmEvent::CallTransfer_L10_FromServer, FsmState::DoneTransfer_L10_FromServer, FsmAction::DoTransfer_L10_FromServer >
      // clang-format on
      >;
  using MsgTransferFlow_Transfer_L41_L42_L50 = boost::mpl::vector<
      // clang-format off
      //##                    FsmStateSource,                    FsmEvent,                              FsmStateTarget,                        FsmAction,
      boost::msm::front::Row< FsmState::Head,                    FsmEvent::CallTransfer_OR_L41_L50,     FsmState::DoneTransfer_OR_L41_L50, FsmAction::DoTransfer_OR_L41_L50 >,
      boost::msm::front::Row< FsmState::DoneTransfer_OR_L41_L50, FsmEvent::GotoState_DoneTransfer_L41,  FsmState::DoneTransfer_L41,        boost::msm::front::none          >,
      boost::msm::front::Row< FsmState::DoneTransfer_L41,        FsmEvent::CallTransfer_L42,            FsmState::DoneTransfer_L42,        FsmAction::DoTransfer_L42        >,
      boost::msm::front::Row< FsmState::DoneTransfer_L42,        FsmEvent::CallTransfer_OR_L41_L50,     FsmState::DoneTransfer_OR_L41_L50, FsmAction::DoTransfer_OR_L41_L50 >,
      boost::msm::front::Row< FsmState::DoneTransfer_OR_L41_L50, FsmEvent::GotoState_DoneTransfer_L50,  FsmState::DoneTransfer_L50,        boost::msm::front::none          >
      // clang-format on
      >;
};

struct                                                                   //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::construction:: //
    FsmFactory {
private:
  template <typename FSM_STATE_TRANSITION_TABLE, typename FSM_STATE_TRANSITION_TABLE_HEAD> struct FsmFactory0;

public:
  using MsgTransferFlow = FsmFactory0<FsmTransitionTable::MsgTransferFlow, element::FsmState::Head>;
  using MsgTransferFlow_Transfer_L10 = FsmFactory0<FsmTransitionTable::MsgTransferFlow_Transfer_L10, element::FsmState::Head>;
  using MsgTransferFlow_Transfer_L41_L42_L50 = FsmFactory0<FsmTransitionTable::MsgTransferFlow_Transfer_L41_L42_L50, element::FsmState::Head>;
};

struct                                                                   //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::construction:: //
    FsmBack {
  struct MsgTransferFlowClient;
  struct MsgTransferFlowServer;
};
