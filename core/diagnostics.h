#pragma once

// TODO: would be implemented later

#if defined (BLACK_CAT_DIAGNOSTICS_ENABLED)

   #define BLACK_CAT_DIAGNOSTIC_CHECK_NULL(expression) ((void)0)
   #define BLACK_CAT_DIAGNOSTIC_CHECK_NOT_NULL(expression) ((void)0)
   #define BLACK_CAT_DIAGNOSTIC_CHECK_TRUE(expression) ((void)0)
   #define BLACK_CAT_DIAGNOSTIC_CHECK_FALSE(expression) ((void)0)
   #define BLACK_CAT_DIAGNOSTIC_CHECK_LESS(expression, expected) ((void)0)
   #define BLACK_CAT_DIAGNOSTIC_CHECK_LESS_EQUAL(expression, expected) ((void)0)
   #define BLACK_CAT_DIAGNOSTIC_CHECK_EQUAL(expression, expected) ((void)0)
   #define BLACK_CAT_DIAGNOSTIC_CHECK_GREATER_EQUAL(expression, expected) ((void)0)
   #define BLACK_CAT_DIAGNOSTIC_CHECK_GREATER(expression, expected) ((void)0)
   #define BLACK_CAT_DIAGNOSTIC_CHECK_NOT_EQUAL(expression, expected) ((void)0)
   #define BLACK_CAT_DIAGNOSTIC_CHECK_RANGE(expression, minimum, maximum) ((void)0)

#else

   #define BLACK_CAT_DIAGNOSTIC_CHECK_NULL(expression) ((void)0)
   #define BLACK_CAT_DIAGNOSTIC_CHECK_NOT_NULL(expression) ((void)0)
   #define BLACK_CAT_DIAGNOSTIC_CHECK_TRUE(expression) ((void)0)
   #define BLACK_CAT_DIAGNOSTIC_CHECK_FALSE(expression) ((void)0)
   #define BLACK_CAT_DIAGNOSTIC_CHECK_LESS(expression, expected) ((void)0)
   #define BLACK_CAT_DIAGNOSTIC_CHECK_LESS_EQUAL(expression, expected) ((void)0)
   #define BLACK_CAT_DIAGNOSTIC_CHECK_EQUAL(expression, expected) ((void)0)
   #define BLACK_CAT_DIAGNOSTIC_CHECK_GREATER_EQUAL(expression, expected) ((void)0)
   #define BLACK_CAT_DIAGNOSTIC_CHECK_GREATER(expression, expected) ((void)0)
   #define BLACK_CAT_DIAGNOSTIC_CHECK_NOT_EQUAL(expression, expected) ((void)0)
   #define BLACK_CAT_DIAGNOSTIC_CHECK_RANGE(expression, minimum, maximum) ((void)0)

#endif
