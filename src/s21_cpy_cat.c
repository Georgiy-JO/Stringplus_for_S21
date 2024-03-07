#include "s21_string.h"

// Copies n characters from src to dest.
void *s21_memcpy(void *dest, const void *src, size_t n) {
  symbol *destination = dest;
  symbol *source = (void *)src;
  for (size_t i = 0; i < n; i++) {
    //*(pointer+(sizeof(char)*i))=*(char*)(src+(sizeof(char)*i));
    *(destination + i) = *(source + i);
  }
  //*(destination+n)=C_ZERO;
  return dest;
}

// Copies up to n characters from the string pointed to, by src to dest.
char *s21_strncpy(char *dest, const char *src, size_t n) {
  size_t len_dest = 0, len_src = 0;
  for (size_t i = 0; i < n /*&& i<len_src*/; i++) {
    *(dest + i) = *(src + i);
  }
  len_dest = s21_strlen(dest);
  len_src = s21_strlen(src);
  if (len_dest <= n && len_src >= n)
    padding((dest + n), 1);  //*(dest+n)=C_ZERO;
  else if (len_src < n)
    padding((dest + len_src), n - len_src);
  return dest;
}

// Filling the line length n with \0
void padding(char *place, size_t length) {
  for (size_t i = 0; i < length; i++) {
    *(place + i) = C_ZERO;
  }
}

// Appends the string pointed to, by src to the end of the string pointed to, by
// dest up to n characters long.
char *s21_strncat(char *dest, const char *src, size_t n) {
  size_t len_src = 0, i = 0, len_dest = 0;
  len_src = s21_strlen(src);
  len_dest = s21_strlen(dest);
  for (; i < n && i < len_src; i++) {
    *(dest + i + len_dest) = *(src + i);
  }
  // padding(dest+i+len_dest, n-i+1);
  padding(dest + i + len_dest, 1);
  return dest;
}
