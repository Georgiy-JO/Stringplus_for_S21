#include "s21_string.h"

int s21_memcmp(const void *str1_, const void *str2_, size_t n){
	int status = 0;
	unsigned char* str1 = (unsigned char*)str1_;
	unsigned char* str2 = (unsigned char*)str2_;
	unsigned char* end1 = str1 + n;
	while (str1 < end1 && !status){
		if (*str1++ != *str2++){
			status = *--str1 - *--str2;
		}
	}
	return status;
}
