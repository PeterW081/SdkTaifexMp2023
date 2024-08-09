#pragma once
#include <span>

namespace xplum::ancestor
{
template <typename TYPENAME_ARRAY_TYPE, std::size_t VALUE_ARRAY_SIZE> class AssignerArray;

template <std::size_t VALUE_ARRAY_SIZE> class AssignerArrayChar;
}

template <typename TYPENAME_ARRAY_TYPE, std::size_t VALUE_ARRAY_SIZE> class xplum::ancestor::AssignerArray
{
public:
  enum class Align : bool;
  struct AdvancedOption;
  using Type = TYPENAME_ARRAY_TYPE;
  using AncestorType = Type[VALUE_ARRAY_SIZE];

public:
  static const auto M_SIZE = VALUE_ARRAY_SIZE;
  static std::size_t Fill (Type (&lvariable)[M_SIZE], Type filler);                                                                         // 回傳處理個數。
  template <std::size_t RVALUE_ARRAY_SIZE>                                                                                                  // template<>
  static std::size_t Assign (Type (&lvariable)[M_SIZE], std::span<Type, RVALUE_ARRAY_SIZE> rvalue);                                         // 回傳處理個數。
  template <std::size_t RVALUE_ARRAY_SIZE>                                                                                                  // template<>
  static std::size_t Advanced_Assign (const AdvancedOption &&option, Type (&lvariable)[M_SIZE], std::span<Type, RVALUE_ARRAY_SIZE> rvalue); // 回傳處理個數。
};

template <std::size_t VALUE_ARRAY_SIZE> class xplum::ancestor::AssignerArrayChar : public AssignerArray<char, VALUE_ARRAY_SIZE>
{
  using SUPER = AssignerArray<char, VALUE_ARRAY_SIZE>;

public:
  using Type = typename SUPER::Type;
  using AncestorType = typename SUPER::AncestorType;

public:
  static const auto M_SIZE = SUPER::M_SIZE;

  template <std::size_t RVALUE_ARRAY_SIZE> static std::size_t Assign (Type (&lvariable)[M_SIZE], std::span<Type, RVALUE_ARRAY_SIZE> rvalue);
  template <std::size_t RVALUE_ARRAY_SIZE> static std::size_t Advanced_Assign (const typename SUPER::AdvancedOption &&option, Type (&lvariable)[M_SIZE], std::span<Type, RVALUE_ARRAY_SIZE> rvalue);

  static std::size_t Assign (Type (&lvariable)[M_SIZE], std::string_view rvalue);
  static std::size_t Advanced_Assign (const typename SUPER::AdvancedOption &&option, Type (&lvariable)[M_SIZE], std::string_view rvalue);
};

// ******************************** ******************************** ******************************** ******************************** //
template <typename T01, std::size_t V02>
enum class xplum::ancestor::AssignerArray<T01, V02>::Align : bool //
{                                                                 //
  ALIGN_LEFT = true,
  ALIGN_RIGHT = false,
};

template <typename T01, std::size_t V02> struct xplum::ancestor::AssignerArray<T01, V02>::AdvancedOption
{
  Align align = Align::ALIGN_LEFT;
  std::optional<Type> filler = std::nullopt;
};

// ******************************** ******************************** ******************************** ******************************** //
// AssignerArray
template <typename T01, std::size_t V02>
auto
xplum::ancestor::AssignerArray<T01, V02>::Fill (Type (&lvariable)[M_SIZE], Type filler) -> std::size_t
{
  std::memset (lvariable, filler, M_SIZE);
  return M_SIZE;
}

template <typename T01, std::size_t V02>
template <std::size_t RVALUE_ARRAY_SIZE>
auto
xplum::ancestor::AssignerArray<T01, V02>::Assign (Type (&lvariable)[M_SIZE], std::span<Type, RVALUE_ARRAY_SIZE> rvalue) -> std::size_t
{
  static_assert (RVALUE_ARRAY_SIZE <= M_SIZE || RVALUE_ARRAY_SIZE == std::dynamic_extent);

  std::size_t rvalue_array_size;
  if constexpr (RVALUE_ARRAY_SIZE <= M_SIZE)
    {
      rvalue_array_size = RVALUE_ARRAY_SIZE;
    }
  if constexpr (RVALUE_ARRAY_SIZE == std::dynamic_extent)
    {
      assert (rvalue.size () <= M_SIZE);
      rvalue_array_size = rvalue.size ();
    }

  std::memcpy (lvariable, rvalue.data (), rvalue_array_size);
  return rvalue_array_size;
}

