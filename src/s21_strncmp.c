#include "s21_string.h"

int s21_strncmp(const char* str1_, const char* str2_, size_t n) {
  int status = 0;
  unsigned char* str1 = (unsigned char*)str1_;
  unsigned char* str2 = (unsigned char*)str2_;
  unsigned char* end1 = str1 + n;
  do {
    if (*str1++ != *str2++) {
      status = *--str1 - *--str2;
    }
  } while (str1 < end1 && *str1 != '\0' && *str2 != '\0' && !status);
  return status;
}
