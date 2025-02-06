#pragma once
#include "./AssignerMsgFieldArrayChar.h"
#pragma
#

template <std::size_t TP01, char TP02, typename xplum::ancestor::AssignerArrayChar<TP01>::Align TP03>
template <std::size_t RVALUE_array_size>
auto                                              //
    xplum_sdkit::taifex_msg_proto::ancestor::     //
    AssignerMsgFieldArrayChar<TP01, TP02, TP03>:: //
    FX_assign(Type (&lvariable)[M_size], const std::span<Type, RVALUE_array_size> rvalue) -> std::size_t
{
    if constexpr (RVALUE_array_size == M_size)
    {
        return SUPER::Assign(lvariable, rvalue);
    }
    if constexpr (RVALUE_array_size == std::dynamic_extent)
    {
        if (rvalue.size() == M_size)
        {
            return SUPER::Assign(lvariable, rvalue);
        }
    }
    return SUPER::Advanced_Assign(static_cast<const typename SUPER::AdvancedOption &&>(M_Advanced_Option), lvariable, rvalue);
}

template <std::size_t TP01, char TP02, typename xplum::ancestor::AssignerArrayChar<TP01>::Align TP03>
template <std::size_t RVALUE_array_size>
auto                                              //
    xplum_sdkit::taifex_msg_proto::ancestor::     //
    AssignerMsgFieldArrayChar<TP01, TP02, TP03>:: //
    FX_assign(Type (&lvariable)[M_size], const std::array<Type, RVALUE_array_size> &rvalue) -> std::size_t
{
    return FX_assign(lvariable, std::span<Type, RVALUE_array_size>(const_cast<Type *>(rvalue.data()), RVALUE_array_size));
}

template <std::size_t TP01, char TP02, typename xplum::ancestor::AssignerArrayChar<TP01>::Align TP03>
auto                                              //
    xplum_sdkit::taifex_msg_proto::ancestor::     //
    AssignerMsgFieldArrayChar<TP01, TP02, TP03>:: //
    FX_assign(Type (&lvariable)[M_size], const std::string_view rvalue) -> std::size_t
{
    return FX_assign(lvariable, std::span(const_cast<Type *>(rvalue.data()), rvalue.size()));
}