template <typename T01, std::size_t V02>
template <std::size_t RVALUE_ARRAY_SIZE>
auto
xplum::ancestor::AssignerArray<T01, V02>::Advanced_Assign (const AdvancedOption &&option, Type (&lvariable)[M_SIZE], std::span<Type, RVALUE_ARRAY_SIZE> rvalue) -> std::size_t
{
  static_assert (RVALUE_ARRAY_SIZE <= M_SIZE || RVALUE_ARRAY_SIZE == std::dynamic_extent);

  std::size_t rvalue_array_size;
  if constexpr (RVALUE_ARRAY_SIZE <= M_SIZE)
    {
      rvalue_array_size = RVALUE_ARRAY_SIZE;
    }
  if constexpr (RVALUE_ARRAY_SIZE == std::dynamic_extent)
    {
      assert (rvalue.size () <= M_SIZE);
      rvalue_array_size = rvalue.size ();
    }

  switch (option.align)
    {
    default:
    case Align::ALIGN_LEFT:
      std::memcpy (lvariable, rvalue.data (), rvalue_array_size);
      break;
    case Align::ALIGN_RIGHT:
      std::memcpy (lvariable + (M_SIZE - rvalue_array_size), rvalue.data (), rvalue_array_size);
      break;
    }

  if constexpr (RVALUE_ARRAY_SIZE == M_SIZE)
    {
      return M_SIZE;
    }
  else if (rvalue_array_size == M_SIZE || !option.filler.has_value ())
    {
      return rvalue_array_size;
    }
  else
    {
      // assert0(option.filler.has_value());
      switch (option.align)
        {
        default:
        case Align::ALIGN_LEFT:
          std::memset (lvariable + rvalue_array_size, option.filler.value (), M_SIZE - rvalue_array_size);
          break;
        case Align::ALIGN_RIGHT:
          std::memset (lvariable, option.filler.value (), M_SIZE - rvalue_array_size);
          break;
        }
      return M_SIZE;
    }
}

// ******************************** ******************************** ******************************** ******************************** //
template <std::size_t V01>
template <std::size_t RVALUE_ARRAY_SIZE>
auto
xplum::ancestor::AssignerArrayChar<V01>::Assign (Type (&lvariable)[M_SIZE], std::span<Type, RVALUE_ARRAY_SIZE> rvalue) -> std::size_t
{
  return SUPER::Assign (lvariable, rvalue);
}

template <std::size_t V01>
template <std::size_t RVALUE_ARRAY_SIZE>
auto
xplum::ancestor::AssignerArrayChar<V01>::Advanced_Assign (const typename SUPER::AdvancedOption &&option, Type (&lvariable)[M_SIZE], std::span<Type, RVALUE_ARRAY_SIZE> rvalue) -> std::size_t
{
  return SUPER::Advanced_Assign (static_cast<const typename SUPER::AdvancedOption &&> (option), lvariable, rvalue);
}

template <std::size_t V01>
auto
xplum::ancestor::AssignerArrayChar<V01>::Assign (Type (&lvariable)[M_SIZE], std::string_view rvalue) -> std::size_t
{
  return SUPER::Assign (lvariable, std::span (const_cast<Type *> (rvalue.data ()), rvalue.size ()));
}

template <std::size_t V01>
auto
xplum::ancestor::AssignerArrayChar<V01>::Advanced_Assign (const typename SUPER::AdvancedOption &&option, Type (&lvariable)[M_SIZE], std::string_view rvalue) -> std::size_t
{
  return SUPER::Advanced_Assign (static_cast<const typename SUPER::AdvancedOption &&> (option), lvariable, std::span (const_cast<Type *> (rvalue.data ()), rvalue.size ()));
}
