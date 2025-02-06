#pragma once
#include "./MkV3_MsgSessionLayerLxx_FsmSchema.h"
#pragma
#

/// ******************************** ******************************** ******************************** ******************************** ///
/// MkV3_MsgSessionLayerLxx_FsmElement::Event
#define MACRO_XPLUM_0_FSMEVENT_01(PARAM01_CLASS_NAME)                                                                                                                                                                                                          \
    struct                                          /**/                                                                                                                                                                                                       \
        xplum_sdkit::taifex_msg_proto::fsm_element::/**/                                                                                                                                                                                                       \
        MkV3_MsgSessionLayerLxx_FsmElement::Event::PARAM01_CLASS_NAME : Event_A                                                                                                                                                                                \
    {                                                                                                                                                                                                                                                          \
    };                                                                                                                                                                                                                                                         \
    /**/
#define MACRO_XPLUM_0_FSMEVENT_02(PARAM01_CLASS_NAME, PARAM02_SERVER_ACTION, PARAM03_CLIENT_ACTION)                                                                                                                                                            \
    struct                                          /**/                                                                                                                                                                                                       \
        xplum_sdkit::taifex_msg_proto::fsm_element::/**/                                                                                                                                                                                                       \
        MkV3_MsgSessionLayerLxx_FsmElement::Event::PARAM01_CLASS_NAME : Event_MsgProcessorContext_A0<PARAM02_SERVER_ACTION, PARAM03_CLIENT_ACTION>                                                                                                             \
    {                                                                                                                                                                                                                                                          \
        explicit PARAM01_CLASS_NAME(std::span<std::byte> span) : Event_MsgProcessorContext_A0(span)                                                                                                                                                            \
        {                                                                                                                                                                                                                                                      \
        }                                                                                                                                                                                                                                                      \
    };                                                                                                                                                                                                                                                         \
    /**/
#
// Event, ServerAction, ClientAction
MACRO_XPLUM_0_FSMEVENT_01(Sxx_MsgLxx_MsgSeq_NEXT /*-----*/)
MACRO_XPLUM_0_FSMEVENT_02(S01_MsgL10_BEGING_ClientToServer, EnumAction::NULL0, EnumAction::WRITE_PREP) // 【S<-C】BEGING
MACRO_XPLUM_0_FSMEVENT_02(S02_MsgL10_ENDxxx_ClientToServer, EnumAction::READE_POST, EnumAction::NULL0) // 【S<-C】ENDxxx
MACRO_XPLUM_0_FSMEVENT_02(S03_MsgL10_BEGING_ServerToClient, EnumAction::WRITE_PREP, EnumAction::NULL0) // 【S->C】BEGING
MACRO_XPLUM_0_FSMEVENT_02(S04_MsgL10_ENDxxx_ServerToClient, EnumAction::NULL0, EnumAction::READE_POST) // 【S->C】ENDxxx
MACRO_XPLUM_0_FSMEVENT_02(S05_MsgL20_BEGING /*----------*/, EnumAction::NULL0, EnumAction::WRITE_PREP) // 【S<-C】BEGING
MACRO_XPLUM_0_FSMEVENT_02(S06_MsgL20_ENDxxx /*----------*/, EnumAction::READE_POST, EnumAction::NULL0) // 【S<-C】ENDxxx
MACRO_XPLUM_0_FSMEVENT_02(S07_MsgL30_BEGING /*----------*/, EnumAction::WRITE_PREP, EnumAction::NULL0) // 【S->C】BEGING
MACRO_XPLUM_0_FSMEVENT_02(S08_MsgL30_ENDxxx /*----------*/, EnumAction::NULL0, EnumAction::READE_POST) // 【S->C】ENDxxx
MACRO_XPLUM_0_FSMEVENT_02(S09_MsgL40_BEGING /*----------*/, EnumAction::NULL0, EnumAction::WRITE_PREP) // 【S<-C】BEGING
MACRO_XPLUM_0_FSMEVENT_02(S10_MsgL40_ENDxxx /*----------*/, EnumAction::READE_POST, EnumAction::NULL0) // 【S<-C】ENDxxx
MACRO_XPLUM_0_FSMEVENT_02(S11_MsgL41_BEGING /*----------*/, EnumAction::WRITE_PREP, EnumAction::NULL0) // 【S->C】BEGING
MACRO_XPLUM_0_FSMEVENT_02(S12_MsgL41_ENDxxx /*----------*/, EnumAction::NULL0, EnumAction::READE_POST) // 【S->C】ENDxxx
MACRO_XPLUM_0_FSMEVENT_02(S13_MsgL42_BEGING /*----------*/, EnumAction::NULL0, EnumAction::WRITE_PREP) // 【S<-C】BEGING
MACRO_XPLUM_0_FSMEVENT_02(S14_MsgL42_ENDxxx /*----------*/, EnumAction::READE_POST, EnumAction::NULL0) // 【S<-C】ENDxxx
MACRO_XPLUM_0_FSMEVENT_02(S15_MsgL50_BEGING /*----------*/, EnumAction::WRITE_PREP, EnumAction::NULL0) // 【S->C】BEGING
MACRO_XPLUM_0_FSMEVENT_02(S16_MsgL50_ENDxxx /*----------*/, EnumAction::NULL0, EnumAction::READE_POST) // 【S->C】ENDxxx
MACRO_XPLUM_0_FSMEVENT_02(S17_MsgL60_BEGING /*----------*/, EnumAction::NULL0, EnumAction::WRITE_PREP) // 【S<-C】BEGING
MACRO_XPLUM_0_FSMEVENT_02(S18_MsgL60_ENDxxx /*----------*/, EnumAction::READE_POST, EnumAction::NULL0) // 【S<-C】ENDxxx
#
#undef MACRO_XPLUM_0_FSMEVENT_01
#undef MACRO_XPLUM_0_FSMEVENT_02

