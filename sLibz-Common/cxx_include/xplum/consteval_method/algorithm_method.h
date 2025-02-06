#pragma once
#include <cassert>

namespace ext
{
using long_double_t = long double;
}
namespace xplum::constexpr_method
{
extern constexpr auto FX_powl(std::size_t, std::size_t) -> ext::long_double_t;
}

inline constexpr auto xplum::constexpr_method::FX_powl(std::size_t base, std::size_t exp) -> ext::long_double_t
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

    ext::long_double_t var_last;
    ext::long_double_t var = 1;
    for (std::size_t i = 0, j = exp; i < j; i++)
    {
        var_last = var;
        var *= base;
        assert(var > var_last);
    }
    return var;
}
