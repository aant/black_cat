#pragma once

#include "basic_types.h"

namespace black_cat
{
   // logger interface
   struct i_logger
   {
      virtual ~i_logger() noexcept = default;

      virtual void write_message(const t_char* message) noexcept = 0;

      virtual void write_warning(const t_char* description) noexcept = 0;

      virtual void write_error(const t_char* description, t_u64 error_code) noexcept = 0;
   };

} // namespace black_cat
