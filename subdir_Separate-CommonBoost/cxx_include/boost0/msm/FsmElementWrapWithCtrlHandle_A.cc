#pragma once
#include "./FsmElementWrapWithCtrlHandle_A.h"
#pragma

#include <boost/msm/front/functor_row.hpp>
#include <boost/msm/front/state_machine_def.hpp>
#include <boost/msm/back/state_machine.hpp>
#include "boost0/msm/FsmElementWrapSimple.h"

namespace boost0::msm
{
template <typename FSM_CTRL_HANDLE> struct FsmElementWrapWithCtrlHandle_A;
}

template <typename FSM_CTRL_HANDLE> //
struct                              //
    boost0::msm::                   //
    FsmElementWrapWithCtrlHandle_A  //
    : FsmElementWrapSimple
{
  template <typename CRTP_SELF, typename FSM_STATE_TRANSITION_TABLE, typename FSM_STATE_TRANSITION_TABLE_HEAD> struct FsmFront;
  struct FsmGuard;
  struct FsmAction;

private:
  using SUPER = FsmElementWrapSimple;
  struct FsmCtrlHandlePlugin;
  struct FsmCtrlHandleParser;
};

template <typename FSM_CTRL_HANDLE> //
struct                              //
    boost0::msm::                   //
    FsmElementWrapWithCtrlHandle_A<FSM_CTRL_HANDLE>::FsmCtrlHandlePlugin
{
public:
  friend FsmCtrlHandleParser;
  using FsmCtrlHandle = FSM_CTRL_HANDLE;

protected:
  std::shared_ptr<FsmCtrlHandle> m_ctrl;
};

template <typename FSM_CTRL_HANDLE> //
struct                              //
    boost0::msm::                   //
    FsmElementWrapWithCtrlHandle_A<FSM_CTRL_HANDLE>::FsmCtrlHandleParser
{
  static auto FX_FROM_FSM_GET_CTRL_HANDLE (FsmCtrlHandlePlugin &) -> std::shared_ptr<FSM_CTRL_HANDLE>;
};

template <typename FSM_CTRL_HANDLE>                                                                          //
template <typename CRTP_SELF, typename FSM_STATE_TRANSITION_TABLE, typename FSM_STATE_TRANSITION_TABLE_HEAD> //
struct                                                                                                       //
    boost0::msm::                                                                                            //
    FsmElementWrapWithCtrlHandle_A<FSM_CTRL_HANDLE>::FsmFront                                                //
    : SUPER::FsmFront<CRTP_SELF, FSM_STATE_TRANSITION_TABLE, FSM_STATE_TRANSITION_TABLE_HEAD>,
      FsmCtrlHandlePlugin,
      FsmCtrlHandleParser
{
  template <typename FSM, typename EVENT> auto on_entry (const EVENT &, FSM &) -> void;
};

template <typename FSM_CTRL_HANDLE>                           //
struct                                                        //
    boost0::msm::                                             //
    FsmElementWrapWithCtrlHandle_A<FSM_CTRL_HANDLE>::FsmGuard //
    : SUPER::FsmGuard,
      FsmCtrlHandleParser
{
};

template <typename FSM_CTRL_HANDLE>                            //
struct                                                         //
    boost0::msm::                                              //
    FsmElementWrapWithCtrlHandle_A<FSM_CTRL_HANDLE>::FsmAction //
    : SUPER::FsmAction,
      FsmCtrlHandleParser
{
};
