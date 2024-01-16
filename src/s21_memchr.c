#include "s21_string.h"

void *s21_memchr(const void *_str, int c, size_t n){
	unsigned char* ptr = NULL;
	unsigned char* str = (unsigned char*)_str; 
	size_t size = sizeof(str);
	for (size_t i = 0; i < n && i < size; i++){
		if (str[i] == c) ptr = &(str[i]);
	}
	return (void*)ptr;
}
