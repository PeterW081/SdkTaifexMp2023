#include "xplum_sdkit/taifex_msg_proto/network_osi_L05/partition_msg_session_fsm/MkV3_MsgSessionLayerLxx_FsmSchema.h"
#pragma
#include "xplum_sdkit/taifex_msg_proto/_define_cxx.h"
#

/// ******************************** ******************************** ******************************** ******************************** ///
/// Cxx
namespace nscxx_root = xplum_sdkit::taifex_msg_proto;
namespace nscxx
{
using xplum_sdkit::taifex_msg_proto::enumerate::EnumMsgType;
using xplum_sdkit::taifex_msg_proto::util::MsgSessionMsgProcessor;
struct CxxFuncWrap;
}
struct nscxx::CxxFuncWrap : nscxx_root::fsm_element::MkV3_MsgSessionLayerLxx_FsmElement
{
    template <EnumMsgType>
    static auto FX_msg_process_0_common(MsgSessionMsgProcessor &, Event_MsgProcessorContext_A const &) -> void;
};

/// ******************************** ******************************** ******************************** ******************************** ///
/// MkV2_MsgSessionFsmElement::Action
#define MACRO_XPLUM_0_FSMACTION_0_OPERATOR(PARAM01_CLASS_NAME, PARAM02_MSG_TYPE)                                                                                                                                                                               \
    auto                                                               /**/                                                                                                                                                                                    \
        nscxx_root::fsm_element::                                      /**/                                                                                                                                                                                    \
        MkV3_MsgSessionLayerLxx_FsmElement::Action::PARAM01_CLASS_NAME /**/                                                                                                                                                                                    \
        ::operator()(Event_MsgProcessorContext_A const &event, MachineFront & fsm, State_A &, State_A &)                                                                                                                                                       \
            ->void                                                                                                                                                                                                                                             \
    {                                                                                                                                                                                                                                                          \
        nscxx::CxxFuncWrap::FX_msg_process_0_common<nscxx::EnumMsgType::PARAM02_MSG_TYPE>(fsm.m_fsm_context.m_msg_processor.operator*(), event);                                                                                                               \
    }                                                                                                                                                                                                                                                          \
    /**/
MACRO_XPLUM_0_FSMACTION_0_OPERATOR(MsgL10_PREP_ClientToServer, L10)
MACRO_XPLUM_0_FSMACTION_0_OPERATOR(MsgL10_POST_ClientToServer, L10)
MACRO_XPLUM_0_FSMACTION_0_OPERATOR(MsgL10_PREP_ServerToClient, L10)
MACRO_XPLUM_0_FSMACTION_0_OPERATOR(MsgL10_POST_ServerToClient, L10)
MACRO_XPLUM_0_FSMACTION_0_OPERATOR(MsgL20_PREP /*----------*/, L20)
MACRO_XPLUM_0_FSMACTION_0_OPERATOR(MsgL20_POST /*----------*/, L20)
MACRO_XPLUM_0_FSMACTION_0_OPERATOR(MsgL30_PREP /*----------*/, L30)
MACRO_XPLUM_0_FSMACTION_0_OPERATOR(MsgL30_POST /*----------*/, L30)
MACRO_XPLUM_0_FSMACTION_0_OPERATOR(MsgL40_PREP /*----------*/, L40)
MACRO_XPLUM_0_FSMACTION_0_OPERATOR(MsgL40_POST /*----------*/, L40)
MACRO_XPLUM_0_FSMACTION_0_OPERATOR(MsgL41_PREP /*----------*/, L41)
MACRO_XPLUM_0_FSMACTION_0_OPERATOR(MsgL41_POST /*----------*/, L41)
MACRO_XPLUM_0_FSMACTION_0_OPERATOR(MsgL42_PREP /*----------*/, L42)
MACRO_XPLUM_0_FSMACTION_0_OPERATOR(MsgL42_POST /*----------*/, L42)
MACRO_XPLUM_0_FSMACTION_0_OPERATOR(MsgL50_PREP /*----------*/, L50)
MACRO_XPLUM_0_FSMACTION_0_OPERATOR(MsgL50_POST /*----------*/, L50)
MACRO_XPLUM_0_FSMACTION_0_OPERATOR(MsgL60_PREP /*----------*/, L60)
MACRO_XPLUM_0_FSMACTION_0_OPERATOR(MsgL60_POST /*----------*/, L60)

