#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, size_t n){
	int status = 0;
	size_t size1 = sizeof(str1);
	size_t size2 = sizeof(str2);
	for (int i = 0; i < n && i < str1 && i < str2 && status == 0; i++){
		status = str1[i] - str2[i];
	}
	return status;
}
