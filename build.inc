#pragma message ("Building black_cat library...")
#pragma message ("Detecting C++ compiler...")

#if !defined (BLACK_CAT_COMPILER)
   #if defined (__GNUC__)
      #if defined (__clang__)
         #define BLACK_CAT_COMPILER_CLANG
         #define BLACK_CAT_COMPILER "CLang"
         #pragma message ("CLang C++ compiler was detected")
      #else
         #define BLACK_CAT_COMPILER_GCC
         #define BLACK_CAT_COMPILER "GCC"
         #pragma message ("GCC C++ compiler was detected")
      #endif
   #elif defined(_MSC_VER)
      #define BLACK_CAT_COMPILER_MSVC
      #define BLACK_CAT_COMPILER "MSVC"
      #pragma message ("MSVC C++ compiler was detected")
   #else
      #error "C++ compiler was not detected"
   #endif
#endif

#pragma message ("Detecting C++ version, the minimum 14 is required...")

#if (defined (__cplusplus) && (__cplusplus >= 201402L)) || (defined (_MSVC_LANG) && (_MSVC_LANG >= 201402L))
   #pragma message ("C++ 14 or greater was detected")
#else
   #error "C++ 14 or greater version was not detected"
#endif

#pragma message ("Detecting platform...")

#if !defined (BLACK_CAT_PLATFORM)
   #if (defined (__unix__) || defined (__unix) || defined (unix)) && (defined (__linux__) || defined (__linux) || defined (linux))
      #define BLACK_CAT_PLATFORM_LINUX
      #define BLACK_CAT_PLATFORM "Linux"
      #pragma message ("Linux platform was detected")
   #elif defined (_WIN32)
      #define BLACK_CAT_PLATFORM_WINDOWS
      #define BLACK_CAT_PLATFORM "Windows"
      #pragma message ("Windows platform was detected")
   #else
      #error "Platform was not detected"
   #endif
#endif
