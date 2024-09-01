#pragma once
#include "./fsm_msg_transfer_flow.h"
#pragma

#include <boost/msm/front/functor_row.hpp>
#include <boost/msm/front/state_machine_def.hpp>
#include <boost/msm/back/state_machine.hpp>
#include "boost0/msm/FsmElementWrapWithCtrlHandle_A.h"
#include "xplum_sdkit/taifex_msg_proto/fsm/fsm_0ctrl_handle.h"

namespace xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::_ns_ignore
{
struct FsmElementWrapImpl;
}

struct                                                                 //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::_ns_ignore:: //
    FsmElementWrapImpl
{
    struct FsmActionWithCtrlHandle;
    struct FsmGuardWithCtrlHandle;

  private:
    struct CtrlHandle;
    using FsmElementWrap = boost0::msm::FsmElementWrapWithCtrlHandle_A<CtrlHandle>;
    using FsmGuard = FsmElementWrap::FsmGuard;

  public:
    template <typename CRTP_SELF, typename FSM_STATE_TRANSITION_TABLE, typename FSM_STATE_TRANSITION_TABLE_HEAD>
    using FsmFront = FsmElementWrap::FsmFront<CRTP_SELF, FSM_STATE_TRANSITION_TABLE, FSM_STATE_TRANSITION_TABLE_HEAD>;
    using FsmState = FsmElementWrap::FsmState;
    using FsmEvent = FsmElementWrap::FsmEvent;
    using FsmAction = FsmElementWrap::FsmAction;
};

struct                                                                 //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::_ns_ignore:: //
    FsmElementWrapImpl::CtrlHandle : xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::ctrl_handle::FsmCtrlHandleTcpTransfer,
                                     xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::ctrl_handle::FsmCtrlHandleTcpSession
{
};

/// FsmState
///

struct                                                              //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::element:: //
    FsmState::Head                                                  //
    : _ns_ignore::FsmElementWrapImpl::FsmState
{
};

struct                                                              //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::element:: //
    FsmState::Tail                                                  //
    : _ns_ignore::FsmElementWrapImpl::FsmState
{
};

struct                                                              //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::element:: //
    FsmState::DoneTransferReady                                     //
    : _ns_ignore::FsmElementWrapImpl::FsmState
{
};

struct                                                              //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::element:: //
    FsmState::DoneTransfer_L10_FromClient                           //
    : _ns_ignore::FsmElementWrapImpl::FsmState
{
};

struct                                                              //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::element:: //
    FsmState::DoneTransfer_L10_FromServer                           //
    : _ns_ignore::FsmElementWrapImpl::FsmState
{
};

struct                                                              //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::element:: //
    FsmState::DoneTransfer_L20                                      //
    : _ns_ignore::FsmElementWrapImpl::FsmState
{
};

struct                                                              //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::element:: //
    FsmState::DoneTransfer_L30                                      //
    : _ns_ignore::FsmElementWrapImpl::FsmState
{
};

struct                                                              //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::element:: //
    FsmState::DoneTransfer_L40                                      //
    : _ns_ignore::FsmElementWrapImpl::FsmState
{
};

struct                                                              //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::element:: //
    FsmState::DoneTransfer_L41                                      //
    : _ns_ignore::FsmElementWrapImpl::FsmState
{
};

struct                                                              //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::element:: //
    FsmState::DoneTransfer_L42                                      //
    : _ns_ignore::FsmElementWrapImpl::FsmState
{
};

struct                                                              //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::element:: //
    FsmState::DoneTransfer_L50                                      //
    : _ns_ignore::FsmElementWrapImpl::FsmState
{
};

struct                                                              //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::element:: //
    FsmState::DoneTransfer_L60                                      //
    : _ns_ignore::FsmElementWrapImpl::FsmState
{
};

struct                                                              //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::element:: //
    FsmState::DoneTransfer_OR_L41_L50                               //
    : _ns_ignore::FsmElementWrapImpl::FsmState
{
};

/// FsmEvent
///

struct                                                              //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::element:: //
    FsmEvent::CallTransferReady                                     //
    : _ns_ignore::FsmElementWrapImpl::FsmEvent
{
};

struct                                                              //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::element:: //
    FsmEvent::CallTransfer_L10_FromClient                           //
    : _ns_ignore::FsmElementWrapImpl::FsmEvent
{
};

struct                                                              //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::element:: //
    FsmEvent::CallTransfer_L10_FromServer                           //
    : _ns_ignore::FsmElementWrapImpl::FsmEvent
{
};

struct                                                              //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::element:: //
    FsmEvent::CallTransfer_L20                                      //
    : _ns_ignore::FsmElementWrapImpl::FsmEvent
{
};