/// ******************************** ******************************** ******************************** ******************************** ///
/// MkV3_MsgSessionLayerLxx_FsmElement::State
#define MACRO_XPLUM_0_FSMSTATE_01(PARAM01_CLASS_NAME)                                                                                                                                                                                                          \
    struct                                          /**/                                                                                                                                                                                                       \
        xplum_sdkit::taifex_msg_proto::fsm_element::/**/                                                                                                                                                                                                       \
        MkV3_MsgSessionLayerLxx_FsmElement::State::PARAM01_CLASS_NAME : boost::msm::front::state<>,                                                                                                                                                            \
                                                                        State_A                                                                                                                                                                                \
    {                                                                                                                                                                                                                                                          \
    };                                                                                                                                                                                                                                                         \
    /**/
#define MACRO_XPLUM_0_FSMSTATE_02(PARAM01_CLASS_NAME, PARAM02_DIRECTION)                                                                                                                                                                                       \
    struct                                          /**/                                                                                                                                                                                                       \
        xplum_sdkit::taifex_msg_proto::fsm_element::/**/                                                                                                                                                                                                       \
        MkV3_MsgSessionLayerLxx_FsmElement::State::PARAM01_CLASS_NAME : boost::msm::front::state<>,                                                                                                                                                            \
                                                                        State_MsgTransferDirection_A<PARAM02_DIRECTION>                                                                                                                                        \
    {                                                                                                                                                                                                                                                          \
    };                                                                                                                                                                                                                                                         \
    /**/
#
MACRO_XPLUM_0_FSMSTATE_01(MsgL10_WILLx_ClientToServer)
MACRO_XPLUM_0_FSMSTATE_02(MsgL10_DOING_ClientToServer, EnumDirection::CLIENT_TO_SERVER) // 【S<-C】
MACRO_XPLUM_0_FSMSTATE_01(MsgL10_HAVEx_ClientToServer)
MACRO_XPLUM_0_FSMSTATE_01(MsgL10_WILLx_ServerToClient)
MACRO_XPLUM_0_FSMSTATE_02(MsgL10_DOING_ServerToClient, EnumDirection::SERVER_TO_CLIENT) // 【S<-C】
MACRO_XPLUM_0_FSMSTATE_01(MsgL10_HAVEx_ServerToClient)
MACRO_XPLUM_0_FSMSTATE_01(MsgL20_WILLx /*----------*/)
MACRO_XPLUM_0_FSMSTATE_02(MsgL20_DOING /*----------*/, EnumDirection::CLIENT_TO_SERVER) // 【S<-C】
MACRO_XPLUM_0_FSMSTATE_01(MsgL20_HAVEx /*----------*/)
MACRO_XPLUM_0_FSMSTATE_01(MsgL30_WILLx /*----------*/)
MACRO_XPLUM_0_FSMSTATE_02(MsgL30_DOING /*----------*/, EnumDirection::SERVER_TO_CLIENT) // 【S<-C】
MACRO_XPLUM_0_FSMSTATE_01(MsgL30_HAVEx /*----------*/)
MACRO_XPLUM_0_FSMSTATE_01(MsgL40_WILLx /*----------*/)
MACRO_XPLUM_0_FSMSTATE_02(MsgL40_DOING /*----------*/, EnumDirection::CLIENT_TO_SERVER) // 【S<-C】
MACRO_XPLUM_0_FSMSTATE_01(MsgL40_HAVEx /*----------*/)
MACRO_XPLUM_0_FSMSTATE_02(MsgL41_DOING /*----------*/, EnumDirection::SERVER_TO_CLIENT) // 【S<-C】
MACRO_XPLUM_0_FSMSTATE_01(MsgL41_HAVEx /*----------*/)
MACRO_XPLUM_0_FSMSTATE_01(MsgL42_WILLx /*----------*/)
MACRO_XPLUM_0_FSMSTATE_02(MsgL42_DOING /*----------*/, EnumDirection::CLIENT_TO_SERVER) // 【S<-C】
MACRO_XPLUM_0_FSMSTATE_01(MsgL42_HAVEx /*----------*/)
MACRO_XPLUM_0_FSMSTATE_02(MsgL50_DOING /*----------*/, EnumDirection::SERVER_TO_CLIENT) // 【S<-C】
MACRO_XPLUM_0_FSMSTATE_01(MsgL50_HAVEx /*----------*/)
MACRO_XPLUM_0_FSMSTATE_01(MsgL60_WILLx /*----------*/)
MACRO_XPLUM_0_FSMSTATE_02(MsgL60_DOING /*----------*/, EnumDirection::CLIENT_TO_SERVER) // 【S<-C】
MACRO_XPLUM_0_FSMSTATE_01(MsgL60_HAVEx /*----------*/)
MACRO_XPLUM_0_FSMSTATE_01(MsgLxx_WILLx_0_MsgL41_MsgL50)
MACRO_XPLUM_0_FSMSTATE_02(MsgLxx_DOING_0_MsgL41_MsgL50, EnumDirection::SERVER_TO_CLIENT) // 【S<-C】
#
#undef MACRO_XPLUM_0_FSMSTATE_01
#undef MACRO_XPLUM_0_FSMSTATE_02

