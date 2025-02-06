#pragma once
#include <span>
#include "boost0/asio/_define_cxx.h"
#include "boost0/msm/FsmFactoryPlus.h"
#include "xplum_sdkit/taifex_msg_proto/network_osi_L05/partition_msg_session/MsgSessionMsgProcessor.h"
#

namespace xplum_sdkit::taifex_msg_proto::fsm_element
{
struct MkV3_MsgSession_FsmElementCommon;
}

/// ******************************** ******************************** ******************************** ******************************** ///
#define nshdr_root xplum_sdkit::taifex_msg_proto::fsm_element
#

/// ******************************** ******************************** ******************************** ******************************** ///
/// MkV3_MsgSession_FsmElementCommon
// X class
struct                                           //
    xplum_sdkit::taifex_msg_proto::fsm_element:: //
    MkV3_MsgSession_FsmElementCommon             //
{
    using EnumSide = ext::boost_asio0::EnumTcpEndpointSide;
    using EnumAction = ext::boost_asio0::EnumTcpSocketAction;
    using EnumDirection = ext::boost_asio0::EnumTcpTransferDirection;
    //
    struct Event_A;
    struct Event_MsgProcessorContext_A;
    template <EnumAction, EnumAction>
    struct Event_MsgProcessorContext_A0;
    struct State_A;
    template <EnumDirection>
    struct State_MsgTransferDirection_A;
    //
    struct State_0_TODO;
    struct Action_0_TODO;
    struct Guard_0_Exception_FsmNoTransition;
    template <typename, std::uint8_t = 0>
    struct Guard_0_Assert_StateSource_SubfsmCurrentState;
    struct MachineFront;
};

/// ******************************** ******************************** ******************************** ******************************** ///
/// MkV3_MsgSession_FsmElementCommon::Event_A
// X class
struct                                           //
    xplum_sdkit::taifex_msg_proto::fsm_element:: //
    MkV3_MsgSession_FsmElementCommon::Event_A    //
{
};
struct                                                                      //
    xplum_sdkit::taifex_msg_proto::fsm_element::                            //
    MkV3_MsgSession_FsmElementCommon::Event_MsgProcessorContext_A : Event_A //
{
    std::span<std::byte> const m_span;
    EnumAction const m_server_action;
    EnumAction const m_client_action;
    explicit Event_MsgProcessorContext_A(std::span<std::byte>, EnumAction, EnumAction); // span, server_action, client_action,
};
template <nshdr_root::MkV3_MsgSession_FsmElementCommon::EnumAction ENUM_server_action, nshdr_root::MkV3_MsgSession_FsmElementCommon::EnumAction ENUM_client_action>
struct                                                                                           //
    xplum_sdkit::taifex_msg_proto::fsm_element::                                                 //
    MkV3_MsgSession_FsmElementCommon::Event_MsgProcessorContext_A0 : Event_MsgProcessorContext_A //
{
    explicit Event_MsgProcessorContext_A0(std::span<std::byte>); // span
};
// X function
template <nshdr_root::MkV3_MsgSession_FsmElementCommon::EnumAction ENUM_server_action, nshdr_root::MkV3_MsgSession_FsmElementCommon::EnumAction ENUM_client_action>
inline /*Constructor*/                                                                                       //
    xplum_sdkit::taifex_msg_proto::fsm_element::                                                             //
    MkV3_MsgSession_FsmElementCommon::Event_MsgProcessorContext_A0<ENUM_server_action, ENUM_client_action>:: //
    Event_MsgProcessorContext_A0(std::span<std::byte> span)
    : Event_MsgProcessorContext_A(span, ENUM_server_action, ENUM_client_action)
{
}
#if (true)
// X function - head.h inline
inline /*Constructor*/                                              //
    xplum_sdkit::taifex_msg_proto::fsm_element::                    //
    MkV3_MsgSession_FsmElementCommon::Event_MsgProcessorContext_A:: //
    Event_MsgProcessorContext_A(std::span<std::byte> span, EnumAction server_action, EnumAction client_action)
    : m_span(span), m_server_action(server_action), m_client_action(client_action)
{
}
#endif

