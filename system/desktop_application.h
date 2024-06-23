#pragma once

#include "../core/image.h"
#include "../core/logger.h"

namespace black_cat
{
   // window style enumeration
   enum class e_window_style : t_s32
   {
      INVALID_ENUM = -1,

      BORDERLESS,
      FIXEDFRAME,
      RESIZIBLE
   };

   // mouse button enumeration
   enum class e_mouse_button : t_s32
   {
      INVALID_ENUM = -1,

      LEFT,
      RIGHT,
      MIDDLE,
      EXTRA1,
      EXTRA2,

      ENUM_COUNT
   };

   static constexpr t_s32 MAX_MOUSE_BUTTONS = t_s32(e_mouse_button::ENUM_COUNT);

   // keyboard key enumeration
   enum class e_keyboard_key : t_s32
   {
      INVALID_ENUM = -1,

      // system keys

      ESCAPE,
      SHIFT_LEFT,
      SHIFT_RIGHT,
      CONTROL_LEFT,
      CONTROL_RIGHT,
      ALT_LEFT,
      ALT_RIGHT,

      COMMAND_LEFT,
      COMMAND_RIGHT,

      WINDOWS_LEFT = COMMAND_LEFT,
      WINDOWS_RIGHT = COMMAND_RIGHT,

      PAUSE,
      BREAK,
      SNAPSHOT,
      APPLICATION,
      SYSRQ,
      CAPS_LOCK,
      SCROLL_LOCK,

      // editing keys

      INSERT,
      DELETE,
      BACKSPACE,
      ENTER,

      // navigation keys

      ARROW_LEFT,
      ARROW_RIGHT,
      ARROW_UP,
      ARROW_DOWN,
      HOME,
      END,
      PAGE_UP,
      PAGE_DOWN,

      // functional keys

      F1,
      F2,
      F3,
      F4,
      F5,
      F6,
      F7,
      F8,
      F9,
      F10,
      F11,
      F12,
      F13,
      F14,
      F15,
      F16,
      F17,
      F18,
      F19,
      F20,
      F21,
      F22,
      F23,
      F24,

      // numeric pad keys

      NUMPAD_LOCK,
      NUMPAD_0,
      NUMPAD_1,
      NUMPAD_2,
      NUMPAD_3,
      NUMPAD_4,
      NUMPAD_5,
      NUMPAD_6,
      NUMPAD_7,
      NUMPAD_8,
      NUMPAD_9,
      NUMPAD_PLUS,
      NUMPAD_MINUS,
      NUMPAD_MULTIPLY,
      NUMPAD_DIVIDE,
      NUMPAD_CLEAR,
      NUMPAD_DECIMAL,
      NUMPAD_ENTER,

      // punctuation keys

      SPACE,
      TABULATOR,
      COMMA,
      PERIOD,
      APOSTROPHE,
      BACKTICK,
      SEMICOLON,
      SLASH,
      BACKSLASH,
      BRACKET_LEFT,
      BRACKET_RIGHT,
      MINUS,
      EQUALS,

      // digital keys

      D0,
      D1,
      D2,
      D3,
      D4,
      D5,
      D6,
      D7,
      D8,
      D9,

      // alphabetic keys

      A,
      B,
      C,
      D,
      E,
      F,
      G,
      H,
      I,
      J,
      K,
      L,
      M,
      N,
      O,
      P,
      Q,
      R,
      S,
      T,
      U,
      V,
      W,
      X,
      Y,
      Z,

      ENUM_COUNT
   };

   static constexpr t_s32 MAX_KEYBOARD_KEYS = t_s32(e_keyboard_key::ENUM_COUNT);

   // keyboard indicator enumeration
   enum class e_keyboard_indicator : t_s32
   {
      INVALID_ENUM = -1,

      CAPS_LOCK,
      SCROLL_LOCK,
      NUMPAD_LOCK,

      ENUM_COUNT
   };

   static constexpr t_s32 MAX_KEYBOARD_INDICATORS = t_s32(e_keyboard_indicator::ENUM_COUNT);

   // display device interface
   struct i_display;

   // window interface
   struct i_window;

   // mouse device interface
   struct i_mouse_device;

   // mouse cursor interface
   struct i_mouse_cursor;

   // keyboard device interface
   struct i_keyboard;

   // application event handler interface
   struct i_application_event_handler;

   // application configuration class
   struct c_application_config;

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

      // gets the display at index
      virtual const i_display& get_display(t_s32 index) const noexcept = 0;

      // finds the nearest display to the specified point on the screen
      virtual const i_display& find_nearest_display(const c_vec2i& point) const noexcept = 0;

      // gets the window 
      virtual i_window& get_window() const noexcept = 0;

      // gets the mouse device
      virtual i_mouse_device& get_mouse() const noexcept = 0;

      // gets the default mouse cursor
      virtual i_mouse_cursor& get_default_mouse_cursor() const noexcept = 0;

      // creates the mouse cursor from an image and hot spot
      virtual i_mouse_cursor* create_mouse_cursor(const c_image& image, const c_vec2i& hot_spot) noexcept = 0;

      // gets the keyboard
      virtual i_keyboard& get_keyboard() const noexcept = 0;

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

      // gets the window style
      virtual e_window_style get_style() const noexcept = 0;

      // gets the window client area position on screen
      virtual const c_vec2i& get_client_position() const noexcept = 0;

      // gets the window client area size
      virtual const c_vec2i& get_client_size() const noexcept = 0;

      // sets the window style and the client area rectangle
      // the final window position and size depend on the window style
      virtual t_bool set_shape(e_window_style style, const c_vec2i& client_position, const c_vec2i& client_size) noexcept = 0;

