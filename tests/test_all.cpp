#include <cstdio>

extern bool test_basic_types() noexcept;
extern bool test_basic_operations() noexcept;

int main()
{
   std::fputs("Testing basic types ...\n", stdout);

   if (!test_basic_types())
   {
      return -1;
   }

   std::fputs("done\n", stdout);

   std::fputs("\nTesting basic operations ...\n", stdout);

   if (!test_basic_operations())
   {
      return -1;
   }

   std::fputs("done\n", stdout);
   return 0;
}
