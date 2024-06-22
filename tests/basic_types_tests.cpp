#include "utest.h"

#include "../core/basic_types.h"

using namespace black_cat;

static bool test_minmax()
{
   std::fputs("\nTesting numeric limits (min and max) ...\n", stdout);

   UTEST_ASSERT_EQUAL(t_minmax<t_s8>::MIN_VALUE, INT8_MIN);
   UTEST_ASSERT_EQUAL(t_minmax<t_s8>::MAX_VALUE, INT8_MAX);
   UTEST_ASSERT_EQUAL(t_minmax<t_u8>::MIN_VALUE, 0);
   UTEST_ASSERT_EQUAL(t_minmax<t_u8>::MAX_VALUE, UINT8_MAX);

   UTEST_ASSERT_EQUAL(t_minmax<t_s16>::MIN_VALUE, INT16_MIN);
   UTEST_ASSERT_EQUAL(t_minmax<t_s16>::MAX_VALUE, INT16_MAX);
   UTEST_ASSERT_EQUAL(t_minmax<t_u16>::MIN_VALUE, 0);
   UTEST_ASSERT_EQUAL(t_minmax<t_u16>::MAX_VALUE, UINT16_MAX);

   UTEST_ASSERT_EQUAL(t_minmax<t_s32>::MIN_VALUE, INT32_MIN);
   UTEST_ASSERT_EQUAL(t_minmax<t_s32>::MAX_VALUE, INT32_MAX);
   UTEST_ASSERT_EQUAL(t_minmax<t_u32>::MIN_VALUE, 0);
   UTEST_ASSERT_EQUAL(t_minmax<t_u32>::MAX_VALUE, UINT32_MAX);

   UTEST_ASSERT_EQUAL(t_minmax<t_s64>::MIN_VALUE, INT64_MIN);
   UTEST_ASSERT_EQUAL(t_minmax<t_s64>::MAX_VALUE, INT64_MAX);
   UTEST_ASSERT_EQUAL(t_minmax<t_u64>::MIN_VALUE, 0);
   UTEST_ASSERT_EQUAL(t_minmax<t_u64>::MAX_VALUE, UINT64_MAX);

   UTEST_ASSERT_EQUAL(t_minmax<t_sptr_size>::MIN_VALUE, INTPTR_MIN);
   UTEST_ASSERT_EQUAL(t_minmax<t_sptr_size>::MAX_VALUE, INTPTR_MAX);
   UTEST_ASSERT_EQUAL(t_minmax<t_uptr_size>::MIN_VALUE, 0);
   UTEST_ASSERT_EQUAL(t_minmax<t_uptr_size>::MAX_VALUE, UINTPTR_MAX);

   UTEST_ASSERT_EQUAL(t_minmax<char>::MIN_VALUE, CHAR_MIN);
   UTEST_ASSERT_EQUAL(t_minmax<char>::MAX_VALUE, CHAR_MAX);

   UTEST_ASSERT_EQUAL(t_minmax<signed char>::MIN_VALUE, SCHAR_MIN);
   UTEST_ASSERT_EQUAL(t_minmax<signed char>::MAX_VALUE, SCHAR_MAX);
   UTEST_ASSERT_EQUAL(t_minmax<unsigned char>::MIN_VALUE, 0);
   UTEST_ASSERT_EQUAL(t_minmax<unsigned char>::MAX_VALUE, UCHAR_MAX);

   UTEST_ASSERT_EQUAL(t_minmax<signed short>::MIN_VALUE, SHRT_MIN);
   UTEST_ASSERT_EQUAL(t_minmax<signed short>::MAX_VALUE, SHRT_MAX);
   UTEST_ASSERT_EQUAL(t_minmax<unsigned short>::MIN_VALUE, 0);
   UTEST_ASSERT_EQUAL(t_minmax<unsigned short>::MAX_VALUE, USHRT_MAX);

   UTEST_ASSERT_EQUAL(t_minmax<signed int>::MIN_VALUE, INT_MIN);
   UTEST_ASSERT_EQUAL(t_minmax<signed int>::MAX_VALUE, INT_MAX);
   UTEST_ASSERT_EQUAL(t_minmax<unsigned int>::MIN_VALUE, 0);
   UTEST_ASSERT_EQUAL(t_minmax<unsigned int>::MAX_VALUE, UINT_MAX);

   UTEST_ASSERT_EQUAL(t_minmax<signed long>::MIN_VALUE, LONG_MIN);
   UTEST_ASSERT_EQUAL(t_minmax<signed long>::MAX_VALUE, LONG_MAX);
   UTEST_ASSERT_EQUAL(t_minmax<unsigned long>::MIN_VALUE, 0);
   UTEST_ASSERT_EQUAL(t_minmax<unsigned long>::MAX_VALUE, ULONG_MAX);

   UTEST_ASSERT_EQUAL(t_minmax<signed long long>::MIN_VALUE, LLONG_MIN);
   UTEST_ASSERT_EQUAL(t_minmax<signed long long>::MAX_VALUE, LLONG_MAX);
   UTEST_ASSERT_EQUAL(t_minmax<unsigned long long>::MIN_VALUE, 0);
   UTEST_ASSERT_EQUAL(t_minmax<unsigned long long>::MAX_VALUE, ULLONG_MAX);

   std::fputs("done\n", stdout);
   return true;
}