/// ******************************** ******************************** ******************************** ******************************** ///
/// MkV3_MsgSessionLayerLxx_FsmElement::Action
#define MACRO_XPLUM_0_FSMACTION_01(PARAM01_CLASS_NAME)                                                                                                                                                                                                         \
    struct                                          /**/                                                                                                                                                                                                       \
        xplum_sdkit::taifex_msg_proto::fsm_element::/**/                                                                                                                                                                                                       \
        MkV3_MsgSessionLayerLxx_FsmElement::Action::PARAM01_CLASS_NAME                                                                                                                                                                                         \
    {                                                                                                                                                                                                                                                          \
        auto operator()(Event_MsgProcessorContext_A const &, MachineFront &, State_A &, State_A &) -> void;                                                                                                                                                    \
    };                                                                                                                                                                                                                                                         \
    /**/
#
MACRO_XPLUM_0_FSMACTION_01(MsgL10_PREP_ClientToServer)
MACRO_XPLUM_0_FSMACTION_01(MsgL10_POST_ClientToServer)
MACRO_XPLUM_0_FSMACTION_01(MsgL10_PREP_ServerToClient)
MACRO_XPLUM_0_FSMACTION_01(MsgL10_POST_ServerToClient)
MACRO_XPLUM_0_FSMACTION_01(MsgL20_PREP)
MACRO_XPLUM_0_FSMACTION_01(MsgL20_POST)
MACRO_XPLUM_0_FSMACTION_01(MsgL30_PREP)
MACRO_XPLUM_0_FSMACTION_01(MsgL30_POST)
MACRO_XPLUM_0_FSMACTION_01(MsgL40_PREP)
MACRO_XPLUM_0_FSMACTION_01(MsgL40_POST)
MACRO_XPLUM_0_FSMACTION_01(MsgL41_PREP)
MACRO_XPLUM_0_FSMACTION_01(MsgL41_POST)
MACRO_XPLUM_0_FSMACTION_01(MsgL42_PREP)
MACRO_XPLUM_0_FSMACTION_01(MsgL42_POST)
MACRO_XPLUM_0_FSMACTION_01(MsgL50_PREP)
MACRO_XPLUM_0_FSMACTION_01(MsgL50_POST)
MACRO_XPLUM_0_FSMACTION_01(MsgL60_PREP)
MACRO_XPLUM_0_FSMACTION_01(MsgL60_POST)
#
#undef MACRO_XPLUM_0_FSMACTION_01

/// ******************************** ******************************** ******************************** ******************************** ///
/// MkV3_MsgSessionLayerLxx_FsmElement::Guard
#define MACRO_XPLUM_0_FSMGUARD_01(PARAM01_CLASS_NAME)                                                                                                                                                                                                          \
    struct                                          /**/                                                                                                                                                                                                       \
        xplum_sdkit::taifex_msg_proto::fsm_element::/**/                                                                                                                                                                                                       \
        MkV3_MsgSessionLayerLxx_FsmElement::Guard::PARAM01_CLASS_NAME                                                                                                                                                                                          \
    {                                                                                                                                                                                                                                                          \
        auto operator()(Event_MsgProcessorContext_A const &, MachineFront &, State_A &, State_A &) -> bool;                                                                                                                                                    \
    };                                                                                                                                                                                                                                                         \
    /**/
#
MACRO_XPLUM_0_FSMGUARD_01(A1_MsgServer_IsWillWriteL41)
MACRO_XPLUM_0_FSMGUARD_01(A2_MsgServer_IsWillWriteL50)
MACRO_XPLUM_0_FSMGUARD_01(A3_MsgClient_IsWillReadeLxx_0_L41_L50)
MACRO_XPLUM_0_FSMGUARD_01(B1_MsgClient_IsHaveReadeL41)
MACRO_XPLUM_0_FSMGUARD_01(B2_MsgClient_IsHaveReadeL50)
#
#undef MACRO_XPLUM_0_FSMGUARD_01
