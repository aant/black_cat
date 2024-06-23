#pragma once

#include "../core/logger.h"

#include "window.h"

namespace black_cat
{
   // display device interface
   struct i_display
   {
      virtual ~i_display() noexcept = default;

      // gets the display platform-specific handle
      virtual t_u64 get_handle() const noexcept = 0;

      // gets the display origin on the screen
      virtual const c_vec2i& get_origin() const noexcept = 0;

      // gets the display resolution
      virtual const c_vec2i& get_resolution() const noexcept = 0;
   };

   // application event handler interface
   struct i_application_event_handler;

   // application interface
   struct i_application
   {
      virtual ~i_application() noexcept = default;

      // gets the application platform-specific handle
      virtual t_u64 get_handle() const noexcept = 0;

      // gets the number of available display devices
      virtual t_s32 get_display_count() const noexcept = 0;

      // gets the main display
      virtual const i_display& get_main_display() const noexcept = 0;

      // gets the display at index or NULL if index is invalid
      virtual const i_display* get_display(t_s32 index) const noexcept = 0;

      // finds the nearest display to the specified point on the screen
      virtual const i_display& find_nearest_display(const c_vec2i& point) const noexcept = 0;

      // gets the window 
      virtual i_window& get_window() const noexcept = 0;

      // gets the application event handler
      virtual i_application_event_handler* get_event_handler() const noexcept = 0;

      // sets the application event handler
      virtual void set_event_handler(i_application_event_handler* handler) noexcept = 0;

      // gets the user data associated with the application
      virtual void* get_user_data() const noexcept = 0;

      // sets the user data associated with the application
      virtual void set_user_data(void* data) noexcept = 0;

      // runs the application main loop
      virtual t_bool run() noexcept = 0;

      // shutdowns the application main loop
      virtual t_bool shutdown() noexcept = 0;
   };

   // application event handler interface
   struct i_application_event_handler
   {
      virtual ~i_application_event_handler() noexcept = default;

      // occurs when the application is going to sleep or is waked up
      virtual void power_status_changed(i_application& app, t_bool power_on) noexcept
      {
         static_cast<void>(app);
         static_cast<void>(power_on);
      }

      // occurs when the display list is changed (some display is connected or is disconnected to the system)
      virtual void display_list_changed(i_application& app) noexcept
      {
         static_cast<void>(app);
      }

      // occurs when a display resolution is changed
      virtual void display_resolution_changed(i_application& app, t_s32 display_index) noexcept
      {
         static_cast<void>(app);
         static_cast<void>(display_index);
      }
   };

   // creates the application instance
   // returns NULL if there is no free memory available or if an instance of the application is already created
   extern i_application* create_application(i_logger* logger = nullptr) noexcept;

} // namespace black_cat
