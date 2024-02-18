#ifndef S21_STRING
#define S21_STRING

//Needed for sscanf && sprintf && S.String.P.F.
#include <stdarg.h>
#include <stdlib.h>  //--allowed?

#define size_t unsigned long int
#define symbol unsigned char
#define MY_NULL ((void *)0)
#ifndef NULL
#define NULL ((void *)0)
#endif

#define C_ZERO '\0'

//------------------------------------------------------------------------------------

//string functions
void *s21_memcpy(void *dest, const void *src, size_t n);
size_t s21_strlen(const char *str);
void *s21_memset(void *str, int c, size_t n);
char *s21_strncpy(char *dest, const char *src, size_t n);
char *s21_strncat(char *dest, const char *src, size_t n);
size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strtok(char *str, const char *delim);
void *s21_memchr(const void *str, int c, size_t n);
int s21_memcmp(const void *str1, const void *str2, size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, size_t n);
char *s21_strerror(int errnum);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);

//service functions
void padding(char* place, size_t length);   //Filling the line length n with \0 
char s21_isinstr(const char a, const char* str);    //checking if the char is in str

//------------------------------------------------------------------------------------

//sprintf - sends formatted output to a string pointed to, by str.
int s21_sprintf(char *str, const char *format, ...);

//------------------------------------------------------------------------------------

//sscanf - reads formatted input from a string.
int s21_sscanf(const char *str, const char *format, ...);
typedef struct variables variables; //is needed not to break the header file

char char_is_invis (const char tmp);
char char_is_num (const char tmp);
char char_is_hex (const char tmp);
int char_to_num (const char n);
char num_to_char (const int n);
int big_hex_to_num (const char n);
int small_hex_to_num (const char n);

void zero_struct(variables * var);
size_t var_counting (const char *format);

unsigned int uint_from_line(const char* line, size_t* move);
size_t ulong_from_line(const char* line, size_t* move);
unsigned short ushort_from_line(const char* line, size_t* move);
int int_from_line(const char* line, size_t* move);
long int long_from_line(const char* line, size_t* move);
short int short_from_line(const char* line, size_t* move);
unsigned int uoctal_from_line(const char* line, size_t* move);
unsigned short short_uoctal_from_line(const char* line, size_t* move);
size_t long_uoctal_from_line(const char* line, size_t* move);
int hex_from_line(const char* line, size_t* move);
short int short_hex_from_line(const char* line, size_t* move);
long int long_hex_from_line(const char* line, size_t* move);

char* string_cutter(char** str_coursor, const char* format_coursor);
char* spec_translator(variables* var_spec, const char* format);
char* var_filling(va_list* var, variables var_spec, char* str_coursor);

//------------------------------------------------------------------------------------

//Special string processing functions (from the String class in C#)
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

char char_is_lower_case(char a);
char char_is_upper_case(char a);
size_t head_tail_delta_finder (const char *src, const char *trim_chars, size_t* head_point);

//------------------------------------------------------------------------------------

#endif
