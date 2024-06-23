#pragma once

#include "vector2.h"

#include <cstring>
#include <new>

namespace black_cat
{
   enum class e_image_format : t_s32
   {
      INVALID_ENUM = -1,

      L8,
      L8_A8,

      R8_G8_B8,
      R8_G8_B8_A8,

      B8_G8_R8,
      B8_G8_R8_A8,

      A8_R8_G8_B8,
      A8_B8_G8_R8,

      L16,
      L16_A16,

      R16_G16_B16,
      R16_G16_B16_A16,

      B16_G16_R16,
      B16_G16_R16_A16,

      A16_R16_G16_B16,
      A16_B16_G16_R16,

      ENUM_COUNT
   };

   // image class
   struct c_image
   {
   private:

      e_image_format m_format;
      c_vec2i m_size;
      t_u8* m_data;

   public:

      c_image() noexcept : m_format(e_image_format::INVALID_ENUM), m_size(), m_data() { }

      c_image(const c_image& other) noexcept
      {
         build(other.m_format, other.m_size, other.m_data);
      }

      c_image& operator = (const c_image& other) noexcept
      {
         if (this != &other)
         {
            safe_destroy();
            build(other.m_format, other.m_size, other.m_data);
         }

         return *this;
      }

      c_image(c_image&& other) noexcept : m_format(other.m_format), m_size(other.m_size), m_data(other.m_data)
      {
         other.m_data = nullptr;
      }

      c_image& operator = (c_image&& other) noexcept
      {
         m_format = other.m_format;
         m_size = other.m_size;
         m_data = other.m_data;
         other.m_data = nullptr;
         return *this;
      }

      c_image(e_image_format format, const c_vec2i& size, const t_u8* data = nullptr) noexcept
      {
         build(format, size, data);
      }

      ~c_image() noexcept
      {
         safe_destroy();
      }

      t_bool is_empty() const noexcept
      {
         return m_data == nullptr;
      }

      e_image_format get_format() const noexcept
      {
         return m_format;
      }

      const c_vec2i& get_size() const noexcept
      {
         return m_size;
      }

      const t_u8* get_data() const noexcept
      {
         return m_data;
      }

      t_u8* access_data() noexcept
      {
         return m_data;
      }

      void clear() noexcept
      {
         if (m_data)
         {
            ::operator delete (m_data);
            m_format = e_image_format::INVALID_ENUM;
            m_size = c_vec2i();
            m_data = nullptr;
         }
      }

   private:

      static std::size_t get_pixel_size(e_image_format format) noexcept
      {
         switch (format)
         {
            case e_image_format::L8:
               return 1;
            case e_image_format::L8_A8:
               return 2;
            case e_image_format::R8_G8_B8:
               return 3;
            case e_image_format::R8_G8_B8_A8:
               return 4;
            case e_image_format::B8_G8_R8:
               return 3;
            case e_image_format::B8_G8_R8_A8:
               return 4;
            case e_image_format::A8_R8_G8_B8:
               return 4;
            case e_image_format::A8_B8_G8_R8:
               return 4;
            case e_image_format::L16:
               return 2;
            case e_image_format::L16_A16:
               return 4;
            case e_image_format::R16_G16_B16:
               return 6;
            case e_image_format::R16_G16_B16_A16:
               return 8;
            case e_image_format::B16_G16_R16:
               return 6;
            case e_image_format::B16_G16_R16_A16:
               return 8;
            case e_image_format::A16_R16_G16_B16:
               return 8;
            case e_image_format::A16_B16_G16_R16:
               return 8;
            default:
               return 0;
         }
      }

      void build(e_image_format format, const c_vec2i& size, const t_u8* data) noexcept
      {
         if (format == e_image_format::INVALID_ENUM || size.x < 1 || size.y < 1)
         {
            return;
         }

         const ::std::size_t mem_size = get_pixel_size(format) * ::std::size_t(size.x) * std::size_t(size.y);
         m_data = static_cast<t_u8*>(::operator new (mem_size, ::std::nothrow));

         if (m_data)
         {
            m_format = format;
            m_size = size;

            if (data)
            {
               ::std::memcpy(m_data, data, mem_size);
            }
         }
         else
         {
            m_format = e_image_format::INVALID_ENUM;
            m_size = c_vec2i();
         }
      }

      void safe_destroy() noexcept
      {
         if (m_data)
         {
            ::operator delete (m_data);
         }
      }
   };

} // namespace black_cat
