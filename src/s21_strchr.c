#include "s21_string.h"

char *s21_strchr(const char *_str, int c){
	unsigned char* ptr = NULL;
	unsigned char* str = (unsigned char*)_str; 
	while(*str != '\0'){
		if (*str == c){
			ptr = str;
			break;
		}
		str++;
	}
	return (char*)ptr;
}
