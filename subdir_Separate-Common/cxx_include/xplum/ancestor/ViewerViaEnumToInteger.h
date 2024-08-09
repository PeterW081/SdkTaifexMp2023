#pragma once
#include <type_traits>

#define MACRO_XPLUM_ANCESTOR_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS(PARAM01_SUBCLASS_NAME) explicit PARAM01_SUBCLASS_NAME (IntegerType &data) : ViewerViaEnumToInteger (data){};

namespace xplum::ancestor
{
template <typename TYPENAME_ENUM, typename TYPENAME_INTEGER> class ViewerViaEnumToInteger;
}

template <typename TYPENAME_ENUM, typename TYPENAME_INTEGER = typename std::underlying_type<TYPENAME_ENUM>::type> class xplum::ancestor::ViewerViaEnumToInteger
{
  static_assert (std::is_enum<TYPENAME_ENUM>::value);

public:
  using EnumType = TYPENAME_ENUM;
  using EnumUnderlyingType = typename std::underlying_type<TYPENAME_ENUM>::type;
  using IntegerType = TYPENAME_INTEGER;
  explicit ViewerViaEnumToInteger (IntegerType &data);
  explicit operator IntegerType () const;
  void operator_assign (EnumType var);
  IntegerType integer_type_value () const;
  EnumType enum_value () const;
  EnumUnderlyingType enum_underlying_value () const;

private:
  IntegerType &m_data;
};

// ******************************** ******************************** ******************************** ******************************** //
template <typename TYPENAME_ENUM, typename TYPENAME_INTEGER> xplum::ancestor::ViewerViaEnumToInteger<TYPENAME_ENUM, TYPENAME_INTEGER>::ViewerViaEnumToInteger (IntegerType &data) : m_data (data) {}

template <typename TYPENAME_ENUM, typename TYPENAME_INTEGER> xplum::ancestor::ViewerViaEnumToInteger<TYPENAME_ENUM, TYPENAME_INTEGER>::operator IntegerType () const { return m_data; }

template <typename TYPENAME_ENUM, typename TYPENAME_INTEGER>
void
xplum::ancestor::ViewerViaEnumToInteger<TYPENAME_ENUM, TYPENAME_INTEGER>::operator_assign (EnumType var)
{
  this->m_data = static_cast<EnumUnderlyingType> (var);
}

template <typename TYPENAME_ENUM, typename TYPENAME_INTEGER>
auto
xplum::ancestor::ViewerViaEnumToInteger<TYPENAME_ENUM, TYPENAME_INTEGER>::integer_type_value () const -> IntegerType
{
  return m_data;
}

template <typename TYPENAME_ENUM, typename TYPENAME_INTEGER>
auto
xplum::ancestor::ViewerViaEnumToInteger<TYPENAME_ENUM, TYPENAME_INTEGER>::enum_value () const -> EnumType
{
  return static_cast<EnumType> (static_cast<EnumUnderlyingType> (m_data));
}

template <typename TYPENAME_ENUM, typename TYPENAME_INTEGER>
auto
xplum::ancestor::ViewerViaEnumToInteger<TYPENAME_ENUM, TYPENAME_INTEGER>::enum_underlying_value () const -> EnumUnderlyingType
{
  return m_data;
}
