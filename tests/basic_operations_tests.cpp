#include "utest.h"

#include "../core/basic_operations.h"

#include <climits>

using namespace black_cat;

struct c_custom_class
{
   t_s32 x;

   explicit c_custom_class(t_s32 x) noexcept : x(x) { }

   t_bool operator < (const c_custom_class& other) noexcept
   {
      return x < other.x;
   }
};

template <>
inline void utest_print_value<c_custom_class>(const c_custom_class& value, FILE* f_out) noexcept
{
   std::fprintf(f_out, "c_custom_class { %d }", value.x);
}

bool test_basic_operations() noexcept
{
   UTEST_ASSERT_EQUAL(get_min(1, 2), 1);
   UTEST_ASSERT_LESS(get_min(1.5, 2.5), 2.5);
   UTEST_ASSERT_EQUAL(get_max(1, 2), 2);
   UTEST_ASSERT_GREATER(get_max(1.5, 2.5), 1.5);
   UTEST_ASSERT_LESS(c_custom_class(1), c_custom_class(2));
   return true;
}