struct                                                              //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::element:: //
    FsmEvent::CallTransfer_L30                                      //
    : _ns_ignore::FsmElementWrapImpl::FsmEvent
{
};

struct                                                              //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::element:: //
    FsmEvent::CallTransfer_L40                                      //
    : _ns_ignore::FsmElementWrapImpl::FsmEvent
{
};

struct                                                              //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::element:: //
    FsmEvent::CallTransfer_L42                                      //
    : _ns_ignore::FsmElementWrapImpl::FsmEvent
{
};

struct                                                              //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::element:: //
    FsmEvent::CallTransfer_L60                                      //
    : _ns_ignore::FsmElementWrapImpl::FsmEvent
{
};

struct                                                              //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::element:: //
    FsmEvent::GotoState_DoneTransfer_L41                            //
    : _ns_ignore::FsmElementWrapImpl::FsmEvent
{
};

struct                                                              //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::element:: //
    FsmEvent::GotoState_DoneTransfer_L50                            //
    : _ns_ignore::FsmElementWrapImpl::FsmEvent
{
};

struct                                                              //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::element:: //
    FsmEvent::CallTransfer_OR_L41_L50                               //
    : _ns_ignore::FsmElementWrapImpl::FsmEvent
{
};

struct                                                              //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::element:: //
    FsmEvent::StartFsm_MsgTransferFlow_Transfer_L10                 //
    : _ns_ignore::FsmElementWrapImpl::FsmEvent
{
};

struct                                                              //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::element:: //
    FsmEvent::CloseFsm_MsgTransferFlow_Transfer_L10                 //
    : _ns_ignore::FsmElementWrapImpl::FsmEvent
{
};

struct                                                              //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::element:: //
    FsmEvent::StartFsm_MsgTransferFlow_Transfer_L41_L42_L50         //
    : _ns_ignore::FsmElementWrapImpl::FsmEvent
{
};

struct                                                              //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::element:: //
    FsmEvent::CloseFsm_MsgTransferFlow_Transfer_L41_L42_L50         //
    : _ns_ignore::FsmElementWrapImpl::FsmEvent
{
};

/// FsmGuard
///

struct                                                                 //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::_ns_ignore:: //
    FsmElementWrapImpl::FsmGuardWithCtrlHandle                         //
    : _ns_ignore::FsmElementWrapImpl::FsmGuard
{
    template <typename FSM, typename EVENT, typename SRCE, typename TAGT>
    auto operator()(const EVENT &, FSM &, SRCE &, TAGT &) -> bool;

  protected:
    using CtrlHandle = CtrlHandle;
    virtual auto fx_operator(CtrlHandle &) -> bool = 0;
};

/// FsmAction
///

struct                                                                 //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::_ns_ignore:: //
    FsmElementWrapImpl::FsmActionWithCtrlHandle                        //
    : _ns_ignore::FsmElementWrapImpl::FsmAction
{
    template <typename FSM, typename EVENT, typename SRCE, typename TAGT>
    auto operator()(const EVENT &, FSM &, SRCE &, TAGT &) -> void;

  protected:
    using CtrlHandle = CtrlHandle;
    virtual auto fx_operator_tcp_client(CtrlHandle &) -> void = 0;
    virtual auto fx_operator_tcp_server(CtrlHandle &) -> void = 0;
};

struct                                                              //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::element:: //
    FsmAction::AssertFsmStateOrFsmNoTransition                      //
    : _ns_ignore::FsmElementWrapImpl::FsmAction
{
    template <typename FSM, typename EVENT, typename SRCE, typename TAGT>
    auto operator()(const EVENT &, FSM &, SRCE &, TAGT &) -> void;
};

struct                                                              //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::element:: //
    FsmAction::DoTransferReady                                      //
    : _ns_ignore::FsmElementWrapImpl::FsmActionWithCtrlHandle
{
    auto fx_operator_tcp_client(CtrlHandle &) -> void override;
    auto fx_operator_tcp_server(CtrlHandle &) -> void override;
};

struct                                                              //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::element:: //
    FsmAction::DoTransfer_L10_FromClient                            //
    : _ns_ignore::FsmElementWrapImpl::FsmActionWithCtrlHandle
{
    auto fx_operator_tcp_client(CtrlHandle &) -> void override;
    auto fx_operator_tcp_server(CtrlHandle &) -> void override;
};

struct                                                              //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::element:: //
    FsmAction::DoTransfer_L10_FromServer                            //
    : _ns_ignore::FsmElementWrapImpl::FsmActionWithCtrlHandle
{
    auto fx_operator_tcp_client(CtrlHandle &) -> void override;
    auto fx_operator_tcp_server(CtrlHandle &) -> void override;
};

