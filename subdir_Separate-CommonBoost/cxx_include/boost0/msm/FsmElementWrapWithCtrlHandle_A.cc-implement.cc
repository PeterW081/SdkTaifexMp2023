#pragma once
#include "./FsmElementWrapWithCtrlHandle_A.h"
#pragma

template <typename FSM_CTRL_HANDLE>
auto                                                                       //
    boost0::msm::                                                          //
    FsmElementWrapWithCtrlHandle_A<FSM_CTRL_HANDLE>::FsmCtrlHandleParser:: //
    FX_FROM_FSM_GET_CTRL_HANDLE(FsmCtrlHandlePlugin &fsm) -> std::shared_ptr<FSM_CTRL_HANDLE>
{
    return fsm.m_ctrl;
}

template <typename FSM_CTRL_HANDLE>
template <typename CRTP_SELF, typename FSM_STATE_TRANSITION_TABLE, typename FSM_STATE_TRANSITION_TABLE_HEAD>
template <typename FSM, typename EVENT>
auto boost0::msm::                                                                                                                      //
    FsmElementWrapWithCtrlHandle_A<FSM_CTRL_HANDLE>::FsmFront<CRTP_SELF, FSM_STATE_TRANSITION_TABLE, FSM_STATE_TRANSITION_TABLE_HEAD>:: //
    on_entry(const EVENT &, FSM &fsm) -> void
{
    if constexpr (std::is_base_of_v<FsmCtrlHandlePlugin, FSM>)
    {
        if (this != static_cast<void *>(&fsm))
        {
            this->m_ctrl = FsmCtrlHandleParser::FX_FROM_FSM_GET_CTRL_HANDLE(fsm);
        }
    }
}
