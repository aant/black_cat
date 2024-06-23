#include "utest.h"

#include "../core/vector2.h"

using namespace black_cat;

template <>
inline void utest_print_value<c_vec2i>(c_vec2i vec, FILE* f_out) noexcept
{
   std::fprintf(f_out, "c_vec2i { %d, %d }", vec.x, vec.y);
}

template <>
inline void utest_print_value<c_vec2f>(c_vec2f vec, FILE* f_out) noexcept
{
   std::fprintf(f_out, "c_vec2f { %.4f, %.4f }", vec.x, vec.y);
}

bool test_vector2()
{
   UTEST_ASSERT_EQUAL(c_vec2i(1, 2), c_vec2i(1, 2));
   UTEST_ASSERT_NOT_EQUAL(c_vec2i(1, 2), c_vec2i(2, 3));

   UTEST_ASSERT_EQUAL(+c_vec2i(1, 2), c_vec2i(1, 2));
   UTEST_ASSERT_EQUAL(-c_vec2i(1, 2), c_vec2i(-1, -2));

   UTEST_ASSERT_EQUAL(c_vec2i(1, 2) + 2, c_vec2i(3, 4));
   UTEST_ASSERT_EQUAL(c_vec2i(1, 0) + c_vec2i(0, 2), c_vec2i(1, 2));

   UTEST_ASSERT_EQUAL(c_vec2i(3, 4) - 2, c_vec2i(1, 2));
   UTEST_ASSERT_EQUAL(c_vec2i(3, 4) - c_vec2i(2, 2), c_vec2i(1, 2));

   UTEST_ASSERT_EQUAL(c_vec2i(3, 4) * 2, c_vec2i(6, 8));
   UTEST_ASSERT_EQUAL(c_vec2i(3, 4) * c_vec2i(3, 2), c_vec2i(9, 8));

   UTEST_ASSERT_EQUAL(c_vec2i(8, 12) / 2, c_vec2i(4, 6));
   UTEST_ASSERT_EQUAL(c_vec2i(6, 8) / c_vec2i(3, 2), c_vec2i(2, 4));

   UTEST_ASSERT_EQUAL(to_vec2i(c_vec2f(1.1f, 2.2f)), c_vec2i(1, 2));
   UTEST_ASSERT_EQUAL(to_vec2f(c_vec2i(1, 2)), c_vec2f(1.0f, 2.0f));

   UTEST_ASSERT_EQUAL(t_s32(calc_dot(c_vec2f(2.1f, 3.1f), c_vec2f(2.1f, 3.1f))), 14);
   UTEST_ASSERT_EQUAL(t_s32(calc_sqlen(c_vec2f(5.11f, 0.0f))), 26);
   UTEST_ASSERT_EQUAL(t_s32(calc_len(c_vec2f(5.1f, 0.0f))), 5);

   c_vec2i v(1, 2);
   v += c_vec2i(2, 3);

   UTEST_ASSERT_EQUAL(v, c_vec2i(3, 5));

   v += 2;

   UTEST_ASSERT_EQUAL(v, c_vec2i(5, 7));

   v -= c_vec2i(2, 3);

   UTEST_ASSERT_EQUAL(v, c_vec2i(3, 4));

   v -= 2;

   UTEST_ASSERT_EQUAL(v, c_vec2i(1, 2));

   v *= c_vec2i(2, 3);

   UTEST_ASSERT_EQUAL(v, c_vec2i(2, 6));

   v *= 2;

   UTEST_ASSERT_EQUAL(v, c_vec2i(4, 12));

   v /= c_vec2i(2, 3);

   UTEST_ASSERT_EQUAL(v, c_vec2i(2, 4));

   v /= 2;

   UTEST_ASSERT_EQUAL(v, c_vec2i(1, 2));

   return true;
}