struct                                                              //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::element:: //
    FsmAction::DoTransfer_L20                                       //
    : _ns_ignore::FsmElementWrapImpl::FsmActionWithCtrlHandle
{
    auto fx_operator_tcp_client(CtrlHandle &) -> void override;
    auto fx_operator_tcp_server(CtrlHandle &) -> void override;
};

struct                                                              //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::element:: //
    FsmAction::DoTransfer_L30                                       //
    : _ns_ignore::FsmElementWrapImpl::FsmActionWithCtrlHandle
{
    auto fx_operator_tcp_client(CtrlHandle &) -> void override;
    auto fx_operator_tcp_server(CtrlHandle &) -> void override;
};

struct                                                              //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::element:: //
    FsmAction::DoTransfer_L40                                       //
    : _ns_ignore::FsmElementWrapImpl::FsmActionWithCtrlHandle
{
    auto fx_operator_tcp_client(CtrlHandle &) -> void override;
    auto fx_operator_tcp_server(CtrlHandle &) -> void override;
};

struct                                                              //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::element:: //
    FsmAction::DoTransfer_L42                                       //
    : _ns_ignore::FsmElementWrapImpl::FsmActionWithCtrlHandle
{
    auto fx_operator_tcp_client(CtrlHandle &) -> void override;
    auto fx_operator_tcp_server(CtrlHandle &) -> void override;
};

struct                                                              //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::element:: //
    FsmAction::DoTransfer_L60                                       //
    : _ns_ignore::FsmElementWrapImpl::FsmActionWithCtrlHandle
{
    auto fx_operator_tcp_client(CtrlHandle &) -> void override;
    auto fx_operator_tcp_server(CtrlHandle &) -> void override;
};

struct                                                              //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::element:: //
    FsmAction::DoTransfer_OR_L41_L50                                //
    : _ns_ignore::FsmElementWrapImpl::FsmActionWithCtrlHandle
{
    auto fx_operator_tcp_client(CtrlHandle &) -> void override;
    auto fx_operator_tcp_server(CtrlHandle &) -> void override;

  protected:
    auto fx_transfer_L41_write_prepwork(CtrlHandle &) -> void;
    auto fx_transfer_L41_reade_postwork(CtrlHandle &) -> void;
    auto fx_transfer_L50_write_prepwork(CtrlHandle &) -> void;
    auto fx_transfer_L50_reade_postwork(CtrlHandle &) -> void;
};

/// FsmMachine
///

template <typename FSM_STATE_TRANSITION_TABLE, typename FSM_STATE_TRANSITION_TABLE_HEAD>
struct                                                                   //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::construction:: //
    FsmFactory::FsmFactory0
{
    struct FsmFront;
    using FsmBack = boost::msm::back::state_machine<FsmFront>;
};

template <typename FSM_STATE_TRANSITION_TABLE, typename FSM_STATE_TRANSITION_TABLE_HEAD>
struct                                                                                             //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::construction::                           //
    FsmFactory::FsmFactory0<FSM_STATE_TRANSITION_TABLE, FSM_STATE_TRANSITION_TABLE_HEAD>::FsmFront //
    : _ns_ignore::FsmElementWrapImpl::FsmFront<FsmFront, FSM_STATE_TRANSITION_TABLE, FSM_STATE_TRANSITION_TABLE_HEAD>
{
};

/// FsmMachine - FsmBack
///

struct                                                              //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::element:: //
    FsmStateIsSubMachine::MsgTransferFlow_Transfer_L10              //
    : FsmFactory::MsgTransferFlow_Transfer_L10::FsmBack
{
};

struct                                                              //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::element:: //
    FsmStateIsSubMachine::MsgTransferFlow_Transfer_L41_L42_L50      //
    : FsmFactory::MsgTransferFlow_Transfer_L41_L42_L50::FsmBack
{
};

struct                                                                   //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::construction:: //
    FsmBack::MsgTransferFlowClient                                       //
    : FsmFactory::MsgTransferFlow::FsmBack
{
    using Event = element::FsmEvent;
    using Unity = xplum_sdkit::taifex_msg_proto::kitbag::UnityTcpSession;
    explicit MsgTransferFlowClient(std::shared_ptr<Unity>);
    auto fx_is_hold_L41() -> bool;
};

struct                                                                   //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::construction:: //
    FsmBack::MsgTransferFlowServer                                       //
    : MsgTransferFlowClient
{
    using Event = element::FsmEvent;
    using Unity = xplum_sdkit::taifex_msg_proto::kitbag::UnityTcpSession;
    using UnityReServer = xplum_sdkit::taifex_msg_proto::kitbag::UnityTcpSessionPluginReServer_MOCK;
    explicit MsgTransferFlowServer(std::shared_ptr<Unity>, std::shared_ptr<UnityReServer>);
};
