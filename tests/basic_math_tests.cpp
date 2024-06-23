#include "utest.h"

#include "../core/basic_math.h"

using namespace black_cat;

bool test_basic_math()
{
   UTEST_ASSERT_EQUAL(t_s32(calc_sqr(4.0f)), 2);
   UTEST_ASSERT_EQUAL(t_s32(calc_sqr(4.0)), 2);

   UTEST_ASSERT_EQUAL(t_s32(lerp(2.1f, 6.1f, 0.0f)), 2);
   UTEST_ASSERT_EQUAL(t_s32(lerp(2.1f, 6.1f, 0.5f)), 4);
   UTEST_ASSERT_EQUAL(t_s32(lerp(2.1f, 6.1f, 1.0f)), 6);

   UTEST_ASSERT_EQUAL(t_s32(lerp(2.1, 6.1, 0.0f)), 2);
   UTEST_ASSERT_EQUAL(t_s32(lerp(2.1, 6.1, 0.5f)), 4);
   UTEST_ASSERT_EQUAL(t_s32(lerp(2.1, 6.1, 1.0f)), 6);

   return true;
}
