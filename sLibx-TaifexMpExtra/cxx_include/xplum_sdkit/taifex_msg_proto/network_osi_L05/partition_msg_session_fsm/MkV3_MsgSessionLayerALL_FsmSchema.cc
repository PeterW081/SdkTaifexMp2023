#pragma once
#include "./MkV3_MsgSessionLayerALL_FsmSchema.h"
#pragma
#include "xplum_sdkit/taifex_msg_proto/network_osi_L05/partition_msg_session_fsm/MkV3_MsgSession_FsmElementCommon.h"
#include "xplum_sdkit/taifex_msg_proto/network_osi_L05/partition_msg_session_fsm/MkV3_MsgSessionLayerLxx_FsmSchema.h"
#include "xplum_sdkit/taifex_msg_proto/network_osi_L05/partition_msg_session_fsm/MkV3_MsgSessionLayerRxx_FsmSchema.h"
#

/// namespace
namespace xplum_sdkit::taifex_msg_proto::fsm_element
{
struct MkV3_MsgSessionLayerALL_FsmElement;
}
namespace xplum_sdkit::taifex_msg_proto::fsm
{
struct MkV3_MsgSessionLayerALL_FsmSchema;
}

/// MkV3_MsgSessionLayerALL_FsmElement
struct                                                                    //
    xplum_sdkit::taifex_msg_proto::fsm_element::                          //
    MkV3_MsgSessionLayerALL_FsmElement : MkV3_MsgSession_FsmElementCommon //
{
    struct Event;
    struct State;
    struct Action;
    struct Guard;
};
struct                                           //
    xplum_sdkit::taifex_msg_proto::fsm_element:: //
    MkV3_MsgSessionLayerALL_FsmElement::Event    //
    : fsm::MkV3_MsgSessionLayerLxx_FsmSchema::FsmEvent
{
    struct Sxx_MsgLayer_NEXT;
    struct Sxx_MsgLayer_REDO_AFTER_MsgL10_ClientToServer;
    struct Sxx_MsgLayer_REDO_AFTER_MsgL10_ServerToClient;
};
struct                                           //
    xplum_sdkit::taifex_msg_proto::fsm_element:: //
    MkV3_MsgSessionLayerALL_FsmElement::State    //
    : fsm::MkV3_MsgSessionLayerLxx_FsmSchema::FsmState
{
    using None = boost::msm::front::none;
    using MsgLayerLxx = fsm::MkV3_MsgSessionLayerLxx_FsmSchema::FsmBack;
    using MsgLayerRxx = fsm::MkV3_MsgSessionLayerRxx_FsmSchema::FsmBack;
};
struct                                           //
    xplum_sdkit::taifex_msg_proto::fsm_element:: //
    MkV3_MsgSessionLayerALL_FsmElement::Action   //
{
    using None = boost::msm::front::none;
    using TODO = Action_0_TODO;
};
struct                                           //
    xplum_sdkit::taifex_msg_proto::fsm_element:: //
    MkV3_MsgSessionLayerALL_FsmElement::Guard    //
{
    using None = boost::msm::front::none;
    using Exception_FsmNoTransition = Guard_0_Exception_FsmNoTransition;
    template <typename TYPE_subfsm_state>
    using Assert_StateSource_SubfsmCurrentState = Guard_0_Assert_StateSource_SubfsmCurrentState<TYPE_subfsm_state>;
};

/// MkV3_MsgSessionLayerALL_FsmSchema
struct                                   //
    xplum_sdkit::taifex_msg_proto::fsm:: //
    MkV3_MsgSessionLayerALL_FsmSchema : protected fsm_element::MkV3_MsgSessionLayerALL_FsmElement
{
    using FsmMeta = std::tuple<
        MachineFront,                           // FsmFront
        boost::mpl::vector<State::MsgLayerLxx>, // FsmInitialState
        boost::mpl::vector<                     // FsmTransitionTable
                            // StateSource, Event, StateTarget, Action, Guard,
            boost::msm::front::Row<State::MsgLayerLxx, Event::Sxx_MsgLayer_NEXT /*-----------------------*/, State::None /*----------------------------------------------*/, Action::None, Guard::Exception_FsmNoTransition /*----------------------------*/>,
            boost::msm::front::Row<State::MsgLayerLxx, Event::Sxx_MsgLayer_NEXT /*-----------------------*/, State::MsgLayerRxx /*---------------------------------------*/, Action::None, Guard::Assert_StateSource_SubfsmCurrentState<State::MsgL60_HAVEx>>,
            boost::msm::front::Row<State::MsgLayerLxx, Event::Sxx_MsgLayer_REDO_AFTER_MsgL10_ClientToServer, State::MsgLayerLxx::direct<State::MsgL10_WILLx_ServerToClient>, Action::TODO, Guard::None /*-------------------------------------------------*/>,
            boost::msm::front::Row<State::MsgLayerRxx, Event::Sxx_MsgLayer_REDO_AFTER_MsgL10_ClientToServer, State::MsgLayerLxx::direct<State::MsgL10_WILLx_ServerToClient>, Action::TODO, Guard::None /*-------------------------------------------------*/>,
            boost::msm::front::Row<State::MsgLayerLxx, Event::Sxx_MsgLayer_REDO_AFTER_MsgL10_ServerToClient, State::MsgLayerLxx::direct<State::MsgL20_WILLx> /*----------*/, Action::TODO, Guard::None /*-------------------------------------------------*/>,
            boost::msm::front::Row<State::MsgLayerRxx, Event::Sxx_MsgLayer_REDO_AFTER_MsgL10_ServerToClient, State::MsgLayerLxx::direct<State::MsgL20_WILLx> /*----------*/, Action::TODO, Guard::None /*-------------------------------------------------*/>
            // ---
            > /**/
        >;

  public:
    using FsmEvent = Event;
    using FsmState = State;
    using FsmBack = boost0::msm::FsmFactoryPlus_TUPLE<FsmMeta>::FsmBack;
};
