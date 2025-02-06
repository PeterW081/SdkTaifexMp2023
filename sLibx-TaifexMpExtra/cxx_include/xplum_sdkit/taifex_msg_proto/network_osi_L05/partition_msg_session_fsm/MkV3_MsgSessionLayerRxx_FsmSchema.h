#pragma once
#include "xplum_sdkit/taifex_msg_proto/network_osi_L05/partition_msg_session_fsm/MkV3_MsgSession_FsmElementCommon.h"
#

/// namespace
namespace xplum_sdkit::taifex_msg_proto::fsm_element
{
struct MkV3_MsgSessionLayerRxx_FsmElement;
}
namespace xplum_sdkit::taifex_msg_proto::fsm
{
struct MkV3_MsgSessionLayerRxx_FsmSchema;
}

/// MkV3_MsgSessionLayerRxx_FsmElement
struct                                                                    //
    xplum_sdkit::taifex_msg_proto::fsm_element::                          //
    MkV3_MsgSessionLayerRxx_FsmElement : MkV3_MsgSession_FsmElementCommon //
{
    struct Event;
    struct State;
    struct Action;
    struct Guard;
};
struct                                           //
    xplum_sdkit::taifex_msg_proto::fsm_element:: //
    MkV3_MsgSessionLayerRxx_FsmElement::Event    //
{
};
struct                                           //
    xplum_sdkit::taifex_msg_proto::fsm_element:: //
    MkV3_MsgSessionLayerRxx_FsmElement::State    //
{
    using None = boost::msm::front::none;
};
struct                                           //
    xplum_sdkit::taifex_msg_proto::fsm_element:: //
    MkV3_MsgSessionLayerRxx_FsmElement::Action   //
{
    using None = boost::msm::front::none;
};
struct                                           //
    xplum_sdkit::taifex_msg_proto::fsm_element:: //
    MkV3_MsgSessionLayerRxx_FsmElement::Guard    //
{
    using None = boost::msm::front::none;
};

/// MkV3_MsgSessionLayerRxx_FsmSchema
struct                                   //
    xplum_sdkit::taifex_msg_proto::fsm:: //
    MkV3_MsgSessionLayerRxx_FsmSchema : protected fsm_element::MkV3_MsgSessionLayerRxx_FsmElement
{
    using FsmMeta = std::tuple<MachineFront,                     // FsmFront
                               boost::mpl::vector<State_0_TODO>, // FsmInitialState
                               boost::mpl::vector<               // FsmTransitionTable
                                                   // StateSource, Event, StateTarget, Action, Guard,
                                   > /**/
                               >;

  public:
    using FsmEvent = Event;
    using FsmState = State;
    using FsmBack = boost0::msm::FsmFactoryPlus_TUPLE<FsmMeta>::FsmBack;
};
