#pragma once
#include "./MkV3_MsgSessionLayerLxx_FsmSchema.h"
#pragma
#include "xplum_sdkit/taifex_msg_proto/network_osi_L05/partition_msg_session_fsm/MkV3_MsgSession_FsmElementCommon.h"
#

/// namespace
namespace xplum_sdkit::taifex_msg_proto::fsm_element
{
struct MkV3_MsgSessionLayerLxx_FsmElement;
}
namespace xplum_sdkit::taifex_msg_proto::fsm
{
struct MkV3_MsgSessionLayerLxx_FsmSchema;
}

/// MkV3_MsgSessionLayerLxx_FsmElement
struct                                                                    //
    xplum_sdkit::taifex_msg_proto::fsm_element::                          //
    MkV3_MsgSessionLayerLxx_FsmElement : MkV3_MsgSession_FsmElementCommon //
{
    struct Event;
    struct State;
    struct Action;
    struct Guard;
};
struct                                           //
    xplum_sdkit::taifex_msg_proto::fsm_element:: //
    MkV3_MsgSessionLayerLxx_FsmElement::Event    //
{
    struct Sxx_MsgLxx_MsgSeq_NEXT;
    struct S01_MsgL10_BEGING_ClientToServer; // Step01_MsgL10_BEGING_ClientToServer
    struct S02_MsgL10_ENDxxx_ClientToServer;
    struct S03_MsgL10_BEGING_ServerToClient;
    struct S04_MsgL10_ENDxxx_ServerToClient;
    struct S05_MsgL20_BEGING;
    struct S06_MsgL20_ENDxxx;
    struct S07_MsgL30_BEGING;
    struct S08_MsgL30_ENDxxx;
    struct S09_MsgL40_BEGING;
    struct S10_MsgL40_ENDxxx;
    struct S11_MsgL41_BEGING;
    struct S12_MsgL41_ENDxxx;
    struct S13_MsgL42_BEGING;
    struct S14_MsgL42_ENDxxx;
    struct S15_MsgL50_BEGING;
    struct S16_MsgL50_ENDxxx;
    struct S17_MsgL60_BEGING;
    struct S18_MsgL60_ENDxxx;
};
struct                                           //
    xplum_sdkit::taifex_msg_proto::fsm_element:: //
    MkV3_MsgSessionLayerLxx_FsmElement::State    //
{
    using None = boost::msm::front::none;
    struct MsgL10_WILLx_ClientToServer; // MsgL10_Transfer_WILLx_ClientToServer
    struct MsgL10_DOING_ClientToServer;
    struct MsgL10_HAVEx_ClientToServer;
    struct MsgL10_WILLx_ServerToClient;
    struct MsgL10_DOING_ServerToClient;
    struct MsgL10_HAVEx_ServerToClient;
    struct MsgL20_WILLx;
    struct MsgL20_DOING;
    struct MsgL20_HAVEx;
    struct MsgL30_WILLx;
    struct MsgL30_DOING;
    struct MsgL30_HAVEx;
    struct MsgL40_WILLx;
    struct MsgL40_DOING;
    struct MsgL40_HAVEx;
    struct MsgL41_DOING;
    struct MsgL41_HAVEx;
    struct MsgL42_WILLx;
    struct MsgL42_DOING;
    struct MsgL42_HAVEx;
    struct MsgL50_DOING;
    struct MsgL50_HAVEx;
    struct MsgL60_WILLx;
    struct MsgL60_DOING;
    struct MsgL60_HAVEx;
    struct MsgLxx_WILLx_0_MsgL41_MsgL50; // MsgLxx_Transfer_WILLx_0_MsgL41_MsgL50
    struct MsgLxx_DOING_0_MsgL41_MsgL50;
};
struct                                           //
    xplum_sdkit::taifex_msg_proto::fsm_element:: //
    MkV3_MsgSessionLayerLxx_FsmElement::Action   //
{
    using None = boost::msm::front::none;
    struct MsgL10_PREP_ClientToServer; // MsgL10_Transfer_PREP_ClientToServer
    struct MsgL10_POST_ClientToServer;
    struct MsgL10_PREP_ServerToClient;
    struct MsgL10_POST_ServerToClient;
    struct MsgL20_PREP;
    struct MsgL20_POST;
    struct MsgL30_PREP;
    struct MsgL30_POST;
    struct MsgL40_PREP;
    struct MsgL40_POST;
    struct MsgL41_PREP;
    struct MsgL41_POST;
    struct MsgL42_PREP;
    struct MsgL42_POST;
    struct MsgL50_PREP;
    struct MsgL50_POST;
    struct MsgL60_PREP;
    struct MsgL60_POST;
};
struct                                           //
    xplum_sdkit::taifex_msg_proto::fsm_element:: //
    MkV3_MsgSessionLayerLxx_FsmElement::Guard    //
{
    using None = boost::msm::front::none;
    using Exception_FsmNoTransition = Guard_0_Exception_FsmNoTransition;
    struct A1_MsgServer_IsWillWriteL41; // Switch0A_Case01_MsgServer_IsWillWriteL41
    struct A2_MsgServer_IsWillWriteL50;
    struct A3_MsgClient_IsWillReadeLxx_0_L41_L50;
    struct B1_MsgClient_IsHaveReadeL41;
    struct B2_MsgClient_IsHaveReadeL50;
};

