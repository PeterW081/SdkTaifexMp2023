#pragma once
#include "./AssignerMsgFieldArrayChar.h"
#pragma
#include "xplum/ancestor/AssignerArray.h"
#

namespace xplum_sdkit::taifex_msg_proto::ancestor::_nshdr
{
using xplum::ancestor::AssignerArrayChar;

template <std::size_t VALUE_array_size>
using ArrayAlign = typename xplum::ancestor::AssignerArrayChar<VALUE_array_size>::Align;

}

namespace xplum_sdkit::taifex_msg_proto::ancestor
{
template <std::size_t VALUE_array_size, char VALUE_array_fill, _nshdr::ArrayAlign<VALUE_array_size> VALUE_array_align>
class AssignerMsgFieldArrayChar;
}

template <std::size_t VALUE_array_size, char VALUE_array_fill, typename xplum::ancestor::AssignerArrayChar<VALUE_array_size>::Align VALUE_array_align>
class xplum_sdkit::taifex_msg_proto::ancestor::AssignerMsgFieldArrayChar : protected _nshdr::AssignerArrayChar<VALUE_array_size>
{
    using SUPER = _nshdr::AssignerArrayChar<VALUE_array_size>;
    static const inline typename SUPER::AdvancedOption M_Advanced_Option = {
        .align = VALUE_array_align,
        .filler = VALUE_array_fill,
    };

  public:
    using Type = typename SUPER::Type;
    static inline const auto &M_size = SUPER::M_SIZE;
    static const auto M_fill = VALUE_array_fill;
    static const auto M_align = VALUE_array_align;

    template <std::size_t RVALUE_array_size>
    static auto FX_assign(Type (&lvariable)[M_size], const std::span<Type, RVALUE_array_size> rvalue) -> std::size_t;
    template <std::size_t RVALUE_array_size>
    static auto FX_assign(Type (&lvariable)[M_size], const std::array<Type, RVALUE_array_size> &rvalue) -> std::size_t;
    static auto FX_assign(Type (&lvariable)[M_size], const std::string_view rvalue) -> std::size_t;
};
