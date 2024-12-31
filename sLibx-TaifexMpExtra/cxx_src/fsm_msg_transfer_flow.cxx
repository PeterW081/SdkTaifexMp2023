#include "xplum_sdkit/taifex_msg_proto/fsm/fsm_msg_transfer_flow.h"
#pragma

namespace nscxx_root = xplum_sdkit::taifex_msg_proto::fsm_msg_transfer_flow;

/// FsmMachine
///

/// MsgTransferFlowClient
/*Constructor*/                      //
nscxx_root::construction::           //
    FsmBack::MsgTransferFlowClient:: //
    MsgTransferFlowClient(std::shared_ptr<Unity> unity)
{
    this->m_ctrl = std::make_shared<FsmCtrlHandle>();
    this->m_ctrl->m_side = decltype(this->m_ctrl->m_side)::CLIENT;

    this->m_ctrl->m_unity = std::move(unity);
    this->m_ctrl->m_unity_re_server = nullptr;

    this->m_ctrl->m_is_done_transfer_L10_from_server = false;
    this->m_ctrl->m_is_done_transfer_L50 = false;
    this->m_ctrl->m_is_hold_L41 = false;
}
auto nscxx_root::construction::      //
    FsmBack::MsgTransferFlowClient:: //
    fx_is_hold_L41() -> bool
{
    return this->m_ctrl->m_is_hold_L41;
}

/// MsgTransferFlowServer
/*Constructor*/                      //
nscxx_root::construction::           //
    FsmBack::MsgTransferFlowServer:: //
    MsgTransferFlowServer(std::shared_ptr<Unity> unity, std::shared_ptr<UnityReServer> unity_re_server)
    : MsgTransferFlowClient(std::move(unity))
{
    this->m_ctrl->m_side = decltype(this->m_ctrl->m_side)::SERVER;
    this->m_ctrl->m_unity_re_server = std::move(unity_re_server);
}

/// FsmGuard
///
// nothing...

/// FsmAction
///
// in other file.
