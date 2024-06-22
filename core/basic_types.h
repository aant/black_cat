#pragma once

#include <cstddef>
#include <cstdint>
#include <climits>
#include <cfloat>

namespace black_cat
{
   // 8-bit signed integer type
   using t_s8 = ::std::int8_t;

   // 8-bit unsigned integer type
   using t_u8 = ::std::uint8_t;

   // 16-bit signed integer type
   using t_s16 = ::std::int16_t;

   // 16-bit unsigned integer type
   using t_u16 = ::std::uint16_t;

   // 32-bit signed integer type
   using t_s32 = ::std::int32_t;

   // 32-bit unsigned integer type
   using t_u32 = ::std::uint32_t;

   // 32-bit floating-point type
   using t_f32 = float;

   // 64-bit signed integer type
   using t_s64 = ::std::int64_t;

   // 64-bit unsigned integer type
   using t_u64 = ::std::uint64_t;

   // 64-bit floating-point type
   using t_f64 = double;

   // pointer-wide signed integer type
   using t_sptr_size = ::std::intptr_t;

   // pointer-wide unsigned integer type
   using t_uptr_size = ::std::uintptr_t;

   // 8-bit character type
   using t_char = char;

   // Boolean logic type
   using t_bool = bool;

   static_assert(sizeof(t_s8) == 1, "size of t_s8 != 1");
   static_assert(sizeof(t_u8) == 1, "size of t_u8 != 1");
   static_assert(sizeof(t_s16) == 2, "size of t_s16 != 2");
   static_assert(sizeof(t_u16) == 2, "size of t_u16 != 2");
   static_assert(sizeof(t_s32) == 4, "size of t_s32 != 4");
   static_assert(sizeof(t_u32) == 4, "size of t_u32 != 4");
   static_assert(sizeof(t_f32) == 4, "size of t_f32 != 4");
   static_assert(sizeof(t_s64) == 8, "size of t_s64 != 8");
   static_assert(sizeof(t_u64) == 8, "size of t_u64 != 8");
   static_assert(sizeof(t_f64) == 8, "size of t_f64 != 8");
   static_assert(sizeof(t_sptr_size) == sizeof(void*), "size of t_sptr_size != size of pointer");
   static_assert(sizeof(t_uptr_size) == sizeof(void*), "size of t_uptr_size != size of pointer");

   namespace core_details
   {
      template <typename T, T min_value, T max_value>
      struct t_minmax_helper
      {
         static constexpr T MIN_VALUE = min_value;
         static constexpr T MAX_VALUE = max_value;
      };

   } // namespace core_details

   template <typename T>
   struct t_minmax;

   template <>
   struct t_minmax<t_s8> : core_details::t_minmax_helper<t_s8, INT8_MIN, INT8_MAX> { };

   template <>
   struct t_minmax<t_u8> : core_details::t_minmax_helper<t_u8, 0, UINT8_MAX> { };

   template <>
   struct t_minmax<t_s16> : core_details::t_minmax_helper<t_s16, INT16_MIN, INT16_MAX> { };

   template <>
   struct t_minmax<t_u16> : core_details::t_minmax_helper<t_u16, 0, UINT16_MAX> { };

   template <>
   struct t_minmax<t_s32> : core_details::t_minmax_helper<t_s32, INT32_MIN, INT32_MAX> { };

   template <>
   struct t_minmax<t_u32> : core_details::t_minmax_helper<t_u32, 0, UINT32_MAX> { };

   template <>
   struct t_minmax<t_s64> : core_details::t_minmax_helper<t_s64, INT64_MIN, INT64_MAX> { };

   template <>
   struct t_minmax<t_u64> : core_details::t_minmax_helper<t_u64, 0, UINT64_MAX> { };

   template <>
   struct t_minmax<char> : core_details::t_minmax_helper<char, CHAR_MIN, CHAR_MAX> { };

   #ifdef _WIN32

      template <>
      struct t_minmax<signed long> : core_details::t_minmax_helper<signed long, LONG_MIN, LONG_MAX> { };

      template <>
      struct t_minmax<unsigned long> : core_details::t_minmax_helper<unsigned long, 0, ULONG_MAX> { };

   #endif // _WIN32

   namespace type_traits
   {
      template <typename F, typename S>
      struct is_same
      {
         static constexpr t_bool v = false;
      };

      template <typename T>
      struct is_same<T, T>
      {
         static constexpr t_bool v = true;
      };

      template <typename T>
      struct is_signed
      {
         static constexpr t_bool v = T(-1) < T(0);
      };

   } // namespace type_traits

} // namespace black_cat
