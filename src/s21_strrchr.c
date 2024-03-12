#include "s21_string.h"

char* s21_strrchr(const char* _str, int c) {
  size_t len = s21_strlen(_str);
  unsigned char* ptr = NULL;
  unsigned char* str = (unsigned char*)_str;
  for (int i = (int)len + 1; i >= 0; i--) {
    if (str[i] == c) {
      ptr = &(str[i]);
      break;
    }
  }
  return (char*)ptr;
}
