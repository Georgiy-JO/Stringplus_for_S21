#include "s21_string.h"

char* s21_strchr(const char* _str, int c) {
  size_t len = s21_strlen(_str);
  unsigned char* ptr = NULL;
  unsigned char* str = (unsigned char*)_str;
  for (size_t i = 0; i < len + 1; i++){
	  if (str[i] == c) {
		  ptr = &(str[i]);
		  break;
	  }
  }
  return (char*)ptr;
}
