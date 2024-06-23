#include <cstdio>
#include "../system/desktop_application.h"

extern bool test_basic_types();
extern bool test_basic_operations();
extern bool test_basic_math();
extern bool test_vector2();
extern bool test_image();

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

   std::fputs("\nTesting basic math ...\n", stdout);

   if (!test_basic_math())
   {
      return -1;
   }

   std::fputs("done\n", stdout);

   std::fputs("\nTesting vector 2D ...\n", stdout);

   if (!test_vector2())
   {
      return -1;
   }

   std::fputs("done\n", stdout);

   std::fputs("\nTesting image ...\n", stdout);

   if (!test_image())
   {
      return -1;
   }

   std::fputs("done\n", stdout);

   return 0;
}
