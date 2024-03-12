#include "s21_string.h"

#define CASE_DIFF 32

// Returns a copy of string (str) converted to uppercase. In case of any error,
// return NULL
void *s21_to_upper(const char *str) {
  char *out_str = NULL;
  size_t n = s21_strlen(str);
  out_str = (char *)calloc(n + 1, sizeof(char));
  for (size_t i = 0; out_str != NULL && i < n; i++) {
    if (char_is_lower_case(str[i]))
      out_str[i] = str[i] - CASE_DIFF;
    else
      out_str[i] = str[i];
  }
  out_str[n] = C_ZERO;
  return (void *)out_str;
}

// Returns a copy of string (str) converted to lowercase. In case of any error,
// return NULL
void *s21_to_lower(const char *str) {
  char *out_str = NULL;
  size_t n = s21_strlen(str);
  out_str = (char *)calloc(n + 1, sizeof(char));
  for (size_t i = 0; out_str != NULL && i < n; i++) {
    if (char_is_upper_case(str[i]))
      out_str[i] = str[i] + CASE_DIFF;
    else
      out_str[i] = str[i];
  }
  out_str[n] = C_ZERO;
  return (void *)out_str;
}

// Returns a new string in which a specified string (str) is inserted at a
// specified index
//   position (start_index) in the given string (src). In case of any error,
//   return NULL
void *s21_insert(const char *src, const char *str, size_t start_index) {
  char *out_str = NULL;
  if (src!=NULL && str!=NULL){
    size_t src_len = s21_strlen(src);
    size_t str_len = s21_strlen(str);
    if (src_len >= start_index)
      out_str = (char *)calloc(src_len + str_len + 1, sizeof(char));
    if (out_str != NULL) {
      s21_strncpy(out_str, src, start_index);
      out_str[start_index]=C_ZERO;
      s21_strncat(out_str, str, str_len);
      s21_strncat(out_str, src + start_index, src_len-start_index);
    }
  }
  return (void *)out_str;
}

// Returns a new string in which all leading and trailing occurrences of a set
// of specified characters
//   (trim_chars) from the given string (src) are removed. In case of any error,
//   return NULL
void *s21_trim(const char *src, const char *trim_chars) {
  char *out_str = NULL;
  if(src!=NULL){
    size_t begining = 0, length = 0;
    char *loc_trim_ch = (char *) trim_chars, *whitespace_chars=" \t\n\r\v\f\0";
    if(!trim_chars || !s21_strlen(trim_chars))   loc_trim_ch = whitespace_chars;
    length = head_tail_delta_finder(src, loc_trim_ch, &begining);
    out_str = (char *)calloc(length + 1, sizeof(char));
    if(out_str!=NULL){
      for (size_t i = 0; i < length; i++, begining++) {
        out_str[i] = src[begining];
      }
      out_str[length] = C_ZERO;
    }
  }
  return (void *)out_str;
}

size_t head_tail_delta_finder(const char *src, const char *trim_chars,
                              size_t *head_point) {
  size_t tail_point = s21_strlen(src);
  if (tail_point != 0) {
    tail_point--;
    do {
      if (s21_isinstr(src[*head_point], trim_chars))
        (*head_point)++;
      else
        break;
    } while (*head_point <= tail_point);
    if (*head_point > tail_point)
      tail_point = 0;
    else {
      while (*head_point < tail_point) {
        if (s21_isinstr(src[tail_point], trim_chars))
          tail_point--;
        else
          break;
      }
      tail_point = 1 + tail_point - (*head_point);
    }
  }
  return tail_point;
}

char char_is_lower_case(char a) { return (a <= 'z' && a >= 'a') ? 1 : 0; }
char char_is_upper_case(char a) { return (a <= 'Z' && a >= 'A') ? 1 : 0; }