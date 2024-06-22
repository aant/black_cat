#pragma once

#include <cstdint>
#include <cstdio>

#ifndef private
   #define private public
#endif

#ifndef protected
   #define protected public
#endif

template <typename T>
inline void utest_print_value(T value, FILE* f_out) noexcept;

template <>
inline void utest_print_value<std::int64_t>(std::int64_t value, FILE* f_out) noexcept
{
   std::fprintf(f_out, "%lld", value);
}

template <>
inline void utest_print_value<std::uint64_t>(std::uint64_t value, FILE* f_out) noexcept
{
   std::fprintf(f_out, "%llu", value);
}

template <>
inline void utest_print_value<std::int8_t>(std::int8_t value, FILE* f_out) noexcept
{
   utest_print_value<std::int64_t>(value, f_out);
}

template <>
inline void utest_print_value<std::uint8_t>(std::uint8_t value, FILE* f_out) noexcept
{
   utest_print_value<std::uint64_t>(value, f_out);
}

template <>
inline void utest_print_value<std::int16_t>(std::int16_t value, FILE* f_out) noexcept
{
   utest_print_value<std::int64_t>(value, f_out);
}

template <>
inline void utest_print_value<std::uint16_t>(std::uint16_t value, FILE* f_out) noexcept
{
   utest_print_value<std::uint64_t>(value, f_out);
}

template <>
inline void utest_print_value<std::int32_t>(std::int32_t value, FILE* f_out) noexcept
{
   utest_print_value<std::int64_t>(value, f_out);
}

template <>
inline void utest_print_value<std::uint32_t>(std::uint32_t value, FILE* f_out) noexcept
{
   utest_print_value<std::uint64_t>(value, f_out);
}

template <>
inline void utest_print_value<float>(float value, FILE* f_out) noexcept
{
   std::fprintf(f_out, "%.4f", value);
}

template <>
inline void utest_print_value<double>(double value, FILE* f_out) noexcept
{
   std::fprintf(f_out, "%.8f", value);
}

#ifdef _WIN32

   template <>
   inline void utest_print_value<signed long>(signed long value, FILE* f_out) noexcept
   {
      utest_print_value<std::int64_t>(value, f_out);
   }

   template <>
   inline void utest_print_value<unsigned long>(unsigned long value, FILE* f_out) noexcept
   {
      utest_print_value<std::uint64_t>(value, f_out);
   }

#endif // _WIN32

template <>
inline void utest_print_value<char>(char value, FILE* f_out) noexcept
{
   std::fprintf(f_out, "%c", value);
}

template <>
inline void utest_print_value<bool>(bool value, FILE* f_out) noexcept
{
   std::fputs(value ? "TRUE" : "FALSE", f_out);
}

template <typename T>
inline void utest_print_value(T* ptr, FILE* f_out) noexcept
{
   if (ptr)
   {
      std::fprintf(f_out, "0x%p", ptr);
   }
   else
   {
      std::fputs("NULL", f_out);
   }
}

template <typename T>
inline void utest_print_value(const T* ptr, FILE* f_out) noexcept
{
   if (ptr)
   {
      std::fprintf(f_out, "0x%p", ptr);
   }
   else
   {
      std::fputs("NULL", f_out);
   }
}

#define UTEST_TOSTRLL(n) #n
#define UTEST_TOSTR(n) UTEST_TOSTRLL(n)

#define UTEST_ASSERT_NULL(expression) \
   { \
      auto eval = (expression); \
      if (!(eval == nullptr)) \
      { \
         std::fputs("\nTest failed: expected NULL, actual ", stderr); \
         utest_print_value(eval, stderr); \
         std::fputs("\nin " __FILE__ ", line " UTEST_TOSTR(__LINE__) "\n", stderr); return false; \
      } \
   }

#define UTEST_ASSERT_NOT_NULL(expression) \
   { \
      auto eval = (expression); \
      if (!(eval != nullptr)) \
      { \
         std::fputs("\nTest failed: expected not NULL, actual NULL", stderr); \
         std::fputs("\nin " __FILE__ ", line " UTEST_TOSTR(__LINE__) "\n", stderr); return false; \
      } \
   }

#define UTEST_ASSERT_TRUE(expression) \
   { \
      auto eval = (expression); \
      if (!(eval == true)) \
      { \
         std::fputs("\nTest failed: expected TRUE, actual FALSE", stderr); \
         std::fputs("\nin " __FILE__ ", line " UTEST_TOSTR(__LINE__) "\n", stderr); return false; \
      } \
   }

