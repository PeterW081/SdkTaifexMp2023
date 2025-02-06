#pragma once
#include "./MkV3_MsgSessionLayerALL_FsmSchema.h"
#pragma
#

/// ******************************** ******************************** ******************************** ******************************** ///
/// MkV3_MsgSessionLayerALL_FsmElement::Event
#define MACRO_XPLUM_0_FSMEVENT_01(PARAM01_CLASS_NAME)                                                                                                                                                                                                          \
    struct                                          /**/                                                                                                                                                                                                       \
        xplum_sdkit::taifex_msg_proto::fsm_element::/**/                                                                                                                                                                                                       \
        MkV3_MsgSessionLayerALL_FsmElement::Event::PARAM01_CLASS_NAME : Event_A                                                                                                                                                                                \
    {                                                                                                                                                                                                                                                          \
    };                                                                                                                                                                                                                                                         \
    /**/
// Event, ServerAction, ClientAction
MACRO_XPLUM_0_FSMEVENT_01(Sxx_MsgLayer_NEXT /*-----------------------*/)
MACRO_XPLUM_0_FSMEVENT_01(Sxx_MsgLayer_REDO_AFTER_MsgL10_ClientToServer)
MACRO_XPLUM_0_FSMEVENT_01(Sxx_MsgLayer_REDO_AFTER_MsgL10_ServerToClient)
#
#undef MACRO_XPLUM_0_FSMEVENT_01
