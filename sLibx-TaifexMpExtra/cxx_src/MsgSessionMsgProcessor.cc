#include "xplum_sdkit/taifex_msg_proto/network_osi_L05/partition_msg_session/MsgSessionMsgProcessor.h"
#pragma
#include <cassert>
#

namespace nscxx_root = xplum_sdkit::taifex_msg_proto::util;
namespace nscxx
{
}

/// MsgSessionMsgProcessor
/*Constructor*/              //
nscxx_root::                 //
    MsgSessionMsgProcessor:: //
    MsgSessionMsgProcessor(EnumSide msg_ep_side, std::shared_ptr<MsgSessionContext> msg_session_context, std::shared_ptr<MsgSessionContextReServer> msg_session_context_re_server)
    : m_msg_ep_side(msg_ep_side)
{
    assert(msg_ep_side == EnumSide::CLIENT || (msg_ep_side == EnumSide::SERVER && msg_session_context_re_server != nullptr));
    this->m_msg_session_context = msg_session_context;
    this->m_msg_session_context_re_server = msg_session_context_re_server;
}

/// MsgSessionMsgProcessor - fx_is_validly_0_L41_write_prep()
auto                         //
    nscxx_root::             //
    MsgSessionMsgProcessor:: //
    fx_is_validly_0_L41_write_prep() const -> bool
{
    return this->m_msg_session_context_re_server->fx_get_msg_L41Data_size_MOCK() != 0;
}

/// MsgSessionMsgProcessor - fxUnit_msg_process_0_L41_write_prep()
auto                         //
    nscxx_root::             //
    MsgSessionMsgProcessor:: //
    fxUnit_msg_process_0_L41_write_prep(view::message::MsgL41_VIEW &msg_view) -> void
{
    this->fxUnit_msg_process<view::message::MsgL41_VIEW, EnumMsgSocketAction::WRITE_PREP>(msg_view);
}
