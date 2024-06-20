#pragma once

#include <cstddef>
#include <cstdint>

#ifdef _MSC_VER
   #include <climits>
#endif

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
   using t_f64 = float;

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

} // namespace black_cat