/// ******************************** ******************************** ******************************** ******************************** ///
/// MkV3_MsgSession_FsmElementCommon::State_A
struct                                           //
    xplum_sdkit::taifex_msg_proto::fsm_element:: //
    MkV3_MsgSession_FsmElementCommon::State_A    //
{
};
template <nshdr_root::MkV3_MsgSession_FsmElementCommon::EnumDirection>
struct                                                                       //
    xplum_sdkit::taifex_msg_proto::fsm_element::                             //
    MkV3_MsgSession_FsmElementCommon::State_MsgTransferDirection_A : State_A //
{
};

/// ******************************** ******************************** ******************************** ******************************** ///
/// MkV3_MsgSession_FsmElementCommon::State_0
// X class
struct                                           //
    xplum_sdkit::taifex_msg_proto::fsm_element:: //
    MkV3_MsgSession_FsmElementCommon::State_0_TODO : boost::msm::front::state<>
{
    auto on_entry(auto const &, auto &) -> void;
};
// X function
auto                                                 //
    xplum_sdkit::taifex_msg_proto::fsm_element::     //
    MkV3_MsgSession_FsmElementCommon::State_0_TODO:: //
    on_entry(auto const &, auto &) -> void
{
    std::cout << "LOG_MSG_8A23DA87: boost_msm, fsm, todo...," << std::endl;
}

/// ******************************** ******************************** ******************************** ******************************** ///
/// MkV3_MsgSession_FsmElementCommon::Action_0_
// X class
struct                                           //
    xplum_sdkit::taifex_msg_proto::fsm_element:: //
    MkV3_MsgSession_FsmElementCommon::Action_0_TODO
{
    auto operator()(auto const &, auto &, auto &, auto &) -> void;
};
// X function
auto                                                  //
    xplum_sdkit::taifex_msg_proto::fsm_element::      //
    MkV3_MsgSession_FsmElementCommon::Action_0_TODO:: //
    operator()(auto const &, auto &, auto &, auto &) -> void
{
    throw std::runtime_error("EXCEPTION_MSG_8A23DA87: boost_msm, fsm, todo...,");
}

/// ******************************** ******************************** ******************************** ******************************** ///
/// MkV3_MsgSession_FsmElementCommon::Guard_0_
// X class
struct                                           //
    xplum_sdkit::taifex_msg_proto::fsm_element:: //
    MkV3_MsgSession_FsmElementCommon::Guard_0_Exception_FsmNoTransition
{
    auto operator()(auto const &, auto &, auto &, auto &) -> bool;
};
template <typename, std::uint8_t>
struct                                           //
    xplum_sdkit::taifex_msg_proto::fsm_element:: //
    MkV3_MsgSession_FsmElementCommon::Guard_0_Assert_StateSource_SubfsmCurrentState
{
    auto operator()(auto const &, auto &, auto &, auto &) -> bool;
};
// X function
auto                                                                      //
    xplum_sdkit::taifex_msg_proto::fsm_element::                          //
    MkV3_MsgSession_FsmElementCommon::Guard_0_Exception_FsmNoTransition:: //
    operator()(auto const &, auto &, auto &, auto &) -> bool
{
    throw std::runtime_error("EXCEPTION_MSG_83D40998: boost_msm, fsm, no_transition,");
    return false;
}
template <typename TYPE_subfsm_state, std::uint8_t VARLE_index>
auto                                                                                                                  //
    xplum_sdkit::taifex_msg_proto::fsm_element::                                                                      //
    MkV3_MsgSession_FsmElementCommon::Guard_0_Assert_StateSource_SubfsmCurrentState<TYPE_subfsm_state, VARLE_index>:: //
    operator()(auto const &, auto &, auto &state_source_0_subfsm, auto &) -> bool
{
    return (state_source_0_subfsm.get_state_by_id(state_source_0_subfsm.current_state()[VARLE_index]) == state_source_0_subfsm.template get_state<TYPE_subfsm_state *>());
}

