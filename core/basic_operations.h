#pragma once

#include "basic_types.h"
#include "diagnostics.h"

#include <cmath>

namespace black_cat
{
   /**
      \brief gets the minimum of two values

      \tparam T - an type that supports operator <

      \param [in] value1 the first value
      \param [in] value2 the second value

      \return the minimum of two values
   */
   template <typename T>
   inline T get_min(T value1, T value2) noexcept
   {
      return value1 < value2 ? value1 : value2;
   }

   /**
      \brief gets the minimum of two values (template function, specialized for t_f32 type)

      \param [in] value1 the first value
      \param [in] value2 the second value

      \return the minimum of two values
   */
   template <>
   inline t_f32 get_min<t_f32>(t_f32 value1, t_f32 value2) noexcept
   {
      return std::fmin(value1, value2);
   }

   /**
      \brief gets the minimum of two values (template function, specialized for t_f64 type)

      \param [in] value1 the first value
      \param [in] value2 the second value

      \return the minimum of two values
   */
   template <>
   inline t_f64 get_min<t_f64>(t_f64 value1, t_f64 value2) noexcept
   {
      return std::fmin(value1, value2);
   }

   /**
      \brief gets the minimum of three values

      \tparam T - an type that supports operator <

      \param [in] value1 the first value
      \param [in] value2 the second value
      \param [in] value3 the third value

      \return the minimum of three values
   */
   template <typename T>
   inline T get_min(T value1, T value2, T value3) noexcept
   {
      return get_min(get_min(value1, value2), value3);
   }

   /**
      \brief gets the minimum of four values

      \tparam T - an type that supports operator <

      \param [in] value1 the first value
      \param [in] value2 the second value
      \param [in] value3 the third value
      \param [in] value4 the fourth value

      \return the minimum of four values
   */
   template <typename T>
   inline T get_min(T value1, T value2, T value3, T value4) noexcept
   {
      return get_min(get_min(get_min(value1, value2), value3), value4);
   }

   /**
      \brief gets the minimum of five values

      \tparam T - an type that supports operator <

      \param [in] value1 the first value
      \param [in] value2 the second value
      \param [in] value3 the third value
      \param [in] value4 the fourth value
      \param [in] value5 the fifth value

      \return the minimum of five values
   */
   template <typename T>
   inline T get_min(T value1, T value2, T value3, T value4, T value5) noexcept
   {
      return get_min(get_min(get_min(get_min(value1, value2), value3), value4), value5);
   }

   /**
      \brief gets the maximum of two values

      \tparam T - an type that supports operator <

      \param [in] value1 the first value
      \param [in] value2 the second value

      \return the maximum of two values
   */
   template <typename T>
   inline T get_max(T value1, T value2) noexcept
   {
      return value1 > value2 ? value1 : value2;
   }

   /**
      \brief gets the maximum of two values (template function, specialized for t_f32 type)

      \param [in] value1 the first value
      \param [in] value2 the second value

      \return the maximum of two values
   */
   template <>
   inline t_f32 get_max<t_f32>(t_f32 value1, t_f32 value2) noexcept
   {
      return std::fmax(value1, value2);
   }

   /**
      \brief gets the maximum of two values (template function, specialized for t_f64 type)

      \param [in] value1 the first value
      \param [in] value2 the second value

      \return the maximum of two values
   */
   template <>
   inline t_f64 get_max<t_f64>(t_f64 value1, t_f64 value2) noexcept
   {
      return std::fmax(value1, value2);
   }

   /**
      \brief gets the maximum of three values

      \tparam T - an type that supports operator <

      \param [in] value1 the first value
      \param [in] value2 the second value
      \param [in] value3 the third value

      \return the maximum of three values
   */
   template <typename T>
   inline T get_max(T value1, T value2, T value3) noexcept
   {
      return get_max(get_max(value1, value2), value3);
   }

   /**
      \brief gets the maximum of four values

      \tparam T - an type that supports operator <

      \param [in] value1 the first value
      \param [in] value2 the second value
      \param [in] value3 the third value
      \param [in] value4 the fourth value

      \return the maximum of four values
   */
   template <typename T>
   inline T get_max(T value1, T value2, T value3, T value4) noexcept
   {
      return get_max(get_max(get_max(value1, value2), value3), value4);
   }

   /**
      \brief gets the maximum of five values

      \tparam T - an type that supports operator <

      \param [in] value1 the first value
      \param [in] value2 the second value
      \param [in] value3 the third value
      \param [in] value4 the fourth value
      \param [in] value5 the fifth value

      \return the maximum of five values
   */
   template <typename T>
   inline T get_max(T value1, T value2, T value3, T value4, T value5) noexcept
   {
      return get_max(get_max(get_max(get_max(value1, value2), value3), value4), value5);
   }

   /**
      \brief clamps a value to a range

      \tparam T - an type that supports operators <, >

      \param [in] src_value the source value
      \param [in] min_value the lower bound value
      \param [in] max_value the upper bound value

      \return the value test_value, clamped to the range [min_value, max_value]
   */
   template <typename T>
   inline T clamp(T src_value, T min_value, T max_value) noexcept
   {
      BLACK_CAT_DIAGNOSTIC_CHECK_LESS_EQUAL(min_value, max_value);
      return get_min(get_max(src_value, min_value), max_value);
   }

   /**
      \brief tests if a value is in a range

      \tparam T - an type that supports operators >=, <=

      \param [in] test_value the testing value
      \param [in] min_value the lower bound value
      \param [in] max_value the upper bound value

      \return true if the value test_value is in the range [min_value, max_value], and false otherwise
   */
   template <typename T>
   inline t_bool in_range(T test_value, T min_value, T max_value) noexcept
   {
      BLACK_CAT_DIAGNOSTIC_CHECK_LESS_EQUAL(min_value, max_value);
      return test_value >= min_value && test_value <= max_value;
   }

   namespace core_details
   {
      template <typename T, t_bool is_signed = T(-1) < T(0)>
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

   template <typename T>
   inline T get_abs(T value) noexcept
   {
      return core_details::t_abs_helper::get_value(value);
   }

   /**
      \brief rounds a value up to the nearest greater integer

      \param [in] value the rounding value

      \return the rounded value
   */
   inline t_f32 round_up(t_f32 value) noexcept
   {
      return std::ceil(value);
   }

   /**
      \brief rounds a value up to the nearest greater integer

      \param [in] value the rounding value

      \return the rounded value
   */
   inline t_f64 round_up(t_f64 value) noexcept
   {
      return std::ceil(value);
   }

   /**
      \brief rounds a value down to the nearest lesser integer

      \param [in] value the rounding value

      \return the rounded value
   */
   inline t_f32 round_dn(t_f32 value) noexcept
   {
      return std::floor(value);
   }

   /**
      \brief rounds a value down to the nearest lesser integer

      \param [in] value the rounding value

      \return the rounded value
   */
   inline t_f64 round_dn(t_f64 value) noexcept
   {
      return std::floor(value);
   }

   /**
      \brief rounds a value to the nearest integer

      \param [in] value the rounding value

      \return the rounded value
   */
   inline t_f32 round_nst(t_f32 value) noexcept
   {
      return std::round(value);
   }

   /**
      \brief rounds a value to the nearest integer

      \param [in] value the rounding value

      \return the rounded value
   */
   inline t_f64 round_nst(t_f64 value) noexcept
   {
      return std::round(value);
   }

} // namespace black_cat