/// ******************************** ******************************** ******************************** ******************************** ///
/// MkV2_MsgSessionFsmElement::Guard
// X MkV2_MsgSessionFsmElement::Guard - A1_MsgServer_IsWillWriteL41
auto                                                                       //
    nscxx_root::fsm_element::                                              //
    MkV3_MsgSessionLayerLxx_FsmElement::Guard::A1_MsgServer_IsWillWriteL41 //
    ::operator()(Event_MsgProcessorContext_A const &event, MachineFront & fsm, State_A &, State_A &) -> bool
{
    auto const &msg_processor = fsm.m_fsm_context.m_msg_processor.operator*();
    auto is_validly_0_write_L41 = true;
    is_validly_0_write_L41 &= msg_processor.m_msg_ep_side == EnumSide::SERVER;
    is_validly_0_write_L41 &= msg_processor.fx_is_validly_0_L41_write_prep();
    return is_validly_0_write_L41;
}
// X MkV2_MsgSessionFsmElement::Guard - A2_MsgServer_IsWillWriteL50
auto                                                                       //
    nscxx_root::fsm_element::                                              //
    MkV3_MsgSessionLayerLxx_FsmElement::Guard::A2_MsgServer_IsWillWriteL50 //
    ::operator()(Event_MsgProcessorContext_A const &event, MachineFront & fsm, State_A & fp03, State_A & fp04) -> bool
{
    return not A1_MsgServer_IsWillWriteL41()(event, fsm, fp03, fp04);
}
// X MkV2_MsgSessionFsmElement::Guard - A3_MsgClient_IsWillReadeLxx_0_L41_L50
auto                                                                                 //
    nscxx_root::fsm_element::                                                        //
    MkV3_MsgSessionLayerLxx_FsmElement::Guard::A3_MsgClient_IsWillReadeLxx_0_L41_L50 //
    ::operator()(Event_MsgProcessorContext_A const &event, MachineFront & fsm, State_A &, State_A &) -> bool
{
    auto const &msg_processor = fsm.m_fsm_context.m_msg_processor.operator*();
    return msg_processor.m_msg_ep_side == EnumSide::CLIENT;
}
// X MkV2_MsgSessionFsmElement::Guard - B1_MsgClient_IsHaveReadeL41
auto                                                                       //
    nscxx_root::fsm_element::                                              //
    MkV3_MsgSessionLayerLxx_FsmElement::Guard::B1_MsgClient_IsHaveReadeL41 //
    ::operator()(Event_MsgProcessorContext_A const &event, MachineFront & fsm, State_A &, State_A &) -> bool
{
    return ez_view::FX_get_msg_type_from_msg_data(event.m_span.data()).enum_value() == nscxx::EnumMsgType::L41;
}
// X MkV2_MsgSessionFsmElement::Guard - B2_MsgClient_IsHaveReadeL50
auto                                                                       //
    nscxx_root::fsm_element::                                              //
    MkV3_MsgSessionLayerLxx_FsmElement::Guard::B2_MsgClient_IsHaveReadeL50 //
    ::operator()(Event_MsgProcessorContext_A const &event, MachineFront & fsm, State_A &, State_A &) -> bool
{
    return ez_view::FX_get_msg_type_from_msg_data(event.m_span.data()).enum_value() == nscxx::EnumMsgType::L50;
}

/// ******************************** ******************************** ******************************** ******************************** ///
/// Cxx - function
template <nscxx::EnumMsgType ENUM_msg_type>
auto nscxx::CxxFuncWrap::FX_msg_process_0_common(MsgSessionMsgProcessor &msg_processor, Event_MsgProcessorContext_A const &event) -> void
{
    auto action = EnumAction::NULL0;
    switch (msg_processor.m_msg_ep_side)
    {
    case EnumSide::SERVER:
        action = event.m_server_action;
        break;
    case EnumSide::CLIENT:
        action = event.m_client_action;
        break;
    default:
        break;
    }
    switch (action)
    {
    case EnumAction::WRITE_PREP:
        msg_processor.fx_msg_process_0_write_prep<ENUM_msg_type>(event.m_span);
        break;
    case EnumAction::READE_POST:
        msg_processor.fx_msg_process_0_reade_post<ENUM_msg_type>(event.m_span);
        break;
    default:
        break;
    }
}
