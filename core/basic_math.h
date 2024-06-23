#pragma once

#include "basic_types.h"
#include "diagnostics.h"

#include <cmath>

namespace black_cat
{
   // the great number PI (presented as 64-bit floating-point type)
   static constexpr t_f64 PI64 = 3.1415926535897932384626433832795;

   // the great number PI (presented as 32-bit floating-point type)
   static constexpr t_f32 PI32 = t_f32(PI64);

   // calculates squared root of a value
   inline t_f32 calc_sqr(t_f32 value) noexcept
   {
      BLACK_CAT_DIAGNOSTIC_CHECK_GREATER_EQUAL(value, 0.0f);
      return std::sqrt(value);
   }

   // calculates squared root of a value
   inline t_f64 calc_sqr(t_f64 value) noexcept
   {
      BLACK_CAT_DIAGNOSTIC_CHECK_GREATER_EQUAL(value, 0.0);
      return std::sqrt(value);
   }

   // linearly interpolates two values
   template <typename T>
   inline T lerp(T value1, T value2, t_f32 t) noexcept
   {
      BLACK_CAT_DIAGNOSTIC_CHECK_RANGE(t, 0.0f, 1.0f);
      return T(value1 * (1.0f - t) + value2 * t);
   }

} // namespace black_cat
