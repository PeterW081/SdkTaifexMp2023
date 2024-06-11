#pragma once
#include <boost/msm/front/functor_row.hpp>
#include <boost/msm/front/state_machine_def.hpp>
#include <boost/msm/back/state_machine.hpp>

namespace boost0::msm {
struct FsmElementWrapSimple;
}

struct            //
    boost0::msm:: //
    FsmElementWrapSimple {
  template <typename CRTP_SELF, typename FSM_STATE_TRANSITION_TABLE, typename FSM_STATE_TRANSITION_TABLE_HEAD> struct FsmFront;
  struct FsmEvent;
  struct FsmState;
  struct FsmGuard;
  struct FsmAction;
};

template <typename CRTP_SELF, typename FSM_STATE_TRANSITION_TABLE, typename FSM_STATE_TRANSITION_TABLE_HEAD>
struct                             //
    boost0::msm::                  //
    FsmElementWrapSimple::FsmFront //
    : public boost::msm::front::state_machine_def<CRTP_SELF> {
  // Base:
  using initial_state = FSM_STATE_TRANSITION_TABLE_HEAD;
  using transition_table = FSM_STATE_TRANSITION_TABLE;
  template <typename FSM, typename EVENT> auto on_entry(const EVENT &, FSM &) -> void;
  template <typename FSM, typename EVENT> auto no_transition(const EVENT &, FSM &, int) -> void;
  template <typename FSM, typename EVENT> auto exception_caught(const EVENT &, FSM &, std::exception &e) -> void;
};

struct                             //
    boost0::msm::                  //
    FsmElementWrapSimple::FsmState //
    : public boost::msm::front::state<> {};

struct            //
    boost0::msm:: //
    FsmElementWrapSimple::FsmEvent {};

struct            //
    boost0::msm:: //
    FsmElementWrapSimple::FsmGuard {
  template <typename FSM, typename EVENT, typename SRCE, typename TAGT> auto operator()(const EVENT &, FSM &, SRCE &, TAGT &) -> bool;
};

struct            //
    boost0::msm:: //
    FsmElementWrapSimple::FsmAction {
  template <typename FSM, typename EVENT, typename SRCE, typename TAGT> auto operator()(const EVENT &, FSM &, SRCE &, TAGT &) -> void;
};