/// ******************************** ******************************** ******************************** ******************************** ///
/// MkV3_MsgSession_FsmElementCommon::MachineFront
// X class
struct                                           //
    xplum_sdkit::taifex_msg_proto::fsm_element:: //
    MkV3_MsgSession_FsmElementCommon::MachineFront : boost::msm::front::state_machine_def<MachineFront>
{
    friend struct MkV3_MsgSessionLayerLxx_FsmElement;

  public:
    // BoostMsm
    auto on_entry(auto const &, auto &) -> void;
    auto no_transition(auto const &, auto &, int) -> void;
    auto exception_caught(auto const &, auto &, std::exception &e) -> void;
    // ---
    template <EnumSide, typename> // ENUM_side, TYPE_fsm_state
    static constexpr auto FX_deduce_msg_socket_action() -> EnumAction;
    auto fx_init(std::shared_ptr<util::MsgSessionMsgProcessor>, bool = false) -> void; // msg_processor, is_force_reinit,
  private:
    bool m_is_init = false;
    struct
    {
        std::shared_ptr<util::MsgSessionMsgProcessor> m_msg_processor;
    } m_fsm_context;
};
// X function - BoostMsm
auto                                                 //
    xplum_sdkit::taifex_msg_proto::fsm_element::     //
    MkV3_MsgSession_FsmElementCommon::MachineFront:: //
    on_entry(auto const &, auto &fsm) -> void
{
    if (std::is_base_of_v<MachineFront, std::remove_reference_t<decltype(fsm)>> && this != &fsm)
    {
        this->fx_init(static_cast<MachineFront &>(fsm).m_fsm_context.m_msg_processor, true);
    }
    if (not this->m_is_init)
    {
        throw std::runtime_error("EXCEPTION_MSG_B814884D: boost_msm, fsm, no_init,");
    }
    assert(this->m_is_init);
}
auto                                                 //
    xplum_sdkit::taifex_msg_proto::fsm_element::     //
    MkV3_MsgSession_FsmElementCommon::MachineFront:: //
    no_transition(auto const &, auto &, int) -> void
{
    throw std::runtime_error("EXCEPTION_MSG_B828A089: boost_msm, fsm, no_transition,");
}
auto                                                 //
    xplum_sdkit::taifex_msg_proto::fsm_element::     //
    MkV3_MsgSession_FsmElementCommon::MachineFront:: //
    exception_caught(auto const &, auto &, std::exception &e) -> void
{
    std::exception_ptr ptr = std::current_exception();
    std::rethrow_exception(ptr);
}
// X function - Other
template <nshdr_root::MkV3_MsgSession_FsmElementCommon::EnumSide ENUM_side, typename TYPE_fsm_state>
constexpr auto                                       //
    xplum_sdkit::taifex_msg_proto::fsm_element::     //
    MkV3_MsgSession_FsmElementCommon::MachineFront:: //
    FX_deduce_msg_socket_action() -> EnumAction
{
    static_assert(std::derived_from<TYPE_fsm_state, State_MsgTransferDirection_A<EnumDirection::SERVER_TO_CLIENT>> || std::derived_from<TYPE_fsm_state, State_MsgTransferDirection_A<EnumDirection::CLIENT_TO_SERVER>>);
    auto action = EnumAction::NULL0;
    if constexpr (std::derived_from<TYPE_fsm_state, State_MsgTransferDirection_A<EnumDirection::SERVER_TO_CLIENT>>)
    {
        if constexpr (ENUM_side == EnumSide::SERVER)
        {
            action = EnumAction::WRITE;
        }
        if constexpr (ENUM_side == EnumSide::CLIENT)
        {
            action = EnumAction::READE;
        }
    }
    if constexpr (std::derived_from<TYPE_fsm_state, State_MsgTransferDirection_A<EnumDirection::CLIENT_TO_SERVER>>)
    {
        if constexpr (ENUM_side == EnumSide::SERVER)
        {
            action = EnumAction::READE;
        }
        if constexpr (ENUM_side == EnumSide::CLIENT)
        {
            action = EnumAction::WRITE;
        }
    }
    return action;
}
#if (true)
// X function - head.h inline
inline auto                                          //
    xplum_sdkit::taifex_msg_proto::fsm_element::     //
    MkV3_MsgSession_FsmElementCommon::MachineFront:: //
    fx_init(std::shared_ptr<util::MsgSessionMsgProcessor> msg_processor, bool is_force_reinit) -> void
{
    if (this->m_is_init && not is_force_reinit)
    {
        return;
    }
    this->m_fsm_context.m_msg_processor = msg_processor;
    this->m_is_init = true;
}
#endif

/// ******************************** ******************************** ******************************** ******************************** ///
#
#undef nshdr_root
