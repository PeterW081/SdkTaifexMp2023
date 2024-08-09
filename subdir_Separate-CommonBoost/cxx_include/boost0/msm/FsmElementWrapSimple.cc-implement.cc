#pragma once
#include "./FsmElementWrapSimple.h"
#pragma

template <typename CRTP_SELF, typename FSM_STATE_TRANSITION_TABLE, typename FSM_STATE_TRANSITION_TABLE_HEAD>
template <typename FSM, typename EVENT>
auto                                                                                                         //
    boost0::msm::                                                                                            //
    FsmElementWrapSimple::FsmFront<CRTP_SELF, FSM_STATE_TRANSITION_TABLE, FSM_STATE_TRANSITION_TABLE_HEAD>:: //
    on_entry (const EVENT &, FSM &) -> void
{
}

template <typename CRTP_SELF, typename FSM_STATE_TRANSITION_TABLE, typename FSM_STATE_TRANSITION_TABLE_HEAD>
template <typename FSM, typename EVENT>
auto                                                                                                         //
    boost0::msm::                                                                                            //
    FsmElementWrapSimple::FsmFront<CRTP_SELF, FSM_STATE_TRANSITION_TABLE, FSM_STATE_TRANSITION_TABLE_HEAD>:: //
    no_transition (const EVENT &, FSM &, int) -> void
{
  throw std::runtime_error ("EXCEPTION_MSG_63203BEF: boost_msm, fsm, no_transition,");
}

template <typename CRTP_SELF, typename FSM_STATE_TRANSITION_TABLE, typename FSM_STATE_TRANSITION_TABLE_HEAD>
template <typename FSM, typename EVENT>
auto                                                                                                         //
    boost0::msm::                                                                                            //
    FsmElementWrapSimple::FsmFront<CRTP_SELF, FSM_STATE_TRANSITION_TABLE, FSM_STATE_TRANSITION_TABLE_HEAD>:: //
    exception_caught (const EVENT &, FSM &, std::exception &e) -> void
{
  throw std::runtime_error (e.what ());
}

template <typename FSM, typename EVENT, typename SRCE, typename TAGT>
auto                                 //
    boost0::msm::                    //
    FsmElementWrapSimple::FsmGuard:: //
    operator() (const EVENT &, FSM &, SRCE &, TAGT &) -> bool
{
  return true;
}

template <typename FSM, typename EVENT, typename SRCE, typename TAGT>
auto                                  //
    boost0::msm::                     //
    FsmElementWrapSimple::FsmAction:: //
    operator() (const EVENT &, FSM &, SRCE &, TAGT &) -> void
{
}
