#include_next "xplum_sdkit/taifex_msg_proto/ancestor/AssignerMsgFieldArrayChar.h"
#pragma once

template <std::size_t TP01, char TP02, typename xplum::ancestor::AssignerArrayChar<TP01>::Align TP03>
template <std::size_t RVALUE_ARRAY_SIZE>
auto xplum_sdkit::taifex_msg_proto::ancestor::AssignerMsgFieldArrayChar<TP01, TP02, TP03>::Assign(Type (&lvariable)[M_SIZE], std::span<Type, RVALUE_ARRAY_SIZE> rvalue) -> std::size_t {
  if constexpr (RVALUE_ARRAY_SIZE == M_SIZE) {
    return SUPER::Assign(lvariable, rvalue);
  }
  if constexpr (RVALUE_ARRAY_SIZE == std::dynamic_extent) {
    if (rvalue.size() == M_SIZE) {
      return SUPER::Assign(lvariable, rvalue);
    }
  }
  return SUPER::Advanced_Assign(static_cast<const typename SUPER::AdvancedOption &&>(M_Advanced_Option), lvariable, rvalue);
}

template <std::size_t TP01, char TP02, typename xplum::ancestor::AssignerArrayChar<TP01>::Align TP03>
template <std::size_t RVALUE_ARRAY_SIZE>
auto xplum_sdkit::taifex_msg_proto::ancestor::AssignerMsgFieldArrayChar<TP01, TP02, TP03>::Assign(Type (&lvariable)[M_SIZE], const std::array<Type, RVALUE_ARRAY_SIZE> &rvalue) -> std::size_t {
  return Assign(lvariable, std::span<Type, RVALUE_ARRAY_SIZE>(const_cast<Type *>(rvalue.data()), RVALUE_ARRAY_SIZE));
}

template <std::size_t TP01, char TP02, typename xplum::ancestor::AssignerArrayChar<TP01>::Align TP03>
auto xplum_sdkit::taifex_msg_proto::ancestor::AssignerMsgFieldArrayChar<TP01, TP02, TP03>::Assign(Type (&lvariable)[M_SIZE], std::string_view rvalue) -> std::size_t {
  return Assign(lvariable, std::span(const_cast<Type *>(rvalue.data()), rvalue.size()));
}
