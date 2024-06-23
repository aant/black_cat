#include "utest.h"

#include "../core/image.h"

using namespace black_cat;

template <>
inline void utest_print_value<e_image_format>(e_image_format format, FILE* f_out) noexcept
{
   const t_char* format_str;

   switch (format)
   {
      case e_image_format::L8:
         format_str = "L8";
         break;
      case e_image_format::L8_A8:
         format_str = "L8_A8";
         break;
      case e_image_format::R8_G8_B8:
         format_str = "R8_G8_B8";
         break;
      case e_image_format::R8_G8_B8_A8:
         format_str = "R8_G8_B8_A8";
         break;
      case e_image_format::B8_G8_R8:
         format_str = "B8_G8_R8";
         break;
      case e_image_format::B8_G8_R8_A8:
         format_str = "B8_G8_R8_A8";
         break;
      case e_image_format::A8_R8_G8_B8:
         format_str = "A8_R8_G8_B8";
         break;
      case e_image_format::A8_B8_G8_R8:
         format_str = "A8_B8_G8_R8";
         break;
      case e_image_format::L16:
         format_str = "L16";
         break;
      case e_image_format::L16_A16:
         format_str = "L16_A16";
         break;
      case e_image_format::R16_G16_B16:
         format_str = "R16_G16_B16";
         break;
      case e_image_format::R16_G16_B16_A16:
         format_str = "R16_G16_B16_A16";
         break;
      case e_image_format::B16_G16_R16:
         format_str = "B16_G16_R16";
         break;
      case e_image_format::B16_G16_R16_A16:
         format_str = "B16_G16_R16_A16";
         break;
      case e_image_format::A16_R16_G16_B16:
         format_str = "A16_R16_G16_B16";
         break;
      case e_image_format::A16_B16_G16_R16:
         format_str = "A16_B16_G16_R16";
         break;
      default:
         format_str = "INVALID";
         break;
   }

   std::fputs(format_str, f_out);
}

bool test_image()
{
   UTEST_ASSERT_TRUE(c_image().is_empty());
   UTEST_ASSERT_EQUAL(c_image().get_format(), e_image_format::INVALID_ENUM);
   UTEST_ASSERT_EQUAL(c_image().get_size(), c_vec2i());
   UTEST_ASSERT_NULL(c_image().get_data());

   c_image image(e_image_format::R8_G8_B8, c_vec2i(4, 4));

   UTEST_ASSERT_EQUAL(image.get_format(), e_image_format::R8_G8_B8);
   UTEST_ASSERT_EQUAL(image.get_size(), c_vec2i(4, 4));
   UTEST_ASSERT_NOT_NULL(image.get_data());

   image.clear();

   UTEST_ASSERT_TRUE(c_image().is_empty());
   UTEST_ASSERT_EQUAL(c_image().get_format(), e_image_format::INVALID_ENUM);
   UTEST_ASSERT_EQUAL(c_image().get_size(), c_vec2i());
   UTEST_ASSERT_NULL(c_image().get_data());

   return true;
}
