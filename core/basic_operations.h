#pragma once

#include "basic_types.h"
#include "diagnostics.h"

#include <cmath>

namespace black_cat
{
   // gets the minimum of two values
   // T should provide operator <
   template <typename T>
   inline T get_min(T value1, T value2) noexcept
   {
      return value1 < value2 ? value1 : value2;
   }

   // gets the minimum of two values
   // 32-bit floating-point specialization
   template <>
   inline t_f32 get_min<t_f32>(t_f32 value1, t_f32 value2) noexcept
   {
      return std::fmin(value1, value2);
   }

   // gets the minimum of two values
   // 64-bit floating-point specialization
   template <>
   inline t_f64 get_min<t_f64>(t_f64 value1, t_f64 value2) noexcept
   {
      return std::fmin(value1, value2);
   }

   // gets the minimum of three values
   // T should provide operator <
   template <typename T>
   inline T get_min(T value1, T value2, T value3) noexcept
   {
      return get_min(get_min(value1, value2), value3);
   }

   // gets the minimum of four values
   // T should provide operator <
   template <typename T>
   inline T get_min(T value1, T value2, T value3, T value4) noexcept
   {
      return get_min(get_min(get_min(value1, value2), value3), value4);
   }

   // gets the minimum of five values
   // T should provide operator <
   template <typename T>
   inline T get_min(T value1, T value2, T value3, T value4, T value5) noexcept
   {
      return get_min(get_min(get_min(get_min(value1, value2), value3), value4), value5);
   }

   // gets the maximum of two values
   // T should provide operator >
   template <typename T>
   inline T get_max(T value1, T value2) noexcept
   {
      return value1 > value2 ? value1 : value2;
   }

   // gets the maximum of two values
   // 32-bit floating-point specialization
   template <>
   inline t_f32 get_max<t_f32>(t_f32 value1, t_f32 value2) noexcept
   {
      return std::fmax(value1, value2);
   }

   // gets the maximum of two values
   // 64-bit floating-point specialization
   template <>
   inline t_f64 get_max<t_f64>(t_f64 value1, t_f64 value2) noexcept
   {
      return std::fmax(value1, value2);
   }

   // gets the maximum of three values
   // T should provide operator >
   template <typename T>
   inline T get_max(T value1, T value2, T value3) noexcept
   {
      return get_max(get_max(value1, value2), value3);
   }

   // gets the maximum of four values
   // T should provide operator >
   template <typename T>
   inline T get_max(T value1, T value2, T value3, T value4) noexcept
   {
      return get_max(get_max(get_max(value1, value2), value3), value4);
   }

   // gets the maximum of five values
   // T should provide operator >
   template <typename T>
   inline T get_max(T value1, T value2, T value3, T value4, T value5) noexcept
   {
      return get_max(get_max(get_max(get_max(value1, value2), value3), value4), value5);
   }

   // clamps a value to a specified range
   // T should provide operators <, >
   template <typename T>
   inline T clamp(T src_value, T min_value, T max_value) noexcept
   {
      BLACK_CAT_DIAGNOSTIC_CHECK_LESS_EQUAL(min_value, max_value);
      return get_min(get_max(src_value, min_value), max_value);
   }

   // checks a value is in a specified range
   // T should provide operators <=, >=
   template <typename T>
   inline t_bool in_range(T test_value, T min_value, T max_value) noexcept
   {
      BLACK_CAT_DIAGNOSTIC_CHECK_LESS_EQUAL(min_value, max_value);
      return test_value >= min_value && test_value <= max_value;
   }

   namespace core_details
   {
      template <typename T, t_bool is_signed>
      struct t_abs_helper
      {
         static constexpr T MIN_VALUE = black_cat::t_minmax<T>::MIN_VALUE;

         static T get_value(T value) noexcept
         {
            return value >= 0 ? value : (value == MIN_VALUE ? MIN_VALUE : -value);
         }
      };

      template <typename T>
      struct t_abs_helper<T, false>
      {
         static T get_value(T value) noexcept
         {
            return value;
         }
      };

   } // namespace core_details

   // gets the absolute of specified value
   // T should support operators >=, ==, unary -, if it is signed type
   template <typename T>
   inline T get_abs(T value) noexcept
   {
      return core_details::t_abs_helper<T, type_traits::is_signed<T>::v>::get_value(value);
   }

   // rounds a value to the nearest greater integer
   inline t_f32 round_up(t_f32 value) noexcept
   {
      return std::ceil(value);
   }

   // rounds a value to the nearest greater integer
   inline t_f64 round_up(t_f64 value) noexcept
   {
      return std::ceil(value);
   }

   // rounds a value to the nearest lesser integer
   inline t_f32 round_dn(t_f32 value) noexcept
   {
      return std::floor(value);
   }

   // rounds a value to the nearest lesser integer
   inline t_f64 round_dn(t_f64 value) noexcept
   {
      return std::floor(value);
   }

   // rounds a value to the nearest integer
   inline t_f32 round_nst(t_f32 value) noexcept
   {
      return std::round(value);
   }

   // rounds a value to the nearest integer
   inline t_f64 round_nst(t_f64 value) noexcept
   {
      return std::round(value);
   }

} // namespace black_cat
