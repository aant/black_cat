#pragma once

#include "../core/vector2.h"

namespace black_cat
{
   // window style enumeration
   enum class e_window_style : t_s32
   {
      INVALID = -1,

      BORDERLESS,
      FIXEDFRAME,
      RESIZIBLE
   };

   // pointer device cursor interface
   struct i_ptrdev_cursor;

   // window icon interface
   struct i_window_icon
   {
      virtual ~i_window_icon() noexcept = default;

      // gets the icon platform-specific handle
      virtual t_u64 get_handle() const noexcept = 0;

      // gets the icon size
      virtual const c_vec2i& get_size() const noexcept = 0;
   };

   // window event handler interface
   struct i_window_event_handler;

   // window interface
   struct i_window
   {
      virtual ~i_window() noexcept = default;

      // gets the window platform-specific handle
      virtual t_u64 get_handle() const noexcept = 0;

      // gets the window title
      // TODO: wchar_t* will be replaced later with a string class
      virtual const wchar_t* get_title() const noexcept = 0;

      // sets the window title
      // TODO: wchar_t* will be replaced later with a string class
      virtual t_bool set_title(const wchar_t* title) noexcept = 0;

      // gets the window icon
      virtual i_window_icon* get_icon() const noexcept = 0;

      // sets the window icon
      virtual t_bool set_icon(i_window_icon* icon) noexcept = 0;

      // gets the window cursor
      virtual i_ptrdev_cursor* get_cursor() const noexcept = 0;

      // sets the window cursor
      virtual t_bool set_cursor(i_ptrdev_cursor* cursor) noexcept = 0;

      // gets the window style
      virtual e_window_style get_style() const noexcept = 0;

      // gets the window client area position on screen
      virtual const c_vec2i& get_client_position() const noexcept = 0;

      // gets the window client area size
      virtual const c_vec2i& get_client_size() const noexcept = 0;

      // sets the window style and the client area rectangle
      // the final window position and size depend on the window style
      virtual t_bool set_shape(e_window_style style, const c_vec2i& client_position, const c_vec2i& client_size) noexcept = 0;

      // sets the window style and fits it in desired bounds
      virtual t_bool fit_shape(e_window_style style, const c_vec2i& bounds_origin, const c_vec2i& bounds_extents) noexcept = 0;

      // gets the window activity state
      virtual t_bool is_active() const noexcept = 0;

      // requests the window to be active
      virtual t_bool set_active() noexcept = 0;
      
      // gets the window visibility state
      virtual t_bool is_visible() const noexcept = 0;

      // sets the window visibility state
      virtual t_bool set_visible(t_bool visible) noexcept = 0;

      // gets the window event handler
      virtual i_window_event_handler* get_event_handler() const noexcept = 0;

      // sets the window event handler
      virtual void set_event_handler(i_window_event_handler* handler) noexcept = 0;

      // gets the user data associated with the window
      virtual void* get_user_data() const noexcept = 0;

      // sets the user data associated with the window
      virtual void set_user_data(void* data) noexcept = 0;

      // requests window system to redraw the contents of the window
      virtual void redraw_content() noexcept = 0;
   };

   // window event handler interface
   struct i_window_event_handler
   {
      virtual ~i_window_event_handler() noexcept = default;

      // occurs when the window title is changed
      virtual void title_changed(i_window& window) noexcept
      {
         static_cast<void>(window);
      }

      // occurs when the window style is changed
      virtual void style_changed(i_window& window, e_window_style prev_style) noexcept
      {
         static_cast<void>(window);
         static_cast<void>(prev_style);
      }

      // occurs when the window icon is changed
      virtual void icon_changed(i_window& window) noexcept
      {
         static_cast<void>(window);
      }

      // occurs when the window cursor is changed
      virtual void cursor_changed(i_window& window) noexcept
      {
         static_cast<void>(window);
      }

      // occurs when the window client position is changed
      virtual void client_position_changed(i_window& window, const c_vec2i& prev_client_position) noexcept
      {
         static_cast<void>(window);
         static_cast<void>(prev_client_position);
      }

      // occurs when the window client size is changed
      virtual void client_size_changed(i_window& window, const c_vec2i& prev_client_size) noexcept
      {
         static_cast<void>(window);
         static_cast<void>(prev_client_size);
      }

      // occurs when the window activity state is changed
      virtual void activity_state_changed(i_window& window) noexcept
      {
         static_cast<void>(window);
      }

      // occurs when the window visibility state is changed
      virtual void visibility_state_changed(i_window& window) noexcept
      {
         static_cast<void>(window);
      }

      // occurs when the window content is redrawing
      virtual void drawing_content(i_window& window) noexcept
      {
         static_cast<void>(window);
      }
   };

} // namespace black_cat
