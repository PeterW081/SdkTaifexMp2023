#pragma once
#include <type_traits>

namespace xplum //::expanded_cast
{
template <typename T> typename std::underlying_type<T>::type ToEnumUnderlyingValue(T t);
}

template <typename T> inline auto xplum::ToEnumUnderlyingValue(T t) -> typename std::underlying_type<T>::type { return static_cast<typename std::underlying_type<T>::type>(t); }