/// MkV3_MsgSessionLayerLxx_FsmSchema
struct                                   //
    xplum_sdkit::taifex_msg_proto::fsm:: //
    MkV3_MsgSessionLayerLxx_FsmSchema : protected fsm_element::MkV3_MsgSessionLayerLxx_FsmElement
{
    using FsmMeta = std::tuple<MachineFront,                                           // FsmFront
                               boost::mpl::vector<State::MsgL10_WILLx_ClientToServer>, // FsmInitialState
                               boost::fusion::vector<                                  // FsmTransitionTable
                                                      // StateSource, Event, StateTarget, Action, Guard, - L10
                                   boost::msm::front::Row<State::MsgL10_WILLx_ClientToServer, Event::S01_MsgL10_BEGING_ClientToServer, State::MsgL10_DOING_ClientToServer, Action::MsgL10_PREP_ClientToServer, Guard::None>,
                                   boost::msm::front::Row<State::MsgL10_DOING_ClientToServer, Event::S02_MsgL10_ENDxxx_ClientToServer, State::MsgL10_HAVEx_ClientToServer, Action::MsgL10_POST_ClientToServer, Guard::None>,
                                   boost::msm::front::Row<State::MsgL10_WILLx_ServerToClient, Event::S03_MsgL10_BEGING_ServerToClient, State::MsgL10_DOING_ServerToClient, Action::MsgL10_PREP_ServerToClient, Guard::None>,
                                   boost::msm::front::Row<State::MsgL10_DOING_ServerToClient, Event::S04_MsgL10_ENDxxx_ServerToClient, State::MsgL10_HAVEx_ServerToClient, Action::MsgL10_POST_ServerToClient, Guard::None>,
                                   // StateSource, Event, StateTarget, Action, Guard, - L20,L30,L40,
                                   boost::msm::front::Row<State::MsgL20_WILLx, Event::S05_MsgL20_BEGING, State::MsgL20_DOING, Action::MsgL20_PREP, Guard::None>,
                                   boost::msm::front::Row<State::MsgL20_DOING, Event::S06_MsgL20_ENDxxx, State::MsgL20_HAVEx, Action::MsgL20_POST, Guard::None>,
                                   boost::msm::front::Row<State::MsgL30_WILLx, Event::S07_MsgL30_BEGING, State::MsgL30_DOING, Action::MsgL30_PREP, Guard::None>,
                                   boost::msm::front::Row<State::MsgL30_DOING, Event::S08_MsgL30_ENDxxx, State::MsgL30_HAVEx, Action::MsgL30_POST, Guard::None>,
                                   boost::msm::front::Row<State::MsgL40_WILLx, Event::S09_MsgL40_BEGING, State::MsgL40_DOING, Action::MsgL40_PREP, Guard::None>,
                                   boost::msm::front::Row<State::MsgL40_DOING, Event::S10_MsgL40_ENDxxx, State::MsgL40_HAVEx, Action::MsgL40_POST, Guard::None>,
                                   // StateSource, Event, StateTarget, Action, Guard, - L41,L42,L50,
                                   boost::msm::front::Row<State::MsgLxx_WILLx_0_MsgL41_MsgL50, Event::S11_MsgL41_BEGING, State::None /*-------------------*/, Action::None /*--*/, Guard::Exception_FsmNoTransition /*-------*/>,
                                   boost::msm::front::Row<State::MsgLxx_WILLx_0_MsgL41_MsgL50, Event::S11_MsgL41_BEGING, State::MsgL41_DOING /*-----------*/, Action::MsgL41_PREP, Guard::A1_MsgServer_IsWillWriteL41 /*-----*/>,
                                   boost::msm::front::Row<State::MsgLxx_WILLx_0_MsgL41_MsgL50, Event::S11_MsgL41_BEGING, State::None /*-------------------*/, Action::None /*--*/, Guard::A2_MsgServer_IsWillWriteL50 /*-----*/>,
                                   boost::msm::front::Row<State::MsgLxx_WILLx_0_MsgL41_MsgL50, Event::S11_MsgL41_BEGING, State::MsgLxx_DOING_0_MsgL41_MsgL50, Action::None /*--*/, Guard::A3_MsgClient_IsWillReadeLxx_0_L41_L50>,
                                   boost::msm::front::Row<State::MsgLxx_DOING_0_MsgL41_MsgL50, Event::S11_MsgL41_BEGING, State::None /*-------------------*/, Action::None /*--*/, Guard::None>,
                                   boost::msm::front::Row<State::MsgL41_DOING /*-----------*/, Event::S12_MsgL41_ENDxxx, State::MsgL41_HAVEx /*-----------*/, Action::MsgL41_POST, Guard::None>,
                                   boost::msm::front::Row<State::MsgL50_DOING /*-----------*/, Event::S12_MsgL41_ENDxxx, State::None /*-------------------*/, Action::None /*--*/, Guard::None>,
                                   boost::msm::front::Row<State::MsgLxx_DOING_0_MsgL41_MsgL50, Event::S12_MsgL41_ENDxxx, State::None /*-------------------*/, Action::None /*--*/, Guard::Exception_FsmNoTransition /*-------*/>,
                                   boost::msm::front::Row<State::MsgLxx_DOING_0_MsgL41_MsgL50, Event::S12_MsgL41_ENDxxx, State::MsgL41_HAVEx /*-----------*/, Action::MsgL41_POST, Guard::B1_MsgClient_IsHaveReadeL41 /*-----*/>,
                                   boost::msm::front::Row<State::MsgLxx_DOING_0_MsgL41_MsgL50, Event::S12_MsgL41_ENDxxx, State::None /*-------------------*/, Action::None /*--*/, Guard::B2_MsgClient_IsHaveReadeL50 /*-----*/>,
                                   boost::msm::front::Row<State::MsgL42_WILLx /*-----------*/, Event::S13_MsgL42_BEGING, State::MsgL42_DOING /*-----------*/, Action::MsgL42_PREP, Guard::None>,
                                   boost::msm::front::Row<State::MsgL42_DOING /*-----------*/, Event::S14_MsgL42_ENDxxx, State::MsgL42_HAVEx /*-----------*/, Action::MsgL42_POST, Guard::None>,
                                   boost::msm::front::Row<State::MsgLxx_WILLx_0_MsgL41_MsgL50, Event::S15_MsgL50_BEGING, State::None /*-------------------*/, Action::None /*--*/, Guard::Exception_FsmNoTransition /*-------*/>,
                                   boost::msm::front::Row<State::MsgLxx_WILLx_0_MsgL41_MsgL50, Event::S15_MsgL50_BEGING, State::None /*-------------------*/, Action::None /*--*/, Guard::A1_MsgServer_IsWillWriteL41 /*-----*/>,
                                   boost::msm::front::Row<State::MsgLxx_WILLx_0_MsgL41_MsgL50, Event::S15_MsgL50_BEGING, State::MsgL50_DOING /*-----------*/, Action::MsgL50_PREP, Guard::A2_MsgServer_IsWillWriteL50 /*-----*/>,
                                   boost::msm::front::Row<State::MsgLxx_WILLx_0_MsgL41_MsgL50, Event::S15_MsgL50_BEGING, State::MsgLxx_DOING_0_MsgL41_MsgL50, Action::None /*--*/, Guard::A3_MsgClient_IsWillReadeLxx_0_L41_L50>,
                                   boost::msm::front::Row<State::MsgLxx_DOING_0_MsgL41_MsgL50, Event::S15_MsgL50_BEGING, State::None /*-------------------*/, Action::None /*--*/, Guard::None>,
                                   boost::msm::front::Row<State::MsgL41_DOING /*-----------*/, Event::S16_MsgL50_ENDxxx, State::None /*-------------------*/, Action::None /*--*/, Guard::None>,
                                   boost::msm::front::Row<State::MsgL50_DOING /*-----------*/, Event::S16_MsgL50_ENDxxx, State::MsgL50_HAVEx /*-----------*/, Action::MsgL50_POST, Guard::None>,
                                   boost::msm::front::Row<State::MsgLxx_DOING_0_MsgL41_MsgL50, Event::S16_MsgL50_ENDxxx, State::None /*-------------------*/, Action::None /*--*/, Guard::Exception_FsmNoTransition /*-------*/>,
                                   boost::msm::front::Row<State::MsgLxx_DOING_0_MsgL41_MsgL50, Event::S16_MsgL50_ENDxxx, State::None /*-------------------*/, Action::None /*--*/, Guard::B1_MsgClient_IsHaveReadeL41 /*-----*/>,
                                   boost::msm::front::Row<State::MsgLxx_DOING_0_MsgL41_MsgL50, Event::S16_MsgL50_ENDxxx, State::MsgL50_HAVEx /*-----------*/, Action::MsgL50_POST, Guard::B2_MsgClient_IsHaveReadeL50 /*-----*/>,
                                   // StateSource, Event, StateTarget, Action, Guard, - L60
                                   boost::msm::front::Row<State::MsgL60_WILLx, Event::S17_MsgL60_BEGING, State::MsgL60_DOING, Action::MsgL60_PREP, Guard::None>,
                                   boost::msm::front::Row<State::MsgL60_DOING, Event::S18_MsgL60_ENDxxx, State::MsgL60_HAVEx, Action::MsgL60_POST, Guard::None>,
                                   // StateSource, Event, StateTarget, Action, Guard, - LxxNext
                                   boost::msm::front::Row<State::MsgL10_HAVEx_ClientToServer, Event::Sxx_MsgLxx_MsgSeq_NEXT, State::MsgL10_WILLx_ServerToClient /*--*/, Action::None, Guard::None>,
                                   boost::msm::front::Row<State::MsgL10_HAVEx_ServerToClient, Event::Sxx_MsgLxx_MsgSeq_NEXT, State::MsgL20_WILLx /*-----------------*/, Action::None, Guard::None>,
                                   boost::msm::front::Row<State::MsgL20_HAVEx /*----------*/, Event::Sxx_MsgLxx_MsgSeq_NEXT, State::MsgL30_WILLx /*-----------------*/, Action::None, Guard::None>,
                                   boost::msm::front::Row<State::MsgL30_HAVEx /*----------*/, Event::Sxx_MsgLxx_MsgSeq_NEXT, State::MsgL40_WILLx /*-----------------*/, Action::None, Guard::None>,
                                   boost::msm::front::Row<State::MsgL40_HAVEx /*----------*/, Event::Sxx_MsgLxx_MsgSeq_NEXT, State::MsgLxx_WILLx_0_MsgL41_MsgL50 /*-*/, Action::None, Guard::None>,
                                   boost::msm::front::Row<State::MsgL41_HAVEx /*----------*/, Event::Sxx_MsgLxx_MsgSeq_NEXT, State::MsgL42_WILLx /*-----------------*/, Action::None, Guard::None>,
                                   boost::msm::front::Row<State::MsgL42_HAVEx /*----------*/, Event::Sxx_MsgLxx_MsgSeq_NEXT, State::MsgLxx_WILLx_0_MsgL41_MsgL50 /*-*/, Action::None, Guard::None>,
                                   boost::msm::front::Row<State::MsgL50_HAVEx /*----------*/, Event::Sxx_MsgLxx_MsgSeq_NEXT, State::MsgL60_WILLx /*-----------------*/, Action::None, Guard::None>,
                                   boost::msm::front::Row<State::MsgL60_HAVEx /*----------*/, Event::Sxx_MsgLxx_MsgSeq_NEXT, State::None /*-------------------------*/, Action::None, Guard::None>
                                   // ---
                                   > /**/
                               >;

  public:
    using FsmEvent = Event;
    using FsmState = State;
    using FsmBack = boost0::msm::FsmFactoryPlus_TUPLE<FsmMeta>::FsmBack;
};
