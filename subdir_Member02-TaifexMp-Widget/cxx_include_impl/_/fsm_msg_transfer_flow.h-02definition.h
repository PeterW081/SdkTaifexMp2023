#pragma once
#include_next "xplum_sdkit/taifex_msg_proto/fsm/fsm_msg_transfer_flow.h-02definition.h"
#pragma

/// FsmGuard
///

template <typename FSM, typename EVENT, typename SRCE, typename TAGT>
auto                                                                   //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::_ns_ignore:: //
    FsmElementWrapImpl::FsmGuardWithCtrlHandle::                       //
    operator()(const EVENT &, FSM & fsm, SRCE &, TAGT &) -> bool {
  auto &ctrl = FX_FROM_FSM_GET_CTRL_HANDLE(fsm).operator*();
  return this->fx_operator(ctrl);
}

/// FsmAction
///

template <typename FSM, typename EVENT, typename SRCE, typename TAGT>  //
auto                                                                   //
    xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::_ns_ignore:: //
    FsmElementWrapImpl::FsmActionWithCtrlHandle::                      //
    operator()(const EVENT &, FSM & fsm, SRCE &, TAGT &) -> void {
  auto &ctrl = FX_FROM_FSM_GET_CTRL_HANDLE(fsm).operator*();
  switch (ctrl.m_side) {
  case decltype(ctrl.m_side)::CLIENT:
    this->fx_operator_tcp_client(ctrl);
    break;
  case decltype(ctrl.m_side)::SERVER:
    this->fx_operator_tcp_server(ctrl);
    break;
  [[unlikely]] default:
    break;
  }
}

template <typename FSM, typename EVENT, typename SRCE, typename TAGT> //
auto xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow::element::  //
    FsmAction::AssertFsmStateOrFsmNoTransition::                      //
    operator()(const EVENT & event, FSM & fsm, SRCE &, TAGT &) -> void {
  auto &ctrl = FX_FROM_FSM_GET_CTRL_HANDLE(fsm).operator*();

  auto is_ok = true;
  if constexpr (std::is_same_v<TAGT, FsmState::DoneTransfer_L10_FromServer>) {
    is_ok &= ctrl.m_is_done_transfer_L10_from_server;
  }
  if constexpr (std::is_same_v<TAGT, FsmState::DoneTransfer_L50>) {
    is_ok &= ctrl.m_is_done_transfer_L50;
  }
  if (not is_ok) {
    fsm.no_transition(event, fsm, *(fsm.current_state()));
  }
}
