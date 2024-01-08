#include "s21_string.h"

void *s21_memchr(const void *str, int c, size_t n){
	void* ptr = NULL;
	size_t size = sizeof(str);
	for (int i = 0; i < n && i < size; i++){
		if (str[i] == c) ptr = &(str[i]);
	}
	return ptr;
}