static bool test_type_traits_is_signed()
{
   std::fputs("\nTesting type traits (is signed) ...\n", stdout);

   UTEST_ASSERT_TRUE(type_traits::is_signed<t_s8>::v);
   UTEST_ASSERT_FALSE(type_traits::is_signed<t_u8>::v);

   UTEST_ASSERT_TRUE(type_traits::is_signed<t_s16>::v);
   UTEST_ASSERT_FALSE(type_traits::is_signed<t_u16>::v);

   UTEST_ASSERT_TRUE(type_traits::is_signed<t_s32>::v);
   UTEST_ASSERT_FALSE(type_traits::is_signed<t_u32>::v);

   UTEST_ASSERT_TRUE(type_traits::is_signed<t_f32>::v);
   UTEST_ASSERT_TRUE(type_traits::is_signed<t_s64>::v);

   UTEST_ASSERT_FALSE(type_traits::is_signed<t_u64>::v);
   UTEST_ASSERT_TRUE(type_traits::is_signed<t_f64>::v);

   UTEST_ASSERT_TRUE(type_traits::is_signed<t_sptr_size>::v);
   UTEST_ASSERT_FALSE(type_traits::is_signed<t_uptr_size>::v);

   UTEST_ASSERT_TRUE(type_traits::is_signed<signed char>::v);
   UTEST_ASSERT_FALSE(type_traits::is_signed<unsigned char>::v);

   UTEST_ASSERT_TRUE(type_traits::is_signed<signed short>::v);
   UTEST_ASSERT_FALSE(type_traits::is_signed<unsigned short>::v);

   UTEST_ASSERT_TRUE(type_traits::is_signed<signed int>::v);
   UTEST_ASSERT_FALSE(type_traits::is_signed<unsigned int>::v);

   UTEST_ASSERT_TRUE(type_traits::is_signed<signed long>::v);
   UTEST_ASSERT_FALSE(type_traits::is_signed<unsigned long>::v);

   UTEST_ASSERT_TRUE(type_traits::is_signed<signed long long>::v);
   UTEST_ASSERT_FALSE(type_traits::is_signed<unsigned long long>::v);

   std::fputs("done\n", stdout);
   return true;
}

static bool test_type_traits_is_same()
{
   std::fputs("\nTesting type traits (is same) ...\n", stdout);

   // extra parentheses are needed to prevent the preprocessor from going crazy

   UTEST_ASSERT_TRUE((type_traits::is_same<t_s8, t_s8>::v));
   UTEST_ASSERT_FALSE((type_traits::is_same<t_s8, t_u8>::v));
   UTEST_ASSERT_FALSE((type_traits::is_same<t_u8, const t_u8>::v));
   UTEST_ASSERT_FALSE((type_traits::is_same<char, signed char>::v));
   UTEST_ASSERT_FALSE((type_traits::is_same<char, unsigned char>::v));

   std::fputs("done\n\n", stdout);
   return true;
}

bool test_basic_types() noexcept
{
   return test_minmax() && test_type_traits_is_signed() && test_type_traits_is_same();
}
