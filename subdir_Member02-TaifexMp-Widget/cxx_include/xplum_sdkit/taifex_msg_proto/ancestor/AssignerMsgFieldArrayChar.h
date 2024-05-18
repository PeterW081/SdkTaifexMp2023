#pragma once
#include "xplum/ancestor/AssignerArray.h"

namespace xplum_sdkit::taifex_msg_proto::ancestor::_nshdr {
using xplum::ancestor::AssignerArrayChar;

template <std::size_t VALUE_ARRAY_SIZE> using ArrayAlign = typename xplum::ancestor::AssignerArrayChar<VALUE_ARRAY_SIZE>::Align;

}

namespace xplum_sdkit::taifex_msg_proto::ancestor {
template <std::size_t VALUE_ARRAY_SIZE, char VALUE_ARRAY_FILL, _nshdr::ArrayAlign<VALUE_ARRAY_SIZE> VALUE_ARRAY_ALIGN> class AssignerMsgFieldArrayChar;
}

template <std::size_t VALUE_ARRAY_SIZE, char VALUE_ARRAY_FILL, typename xplum::ancestor::AssignerArrayChar<VALUE_ARRAY_SIZE>::Align VALUE_ARRAY_ALIGN>
class xplum_sdkit::taifex_msg_proto::ancestor::AssignerMsgFieldArrayChar : protected _nshdr::AssignerArrayChar<VALUE_ARRAY_SIZE> {
  using SUPER = _nshdr::AssignerArrayChar<VALUE_ARRAY_SIZE>;
  static const inline typename SUPER::AdvancedOption M_Advanced_Option = {
      .align = VALUE_ARRAY_ALIGN,
      .filler = VALUE_ARRAY_FILL,
  };

public:
  using Type = typename SUPER::Type;
  static inline const auto &M_SIZE = SUPER::M_SIZE;
  static const auto M_FILL = VALUE_ARRAY_FILL;
  static const auto M_ALIGN = VALUE_ARRAY_ALIGN;

  template <std::size_t RVALUE_ARRAY_SIZE> static auto Assign(Type (&lvariable)[M_SIZE], std::span<Type, RVALUE_ARRAY_SIZE> rvalue) -> std::size_t;
  template <std::size_t RVALUE_ARRAY_SIZE> static auto Assign(Type (&lvariable)[M_SIZE], const std::array<Type, RVALUE_ARRAY_SIZE> &rvalue) -> std::size_t;
  static auto Assign(Type (&lvariable)[M_SIZE], std::string_view rvalue) -> std::size_t;
};