#define UTEST_ASSERT_FALSE(expression) \
   { \
      auto eval = (expression); \
      if (!(eval == false)) \
      { \
         std::fputs("\nTest failed: expected FALSE, actual TRUE", stderr); \
         std::fputs("\nin " __FILE__ ", line " UTEST_TOSTR(__LINE__) "\n", stderr); return false; \
      } \
   }

#define UTEST_ASSERT_LESS(expression, expected) \
   { \
      auto eval1 = (expression); \
      auto eval2 = decltype(eval1)((expected)); \
      if (!(eval1 < eval2)) \
      { \
         std::fputs("\nTest failed: expected < ", stderr); \
         utest_print_value(eval2, stderr); \
         std::fputs(", actual ", stderr); \
         utest_print_value(eval1, stderr); \
         std::fputs("\nin " __FILE__ ", line " UTEST_TOSTR(__LINE__) "\n", stderr); return false; \
      } \
   }

#define UTEST_ASSERT_LESS_EQUAL(expression, expected) \
   { \
      auto eval1 = (expression); \
      auto eval2 = decltype(eval1)((expected)); \
      if (!(eval1 <= eval2)) \
      { \
         std::fputs("\nTest failed: expected <= ", stderr); \
         utest_print_value(eval2, stderr); \
         std::fputs(", actual ", stderr); \
         utest_print_value(eval1, stderr); \
         std::fputs("\nin " __FILE__ ", line " UTEST_TOSTR(__LINE__) "\n", stderr); return false; \
      } \
   }

#define UTEST_ASSERT_EQUAL(expression, expected) \
   { \
      auto eval1 = (expression); \
      auto eval2 = decltype(eval1)((expected)); \
      if (!(eval1 == eval2)) \
      { \
         std::fputs("\nTest failed: expected == ", stderr); \
         utest_print_value(eval2, stderr); \
         std::fputs(", actual ", stderr); \
         utest_print_value(eval1, stderr); \
         std::fputs("\nin " __FILE__ ", line " UTEST_TOSTR(__LINE__) "\n", stderr); return false; \
      } \
   }

#define UTEST_ASSERT_GREATER_EQUAL(expression, expected) \
   { \
      auto eval1 = (expression); \
      auto eval2 = decltype(eval1)((expected)); \
      if (!(eval1 >= eval2)) \
      { \
         std::fputs("\nTest failed: expected >= ", stderr); \
         utest_print_value(eval2, stderr); \
         std::fputs(", actual ", stderr); \
         utest_print_value(eval1, stderr); \
         std::fputs("\nin " __FILE__ ", line " UTEST_TOSTR(__LINE__) "\n", stderr); return false; \
      } \
   }

#define UTEST_ASSERT_GREATER(expression, expected) \
   { \
      auto eval1 = (expression); \
      auto eval2 = decltype(eval1)((expected)); \
      if (!(eval1 > eval2)) \
      { \
         std::fputs("\nTest failed: expected > ", stderr); \
         utest_print_value(eval2, stderr); \
         std::fputs(", actual ", stderr); \
         utest_print_value(eval1, stderr); \
         std::fputs("\nin " __FILE__ ", line " UTEST_TOSTR(__LINE__) "\n", stderr); return false; \
      } \
   }

#define UTEST_ASSERT_NOT_EQUAL(expression, expected) \
   { \
      auto eval1 = (expression); \
      auto eval2 = decltype(eval1)((expected)); \
      if (!(eval1 != eval2)) \
      { \
         std::fputs("\nTest failed: expected != ", stderr); \
         utest_print_value(eval2, stderr); \
         std::fputs(", actual ", stderr); \
         utest_print_value(eval1, stderr); \
         std::fputs("\nin " __FILE__ ", line " UTEST_TOSTR(__LINE__) "\n", stderr); return false; \
      } \
   }

#define UTEST_ASSERT_RANGE(expression, lower_bound, upper_bound) \
   { \
      auto eval1 = (expression); \
      auto eval2 = decltype(eval1)((lower_bound)); \
      auto eval3 = decltype(eval1)((upper_bound)); \
      if (!(eval1 >= eval2 && eval1 <= eval3)) \
      { \
         std::fputs("\nTest failed: expected in range [", stderr); \
         utest_print_value(eval2, stderr); \
         std::fputs(", ", stderr); \
         utest_print_value(eval3, stderr); \
         std::fputs("], actual ", stderr); \
         utest_print_value(eval1, stderr); \
         std::fputs("\nin " __FILE__ ", line " UTEST_TOSTR(__LINE__) "\n", stderr); return false; \
      } \
   }
