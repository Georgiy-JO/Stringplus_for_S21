#ifndef S21_STRING
#define S21_STRING

#include <stdio.h>

#define size_t unsigned long int
#define symbol unsigned char
#define MY_NULL ((void *)0)       //#define NULL ((void *)0)
#define C_ZERO '\0'

//void *s21_memchr(const void *str, int c, size_t n);
//int s21_memcmp(const void *str1, const void *str2, size_t n);

void *s21_memcpy(void *dest, const void *src, size_t n);
size_t s21_strlen(const char *str);
void *s21_memset(void *str, int c, size_t n);
char *s21_strncpy(char *dest, const char *src, size_t n);
void padding(char* place, size_t length);   //Filling the line length n with \0 
char *s21_strncat(char *dest, const char *src, size_t n);                           //NOT CHECKED MANUALY!
size_t s21_strcspn(const char *str1, const char *str2);                             //NOT CHECKED MANUALY!
char s21_isinstr(const char a, const char* str);    //checking if the char is in str
char *s21_strpbrk(const char *str1, const char *str2);                             //NOT CHECKED MANUALY!
char *s21_strtok(char *str, const char *delim);                                    //NOT CHECKED MANUALY!

// char *s21_strchr(const char *str, int c);
// int s21_strncmp(const char *str1, const char *str2, size_t n);
// char *s21_strerror(int errnum);
// char *s21_strrchr(const char *str, int c);
// char *s21_strstr(const char *haystack, const char *needle);

// int s21_sscanf(const char *str, const char *format, ...);
// int s21_sprintf(char *str, const char *format, ...);

#endif