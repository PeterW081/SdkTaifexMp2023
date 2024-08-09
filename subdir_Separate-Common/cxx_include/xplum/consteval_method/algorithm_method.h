#pragma once
#include <cassert>

namespace xplum::constexpr_method
{
long double constexpr Powl (std::size_t base, std::size_t exp);
}

inline long double constexpr
xplum::constexpr_method::Powl (std::size_t base, std::size_t exp)
{
  // like std::powl()
  if (exp == 0)
    {
      return 1;
    }
  if (base == 1 || base == 0)
    {
      return base;
    }

  long double var_last;
  long double var = 1;
  for (std::size_t i = 0, j = exp; i < j; i++)
    {
      var_last = var;
      var *= base;
      assert (var > var_last);
    }
  return var;
}