      // sets the window style and fits it in the desired rectangle on the screen
      virtual t_bool fit_shape(e_window_style style, const c_vec2i& bounding_rect_origin, const c_vec2i& bounding_rect_size) noexcept = 0;

      // gets the window activity state
      virtual t_bool is_active() const noexcept = 0;

      // requests the window to be active
      virtual t_bool set_active() noexcept = 0;
      
      // gets the window visibility state
      virtual t_bool is_visible() const noexcept = 0;

      // sets the window visibility state
      virtual t_bool set_visible(t_bool visible) noexcept = 0;

      // requests window system to redraw the contents of the window
      virtual t_bool redraw_content() noexcept = 0;
   };

   // mouse device interface
   struct i_mouse_device
   {
      virtual ~i_mouse_device() noexcept = default;

      // gets the mouse platform-specific handle
      virtual t_u64 get_handle() const noexcept = 0;

      // gets the mouse button state
      virtual t_bool is_button_pressed(e_mouse_button button) const noexcept = 0;

      // gets the mouse pointer position on the window client area
      virtual const c_vec2i& get_position(e_mouse_button button) const noexcept = 0;

      // sets the mouse pointer position on the window client area
      virtual t_bool set_position(const c_vec2i& position) noexcept = 0;

      // gets the mouse locked state
      virtual t_bool is_locked() const noexcept = 0;

      // locks the mouse in the specified rectangular area on the screen
      virtual t_bool lock(const c_vec2i& lock_rect_origin, const c_vec2i& lock_rect_size) noexcept = 0;

      // unlocks the mouse
      virtual t_bool unlock() noexcept = 0;
   };

   // mouse cursor interface
   struct i_mouse_cursor
   {
      virtual ~i_mouse_cursor() noexcept = default;

      // gets the cursor platform-specific handle
      virtual t_u64 get_handle() const noexcept = 0;

      // gets the cursor size
      virtual const c_vec2i& get_size() const noexcept = 0;

      // gets the cursor hot spot
      virtual const c_vec2i& get_hot_spot() const noexcept = 0;
   };

   // keyboard device interface
   struct i_keyboard
   {
      virtual ~i_keyboard() noexcept = default;

      // gets the keyboard platform-specific handle
      virtual t_u64 get_handle() const noexcept = 0;

      // gets the keyboard key state
      virtual t_bool is_key_pressed(e_keyboard_key key) const noexcept = 0;

      // gets the keyboard indicator state
      virtual t_bool is_indicator_on(e_keyboard_indicator indicator) const noexcept = 0;
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
      virtual void display_list_changed(i_application& app, t_s32 prev_display_count) noexcept
      {
         static_cast<void>(app);
         static_cast<void>(prev_display_count);
      }

      // occurs when a display resolution is changed
      virtual void display_resolution_changed(i_application& app,
         t_s32 display_index,
         const c_vec2i& prev_resolution,
         const c_vec2i& new_resolution) noexcept
      {
         static_cast<void>(app);
         static_cast<void>(display_index);
         static_cast<void>(prev_resolution);
         static_cast<void>(new_resolution);
      }

      // occurs when the window title is changed
      virtual void window_title_changed(i_application& app) noexcept
      {
         static_cast<void>(app);
      }

      // occurs when the window style is changed
      virtual void window_style_changed(i_application& app, e_window_style prev_style) noexcept
      {
         static_cast<void>(app);
         static_cast<void>(prev_style);
      }

      // occurs when the window client position is changed
      virtual void window_client_position_changed(i_application& app, const c_vec2i& prev_position) noexcept
      {
         static_cast<void>(app);
         static_cast<void>(prev_position);
      }

      // occurs when the window client size is changed
      virtual void window_client_size_changed(i_application& app, const c_vec2i& prev_size) noexcept
      {
         static_cast<void>(app);
         static_cast<void>(prev_size);
      }

      // occurs when the window activity state is changed
      virtual void window_activity_state_changed(i_application& app, t_bool active) noexcept
      {
         static_cast<void>(app);
         static_cast<void>(active);
      }

      // occurs when the window visibility state is changed
      virtual void window_visibility_state_changed(i_application& app, t_bool visible) noexcept
      {
         static_cast<void>(app);
         static_cast<void>(visible);
      }

      // occurs when the window content is redrawing
      virtual void window_redrawing_content(i_application& app) noexcept
      {
         static_cast<void>(app);
      }

      // occurs when the mouse is moved over the window client area
      // the movement delta is in DPI (not in pixels) and is not affected by any mouse ballistics
      virtual void mouse_moved(i_application& app, const c_vec2i& movement_delta, const c_vec2i& prev_position) noexcept
      {
         static_cast<void>(app);
         static_cast<void>(movement_delta);
         static_cast<void>(prev_position);
      }

      // occurs when the mouse wheel is scrolled
      virtual void mouse_scrolled(i_application& app, const c_vec2i& scrolling_delta) noexcept
      {
         static_cast<void>(app);
         static_cast<void>(scrolling_delta);
      }

      // occurs when the mouse button state is changed
      virtual void mouse_button_state_changed(i_application& app, e_mouse_button button) noexcept
      {
         static_cast<void>(app);
         static_cast<void>(button);
      }

      // occurs when the keyboard key state is changed
      virtual void keyboard_key_state_changed(i_application& app, e_keyboard_key key) noexcept
      {
         static_cast<void>(app);
         static_cast<void>(key);
      }
   };

   // application configuration class
   struct c_application_config
   {
      c_image window_icon;
      const wchar_t* window_title;
   };

   // creates the application instance
   // returns NULL if there is no free memory available or if an instance of the application is already created
   extern i_application* create_application(const c_application_config& config, i_logger* logger = nullptr) noexcept;

} // namespace black_cat
