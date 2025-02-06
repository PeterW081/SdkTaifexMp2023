#pragma once
#include <boost/fusion/algorithm.hpp>
#include <boost/msm/front/functor_row.hpp>
#include <boost/msm/front/state_machine_def.hpp>
#include <boost/msm/back/state_machine.hpp>
#

namespace boost0::msm
{
template <typename, typename, typename>
struct FsmFactoryPlus;
template <typename TUPLE>
using FsmFactoryPlus_TUPLE = FsmFactoryPlus<std::tuple_element_t<0, TUPLE>, std::tuple_element_t<1, TUPLE>, std::tuple_element_t<2, TUPLE>>;
}

/// FsmFactory
template <typename, typename, typename>
struct            //
    boost0::msm:: //
    FsmFactoryPlus
{
  private:
    struct FsmFront;

  public:
    struct FsmBack;
};

/// FsmFactory::FsmFront
template <typename TYPE01_FsmFrontCustom, typename TYPE02_FsmInitialState, typename TYPE03_FsmTransitionTable>
struct            //
    boost0::msm:: //
    FsmFactoryPlus<TYPE01_FsmFrontCustom, TYPE02_FsmInitialState, TYPE03_FsmTransitionTable>::FsmFront : TYPE01_FsmFrontCustom
{
    static_assert(std::derived_from<TYPE01_FsmFrontCustom, boost::msm::front::state_machine_def<TYPE01_FsmFrontCustom>>);
    using initial_state = TYPE02_FsmInitialState;
    using transition_table = TYPE03_FsmTransitionTable;
};

/// FsmFactory::FsmBack
template <typename TYPE01_FsmFrontCustom, typename TYPE02_FsmInitialState, typename TYPE03_FsmTransitionTable>
struct            //
    boost0::msm:: //
    FsmFactoryPlus<TYPE01_FsmFrontCustom, TYPE02_FsmInitialState, TYPE03_FsmTransitionTable>::FsmBack : boost::msm::back::state_machine<FsmFront>
{
    template <typename>
    auto fx_assert_current_state(int = 0) -> bool;
    template <typename, typename>
    auto fx_assert_current_state(int = 0) -> bool;
};

/// FsmFactory::FsmBack - fx_xxx()
template <typename T1, typename T2, typename T3>
template <typename TYPE_fsm_state>
auto                                      //
    boost0::msm::                         //
    FsmFactoryPlus<T1, T2, T3>::FsmBack:: //
    fx_assert_current_state(int index) -> bool
{
    return this->get_state_by_id(this->current_state()[index]) == this->template get_state<TYPE_fsm_state *>();
}
template <typename T1, typename T2, typename T3>
template <typename TYPE_subfsm, typename TYPE_subfsm_state>
auto                                      //
    boost0::msm::                         //
    FsmFactoryPlus<T1, T2, T3>::FsmBack:: //
    fx_assert_current_state(int index) -> bool
{
    auto &fsm = *this;
    if (fsm.get_state_by_id(fsm.current_state()[index]) == fsm.template get_state<TYPE_subfsm *>())
    {
        auto &subfsm = *(static_cast<TYPE_subfsm *>(fsm.get_state_by_id(fsm.current_state()[index])));
        return (subfsm.get_state_by_id(subfsm.current_state()[index]) == subfsm.template get_state<TYPE_subfsm_state *>());
    }
    else
    {
        return false;
    }
}
