#pragma once
#include "./MsgSessionMsgProcessor.h"
#pragma
#include <span>
#include "boost0/asio/_define_cxx.h"
#include "xplum_model/taifex_msg_proto/network_osi_L06/structure_msg_field/msg_field_enumerate.h"
#include "xplum_sdkit/taifex_msg_proto/_define_cxx.h"
#include "xplum_sdkit/taifex_msg_proto/network_osi_L05/partition_msg_session/msg_util_session_context.h"
#include "xplum_sdkit/taifex_msg_proto/network_osi_L06/reference_msg/msg_all_layer.h"
#

namespace xplum_sdkit::taifex_msg_proto::util
{
class MsgSessionMsgProcessor;
}

/// MsgSessionMsgProcessor
class                                     //
    xplum_sdkit::taifex_msg_proto::util:: //
    MsgSessionMsgProcessor
{
  public:
    using EnumSide = ext::boost_asio0::EnumTcpEndpointSide;
    using Type_MsgSessionContext = util::MsgSessionContext;
    using Type_MsgSessionContextReServer = util::MsgSessionContextReServer;
    EnumSide const m_msg_ep_side;
    //
    explicit MsgSessionMsgProcessor(EnumSide, std::shared_ptr<MsgSessionContext>, std::shared_ptr<MsgSessionContextReServer> = nullptr);
    auto fx_is_validly_0_L41_write_prep() const -> bool;
    template <enumerate::EnumMsgType>
    auto fx_msg_process_0_write_prep(std::span<std::byte>) -> void; // fx(data)
    template <enumerate::EnumMsgType>
    auto fx_msg_process_0_reade_post(std::span<std::byte>) -> void; // fx(data)
  private:
    using EnumMsgSocketAction = ext::boost_asio0::EnumTcpSocketAction;
    std::shared_ptr<Type_MsgSessionContext> m_msg_session_context;
    std::shared_ptr<Type_MsgSessionContextReServer> m_msg_session_context_re_server;
    //
    template <typename TYPE_msg_view, EnumMsgSocketAction> // TYPE_msg_view, ENUM_action
    auto fxUnit_msg_process(TYPE_msg_view &) -> void;      // msg_view
    auto fxUnit_msg_process_0_L41_write_prep(view::message::MsgL41_VIEW &) -> void;
};
