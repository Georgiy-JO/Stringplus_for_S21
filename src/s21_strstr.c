#include "s21_string.h"

char* s21_strstr(const char* haystack, const char* needle) {
  const char* result = NULL;
  if (*needle == '\0') {
    result = haystack;
  } else {
    while (*haystack != '\0') {
      const char* h = haystack;
      const char* n = needle;

      while (*n != '\0' && *h == *n) {
        ++h;
        ++n;
      }
      if (*n == '\0') {
        result = haystack;
        break;
      }
      ++haystack;
    }
  }
  return (char*)result;
}
