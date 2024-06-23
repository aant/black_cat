#pragma once

#include "basic_math.h"

namespace black_cat
{
   #pragma pack (push, 1)

   // 2D vector class
   template <typename T>
   struct c_vec2
   {
      T x;
      T y;

      c_vec2() noexcept : x(), y() { }

      c_vec2(T x, T y) noexcept : x(x), y(y) { }

      t_bool operator == (const c_vec2& other) const noexcept
      {
         return x == other.x && y == other.y;
      }

      t_bool operator != (const c_vec2& other) const noexcept
      {
         return x != other.x || y != other.y;
      }

      c_vec2 operator + () const noexcept
      {
         return *this;
      }

      c_vec2 operator - () const noexcept
      {
         return c_vec2(-x, -y);
      }

      c_vec2 operator + (const c_vec2& other) const noexcept
      {
         return c_vec2(x + other.x, y + other.y);
      }

      c_vec2 operator + (T value) const noexcept
      {
         return c_vec2(x + value, y + value);
      }

      c_vec2 operator - (const c_vec2& other) const noexcept
      {
         return c_vec2(x - other.x, y - other.y);
      }

      c_vec2 operator - (T value) const noexcept
      {
         return c_vec2(x - value, y - value);
      }

      c_vec2 operator * (const c_vec2& other) const noexcept
      {
         return c_vec2(x * other.x, y * other.y);
      }

      c_vec2 operator * (T value) const noexcept
      {
         return c_vec2(x * value, y * value);
      }

      c_vec2 operator / (const c_vec2& other) const noexcept
      {
         BLACK_CAT_DIAGNOSTIC_CHECK_NOT_EQUAL(other.x, T(0));
         BLACK_CAT_DIAGNOSTIC_CHECK_NOT_EQUAL(other.y, T(0));
         return c_vec2(x / other.x, y / other.y);
      }

      c_vec2 operator / (T value) const noexcept
      {
         BLACK_CAT_DIAGNOSTIC_CHECK_NOT_EQUAL(value, T(0));
         return c_vec2(x / value, y / value);
      }

      c_vec2& operator += (const c_vec2& other) noexcept
      {
         x += other.x;
         y += other.y;
         return *this;
      }

      c_vec2& operator += (T value) noexcept
      {
         x += value;
         y += value;
         return *this;
      }

      c_vec2& operator -= (const c_vec2& other) noexcept
      {
         x -= other.x;
         y -= other.y;
         return *this;
      }

      c_vec2& operator -= (T value) noexcept
      {
         x -= value;
         y -= value;
         return *this;
      }

      c_vec2& operator *= (const c_vec2& other) noexcept
      {
         x *= other.x;
         y *= other.y;
         return *this;
      }

      c_vec2& operator *= (T value) noexcept
      {
         x *= value;
         y *= value;
         return *this;
      }

      c_vec2& operator /= (const c_vec2& other) noexcept
      {
         BLACK_CAT_DIAGNOSTIC_CHECK_NOT_EQUAL(other.x, T(0));
         BLACK_CAT_DIAGNOSTIC_CHECK_NOT_EQUAL(other.y, T(0));
         x /= other.x;
         y /= other.y;
         return *this;
      }

      c_vec2& operator /= (T value) noexcept
      {
         BLACK_CAT_DIAGNOSTIC_CHECK_NOT_EQUAL(value, T(0));
         x /= value;
         y /= value;
         return *this;
      }
   };

   #pragma pack (pop)

   // 32-bit signed integer 2D vector class
   using c_vec2i = c_vec2<t_s32>;

   // 32-bit floating point 2D vector class
   using c_vec2f = c_vec2<t_f32>;

   // converts an floating-point 2D vector to a integral one
   inline c_vec2i to_vec2i(const c_vec2f& vec) noexcept
   {
      return c_vec2i(t_s32(vec.x), t_s32(vec.y));
   }

   // converts an integral 2D vector to a floating-point one
   inline c_vec2f to_vec2f(const c_vec2i& vec) noexcept
   {
      return c_vec2f(t_f32(vec.x), t_f32(vec.y));
   }

   // linearly interpolates two 2D vectors
   inline c_vec2f lerp(const c_vec2f& vec1, const c_vec2f& vec2, t_f32 t) noexcept
   {
      return c_vec2f(lerp(vec1.x, vec2.x, t), lerp(vec1.y, vec2.y, t));
   }

   // calculates dot product of two 2D vectors
   inline t_f32 calc_dot(const c_vec2f& vec1, const c_vec2f& vec2) noexcept
   {
      return vec1.x * vec2.x + vec1.y * vec2.y;
   }

   // calculates squared length of a 2D vector
   inline t_f32 calc_sqlen(const c_vec2f& vec) noexcept
   {
      return calc_dot(vec, vec);
   }

   // calculates length of a 2D vector
   inline t_f32 calc_len(const c_vec2f& vec) noexcept
   {
      return calc_sqr(calc_sqlen(vec));
   }

   // calculates squared distance between two 2D points
   inline t_f32 calc_sqdist(const c_vec2f& pt1, const c_vec2f& pt2) noexcept
   {
      return calc_sqlen(pt2 - pt1);
   }

   // calculates distance between two 2D points
   inline t_f32 calc_dist(const c_vec2f& pt1, const c_vec2f& pt2) noexcept
   {
      return calc_sqr(calc_sqdist(pt1, pt2));
   }

} // namespace black_cat
