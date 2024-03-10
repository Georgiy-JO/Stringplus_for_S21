#include <stdio.h>

#include "s21_string.h"

// Breaks string str into a series of tokens separated by delim.
char *s21_strtok(char *str, const char *delim) {
  static char *point = MY_NULL;
  static size_t i = 0;
  point = (str != NULL) ? (char *)str : point + i;  // MY_NULL
  for (i = 0; *(point + i) != C_ZERO; i++) {
    // printf("\n++%s\n",(point+i));
    if (s21_isinstr(*(point + i), delim)) {
      // printf("**\n");
      point[i] = C_ZERO;
      // printf("**\n");
      // printf("**\n");
      // printf("**\n");
      if (i != 0) {
        i++;
        break;
      } else {
        point = point + 1;
        i = -1;
      }
    }
    // printf("++\n");
  }
  if (*point == C_ZERO) point = MY_NULL;
  // printf("\n[][][]\n");
  return point;
}