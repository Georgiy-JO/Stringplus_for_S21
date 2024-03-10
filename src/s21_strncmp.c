#include "s21_string.h"

int s21_strncmp(const char* str1_, const char* str2_, size_t n) {
  int status = 0;
  unsigned char* str1 = (unsigned char*)str1_;
  unsigned char* str2 = (unsigned char*)str2_;

  for (size_t i = 0; i < n; i++){
	  if (str1[i] != str2[i]){
		  status = (int)(str1[i] - str2[i]);
		  break;
	  }
  }
  return status;
}
