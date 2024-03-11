#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "s21_string.h"
// elevator

#define NULL_LINE "\0"  // 2+
#define INVIS_CHAR                                                             \
  {                                                                            \
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, \
        22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32                             \
  }  // 32(33)
#define NULL_END_line \
  { 'g', 'h', 't', '\0' }  // 4(5)
#define ENTER_END_line \
  { 'g', 'h', 't', '\n' }  // 4(5)
#define TAB_END_line \
  { 'g', 'h', 't', '\t' }  // 4(5)
#define NULL_MID_line \
  { 'Z', 'F', '\0', 'T' }  // 4(5)
#define ENTER_MID_line \
  { 'g', 'h', '\n', 't' }  // 4(5)
#define TAB_MID_line \
  { 'g', '\t', 'h', 't' }     // 4(5)
#define FRIVE_CHAR_1 "ggggg"  // 5(6)
#define FRIVE_CHAR_2 "fffff"  // 5(6)
#define FOUR_CHAR "asdf"      // 4(5)
#define LONG_CHECK_LINE 100001
#define NORMLINES_SIX 6

// s21_strlen -->1.1-1.6
// s21_memset -->2.0-2.7
// s21_memcpy  -->3.0-3.5
// s21_strncpy -->4.0-4.5
// s21_strncat -->5.0-5.5
// s21_strcspn -->6.0-6.4
// s21_strpbrk -->7.0-7.4
// s21_strtok -->8.0-8.4
// s21_sscanf -->9.0-9.23

// elevator
void rand_str(char* line, size_t n) {
  srand((unsigned)time(NULL));
  symbol sim = C_ZERO;
  for (size_t i = 0; i < n; i++) {
    sim = rand() % 255 + 1;
    if (sim == '\t' || sim == '\n') sim = 55;
    line[i] = sim;
  }
}

START_TEST(test_settings) { ck_assert_ptr_eq(NULL, MY_NULL); }

// s21_memcmp   //elevator
START_TEST(test_memcmp) {
  char* str1 = "hello";
  char* str2 = "hello";
  size_t n = 4;
  int result = s21_memcmp(str1, str2, n);
  int expected = memcmp(str1, str2, n);
  ck_assert_int_eq(result, expected);
}
START_TEST(test_memcmp_2) {
  char* str1 = "hello";
  char* str2 = "hallo";
  size_t n = 4;
  int result = s21_memcmp(str1, str2, n);
  int expected = memcmp(str1, str2, n);
  ck_assert_int_eq(result, expected);
}
START_TEST(test_memcmp_3) {
  char* str1 = "hello";
  char* str2 = "h3llo";
  size_t n = 4;
  int result = s21_memcmp(str1, str2, n);
  int expected = memcmp(str1, str2, n);
  ck_assert_int_eq(result, expected);
}
/*                          //WERROR -- overread
START_TEST(test_memcmp_4) {
        char* str1 = "hello";
        char* str2 = "";
        size_t n = 4;
        int result = s21_memcmp(str1, str2, n);
        int expected = memcmp(str1, str2, n);
        ck_assert_int_eq(result, expected);
}

START_TEST(test_memcmp_5) {
        char* str1 = "";
        char* str2 = "hello";
        size_t n = 4;
        int result = s21_memcmp(str1, str2, n);
        int expected = memcmp(str1, str2, n);
        ck_assert_int_eq(result, expected);
}

START_TEST(test_memcmp_6) {
        char* str1 = "";
        char* str2 = "";
        size_t n = 4;
        int result = s21_memcmp(str1, str2, n);
        int expected = memcmp(str1, str2, n);
        ck_assert_int_eq(result, expected);
}
*/

// s21_strmcmp   //elevator
START_TEST(test_strncmp) {
  char* str1 = "hello";
  char* str2 = "hello";
  size_t n = 4;
  int result = s21_strncmp(str1, str2, n);
  int expected = strncmp(str1, str2, n);
  ck_assert_int_eq(result, expected);
}
START_TEST(test_strncmp_2) {
  char* str1 = "hello";
  char* str2 = "hallo";
  size_t n = 4;
  int result = s21_strncmp(str1, str2, n);
  int expected = strncmp(str1, str2, n);
  ck_assert_int_gt(expected, 0);
  ck_assert_int_gt(result, 0);
}
START_TEST(test_strncmp_3) {
  char* str1 = "hello";
  char* str2 = "h3llo";
  size_t n = 4;
  int result = s21_strncmp(str1, str2, n);
  int expected = strncmp(str1, str2, n);
  ck_assert_int_gt(expected, 0);
  ck_assert_int_gt(result, 0);
}
START_TEST(test_strncmp_4) {
  char* str1 = "hello";
  char* str2 = "";
  size_t n = 4;
  int result = s21_strncmp(str1, str2, n);
  int expected = strncmp(str1, str2, n);
  ck_assert_int_gt(expected, 0);
  ck_assert_int_gt(result, 0);
}
START_TEST(test_strncmp_5) {
  char* str1 = "";
  char* str2 = "hello";
  size_t n = 4;
  int result = s21_strncmp(str1, str2, n);
  int expected = strncmp(str1, str2, n);
  ck_assert_int_lt(expected, 0);
  ck_assert_int_lt(result, 0);
}
START_TEST(test_strncmp_6) {
  char* str1 = "";
  char* str2 = "";
  size_t n = 4;
  int result = s21_strncmp(str1, str2, n);
  int expected = strncmp(str1, str2, n);
  ck_assert_int_eq(result, expected);
}

// s21_memchr   //elevator
START_TEST(test_memchr) {
  char* str1 = "hello";
  int c = 'l';
  size_t n = 4;
  char* result = s21_memchr(str1, c, n);
  char* expected = memchr(str1, c, n);
  ck_assert_ptr_eq(result, expected);
}
START_TEST(test_memchr_2) {
  char* str1 = "hello";
  int c = 'f';
  size_t n = 4;
  char* result = s21_memchr(str1, c, n);
  char* expected = memchr(str1, c, n);
  ck_assert_ptr_eq(result, expected);
}
/*   //WERROR -- overread
START_TEST(test_memchr_3) {
        char* str1 = "hello";
        int c = 'f';
        size_t n = 10;
        char* result = s21_memchr(str1, c, n);
        char* expected = memchr(str1, c, n);
        ck_assert_ptr_eq(result, expected);
}
*/

// s21_strchr   //elevator
START_TEST(test_strchr) {
  char* str1 = "hello";
  int c = 'l';
  char* result = s21_strchr(str1, c);
  char* expected = strchr(str1, c);
  ck_assert_ptr_eq(result, expected);
}
START_TEST(test_strchr_2) {
  char* str1 = "hello";
  int c = 'f';
  char* result = s21_strchr(str1, c);
  char* expected = strchr(str1, c);
  ck_assert_ptr_eq(result, expected);
}
START_TEST(test_strchr_3) {
  char* str1 = "hello";
  int c = 'f';
  char* result = s21_strchr(str1, c);
  char* expected = strchr(str1, c);
  ck_assert_ptr_eq(result, expected);
}
START_TEST(test_strchr_4) {
  char* str1 = "hello\0bye";
  int c = 'y';
  char* result = s21_strchr(str1, c);
  char* expected = strchr(str1, c);
  ck_assert_ptr_eq(result, expected);
}

// s21_strrchr   //elevator
START_TEST(test_strrchr) {
  char* str1 = "hello";
  int c = 'l';
  char* result = s21_strrchr(str1, c);
  char* expected = strrchr(str1, c);
  ck_assert_ptr_eq(result, expected);
}
START_TEST(test_strrchr_2) {
  char* str1 = "hello";
  int c = 'f';
  char* result = s21_strrchr(str1, c);
  char* expected = strrchr(str1, c);
  ck_assert_ptr_eq(result, expected);
}
START_TEST(test_strrchr_3) {
  char* str1 = "hello";
  int c = 'f';
  char* result = s21_strrchr(str1, c);
  char* expected = strrchr(str1, c);
  ck_assert_ptr_eq(result, expected);
}
START_TEST(test_strrchr_4) {
  char* str1 = "hello\0bye";
  int c = 'y';
  char* result = s21_strrchr(str1, c);
  char* expected = strrchr(str1, c);
  ck_assert_ptr_eq(result, expected);
}

// s21_strstr   //elevator
START_TEST(test_strstr) {
  char* str1 = "hello";
  char* str2 = "lo";
  char* result = s21_strstr(str1, str2);
  char* expected = strstr(str1, str2);
  ck_assert_ptr_eq(result, expected);
}
START_TEST(test_strstr_2) {
  char* str1 = "hello";
  char* str2 = "abc";
  char* result = s21_strstr(str1, str2);
  char* expected = strstr(str1, str2);
  ck_assert_ptr_eq(result, expected);
}
START_TEST(test_strstr_3) {
  char* str1 = "hello";
  char* str2 = "";
  char* result = s21_strstr(str1, str2);
  char* expected = strstr(str1, str2);
  ck_assert_ptr_eq(result, expected);
}
START_TEST(test_strstr_4) {
  char* str1 = "";
  char* str2 = "hello";
  char* result = s21_strstr(str1, str2);
  char* expected = strstr(str1, str2);
  ck_assert_ptr_eq(result, expected);
}
START_TEST(test_strstr_5) {
  char* str1 = "";
  char* str2 = "";
  char* result = s21_strstr(str1, str2);
  char* expected = strstr(str1, str2);
  ck_assert_ptr_eq(result, expected);
}
START_TEST(test_strstr_6) {
  char* str1 = "hello\0bye";
  char* str2 = "bye";
  char* result = s21_strstr(str1, str2);
  char* expected = strstr(str1, str2);
  ck_assert_ptr_eq(result, expected);
}

// s21_strlen    //elevator
// 1.1
START_TEST(test_strlen_usual_1) {
  char line[5] = FRIVE_CHAR_1;
  ck_assert_int_eq(strlen(line), s21_strlen(line));
}
START_TEST(test_strlen_usual_2) {
  char line[6] = FRIVE_CHAR_1;
  ck_assert_int_eq(strlen(line), s21_strlen(line));
}
START_TEST(test_strlen_usual_3) {
  char line[7] = FRIVE_CHAR_1;
  ck_assert_int_eq(strlen(line), s21_strlen(line));
}
START_TEST(test_strlen_usual_4) {
  char line[8] = FRIVE_CHAR_1;
  ck_assert_int_eq(strlen(line), s21_strlen(line));
}
// 1.2
START_TEST(test_strlen_nullline) {
  char line[8] = NULL_LINE;
  ck_assert_int_eq(strlen(line), s21_strlen(line));
}
// 1.3
START_TEST(test_strlen_nullendline) {
  char line[4] = NULL_END_line;
  ck_assert_int_eq(strlen(line), s21_strlen(line));
}
START_TEST(test_strlen_enterendline_1) {
  char line[4] = ENTER_END_line;
  ck_assert_int_eq(strlen(line), s21_strlen(line));
}
START_TEST(test_strlen_enterendline_2) {
  char line[5] = ENTER_END_line;
  ck_assert_int_eq(strlen(line), s21_strlen(line));
}
START_TEST(test_strlen_tabendline_1) {
  char line[4] = TAB_END_line;
  ck_assert_int_eq(strlen(line), s21_strlen(line));
}
START_TEST(test_strlen_tabendline_2) {
  char line[5] = TAB_END_line;
  ck_assert_int_eq(strlen(line), s21_strlen(line));
}
// 1.4
START_TEST(test_strlen_nullmidline_1) {
  char line[4] = NULL_MID_line;
  ck_assert_int_eq(strlen(line), s21_strlen(line));
}
START_TEST(test_strlen_nullmidline_2) {
  char line[5] = NULL_MID_line;
  ck_assert_int_eq(strlen(line), s21_strlen(line));
}
START_TEST(test_strlen_entermidline_1) {
  char line[4] = ENTER_MID_line;
  ck_assert_int_eq(strlen(line), s21_strlen(line));
}
START_TEST(test_strlen_entermidline_2) {
  char line[5] = ENTER_MID_line;
  ck_assert_int_eq(strlen(line), s21_strlen(line));
}
START_TEST(test_strlen_tabmidline_1) {
  char line[4] = TAB_MID_line;
  ck_assert_int_eq(strlen(line), s21_strlen(line));
}
START_TEST(test_strlen_tabmidline_2) {
  char line[5] = TAB_MID_line;
  ck_assert_int_eq(strlen(line), s21_strlen(line));
}
// 1.5
START_TEST(test_strlen_invisible_1) {
  char line[33] = INVIS_CHAR;
  ck_assert_int_eq(strlen(line), s21_strlen(line));
}
START_TEST(test_strlen_invisible_2) {
  char line[34] = INVIS_CHAR;
  ck_assert_int_eq(strlen(line), s21_strlen(line));
}
// 1.6
START_TEST(test_strlen_long) {
  char line[LONG_CHECK_LINE] = {'\0'};
  rand_str(line, LONG_CHECK_LINE - 1);
  ck_assert_int_eq(strlen(line), s21_strlen(line));
}

// s21_memset   //elevator
// 2.0
START_TEST(test_memset_pointertest) {
  char line1[6] = FRIVE_CHAR_1;
  char line2[6] = FRIVE_CHAR_1;
  char letter = 'f';
  int len = 4;
  void* p1 = memset(line1, letter, len);
  void* p2 = s21_memset(line2, letter, len);
  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(memset(line1, letter, len), s21_memset(line2, letter, len));
  ck_assert_str_eq(p1, memset(line1, letter, len));
  ck_assert_str_eq(p2, s21_memset(line2, letter, len));
  ck_assert_str_eq(p1, s21_memset(line2, letter, len));
  ck_assert_str_eq(p2, memset(line1, letter, len));
  ck_assert_str_eq(line1, p1);
  ck_assert_str_eq(line2, p2);
  ck_assert_str_eq(line1, line2);
  ck_assert_str_eq(line1, p2);
  ck_assert_str_eq(line2, p1);
}
// 2.1
START_TEST(test_memset_normal_1) {
  char line1[6] = FRIVE_CHAR_1;
  char line2[6] = FRIVE_CHAR_1;
  char letter = 'f';
  int len = 3;
  void* p1 = memset(line1, letter, len);
  void* p2 = s21_memset(line2, letter, len);
  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);
}
START_TEST(test_memset_normal_2) {
  char line1[6] = FRIVE_CHAR_1;
  char line2[6] = FRIVE_CHAR_1;
  char letter = 'f';
  int len = 1;
  void* p1 = memset(line1, letter, len);
  void* p2 = s21_memset(line2, letter, len);
  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);
}
// 2.2
START_TEST(test_memset_nullline) {
  char line1[5] = NULL_LINE;
  char line2[5] = NULL_LINE;
  char letter = 'f';
  int len = 3;
  void* p1 = memset(line1, letter, len);
  void* p2 = s21_memset(line2, letter, len);
  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);
}
// 2.3
START_TEST(test_memset_numzero) {
  char line1[6] = FRIVE_CHAR_1;
  char line2[6] = FRIVE_CHAR_1;
  char letter = 'f';
  int len = 0;
  void* p1 = memset(line1, letter, len);
  void* p2 = s21_memset(line2, letter, len);
  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);
}
START_TEST(test_memset_nummore_5) {
  char line1[10] = FRIVE_CHAR_1;
  char line2[10] = FRIVE_CHAR_1;
  char letter = 'f';
  int len = 8;
  void* p1 = memset(line1, letter, len);
  void* p2 = s21_memset(line2, letter, len);
  ck_assert_mem_eq(p1, p2, 10);
  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, 10);
  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_memset_numsame) {
  char line1[6] = FRIVE_CHAR_1;
  char line2[6] = FRIVE_CHAR_1;
  char letter = 'f';
  int len = 6;
  void* p1 = memset(line1, letter, len);
  void* p2 = s21_memset(line2, letter, len);
  ck_assert_mem_eq(p1, p2, 6);
  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, 6);
  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
// 2.4
START_TEST(test_memset_charenter) {
  char line1[6] = FRIVE_CHAR_1;
  char line2[6] = FRIVE_CHAR_1;
  char letter = '\n';
  int len = 3;
  void* p1 = memset(line1, letter, len);
  void* p2 = s21_memset(line2, letter, len);
  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);
}
START_TEST(test_memset_charspace) {
  char line1[6] = FRIVE_CHAR_1;
  char line2[6] = FRIVE_CHAR_1;
  char letter = ' ';
  int len = 3;
  void* p1 = memset(line1, letter, len);
  void* p2 = s21_memset(line2, letter, len);
  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);
}
START_TEST(test_memset_chartab) {
  char line1[6] = FRIVE_CHAR_1;
  char line2[6] = FRIVE_CHAR_1;
  char letter = '\t';
  int len = 3;
  void* p1 = memset(line1, letter, len);
  void* p2 = s21_memset(line2, letter, len);
  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);
}
START_TEST(test_memset_charnull) {
  char line1[6] = FRIVE_CHAR_1;
  char line2[6] = FRIVE_CHAR_1;
  char letter = '\0';
  int len = 3;
  void* p1 = memset(line1, letter, len);
  void* p2 = s21_memset(line2, letter, len);
  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);
}
START_TEST(test_memset_charinvis_1) {
  char line1[6] = FRIVE_CHAR_1;
  char line2[6] = FRIVE_CHAR_1;
  char letter = 6;
  int len = 3;
  void* p1 = memset(line1, letter, len);
  void* p2 = s21_memset(line2, letter, len);
  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);
}
START_TEST(test_memset_charinvis_2) {
  char line1[6] = FRIVE_CHAR_1;
  char line2[6] = FRIVE_CHAR_1;
  char letter = 20;
  int len = 3;
  void* p1 = memset(line1, letter, len);
  void* p2 = s21_memset(line2, letter, len);
  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);
}
START_TEST(test_memset_charinvis_3) {
  char line1[6] = FRIVE_CHAR_1;
  char line2[6] = FRIVE_CHAR_1;
  char letter = 15;
  int len = 3;
  void* p1 = memset(line1, letter, len);
  void* p2 = s21_memset(line2, letter, len);
  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);
}
// 2.6
START_TEST(test_memset_midline_1) {
  char line1[5] = ENTER_MID_line;
  char line2[5] = ENTER_MID_line;
  char letter = 'g';
  int len = 3;
  void* p1 = memset(line1, letter, len);
  void* p2 = s21_memset(line2, letter, len);
  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);
}
START_TEST(test_memset_midline_2) {
  char line1[5] = NULL_MID_line;
  char line2[5] = NULL_MID_line;
  char letter = 'g';
  int len = 2;
  void* p1 = memset(line1, letter, len);
  void* p2 = s21_memset(line2, letter, len);
  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);
}
START_TEST(test_memset_midline_3) {
  char line1[5] = NULL_MID_line;
  char line2[5] = NULL_MID_line;
  char letter = 'g';
  int len = 3;
  void* p1 = memset(line1, letter, len);
  void* p2 = s21_memset(line2, letter, len);
  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);
}
START_TEST(test_memset_midline_4) {
  char line1[5] = NULL_MID_line;
  char line2[5] = NULL_MID_line;
  char letter = 'g';
  int len = 4;
  void* p1 = memset(line1, letter, len);
  void* p2 = s21_memset(line2, letter, len);
  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);
}
// 2.7
START_TEST(test_memset_long_2) {
  char line1[LONG_CHECK_LINE] = NULL_LINE;
  char line2[LONG_CHECK_LINE] = NULL_LINE;
  rand_str(line1, LONG_CHECK_LINE - 1);
  strcpy(line2, line1);
  char letter = 'f';
  int len = 9;
  void* p1 = memset(line1, letter, len);
  void* p2 = s21_memset(line2, letter, len);
  ck_assert_mem_eq(p1, p2, LONG_CHECK_LINE);
  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, LONG_CHECK_LINE);
  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);
  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_memset_long_3) {
  char line1[LONG_CHECK_LINE] = NULL_LINE;
  char line2[LONG_CHECK_LINE] = NULL_LINE;
  rand_str(line1, LONG_CHECK_LINE - 1);
  strcpy(line2, line1);
  char letter = 'f';
  int len = LONG_CHECK_LINE - 1;
  void* p1 = memset(line1, letter, len);
  void* p2 = s21_memset(line2, letter, len);
  ck_assert_mem_eq(p1, p2, LONG_CHECK_LINE);
  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, LONG_CHECK_LINE);
  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);
  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_memset_long_4) {
  char line1[LONG_CHECK_LINE] = NULL_LINE;
  char line2[LONG_CHECK_LINE] = NULL_LINE;
  rand_str(line1, LONG_CHECK_LINE - 1);
  strcpy(line2, line1);
  char letter = 'f';
  int len = LONG_CHECK_LINE;
  void* p1 = memset(line1, letter, len);
  void* p2 = memset(line2, letter, len);
  ck_assert_mem_eq(p1, p2, LONG_CHECK_LINE);
  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, LONG_CHECK_LINE);
  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
// s21_memcpy   //elevator
// 3.0
START_TEST(test_memcpy_pointertes) {
  char line1[6] = FRIVE_CHAR_1;
  char line2[6] = FRIVE_CHAR_1;
  char sourceline[6] = FRIVE_CHAR_2;
  int len = 4;
  void* p1 = memcpy(line1, sourceline, len);
  void* p2 = s21_memcpy(line2, sourceline, len);
  ck_assert_str_eq(p1, line1);
  ck_assert_str_eq(p2, line2);
  ck_assert_ptr_eq(p1, line1);
  ck_assert_ptr_eq(p2, line2);
  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);
  ck_assert_str_eq(memcpy(line1, sourceline, len),
                   s21_memcpy(line2, sourceline, len));
}
// 3.1
START_TEST(test_memcpy_norm) {
  char line1[6] = FRIVE_CHAR_1;
  char line2[6] = FRIVE_CHAR_1;
  char sourceline[6] = FRIVE_CHAR_2;
  int len = 4;
  void* p1 = memcpy(line1, sourceline, len);
  void* p2 = s21_memcpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 6);
  ck_assert_mem_eq(line1, line2, 6);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
// 3.2
START_TEST(test_memcpy_nullend_1) {
  char line1[5] = NULL_END_line;
  char line2[5] = NULL_END_line;
  char sourceline[5] = TAB_END_line;
  int len = 3;
  void* p1 = memcpy(line1, sourceline, len);
  void* p2 = s21_memcpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 5);
  ck_assert_mem_eq(line1, line2, 5);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_memcpy_nullend_2) {
  char line1[5] = NULL_END_line;
  char line2[5] = NULL_END_line;
  char sourceline[5] = TAB_END_line;
  int len = 4;
  void* p1 = memcpy(line1, sourceline, len);
  void* p2 = s21_memcpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 5);
  ck_assert_mem_eq(line1, line2, 5);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_memcpy_nullmid_1) {
  char line1[5] = NULL_MID_line;
  char line2[5] = NULL_MID_line;
  char sourceline[5] = TAB_END_line;
  int len = 2;
  void* p1 = memcpy(line1, sourceline, len);
  void* p2 = s21_memcpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 5);
  ck_assert_mem_eq(line1, line2, 5);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_memcpy_nullmid_2) {
  char line1[5] = NULL_MID_line;
  char line2[5] = NULL_MID_line;
  char sourceline[5] = TAB_END_line;
  int len = 3;
  void* p1 = memcpy(line1, sourceline, len);
  void* p2 = s21_memcpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 5);
  ck_assert_mem_eq(line1, line2, 5);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_memcpy_nullmid_3) {
  char line1[5] = NULL_MID_line;
  char line2[5] = NULL_MID_line;
  char sourceline[5] = TAB_END_line;
  int len = 4;
  void* p1 = memcpy(line1, sourceline, len);
  void* p2 = s21_memcpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 5);
  ck_assert_mem_eq(line1, line2, 5);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_memcpy_entermid_1) {
  char line1[5] = ENTER_MID_line;
  char line2[5] = ENTER_MID_line;
  char sourceline[5] = TAB_END_line;
  int len = 2;
  void* p1 = memcpy(line1, sourceline, len);
  void* p2 = s21_memcpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 5);
  ck_assert_mem_eq(line1, line2, 5);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_memcpy_entermid_2) {
  char line1[5] = ENTER_MID_line;
  char line2[5] = ENTER_MID_line;
  char sourceline[5] = TAB_END_line;
  int len = 3;
  void* p1 = memcpy(line1, sourceline, len);
  void* p2 = s21_memcpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 5);
  ck_assert_mem_eq(line1, line2, 5);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_memcpy_entermid_3) {
  char line1[5] = ENTER_MID_line;
  char line2[5] = ENTER_MID_line;
  char sourceline[5] = TAB_END_line;
  int len = 4;
  void* p1 = memcpy(line1, sourceline, len);
  void* p2 = s21_memcpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 5);
  ck_assert_mem_eq(line1, line2, 5);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_memcpy_invis_1) {
  char line1[33] = INVIS_CHAR;
  char line2[33] = INVIS_CHAR;
  char sourceline[5] = TAB_END_line;
  int len = 4;
  void* p1 = memcpy(line1, sourceline, len);
  void* p2 = s21_memcpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 33);
  ck_assert_mem_eq(line1, line2, 33);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_memcpy_invis_2) {
  char line1[33] = INVIS_CHAR;
  char line2[33] = INVIS_CHAR;
  char sourceline[33] = INVIS_CHAR;
  int len = 4;
  void* p1 = memcpy(line1, sourceline, len);
  void* p2 = s21_memcpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 33);
  ck_assert_mem_eq(line1, line2, 33);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_memcpy_invis_3) {
  char line1[33] = INVIS_CHAR;
  char line2[33] = INVIS_CHAR;
  char sourceline[33] = INVIS_CHAR;
  int len = 32;
  void* p1 = memcpy(line1, sourceline, len);
  void* p2 = s21_memcpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 33);
  ck_assert_mem_eq(line1, line2, 33);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
// 3.3
START_TEST(test_memcpy_different_n_1) {
  char line1[6] = FRIVE_CHAR_1;
  char line2[6] = FRIVE_CHAR_1;
  char sourceline[6] = FRIVE_CHAR_2;
  int len = 0;
  void* p1 = memcpy(line1, sourceline, len);
  void* p2 = s21_memcpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 6);
  ck_assert_mem_eq(line1, line2, 6);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_memcpy_different_n_2) {
  char line1[6] = FRIVE_CHAR_1;
  char line2[6] = FRIVE_CHAR_1;
  char sourceline[6] = FRIVE_CHAR_2;
  int len = 5;
  void* p1 = memcpy(line1, sourceline, len);
  void* p2 = s21_memcpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 6);
  ck_assert_mem_eq(line1, line2, 6);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_memcpy_different_n_3) {
  char line1[6] = FRIVE_CHAR_1;
  char line2[6] = FRIVE_CHAR_1;
  char sourceline[6] = FRIVE_CHAR_2;
  int len = 6;
  void* p1 = memcpy(line1, sourceline, len);
  void* p2 = s21_memcpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 6);
  ck_assert_mem_eq(line1, line2, 6);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_memcpy_different_n_6) {
  char line1[6] = FRIVE_CHAR_1;
  char line2[6] = FRIVE_CHAR_1;
  char sourceline[5] = FOUR_CHAR;
  int len = 4;
  void* p1 = memcpy(line1, sourceline, len);
  void* p2 = s21_memcpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 6);
  ck_assert_mem_eq(line1, line2, 6);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_memcpy_different_n_7) {
  char line1[6] = FRIVE_CHAR_1;
  char line2[6] = FRIVE_CHAR_1;
  char sourceline[5] = FOUR_CHAR;
  int len = 5;
  void* p1 = memcpy(line1, sourceline, len);
  void* p2 = s21_memcpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 6);
  ck_assert_mem_eq(line1, line2, 6);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
// 3.4
START_TEST(test_memcpy_nullline_1) {
  char line1[6] = FRIVE_CHAR_1;
  char line2[6] = FRIVE_CHAR_1;
  char sourceline[5] = NULL_LINE;
  int len = 3;
  void* p1 = memcpy(line1, sourceline, len);
  void* p2 = s21_memcpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 6);
  ck_assert_mem_eq(line1, line2, 6);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_memcpy_nullline_2) {
  char line1[NORMLINES_SIX] = NULL_LINE;
  char line2[NORMLINES_SIX] = NULL_LINE;
  char sourceline[6] = FRIVE_CHAR_1;
  int len = 3;
  void* p1 = memcpy(line1, sourceline, len);
  void* p2 = s21_memcpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, NORMLINES_SIX);
  ck_assert_mem_eq(line1, line2, NORMLINES_SIX);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
// 3.5
START_TEST(test_memcpy_long_1) {
  char line1[LONG_CHECK_LINE] = NULL_LINE;
  char line2[LONG_CHECK_LINE] = NULL_LINE;
  rand_str(line1, LONG_CHECK_LINE - 1);
  strcpy(line2, line1);
  char sourceline[6] = FRIVE_CHAR_1;
  int len = 5;
  void* p1 = memcpy(line1, sourceline, len);
  void* p2 = s21_memcpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, LONG_CHECK_LINE);
  ck_assert_mem_eq(line1, line2, LONG_CHECK_LINE);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_memcpy_long_2) {
  char line1[LONG_CHECK_LINE] = NULL_LINE;
  char line2[LONG_CHECK_LINE] = NULL_LINE;
  rand_str(line1, LONG_CHECK_LINE - 1);
  strcpy(line2, line1);
  char sourceline[LONG_CHECK_LINE] = NULL_LINE;
  int len = 5;
  void* p1 = memcpy(line1, sourceline, len);
  void* p2 = s21_memcpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, LONG_CHECK_LINE);
  ck_assert_mem_eq(line1, line2, LONG_CHECK_LINE);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_memcpy_long_3) {
  char line1[LONG_CHECK_LINE] = NULL_LINE;
  char line2[LONG_CHECK_LINE] = NULL_LINE;
  rand_str(line1, LONG_CHECK_LINE - 1);
  strcpy(line2, line1);
  char sourceline[LONG_CHECK_LINE] = NULL_LINE;
  rand_str(sourceline, LONG_CHECK_LINE - 1);
  int len = LONG_CHECK_LINE - 1;
  void* p1 = memcpy(line1, sourceline, len);
  void* p2 = s21_memcpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, LONG_CHECK_LINE);
  ck_assert_mem_eq(line1, line2, LONG_CHECK_LINE);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_memcpy_long_4) {
  char line1[LONG_CHECK_LINE] = NULL_LINE;
  char line2[LONG_CHECK_LINE] = NULL_LINE;
  rand_str(line1, LONG_CHECK_LINE - 1);
  strcpy(line2, line1);
  char sourceline[LONG_CHECK_LINE] = NULL_LINE;
  rand_str(sourceline, LONG_CHECK_LINE - 1);
  int len = LONG_CHECK_LINE;
  void* p1 = memcpy(line1, sourceline, len);
  void* p2 = s21_memcpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, LONG_CHECK_LINE);
  ck_assert_mem_eq(line1, line2, LONG_CHECK_LINE);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}

// s21_strncpy    //elevator
// 4.0
START_TEST(test_strncpy_pointertes) {
  char line1[6] = FRIVE_CHAR_1;
  char line2[6] = FRIVE_CHAR_1;
  char sourceline[6] = FRIVE_CHAR_2;
  int len = 4;
  void* p1 = strncpy(line1, sourceline, len);
  void* p2 = s21_strncpy(line2, sourceline, len);
  ck_assert_str_eq(p1, line1);
  ck_assert_str_eq(p2, line2);
  ck_assert_ptr_eq(p1, line1);
  ck_assert_ptr_eq(p2, line2);
  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);
  ck_assert_str_eq(strncpy(line1, sourceline, len),
                   s21_strncpy(line2, sourceline, len));
}
// 4.1
START_TEST(test_strncpy_norm_1) {
  char line1[6] = FRIVE_CHAR_1;
  char line2[6] = FRIVE_CHAR_1;
  char sourceline[6] = FRIVE_CHAR_2;
  int len = 4;
  void* p1 = strncpy(line1, sourceline, len);
  void* p2 = s21_strncpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 6);
  ck_assert_mem_eq(line1, line2, 6);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_strncpy_norm_2) {
  char line1[6] = FRIVE_CHAR_1;
  char line2[6] = FRIVE_CHAR_1;
  char sourceline[6] = FRIVE_CHAR_2;
  int len = 5;
  void* p1 = strncpy(line1, sourceline, len);
  void* p2 = s21_strncpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 6);
  ck_assert_mem_eq(line1, line2, 6);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
// 4.2
START_TEST(test_strncpy_nullend_1) {
  char line1[5] = NULL_END_line;
  char line2[5] = NULL_END_line;
  char sourceline[5] = TAB_END_line;
  int len = 3;
  void* p1 = strncpy(line1, sourceline, len);
  void* p2 = s21_strncpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 5);
  ck_assert_mem_eq(line1, line2, 5);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_strncpy_nullend_2) {
  char line1[5] = NULL_END_line;
  char line2[5] = NULL_END_line;
  char sourceline[5] = TAB_END_line;
  int len = 4;
  void* p1 = strncpy(line1, sourceline, len);
  void* p2 = s21_strncpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 5);
  ck_assert_mem_eq(line1, line2, 5);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_strncpy_nullmid_1) {
  char line1[5] = NULL_MID_line;
  char line2[5] = NULL_MID_line;
  char sourceline[5] = TAB_END_line;
  int len = 2;
  void* p1 = strncpy(line1, sourceline, len);
  void* p2 = s21_strncpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 5);
  ck_assert_mem_eq(line1, line2, 5);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_strncpy_nullmid_2) {
  char line1[5] = NULL_MID_line;
  char line2[5] = NULL_MID_line;
  char sourceline[5] = TAB_END_line;

  int len = 3;
  void* p1 = strncpy(line1, sourceline, len);
  void* p2 = s21_strncpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 5);
  ck_assert_mem_eq(line1, line2, 5);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_strncpy_nullmid_3) {
  char line1[5] = NULL_MID_line;
  char line2[5] = NULL_MID_line;
  char sourceline[5] = TAB_END_line;
  int len = 4;
  void* p1 = strncpy(line1, sourceline, len);
  void* p2 = s21_strncpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 5);
  ck_assert_mem_eq(line1, line2, 5);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_strncpy_entermid_1) {
  char line1[5] = ENTER_MID_line;
  char line2[5] = ENTER_MID_line;
  char sourceline[5] = TAB_END_line;
  int len = 2;
  void* p1 = strncpy(line1, sourceline, len);
  void* p2 = s21_strncpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 5);
  ck_assert_mem_eq(line1, line2, 5);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_strncpy_entermid_2) {
  char line1[5] = ENTER_MID_line;
  char line2[5] = ENTER_MID_line;
  char sourceline[5] = TAB_END_line;
  int len = 3;
  void* p1 = strncpy(line1, sourceline, len);
  void* p2 = s21_strncpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 5);
  ck_assert_mem_eq(line1, line2, 5);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_strncpy_entermid_3) {
  char line1[5] = ENTER_MID_line;
  char line2[5] = ENTER_MID_line;
  char sourceline[5] = TAB_END_line;
  int len = 4;
  void* p1 = strncpy(line1, sourceline, len);
  void* p2 = s21_strncpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 5);
  ck_assert_mem_eq(line1, line2, 5);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_strncpy_invis_1) {
  char line1[33] = INVIS_CHAR;
  char line2[33] = INVIS_CHAR;
  char sourceline[5] = TAB_END_line;
  int len = 4;
  void* p1 = strncpy(line1, sourceline, len);
  void* p2 = s21_strncpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 33);
  ck_assert_mem_eq(line1, line2, 33);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_strncpy_invis_2) {
  char line1[33] = INVIS_CHAR;
  char line2[33] = INVIS_CHAR;
  char sourceline[33] = INVIS_CHAR;
  int len = 4;
  void* p1 = strncpy(line1, sourceline, len);
  void* p2 = s21_strncpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 33);
  ck_assert_mem_eq(line1, line2, 33);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_strncpy_invis_3) {
  char line1[33] = INVIS_CHAR;
  char line2[33] = INVIS_CHAR;
  char sourceline[33] = INVIS_CHAR;
  int len = 32;
  void* p1 = strncpy(line1, sourceline, len);
  void* p2 = s21_strncpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 33);
  ck_assert_mem_eq(line1, line2, 33);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
// 4.3
START_TEST(test_strncpy_different_n_1) {
  char line1[6] = FRIVE_CHAR_1;
  char line2[6] = FRIVE_CHAR_1;
  char sourceline[6] = FRIVE_CHAR_2;
  int len = 0;
  void* p1 = strncpy(line1, sourceline, len);
  void* p2 = s21_strncpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 6);
  ck_assert_mem_eq(line1, line2, 6);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_strncpy_different_n_2) {
  char line1[6] = FRIVE_CHAR_1;
  char line2[6] = FRIVE_CHAR_1;
  char sourceline[6] = FRIVE_CHAR_2;
  int len = 5;
  void* p1 = strncpy(line1, sourceline, len);
  void* p2 = s21_strncpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 6);
  ck_assert_mem_eq(line1, line2, 6);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_strncpy_different_n_3) {
  char line1[6] = FRIVE_CHAR_1;
  char line2[6] = FRIVE_CHAR_1;
  char sourceline[6] = FRIVE_CHAR_2;
  int len = 6;
  void* p1 = strncpy(line1, sourceline, len);
  void* p2 = s21_strncpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 6);
  ck_assert_mem_eq(line1, line2, 6);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_strncpy_different_n_6) {
  char line1[6] = FRIVE_CHAR_1;
  char line2[6] = FRIVE_CHAR_1;
  char sourceline[5] = FOUR_CHAR;
  int len = 4;
  void* p1 = strncpy(line1, sourceline, len);
  void* p2 = s21_strncpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 6);
  ck_assert_mem_eq(line1, line2, 6);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_strncpy_different_n_7) {
  char line1[6] = FRIVE_CHAR_1;
  char line2[6] = FRIVE_CHAR_1;
  char sourceline[5] = FOUR_CHAR;
  int len = 5;
  void* p1 = strncpy(line1, sourceline, len);
  void* p2 = s21_strncpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 6);
  ck_assert_mem_eq(line1, line2, 6);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_strncpy_different_n_10) {
  char line1[8] = FRIVE_CHAR_1;
  char line2[8] = FRIVE_CHAR_1;
  char sourceline[5] = FOUR_CHAR;
  int len = 6;
  void* p1 = strncpy(line1, sourceline, len);
  void* p2 = s21_strncpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 8);
  ck_assert_mem_eq(line1, line2, 8);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_strncpy_different_n_11) {
  char line1[10] = "ggggggggg";
  char line2[10] = "ggggggggg";
  char sourceline[5] = FOUR_CHAR;
  int len = 9;
  void* p1 = strncpy(line1, sourceline, len);
  void* p2 = s21_strncpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 10);
  ck_assert_mem_eq(line1, line2, 10);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_strncpy_different_n_12) {
  char line1[10] = FRIVE_CHAR_1;
  char line2[10] = FRIVE_CHAR_1;
  char sourceline[5] = FOUR_CHAR;
  int len = 5;
  void* p1 = strncpy(line1, sourceline, len);
  void* p2 = s21_strncpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 10);
  ck_assert_mem_eq(line1, line2, 10);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
// 4.4
START_TEST(test_strncpy_nullline_1) {
  char line1[6] = FRIVE_CHAR_1;
  char line2[6] = FRIVE_CHAR_1;
  char sourceline[5] = NULL_LINE;
  int len = 3;
  void* p1 = strncpy(line1, sourceline, len);
  void* p2 = s21_strncpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 6);
  ck_assert_mem_eq(line1, line2, 6);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_strncpy_nullline_2) {
  char line1[NORMLINES_SIX] = NULL_LINE;
  char line2[NORMLINES_SIX] = NULL_LINE;
  char sourceline[NORMLINES_SIX] = FRIVE_CHAR_1;
  int len = 3;
  void* p1 = strncpy(line1, sourceline, len);
  void* p2 = s21_strncpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, NORMLINES_SIX);
  ck_assert_mem_eq(line1, line2, NORMLINES_SIX);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
// 4.5
START_TEST(test_strncpy_long_1) {
  char line1[LONG_CHECK_LINE] = NULL_LINE;
  char line2[LONG_CHECK_LINE] = NULL_LINE;
  rand_str(line1, LONG_CHECK_LINE - 1);
  strcpy(line2, line1);
  char sourceline[6] = FRIVE_CHAR_1;
  int len = 5;
  void* p1 = strncpy(line1, sourceline, len);
  void* p2 = s21_strncpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, LONG_CHECK_LINE);
  ck_assert_mem_eq(line1, line2, LONG_CHECK_LINE);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_strncpy_long_2) {
  char line1[LONG_CHECK_LINE] = NULL_LINE;
  char line2[LONG_CHECK_LINE] = NULL_LINE;
  rand_str(line1, LONG_CHECK_LINE - 1);
  strcpy(line2, line1);
  char sourceline[LONG_CHECK_LINE] = NULL_LINE;
  int len = 5;
  void* p1 = strncpy(line1, sourceline, len);
  void* p2 = s21_strncpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, LONG_CHECK_LINE);
  ck_assert_mem_eq(line1, line2, LONG_CHECK_LINE);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_strncpy_long_3) {
  char line1[LONG_CHECK_LINE] = NULL_LINE;
  char line2[LONG_CHECK_LINE] = NULL_LINE;
  rand_str(line1, LONG_CHECK_LINE - 1);
  strcpy(line2, line1);
  char sourceline[LONG_CHECK_LINE] = NULL_LINE;
  rand_str(sourceline, LONG_CHECK_LINE - 1);
  int len = LONG_CHECK_LINE - 1;
  void* p1 = strncpy(line1, sourceline, len);
  void* p2 = s21_strncpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, LONG_CHECK_LINE);
  ck_assert_mem_eq(line1, line2, LONG_CHECK_LINE);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_strncpy_long_4) {
  char line1[LONG_CHECK_LINE] = NULL_LINE;
  char line2[LONG_CHECK_LINE] = NULL_LINE;
  rand_str(line1, LONG_CHECK_LINE - 1);
  strcpy(line2, line1);
  char sourceline[LONG_CHECK_LINE] = NULL_LINE;
  rand_str(sourceline, LONG_CHECK_LINE - 1);
  int len = LONG_CHECK_LINE;
  void* p1 = strncpy(line1, sourceline, len);
  void* p2 = s21_strncpy(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, LONG_CHECK_LINE);
  ck_assert_mem_eq(line1, line2, LONG_CHECK_LINE);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}

// s21_strncat   //elevator
// 5.0
START_TEST(test_strncat_pointertes) {
  char line1[10] = FRIVE_CHAR_1;
  char line2[10] = FRIVE_CHAR_1;
  char sourceline[6] = FRIVE_CHAR_2;
  int len = 4;
  void* p1 = strncat(line1, sourceline, len);
  void* p2 = s21_strncat(line2, sourceline, len);
  ck_assert_str_eq(p1, line1);
  ck_assert_str_eq(p2, line2);
  ck_assert_ptr_eq(p1, line1);
  ck_assert_ptr_eq(p2, line2);
  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);
}
// 5.1
START_TEST(test_strncat_norm_1) {
  char line1[10] = FRIVE_CHAR_1;
  char line2[10] = FRIVE_CHAR_1;
  char sourceline[6] = FRIVE_CHAR_2;
  int len = 4;
  void* p1 = strncat(line1, sourceline, len);
  void* p2 = s21_strncat(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 10);
  ck_assert_mem_eq(line1, line2, 10);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_strncat_norm_2) {
  char line1[11] = FRIVE_CHAR_1;
  char line2[11] = FRIVE_CHAR_1;
  char sourceline[6] = FRIVE_CHAR_2;
  int len = 5;
  void* p1 = strncat(line1, sourceline, len);
  void* p2 = s21_strncat(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 11);
  ck_assert_mem_eq(line1, line2, 11);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
// 5.2
START_TEST(test_strncat_nullend_1) {
  char line1[11] = NULL_END_line;
  char line2[11] = NULL_END_line;
  char sourceline[5] = TAB_END_line;
  int len = 3;
  void* p1 = strncat(line1, sourceline, len);
  void* p2 = s21_strncat(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 11);
  ck_assert_mem_eq(line1, line2, 11);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_strncat_nullend_2) {
  char line1[11] = NULL_END_line;
  char line2[11] = NULL_END_line;
  char sourceline[5] = TAB_END_line;
  int len = 4;
  void* p1 = strncat(line1, sourceline, len);
  void* p2 = s21_strncat(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 11);
  ck_assert_mem_eq(line1, line2, 11);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_strncat_nullend_3) {
  char line1[11] = TAB_END_line;
  char line2[11] = TAB_END_line;
  char sourceline[5] = NULL_END_line;
  int len = 4;
  void* p1 = strncat(line1, sourceline, len);
  void* p2 = s21_strncat(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 11);
  ck_assert_mem_eq(line1, line2, 11);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_strncat_nullmid_4) {
  char line1[11] = TAB_END_line;
  char line2[11] = TAB_END_line;
  char sourceline[5] = NULL_MID_line;
  int len = 4;
  void* p1 = strncat(line1, sourceline, len);
  void* p2 = s21_strncat(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 11);
  ck_assert_mem_eq(line1, line2, 11);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_strncat_nullmid_5) {
  char line1[11] = TAB_END_line;
  char line2[11] = TAB_END_line;
  char sourceline[5] = NULL_MID_line;
  int len = 3;
  void* p1 = strncat(line1, sourceline, len);
  void* p2 = s21_strncat(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 11);
  ck_assert_mem_eq(line1, line2, 11);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_strncat_nullmid_6) {
  char line1[11] = TAB_END_line;
  char line2[11] = TAB_END_line;
  char sourceline[5] = NULL_MID_line;
  int len = 2;
  void* p1 = strncat(line1, sourceline, len);
  void* p2 = s21_strncat(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 11);
  ck_assert_mem_eq(line1, line2, 11);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_strncat_nullmid_1) {
  char line1[11] = NULL_MID_line;
  char line2[11] = NULL_MID_line;
  char sourceline[5] = TAB_END_line;
  int len = 2;
  void* p1 = strncat(line1, sourceline, len);
  void* p2 = s21_strncat(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 11);
  ck_assert_mem_eq(line1, line2, 11);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_strncat_nullmid_2) {
  char line1[11] = NULL_MID_line;
  char line2[11] = NULL_MID_line;
  char sourceline[5] = TAB_END_line;

  int len = 3;
  void* p1 = strncat(line1, sourceline, len);
  void* p2 = s21_strncat(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 11);
  ck_assert_mem_eq(line1, line2, 11);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_strncat_nullmid_3) {
  char line1[11] = NULL_MID_line;
  char line2[11] = NULL_MID_line;
  char sourceline[5] = TAB_END_line;
  int len = 4;
  void* p1 = strncat(line1, sourceline, len);
  void* p2 = s21_strncat(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 11);
  ck_assert_mem_eq(line1, line2, 11);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_strncat_entermid_1) {
  char line1[11] = ENTER_MID_line;
  char line2[11] = ENTER_MID_line;
  char sourceline[5] = TAB_END_line;
  int len = 2;
  void* p1 = strncat(line1, sourceline, len);
  void* p2 = s21_strncat(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 11);
  ck_assert_mem_eq(line1, line2, 11);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_strncat_entermid_2) {
  char line1[11] = ENTER_MID_line;
  char line2[11] = ENTER_MID_line;
  char sourceline[5] = TAB_END_line;
  int len = 3;
  void* p1 = strncat(line1, sourceline, len);
  void* p2 = s21_strncat(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 11);
  ck_assert_mem_eq(line1, line2, 11);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_strncat_entermid_3) {
  char line1[11] = ENTER_MID_line;
  char line2[11] = ENTER_MID_line;
  char sourceline[5] = TAB_END_line;
  int len = 4;
  void* p1 = strncat(line1, sourceline, len);
  void* p2 = s21_strncat(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 11);
  ck_assert_mem_eq(line1, line2, 11);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_strncat_invis_1) {
  char line1[38] = INVIS_CHAR;
  char line2[38] = INVIS_CHAR;
  char sourceline[5] = TAB_END_line;
  int len = 4;
  void* p1 = strncat(line1, sourceline, len);
  void* p2 = s21_strncat(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 38);
  ck_assert_mem_eq(line1, line2, 38);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_strncat_invis_3) {
  char line1[66] = INVIS_CHAR;
  char line2[66] = INVIS_CHAR;
  char sourceline[33] = INVIS_CHAR;
  int len = 32;
  void* p1 = strncat(line1, sourceline, len);
  void* p2 = s21_strncat(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 66);
  ck_assert_mem_eq(line1, line2, 66);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_strncat_invis_2) {
  char line1[38] = FRIVE_CHAR_1;
  char line2[38] = FRIVE_CHAR_1;
  char sourceline[33] = INVIS_CHAR;
  int len = 32;
  void* p1 = strncat(line1, sourceline, len);
  void* p2 = s21_strncat(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 38);
  ck_assert_mem_eq(line1, line2, 38);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
// 5.3
START_TEST(test_strncat_different_n_1) {
  char line1[6] = FRIVE_CHAR_1;
  char line2[6] = FRIVE_CHAR_1;
  char sourceline[6] = FRIVE_CHAR_2;
  int len = 0;
  void* p1 = strncat(line1, sourceline, len);
  void* p2 = s21_strncat(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 6);
  ck_assert_mem_eq(line1, line2, 6);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_strncat_different_n_13) {
  char line1[11] = FRIVE_CHAR_1;
  char line2[11] = FRIVE_CHAR_1;
  char sourceline[6] = FRIVE_CHAR_2;
  int len = 0;
  void* p1 = strncat(line1, sourceline, len);
  void* p2 = s21_strncat(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 11);
  ck_assert_mem_eq(line1, line2, 11);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_strncat_different_n_2) {
  char line1[11] = FRIVE_CHAR_1;
  char line2[11] = FRIVE_CHAR_1;
  char sourceline[6] = FRIVE_CHAR_2;
  int len = 5;
  void* p1 = strncat(line1, sourceline, len);
  void* p2 = s21_strncat(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 11);
  ck_assert_mem_eq(line1, line2, 11);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_strncat_different_n_3) {
  char line1[12] = FRIVE_CHAR_1;
  char line2[12] = FRIVE_CHAR_1;
  char sourceline[6] = FRIVE_CHAR_2;
  int len = 6;
  void* p1 = strncat(line1, sourceline, len);
  void* p2 = s21_strncat(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 12);
  ck_assert_mem_eq(line1, line2, 12);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_strncat_different_n_14) {
  char line1[11] = FRIVE_CHAR_1;
  char line2[11] = FRIVE_CHAR_1;
  char sourceline[6] = FRIVE_CHAR_2;
  int len = 6;
  void* p1 = s21_strncat(line1, sourceline, len);
  void* p2 = strncat(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_strncat_different_n_15) {
  char line1[14] = FRIVE_CHAR_1;
  char line2[14] = FRIVE_CHAR_1;
  char sourceline[6] = FRIVE_CHAR_2;
  int len = 7;
  void* p1 = strncat(line1, sourceline, len);
  void* p2 = s21_strncat(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 14);
  ck_assert_mem_eq(line1, line2, 14);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_strncat_different_n_11) {
  char line1[14] = "ggggggggg";
  char line2[14] = "ggggggggg";
  char sourceline[5] = FOUR_CHAR;
  int len = 9;
  void* p1 = strncat(line1, sourceline, len);
  void* p2 = s21_strncat(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 10);
  ck_assert_mem_eq(line1, line2, 10);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
// 5.4
START_TEST(test_strncat_nullline_1) {
  char line1[9] = FRIVE_CHAR_1;
  char line2[9] = FRIVE_CHAR_1;
  char sourceline[5] = NULL_LINE;
  int len = 3;
  void* p1 = strncat(line1, sourceline, len);
  void* p2 = s21_strncat(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, 9);
  ck_assert_mem_eq(line1, line2, 9);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_strncat_nullline_2) {
  char line1[NORMLINES_SIX * 2 - 1] = NULL_LINE;
  char line2[NORMLINES_SIX * 2 - 1] = NULL_LINE;
  char sourceline[NORMLINES_SIX] = FRIVE_CHAR_1;
  int len = 3;
  void* p1 = strncat(line1, sourceline, len);
  void* p2 = s21_strncat(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, NORMLINES_SIX * 2 - 1);
  ck_assert_mem_eq(line1, line2, NORMLINES_SIX * 2 - 1);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
// 5.5
START_TEST(test_strncat_long_1) {
  char line1[LONG_CHECK_LINE * 2 - 1] = NULL_LINE;
  char line2[LONG_CHECK_LINE * 2 - 1] = NULL_LINE;
  rand_str(line1, LONG_CHECK_LINE - 1);
  strcpy(line2, line1);
  char sourceline[6] = FRIVE_CHAR_1;
  int len = 5;
  void* p1 = strncat(line1, sourceline, len);
  void* p2 = s21_strncat(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, LONG_CHECK_LINE * 2 - 1);
  ck_assert_mem_eq(line1, line2, LONG_CHECK_LINE * 2 - 1);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}

START_TEST(test_strncat_long_2) {
  char line1[LONG_CHECK_LINE * 2 - 1] = NULL_LINE;
  char line2[LONG_CHECK_LINE * 2 - 1] = NULL_LINE;
  rand_str(line1, LONG_CHECK_LINE - 1);
  strcpy(line2, line1);
  char sourceline[LONG_CHECK_LINE] = NULL_LINE;
  rand_str(sourceline, LONG_CHECK_LINE - 1);
  int len = 5;
  void* p1 = strncat(line1, sourceline, len);
  void* p2 = s21_strncat(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, LONG_CHECK_LINE * 2 - 1);
  ck_assert_mem_eq(line1, line2, LONG_CHECK_LINE * 2 - 1);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_strncat_long_3) {
  char line1[LONG_CHECK_LINE * 2 - 1] = NULL_LINE;
  char line2[LONG_CHECK_LINE * 2 - 1] = NULL_LINE;
  rand_str(line1, LONG_CHECK_LINE - 1);
  strcpy(line2, line1);
  char sourceline[LONG_CHECK_LINE] = NULL_LINE;
  rand_str(sourceline, LONG_CHECK_LINE - 1);
  int len = LONG_CHECK_LINE - 1;
  void* p1 = strncat(line1, sourceline, len);
  void* p2 = s21_strncat(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, LONG_CHECK_LINE * 2 - 1);
  ck_assert_mem_eq(line1, line2, LONG_CHECK_LINE * 2 - 1);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_strncat_long_4) {
  char line1[LONG_CHECK_LINE * 2 - 1] = NULL_LINE;
  char line2[LONG_CHECK_LINE * 2 - 1] = NULL_LINE;
  rand_str(line1, LONG_CHECK_LINE - 1);
  strcpy(line2, line1);
  char sourceline[LONG_CHECK_LINE] = NULL_LINE;
  rand_str(sourceline, LONG_CHECK_LINE - 1);
  int len = LONG_CHECK_LINE;
  void* p1 = strncat(line1, sourceline, len);
  void* p2 = s21_strncat(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, LONG_CHECK_LINE * 2 - 1);
  ck_assert_mem_eq(line1, line2, LONG_CHECK_LINE * 2 - 1);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
START_TEST(test_strncat_long_5) {
  char line1[LONG_CHECK_LINE * 2 - 1] = NULL_LINE;
  char line2[LONG_CHECK_LINE * 2 - 1] = NULL_LINE;
  char sourceline[LONG_CHECK_LINE] = NULL_LINE;
  rand_str(sourceline, LONG_CHECK_LINE - 1);
  int len = LONG_CHECK_LINE - 1;
  void* p1 = strncat(line1, sourceline, len);
  void* p2 = s21_strncat(line2, sourceline, len);

  ck_assert_str_eq(p1, p2);
  ck_assert_str_eq(line1, line2);

  ck_assert_mem_eq(p1, p2, LONG_CHECK_LINE * 2 - 1);
  ck_assert_mem_eq(line1, line2, LONG_CHECK_LINE * 2 - 1);

  ck_assert_mem_eq(p1, p2, len);
  ck_assert_mem_eq(line1, line2, len);

  ck_assert_ptr_eq(line1, p1);
  ck_assert_ptr_eq(line2, p2);
}
// strcspn   //elevator
// 6.0
START_TEST(test_strcspn_types) {
  char line[6] = "asdfg";
  char searchline[6] = "fghjk";
  size_t n = 0, m = 0;
  n = strcspn(line, searchline);
  m = s21_strcspn(line, searchline);
  ck_assert_int_eq(n, m);
  ck_assert_uint_eq(n, m);
  ck_assert_float_eq(n, m);
  ck_assert_float_eq(n, m);
  ck_assert_ldouble_eq(n, m);
}
// 6.1
START_TEST(test_strcspn_norm_1) {
  char line[6] = "asdfg";
  char searchline[6] = "fghjk";
  size_t n = 0, m = 0;
  n = strcspn(line, searchline);
  m = s21_strcspn(line, searchline);

  ck_assert_int_eq(n, m);
  ck_assert_uint_eq(n, m);
}
START_TEST(test_strcspn_norm_2) {
  char line[6] = "asdfg";
  char searchline[6] = "hjkl;";
  size_t n = 0, m = 0;
  n = strcspn(line, searchline);
  m = s21_strcspn(line, searchline);

  ck_assert_int_eq(n, m);
  ck_assert_uint_eq(n, m);
}
START_TEST(test_strcspn_norm_3) {
  char line[6] = "asdfg";
  char searchline[6] = "asdfg";
  size_t n = 0, m = 0;
  n = strcspn(line, searchline);
  m = s21_strcspn(line, searchline);

  ck_assert_int_eq(n, m);
  ck_assert_uint_eq(n, m);
}
START_TEST(test_strcspn_norm_4) {
  char line[6] = "asdfg";
  char searchline[6] = "d";
  size_t n = 0, m = 0;
  n = strcspn(line, searchline);
  m = s21_strcspn(line, searchline);

  ck_assert_int_eq(n, m);
  ck_assert_uint_eq(n, m);
}
START_TEST(test_strcspn_norm_5) {
  char line[6] = "asdfg";
  char searchline[6] = "D";
  size_t n = 0, m = 0;
  n = strcspn(line, searchline);
  m = s21_strcspn(line, searchline);

  ck_assert_int_eq(n, m);
  ck_assert_uint_eq(n, m);
}
// 6.2
START_TEST(test_strcspn_nullend_1) {
  char line[6] = NULL_END_line;
  char searchline[6] = "th";
  size_t n = 0, m = 0;
  n = strcspn(line, searchline);
  m = s21_strcspn(line, searchline);

  ck_assert_int_eq(n, m);
  ck_assert_uint_eq(n, m);
}
START_TEST(test_strcspn_nullend_2) {
  char line[6] = NULL_END_line;
  char searchline[6] = "t\0";
  size_t n = 0, m = 0;
  n = strcspn(line, searchline);
  m = s21_strcspn(line, searchline);

  ck_assert_int_eq(n, m);
  ck_assert_uint_eq(n, m);
}
START_TEST(test_strcspn_nullend_3) {
  char line[6] = NULL_END_line;
  char searchline[6] = "\0";
  size_t n = 0, m = 0;
  n = strcspn(line, searchline);
  m = s21_strcspn(line, searchline);

  ck_assert_int_eq(n, m);
  ck_assert_uint_eq(n, m);
}
START_TEST(test_strcspn_nullend_4) {
  char line[6] = NULL_END_line;
  char searchline[6] = {'G', 'H', 'T', '\0'};
  size_t n = 0, m = 0;
  n = strcspn(line, searchline);
  m = s21_strcspn(line, searchline);

  ck_assert_int_eq(n, m);
  ck_assert_uint_eq(n, m);
}
START_TEST(test_strcspn_nullend_5) {
  char line[6] = FRIVE_CHAR_1;
  char searchline[6] = {'G', 'H', 'T', '\0'};
  size_t n = 0, m = 0;
  n = strcspn(line, searchline);
  m = s21_strcspn(line, searchline);

  ck_assert_int_eq(n, m);
  ck_assert_uint_eq(n, m);
}
START_TEST(test_strcspn_nullmid_1) {
  char line[6] = NULL_MID_line;
  char searchline[6] = NULL_LINE;
  size_t n = 0, m = 0;
  n = strcspn(line, searchline);
  m = s21_strcspn(line, searchline);

  ck_assert_int_eq(n, m);
  ck_assert_uint_eq(n, m);
}
START_TEST(test_strcspn_nullmid_2) {
  char line[6] = NULL_MID_line;
  char searchline[6] = "NTM";
  size_t n = 0, m = 0;
  n = strcspn(line, searchline);
  m = s21_strcspn(line, searchline);

  ck_assert_int_eq(n, m);
  ck_assert_uint_eq(n, m);
}
START_TEST(test_strcspn_nullmid_3) {
  char line[5] = {'Z', 'F', '\0', 'T'};
  char searchline[5] = {'\0', 'T', 'Z', 'k'};
  size_t n = 0, m = 0;
  n = strcspn(line, searchline);
  m = s21_strcspn(line, searchline);

  ck_assert_int_eq(n, m);
  ck_assert_uint_eq(n, m);
}
START_TEST(test_strcspn_entermid_1) {
  char line[5] = ENTER_MID_line;
  char searchline[5] = "\n";
  size_t n = 0, m = 0;
  n = strcspn(line, searchline);
  m = s21_strcspn(line, searchline);

  ck_assert_int_eq(n, m);
  ck_assert_uint_eq(n, m);
}
START_TEST(test_strcspn_entermid_2) {
  char line[5] = ENTER_MID_line;
  char searchline[5] = "tmn";
  size_t n = 0, m = 0;
  n = strcspn(line, searchline);
  m = s21_strcspn(line, searchline);

  ck_assert_int_eq(n, m);
  ck_assert_uint_eq(n, m);
}
START_TEST(test_strcspn_entermid_3) {
  char line[5] = ENTER_MID_line;
  char searchline[5] = {'G', 'H', '\n', 'T'};
  size_t n = 0, m = 0;
  n = strcspn(line, searchline);
  m = s21_strcspn(line, searchline);

  ck_assert_int_eq(n, m);
  ck_assert_uint_eq(n, m);
}
START_TEST(test_strcspn_tabmid_1) {
  char line[5] = TAB_MID_line;
  char searchline[5] = "\t";
  size_t n = 0, m = 0;
  n = strcspn(line, searchline);
  m = s21_strcspn(line, searchline);

  ck_assert_int_eq(n, m);
  ck_assert_uint_eq(n, m);
}
START_TEST(test_strcspn_tabmid_2) {
  char line[5] = TAB_MID_line;
  char searchline[5] = "tmn";
  size_t n = 0, m = 0;
  n = strcspn(line, searchline);
  m = s21_strcspn(line, searchline);

  ck_assert_int_eq(n, m);
  ck_assert_uint_eq(n, m);
}
START_TEST(test_strcspn_tabmid_3) {
  char line[5] = TAB_MID_line;
  char searchline[5] = {'G', 'H', '\t', 'T'};
  size_t n = 0, m = 0;
  n = strcspn(line, searchline);
  m = s21_strcspn(line, searchline);

  ck_assert_int_eq(n, m);
  ck_assert_uint_eq(n, m);
}
START_TEST(test_strcspn_enterend_1) {
  char line[5] = ENTER_END_line;
  char searchline[5] = "\n";
  size_t n = 0, m = 0;
  n = strcspn(line, searchline);
  m = s21_strcspn(line, searchline);

  ck_assert_int_eq(n, m);
  ck_assert_uint_eq(n, m);
}
START_TEST(test_strcspn_invis_1) {
  char line[33] = INVIS_CHAR;
  char searchline[5] = {'g', 'm', 15, 't'};
  size_t n = 0, m = 0;
  n = strcspn(line, searchline);
  m = s21_strcspn(line, searchline);

  ck_assert_int_eq(n, m);
  ck_assert_uint_eq(n, m);
}
START_TEST(test_strcspn_invis_2) {
  char line[33] = INVIS_CHAR;
  char searchline[5] = {'g', 'm', 10, 't'};
  size_t n = 0, m = 0;
  n = strcspn(line, searchline);
  m = s21_strcspn(line, searchline);

  ck_assert_int_eq(n, m);
  ck_assert_uint_eq(n, m);
}
START_TEST(test_strcspn_invis_3) {
  char line[33] = INVIS_CHAR;
  char searchline[5] = {'g', 'm', 25, 't'};
  size_t n = 0, m = 0;
  n = strcspn(line, searchline);
  m = s21_strcspn(line, searchline);

  ck_assert_int_eq(n, m);
  ck_assert_uint_eq(n, m);
}
START_TEST(test_strcspn_invis_4) {
  char line[6] = FRIVE_CHAR_1;
  char searchline[33] = INVIS_CHAR;
  size_t n = 0, m = 0;
  n = strcspn(line, searchline);
  m = s21_strcspn(line, searchline);

  ck_assert_int_eq(n, m);
  ck_assert_uint_eq(n, m);
}
START_TEST(test_strcspn_invis_5) {
  char line[33] = INVIS_CHAR;
  char searchline[33] = INVIS_CHAR;
  size_t n = 0, m = 0;
  n = strcspn(line, searchline);
  m = s21_strcspn(line, searchline);

  ck_assert_int_eq(n, m);
  ck_assert_uint_eq(n, m);
}
START_TEST(test_strcspn_invis_6) {
  char line[5] = NULL_MID_line;
  char searchline[33] = INVIS_CHAR;
  size_t n = 0, m = 0;
  n = strcspn(line, searchline);
  m = s21_strcspn(line, searchline);

  ck_assert_int_eq(n, m);
  ck_assert_uint_eq(n, m);
}
START_TEST(test_strcspn_invis_7) {
  char line[5] = {'g', 15, 25, 'f'};
  char searchline[33] = INVIS_CHAR;
  size_t n = 0, m = 0;
  n = strcspn(line, searchline);
  m = s21_strcspn(line, searchline);

  ck_assert_int_eq(n, m);
  ck_assert_uint_eq(n, m);
}
// 6.3
START_TEST(test_strcspn_nullline_1) {
  char line[5] = NULL_LINE;
  char searchline[6] = FRIVE_CHAR_1;
  size_t n = 0, m = 0;
  n = strcspn(line, searchline);
  m = s21_strcspn(line, searchline);

  ck_assert_int_eq(n, m);
  ck_assert_uint_eq(n, m);
}
START_TEST(test_strcspn_nullline_3) {
  char line[6] = FRIVE_CHAR_1;
  char searchline[5] = NULL_LINE;
  size_t n = 0, m = 0;
  n = strcspn(line, searchline);
  m = s21_strcspn(line, searchline);

  ck_assert_int_eq(n, m);
  ck_assert_uint_eq(n, m);
}

// 6.4
START_TEST(test_strcspn_long_1) {
  char line[LONG_CHECK_LINE] = NULL_LINE;
  rand_str(line, LONG_CHECK_LINE - 1);
  char searchline[10] = "asdfghjkl";
  size_t n = 0, m = 0;
  n = strcspn(line, searchline);
  m = s21_strcspn(line, searchline);

  ck_assert_int_eq(n, m);
  ck_assert_uint_eq(n, m);
}
START_TEST(test_strcspn_long_2) {
  char line[LONG_CHECK_LINE] = NULL_LINE;
  rand_str(line, LONG_CHECK_LINE - 1);
  char searchline[LONG_CHECK_LINE] = NULL_LINE;
  rand_str(searchline, LONG_CHECK_LINE - 1);
  size_t n = 0, m = 0;
  n = strcspn(line, searchline);
  m = s21_strcspn(line, searchline);

  ck_assert_int_eq(n, m);
  ck_assert_uint_eq(n, m);
}
START_TEST(test_strcspn_long_3) {
  char line[LONG_CHECK_LINE] = NULL_LINE;
  rand_str(line, LONG_CHECK_LINE - 1);
  char searchline[33] = INVIS_CHAR;
  size_t n = 0, m = 0;
  n = strcspn(line, searchline);
  m = s21_strcspn(line, searchline);

  ck_assert_int_eq(n, m);
  ck_assert_uint_eq(n, m);
}
START_TEST(test_strcspn_long_4) {
  char line[LONG_CHECK_LINE] = NULL_LINE;
  rand_str(line, LONG_CHECK_LINE - 1);
  char searchline[5] = ENTER_MID_line;
  size_t n = 0, m = 0;
  n = strcspn(line, searchline);
  m = s21_strcspn(line, searchline);

  ck_assert_int_eq(n, m);
  ck_assert_uint_eq(n, m);
}
START_TEST(test_strcspn_long_5) {
  char line[33] = INVIS_CHAR;
  char searchline[LONG_CHECK_LINE] = NULL_LINE;
  rand_str(searchline, LONG_CHECK_LINE - 1);
  size_t n = 0, m = 0;
  n = strcspn(line, searchline);
  m = s21_strcspn(line, searchline);

  ck_assert_int_eq(n, m);
  ck_assert_uint_eq(n, m);
}
START_TEST(test_strcspn_long_6) {
  char line[5] = "asdf";
  char searchline[LONG_CHECK_LINE] = NULL_LINE;
  rand_str(searchline, LONG_CHECK_LINE - 1);
  size_t n = 0, m = 0;
  n = strcspn(line, searchline);
  m = s21_strcspn(line, searchline);

  ck_assert_int_eq(n, m);
  ck_assert_uint_eq(n, m);
}
START_TEST(test_strcspn_long_7) {
  char line[5] = "\n";
  char searchline[LONG_CHECK_LINE * 10] = NULL_LINE;
  rand_str(searchline, LONG_CHECK_LINE * 10 - 1);
  size_t n = 0, m = 0;
  n = strcspn(line, searchline);
  m = s21_strcspn(line, searchline);

  ck_assert_int_eq(n, m);
  ck_assert_uint_eq(n, m);
}

// strpbrk   //elevator
// 7.0
START_TEST(test_strpbrk_types) {
  char line[6] = "asdfg";
  char searchline[6] = "fghjk";
  char *n = NULL, *m = MY_NULL;
  n = strpbrk(line, searchline);
  m = s21_strpbrk(line, searchline);

  ck_assert_pstr_eq(n, m);
  ck_assert_ptr_eq(n, m);
  ck_assert_str_eq(n, m);
}
// 7.1
START_TEST(test_strpbrk_norm_1) {
  char line[6] = "asdfg";
  char searchline[6] = "fghjk";
  char *n = NULL, *m = MY_NULL;
  n = strpbrk(line, searchline);
  m = s21_strpbrk(line, searchline);

  ck_assert_pstr_eq(n, m);
  ck_assert_ptr_eq(n, m);
}
START_TEST(test_strpbrk_norm_2) {
  char line[6] = "asdfg";
  char searchline[6] = "hjkl;";
  char *n = NULL, *m = MY_NULL;
  n = strpbrk(line, searchline);
  m = s21_strpbrk(line, searchline);

  ck_assert_pstr_eq(n, m);
  ck_assert_ptr_eq(n, m);
}
START_TEST(test_strpbrk_norm_3) {
  char line[6] = "asdfg";
  char searchline[6] = "asdfg";
  char *n = NULL, *m = MY_NULL;
  n = strpbrk(line, searchline);
  m = s21_strpbrk(line, searchline);

  ck_assert_pstr_eq(n, m);
  ck_assert_ptr_eq(n, m);
}
START_TEST(test_strpbrk_norm_4) {
  char line[6] = "asdfg";
  char searchline[6] = "d";
  char *n = NULL, *m = MY_NULL;
  n = strpbrk(line, searchline);
  m = s21_strpbrk(line, searchline);

  ck_assert_pstr_eq(n, m);
  ck_assert_ptr_eq(n, m);
}
START_TEST(test_strpbrk_norm_5) {
  char line[6] = "asdfg";
  char searchline[6] = "D";
  char *n = NULL, *m = MY_NULL;
  n = strpbrk(line, searchline);
  m = s21_strpbrk(line, searchline);

  ck_assert_pstr_eq(n, m);
  ck_assert_ptr_eq(n, m);
}
START_TEST(test_strpbrk_norm_6) {
  char line[6] = "asdfg";
  char searchline[6] = "gooo";
  char *n = NULL, *m = MY_NULL;
  n = strpbrk(line, searchline);
  m = s21_strpbrk(line, searchline);

  ck_assert_pstr_eq(n, m);
  ck_assert_ptr_eq(n, m);
}
// 7.2
START_TEST(test_strpbrk_nullend_1) {
  char line[6] = NULL_END_line;
  char searchline[6] = "th";
  char *n = NULL, *m = MY_NULL;
  n = strpbrk(line, searchline);
  m = s21_strpbrk(line, searchline);

  ck_assert_pstr_eq(n, m);
  ck_assert_ptr_eq(n, m);
}
START_TEST(test_strpbrk_nullend_2) {
  char line[6] = NULL_END_line;
  char searchline[6] = "t\0";
  char *n = NULL, *m = MY_NULL;
  n = strpbrk(line, searchline);
  m = s21_strpbrk(line, searchline);

  ck_assert_pstr_eq(n, m);
  ck_assert_ptr_eq(n, m);
}
START_TEST(test_strpbrk_nullend_3) {
  char line[6] = NULL_END_line;
  char searchline[6] = "\0";
  char *n = NULL, *m = MY_NULL;
  n = strpbrk(line, searchline);
  m = s21_strpbrk(line, searchline);

  ck_assert_pstr_eq(n, m);
  ck_assert_ptr_eq(n, m);
}
START_TEST(test_strpbrk_nullend_4) {
  char line[6] = NULL_END_line;
  char searchline[6] = {'G', 'H', 'T', '\0'};
  char *n = NULL, *m = MY_NULL;
  n = strpbrk(line, searchline);
  m = s21_strpbrk(line, searchline);

  ck_assert_pstr_eq(n, m);
  ck_assert_ptr_eq(n, m);
}
START_TEST(test_strpbrk_nullend_5) {
  char line[6] = FRIVE_CHAR_1;
  char searchline[6] = {'G', 'H', 'T', '\0'};
  char *n = NULL, *m = MY_NULL;
  n = strpbrk(line, searchline);
  m = s21_strpbrk(line, searchline);

  ck_assert_pstr_eq(n, m);
  ck_assert_ptr_eq(n, m);
}
START_TEST(test_strpbrk_nullmid_1) {
  char line[6] = NULL_MID_line;
  char searchline[6] = NULL_LINE;
  char *n = NULL, *m = MY_NULL;
  n = strpbrk(line, searchline);
  m = s21_strpbrk(line, searchline);

  ck_assert_pstr_eq(n, m);
  ck_assert_ptr_eq(n, m);
}
START_TEST(test_strpbrk_nullmid_2) {
  char line[6] = NULL_MID_line;
  char searchline[6] = "NTM";
  char *n = NULL, *m = MY_NULL;
  n = strpbrk(line, searchline);
  m = s21_strpbrk(line, searchline);

  ck_assert_pstr_eq(n, m);
  ck_assert_ptr_eq(n, m);
}
START_TEST(test_strpbrk_nullmid_3) {
  char line[5] = {'Z', 'F', '\0', 'T'};
  char searchline[5] = {'\0', 'T', 'Z', 'k'};
  char *n = NULL, *m = MY_NULL;
  n = strpbrk(line, searchline);
  m = s21_strpbrk(line, searchline);

  ck_assert_pstr_eq(n, m);
  ck_assert_ptr_eq(n, m);
}
START_TEST(test_strpbrk_entermid_1) {
  char line[5] = ENTER_MID_line;
  char searchline[5] = "\n";
  char *n = NULL, *m = MY_NULL;
  n = strpbrk(line, searchline);
  m = s21_strpbrk(line, searchline);

  ck_assert_pstr_eq(n, m);
  ck_assert_ptr_eq(n, m);
}
START_TEST(test_strpbrk_entermid_2) {
  char line[5] = ENTER_MID_line;
  char searchline[5] = "tmn";
  char *n = NULL, *m = MY_NULL;
  n = strpbrk(line, searchline);
  m = s21_strpbrk(line, searchline);

  ck_assert_pstr_eq(n, m);
  ck_assert_ptr_eq(n, m);
}
START_TEST(test_strpbrk_entermid_3) {
  char line[5] = ENTER_MID_line;
  char searchline[5] = {'G', 'H', '\n', 'T'};
  char *n = NULL, *m = MY_NULL;
  n = strpbrk(line, searchline);
  m = s21_strpbrk(line, searchline);

  ck_assert_pstr_eq(n, m);
  ck_assert_ptr_eq(n, m);
}
START_TEST(test_strpbrk_tabmid_1) {
  char line[5] = TAB_MID_line;
  char searchline[5] = "\t";
  char *n = NULL, *m = MY_NULL;
  n = strpbrk(line, searchline);
  m = s21_strpbrk(line, searchline);

  ck_assert_pstr_eq(n, m);
  ck_assert_ptr_eq(n, m);
}
START_TEST(test_strpbrk_tabmid_2) {
  char line[5] = TAB_MID_line;
  char searchline[5] = "tmn";
  char *n = NULL, *m = MY_NULL;
  n = strpbrk(line, searchline);
  m = s21_strpbrk(line, searchline);

  ck_assert_pstr_eq(n, m);
  ck_assert_ptr_eq(n, m);
}
START_TEST(test_strpbrk_tabmid_3) {
  char line[5] = TAB_MID_line;
  char searchline[5] = {'G', 'H', '\t', 'T'};
  char *n = NULL, *m = MY_NULL;
  n = strpbrk(line, searchline);
  m = s21_strpbrk(line, searchline);

  ck_assert_pstr_eq(n, m);
  ck_assert_ptr_eq(n, m);
}
START_TEST(test_strpbrk_enterend_1) {
  char line[5] = ENTER_END_line;
  char searchline[5] = "\n";
  char *n = NULL, *m = MY_NULL;
  n = strpbrk(line, searchline);
  m = s21_strpbrk(line, searchline);

  ck_assert_pstr_eq(n, m);
  ck_assert_ptr_eq(n, m);
}
START_TEST(test_strpbrk_invis_1) {
  char line[33] = INVIS_CHAR;
  char searchline[5] = {'g', 'm', 15, 't'};
  char *n = NULL, *m = MY_NULL;
  n = strpbrk(line, searchline);
  m = s21_strpbrk(line, searchline);

  ck_assert_pstr_eq(n, m);
  ck_assert_ptr_eq(n, m);
}
START_TEST(test_strpbrk_invis_2) {
  char line[33] = INVIS_CHAR;
  char searchline[5] = {'g', 'm', 10, 't'};
  char *n = NULL, *m = MY_NULL;
  n = strpbrk(line, searchline);
  m = s21_strpbrk(line, searchline);

  ck_assert_pstr_eq(n, m);
  ck_assert_ptr_eq(n, m);
}
START_TEST(test_strpbrk_invis_3) {
  char line[33] = INVIS_CHAR;
  char searchline[5] = {'g', 'm', 25, 't'};
  char *n = NULL, *m = MY_NULL;
  n = strpbrk(line, searchline);
  m = s21_strpbrk(line, searchline);

  ck_assert_pstr_eq(n, m);
  ck_assert_ptr_eq(n, m);
}
START_TEST(test_strpbrk_invis_4) {
  char line[6] = FRIVE_CHAR_1;
  char searchline[33] = INVIS_CHAR;
  char *n = NULL, *m = MY_NULL;
  n = strpbrk(line, searchline);
  m = s21_strpbrk(line, searchline);

  ck_assert_pstr_eq(n, m);
  ck_assert_ptr_eq(n, m);
}
START_TEST(test_strpbrk_invis_8) {
  char line[6] = {'6', '5', '9', '7', '1'};
  char searchline[33] = INVIS_CHAR;
  char *n = NULL, *m = MY_NULL;
  n = strpbrk(line, searchline);
  m = s21_strpbrk(line, searchline);

  ck_assert_pstr_eq(n, m);
  ck_assert_ptr_eq(n, m);
}
START_TEST(test_strpbrk_invis_9) {
  char line[6] = {'6', '0', '9', 7, '1'};
  char searchline[33] = INVIS_CHAR;
  char *n = NULL, *m = MY_NULL;
  n = strpbrk(line, searchline);
  m = s21_strpbrk(line, searchline);

  ck_assert_pstr_eq(n, m);
  ck_assert_ptr_eq(n, m);
}
START_TEST(test_strpbrk_invis_5) {
  char line[33] = INVIS_CHAR;
  char searchline[33] = INVIS_CHAR;
  char *n = NULL, *m = MY_NULL;
  n = strpbrk(line, searchline);
  m = s21_strpbrk(line, searchline);

  ck_assert_pstr_eq(n, m);
  ck_assert_ptr_eq(n, m);
}
START_TEST(test_strpbrk_invis_6) {
  char line[5] = NULL_MID_line;
  char searchline[33] = INVIS_CHAR;
  char *n = NULL, *m = MY_NULL;
  n = strpbrk(line, searchline);
  m = s21_strpbrk(line, searchline);

  ck_assert_pstr_eq(n, m);
  ck_assert_ptr_eq(n, m);
}
START_TEST(test_strpbrk_invis_7) {
  char line[5] = {'g', 15, 25, 'f'};
  char searchline[33] = INVIS_CHAR;
  char *n = NULL, *m = MY_NULL;
  n = strpbrk(line, searchline);
  m = s21_strpbrk(line, searchline);

  ck_assert_pstr_eq(n, m);
  ck_assert_ptr_eq(n, m);
}
// 7.3
START_TEST(test_strpbrk_nullline_1) {
  char line[5] = NULL_LINE;
  char searchline[6] = FRIVE_CHAR_1;
  char *n = NULL, *m = MY_NULL;
  n = strpbrk(line, searchline);
  m = s21_strpbrk(line, searchline);

  ck_assert_pstr_eq(n, m);
  ck_assert_ptr_eq(n, m);
}
START_TEST(test_strpbrk_nullline_3) {
  char line[6] = FRIVE_CHAR_1;
  char searchline[5] = NULL_LINE;
  char *n = NULL, *m = MY_NULL;
  n = strpbrk(line, searchline);
  m = s21_strpbrk(line, searchline);

  ck_assert_pstr_eq(n, m);
  ck_assert_ptr_eq(n, m);
}
// 7.4
START_TEST(test_strpbrk_long_1) {
  char line[LONG_CHECK_LINE] = NULL_LINE;
  rand_str(line, LONG_CHECK_LINE - 1);
  char searchline[10] = "asdfghjkl";
  char *n = NULL, *m = MY_NULL;
  n = strpbrk(line, searchline);
  m = s21_strpbrk(line, searchline);

  ck_assert_pstr_eq(n, m);
  ck_assert_ptr_eq(n, m);
}
START_TEST(test_strpbrk_long_2) {
  char line[LONG_CHECK_LINE] = NULL_LINE;
  rand_str(line, LONG_CHECK_LINE - 1);
  char searchline[LONG_CHECK_LINE] = NULL_LINE;
  rand_str(searchline, LONG_CHECK_LINE - 1);
  char *n = NULL, *m = MY_NULL;
  n = strpbrk(line, searchline);
  m = s21_strpbrk(line, searchline);

  ck_assert_pstr_eq(n, m);
  ck_assert_ptr_eq(n, m);
}
START_TEST(test_strpbrk_long_3) {
  char line[LONG_CHECK_LINE] = NULL_LINE;
  rand_str(line, LONG_CHECK_LINE - 1);
  char searchline[33] = INVIS_CHAR;
  char *n = NULL, *m = MY_NULL;
  n = strpbrk(line, searchline);
  m = s21_strpbrk(line, searchline);

  ck_assert_pstr_eq(n, m);
  ck_assert_ptr_eq(n, m);
}
START_TEST(test_strpbrk_long_4) {
  char line[LONG_CHECK_LINE] = NULL_LINE;
  rand_str(line, LONG_CHECK_LINE - 1);
  char searchline[5] = ENTER_MID_line;
  char *n = NULL, *m = MY_NULL;
  n = strpbrk(line, searchline);
  m = s21_strpbrk(line, searchline);

  ck_assert_pstr_eq(n, m);
  ck_assert_ptr_eq(n, m);
}
START_TEST(test_strpbrk_long_5) {
  char line[33] = INVIS_CHAR;
  char searchline[LONG_CHECK_LINE] = NULL_LINE;
  rand_str(searchline, LONG_CHECK_LINE - 1);
  char *n = NULL, *m = MY_NULL;
  n = strpbrk(line, searchline);
  m = s21_strpbrk(line, searchline);

  ck_assert_pstr_eq(n, m);
  ck_assert_ptr_eq(n, m);
}
START_TEST(test_strpbrk_long_6) {
  char line[5] = "asdf";
  char searchline[LONG_CHECK_LINE] = NULL_LINE;
  rand_str(searchline, LONG_CHECK_LINE - 1);
  char *n = NULL, *m = MY_NULL;
  n = strpbrk(line, searchline);
  m = s21_strpbrk(line, searchline);

  ck_assert_pstr_eq(n, m);
  ck_assert_ptr_eq(n, m);
}
START_TEST(test_strpbrk_long_7) {
  char line[5] = "\n";
  char searchline[LONG_CHECK_LINE * 10] = NULL_LINE;
  rand_str(searchline, LONG_CHECK_LINE * 10 - 1);
  char *n = NULL, *m = MY_NULL;
  n = strpbrk(line, searchline);
  m = s21_strpbrk(line, searchline);

  ck_assert_pstr_eq(n, m);
  ck_assert_ptr_eq(n, m);
}

// strtok    //elevator
// 8.0
START_TEST(test_strtok_lineschange) {
  char line[6] = "asdfg";
  char line2[6] = NULL_LINE;
  char line3[6] = NULL_LINE;
  strcpy(line3, line);
  strcpy(line2, line);
  char divline[6] = "fs";
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line3, divline);
  ck_assert_pstr_eq(n, m);
  ck_assert_pstr_ne(line, line2);
  ck_assert_pstr_ne(line3, line2);

  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
    ck_assert_pstr_ne(line, line2);
    ck_assert_pstr_ne(line3, line2);
  }
}
START_TEST(test_strtok_types) {
  char line[6] = "asdfg";
  char line2[6] = NULL_LINE;
  strcpy(line2, line);
  char divline[6] = "fs";
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
START_TEST(test_strtok_diflines_1) {
  char line[6] = "asdfg";
  char line2[6] = "asdfg";
  char divline[6] = "fs";
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);

  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
START_TEST(test_strtok_diflines_2) {
  char line[6] = "asdfg";
  char line2[6] = "afdfg";
  char divline[6] = "fs";
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);

  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
START_TEST(test_strtok_diflines_3) {
  char line[6] = "asdfg";
  char line2[6] = "pfpfp";
  char divline[6] = "fs";
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_ne(n, m);

  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    if (n != MY_NULL && m != NULL) ck_assert_pstr_ne(n, m);
  }
}
START_TEST(test_strtok_diflines_4) {
  char line[6] = "asdfg";
  char line2[6] = "afpfp";
  char divline[6] = "fs";
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);

  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    if (n != MY_NULL && m != NULL) ck_assert_pstr_ne(n, m);
  }
}
// 8.1
START_TEST(test_strtok_norm_1) {
  char line[6] = "asdfg";
  char line2[6] = NULL_LINE;
  strcpy(line2, line);
  char divline[6] = "fs";
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
START_TEST(test_strtok_norm_2) {
  char line[6] = "asdfg";
  char line2[6] = NULL_LINE;
  strcpy(line2, line);
  char divline[6] = "afs";
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
START_TEST(test_strtok_norm_3) {
  char line[6] = "asdfg";
  char line2[6] = NULL_LINE;
  strcpy(line2, line);
  char divline[6] = "gfkps";
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
START_TEST(test_strtok_norm_4) {
  char line[84] = "https://youtu.be/dQw4w9WgXcQ?si=V_2-moWdSx-jhLE7";
  char line2[84] = NULL_LINE;
  strcpy(line2, line);
  char divline[6] = ":/.";
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
START_TEST(test_strtok_norm_5) {
  char line[84] =
      "/home/jackoneill/Programming/s21/StrString/C2_s21_stringplus-1/src";
  char line2[84] = NULL_LINE;
  strcpy(line2, line);
  char divline[6] = "/";
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
START_TEST(test_strtok_norm_6) {
  char line[370] =
      "You motherfucker, come on you little ass… fuck with me, eh? You fucking "
      "little asshole, dickhead cocksucker…You fuckin' come on, come fuck with "
      "me! I'll get your ass, you jerk! Oh, you fuckhead motherfucker! Fuck "
      "all you and your family! Come on, you cocksucker, slime bucket, "
      "shitface turdball! Come on, you scum sucker, you fucking with me? Come "
      "on, you asshole!";
  char line2[370] = NULL_LINE;
  strcpy(line2, line);
  char divline[6] = " ";
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
START_TEST(test_strtok_norm_7) {
  char line[15] = "Hello. .World";
  char line2[15] = NULL_LINE;
  strcpy(line2, line);
  char divline[6] = ".";
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
START_TEST(test_strtok_norm_8) {
  char line[20] = "Hello.....World";
  char line2[20] = NULL_LINE;
  strcpy(line2, line);
  char divline[6] = ".";
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
START_TEST(test_strtok_norm_9) {
  char line[16] = "Hello.....World";
  char line2[16] = NULL_LINE;
  strcpy(line2, line);
  char divline[6] = "_";
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
START_TEST(test_strtok_norm_10) {
  char line[16] = "Hello.....World";
  char line2[16] = NULL_LINE;
  strcpy(line2, line);
  char divline[6] = "a";
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
START_TEST(test_strtok_norm_11) {
  char line[116] =
      " fff..Fg.fgg  dscsdc scdscs.. . dcscsdcs.cs c..cs   .cdscs  .  .   ... "
      "cdscscs cdscs.cdscsd dcsc.csc s.cscs .scscsc";
  char line2[116] = NULL_LINE;
  strcpy(line2, line);
  char divline[6] = " .";
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
START_TEST(test_strtok_norm_12) {
  char line[116] =
      " fff..Fg.fgg  dscsdc scdscs.. . dcscsdcs.cs c..cs   .cdscs  .  .   ... "
      "cdscscs cdscs.cdscsd dcsc.csc s.cscs .scscsc";
  char line2[116] = NULL_LINE;
  strcpy(line2, line);
  char divline[6] = {'.', ' '};
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
START_TEST(test_strtok_norm_13) {
  char line[116] =
      " fff..Fg.fgg  dscsdc scdscs.. . dcscsdcs.cs c..cs   .cdscs  .  .   ... "
      "cdscscs cdscs.cdscsd dcsc.csc s.cscs .scscsc";
  char line2[116] = NULL_LINE;
  strcpy(line2, line);
  char divline[6] = {'z'};
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
START_TEST(test_strtok_norm_14) {
  char line[120] =
      " fff..Fg.fgg  dscsdc scdscs.. . dcscsdcs.cs c..cs   .cdscs  .  .   ... "
      "cdscscs cdscs.cdscsd dcsc.csc s.cscs .scscsc";
  char line2[120] = NULL_LINE;
  strcpy(line2, line);
  char divline[6] = {' '};
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
// 8.2
START_TEST(test_strtok_nullendline_1) {
  char line[6] = NULL_END_line;
  char line2[6] = NULL_LINE;
  strcpy(line2, line);
  char divline[6] = "t";
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
START_TEST(test_strtok_nullendline_2) {
  char line[6] = NULL_END_line;
  char line2[6] = NULL_LINE;
  strcpy(line2, line);
  char divline[6] = "\t \0";
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
START_TEST(test_strtok_nullmidline_1) {
  char line[5] = NULL_MID_line;
  char line2[5] = NULL_LINE;
  strcpy(line2, line);
  char divline[4] = "TZ";
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
START_TEST(test_strtok_nullmidline_3) {
  char line[5] = NULL_MID_line;
  char line2[5] = NULL_LINE;
  strcpy(line2, line);
  char divline[4] = "TZ\0";
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
START_TEST(test_strtok_nullmidline_2) {
  char line[8] = "ZggTffT";
  char line2[8] = NULL_LINE;
  strcpy(line2, line);
  char divline[5] = NULL_MID_line;
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
START_TEST(test_strtok_nullmidline_4) {
  char line[8] = {'z', 't', 't', '\0', 'k', 't', 'z'};
  char line2[8] = NULL_LINE;
  strcpy(line2, line);
  char divline[2] = {'t'};
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
START_TEST(test_strtok_entermidline_1) {
  char line[9] = ENTER_MID_line;
  char line2[9] = NULL_LINE;
  strcpy(line2, line);
  char divline[3] = {'\n'};
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
START_TEST(test_strtok_entermidline_2) {
  char line[9] = ENTER_MID_line;
  char line2[9] = NULL_LINE;
  strcpy(line2, line);
  char divline[3] = {'\n', 'h'};
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
START_TEST(test_strtok_entermidline_3) {
  char line[9] = {'g', 'h', '\n', 't', 'k', 'l'};
  char line2[9] = NULL_LINE;
  strcpy(line2, line);
  char divline[3] = {'\n', 'k'};
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
START_TEST(test_strtok_enterendline) {
  char line[9] = ENTER_END_line;
  char line2[9] = NULL_LINE;
  strcpy(line2, line);
  char divline[3] = {'\n', 'h'};
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
START_TEST(test_strtok_tabendline) {
  char line[9] = TAB_END_line;
  char line2[9] = NULL_LINE;
  strcpy(line2, line);
  char divline[3] = {'\t', 'h'};
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
START_TEST(test_strtok_tabmidline_1) {
  char line[9] = TAB_MID_line;
  char line2[9] = NULL_LINE;
  strcpy(line2, line);
  char divline[3] = {'\t'};
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
START_TEST(test_strtok_tabmidline_2) {
  char line[9] = TAB_MID_line;
  char line2[9] = NULL_LINE;
  strcpy(line2, line);
  char divline[3] = {'\t', 'h'};
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
START_TEST(test_strtok_tabmidline_3) {
  char line[9] = {'g', 'h', '\t', 't', 'k', 'l'};
  char line2[9] = NULL_LINE;
  strcpy(line2, line);
  char divline[3] = {'\t', 'k'};
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
START_TEST(test_strtok_tabmidline_4) {
  char line[9] = {'g', 'h', '\t', 't', 'k', 'l'};
  char line2[9] = NULL_LINE;
  strcpy(line2, line);
  char divline[4] = {'\n', 'k', '\0'};
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
START_TEST(test_strtok_invis_1) {
  char line[33] = INVIS_CHAR;
  char line2[33] = NULL_LINE;
  strcpy(line2, line);
  char divline[4] = {'n', 'k', 't'};
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
START_TEST(test_strtok_invis_2) {
  char line[33] = INVIS_CHAR;
  char line2[33] = NULL_LINE;
  strcpy(line2, line);
  char divline[4] = {'9', '0', '\0'};
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
START_TEST(test_strtok_invis_3) {
  char line[33] = INVIS_CHAR;
  char line2[33] = NULL_LINE;
  strcpy(line2, line);
  char divline[10] = {'9', '0', '\0', '\t', '\n', 10};
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
START_TEST(test_strtok_invis_4) {
  char line[33] = INVIS_CHAR;
  char line2[33] = NULL_LINE;
  strcpy(line2, line);
  char divline[10] = {10, 15, 5, 20, 25, 30, 7, 32, 1};
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
START_TEST(test_strtok_invis_5) {
  char line[33] = INVIS_CHAR;
  char line2[33] = NULL_LINE;
  strcpy(line2, line);
  char divline[33] = INVIS_CHAR;
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
START_TEST(test_strtok_invis_6) {
  char line[10] = {10, 15, 5, 20, 25, 30, 7, 32, 1};
  char line2[10] = NULL_LINE;
  strcpy(line2, line);
  char divline[33] = INVIS_CHAR;
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
START_TEST(test_strtok_invis_7) {
  char line[10] = {'1', '5', '5', '2', '2', '3', '0', '\t', '1'};
  char line2[10] = NULL_LINE;
  strcpy(line2, line);
  char divline[33] = INVIS_CHAR;
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
START_TEST(test_strtok_invis_8) {
  char line[15] = "asd\tasd\nasd";
  char line2[15] = NULL_LINE;
  strcpy(line2, line);
  char divline[33] = INVIS_CHAR;
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
START_TEST(test_strtok_invis_9) {
  char line[15] = {'a', 'f', '\n', 'a', '.', 5, '\n', 'f', '5', 15, 'd'};
  char line2[15] = NULL_LINE;
  strcpy(line2, line);
  char divline[33] = INVIS_CHAR;
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
// 8.3
START_TEST(test_strtok_nullline_1) {
  char line[15] = NULL_LINE;
  char line2[15] = NULL_LINE;
  strcpy(line2, line);
  char divline[33] = ENTER_MID_line;
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
START_TEST(test_strtok_nullline_2) {
  char line[15] = NULL_LINE;
  char line2[15] = NULL_LINE;
  strcpy(line2, line);
  char divline[33] = NULL_MID_line;
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
START_TEST(test_strtok_nullline_3) {
  char line[15] = NULL_LINE;
  char line2[15] = NULL_LINE;
  strcpy(line2, line);
  char divline[5] = NULL_LINE;
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
START_TEST(test_strtok_nullline_4) {
  char line[15] = FRIVE_CHAR_1;
  char line2[15] = NULL_LINE;
  strcpy(line2, line);
  char divline[5] = NULL_LINE;
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
START_TEST(test_strtok_nullline_5) {
  char line[15] = NULL_MID_line;
  char line2[15] = NULL_LINE;
  strcpy(line2, line);
  char divline[5] = NULL_LINE;
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
// 8.4
/*
START_TEST(test_strtok_longline_1) {
  char line[LONG_CHECK_LINE * 10] = NULL_LINE;
  rand_str(line, LONG_CHECK_LINE * 10 - 1);
  char line2[LONG_CHECK_LINE * 10] = NULL_LINE;
  strcpy(line2, line);
  char divline[33] = INVIS_CHAR;
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
START_TEST(test_strtok_longline_2) {
  char line[LONG_CHECK_LINE * 10] = NULL_LINE;
  rand_str(line, LONG_CHECK_LINE * 10 - 1);
  char line2[LONG_CHECK_LINE * 10] = NULL_LINE;
  strcpy(line2, line);
  char divline[15] = "asdfghjkl;";
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
*/
/*
//takes too much time
START_TEST(test_strtok_longline_3) {
    char line[LONG_CHECK_LINE*10] = NULL_LINE;
    rand_str(line,LONG_CHECK_LINE*10-1);
    char line2[LONG_CHECK_LINE*10]=NULL_LINE;
    strcpy(line2,line);
    char divline[LONG_CHECK_LINE*10] = NULL_LINE;
    rand_str(divline,LONG_CHECK_LINE*10-1);
    char* n=NULL, *m=MY_NULL;
    n=strtok(line,divline);
    m=s21_strtok(line2,divline);
    ck_assert_pstr_eq(n,m);
    for(;n!=MY_NULL && m!=NULL;){
        n=strtok(MY_NULL,divline);
        m=s21_strtok(NULL,divline);
        ck_assert_pstr_eq(n,m);
    }
}
*/
START_TEST(test_strtok_longline_4) {
  char line[35] = "sdadfddsd..asdada_fsfwqdqwdq";
  char line2[35] = NULL_LINE;
  strcpy(line2, line);
  char divline[LONG_CHECK_LINE * 10] = NULL_LINE;
  rand_str(divline, LONG_CHECK_LINE * 10 - 1);
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
START_TEST(test_strtok_longline_5) {
  char line[35] = "aaaaaaaaaaaaaaaaaaaa";
  char line2[35] = NULL_LINE;
  strcpy(line2, line);
  char divline[LONG_CHECK_LINE * 10] = NULL_LINE;
  rand_str(divline, LONG_CHECK_LINE * 10 - 1);
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
START_TEST(test_strtok_longline_6) {
  char line[35] = {5, 6, 7, 0};
  char line2[35] = NULL_LINE;
  strcpy(line2, line);
  char divline[LONG_CHECK_LINE * 10] = NULL_LINE;
  rand_str(divline, LONG_CHECK_LINE * 10 - 1);
  char *n = NULL, *m = MY_NULL;
  n = strtok(line, divline);
  m = s21_strtok(line2, divline);
  ck_assert_pstr_eq(n, m);
  for (; n != MY_NULL && m != NULL;) {
    n = strtok(MY_NULL, divline);
    m = s21_strtok(NULL, divline);
    ck_assert_pstr_eq(n, m);
  }
}
// s21_sscanf
// 9.0   //elevator
START_TEST(test_sscanf_blanks) {
  char input_line_0[] =
      "5  55 \n\t\n  -555                     zpep\t  \n 5555end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(
      sscanf(input_line_0, "%d\n\t\t\t\n%d%d zpep                    %d\n\n%s",
             &intt1, &intt2, &intt3, &intt4, endd1),
      s21_sscanf(input_line_1,
                 "%d\n\t\t\t\n%d%d zpep                    %d\n\n%s", &intt6,
                 &intt7, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
/*
START_TEST(test_sscanf_oldy) {
    char line[]="num:001234567890 -  - \n\n -1235---hello -0X1f0Aa----0.54E3
010\n--\nfghjklqw erty uiop 0x7FFdd251f78c   %   hell 12345 -0X10A  \0";
   // char
templine[]={'1',1,'2',2,'3',3,'4',4,'5',5,'6',6,'7',7,'8',8,'9',14,'0',15,'z',16,'x',17,'c',18,'v',19,'b',20,'n',21,'m',22,'a',23,'s',24,'d',25,'f',26,'g',27,'h',28,'j',29,'k',30,'l',31,'q',32,'w','e'};
    char line_2[130];
    strcpy(line_2,line);
    unsigned int num1=5, num2=5, num5=0, num6=0;
    int num3=0, num4=0, num9=0, num10=0;
    long int num11=0, num12=0;
    float num7=0, num8=0;
    char sym1=0, sym2=0;
    char line1[100]={0,}, line2[100]={0}, line3[10]="0", line4[10]="0";
    char* p1=NULL, *p2=NULL;
    int n1=0, n2=0;

    //const char line[3] = "%d";
    //char* line2 = (char*) line;
    // size_t num2, num5, num6;
    // float num3;
    // char str1[100];
    //sscanf(line,"%20d, %3ld, %*s%s%*s %5f%5d %99ld %5ld", &num1,&num2,str1,
&num3,&num4, &num5,&num6);
    //printf("Result:%d-->%ld-->%s-->%f-->%d---->%ld-->%ld\n",
num1,num2,str1,num3,num4,num5,num6)
    //printf("--%s\n\n",s21_strtok(line2,"%"));
    //printf("--%s\n", line2);
    //line2=s21_strtok(line2,"%");
    //printf("==%s\n",line2);


    ck_assert_int_eq(s21_sscanf(line,"num:%u \n-\t-%d ---hello %x---%7G %o--%3c
%serty uiop %p%n %% %s %*d%li",&num1, &num3, &num5, &num8, &num9, &sym2, line1,
&p2, &n2, line4, &num12), sscanf(line_2,"num:%u \n-\t-%d ---hello%X---%7G %o
--\t %3c %s erty uiop %p       %n %%   %s %*d %li",&num2, &num4, &num6, &num7,
&num10,  &sym1, line2, &p1, &n1, line3,&num11)); ck_assert_uint_eq(num1,num2);
    ck_assert_int_eq(num1,num2);
    ck_assert_int_eq(num3,num4);
    ck_assert_int_eq(num5,num6);
    ck_assert_int_eq(num7,num8);
    ck_assert_int_eq(num9,num10);
    ck_assert_uint_eq(num9,num10);
    ck_assert_uint_eq(sym1,sym2);
    ck_assert_str_eq(line1,line2);
    ck_assert_ptr_eq(p1,p2);
    ck_assert_int_eq(n1,n2);
    ck_assert_str_eq(line3,line4);
    ck_assert_int_eq(num11,num12);



    //printf(">%d -- ",s21_sscanf(line,"num:%u \n-\t-%d ---hello %x---%7G
%o--%3c   %serty uiop %p%n %% %s %*d%li",&num1, &num3, &num5, &num8, &num9,
&sym2, line1,  &p2, &n2, line4, &num12));
    //printf("%p==%u\t%p==%d\t%d\t %f\t%d\t%c\t%s\t%p\t%d\t%s\t%ld<\n",
&num1,num1, &num3,num3, num5,num8,num9,sym2, line1,p2,  n2, line4, num12);
    //printf(">%d -- ",sscanf(line,"num:%u \n-\t-%d ---hello%X---%7G %o --\t %3c
%s erty uiop %p       %n %%   %s %*d %li",&num2, &num4, &num6, &num7, &num10,
&sym1, line2, &p1, &n1, line3,&num11));
    //printf("%p==%u\t%p==%d\t%d\t %f\t%d\t%c\t%s\t%p\t%d\t%s\t%ld<\n",
&num2,num2, &num4,num4, num6, num7,num10,sym1, line2, p1,n1, line3,num11);
}
*/
// 9.1 //elevator
START_TEST(test_sscanf_unsigned_1) {
  char input_line_0[] =
      "111111  11223344556677889900111222333444555  -55555  5555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt3 = 3, uintt4 = 4, uintt6 = 1,
               uintt7 = 2, uintt8 = 3, uintt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%u%u%u%u%s", &uintt1, &uintt2, &uintt3,
                          &uintt4, endd1),
                   s21_sscanf(input_line_1, "%u%u%u%u%s", &uintt6, &uintt7,
                              &uintt8, &uintt9, endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_int_eq(uintt3, uintt8);
  ck_assert_uint_eq(uintt3, uintt8);
  ck_assert_int_eq(uintt4, uintt9);
  ck_assert_uint_eq(uintt4, uintt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_2) {
  char input_line_0[] =
      "111111  11223344556677889900111222333444555  -55555  5555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt3 = 3, uintt4 = 4, uintt6 = 1,
               uintt7 = 2, uintt8 = 3, uintt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%u%%%u%u%u%s", &uintt1, &uintt2,
                          &uintt3, &uintt4, endd1),
                   s21_sscanf(input_line_1, "%u%%%u%u%u%s", &uintt6, &uintt7,
                              &uintt8, &uintt9, endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_int_eq(uintt3, uintt8);
  ck_assert_uint_eq(uintt3, uintt8);
  ck_assert_int_eq(uintt4, uintt9);
  ck_assert_uint_eq(uintt4, uintt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_3) {
  char input_line_0[] =
      "111111  11223344556677889900111222333444555  -55555  5555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt3 = 3, uintt4 = 4, uintt6 = 1,
               uintt7 = 2, uintt8 = 3, uintt9 = 4, uintt5 = 5, uintt10 = 5;
  ck_assert_int_eq(sscanf(input_line_0, "%u%7u%u%u%u%s", &uintt1, &uintt2,
                          &uintt5, &uintt3, &uintt4, endd1),
                   s21_sscanf(input_line_1, "%u%7u%u%u%u%s", &uintt6, &uintt7,
                              &uintt10, &uintt8, &uintt9, endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_int_eq(uintt3, uintt8);
  ck_assert_uint_eq(uintt3, uintt8);
  ck_assert_int_eq(uintt4, uintt9);
  ck_assert_uint_eq(uintt4, uintt9);
  ck_assert_int_eq(uintt5, uintt10);
  ck_assert_uint_eq(uintt5, uintt10);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_5) {
  char input_line_0[] =
      "111111  11223344556677889900111222333444555  -55555  5555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt3 = 3, uintt6 = 1, uintt7 = 2,
               uintt8 = 3;
  ck_assert_int_eq(
      sscanf(input_line_0, "%u%*u%u%u%s", &uintt1, &uintt2, &uintt3, endd1),
      s21_sscanf(input_line_1, "%u%*u%u%u%s", &uintt6, &uintt7, &uintt8,
                 endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_int_eq(uintt3, uintt8);
  ck_assert_uint_eq(uintt3, uintt8);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_6) {
  char input_line_0[] =
      "111111  11223344556677889900111222333444555  -55555  5555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt3 = 3, uintt4 = 4, uintt6 = 1,
               uintt7 = 2, uintt8 = 3, uintt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%u%*26u%u%u%u%s", &uintt1, &uintt2,
                          &uintt3, &uintt4, endd1),
                   s21_sscanf(input_line_1, "%u%*26u%u%u%u%s", &uintt6, &uintt7,
                              &uintt8, &uintt9, endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_int_eq(uintt3, uintt8);
  ck_assert_uint_eq(uintt3, uintt8);
  ck_assert_int_eq(uintt4, uintt9);
  ck_assert_uint_eq(uintt4, uintt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_7) {
  char input_line_0[] =
      "2147483647  11223344556677889900111222333444555  -55555  5555.444  "
      "end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt3 = 3, uintt4 = 4, uintt6 = 1,
               uintt7 = 2, uintt8 = 3, uintt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%u%*26u%u%u%u%s", &uintt1, &uintt2,
                          &uintt3, &uintt4, endd1),
                   s21_sscanf(input_line_1, "%u%*26u%u%u%u%s", &uintt6, &uintt7,
                              &uintt8, &uintt9, endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_int_eq(uintt3, uintt8);
  ck_assert_uint_eq(uintt3, uintt8);
  ck_assert_int_eq(uintt4, uintt9);
  ck_assert_uint_eq(uintt4, uintt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_8) {
  char input_line_0[] =
      "21474  11223344556677889900111222333444555  -2147483647  5555.444  "
      "end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt3 = 3, uintt4 = 4, uintt6 = 1,
               uintt7 = 2, uintt8 = 3, uintt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%u%*26u%u%u%u%s", &uintt1, &uintt2,
                          &uintt3, &uintt4, endd1),
                   s21_sscanf(input_line_1, "%u%*26u%u%u%u%s", &uintt6, &uintt7,
                              &uintt8, &uintt9, endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_int_eq(uintt3, uintt8);
  ck_assert_uint_eq(uintt3, uintt8);
  ck_assert_int_eq(uintt4, uintt9);
  ck_assert_uint_eq(uintt4, uintt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_9) {
  char input_line_0[] =
      "4294967294  11223344556677889900111222333444555  -55555  5555.444  "
      "end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt3 = 3, uintt4 = 4, uintt6 = 1,
               uintt7 = 2, uintt8 = 3, uintt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%u%*26u%u%u%u%s", &uintt1, &uintt2,
                          &uintt3, &uintt4, endd1),
                   s21_sscanf(input_line_1, "%u%*26u%u%u%u%s", &uintt6, &uintt7,
                              &uintt8, &uintt9, endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_int_eq(uintt3, uintt8);
  ck_assert_uint_eq(uintt3, uintt8);
  ck_assert_int_eq(uintt4, uintt9);
  ck_assert_uint_eq(uintt4, uintt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_10) {
  char input_line_0[] =
      "4294967295  11223344556677889900111222333444555  -55555  5555.444  "
      "end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt3 = 3, uintt4 = 4, uintt6 = 1,
               uintt7 = 2, uintt8 = 3, uintt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%u%*26u%u%u%u%s", &uintt1, &uintt2,
                          &uintt3, &uintt4, endd1),
                   s21_sscanf(input_line_1, "%u%*26u%u%u%u%s", &uintt6, &uintt7,
                              &uintt8, &uintt9, endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_int_eq(uintt3, uintt8);
  ck_assert_uint_eq(uintt3, uintt8);
  ck_assert_int_eq(uintt4, uintt9);
  ck_assert_uint_eq(uintt4, uintt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_11) {
  char input_line_0[] =
      "-4294967297  11223344556677889900111222333444555  -55555  5555.444  "
      "end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt3 = 3, uintt4 = 4, uintt6 = 1,
               uintt7 = 2, uintt8 = 3, uintt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%u%*26u%u%u%u%s", &uintt1, &uintt2,
                          &uintt3, &uintt4, endd1),
                   s21_sscanf(input_line_1, "%u%*26u%u%u%u%s", &uintt6, &uintt7,
                              &uintt8, &uintt9, endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_int_eq(uintt3, uintt8);
  ck_assert_uint_eq(uintt3, uintt8);
  ck_assert_int_eq(uintt4, uintt9);
  ck_assert_uint_eq(uintt4, uintt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_12) {
  char input_line_0[] =
      "   9223372036854774  11223344556677889900111222333444555  -55555  "
      "5555.444  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt3 = 3, uintt4 = 4, uintt6 = 1,
               uintt7 = 2, uintt8 = 3, uintt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%u%*26u%u%u%u%s", &uintt1, &uintt2,
                          &uintt3, &uintt4, endd1),
                   s21_sscanf(input_line_1, "%u%*26u%u%u%u%s", &uintt6, &uintt7,
                              &uintt8, &uintt9, endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_int_eq(uintt3, uintt8);
  ck_assert_uint_eq(uintt3, uintt8);
  ck_assert_int_eq(uintt4, uintt9);
  ck_assert_uint_eq(uintt4, uintt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_13) {
  char input_line_0[] = "   922337203685 55555 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt7 = 2, uintt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%5u%u%s", &uintt1, &uintt2, endd1),
      s21_sscanf(input_line_1, "%5u%u%s", &uintt6, &uintt7, endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_14) {
  char input_line_0[] = "   92233                    55555 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt7 = 2, uintt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%8u%u%s", &uintt1, &uintt2, endd1),
      s21_sscanf(input_line_1, "%8u%u%s", &uintt6, &uintt7, endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_15) {
  char input_line_0[] = "   +92233a567                    55555 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt7 = 2, uintt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%8u%u%s", &uintt1, &uintt2, endd1),
      s21_sscanf(input_line_1, "%8u%u%s", &uintt6, &uintt7, endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_16) {
  char input_line_0[] = "   92233a567                    55555 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt7 = 2, uintt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%8u%u%s", &uintt1, &uintt2, endd1),
      s21_sscanf(input_line_1, "%8u%u%s", &uintt6, &uintt7, endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_17) {
  char input_line_0[] = "   -4294967294                    -429496729455 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt7 = 2, uintt6 = 1;
  ck_assert_int_eq(sscanf(input_line_0, "%u%u%s", &uintt1, &uintt2, endd1),
                   s21_sscanf(input_line_1, "%u%u%s", &uintt6, &uintt7, endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_str_eq(endd1, endd2);
}
// 9.2 //elevator
START_TEST(test_sscanf_int_1) {
  char input_line_0[] =
      "111111  11223344556677889900111222333444555  -55555  5555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(
      sscanf(input_line_0, "%d%d%d%d%s", &intt1, &intt2, &intt3, &intt4, endd1),
      s21_sscanf(input_line_1, "%d%d%d%d%s", &intt6, &intt7, &intt8, &intt9,
                 endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_int_2) {
  char input_line_0[] =
      "111111  11223344556677889900111222333444555  -55555  5555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%d%%%d%d%d%s", &intt1, &intt2, &intt3,
                          &intt4, endd1),
                   s21_sscanf(input_line_1, "%d%%%d%d%d%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_int_7) {
  char input_line_0[] =
      "111111  %11223344556677889900111222333444555  -55555  5555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%d%%%d%d%d%s", &intt1, &intt2, &intt3,
                          &intt4, endd1),
                   s21_sscanf(input_line_1, "%d%%%d%d%d%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_int_3) {
  char input_line_0[] =
      "111111  11223344556677889900111222333444555  -55555  5555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4, intt5 = 5, intt10 = 5;
  ck_assert_int_eq(sscanf(input_line_0, "%d%7d%d%d%d%s", &intt1, &intt2, &intt5,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%d%7d%d%d%d%s", &intt6, &intt7,
                              &intt10, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_int_eq(intt5, intt10);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_int_5) {
  char input_line_0[] =
      "111111  11223344556677889900111222333444555  -55555  5555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt6 = 1, intt7 = 2, intt8 = 3;
  ck_assert_int_eq(
      sscanf(input_line_0, "%d%*d%d%d%s", &intt1, &intt2, &intt3, endd1),
      s21_sscanf(input_line_1, "%d%*d%d%d%s", &intt6, &intt7, &intt8, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_int_6) {
  char input_line_0[] =
      "111111  11223344556677889900111222333444555  -55555  5555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%d%*26d%d%d%d%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%d%*26d%d%d%d%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_int_8) {
  char input_line_0[] =
      "111111  11223344556677889900111222333444555  -55555  5555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%d%*25d%d%d%d%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%d%*25d%d%d%d%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_int_9) {
  char input_line_0[] =
      "2147483647  11223344556677889900111222333444555  -55555  5555.444  "
      "end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%d%*25d%d%d%d%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%d%*25d%d%d%d%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_int_10) {
  char input_line_0[] =
      "-2147483647  11223344556677889900111222333444555  -55555  5555.444  "
      "end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%d%*25d%d%d%d%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%d%*25d%d%d%d%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_int_11) {
  char input_line_0[] =
      "0  11223344556677889900111222333444555  -55555  5555.444  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%d%*25d%d%d%d%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%d%*25d%d%d%d%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_int_12) {
  char input_line_0[] =
      "  05.5  11223344556677889900111222333444555  -55555  5555.444  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%d%*25d%d%d%d%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%d%*25d%d%d%d%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_int_13) {
  char input_line_0[] =
      "-2147483648  11223344556677889900111222333444555  -55555  5555.444  "
      "end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%d%*25d%d%d%d%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%d%*25d%d%d%d%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_int_14) {
  char input_line_0[] =
      "-2147483649  11223344556677889900111222333444555  -55555  5555.444  "
      "end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%d%*25d%d%d%d%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%d%*25d%d%d%d%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_int_15) {
  char input_line_0[] =
      "2147483655  11223344556677889900111222333444555  -55555  5555.444  "
      "end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%d%*25d%d%d%d%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%d%*25d%d%d%d%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_int_16) {
  char input_line_0[] = "   922337203685 55555 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt7 = 2, intt6 = 1;
  ck_assert_int_eq(sscanf(input_line_0, "%5d%d%s", &intt1, &intt2, endd1),
                   s21_sscanf(input_line_1, "%5d%d%s", &intt6, &intt7, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_int_17) {
  char input_line_0[] = "   92233                    55555 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt7 = 2, intt6 = 1;
  ck_assert_int_eq(sscanf(input_line_0, "%8d%d%s", &intt1, &intt2, endd1),
                   s21_sscanf(input_line_1, "%8d%d%s", &intt6, &intt7, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_int_18) {
  char input_line_0[] = "   +92233a567                    55555 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt7 = 2, intt6 = 1;
  ck_assert_int_eq(sscanf(input_line_0, "%8d%d%s", &intt1, &intt2, endd1),
                   s21_sscanf(input_line_1, "%8d%d%s", &intt6, &intt7, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_int_19) {
  char input_line_0[] = "   92233a567                    55555 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt7 = 2, intt6 = 1;
  ck_assert_int_eq(sscanf(input_line_0, "%8d%d%s", &intt1, &intt2, endd1),
                   s21_sscanf(input_line_1, "%8d%d%s", &intt6, &intt7, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_int_20) {
  char input_line_0[] = "  -.6                   -0.6 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt7 = 2, intt6 = 1;
  ck_assert_int_eq(sscanf(input_line_0, "%8d%d%s", &intt1, &intt2, endd1),
                   s21_sscanf(input_line_1, "%8d%d%s", &intt6, &intt7, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_int_21) {
  char input_line_0[] = "  .6                   -0.6 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt7 = 2, intt6 = 1;
  ck_assert_int_eq(sscanf(input_line_0, "%8d%d%s", &intt1, &intt2, endd1),
                   s21_sscanf(input_line_1, "%8d%d%s", &intt6, &intt7, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_int_22) {
  char input_line_0[] = "  -f                   -0.6 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt7 = 2, intt6 = 1;
  ck_assert_int_eq(sscanf(input_line_0, "%8d%d%s", &intt1, &intt2, endd1),
                   s21_sscanf(input_line_1, "%8d%d%s", &intt6, &intt7, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_int_23) {
  char input_line_0[] = "  4294967304                  -4294967304 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt7 = 2, intt6 = 1;
  ck_assert_int_eq(sscanf(input_line_0, "%d%d%s", &intt1, &intt2, endd1),
                   s21_sscanf(input_line_1, "%d%d%s", &intt6, &intt7, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_str_eq(endd1, endd2);
}
// 9.3 //elevator
START_TEST(test_sscanf_unsigned_short_1) {
  char input_line_0[] =
      "11111  11223344556677889900111222333444555  -5555  555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt3 = 3, ushortt4 = 4,
                 ushortt6 = 1, ushortt7 = 2, ushortt8 = 3, ushortt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hu%hu%hu%hu%s", &ushortt1, &ushortt2,
                          &ushortt3, &ushortt4, endd1),
                   s21_sscanf(input_line_1, "%hu%hu%hu%hu%s", &ushortt6,
                              &ushortt7, &ushortt8, &ushortt9, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_uint_eq(ushortt3, ushortt8);
  ck_assert_int_eq(ushortt3, ushortt8);
  ck_assert_uint_eq(ushortt4, ushortt9);
  ck_assert_int_eq(ushortt4, ushortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_2) {
  char input_line_0[] =
      "11111  11223344556677889900111222333444555  -5555  555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt3 = 3, ushortt4 = 4,
                 ushortt6 = 1, ushortt7 = 2, ushortt8 = 3, ushortt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hu%%%hu%hu%hu%s", &ushortt1,
                          &ushortt2, &ushortt3, &ushortt4, endd1),
                   s21_sscanf(input_line_1, "%hu%%%hu%hu%hu%s", &ushortt6,
                              &ushortt7, &ushortt8, &ushortt9, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_uint_eq(ushortt3, ushortt8);
  ck_assert_int_eq(ushortt3, ushortt8);
  ck_assert_uint_eq(ushortt4, ushortt9);
  ck_assert_int_eq(ushortt4, ushortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_7) {
  char input_line_0[] =
      "11111  %\n\n11223344556677889900111222333444555  -5555  555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt3 = 3, ushortt4 = 4,
                 ushortt6 = 1, ushortt7 = 2, ushortt8 = 3, ushortt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hu%%%hu%hu%hu%s", &ushortt1,
                          &ushortt2, &ushortt3, &ushortt4, endd1),
                   s21_sscanf(input_line_1, "%hu%%%hu%hu%hu%s", &ushortt6,
                              &ushortt7, &ushortt8, &ushortt9, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_uint_eq(ushortt3, ushortt8);
  ck_assert_int_eq(ushortt3, ushortt8);
  ck_assert_uint_eq(ushortt4, ushortt9);
  ck_assert_int_eq(ushortt4, ushortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_3) {
  char input_line_0[] =
      "11111  11223344556677889900111222333444555  -5555  555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt3 = 3, ushortt4 = 4,
                 ushortt6 = 1, ushortt7 = 2, ushortt8 = 3, ushortt9 = 4,
                 ushortt5 = 5, ushortt10 = 5;
  ck_assert_int_eq(
      sscanf(input_line_0, "%hu%7hu%hu%hu%hu%s", &ushortt1, &ushortt2,
             &ushortt5, &ushortt3, &ushortt4, endd1),
      s21_sscanf(input_line_1, "%hu%7hu%hu%hu%hu%s", &ushortt6, &ushortt7,
                 &ushortt10, &ushortt8, &ushortt9, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_uint_eq(ushortt3, ushortt8);
  ck_assert_int_eq(ushortt3, ushortt8);
  ck_assert_uint_eq(ushortt4, ushortt9);
  ck_assert_int_eq(ushortt4, ushortt9);
  ck_assert_uint_eq(ushortt5, ushortt10);
  ck_assert_int_eq(ushortt5, ushortt10);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_5) {
  char input_line_0[] =
      "11111  11223344556677889900111222333444555  -5555  555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt3 = 3, ushortt6 = 1,
                 ushortt7 = 2, ushortt8 = 3;
  ck_assert_int_eq(sscanf(input_line_0, "%hu%*u%hu%hu%s", &ushortt1, &ushortt2,
                          &ushortt3, endd1),
                   s21_sscanf(input_line_1, "%hu%*u%hu%hu%s", &ushortt6,
                              &ushortt7, &ushortt8, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_uint_eq(ushortt3, ushortt8);
  ck_assert_int_eq(ushortt3, ushortt8);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_6) {
  char input_line_0[] =
      "11111  11223344556677889900111222333444555  -5555  555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt3 = 3, ushortt4 = 4,
                 ushortt6 = 1, ushortt7 = 2, ushortt8 = 3, ushortt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hu%*30u%hu%hu%hu%s", &ushortt1,
                          &ushortt2, &ushortt3, &ushortt4, endd1),
                   s21_sscanf(input_line_1, "%hu%*30u%hu%hu%hu%s", &ushortt6,
                              &ushortt7, &ushortt8, &ushortt9, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_uint_eq(ushortt3, ushortt8);
  ck_assert_int_eq(ushortt3, ushortt8);
  ck_assert_uint_eq(ushortt4, ushortt9);
  ck_assert_int_eq(ushortt4, ushortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_8) {
  char input_line_0[] =
      "11111  11223344556677889900111222333444555  -5555  555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt3 = 3, ushortt4 = 4,
                 ushortt6 = 1, ushortt7 = 2, ushortt8 = 3, ushortt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hu%*25u%hu%hu%hu%s", &ushortt1,
                          &ushortt2, &ushortt3, &ushortt4, endd1),
                   s21_sscanf(input_line_1, "%hu%*25u%hu%hu%hu%s", &ushortt6,
                              &ushortt7, &ushortt8, &ushortt9, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_uint_eq(ushortt3, ushortt8);
  ck_assert_int_eq(ushortt3, ushortt8);
  ck_assert_uint_eq(ushortt4, ushortt9);
  ck_assert_int_eq(ushortt4, ushortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_9) {
  char input_line_0[] =
      "65534  11223344556677889900111222333444555  -5555  555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt3 = 3, ushortt4 = 4,
                 ushortt6 = 1, ushortt7 = 2, ushortt8 = 3, ushortt9 = 4;
  ck_assert_int_eq(
      sscanf(input_line_0, "%hu%*31u\n\n%hu%hu%hu%s", &ushortt1, &ushortt2,
             &ushortt3, &ushortt4, endd1),
      s21_sscanf(input_line_1, "%hu%*31u\n\n%hu%hu%hu%s", &ushortt6, &ushortt7,
                 &ushortt8, &ushortt9, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_uint_eq(ushortt3, ushortt8);
  ck_assert_int_eq(ushortt3, ushortt8);
  ck_assert_uint_eq(ushortt4, ushortt9);
  ck_assert_int_eq(ushortt4, ushortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_24) {
  char input_line_0[] =
      "-65534  11223344556677889900111222333444555  -5555  555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt3 = 3, ushortt4 = 4,
                 ushortt6 = 1, ushortt7 = 2, ushortt8 = 3, ushortt9 = 4;
  ck_assert_int_eq(
      sscanf(input_line_0, "%hu%*31u\n\n%hu%hu%hu%s", &ushortt1, &ushortt2,
             &ushortt3, &ushortt4, endd1),
      s21_sscanf(input_line_1, "%hu%*31u\n\n%hu%hu%hu%s", &ushortt6, &ushortt7,
                 &ushortt8, &ushortt9, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_uint_eq(ushortt3, ushortt8);
  ck_assert_int_eq(ushortt3, ushortt8);
  ck_assert_uint_eq(ushortt4, ushortt9);
  ck_assert_int_eq(ushortt4, ushortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_25) {
  char input_line_0[] =
      "32767  11223344556677889900111222333444555  -5555  555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt3 = 3, ushortt4 = 4,
                 ushortt6 = 1, ushortt7 = 2, ushortt8 = 3, ushortt9 = 4;
  ck_assert_int_eq(
      sscanf(input_line_0, "%hu%*31u\n\n%hu%hu%hu%s", &ushortt1, &ushortt2,
             &ushortt3, &ushortt4, endd1),
      s21_sscanf(input_line_1, "%hu%*31u\n\n%hu%hu%hu%s", &ushortt6, &ushortt7,
                 &ushortt8, &ushortt9, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_uint_eq(ushortt3, ushortt8);
  ck_assert_int_eq(ushortt3, ushortt8);
  ck_assert_uint_eq(ushortt4, ushortt9);
  ck_assert_int_eq(ushortt4, ushortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_26) {
  char input_line_0[] =
      "-32767  11223344556677889900111222333444555  -5555  555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt3 = 3, ushortt4 = 4,
                 ushortt6 = 1, ushortt7 = 2, ushortt8 = 3, ushortt9 = 4;
  ck_assert_int_eq(
      sscanf(input_line_0, "%hu%*31u\n\n%hu%hu%hu%s", &ushortt1, &ushortt2,
             &ushortt3, &ushortt4, endd1),
      s21_sscanf(input_line_1, "%hu%*31u\n\n%hu%hu%hu%s", &ushortt6, &ushortt7,
                 &ushortt8, &ushortt9, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_uint_eq(ushortt3, ushortt8);
  ck_assert_int_eq(ushortt3, ushortt8);
  ck_assert_uint_eq(ushortt4, ushortt9);
  ck_assert_int_eq(ushortt4, ushortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_27) {
  char input_line_0[] =
      "32770  11223344556677889900111222333444555  -5555  555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt3 = 3, ushortt4 = 4,
                 ushortt6 = 1, ushortt7 = 2, ushortt8 = 3, ushortt9 = 4;
  ck_assert_int_eq(
      sscanf(input_line_0, "%hu%*31u\n\n%hu%hu%hu%s", &ushortt1, &ushortt2,
             &ushortt3, &ushortt4, endd1),
      s21_sscanf(input_line_1, "%hu%*31u\n\n%hu%hu%hu%s", &ushortt6, &ushortt7,
                 &ushortt8, &ushortt9, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_uint_eq(ushortt3, ushortt8);
  ck_assert_int_eq(ushortt3, ushortt8);
  ck_assert_uint_eq(ushortt4, ushortt9);
  ck_assert_int_eq(ushortt4, ushortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_28) {
  char input_line_0[] =
      "65535   11223344556677889900111222333444555  -5555  555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt3 = 3, ushortt4 = 4,
                 ushortt6 = 1, ushortt7 = 2, ushortt8 = 3, ushortt9 = 4;
  ck_assert_int_eq(
      sscanf(input_line_0, "%hu%*31u\n\n%hu%hu%hu%s", &ushortt1, &ushortt2,
             &ushortt3, &ushortt4, endd1),
      s21_sscanf(input_line_1, "%hu%*31u\n\n%hu%hu%hu%s", &ushortt6, &ushortt7,
                 &ushortt8, &ushortt9, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_uint_eq(ushortt3, ushortt8);
  ck_assert_int_eq(ushortt3, ushortt8);
  ck_assert_uint_eq(ushortt4, ushortt9);
  ck_assert_int_eq(ushortt4, ushortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_29) {
  char input_line_0[] =
      "-65536   11223344556677889900111222333444555  -5555  555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt3 = 3, ushortt4 = 4,
                 ushortt6 = 1, ushortt7 = 2, ushortt8 = 3, ushortt9 = 4;
  ck_assert_int_eq(
      sscanf(input_line_0, "%hu%*31u\n\n%hu%hu%hu%s", &ushortt1, &ushortt2,
             &ushortt3, &ushortt4, endd1),
      s21_sscanf(input_line_1, "%hu%*31u\n\n%hu%hu%hu%s", &ushortt6, &ushortt7,
                 &ushortt8, &ushortt9, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_uint_eq(ushortt3, ushortt8);
  ck_assert_int_eq(ushortt3, ushortt8);
  ck_assert_uint_eq(ushortt4, ushortt9);
  ck_assert_int_eq(ushortt4, ushortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_10) {
  char input_line_0[] =
      "65536  11223344556677889900111222333444555  -55555  5555.444   end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt3 = 3, ushortt4 = 4,
                 ushortt6 = 1, ushortt7 = 2, ushortt8 = 3, ushortt9 = 4;
  ck_assert_int_eq(
      sscanf(input_line_0, "%hu%*31u\n\n%hu%hu%hu%s", &ushortt1, &ushortt2,
             &ushortt3, &ushortt4, endd1),
      s21_sscanf(input_line_1, "%hu%*31u\n\n%hu%hu%hu%s", &ushortt6, &ushortt7,
                 &ushortt8, &ushortt9, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_uint_eq(ushortt3, ushortt8);
  ck_assert_int_eq(ushortt3, ushortt8);
  ck_assert_uint_eq(ushortt4, ushortt9);
  ck_assert_int_eq(ushortt4, ushortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_11) {
  char input_line_0[] =
      "0  11223344556677889900111222333444555  -55555  5555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt3 = 3, ushortt4 = 4,
                 ushortt6 = 1, ushortt7 = 2, ushortt8 = 3, ushortt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hu%*31u%hu%hu%hu%s", &ushortt1,
                          &ushortt2, &ushortt3, &ushortt4, endd1),
                   s21_sscanf(input_line_1, "%hu%*31u%hu%hu%hu%s", &ushortt6,
                              &ushortt7, &ushortt8, &ushortt9, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_uint_eq(ushortt3, ushortt8);
  ck_assert_int_eq(ushortt3, ushortt8);
  ck_assert_uint_eq(ushortt4, ushortt9);
  ck_assert_int_eq(ushortt4, ushortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_12) {
  char input_line_0[] =
      "  05.5  11223344556677889900111222333444555  -55555  5555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt3 = 3, ushortt4 = 4,
                 ushortt6 = 1, ushortt7 = 2, ushortt8 = 3, ushortt9 = 4;
  ck_assert_int_eq(
      sscanf(input_line_0, "%hu%*31u%hu\t\t%hu%hu%s", &ushortt1, &ushortt2,
             &ushortt3, &ushortt4, endd1),
      s21_sscanf(input_line_1, "%hu%*31u%hu\t\t%hu%hu%s", &ushortt6, &ushortt7,
                 &ushortt8, &ushortt9, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_uint_eq(ushortt3, ushortt8);
  ck_assert_int_eq(ushortt3, ushortt8);
  ck_assert_uint_eq(ushortt4, ushortt9);
  ck_assert_int_eq(ushortt4, ushortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_16) {
  char input_line_0[] = "   922337203685 55555 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt6 = 1, ushortt7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%4hu%hu%s", &ushortt1, &ushortt2, endd1),
      s21_sscanf(input_line_1, "%4hu%hu%s", &ushortt6, &ushortt7, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_17) {
  char input_line_0[] = "   9223                    55555 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt6 = 1, ushortt7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%5hu%hu%s", &ushortt1, &ushortt2, endd1),
      s21_sscanf(input_line_1, "%5hu%hu%s", &ushortt6, &ushortt7, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_18) {
  char input_line_0[] = "   +923a567                    55555 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt6 = 1, ushortt7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%5hu%hu%s", &ushortt1, &ushortt2, endd1),
      s21_sscanf(input_line_1, "%5hu%hu%s", &ushortt6, &ushortt7, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_30) {
  char input_line_0[] = "   +923a567                    55555 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt6 = 1, ushortt7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%4hu\t\na%hu%s", &ushortt1, &ushortt2, endd1),
      s21_sscanf(input_line_1, "%4hu\t\na%hu%s", &ushortt6, &ushortt7, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_19) {
  char input_line_0[] = "   9223a567                    55555 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt6 = 1, ushortt7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%8hu%hu%s", &ushortt1, &ushortt2, endd1),
      s21_sscanf(input_line_1, "%8hu%hu%s", &ushortt6, &ushortt7, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_20) {
  char input_line_0[] = "  -.6                   -0.6 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt6 = 1, ushortt7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%5hu%hu%s", &ushortt1, &ushortt2, endd1),
      s21_sscanf(input_line_1, "%5hu%hu%s", &ushortt6, &ushortt7, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_21) {
  char input_line_0[] = "  .6                   -0.6 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt6 = 1, ushortt7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%5hu%hu%s", &ushortt1, &ushortt2, endd1),
      s21_sscanf(input_line_1, "%5hu%hu%s", &ushortt6, &ushortt7, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_22) {
  char input_line_0[] = "  -f                   -0.6 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt6 = 1, ushortt7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%5hu%hu%s", &ushortt1, &ushortt2, endd1),
      s21_sscanf(input_line_1, "%5hu%hu%s", &ushortt6, &ushortt7, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_23) {
  char input_line_0[] = "  42945                  -4294967304 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt6 = 1, ushortt7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%6hu%6hu%s", &ushortt1, &ushortt2, endd1),
      s21_sscanf(input_line_1, "%6hu%6hu%s", &ushortt6, &ushortt7, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_str_eq(endd1, endd2);
}
// 9.4 //elevator
START_TEST(test_sscanf_short_1) {
  char input_line_0[] =
      "11111  11223344556677889900111222333444555  -5555  555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short shortt1 = 1, shortt2 = 2, shortt3 = 3, shortt4 = 4, shortt6 = 1,
        shortt7 = 2, shortt8 = 3, shortt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hd%hd%hd%hd%s", &shortt1, &shortt2,
                          &shortt3, &shortt4, endd1),
                   s21_sscanf(input_line_1, "%hd%hd%hd%hd%s", &shortt6,
                              &shortt7, &shortt8, &shortt9, endd2));
  ck_assert_int_eq(shortt1, shortt6);
  ck_assert_int_eq(shortt2, shortt7);
  ck_assert_int_eq(shortt3, shortt8);
  ck_assert_int_eq(shortt4, shortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_2) {
  char input_line_0[] =
      "11111  11223344556677889900111222333444555  -5555  555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short shortt1 = 1, shortt2 = 2, shortt3 = 3, shortt4 = 4, shortt6 = 1,
        shortt7 = 2, shortt8 = 3, shortt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hd%%%hd%hd%hd%s", &shortt1, &shortt2,
                          &shortt3, &shortt4, endd1),
                   s21_sscanf(input_line_1, "%hd%%%hd%hd%hd%s", &shortt6,
                              &shortt7, &shortt8, &shortt9, endd2));
  ck_assert_int_eq(shortt1, shortt6);
  ck_assert_int_eq(shortt2, shortt7);
  ck_assert_int_eq(shortt3, shortt8);
  ck_assert_int_eq(shortt4, shortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_7) {
  char input_line_0[] =
      "11111  %\n\n11223344556677889900111222333444555  -5555  555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short shortt1 = 1, shortt2 = 2, shortt3 = 3, shortt4 = 4, shortt6 = 1,
        shortt7 = 2, shortt8 = 3, shortt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hd%%%hd%hd%hd%s", &shortt1, &shortt2,
                          &shortt3, &shortt4, endd1),
                   s21_sscanf(input_line_1, "%hd%%%hd%hd%hd%s", &shortt6,
                              &shortt7, &shortt8, &shortt9, endd2));
  ck_assert_int_eq(shortt1, shortt6);
  ck_assert_int_eq(shortt2, shortt7);
  ck_assert_int_eq(shortt3, shortt8);
  ck_assert_int_eq(shortt4, shortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_3) {
  char input_line_0[] =
      "11111  11223344556677889900111222333444555  -5555  555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short shortt1 = 1, shortt2 = 2, shortt3 = 3, shortt4 = 4, shortt6 = 1,
        shortt7 = 2, shortt8 = 3, shortt9 = 4, shortt5 = 5, shortt10 = 5;
  ck_assert_int_eq(sscanf(input_line_0, "%hd%7hd%hd%hd%hd%s", &shortt1,
                          &shortt2, &shortt5, &shortt3, &shortt4, endd1),
                   s21_sscanf(input_line_1, "%hd%7hd%hd%hd%hd%s", &shortt6,
                              &shortt7, &shortt10, &shortt8, &shortt9, endd2));
  ck_assert_int_eq(shortt1, shortt6);
  ck_assert_int_eq(shortt2, shortt7);
  ck_assert_int_eq(shortt3, shortt8);
  ck_assert_int_eq(shortt4, shortt9);
  ck_assert_int_eq(shortt5, shortt10);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_5) {
  char input_line_0[] =
      "11111  11223344556677889900111222333444555  -5555  555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short shortt1 = 1, shortt2 = 2, shortt3 = 3, shortt6 = 1, shortt7 = 2,
        shortt8 = 3;
  ck_assert_int_eq(sscanf(input_line_0, "%hd%*d%hd%hd%s", &shortt1, &shortt2,
                          &shortt3, endd1),
                   s21_sscanf(input_line_1, "%hd%*d%hd%hd%s", &shortt6,
                              &shortt7, &shortt8, endd2));
  ck_assert_int_eq(shortt1, shortt6);
  ck_assert_int_eq(shortt2, shortt7);
  ck_assert_int_eq(shortt3, shortt8);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_6) {
  char input_line_0[] =
      "11111  11223344556677889900111222333444555  -5555  555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short shortt1 = 1, shortt2 = 2, shortt3 = 3, shortt4 = 4, shortt6 = 1,
        shortt7 = 2, shortt8 = 3, shortt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hd%*30d%hd%hd%hd%s", &shortt1,
                          &shortt2, &shortt3, &shortt4, endd1),
                   s21_sscanf(input_line_1, "%hd%*30d%hd%hd%hd%s", &shortt6,
                              &shortt7, &shortt8, &shortt9, endd2));
  ck_assert_int_eq(shortt1, shortt6);
  ck_assert_int_eq(shortt2, shortt7);
  ck_assert_int_eq(shortt3, shortt8);
  ck_assert_int_eq(shortt4, shortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_8) {
  char input_line_0[] =
      "11111  11223344556677889900111222333444555  -5555  555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short shortt1 = 1, shortt2 = 2, shortt3 = 3, shortt4 = 4, shortt6 = 1,
        shortt7 = 2, shortt8 = 3, shortt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hd%*25d%hd%hd%hd%s", &shortt1,
                          &shortt2, &shortt3, &shortt4, endd1),
                   s21_sscanf(input_line_1, "%hd%*25d%hd%hd%hd%s", &shortt6,
                              &shortt7, &shortt8, &shortt9, endd2));
  ck_assert_int_eq(shortt1, shortt6);
  ck_assert_int_eq(shortt2, shortt7);
  ck_assert_int_eq(shortt3, shortt8);
  ck_assert_int_eq(shortt4, shortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_9) {
  char input_line_0[] =
      "65534  11223344556677889900111222333444555  -5555  555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short shortt1 = 1, shortt2 = 2, shortt3 = 3, shortt4 = 4, shortt6 = 1,
        shortt7 = 2, shortt8 = 3, shortt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hd%*31d\n\n%hd%hd%hd%s", &shortt1,
                          &shortt2, &shortt3, &shortt4, endd1),
                   s21_sscanf(input_line_1, "%hd%*31d\n\n%hd%hd%hd%s", &shortt6,
                              &shortt7, &shortt8, &shortt9, endd2));
  ck_assert_int_eq(shortt1, shortt6);
  ck_assert_int_eq(shortt2, shortt7);
  ck_assert_int_eq(shortt3, shortt8);
  ck_assert_int_eq(shortt4, shortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_24) {
  char input_line_0[] =
      "-65534  11223344556677889900111222333444555  -5555  555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short shortt1 = 1, shortt2 = 2, shortt3 = 3, shortt4 = 4, shortt6 = 1,
        shortt7 = 2, shortt8 = 3, shortt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hd%*31d\n\n%hd%hd%hd%s", &shortt1,
                          &shortt2, &shortt3, &shortt4, endd1),
                   s21_sscanf(input_line_1, "%hd%*31d\n\n%hd%hd%hd%s", &shortt6,
                              &shortt7, &shortt8, &shortt9, endd2));
  ck_assert_int_eq(shortt1, shortt6);
  ck_assert_int_eq(shortt2, shortt7);
  ck_assert_int_eq(shortt3, shortt8);
  ck_assert_int_eq(shortt4, shortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_25) {
  char input_line_0[] =
      "32767  11223344556677889900111222333444555  -5555  555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short shortt1 = 1, shortt2 = 2, shortt3 = 3, shortt4 = 4, shortt6 = 1,
        shortt7 = 2, shortt8 = 3, shortt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hd%*31d\n\n%hd%hd%hd%s", &shortt1,
                          &shortt2, &shortt3, &shortt4, endd1),
                   s21_sscanf(input_line_1, "%hd%*31d\n\n%hd%hd%hd%s", &shortt6,
                              &shortt7, &shortt8, &shortt9, endd2));
  ck_assert_int_eq(shortt1, shortt6);
  ck_assert_int_eq(shortt2, shortt7);
  ck_assert_int_eq(shortt3, shortt8);
  ck_assert_int_eq(shortt4, shortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_26) {
  char input_line_0[] =
      "-32767  11223344556677889900111222333444555  -5555  555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short shortt1 = 1, shortt2 = 2, shortt3 = 3, shortt4 = 4, shortt6 = 1,
        shortt7 = 2, shortt8 = 3, shortt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hd%*31d\n\n%hd%hd%hd%s", &shortt1,
                          &shortt2, &shortt3, &shortt4, endd1),
                   s21_sscanf(input_line_1, "%hd%*31d\n\n%hd%hd%hd%s", &shortt6,
                              &shortt7, &shortt8, &shortt9, endd2));
  ck_assert_int_eq(shortt1, shortt6);
  ck_assert_int_eq(shortt2, shortt7);
  ck_assert_int_eq(shortt3, shortt8);
  ck_assert_int_eq(shortt4, shortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_27) {
  char input_line_0[] =
      "32770  11223344556677889900111222333444555  -5555  555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short shortt1 = 1, shortt2 = 2, shortt3 = 3, shortt4 = 4, shortt6 = 1,
        shortt7 = 2, shortt8 = 3, shortt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hd%*31d\n\n%hd%hd%hd%s", &shortt1,
                          &shortt2, &shortt3, &shortt4, endd1),
                   s21_sscanf(input_line_1, "%hd%*31d\n\n%hd%hd%hd%s", &shortt6,
                              &shortt7, &shortt8, &shortt9, endd2));
  ck_assert_int_eq(shortt1, shortt6);
  ck_assert_int_eq(shortt2, shortt7);
  ck_assert_int_eq(shortt3, shortt8);
  ck_assert_int_eq(shortt4, shortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_28) {
  char input_line_0[] =
      "65535   11223344556677889900111222333444555  -5555  555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short shortt1 = 1, shortt2 = 2, shortt3 = 3, shortt4 = 4, shortt6 = 1,
        shortt7 = 2, shortt8 = 3, shortt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hd%*31d\n\n%hd%hd%hd%s", &shortt1,
                          &shortt2, &shortt3, &shortt4, endd1),
                   s21_sscanf(input_line_1, "%hd%*31d\n\n%hd%hd%hd%s", &shortt6,
                              &shortt7, &shortt8, &shortt9, endd2));
  ck_assert_int_eq(shortt1, shortt6);
  ck_assert_int_eq(shortt2, shortt7);
  ck_assert_int_eq(shortt3, shortt8);
  ck_assert_int_eq(shortt4, shortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_29) {
  char input_line_0[] =
      "-65536   11223344556677889900111222333444555  -5555  555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short shortt1 = 1, shortt2 = 2, shortt3 = 3, shortt4 = 4, shortt6 = 1,
        shortt7 = 2, shortt8 = 3, shortt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hd%*31d\n\n%hd%hd%hd%s", &shortt1,
                          &shortt2, &shortt3, &shortt4, endd1),
                   s21_sscanf(input_line_1, "%hd%*31d\n\n%hd%hd%hd%s", &shortt6,
                              &shortt7, &shortt8, &shortt9, endd2));
  ck_assert_int_eq(shortt1, shortt6);
  ck_assert_int_eq(shortt2, shortt7);
  ck_assert_int_eq(shortt3, shortt8);
  ck_assert_int_eq(shortt4, shortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_10) {
  char input_line_0[] =
      "65536  11223344556677889900111222333444555  -5555  5555.444   end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short shortt1 = 1, shortt2 = 2, shortt3 = 3, shortt4 = 4, shortt6 = 1,
        shortt7 = 2, shortt8 = 3, shortt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hd%*31d\n\n%hd%hd%hd%s", &shortt1,
                          &shortt2, &shortt3, &shortt4, endd1),
                   s21_sscanf(input_line_1, "%hd%*31d\n\n%hd%hd%hd%s", &shortt6,
                              &shortt7, &shortt8, &shortt9, endd2));
  ck_assert_int_eq(shortt1, shortt6);
  ck_assert_int_eq(shortt2, shortt7);
  ck_assert_int_eq(shortt3, shortt8);
  ck_assert_int_eq(shortt4, shortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_11) {
  char input_line_0[] =
      "0  11223344556677889900111222333444555  -5555  5555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short shortt1 = 1, shortt2 = 2, shortt3 = 3, shortt4 = 4, shortt6 = 1,
        shortt7 = 2, shortt8 = 3, shortt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hd%*31d%hd%hd%hd%s", &shortt1,
                          &shortt2, &shortt3, &shortt4, endd1),
                   s21_sscanf(input_line_1, "%hd%*31d%hd%hd%hd%s", &shortt6,
                              &shortt7, &shortt8, &shortt9, endd2));
  ck_assert_int_eq(shortt1, shortt6);
  ck_assert_int_eq(shortt2, shortt7);
  ck_assert_int_eq(shortt3, shortt8);
  ck_assert_int_eq(shortt4, shortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_12) {
  char input_line_0[] =
      "  05.5  11223344556677889900111222333444555  -5555  5555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short shortt1 = 1, shortt2 = 2, shortt3 = 3, shortt4 = 4, shortt6 = 1,
        shortt7 = 2, shortt8 = 3, shortt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hd%*31d%hd\t\t%hd%hd%s", &shortt1,
                          &shortt2, &shortt3, &shortt4, endd1),
                   s21_sscanf(input_line_1, "%hd%*31d%hd\t\t%hd%hd%s", &shortt6,
                              &shortt7, &shortt8, &shortt9, endd2));
  ck_assert_int_eq(shortt1, shortt6);
  ck_assert_int_eq(shortt2, shortt7);
  ck_assert_int_eq(shortt3, shortt8);
  ck_assert_int_eq(shortt4, shortt9);
  ck_assert_str_eq(endd1, endd2);
}

START_TEST(test_sscanf_short_31) {
  char input_line_0[] =
      "5 -1000000000000000  11223344556677889900111222333444555  -5555  "
      "5555.444  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short shortt1 = 1, shortt2 = 2, shortt3 = 3, shortt4 = 4, shortt6 = 1,
        shortt7 = 2, shortt8 = 3, shortt9 = 4, shortt5 = 5, shortt10 = 5;
  ck_assert_int_eq(sscanf(input_line_0, "%hd%hd%*31d%hd%hd%hd%s", &shortt5,
                          &shortt1, &shortt2, &shortt3, &shortt4, endd1),
                   s21_sscanf(input_line_1, "%hd%hd%*31d%hd%hd%hd%s", &shortt10,
                              &shortt6, &shortt7, &shortt8, &shortt9, endd2));
  ck_assert_int_eq(shortt5, shortt10);
  ck_assert_int_eq(shortt1, shortt6);
  ck_assert_int_eq(shortt2, shortt7);
  ck_assert_int_eq(shortt3, shortt8);
  ck_assert_int_eq(shortt4, shortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_32) {
  char input_line_0[] =
      "100000000000000000  11223344556677889900111222333444555  -5555  "
      "5555.444  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short shortt1 = 1, shortt2 = 2, shortt3 = 3, shortt4 = 4, shortt6 = 1,
        shortt7 = 2, shortt8 = 3, shortt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hd%*31d%hd%hd%hd%s", &shortt1,
                          &shortt2, &shortt3, &shortt4, endd1),
                   s21_sscanf(input_line_1, "%hd%*31d%hd%hd%hd%s", &shortt6,
                              &shortt7, &shortt8, &shortt9, endd2));
  ck_assert_int_eq(shortt1, shortt6);
  ck_assert_int_eq(shortt2, shortt7);
  ck_assert_int_eq(shortt3, shortt8);
  ck_assert_int_eq(shortt4, shortt9);
  ck_assert_str_eq(endd1, endd2);
}

START_TEST(test_sscanf_short_16) {
  char input_line_0[] = "   922337203685 5555 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short shortt1 = 1, shortt2 = 2, shortt6 = 1, shortt7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%4hd%hd%s", &shortt1, &shortt2, endd1),
      s21_sscanf(input_line_1, "%4hd%hd%s", &shortt6, &shortt7, endd2));
  ck_assert_int_eq(shortt1, shortt6);
  ck_assert_int_eq(shortt2, shortt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_17) {
  char input_line_0[] = "   9223                    5555 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short shortt1 = 1, shortt2 = 2, shortt6 = 1, shortt7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%5hd%hd%s", &shortt1, &shortt2, endd1),
      s21_sscanf(input_line_1, "%5hd%hd%s", &shortt6, &shortt7, endd2));
  ck_assert_int_eq(shortt1, shortt6);
  ck_assert_int_eq(shortt2, shortt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_18) {
  char input_line_0[] = "   +923a567                    5555 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short shortt1 = 1, shortt2 = 2, shortt6 = 1, shortt7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%5hd%hd%s", &shortt1, &shortt2, endd1),
      s21_sscanf(input_line_1, "%5hd%hd%s", &shortt6, &shortt7, endd2));
  ck_assert_int_eq(shortt1, shortt6);
  ck_assert_int_eq(shortt2, shortt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_30) {
  char input_line_0[] = "   +923a567                    5555 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short shortt1 = 1, shortt2 = 2, shortt6 = 1, shortt7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%4hd\t\na%hd%s", &shortt1, &shortt2, endd1),
      s21_sscanf(input_line_1, "%4hd\t\na%hd%s", &shortt6, &shortt7, endd2));
  ck_assert_int_eq(shortt1, shortt6);
  ck_assert_int_eq(shortt2, shortt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_19) {
  char input_line_0[] = "   9223a567                    5555 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short shortt1 = 1, shortt2 = 2, shortt6 = 1, shortt7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%8hd%hd%s", &shortt1, &shortt2, endd1),
      s21_sscanf(input_line_1, "%8hd%hd%s", &shortt6, &shortt7, endd2));
  ck_assert_int_eq(shortt1, shortt6);
  ck_assert_int_eq(shortt2, shortt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_20) {
  char input_line_0[] = "  -.6                   -0.6 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short shortt1 = 1, shortt2 = 2, shortt6 = 1, shortt7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%5hd%hd%s", &shortt1, &shortt2, endd1),
      s21_sscanf(input_line_1, "%5hd%hd%s", &shortt6, &shortt7, endd2));
  ck_assert_int_eq(shortt1, shortt6);
  ck_assert_int_eq(shortt2, shortt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_21) {
  char input_line_0[] = "  .6                   -0.6 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short shortt1 = 1, shortt2 = 2, shortt6 = 1, shortt7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%5hd%hd%s", &shortt1, &shortt2, endd1),
      s21_sscanf(input_line_1, "%5hd%hd%s", &shortt6, &shortt7, endd2));
  ck_assert_int_eq(shortt1, shortt6);
  ck_assert_int_eq(shortt2, shortt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_22) {
  char input_line_0[] = "  -f                   -0.6 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short shortt1 = 1, shortt2 = 2, shortt6 = 1, shortt7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%5hd%hd%s", &shortt1, &shortt2, endd1),
      s21_sscanf(input_line_1, "%5hd%hd%s", &shortt6, &shortt7, endd2));
  ck_assert_int_eq(shortt1, shortt6);
  ck_assert_int_eq(shortt2, shortt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_23) {
  char input_line_0[] = "  -4294                  -4294967304 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short shortt1 = 1, shortt2 = 2, shortt6 = 1, shortt7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%6hd%6hd%s", &shortt1, &shortt2, endd1),
      s21_sscanf(input_line_1, "%6hd%6hd%s", &shortt6, &shortt7, endd2));
  ck_assert_int_eq(shortt1, shortt6);
  ck_assert_int_eq(shortt2, shortt7);
  ck_assert_str_eq(endd1, endd2);
}
// 9.5   //elevator
START_TEST(test_sscanf_unsigned_long_1) {
  char input_line_0[] =
      "1111155  11223344556677889900111222333444555  -555555  55545.444  end\0";
  char input_line_1[100] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned long ulongg1 = 1, ulongg2 = 2, ulongg3 = 3, ulongg4 = 4, ulongg6 = 1,
                ulongg7 = 2, ulongg8 = 3, ulongg9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%lu%lu%lu%lu%s", &ulongg1, &ulongg2,
                          &ulongg3, &ulongg4, endd1),
                   s21_sscanf(input_line_1, "%lu%lu%lu%lu%s", &ulongg6,
                              &ulongg7, &ulongg8, &ulongg9, endd2));
  ck_assert_uint_eq(ulongg1, ulongg6);
  ck_assert_int_eq(ulongg1, ulongg6);
  ck_assert_uint_eq(ulongg2, ulongg7);
  ck_assert_int_eq(ulongg2, ulongg7);
  ck_assert_uint_eq(ulongg3, ulongg8);
  ck_assert_int_eq(ulongg3, ulongg8);
  ck_assert_uint_eq(ulongg4, ulongg9);
  ck_assert_int_eq(ulongg4, ulongg9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_long_2) {
  char input_line_0[] =
      "1111155  11223344556677889900111222333444555  -555555  55545.444  end\0";
  char input_line_1[100] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned long ulongg1 = 1, ulongg2 = 2, ulongg3 = 3, ulongg4 = 4, ulongg6 = 1,
                ulongg7 = 2, ulongg8 = 3, ulongg9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%lu%%%lu%lu%lu%s", &ulongg1, &ulongg2,
                          &ulongg3, &ulongg4, endd1),
                   s21_sscanf(input_line_1, "%lu%%%lu%lu%lu%s", &ulongg6,
                              &ulongg7, &ulongg8, &ulongg9, endd2));
  ck_assert_uint_eq(ulongg1, ulongg6);
  ck_assert_int_eq(ulongg1, ulongg6);
  ck_assert_uint_eq(ulongg2, ulongg7);
  ck_assert_int_eq(ulongg2, ulongg7);
  ck_assert_uint_eq(ulongg3, ulongg8);
  ck_assert_int_eq(ulongg3, ulongg8);
  ck_assert_uint_eq(ulongg4, ulongg9);
  ck_assert_int_eq(ulongg4, ulongg9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_long_7) {
  char input_line_0[] =
      "1111155  %11223344556677889900111222333444555  -555555  55545.444  "
      "end\0";
  char input_line_1[100] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned long ulongg1 = 1, ulongg2 = 2, ulongg3 = 3, ulongg4 = 4, ulongg6 = 1,
                ulongg7 = 2, ulongg8 = 3, ulongg9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%lu%%%lu%lu%lu%s", &ulongg1, &ulongg2,
                          &ulongg3, &ulongg4, endd1),
                   s21_sscanf(input_line_1, "%lu%%%lu%lu%lu%s", &ulongg6,
                              &ulongg7, &ulongg8, &ulongg9, endd2));
  ck_assert_uint_eq(ulongg1, ulongg6);
  ck_assert_int_eq(ulongg1, ulongg6);
  ck_assert_uint_eq(ulongg2, ulongg7);
  ck_assert_int_eq(ulongg2, ulongg7);
  ck_assert_uint_eq(ulongg3, ulongg8);
  ck_assert_int_eq(ulongg3, ulongg8);
  ck_assert_uint_eq(ulongg4, ulongg9);
  ck_assert_int_eq(ulongg4, ulongg9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_long_3) {
  char input_line_0[] =
      "1111155  11223344556677889900111222333444555  -555555  55545.444  end\0";
  char input_line_1[100] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned long ulongg1 = 1, ulongg2 = 2, ulongg3 = 3, ulongg4 = 4, ulongg6 = 1,
                ulongg7 = 2, ulongg8 = 3, ulongg9 = 4, ulongg5 = 5,
                ulongg10 = 5;
  ck_assert_int_eq(sscanf(input_line_0, "%lu%7lu%lu%lu%lu%s", &ulongg1,
                          &ulongg2, &ulongg5, &ulongg3, &ulongg4, endd1),
                   s21_sscanf(input_line_1, "%lu%7lu%lu%lu%lu%s", &ulongg6,
                              &ulongg7, &ulongg10, &ulongg8, &ulongg9, endd2));
  ck_assert_uint_eq(ulongg1, ulongg6);
  ck_assert_int_eq(ulongg1, ulongg6);
  ck_assert_uint_eq(ulongg2, ulongg7);
  ck_assert_int_eq(ulongg2, ulongg7);
  ck_assert_uint_eq(ulongg3, ulongg8);
  ck_assert_int_eq(ulongg3, ulongg8);
  ck_assert_uint_eq(ulongg4, ulongg9);
  ck_assert_int_eq(ulongg4, ulongg9);
  ck_assert_uint_eq(ulongg5, ulongg10);
  ck_assert_int_eq(ulongg5, ulongg10);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_long_5) {
  char input_line_0[] =
      "1111155  11223344556677889900111222333444555  -555555  55545.444  end\0";
  char input_line_1[100] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned long ulongg1 = 1, ulongg2 = 2, ulongg3 = 3, ulongg6 = 1, ulongg7 = 2,
                ulongg8 = 3;
  ck_assert_int_eq(sscanf(input_line_0, "%lu%*u%lu%lu%s", &ulongg1, &ulongg2,
                          &ulongg3, endd1),
                   s21_sscanf(input_line_1, "%lu%*u%lu%lu%s", &ulongg6,
                              &ulongg7, &ulongg8, endd2));
  ck_assert_uint_eq(ulongg1, ulongg6);
  ck_assert_int_eq(ulongg1, ulongg6);
  ck_assert_uint_eq(ulongg2, ulongg7);
  ck_assert_int_eq(ulongg2, ulongg7);
  ck_assert_uint_eq(ulongg3, ulongg8);
  ck_assert_int_eq(ulongg3, ulongg8);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_long_8) {
  char input_line_0[] =
      "1111155  11223344556677889900111222333444555  -532456755555  55545.444  "
      "end\0";
  char input_line_1[100] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned long ulongg1 = 1, ulongg2 = 2, ulongg3 = 3, ulongg4 = 4, ulongg6 = 1,
                ulongg7 = 2, ulongg8 = 3, ulongg9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%lu%*10u%lu%lu%lu%s", &ulongg1,
                          &ulongg2, &ulongg3, &ulongg4, endd1),
                   s21_sscanf(input_line_1, "%lu%*10u%lu%lu%lu%s", &ulongg6,
                              &ulongg7, &ulongg8, &ulongg9, endd2));
  ck_assert_uint_eq(ulongg1, ulongg6);
  ck_assert_int_eq(ulongg1, ulongg6);
  ck_assert_uint_eq(ulongg2, ulongg7);
  ck_assert_int_eq(ulongg2, ulongg7);
  ck_assert_uint_eq(ulongg3, ulongg8);
  ck_assert_int_eq(ulongg3, ulongg8);
  ck_assert_uint_eq(ulongg4, ulongg9);
  ck_assert_int_eq(ulongg4, ulongg9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_long_12) {
  char input_line_0[] =
      "  05.5   11223344556677889900111222333444555  -532456755555  55545.444  "
      "end\0";
  char input_line_1[100] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned long ulongg1 = 1, ulongg2 = 2, ulongg3 = 3, ulongg4 = 4, ulongg6 = 1,
                ulongg7 = 2, ulongg8 = 3, ulongg9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%lu%*17u%lu\t\t%lu%lu%s", &ulongg1,
                          &ulongg2, &ulongg3, &ulongg4, endd1),
                   s21_sscanf(input_line_1, "%lu%*17u%lu\t\t%lu%lu%s", &ulongg6,
                              &ulongg7, &ulongg8, &ulongg9, endd2));
  ck_assert_uint_eq(ulongg1, ulongg6);
  ck_assert_int_eq(ulongg1, ulongg6);
  ck_assert_uint_eq(ulongg2, ulongg7);
  ck_assert_int_eq(ulongg2, ulongg7);
  ck_assert_uint_eq(ulongg3, ulongg8);
  ck_assert_int_eq(ulongg3, ulongg8);
  ck_assert_uint_eq(ulongg4, ulongg9);
  ck_assert_int_eq(ulongg4, ulongg9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_long_16) {
  char input_line_0[] = "   922337203685 55555 end\0";
  char input_line_1[100] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned long ulongg1 = 1, ulongg2 = 2, ulongg6 = 1, ulongg7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%4lu%lu%s", &ulongg1, &ulongg2, endd1),
      s21_sscanf(input_line_1, "%4lu%lu%s", &ulongg6, &ulongg7, endd2));
  ck_assert_uint_eq(ulongg1, ulongg6);
  ck_assert_int_eq(ulongg1, ulongg6);
  ck_assert_uint_eq(ulongg2, ulongg7);
  ck_assert_int_eq(ulongg2, ulongg7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_long_17) {
  char input_line_0[] = "   9223                    55555 end\0";
  char input_line_1[100] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned long ulongg1 = 1, ulongg2 = 2, ulongg6 = 1, ulongg7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%5lu%lu%s", &ulongg1, &ulongg2, endd1),
      s21_sscanf(input_line_1, "%5lu%lu%s", &ulongg6, &ulongg7, endd2));
  ck_assert_uint_eq(ulongg1, ulongg6);
  ck_assert_int_eq(ulongg1, ulongg6);
  ck_assert_uint_eq(ulongg2, ulongg7);
  ck_assert_int_eq(ulongg2, ulongg7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_long_18) {
  char input_line_0[] = "   +923a567                    55555 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned long ulongg1 = 1, ulongg2 = 2, ulongg6 = 1, ulongg7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%5lu%lu%s", &ulongg1, &ulongg2, endd1),
      s21_sscanf(input_line_1, "%5lu%lu%s", &ulongg6, &ulongg7, endd2));
  ck_assert_uint_eq(ulongg1, ulongg6);
  ck_assert_int_eq(ulongg1, ulongg6);
  ck_assert_uint_eq(ulongg2, ulongg7);
  ck_assert_int_eq(ulongg2, ulongg7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_long_30) {
  char input_line_0[] = "   +923a567                    55555 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned long ulongg1 = 1, ulongg2 = 2, ulongg6 = 1, ulongg7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%4lu\t\na%lu%s", &ulongg1, &ulongg2, endd1),
      s21_sscanf(input_line_1, "%4lu\t\na%lu%s", &ulongg6, &ulongg7, endd2));
  ck_assert_uint_eq(ulongg1, ulongg6);
  ck_assert_int_eq(ulongg1, ulongg6);
  ck_assert_uint_eq(ulongg2, ulongg7);
  ck_assert_int_eq(ulongg2, ulongg7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_long_19) {
  char input_line_0[] = "   9223a567                    55555 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned long ulongg1 = 1, ulongg2 = 2, ulongg6 = 1, ulongg7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%8lu%lu%s", &ulongg1, &ulongg2, endd1),
      s21_sscanf(input_line_1, "%8lu%lu%s", &ulongg6, &ulongg7, endd2));
  ck_assert_uint_eq(ulongg1, ulongg6);
  ck_assert_int_eq(ulongg1, ulongg6);
  ck_assert_uint_eq(ulongg2, ulongg7);
  ck_assert_int_eq(ulongg2, ulongg7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_long_20) {
  char input_line_0[] = "  -.6                   -0.6 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned long ulongg1 = 1, ulongg2 = 2, ulongg6 = 1, ulongg7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%5lu%lu%s", &ulongg1, &ulongg2, endd1),
      s21_sscanf(input_line_1, "%5lu%lu%s", &ulongg6, &ulongg7, endd2));
  ck_assert_uint_eq(ulongg1, ulongg6);
  ck_assert_int_eq(ulongg1, ulongg6);
  ck_assert_uint_eq(ulongg2, ulongg7);
  ck_assert_int_eq(ulongg2, ulongg7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_long_21) {
  char input_line_0[] = "  .6                   -0.6 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned long ulongg1 = 1, ulongg2 = 2, ulongg6 = 1, ulongg7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%5lu%lu%s", &ulongg1, &ulongg2, endd1),
      s21_sscanf(input_line_1, "%5lu%lu%s", &ulongg6, &ulongg7, endd2));
  ck_assert_uint_eq(ulongg1, ulongg6);
  ck_assert_int_eq(ulongg1, ulongg6);
  ck_assert_uint_eq(ulongg2, ulongg7);
  ck_assert_int_eq(ulongg2, ulongg7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_long_22) {
  char input_line_0[] = "  -f                   -0.6 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned long ulongg1 = 1, ulongg2 = 2, ulongg6 = 1, ulongg7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%5lu%lu%s", &ulongg1, &ulongg2, endd1),
      s21_sscanf(input_line_1, "%5lu%lu%s", &ulongg6, &ulongg7, endd2));
  ck_assert_uint_eq(ulongg1, ulongg6);
  ck_assert_int_eq(ulongg1, ulongg6);
  ck_assert_uint_eq(ulongg2, ulongg7);
  ck_assert_int_eq(ulongg2, ulongg7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_long_23) {
  char input_line_0[] = "  42945                  -4294967304 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned long ulongg1 = 1, ulongg2 = 2, ulongg6 = 1, ulongg7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%6lu%6lu%s", &ulongg1, &ulongg2, endd1),
      s21_sscanf(input_line_1, "%6lu%6lu%s", &ulongg6, &ulongg7, endd2));
  ck_assert_uint_eq(ulongg1, ulongg6);
  ck_assert_int_eq(ulongg1, ulongg6);
  ck_assert_uint_eq(ulongg2, ulongg7);
  ck_assert_int_eq(ulongg2, ulongg7);
  ck_assert_str_eq(endd1, endd2);
}
// 9.6   //elevator
/*
START_TEST(test_sscanf_long_1) {
  char input_line_0[] =
      "1111155  11223344556677889900111222333444555  -555555  55545.444  end\0";
  char input_line_1[100] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long longg1 = 1, longg2 = 2, longg3 = 3, longg4 = 4, longg6 = 1, longg7 = 2,
       longg8 = 3, longg9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%ld%ld%ld%ld%s", &longg1, &longg2,
                          &longg3, &longg4, endd1),
                   s21_sscanf(input_line_1, "%ld%ld%ld%ld%s", &longg6, &longg7,
                              &longg8, &longg9, endd2));
  ck_assert_int_eq(longg1, longg6);
  ck_assert_int_eq(longg2, longg7);
  ck_assert_int_eq(longg3, longg8);
  ck_assert_int_eq(longg4, longg9);
  ck_assert_str_eq(endd1, endd2);
}
*/
START_TEST(test_sscanf_long_2) {
  char input_line_0[] =
      "1111155  11223344556677889900111222333444555  -555555  55545.444  end\0";
  char input_line_1[100] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long longg1 = 1, longg2 = 2, longg3 = 3, longg4 = 4, longg6 = 1, longg7 = 2,
       longg8 = 3, longg9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%ld%%%ld%ld%ld%s", &longg1, &longg2,
                          &longg3, &longg4, endd1),
                   s21_sscanf(input_line_1, "%ld%%%ld%ld%ld%s", &longg6,
                              &longg7, &longg8, &longg9, endd2));
  ck_assert_int_eq(longg1, longg6);
  ck_assert_int_eq(longg2, longg7);
  ck_assert_int_eq(longg3, longg8);
  ck_assert_int_eq(longg4, longg9);
  ck_assert_str_eq(endd1, endd2);
}
/*
START_TEST(test_sscanf_long_7) {
  char input_line_0[] =
      "1111155  %11223344556677889900111222333444555  -555555  55545.444  "
      "end\0";
  char input_line_1[100] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long longg1 = 1, longg2 = 2, longg3 = 3, longg4 = 4, longg6 = 1, longg7 = 2,
       longg8 = 3, longg9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%ld%%%ld%ld%ld%s", &longg1, &longg2,
                          &longg3, &longg4, endd1),
                   s21_sscanf(input_line_1, "%ld%%%ld%ld%ld%s", &longg6,
                              &longg7, &longg8, &longg9, endd2));
  ck_assert_int_eq(longg1, longg6);
  ck_assert_int_eq(longg2, longg7);
  ck_assert_int_eq(longg3, longg8);
  ck_assert_int_eq(longg4, longg9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_3) {
  char input_line_0[] =
      "1111155  11223344556677889900111222333444555  -555555  55545.444  end\0";
  char input_line_1[100] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long longg1 = 1, longg2 = 2, longg3 = 3, longg4 = 4, longg6 = 1, longg7 = 2,
       longg8 = 3, longg9 = 4, longg5 = 5, longg10 = 5;
  ck_assert_int_eq(sscanf(input_line_0, "%ld%7ld%ld%ld%ld%s", &longg1, &longg2,
                          &longg5, &longg3, &longg4, endd1),
                   s21_sscanf(input_line_1, "%ld%7ld%ld%ld%ld%s", &longg6,
                              &longg7, &longg10, &longg8, &longg9, endd2));
  ck_assert_int_eq(longg1, longg6);
  ck_assert_int_eq(longg2, longg7);
  ck_assert_int_eq(longg3, longg8);
  ck_assert_int_eq(longg4, longg9);
  ck_assert_int_eq(longg5, longg10);
  ck_assert_str_eq(endd1, endd2);
}
*/
START_TEST(test_sscanf_long_5) {
  char input_line_0[] =
      "1111155  11223344556677889900111222333444555  -555555  55545.444  end\0";
  char input_line_1[100] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long longg1 = 1, longg2 = 2, longg3 = 3, longg6 = 1, longg7 = 2, longg8 = 3;
  ck_assert_int_eq(
      sscanf(input_line_0, "%ld%*d%ld%ld%s", &longg1, &longg2, &longg3, endd1),
      s21_sscanf(input_line_1, "%ld%*d%ld%ld%s", &longg6, &longg7, &longg8,
                 endd2));
  ck_assert_int_eq(longg1, longg6);
  ck_assert_int_eq(longg2, longg7);
  ck_assert_int_eq(longg3, longg8);
  ck_assert_str_eq(endd1, endd2);
}
/*
START_TEST(test_sscanf_long_6) {
  char input_line_0[] =
      "1111155  11223344556677889900111222333444555  -555555  55545.444  end\0";
  char input_line_1[100] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long longg1 = 1, longg2 = 2, longg3 = 3, longg4 = 4, longg6 = 1, longg7 = 2,
       longg8 = 3, longg9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%ld%*16d%ld%ld%ld%s", &longg1, &longg2,
                          &longg3, &longg4, endd1),
                   s21_sscanf(input_line_1, "%ld%*16d%ld%ld%ld%s", &longg6,
                              &longg7, &longg8, &longg9, endd2));
  ck_assert_int_eq(longg1, longg6);
  ck_assert_int_eq(longg2, longg7);
  ck_assert_int_eq(longg3, longg8);
  ck_assert_int_eq(longg4, longg9);
  ck_assert_str_eq(endd1, endd2);
}
*/
/*
START_TEST(test_sscanf_long_27) {
  char input_line_0[] =
      "9223372036854775999   11223344556677889900111222333444555  "
      "-532456755555  55545.444  end\0";
  char input_line_1[100] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long longg1 = 1, longg2 = 2, longg3 = 3, longg4 = 4, longg6 = 1, longg7 = 2,
       longg8 = 3, longg9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%ld%*17d\n\n%ld%ld%ld%s", &longg1,
                          &longg2, &longg3, &longg4, endd1),
                   s21_sscanf(input_line_1, "%ld%*17d\n\n%ld%ld%ld%s", &longg6,
                              &longg7, &longg8, &longg9, endd2));
  ck_assert_int_eq(longg1, longg6);
  ck_assert_int_eq(longg2, longg7);
  ck_assert_int_eq(longg3, longg8);
  ck_assert_int_eq(longg4, longg9);
  ck_assert_str_eq(endd1, endd2);
}
*/
/*
START_TEST(test_sscanf_long_29) {
  char input_line_0[] =
      "18446744073709551615   11223344556677889900111222333444585  "
      "-532456755555  55545.444  end\0";
  char input_line_1[100] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long longg1 = 1, longg2 = 2, longg3 = 3, longg4 = 4, longg6 = 1, longg7 = 2,
       longg8 = 3, longg9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%ld%*17d\n\n%ld%ld%ld%s", &longg1,
                          &longg2, &longg3, &longg4, endd1),
                   s21_sscanf(input_line_1, "%ld%*17d\n\n%ld%ld%ld%s", &longg6,
                              &longg7, &longg8, &longg9, endd2));
  ck_assert_int_eq(longg1, longg6);
  ck_assert_int_eq(longg2, longg7);
  ck_assert_int_eq(longg3, longg8);
  ck_assert_int_eq(longg4, longg9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_8) {
  char input_line_0[] =
      "1111155  11223344556677889900111222333444555  -532456755555  55545.444  "
      "end\0";
  char input_line_1[100] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long longg1 = 1, longg2 = 2, longg3 = 3, longg4 = 4, longg6 = 1, longg7 = 2,
       longg8 = 3, longg9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%ld%*10d%ld%ld%ld%s", &longg1, &longg2,
                          &longg3, &longg4, endd1),
                   s21_sscanf(input_line_1, "%ld%*10d%ld%ld%ld%s", &longg6,
                              &longg7, &longg8, &longg9, endd2));
  ck_assert_int_eq(longg1, longg6);
  ck_assert_int_eq(longg2, longg7);
  ck_assert_int_eq(longg3, longg8);
  ck_assert_int_eq(longg4, longg9);
  ck_assert_str_eq(endd1, endd2);
}
*/
START_TEST(test_sscanf_long_12) {
  char input_line_0[] =
      "  05.5   11223344556677889900111222333444555  -532456755555  55545.444  "
      "end\0";
  char input_line_1[100] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long longg1 = 1, longg2 = 2, longg3 = 3, longg4 = 4, longg6 = 1, longg7 = 2,
       longg8 = 3, longg9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%ld%*17d%ld\t\t%ld%ld%s", &longg1,
                          &longg2, &longg3, &longg4, endd1),
                   s21_sscanf(input_line_1, "%ld%*17d%ld\t\t%ld%ld%s", &longg6,
                              &longg7, &longg8, &longg9, endd2));
  ck_assert_int_eq(longg1, longg6);
  ck_assert_int_eq(longg2, longg7);
  ck_assert_int_eq(longg3, longg8);
  ck_assert_int_eq(longg4, longg9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_16) {
  char input_line_0[] = "   922337203685 55555 end\0";
  char input_line_1[100] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long longg1 = 1, longg2 = 2, longg6 = 1, longg7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%4ld%ld%s", &longg1, &longg2, endd1),
      s21_sscanf(input_line_1, "%4ld%ld%s", &longg6, &longg7, endd2));
  ck_assert_int_eq(longg1, longg6);
  ck_assert_int_eq(longg2, longg7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_17) {
  char input_line_0[] = "   9223                    55555 end\0";
  char input_line_1[100] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long longg1 = 1, longg2 = 2, longg6 = 1, longg7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%5ld%ld%s", &longg1, &longg2, endd1),
      s21_sscanf(input_line_1, "%5ld%ld%s", &longg6, &longg7, endd2));
  ck_assert_int_eq(longg1, longg6);
  ck_assert_int_eq(longg2, longg7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_18) {
  char input_line_0[] = "   +923a567                    55555 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long longg1 = 1, longg2 = 2, longg6 = 1, longg7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%5ld%ld%s", &longg1, &longg2, endd1),
      s21_sscanf(input_line_1, "%5ld%ld%s", &longg6, &longg7, endd2));
  ck_assert_int_eq(longg1, longg6);
  ck_assert_int_eq(longg2, longg7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_30) {
  char input_line_0[] = "   +923a567                    55555 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long longg1 = 1, longg2 = 2, longg6 = 1, longg7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%4ld\t\na%ld%s", &longg1, &longg2, endd1),
      s21_sscanf(input_line_1, "%4ld\t\na%ld%s", &longg6, &longg7, endd2));
  ck_assert_int_eq(longg1, longg6);
  ck_assert_int_eq(longg2, longg7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_19) {
  char input_line_0[] = "   9223a567                    55555 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long longg1 = 1, longg2 = 2, longg6 = 1, longg7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%8ld%ld%s", &longg1, &longg2, endd1),
      s21_sscanf(input_line_1, "%8ld%ld%s", &longg6, &longg7, endd2));
  ck_assert_int_eq(longg1, longg6);
  ck_assert_int_eq(longg2, longg7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_20) {
  char input_line_0[] = "  -.6                   -0.6 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long longg1 = 1, longg2 = 2, longg6 = 1, longg7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%5ld%ld%s", &longg1, &longg2, endd1),
      s21_sscanf(input_line_1, "%5ld%ld%s", &longg6, &longg7, endd2));
  ck_assert_int_eq(longg1, longg6);
  ck_assert_int_eq(longg2, longg7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_21) {
  char input_line_0[] = "  .6                   -0.6 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long longg1 = 1, longg2 = 2, longg6 = 1, longg7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%5ld%ld%s", &longg1, &longg2, endd1),
      s21_sscanf(input_line_1, "%5ld%ld%s", &longg6, &longg7, endd2));
  ck_assert_int_eq(longg1, longg6);
  ck_assert_int_eq(longg2, longg7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_22) {
  char input_line_0[] = "  -f                   -0.6 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long longg1 = 1, longg2 = 2, longg6 = 1, longg7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%5ld%ld%s", &longg1, &longg2, endd1),
      s21_sscanf(input_line_1, "%5ld%ld%s", &longg6, &longg7, endd2));
  ck_assert_int_eq(longg1, longg6);
  ck_assert_int_eq(longg2, longg7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_23) {
  char input_line_0[] = "  42945                  -4294967304 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long longg1 = 1, longg2 = 2, longg6 = 1, longg7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%6ld%6ld%s", &longg1, &longg2, endd1),
      s21_sscanf(input_line_1, "%6ld%6ld%s", &longg6, &longg7, endd2));
  ck_assert_int_eq(longg1, longg6);
  ck_assert_int_eq(longg2, longg7);
  ck_assert_str_eq(endd1, endd2);
}
// 9.7       //elevator
START_TEST(test_sscanf_unsigned_octal_1) {
  char input_line_0[] =
      "111111  1122334455667700111222333444555  -55555  5555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt3 = 3, uintt4 = 4, uintt6 = 1,
               uintt7 = 2, uintt8 = 3, uintt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%o%o%o%o%s", &uintt1, &uintt2, &uintt3,
                          &uintt4, endd1),
                   s21_sscanf(input_line_1, "%o%o%o%o%s", &uintt6, &uintt7,
                              &uintt8, &uintt9, endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_int_eq(uintt3, uintt8);
  ck_assert_uint_eq(uintt3, uintt8);
  ck_assert_int_eq(uintt4, uintt9);
  ck_assert_uint_eq(uintt4, uintt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_octal_18) {
  char input_line_0[] =
      "11119  1122334455667700111222333444555  -55555  5555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt3 = 3, uintt4 = 4, uintt6 = 1,
               uintt7 = 2, uintt8 = 3, uintt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%o%o%o%o%s", &uintt1, &uintt2, &uintt3,
                          &uintt4, endd1),
                   s21_sscanf(input_line_1, "%o%o%o%o%s", &uintt6, &uintt7,
                              &uintt8, &uintt9, endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_int_eq(uintt3, uintt8);
  ck_assert_uint_eq(uintt3, uintt8);
  ck_assert_int_eq(uintt4, uintt9);
  ck_assert_uint_eq(uintt4, uintt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_octal_19) {
  char input_line_0[] =
      "11181  1122334455667700111222333444555  -55555  5555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt3 = 3, uintt4 = 4, uintt6 = 1,
               uintt7 = 2, uintt8 = 3, uintt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%o%o%o%o%s", &uintt1, &uintt2, &uintt3,
                          &uintt4, endd1),
                   s21_sscanf(input_line_1, "%o%o%o%o%s", &uintt6, &uintt7,
                              &uintt8, &uintt9, endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_int_eq(uintt3, uintt8);
  ck_assert_uint_eq(uintt3, uintt8);
  ck_assert_int_eq(uintt4, uintt9);
  ck_assert_uint_eq(uintt4, uintt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_octal_2) {
  char input_line_0[] =
      "111111  1122334455667700111222333444555  -55555  5555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt3 = 3, uintt4 = 4, uintt6 = 1,
               uintt7 = 2, uintt8 = 3, uintt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%o%%%o%o%o%s", &uintt1, &uintt2,
                          &uintt3, &uintt4, endd1),
                   s21_sscanf(input_line_1, "%o%%%o%o%o%s", &uintt6, &uintt7,
                              &uintt8, &uintt9, endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_int_eq(uintt3, uintt8);
  ck_assert_uint_eq(uintt3, uintt8);
  ck_assert_int_eq(uintt4, uintt9);
  ck_assert_uint_eq(uintt4, uintt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_octal_20) {
  char input_line_0[] =
      "111111  %1122334455667700111222333444555  -55555  5555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt3 = 3, uintt4 = 4, uintt6 = 1,
               uintt7 = 2, uintt8 = 3, uintt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%o%%%o%o%o%s", &uintt1, &uintt2,
                          &uintt3, &uintt4, endd1),
                   s21_sscanf(input_line_1, "%o%%%o%o%o%s", &uintt6, &uintt7,
                              &uintt8, &uintt9, endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_int_eq(uintt3, uintt8);
  ck_assert_uint_eq(uintt3, uintt8);
  ck_assert_int_eq(uintt4, uintt9);
  ck_assert_uint_eq(uintt4, uintt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_octal_3) {
  char input_line_0[] =
      "111111  1122334455667700111222333444555  -55555  5555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt3 = 3, uintt4 = 4, uintt6 = 1,
               uintt7 = 2, uintt8 = 3, uintt9 = 4, uintt5 = 5, uintt10 = 5;
  ck_assert_int_eq(sscanf(input_line_0, "%o%7o%o%o%o%s", &uintt1, &uintt2,
                          &uintt5, &uintt3, &uintt4, endd1),
                   s21_sscanf(input_line_1, "%o%7o%o%o%o%s", &uintt6, &uintt7,
                              &uintt10, &uintt8, &uintt9, endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_int_eq(uintt3, uintt8);
  ck_assert_uint_eq(uintt3, uintt8);
  ck_assert_int_eq(uintt4, uintt9);
  ck_assert_uint_eq(uintt4, uintt9);
  ck_assert_int_eq(uintt5, uintt10);
  ck_assert_uint_eq(uintt5, uintt10);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_octal_5) {
  char input_line_0[] =
      "111111  1122334455667700111222333444555  -55555  5555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt3 = 3, uintt6 = 1, uintt7 = 2,
               uintt8 = 3;
  ck_assert_int_eq(
      sscanf(input_line_0, "%o%*o%o%o%s", &uintt1, &uintt2, &uintt3, endd1),
      s21_sscanf(input_line_1, "%o%*o%o%o%s", &uintt6, &uintt7, &uintt8,
                 endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_int_eq(uintt3, uintt8);
  ck_assert_uint_eq(uintt3, uintt8);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_octal_6) {
  char input_line_0[] =
      "111111  1122334455667700111222333444555  -55555  5555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt3 = 3, uintt4 = 4, uintt6 = 1,
               uintt7 = 2, uintt8 = 3, uintt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%o%*26o%o%o%o%s", &uintt1, &uintt2,
                          &uintt3, &uintt4, endd1),
                   s21_sscanf(input_line_1, "%o%*26o%o%o%o%s", &uintt6, &uintt7,
                              &uintt8, &uintt9, endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_int_eq(uintt3, uintt8);
  ck_assert_uint_eq(uintt3, uintt8);
  ck_assert_int_eq(uintt4, uintt9);
  ck_assert_uint_eq(uintt4, uintt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_octal_21) {
  char input_line_0[] =
      "111111  11223344556677001191222333444555  -55555  5555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt3 = 3, uintt4 = 4, uintt6 = 1,
               uintt7 = 2, uintt8 = 3, uintt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%o%*26o%o%o%o%s", &uintt1, &uintt2,
                          &uintt3, &uintt4, endd1),
                   s21_sscanf(input_line_1, "%o%*26o%o%o%o%s", &uintt6, &uintt7,
                              &uintt8, &uintt9, endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_int_eq(uintt3, uintt8);
  ck_assert_uint_eq(uintt3, uintt8);
  ck_assert_int_eq(uintt4, uintt9);
  ck_assert_uint_eq(uintt4, uintt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_octal_7) {
  char input_line_0[] =
      "17777777777  1122334455667700111222333444555  -55555  5555.444  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt3 = 3, uintt4 = 4, uintt6 = 1,
               uintt7 = 2, uintt8 = 3, uintt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%o%*26o%o%o%o%s", &uintt1, &uintt2,
                          &uintt3, &uintt4, endd1),
                   s21_sscanf(input_line_1, "%o%*26o%o%o%o%s", &uintt6, &uintt7,
                              &uintt8, &uintt9, endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_int_eq(uintt3, uintt8);
  ck_assert_uint_eq(uintt3, uintt8);
  ck_assert_int_eq(uintt4, uintt9);
  ck_assert_uint_eq(uintt4, uintt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_octal_8) {
  char input_line_0[] =
      "37777777777  1122334455667700111222333444555  -17777777777  5555.444  "
      "end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt3 = 3, uintt4 = 4, uintt6 = 1,
               uintt7 = 2, uintt8 = 3, uintt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%o%*26o%o%o%o%s", &uintt1, &uintt2,
                          &uintt3, &uintt4, endd1),
                   s21_sscanf(input_line_1, "%o%*26o%o%o%o%s", &uintt6, &uintt7,
                              &uintt8, &uintt9, endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_int_eq(uintt3, uintt8);
  ck_assert_uint_eq(uintt3, uintt8);
  ck_assert_int_eq(uintt4, uintt9);
  ck_assert_uint_eq(uintt4, uintt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_octal_9) {
  char input_line_0[] =
      "40000000000  1122334455667700111222333444555  -55555  5555.444  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt3 = 3, uintt4 = 4, uintt6 = 1,
               uintt7 = 2, uintt8 = 3, uintt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%o%*26o%o%o%o%s", &uintt1, &uintt2,
                          &uintt3, &uintt4, endd1),
                   s21_sscanf(input_line_1, "%o%*26o%o%o%o%s", &uintt6, &uintt7,
                              &uintt8, &uintt9, endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_int_eq(uintt3, uintt8);
  ck_assert_uint_eq(uintt3, uintt8);
  ck_assert_int_eq(uintt4, uintt9);
  ck_assert_uint_eq(uintt4, uintt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_octal_10) {
  char input_line_0[] =
      "-37777777777  11223344556677900111222333444555  -55555  5555.444  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt3 = 3, uintt4 = 4, uintt6 = 1,
               uintt7 = 2, uintt8 = 3, uintt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%o%*26o%o%o%o%s", &uintt1, &uintt2,
                          &uintt3, &uintt4, endd1),
                   s21_sscanf(input_line_1, "%o%*26o%o%o%o%s", &uintt6, &uintt7,
                              &uintt8, &uintt9, endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_int_eq(uintt3, uintt8);
  ck_assert_uint_eq(uintt3, uintt8);
  ck_assert_int_eq(uintt4, uintt9);
  ck_assert_uint_eq(uintt4, uintt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_octal_11) {
  char input_line_0[] =
      "-40000000001  1122334455667700111222333444555  -55555  5555.444  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt3 = 3, uintt4 = 4, uintt6 = 1,
               uintt7 = 2, uintt8 = 3, uintt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%o%*26o%o%o%o%s", &uintt1, &uintt2,
                          &uintt3, &uintt4, endd1),
                   s21_sscanf(input_line_1, "%o%*26o%o%o%o%s", &uintt6, &uintt7,
                              &uintt8, &uintt9, endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_int_eq(uintt3, uintt8);
  ck_assert_uint_eq(uintt3, uintt8);
  ck_assert_int_eq(uintt4, uintt9);
  ck_assert_uint_eq(uintt4, uintt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_octal_12) {
  char input_line_0[] =
      "   9223372036854774  11223344556677889900111222333444555  -55555  "
      "5555.444  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt3 = 3, uintt4 = 4, uintt6 = 1,
               uintt7 = 2, uintt8 = 3, uintt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%o%*26o%o%o%o%s", &uintt1, &uintt2,
                          &uintt3, &uintt4, endd1),
                   s21_sscanf(input_line_1, "%o%*26o%o%o%o%s", &uintt6, &uintt7,
                              &uintt8, &uintt9, endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_int_eq(uintt3, uintt8);
  ck_assert_uint_eq(uintt3, uintt8);
  ck_assert_int_eq(uintt4, uintt9);
  ck_assert_uint_eq(uintt4, uintt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_octal_13) {
  char input_line_0[] = "   15327745152745 55555 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt7 = 2, uintt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%5o%o%s", &uintt1, &uintt2, endd1),
      s21_sscanf(input_line_1, "%5o%o%s", &uintt6, &uintt7, endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_octal_14) {
  char input_line_0[] = "   72233                    55555 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt7 = 2, uintt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%8o%o%s", &uintt1, &uintt2, endd1),
      s21_sscanf(input_line_1, "%8o%o%s", &uintt6, &uintt7, endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_octal_15) {
  char input_line_0[] = "   +72233a567                    55555 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt7 = 2, uintt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%8o%o%s", &uintt1, &uintt2, endd1),
      s21_sscanf(input_line_1, "%8o%o%s", &uintt6, &uintt7, endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_octal_16) {
  char input_line_0[] = "   72233a567                    55555 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt7 = 2, uintt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%8o%o%s", &uintt1, &uintt2, endd1),
      s21_sscanf(input_line_1, "%8o%o%s", &uintt6, &uintt7, endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_str_eq(endd1, endd2);
}
// 9.8       //elevator
START_TEST(test_sscanf_unsigned_short_octal_1) {
  char input_line_0[] =
      "11111  1122334455667700111222333444555  -5555  555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt3 = 3, ushortt4 = 4,
                 ushortt6 = 1, ushortt7 = 2, ushortt8 = 3, ushortt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%ho%ho%ho%ho%s", &ushortt1, &ushortt2,
                          &ushortt3, &ushortt4, endd1),
                   s21_sscanf(input_line_1, "%ho%ho%ho%ho%s", &ushortt6,
                              &ushortt7, &ushortt8, &ushortt9, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_uint_eq(ushortt3, ushortt8);
  ck_assert_int_eq(ushortt3, ushortt8);
  ck_assert_uint_eq(ushortt4, ushortt9);
  ck_assert_int_eq(ushortt4, ushortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_octal_2) {
  char input_line_0[] =
      "11111  1122334455667700111222333444555  -5555  555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt3 = 3, ushortt4 = 4,
                 ushortt6 = 1, ushortt7 = 2, ushortt8 = 3, ushortt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%ho%%%ho%ho%ho%s", &ushortt1,
                          &ushortt2, &ushortt3, &ushortt4, endd1),
                   s21_sscanf(input_line_1, "%ho%%%ho%ho%ho%s", &ushortt6,
                              &ushortt7, &ushortt8, &ushortt9, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_uint_eq(ushortt3, ushortt8);
  ck_assert_int_eq(ushortt3, ushortt8);
  ck_assert_uint_eq(ushortt4, ushortt9);
  ck_assert_int_eq(ushortt4, ushortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_octal_3) {
  char input_line_0[] =
      "11111  %\n\n1122334455667700111222333444555  -5555  555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt3 = 3, ushortt4 = 4,
                 ushortt6 = 1, ushortt7 = 2, ushortt8 = 3, ushortt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%ho%%%ho%ho%ho%s", &ushortt1,
                          &ushortt2, &ushortt3, &ushortt4, endd1),
                   s21_sscanf(input_line_1, "%ho%%%ho%ho%ho%s", &ushortt6,
                              &ushortt7, &ushortt8, &ushortt9, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_uint_eq(ushortt3, ushortt8);
  ck_assert_int_eq(ushortt3, ushortt8);
  ck_assert_uint_eq(ushortt4, ushortt9);
  ck_assert_int_eq(ushortt4, ushortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_octal_4) {
  char input_line_0[] =
      "11111  1122334455667700111222333444555  -5555  555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt3 = 3, ushortt4 = 4,
                 ushortt6 = 1, ushortt7 = 2, ushortt8 = 3, ushortt9 = 4,
                 ushortt5 = 5, ushortt10 = 5;
  ck_assert_int_eq(
      sscanf(input_line_0, "%ho%4ho%ho%ho%ho%s", &ushortt1, &ushortt2,
             &ushortt5, &ushortt3, &ushortt4, endd1),
      s21_sscanf(input_line_1, "%ho%4ho%ho%ho%ho%s", &ushortt6, &ushortt7,
                 &ushortt10, &ushortt8, &ushortt9, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_uint_eq(ushortt3, ushortt8);
  ck_assert_int_eq(ushortt3, ushortt8);
  ck_assert_uint_eq(ushortt4, ushortt9);
  ck_assert_int_eq(ushortt4, ushortt9);
  ck_assert_uint_eq(ushortt5, ushortt10);
  ck_assert_int_eq(ushortt5, ushortt10);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_octal_5) {
  char input_line_0[] =
      "11111  1122334455667700111222333444555  -5555  555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt3 = 3, ushortt6 = 1,
                 ushortt7 = 2, ushortt8 = 3;
  ck_assert_int_eq(sscanf(input_line_0, "%ho%*o%ho%ho%s", &ushortt1, &ushortt2,
                          &ushortt3, endd1),
                   s21_sscanf(input_line_1, "%ho%*o%ho%ho%s", &ushortt6,
                              &ushortt7, &ushortt8, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_uint_eq(ushortt3, ushortt8);
  ck_assert_int_eq(ushortt3, ushortt8);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_octal_6) {
  char input_line_0[] =
      "11111  1122334455667700111222333444555  -5555  555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt3 = 3, ushortt4 = 4,
                 ushortt6 = 1, ushortt7 = 2, ushortt8 = 3, ushortt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%ho%*26o%ho%ho%ho%s", &ushortt1,
                          &ushortt2, &ushortt3, &ushortt4, endd1),
                   s21_sscanf(input_line_1, "%ho%*26o%ho%ho%ho%s", &ushortt6,
                              &ushortt7, &ushortt8, &ushortt9, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_uint_eq(ushortt3, ushortt8);
  ck_assert_int_eq(ushortt3, ushortt8);
  ck_assert_uint_eq(ushortt4, ushortt9);
  ck_assert_int_eq(ushortt4, ushortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_octal_7) {
  char input_line_0[] =
      "11111  1122334455667700111222333444555  -5555  555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt3 = 3, ushortt4 = 4,
                 ushortt6 = 1, ushortt7 = 2, ushortt8 = 3, ushortt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%ho%*24o%ho%ho%ho%s", &ushortt1,
                          &ushortt2, &ushortt3, &ushortt4, endd1),
                   s21_sscanf(input_line_1, "%ho%*24o%ho%ho%ho%s", &ushortt6,
                              &ushortt7, &ushortt8, &ushortt9, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_uint_eq(ushortt3, ushortt8);
  ck_assert_int_eq(ushortt3, ushortt8);
  ck_assert_uint_eq(ushortt4, ushortt9);
  ck_assert_int_eq(ushortt4, ushortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_octal_8) {
  char input_line_0[] =
      "77777  1122334455667700111222333444555  -5555  555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt3 = 3, ushortt4 = 4,
                 ushortt6 = 1, ushortt7 = 2, ushortt8 = 3, ushortt9 = 4;
  ck_assert_int_eq(
      sscanf(input_line_0, "%ho%*31o\n\n%ho%ho%ho%s", &ushortt1, &ushortt2,
             &ushortt3, &ushortt4, endd1),
      s21_sscanf(input_line_1, "%ho%*31o\n\n%ho%ho%ho%s", &ushortt6, &ushortt7,
                 &ushortt8, &ushortt9, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_uint_eq(ushortt3, ushortt8);
  ck_assert_int_eq(ushortt3, ushortt8);
  ck_assert_uint_eq(ushortt4, ushortt9);
  ck_assert_int_eq(ushortt4, ushortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_octal_20) {
  char input_line_0[] =
      "177777  1122334455667700111222333444555  -5555  555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt3 = 3, ushortt4 = 4,
                 ushortt6 = 1, ushortt7 = 2, ushortt8 = 3, ushortt9 = 4;
  ck_assert_int_eq(
      sscanf(input_line_0, "%ho%*31o\n\n%ho%ho%ho%s", &ushortt1, &ushortt2,
             &ushortt3, &ushortt4, endd1),
      s21_sscanf(input_line_1, "%ho%*31o\n\n%ho%ho%ho%s", &ushortt6, &ushortt7,
                 &ushortt8, &ushortt9, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_uint_eq(ushortt3, ushortt8);
  ck_assert_int_eq(ushortt3, ushortt8);
  ck_assert_uint_eq(ushortt4, ushortt9);
  ck_assert_int_eq(ushortt4, ushortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_octal_32) {
  char input_line_0[] =
      "200000  1122334455667700111222333444555  -5555  555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt3 = 3, ushortt4 = 4,
                 ushortt6 = 1, ushortt7 = 2, ushortt8 = 3, ushortt9 = 4;
  ck_assert_int_eq(
      sscanf(input_line_0, "%ho%*31o\n\n%ho%ho%ho%s", &ushortt1, &ushortt2,
             &ushortt3, &ushortt4, endd1),
      s21_sscanf(input_line_1, "%ho%*31o\n\n%ho%ho%ho%s", &ushortt6, &ushortt7,
                 &ushortt8, &ushortt9, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_uint_eq(ushortt3, ushortt8);
  ck_assert_int_eq(ushortt3, ushortt8);
  ck_assert_uint_eq(ushortt4, ushortt9);
  ck_assert_int_eq(ushortt4, ushortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_octal_9) {
  char input_line_0[] =
      "-77777 1122334455667700111222333444555  -5555  555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt3 = 3, ushortt4 = 4,
                 ushortt6 = 1, ushortt7 = 2, ushortt8 = 3, ushortt9 = 4;
  ck_assert_int_eq(
      sscanf(input_line_0, "%ho%*26o\n\n%ho%ho%ho%s", &ushortt1, &ushortt2,
             &ushortt3, &ushortt4, endd1),
      s21_sscanf(input_line_1, "%ho%*26o\n\n%ho%ho%ho%s", &ushortt6, &ushortt7,
                 &ushortt8, &ushortt9, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_uint_eq(ushortt3, ushortt8);
  ck_assert_int_eq(ushortt3, ushortt8);
  ck_assert_uint_eq(ushortt4, ushortt9);
  ck_assert_int_eq(ushortt4, ushortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_octal_10) {
  char input_line_0[] =
      "100000  1122334455667700111222333444555  -5555  555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt3 = 3, ushortt4 = 4,
                 ushortt6 = 1, ushortt7 = 2, ushortt8 = 3, ushortt9 = 4;
  ck_assert_int_eq(
      sscanf(input_line_0, "%ho%*26o\n\n%ho%ho%ho%s", &ushortt1, &ushortt2,
             &ushortt3, &ushortt4, endd1),
      s21_sscanf(input_line_1, "%ho%*26o\n\n%ho%ho%ho%s", &ushortt6, &ushortt7,
                 &ushortt8, &ushortt9, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_uint_eq(ushortt3, ushortt8);
  ck_assert_int_eq(ushortt3, ushortt8);
  ck_assert_uint_eq(ushortt4, ushortt9);
  ck_assert_int_eq(ushortt4, ushortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_octal_11) {
  char input_line_0[] =
      "-100000  1122334455667700111222333444555  -5555  555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt3 = 3, ushortt4 = 4,
                 ushortt6 = 1, ushortt7 = 2, ushortt8 = 3, ushortt9 = 4;
  ck_assert_int_eq(
      sscanf(input_line_0, "%ho%*26o\n\n%ho%ho%ho%s", &ushortt1, &ushortt2,
             &ushortt3, &ushortt4, endd1),
      s21_sscanf(input_line_1, "%ho%*26o\n\n%ho%ho%ho%s", &ushortt6, &ushortt7,
                 &ushortt8, &ushortt9, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_uint_eq(ushortt3, ushortt8);
  ck_assert_int_eq(ushortt3, ushortt8);
  ck_assert_uint_eq(ushortt4, ushortt9);
  ck_assert_int_eq(ushortt4, ushortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_octal_14) {
  char input_line_0[] =
      "-65536   1122334455667700111222333444555  -5555  555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt3 = 3, ushortt4 = 4,
                 ushortt6 = 1, ushortt7 = 2, ushortt8 = 3, ushortt9 = 4;
  ck_assert_int_eq(
      sscanf(input_line_0, "%ho%*26o\n\n%ho%ho%ho%s", &ushortt1, &ushortt2,
             &ushortt3, &ushortt4, endd1),
      s21_sscanf(input_line_1, "%ho%*26o\n\n%ho%ho%ho%s", &ushortt6, &ushortt7,
                 &ushortt8, &ushortt9, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_uint_eq(ushortt3, ushortt8);
  ck_assert_int_eq(ushortt3, ushortt8);
  ck_assert_uint_eq(ushortt4, ushortt9);
  ck_assert_int_eq(ushortt4, ushortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_octal_15) {
  char input_line_0[] =
      "65593  1122334455667700111222333444555  -55555  5555.444   end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt3 = 3, ushortt4 = 4,
                 ushortt6 = 1, ushortt7 = 2, ushortt8 = 3, ushortt9 = 4;
  ck_assert_int_eq(
      sscanf(input_line_0, "%ho%*26o\n\n%ho%ho%ho%s", &ushortt1, &ushortt2,
             &ushortt3, &ushortt4, endd1),
      s21_sscanf(input_line_1, "%ho%*26o\n\n%ho%ho%ho%s", &ushortt6, &ushortt7,
                 &ushortt8, &ushortt9, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_uint_eq(ushortt3, ushortt8);
  ck_assert_int_eq(ushortt3, ushortt8);
  ck_assert_uint_eq(ushortt4, ushortt9);
  ck_assert_int_eq(ushortt4, ushortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_octal_16) {
  char input_line_0[] =
      "0  1122334455667700111222333444555  -55555  5555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt3 = 3, ushortt4 = 4,
                 ushortt6 = 1, ushortt7 = 2, ushortt8 = 3, ushortt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%ho%*26o%ho%ho%ho%s", &ushortt1,
                          &ushortt2, &ushortt3, &ushortt4, endd1),
                   s21_sscanf(input_line_1, "%ho%*26o%ho%ho%ho%s", &ushortt6,
                              &ushortt7, &ushortt8, &ushortt9, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_uint_eq(ushortt3, ushortt8);
  ck_assert_int_eq(ushortt3, ushortt8);
  ck_assert_uint_eq(ushortt4, ushortt9);
  ck_assert_int_eq(ushortt4, ushortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_octal_17) {
  char input_line_0[] =
      "  05.5  1122334455667700111222333444555  -55555  5555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt3 = 3, ushortt4 = 4,
                 ushortt6 = 1, ushortt7 = 2, ushortt8 = 3, ushortt9 = 4;
  ck_assert_int_eq(
      sscanf(input_line_0, "%ho%*26o%ho\t\t%ho%ho%s", &ushortt1, &ushortt2,
             &ushortt3, &ushortt4, endd1),
      s21_sscanf(input_line_1, "%ho%*26o%ho\t\t%ho%ho%s", &ushortt6, &ushortt7,
                 &ushortt8, &ushortt9, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_uint_eq(ushortt3, ushortt8);
  ck_assert_int_eq(ushortt3, ushortt8);
  ck_assert_uint_eq(ushortt4, ushortt9);
  ck_assert_int_eq(ushortt4, ushortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_octal_18) {
  char input_line_0[] =
      "9  1122334455667700111222333444555  -55555  5555.444  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt3 = 3, ushortt4 = 4,
                 ushortt6 = 1, ushortt7 = 2, ushortt8 = 3, ushortt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%ho%*26o%ho%ho%ho%s", &ushortt1,
                          &ushortt2, &ushortt3, &ushortt4, endd1),
                   s21_sscanf(input_line_1, "%ho%*26o%ho%ho%ho%s", &ushortt6,
                              &ushortt7, &ushortt8, &ushortt9, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_uint_eq(ushortt3, ushortt8);
  ck_assert_int_eq(ushortt3, ushortt8);
  ck_assert_uint_eq(ushortt4, ushortt9);
  ck_assert_int_eq(ushortt4, ushortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_octal_19) {
  char input_line_0[] =
      "5 -77778  1122334455667700111222333444555  -55555  5555.444  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt3 = 3, ushortt4 = 4,
                 ushortt6 = 1, ushortt7 = 2, ushortt8 = 3, ushortt9 = 4,
                 ushortt5 = 5, ushortt10 = 5;
  ck_assert_int_eq(
      sscanf(input_line_0, "%ho%ho%*26o%ho%ho%ho%s", &ushortt5, &ushortt1,
             &ushortt2, &ushortt3, &ushortt4, endd1),
      s21_sscanf(input_line_1, "%ho%ho%*26o%ho%ho%ho%s", &ushortt10, &ushortt6,
                 &ushortt7, &ushortt8, &ushortt9, endd2));
  ck_assert_uint_eq(ushortt5, ushortt10);
  ck_assert_int_eq(ushortt5, ushortt10);
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_uint_eq(ushortt3, ushortt8);
  ck_assert_int_eq(ushortt3, ushortt8);
  ck_assert_uint_eq(ushortt4, ushortt9);
  ck_assert_int_eq(ushortt4, ushortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_octal_21) {
  char input_line_0[] =
      "5 -1000000000000000  1122334455667700111222333444555  -55555  5555.444  "
      "end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt3 = 3, ushortt4 = 4,
                 ushortt6 = 1, ushortt7 = 2, ushortt8 = 3, ushortt9 = 4,
                 ushortt5 = 5, ushortt10 = 5;
  ck_assert_int_eq(
      sscanf(input_line_0, "%ho%ho%*26o%ho%ho%ho%s", &ushortt5, &ushortt1,
             &ushortt2, &ushortt3, &ushortt4, endd1),
      s21_sscanf(input_line_1, "%ho%ho%*26o%ho%ho%ho%s", &ushortt10, &ushortt6,
                 &ushortt7, &ushortt8, &ushortt9, endd2));
  ck_assert_uint_eq(ushortt5, ushortt10);
  ck_assert_int_eq(ushortt5, ushortt10);
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_uint_eq(ushortt3, ushortt8);
  ck_assert_int_eq(ushortt3, ushortt8);
  ck_assert_uint_eq(ushortt4, ushortt9);
  ck_assert_int_eq(ushortt4, ushortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_octal_23) {
  char input_line_0[] = "   722337203685 55555 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt6 = 1, ushortt7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%4ho%ho%s", &ushortt1, &ushortt2, endd1),
      s21_sscanf(input_line_1, "%4ho%ho%s", &ushortt6, &ushortt7, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_octal_24) {
  char input_line_0[] = "   9223                    55555 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt6 = 1, ushortt7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%5ho%ho%s", &ushortt1, &ushortt2, endd1),
      s21_sscanf(input_line_1, "%5ho%ho%s", &ushortt6, &ushortt7, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_octal_25) {
  char input_line_0[] = "   +923a567                    55555 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt6 = 1, ushortt7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%5ho%ho%s", &ushortt1, &ushortt2, endd1),
      s21_sscanf(input_line_1, "%5ho%ho%s", &ushortt6, &ushortt7, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_octal_26) {
  char input_line_0[] = "   +923a567                    55555 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt6 = 1, ushortt7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%4ho\t\na%ho%s", &ushortt1, &ushortt2, endd1),
      s21_sscanf(input_line_1, "%4ho\t\na%ho%s", &ushortt6, &ushortt7, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_octal_27) {
  char input_line_0[] = "   9223a567                    55555 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt6 = 1, ushortt7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%8ho%ho%s", &ushortt1, &ushortt2, endd1),
      s21_sscanf(input_line_1, "%8ho%ho%s", &ushortt6, &ushortt7, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_octal_22) {
  char input_line_0[] = "   -9223a567                    55555 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt6 = 1, ushortt7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%5ho%ho%s", &ushortt1, &ushortt2, endd1),
      s21_sscanf(input_line_1, "%5ho%ho%s", &ushortt6, &ushortt7, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_octal_28) {
  char input_line_0[] = "  -.6                   -0.6 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt6 = 1, ushortt7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%5ho%ho%s", &ushortt1, &ushortt2, endd1),
      s21_sscanf(input_line_1, "%5ho%ho%s", &ushortt6, &ushortt7, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_octal_29) {
  char input_line_0[] = "  .6                   -0.6 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt6 = 1, ushortt7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%5ho%ho%s", &ushortt1, &ushortt2, endd1),
      s21_sscanf(input_line_1, "%5ho%ho%s", &ushortt6, &ushortt7, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_octal_30) {
  char input_line_0[] = "  -f                   -0.6 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt6 = 1, ushortt7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%5ho%ho%s", &ushortt1, &ushortt2, endd1),
      s21_sscanf(input_line_1, "%5ho%ho%s", &ushortt6, &ushortt7, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_short_octal_31) {
  char input_line_0[] = "  42945                  -4294967304 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt6 = 1, ushortt7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%6ho%6ho%s", &ushortt1, &ushortt2, endd1),
      s21_sscanf(input_line_1, "%6ho%6ho%s", &ushortt6, &ushortt7, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_str_eq(endd1, endd2);
}
// 9.9       //elevator
START_TEST(test_sscanf_unsigned_long_octal_1) {
  char input_line_0[] =
      "1111155  11223344556677000111222333444555  -555555  55545.444  end\0";
  char input_line_1[100] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned long ulongg1 = 1, ulongg2 = 2, ulongg3 = 3, ulongg4 = 4, ulongg6 = 1,
                ulongg7 = 2, ulongg8 = 3, ulongg9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%lo%lo%lo%lo%s", &ulongg1, &ulongg2,
                          &ulongg3, &ulongg4, endd1),
                   s21_sscanf(input_line_1, "%lo%lo%lo%lo%s", &ulongg6,
                              &ulongg7, &ulongg8, &ulongg9, endd2));
  ck_assert_uint_eq(ulongg1, ulongg6);
  ck_assert_int_eq(ulongg1, ulongg6);
  ck_assert_uint_eq(ulongg2, ulongg7);
  ck_assert_int_eq(ulongg2, ulongg7);
  ck_assert_uint_eq(ulongg3, ulongg8);
  ck_assert_int_eq(ulongg3, ulongg8);
  ck_assert_uint_eq(ulongg4, ulongg9);
  ck_assert_int_eq(ulongg4, ulongg9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_long_octal_2) {
  char input_line_0[] =
      "1111155  11223344556677000111222333444555  -555555  55545.444  end\0";
  char input_line_1[100] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned long ulongg1 = 1, ulongg2 = 2, ulongg3 = 3, ulongg4 = 4, ulongg6 = 1,
                ulongg7 = 2, ulongg8 = 3, ulongg9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%lo%%%lo%lo%lo%s", &ulongg1, &ulongg2,
                          &ulongg3, &ulongg4, endd1),
                   s21_sscanf(input_line_1, "%lo%%%lo%lo%lo%s", &ulongg6,
                              &ulongg7, &ulongg8, &ulongg9, endd2));
  ck_assert_uint_eq(ulongg1, ulongg6);
  ck_assert_int_eq(ulongg1, ulongg6);
  ck_assert_uint_eq(ulongg2, ulongg7);
  ck_assert_int_eq(ulongg2, ulongg7);
  ck_assert_uint_eq(ulongg3, ulongg8);
  ck_assert_int_eq(ulongg3, ulongg8);
  ck_assert_uint_eq(ulongg4, ulongg9);
  ck_assert_int_eq(ulongg4, ulongg9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_long_octal_3) {
  char input_line_0[] =
      "1111155  %11223344556677000111222333444555  -555555  55545.444  end\0";
  char input_line_1[100] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned long ulongg1 = 1, ulongg2 = 2, ulongg3 = 3, ulongg4 = 4, ulongg6 = 1,
                ulongg7 = 2, ulongg8 = 3, ulongg9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%lo%%%lo%lo%lo%s", &ulongg1, &ulongg2,
                          &ulongg3, &ulongg4, endd1),
                   s21_sscanf(input_line_1, "%lo%%%lo%lo%lo%s", &ulongg6,
                              &ulongg7, &ulongg8, &ulongg9, endd2));
  ck_assert_uint_eq(ulongg1, ulongg6);
  ck_assert_int_eq(ulongg1, ulongg6);
  ck_assert_uint_eq(ulongg2, ulongg7);
  ck_assert_int_eq(ulongg2, ulongg7);
  ck_assert_uint_eq(ulongg3, ulongg8);
  ck_assert_int_eq(ulongg3, ulongg8);
  ck_assert_uint_eq(ulongg4, ulongg9);
  ck_assert_int_eq(ulongg4, ulongg9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_long_octal_4) {
  char input_line_0[] =
      "1111155  11223344556677000111222333444555  -555555  55545.444  end\0";
  char input_line_1[100] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned long ulongg1 = 1, ulongg2 = 2, ulongg3 = 3, ulongg4 = 4, ulongg6 = 1,
                ulongg7 = 2, ulongg8 = 3, ulongg9 = 4, ulongg5 = 5,
                ulongg10 = 5;
  ck_assert_int_eq(sscanf(input_line_0, "%lo%7lo%lo%lo%lo%s", &ulongg1,
                          &ulongg2, &ulongg5, &ulongg3, &ulongg4, endd1),
                   s21_sscanf(input_line_1, "%lo%7lo%lo%lo%lo%s", &ulongg6,
                              &ulongg7, &ulongg10, &ulongg8, &ulongg9, endd2));
  ck_assert_uint_eq(ulongg1, ulongg6);
  ck_assert_int_eq(ulongg1, ulongg6);
  ck_assert_uint_eq(ulongg2, ulongg7);
  ck_assert_int_eq(ulongg2, ulongg7);
  ck_assert_uint_eq(ulongg3, ulongg8);
  ck_assert_int_eq(ulongg3, ulongg8);
  ck_assert_uint_eq(ulongg4, ulongg9);
  ck_assert_int_eq(ulongg4, ulongg9);
  ck_assert_uint_eq(ulongg5, ulongg10);
  ck_assert_int_eq(ulongg5, ulongg10);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_long_octal_5) {
  char input_line_0[] =
      "1111155  11223344556677000111222333444555  -555555  55545.444  end\0";
  char input_line_1[100] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned long ulongg1 = 1, ulongg2 = 2, ulongg3 = 3, ulongg6 = 1, ulongg7 = 2,
                ulongg8 = 3;
  ck_assert_int_eq(sscanf(input_line_0, "%lo%*o%lo%lo%s", &ulongg1, &ulongg2,
                          &ulongg3, endd1),
                   s21_sscanf(input_line_1, "%lo%*o%lo%lo%s", &ulongg6,
                              &ulongg7, &ulongg8, endd2));
  ck_assert_uint_eq(ulongg1, ulongg6);
  ck_assert_int_eq(ulongg1, ulongg6);
  ck_assert_uint_eq(ulongg2, ulongg7);
  ck_assert_int_eq(ulongg2, ulongg7);
  ck_assert_uint_eq(ulongg3, ulongg8);
  ck_assert_int_eq(ulongg3, ulongg8);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_long_octal_7) {
  char input_line_0[] =
      "1111155  11223344556677000111222333444555  -532456755555  55545.444  "
      "end\0";
  char input_line_1[100] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned long ulongg1 = 1, ulongg2 = 2, ulongg3 = 3, ulongg4 = 4, ulongg6 = 1,
                ulongg7 = 2, ulongg8 = 3, ulongg9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%lo%*10o%lo%lo%lo%s", &ulongg1,
                          &ulongg2, &ulongg3, &ulongg4, endd1),
                   s21_sscanf(input_line_1, "%lo%*10o%lo%lo%lo%s", &ulongg6,
                              &ulongg7, &ulongg8, &ulongg9, endd2));
  ck_assert_uint_eq(ulongg1, ulongg6);
  ck_assert_int_eq(ulongg1, ulongg6);
  ck_assert_uint_eq(ulongg2, ulongg7);
  ck_assert_int_eq(ulongg2, ulongg7);
  ck_assert_uint_eq(ulongg3, ulongg8);
  ck_assert_int_eq(ulongg3, ulongg8);
  ck_assert_uint_eq(ulongg4, ulongg9);
  ck_assert_int_eq(ulongg4, ulongg9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_long_octal_8) {
  char input_line_0[] =
      "2147483647   11223344556677000111222333444555  -532456755555  55545.444 "
      " end\0";
  char input_line_1[100] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned long ulongg1 = 1, ulongg2 = 2, ulongg3 = 3, ulongg4 = 4, ulongg6 = 1,
                ulongg7 = 2, ulongg8 = 3, ulongg9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%lo%*12o\n\n%lo%lo%lo%s", &ulongg1,
                          &ulongg2, &ulongg3, &ulongg4, endd1),
                   s21_sscanf(input_line_1, "%lo%*12o\n\n%lo%lo%lo%s", &ulongg6,
                              &ulongg7, &ulongg8, &ulongg9, endd2));
  ck_assert_uint_eq(ulongg1, ulongg6);
  ck_assert_int_eq(ulongg1, ulongg6);
  ck_assert_uint_eq(ulongg2, ulongg7);
  ck_assert_int_eq(ulongg2, ulongg7);
  ck_assert_uint_eq(ulongg3, ulongg8);
  ck_assert_int_eq(ulongg3, ulongg8);
  ck_assert_uint_eq(ulongg4, ulongg9);
  ck_assert_int_eq(ulongg4, ulongg9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_long_octal_9) {
  char input_line_0[] =
      "-2147483647   11223344556677000111222333444555  -532456755555  "
      "55545.444  end\0";
  char input_line_1[100] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned long ulongg1 = 1, ulongg2 = 2, ulongg3 = 3, ulongg4 = 4, ulongg6 = 1,
                ulongg7 = 2, ulongg8 = 3, ulongg9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%lo%*12o\n\n%lo%lo%lo%s", &ulongg1,
                          &ulongg2, &ulongg3, &ulongg4, endd1),
                   s21_sscanf(input_line_1, "%lo%*12o\n\n%lo%lo%lo%s", &ulongg6,
                              &ulongg7, &ulongg8, &ulongg9, endd2));
  ck_assert_uint_eq(ulongg1, ulongg6);
  ck_assert_int_eq(ulongg1, ulongg6);
  ck_assert_uint_eq(ulongg2, ulongg7);
  ck_assert_int_eq(ulongg2, ulongg7);
  ck_assert_uint_eq(ulongg3, ulongg8);
  ck_assert_int_eq(ulongg3, ulongg8);
  ck_assert_uint_eq(ulongg4, ulongg9);
  ck_assert_int_eq(ulongg4, ulongg9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_long_octal_14) {
  char input_line_0[] =
      "+1000008  11223344556677000111222333444555  -55555  5555.444   end\0";
  char input_line_1[100] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned long ulongg1 = 1, ulongg2 = 2, ulongg3 = 3, ulongg4 = 4, ulongg6 = 1,
                ulongg7 = 2, ulongg8 = 3, ulongg9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%lo%*12o\n\n%lo%lo%lo%s", &ulongg1,
                          &ulongg2, &ulongg3, &ulongg4, endd1),
                   s21_sscanf(input_line_1, "%lo%*12o\n\n%lo%lo%lo%s", &ulongg6,
                              &ulongg7, &ulongg8, &ulongg9, endd2));
  ck_assert_uint_eq(ulongg1, ulongg6);
  ck_assert_int_eq(ulongg1, ulongg6);
  ck_assert_uint_eq(ulongg2, ulongg7);
  ck_assert_int_eq(ulongg2, ulongg7);
  ck_assert_uint_eq(ulongg3, ulongg8);
  ck_assert_int_eq(ulongg3, ulongg8);
  ck_assert_uint_eq(ulongg4, ulongg9);
  ck_assert_int_eq(ulongg4, ulongg9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_long_octal_15) {
  char input_line_0[] =
      "18446744073709551615   11223344556677000111222333444555  -532456755555  "
      "55545.444  end\0";
  char input_line_1[100] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned long ulongg1 = 1, ulongg2 = 2, ulongg3 = 3, ulongg4 = 4, ulongg6 = 1,
                ulongg7 = 2, ulongg8 = 3, ulongg9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%lo%*12o\n\n%lo%lo%lo%s", &ulongg1,
                          &ulongg2, &ulongg3, &ulongg4, endd1),
                   s21_sscanf(input_line_1, "%lo%*12o\n\n%lo%lo%lo%s", &ulongg6,
                              &ulongg7, &ulongg8, &ulongg9, endd2));
  ck_assert_uint_eq(ulongg1, ulongg6);
  ck_assert_int_eq(ulongg1, ulongg6);
  ck_assert_uint_eq(ulongg2, ulongg7);
  ck_assert_int_eq(ulongg2, ulongg7);
  ck_assert_uint_eq(ulongg3, ulongg8);
  ck_assert_int_eq(ulongg3, ulongg8);
  ck_assert_uint_eq(ulongg4, ulongg9);
  ck_assert_int_eq(ulongg4, ulongg9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_long_octal_17) {
  char input_line_0[] =
      "  05.5   11223344556677000111222333444555  -532456755555  55545.444  "
      "end\0";
  char input_line_1[100] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned long ulongg1 = 1, ulongg2 = 2, ulongg3 = 3, ulongg4 = 4, ulongg6 = 1,
                ulongg7 = 2, ulongg8 = 3, ulongg9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%lo%*12o%lo\t\t%lo%lo%s", &ulongg1,
                          &ulongg2, &ulongg3, &ulongg4, endd1),
                   s21_sscanf(input_line_1, "%lo%*12o%lo\t\t%lo%lo%s", &ulongg6,
                              &ulongg7, &ulongg8, &ulongg9, endd2));
  ck_assert_uint_eq(ulongg1, ulongg6);
  ck_assert_int_eq(ulongg1, ulongg6);
  ck_assert_uint_eq(ulongg2, ulongg7);
  ck_assert_int_eq(ulongg2, ulongg7);
  ck_assert_uint_eq(ulongg3, ulongg8);
  ck_assert_int_eq(ulongg3, ulongg8);
  ck_assert_uint_eq(ulongg4, ulongg9);
  ck_assert_int_eq(ulongg4, ulongg9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_long_octal_18) {
  char input_line_0[] =
      "-9   11223344556677000111222333444555  -532456755555  55545.444  end\0";
  char input_line_1[100] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned long ulongg1 = 1, ulongg2 = 2, ulongg3 = 3, ulongg4 = 4, ulongg6 = 1,
                ulongg7 = 2, ulongg8 = 3, ulongg9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%lo9%*12o%lo%lo%lo%s", &ulongg1,
                          &ulongg2, &ulongg3, &ulongg4, endd1),
                   s21_sscanf(input_line_1, "%lo9%*12o%lo%lo%lo%s", &ulongg6,
                              &ulongg7, &ulongg8, &ulongg9, endd2));
  ck_assert_uint_eq(ulongg1, ulongg6);
  ck_assert_int_eq(ulongg1, ulongg6);
  ck_assert_uint_eq(ulongg2, ulongg7);
  ck_assert_int_eq(ulongg2, ulongg7);
  ck_assert_uint_eq(ulongg3, ulongg8);
  ck_assert_int_eq(ulongg3, ulongg8);
  ck_assert_uint_eq(ulongg4, ulongg9);
  ck_assert_int_eq(ulongg4, ulongg9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_long_octal_22) {
  char input_line_0[] =
      "234566699999999999999   11223344556677000111222333444555  -532456755555 "
      " 55545.444  end\0";
  char input_line_1[100] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned long ulongg1 = 1, ulongg2 = 2, ulongg3 = 3, ulongg4 = 4, ulongg6 = 1,
                ulongg7 = 2, ulongg8 = 3, ulongg9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%lo%*12o%lo%lo%lo%s", &ulongg1,
                          &ulongg2, &ulongg3, &ulongg4, endd1),
                   s21_sscanf(input_line_1, "%lo%*12o%lo%lo%lo%s", &ulongg6,
                              &ulongg7, &ulongg8, &ulongg9, endd2));
  ck_assert_uint_eq(ulongg1, ulongg6);
  ck_assert_int_eq(ulongg1, ulongg6);
  ck_assert_uint_eq(ulongg2, ulongg7);
  ck_assert_int_eq(ulongg2, ulongg7);
  ck_assert_uint_eq(ulongg3, ulongg8);
  ck_assert_int_eq(ulongg3, ulongg8);
  ck_assert_uint_eq(ulongg4, ulongg9);
  ck_assert_int_eq(ulongg4, ulongg9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_long_octal_25) {
  char input_line_0[] = "   922337203685 55555 end\0";
  char input_line_1[100] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned long ulongg1 = 1, ulongg2 = 2, ulongg6 = 1, ulongg7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%4lo%lo%s", &ulongg1, &ulongg2, endd1),
      s21_sscanf(input_line_1, "%4lo%lo%s", &ulongg6, &ulongg7, endd2));
  ck_assert_uint_eq(ulongg1, ulongg6);
  ck_assert_int_eq(ulongg1, ulongg6);
  ck_assert_uint_eq(ulongg2, ulongg7);
  ck_assert_int_eq(ulongg2, ulongg7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_long_octal_26) {
  char input_line_0[] = "   9223                    55555 end\0";
  char input_line_1[100] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned long ulongg1 = 1, ulongg2 = 2, ulongg6 = 1, ulongg7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%5lo%lo%s", &ulongg1, &ulongg2, endd1),
      s21_sscanf(input_line_1, "%5lo%lo%s", &ulongg6, &ulongg7, endd2));
  ck_assert_uint_eq(ulongg1, ulongg6);
  ck_assert_int_eq(ulongg1, ulongg6);
  ck_assert_uint_eq(ulongg2, ulongg7);
  ck_assert_int_eq(ulongg2, ulongg7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_long_octal_27) {
  char input_line_0[] = "   +923a567                    55555 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned long ulongg1 = 1, ulongg2 = 2, ulongg6 = 1, ulongg7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%5lo%lo%s", &ulongg1, &ulongg2, endd1),
      s21_sscanf(input_line_1, "%5lo%lo%s", &ulongg6, &ulongg7, endd2));
  ck_assert_uint_eq(ulongg1, ulongg6);
  ck_assert_int_eq(ulongg1, ulongg6);
  ck_assert_uint_eq(ulongg2, ulongg7);
  ck_assert_int_eq(ulongg2, ulongg7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_long_octal_28) {
  char input_line_0[] = "   +923a567                    55555 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned long ulongg1 = 1, ulongg2 = 2, ulongg6 = 1, ulongg7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%4lo\t\na%lo%s", &ulongg1, &ulongg2, endd1),
      s21_sscanf(input_line_1, "%4lo\t\na%lo%s", &ulongg6, &ulongg7, endd2));
  ck_assert_uint_eq(ulongg1, ulongg6);
  ck_assert_int_eq(ulongg1, ulongg6);
  ck_assert_uint_eq(ulongg2, ulongg7);
  ck_assert_int_eq(ulongg2, ulongg7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_long_octal_29) {
  char input_line_0[] = "   9223a567                    55555 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned long ulongg1 = 1, ulongg2 = 2, ulongg6 = 1, ulongg7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%8lo%lo%s", &ulongg1, &ulongg2, endd1),
      s21_sscanf(input_line_1, "%8lo%lo%s", &ulongg6, &ulongg7, endd2));
  ck_assert_uint_eq(ulongg1, ulongg6);
  ck_assert_int_eq(ulongg1, ulongg6);
  ck_assert_uint_eq(ulongg2, ulongg7);
  ck_assert_int_eq(ulongg2, ulongg7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_long_octal_30) {
  char input_line_0[] = "  -.6                   -0.6 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned long ulongg1 = 1, ulongg2 = 2, ulongg6 = 1, ulongg7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%5lo%lo%s", &ulongg1, &ulongg2, endd1),
      s21_sscanf(input_line_1, "%5lo%lo%s", &ulongg6, &ulongg7, endd2));
  ck_assert_uint_eq(ulongg1, ulongg6);
  ck_assert_int_eq(ulongg1, ulongg6);
  ck_assert_uint_eq(ulongg2, ulongg7);
  ck_assert_int_eq(ulongg2, ulongg7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_long_octal_31) {
  char input_line_0[] = "  .6                   -0.6 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned long ulongg1 = 1, ulongg2 = 2, ulongg6 = 1, ulongg7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%5lo%lo%s", &ulongg1, &ulongg2, endd1),
      s21_sscanf(input_line_1, "%5lo%lo%s", &ulongg6, &ulongg7, endd2));
  ck_assert_uint_eq(ulongg1, ulongg6);
  ck_assert_int_eq(ulongg1, ulongg6);
  ck_assert_uint_eq(ulongg2, ulongg7);
  ck_assert_int_eq(ulongg2, ulongg7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_unsigned_long_octal_32) {
  char input_line_0[] = "  -f                   -0.6 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned long ulongg1 = 1, ulongg2 = 2, ulongg6 = 1, ulongg7 = 2;
  ck_assert_int_eq(
      sscanf(input_line_0, "%5lo%lo%s", &ulongg1, &ulongg2, endd1),
      s21_sscanf(input_line_1, "%5lo%lo%s", &ulongg6, &ulongg7, endd2));
  ck_assert_uint_eq(ulongg1, ulongg6);
  ck_assert_int_eq(ulongg1, ulongg6);
  ck_assert_uint_eq(ulongg2, ulongg7);
  ck_assert_int_eq(ulongg2, ulongg7);
  ck_assert_str_eq(endd1, endd2);
}
// 9.10     //elevator
START_TEST(test_sscanf_hexadecimal_1) {
  char input_line_0[] =
      "11afd1  112233445566aaafffecce22333444555  -55AD5  55BB5.44C4  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(
      sscanf(input_line_0, "%x%x%x%x%s", &intt1, &intt2, &intt3, &intt4, endd1),
      s21_sscanf(input_line_1, "%x%x%x%x%s", &intt6, &intt7, &intt8, &intt9,
                 endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_hexadecimal_2) {
  char input_line_0[] =
      "11afd1  112233445566aaafffecce22333444555  -55AD5  55BB5.44C4  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%x%%%x%x%x%s", &intt1, &intt2, &intt3,
                          &intt4, endd1),
                   s21_sscanf(input_line_1, "%x%%%x%x%x%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_hexadecimal_3) {
  char input_line_0[] =
      "11afd1  %112233445566aaafffecce22333444555  -55AD5  55BB5.44C4  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%x%%%x%x%x%s", &intt1, &intt2, &intt3,
                          &intt4, endd1),
                   s21_sscanf(input_line_1, "%x%%%x%x%x%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_hexadecimal_4) {
  char input_line_0[] =
      "11afd1 hello 11223a3445566aaafffecce22333444555  -55AD5  55BB5.44C4  "
      "end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4, intt5 = 5, intt10 = 5;
  ck_assert_int_eq(sscanf(input_line_0, "%x hello%7X%x%x%x%s", &intt1, &intt2,
                          &intt5, &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%x hello%7X%x%x%x%s", &intt6,
                              &intt7, &intt10, &intt8, &intt9, endd2));
  sscanf(input_line_0, "%x hello%7X%x%x%x%s", &intt1, &intt2, &intt5, &intt3,
         &intt4, endd1);
  s21_sscanf(input_line_1, "%xhello%7X%x%x%x%s", &intt6, &intt7, &intt10,
             &intt8, &intt9, endd2);

  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_int_eq(intt5, intt10);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_hexadecimal_5) {
  char input_line_0[] =
      "11afd1  112233445566aaafffecce22333444555  -55AD5  55BB5.44C4  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt6 = 1, intt7 = 2, intt8 = 3;
  ck_assert_int_eq(
      sscanf(input_line_0, "%x%*x%x%x%s", &intt1, &intt2, &intt3, endd1),
      s21_sscanf(input_line_1, "%x%*x%x%x%s", &intt6, &intt7, &intt8, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_hexadecimal_6) {
  char input_line_0[] =
      "11afd1  112233445566aaafffecce2233344f555  -55AD5  55BB5.44C4  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%x%*26X%x%x%x%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%x%*26X%x%x%x%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_hexadecimal_7) {
  char input_line_0[] =
      "11afd1  112233445566aaafffecce22333444555  -55AD5  55BB5.44C4  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%x%*24x%x%x%x%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%x%*24x%x%x%x%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_hexadecimal_8) {
  char input_line_0[] =
      "ABCDEF  112233445566aaafffecce22333abc555  -55AD5  55BB5.44C4  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%x%*25X%x%x%x%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%x%*25X%x%x%x%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_hexadecimal_9) {
  char input_line_0[] =
      "abcdef  112233445566aaafffecce22333abc555  -55AD5  55BB5.44C4  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%x%*25x%x%x%x%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%x%*25x%x%x%x%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_hexadecimal_10) {
  char input_line_0[] =
      "ABCDEF  112233445566aaafffecce22333abc555  -55AD5  55BB5.44C4  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%X%*25X%x%x%x%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%X%*25X%x%x%x%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_hexadecimal_11) {
  char input_line_0[] =
      "       abcdef  112233445566aaafffecce22333abc555  -55AD5  55BB5.44C4  "
      "end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%X%*25x%x%x%x%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%X%*25x%x%x%x%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_hexadecimal_12) {
  char input_line_0[] =
      "  05.5  112233445566aaafffecce22333abc555  -55AD5  55BB5.44C4  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%X%*25X%X%X%X%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%X%*25X%X%X%X%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_hexadecimal_13) {
  char input_line_0[] =
      "0  112233445566aaafffecce22333abc555  -55AD5  55BB5.44C4  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%X%*25x%X%X%X%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%X%*25x%X%X%X%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_hexadecimal_14) {
  char input_line_0[] =
      "7fffffff  112233445566aaafffecce22333abc555  -55AD5  55BB5.44C4  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%X%*25X%X%X%X%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%X%*25X%X%X%X%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_hexadecimal_15) {
  char input_line_0[] =
      "-7fffffff 112233445566aaafffecce22333abc555  -55AD5  55BB5.44C4  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%X%*25x%X%X%X%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%X%*25x%X%X%X%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_hexadecimal_16) {
  char input_line_0[] =
      "-80000005 112233445566aaafffecce22333abc555  -55AD5  55BB5.44C4  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%X%*25x%X%X%X%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%X%*25x%X%X%X%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_hexadecimal_17) {
  char input_line_0[] =
      "+80000005 112233445566aaafffecce22333abc555  -55AD5  55BB5.44C4  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%X%*25x%X%X%X%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%X%*25x%X%X%X%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_hexadecimal_20) {
  char input_line_0[] =
      "8000000000000000 112233445566aaafffecce22333abc555  -55AD5  55BB5.44C4  "
      "end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%X%*25x%X%X%X%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%X%*25x%X%X%X%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_hexadecimal_22) {
  char input_line_0[] =
      "0x7745f 112233445566aaafffecce22333abc555  -55AD5  55BB5.44C4  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%x%*25x%X%X%X%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%x%*25x%X%X%X%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_hexadecimal_23) {
  char input_line_0[] =
      "-0x7745f 112233445566aaafffecce22333abc555  -55AD5  55BB5.44C4  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%x%*25x%X%X%X%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%x%*25x%X%X%X%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_hexadecimal_24) {
  char input_line_0[] =
      "-x7745f 112233445566aaafffecce22333abc555  -55AD5  55BB5.44C4  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%x%*25x%X%X%X%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%x%*25x%X%X%X%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_hexadecimal_25) {
  char input_line_0[] =
      "+x7745f 112233445566aaafffecce22333abc555  -55AD5  55BB5.44C4  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%x%*25x%X%X%X%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%x%*25x%X%X%X%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_hexadecimal_26) {
  char input_line_0[] =
      "+07745f 112233445566aaafffecce22333abc555  -55AD5  55BB5.44C4  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%x%*25x%X%X%X%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%x%*25x%X%X%X%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_hexadecimal_27) {
  char input_line_0[] =
      "xx07745f 112233445566aaafffecce22333abc555  -55AD5  55BB5.44C4  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%x%*25x%X%X%X%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%x%*25x%X%X%X%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_hexadecimal_28) {
  char input_line_0[] =
      "00x07745f 112233445566aaafffecce22333abc555  -55AD5  55BB5.44C4  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%x%*25x%X%X%X%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%x%*25x%X%X%X%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
/*
START_TEST(test_sscanf_hexadecimal_29) {
  char input_line_0[] =
      "0xx07745f 112233445566aaafffecce22333abc555  -55AD5  55BB5.44C4  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%x%*25x%X%X%X%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%x%*25x%X%X%X%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
*/

START_TEST(test_sscanf_hexadecimal_30) {
  char input_line_0[] =
      "+-0x07745f 112233445566aaafffecce22333abc555  -55AD5  55BB5.44C4  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%x%*25x%X%X%X%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%x%*25x%X%X%X%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_hexadecimal_31) {
  char input_line_0[] =
      "--07745f 112233445566aaafffecce22333abc555  -55AD5  55BB5.44C4  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%x%*25x%X%X%X%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%x%*25x%X%X%X%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_hexadecimal_32) {
  char input_line_0[] =
      "+0x7745f 112233445566aaafffecce22333abc555  -55AD5  55BB5.44C4  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%x%*25x%X%X%X%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%x%*25x%X%X%X%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_hexadecimal_33) {
  char input_line_0[] = "   92ff37203685 55Ad5 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt7 = 2, intt6 = 1;
  ck_assert_int_eq(sscanf(input_line_0, "%5X%X%s", &intt1, &intt2, endd1),
                   s21_sscanf(input_line_1, "%5X%X%s", &intt6, &intt7, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_hexadecimal_34) {
  char input_line_0[] = "   92a33                    55Ad5 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt7 = 2, intt6 = 1;
  ck_assert_int_eq(sscanf(input_line_0, "%8x%X%s", &intt1, &intt2, endd1),
                   s21_sscanf(input_line_1, "%8x%X%s", &intt6, &intt7, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_hexadecimal_35) {
  char input_line_0[] = "   +92233a567                    55Ad5 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt7 = 2, intt6 = 1;
  ck_assert_int_eq(sscanf(input_line_0, "%6X%X%s", &intt1, &intt2, endd1),
                   s21_sscanf(input_line_1, "%6X%X%s", &intt6, &intt7, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_hexadecimal_36) {
  char input_line_0[] = "   92233a567                    55Ad5 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt7 = 2, intt6 = 1;
  ck_assert_int_eq(sscanf(input_line_0, "%8x%X%s", &intt1, &intt2, endd1),
                   s21_sscanf(input_line_1, "%8x%X%s", &intt6, &intt7, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_hexadecimal_37) {
  char input_line_0[] = "  -.6                   -0.6 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt7 = 2, intt6 = 1;
  ck_assert_int_eq(sscanf(input_line_0, "%8X%X%s", &intt1, &intt2, endd1),
                   s21_sscanf(input_line_1, "%8X%X%s", &intt6, &intt7, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_hexadecimal_38) {
  char input_line_0[] = "  .6                   -0.6 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt7 = 2, intt6 = 1;
  ck_assert_int_eq(sscanf(input_line_0, "%8x%X%s", &intt1, &intt2, endd1),
                   s21_sscanf(input_line_1, "%8x%X%s", &intt6, &intt7, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_hexadecimal_39) {
  char input_line_0[] = "  -g                   -0.6 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt7 = 2, intt6 = 1;
  ck_assert_int_eq(sscanf(input_line_0, "%8X%X%s", &intt1, &intt2, endd1),
                   s21_sscanf(input_line_1, "%8X%X%s", &intt6, &intt7, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_str_eq(endd1, endd2);
}
/*
START_TEST(test_sscanf_hexadecimal_40) {
  char input_line_0[] = "  0xg                  -4294967304 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt7 = 2, intt6 = 1;
  ck_assert_int_eq(sscanf(input_line_0, "%X%X%s", &intt1, &intt2, endd1),
                   s21_sscanf(input_line_1, "%X%X%s", &intt6, &intt7, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_str_eq(endd1, endd2);
}
*/
/*
START_TEST(test_sscanf_hexadecimal_41) {
  char input_line_0[] = "  -0x                   -4294967304 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt7 = 2, intt6 = 1;
  ck_assert_int_eq(sscanf(input_line_0, "%X%X%s", &intt1, &intt2, endd1),
                   s21_sscanf(input_line_1, "%X%X%s", &intt6, &intt7, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_str_eq(endd1, endd2);
}
*/
START_TEST(test_sscanf_hexadecimal_42) {
  char input_line_0[] = "  +0x5                   -4296fg04 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt7 = 2, intt6 = 1;
  ck_assert_int_eq(sscanf(input_line_0, "%X%X%s", &intt1, &intt2, endd1),
                   s21_sscanf(input_line_1, "%X%X%s", &intt6, &intt7, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_hexadecimal_43) {
  char input_line_0[] = "  +0xf                   -4296fg04 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt7 = 2, intt6 = 1;
  ck_assert_int_eq(sscanf(input_line_0, "%X%X%s", &intt1, &intt2, endd1),
                   s21_sscanf(input_line_1, "%X%X%s", &intt6, &intt7, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_str_eq(endd1, endd2);
}
/*
START_TEST(test_sscanf_hexadecimal_44) {
  char input_line_0[] = "  +0xd                   -0x5 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt7 = 2, intt6 = 1;
  ck_assert_int_eq(sscanf(input_line_0, "%X%3x%s", &intt1, &intt2, endd1),
                   s21_sscanf(input_line_1, "%X%3x%s", &intt6, &intt7, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_str_eq(endd1, endd2);
}

START_TEST(test_sscanf_hexadecimal_45) {
  char input_line_0[] = "  +0                   0X5 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt7 = 2, intt6 = 1;
  ck_assert_int_eq(sscanf(input_line_0, "%X%2X%s", &intt1, &intt2, endd1),
                   s21_sscanf(input_line_1, "%X%2X%s", &intt6, &intt7, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_str_eq(endd1, endd2);
}
*/

// 9.11    //elevator
START_TEST(test_sscanf_short_hexadecimal_1) {
  char input_line_0[] =
      "11af  112233445566aaafffecce22333444555  -55AD  BB5.44C4  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
            intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hX%hX%hx%hx%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%hx%hx%hx%hx%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_hexadecimal_5) {
  char input_line_0[] =
      "11af  112233445566aaafffecce22333444555  -55AD  5BB5.44C4  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short int intt1 = 1, intt2 = 2, intt3 = 3, intt6 = 1, intt7 = 2, intt8 = 3;
  ck_assert_int_eq(
      sscanf(input_line_0, "%hx%*x%hx%hx%s", &intt1, &intt2, &intt3, endd1),
      s21_sscanf(input_line_1, "%hx%*x%hx%hx%s", &intt6, &intt7, &intt8,
                 endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_hexadecimal_6) {
  char input_line_0[] =
      "11af  112233445566aaafffecce22333447555  -55AD  5BB5.44C4  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
            intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hx%*29X%hx%hx%hx%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%hx%*29X%hx%hx%hx%s", &intt6,
                              &intt7, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_hexadecimal_7) {
  char input_line_0[] =
      "11af  112233445566aaafffecce22333444555  -55AD  5BB5.44C4  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
            intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hx%*24x%hx%hx%hx%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%hx%*24x%hx%hx%hx%s", &intt6,
                              &intt7, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_hexadecimal_8) {
  char input_line_0[] =
      "7ABC  112233445566aaafffecce22333abc555  -55AD  5BB5.44C4  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
            intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hx%*30X%hx%hx%hx%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%hx%*30X%hx%hx%hx%s", &intt6,
                              &intt7, &intt8, &intt9, endd2));
  // printf("%d\n",intt6);
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_hexadecimal_9) {
  char input_line_0[] =
      "7abc  112233445566aaafffecce22333abc555  -55AD  5BB5.44C4  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
            intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hx%*30x%hx%hx%hx%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%hx%*30x%hx%hx%hx%s", &intt6,
                              &intt7, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_hexadecimal_10) {
  char input_line_0[] =
      "7ABC  112233445566aaafffecce22333abc555  -55AD  5BB5.44C4  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
            intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hx%*30X%hx%hx%hx%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%hx%*30X%hx%hx%hx%s", &intt6,
                              &intt7, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_hexadecimal_11) {
  char input_line_0[] =
      "       7abc 112233445566aaafffecce22333abc555  -55AD  5BB5.44C4  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
            intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hx%*30x%hx%hx%hx%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%hx%*30x%hx%hx%hx%s", &intt6,
                              &intt7, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_hexadecimal_12) {
  char input_line_0[] =
      "  05.5  112233445566aaafffecce22333abc555  -55AD  5BB5.44C4  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
            intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hx%*30X%hx%hx%hx%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%hx%*30X%hx%hx%hx%s", &intt6,
                              &intt7, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_hexadecimal_13) {
  char input_line_0[] =
      "0  112233445566aaafffecce22333abc555  -55AD  5BB5.44C4  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
            intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hx%*30x%hx%hx%hx%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%hx%*30x%hx%hx%hx%s", &intt6,
                              &intt7, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_hexadecimal_14) {
  char input_line_0[] =
      "7fff  112233445566aaafffecce22333abc555  -55AD  5BB5.44C4  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
            intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hx%*30X%hx%hx%hx%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%hx%*30X%hx%hx%hx%s", &intt6,
                              &intt7, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_hexadecimal_15) {
  char input_line_0[] =
      "-7fff 112233445566aaafffecce22333abc555  -55AD  5BB5.44C4  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
            intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hx%*30x%hx%hx%hx%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%hx%*30x%hx%hx%hx%s", &intt6,
                              &intt7, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_hexadecimal_16) {
  char input_line_0[] =
      "-8000 112233445566aaafffecce22333abc555  -55AD  5BB5.44C4  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
            intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hx%*30x%hx%hx%hx%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%hx%*30x%hx%hx%hx%s", &intt6,
                              &intt7, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_hexadecimal_17) {
  char input_line_0[] =
      "+8000 112233445566aaafffecce22333abc555  -55AD  5BB5.44C4  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
            intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hx%*30x%hx%hx%hx%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%hx%*30x%hx%hx%hx%s", &intt6,
                              &intt7, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_hexadecimal_20) {
  char input_line_0[] =
      "8000000000000000 112233445566aaafffecce22333abc555  -55AD  5BB5.44C4  "
      "end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
            intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hX%*30x%hX%hX%hX%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%hX%*30x%hX%hX%hX%s", &intt6,
                              &intt7, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_hexadecimal_22) {
  char input_line_0[] =
      "0x7745 112233445566aaafffecce22333abc555  -55AD  5BB5.44C4  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
            intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hX%*30x%hX%hX%hX%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%hX%*30x%hX%hX%hX%s", &intt6,
                              &intt7, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_hexadecimal_23) {
  char input_line_0[] =
      "-0x7745 112233445566aaafffecce22333abc555  -55AD  5BB5.44C4  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
            intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hX%*30x%hX%hX%hX%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%hX%*30x%hX%hX%hX%s", &intt6,
                              &intt7, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_hexadecimal_24) {
  char input_line_0[] =
      "-x7745 112233445566aaafffecce22333abc555  -55AD  5BB5.44C4  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
            intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hX%*30x%hX%hX%hX%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%hX%*30x%hX%hX%hX%s", &intt6,
                              &intt7, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_hexadecimal_25) {
  char input_line_0[] =
      "+x7745 112233445566aaafffecce22333abc555  -55AD  5BB5.44C4  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
            intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hX%*30x%hX%hX%hX%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%hX%*30x%hX%hX%hX%s", &intt6,
                              &intt7, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_hexadecimal_26) {
  char input_line_0[] =
      "+07745 112233445566aaafffecce22333abc555  -55AD  5BB5.44C4  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
            intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hX%*30x%hX%hX%hX%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%hX%*30x%hX%hX%hX%s", &intt6,
                              &intt7, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_hexadecimal_27) {
  char input_line_0[] =
      "xx0774 112233445566aaafffecce22333abc555  -55AD  5BB5.44C4  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
            intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hX%*30x%hX%hX%hX%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%hX%*30x%hX%hX%hX%s", &intt6,
                              &intt7, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_hexadecimal_28) {
  char input_line_0[] =
      "00x0774 112233445566aaafffecce22333abc555  -55AD  5BB5.44C4  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
            intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hX%*30x%hX%hX%hX%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%hX%*30x%hX%hX%hX%s", &intt6,
                              &intt7, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
/*
START_TEST(test_sscanf_short_hexadecimal_29) {
  char input_line_0[] =
      "0xx0774 112233445566aaafffecce22333abc555  -55AD  5BB5.44C4  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
            intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hX%*30x%hX%hX%hX%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%hX%*30x%hX%hX%hX%s", &intt6,
                              &intt7, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
*/
START_TEST(test_sscanf_short_hexadecimal_32) {
  char input_line_0[] =
      "+0x7745 112233445566aaafffecce22333abc555  -55AD  5BB5.44C4  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
            intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hX%*30x%hX%hX%hX%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%hX%*30x%hX%hX%hX%s", &intt6,
                              &intt7, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_hexadecimal_33) {
  char input_line_0[] = "   92ff37203685 55AD end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short int intt1 = 1, intt2 = 2, intt7 = 2, intt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%3hX%hX%s", &intt1, &intt2, endd1),
      s21_sscanf(input_line_1, "%3hX%hX%s", &intt6, &intt7, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_hexadecimal_34) {
  char input_line_0[] = "   72a3                    55AD end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short int intt1 = 1, intt2 = 2, intt7 = 2, intt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%8hx%hX%s", &intt1, &intt2, endd1),
      s21_sscanf(input_line_1, "%8hx%hX%s", &intt6, &intt7, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_hexadecimal_35) {
  char input_line_0[] = "   +923a567                    55AD end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short int intt1 = 1, intt2 = 2, intt7 = 2, intt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%4hX%hX%s", &intt1, &intt2, endd1),
      s21_sscanf(input_line_1, "%4hX%hX%s", &intt6, &intt7, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_str_eq(endd1, endd2);
}
/*
START_TEST(test_sscanf_short_hexadecimal_40) {
  char input_line_0[] = "  0xg                  -4294967304 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short int intt1 = 1, intt2 = 2, intt7 = 2, intt6 = 1;
  ck_assert_int_eq(sscanf(input_line_0, "%hX%hX%s", &intt1, &intt2, endd1),
                   s21_sscanf(input_line_1, "%hX%hX%s", &intt6, &intt7, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_hexadecimal_41) {
  char input_line_0[] = "  -0x                   -4294 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short int intt1 = 1, intt2 = 2, intt7 = 2, intt6 = 1;
  ck_assert_int_eq(sscanf(input_line_0, "%hX%hX%s", &intt1, &intt2, endd1),
                   s21_sscanf(input_line_1, "%hX%hX%s", &intt6, &intt7, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_str_eq(endd1, endd2);
}
*/
START_TEST(test_sscanf_short_hexadecimal_42) {
  char input_line_0[] = "  +0x5                   -4296 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short int intt1 = 1, intt2 = 2, intt7 = 2, intt6 = 1;
  ck_assert_int_eq(sscanf(input_line_0, "%hX%hX%s", &intt1, &intt2, endd1),
                   s21_sscanf(input_line_1, "%hX%hX%s", &intt6, &intt7, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_hexadecimal_43) {
  char input_line_0[] = "  +0xf                   -4296 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short int intt1 = 1, intt2 = 2, intt7 = 2, intt6 = 1;
  ck_assert_int_eq(sscanf(input_line_0, "%hX%hX%s", &intt1, &intt2, endd1),
                   s21_sscanf(input_line_1, "%hX%hX%s", &intt6, &intt7, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_str_eq(endd1, endd2);
}
/*
START_TEST(test_sscanf_short_hexadecimal_44) {
  char input_line_0[] = "  +0xd                   -0x5 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short int intt1 = 1, intt2 = 2, intt7 = 2, intt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%hX%3hx%s", &intt1, &intt2, endd1),
      s21_sscanf(input_line_1, "%hX%3hx%s", &intt6, &intt7, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_short_hexadecimal_45) {
  char input_line_0[] = "  +0                   0X5 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short int intt1 = 1, intt2 = 2, intt7 = 2, intt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%hX%2hX%s", &intt1, &intt2, endd1),
      s21_sscanf(input_line_1, "%hX%2hX%s", &intt6, &intt7, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_str_eq(endd1, endd2);
}
*/

// 9.12    //elevator
START_TEST(test_sscanf_long_hexadecimal_1) {
  char input_line_0[] =
      "11abcdef98  112233445566aaafffecce22333444555  -55AD  BB5.44C4  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
           intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%lx%lx%lx%lx%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%lx%lx%lx%lx%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_hexadecimal_5) {
  char input_line_0[] =
      "11abcdef98  112233445566aaafffecce22333444555  -55ADFFDA  5BADAB5.44C4  "
      "end\0";
  char input_line_1[95] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long int intt1 = 1, intt2 = 2, intt3 = 3, intt6 = 1, intt7 = 2, intt8 = 3;
  ck_assert_int_eq(
      sscanf(input_line_0, "%lx%*x%lx%lx%s", &intt1, &intt2, &intt3, endd1),
      s21_sscanf(input_line_1, "%lx%*x%lx%lx%s", &intt6, &intt7, &intt8,
                 endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_hexadecimal_7) {
  char input_line_0[] =
      "11abcdef98  112233445566aaafffecce22333447555  -55ADFFDA  5BADAB5.44C4  "
      "end\0";
  char input_line_1[95] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
           intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%lx%10lX%*x%lx%lx%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%lx%10lX%*x%lx%lx%s", &intt6,
                              &intt7, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_hexadecimal_6) {
  char input_line_0[] =
      "11abcdef98  112233445566aaafffecce22333447555  -55ADFFDA  5BADAB5.44C4  "
      "end\0";
  char input_line_1[95] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
           intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%lx%*15X%lx%lx%lx%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%lx%*15X%lx%lx%lx%s", &intt6,
                              &intt7, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_hexadecimal_8) {
  char input_line_0[] =
      "7ABCAFF  112233445566aaafffecce22333abc555  -55ADFFDA  5BADAB5.44C4  "
      "end\0";
  char input_line_1[95] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
           intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%lx%*20X%lx%lx%lx%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%lx%*20X%lx%lx%lx%s", &intt6,
                              &intt7, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_hexadecimal_9) {
  char input_line_0[] =
      "7abcAFF  112233445566aaafffecce22333abc555  -55ADFFDA  5BADAB5.44C4  "
      "end\0";
  char input_line_1[95] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
           intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%lx%*20x%lx%lx%lx%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%lx%*20x%lx%lx%lx%s", &intt6,
                              &intt7, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_hexadecimal_12) {
  char input_line_0[] =
      "  05.5  112233445566aaafffecce22333abc555  -55ADFFDA  5BADAB5.44C4  "
      "end\0";
  char input_line_1[95] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
           intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%lx%*20X%lx%lx%lx%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%lx%*20X%lx%lx%lx%s", &intt6,
                              &intt7, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_hexadecimal_13) {
  char input_line_0[] =
      "0  112233445566aaafffecce22333abc555  -55ADFFDA  5BADAB5.44C4  end\0";
  char input_line_1[95] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
           intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%lx%*20x%lx%lx%lx%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%lx%*20x%lx%lx%lx%s", &intt6,
                              &intt7, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_hexadecimal_16) {
  char input_line_0[] =
      "-8000000000000000 112233445566aaafffecce22333abc555  -55ADFFDA  "
      "5BADAB5.44C4  end\0";
  char input_line_1[95] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
           intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%lx%*20x%lx%lx%lx%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%lx%*20x%lx%lx%lx%s", &intt6,
                              &intt7, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_hexadecimal_17) {
  char input_line_0[] =
      "+8000000000000000 112233445566aaafffecce22333abc555  -55ADFFDA  "
      "5BADAB5.44C4  end\0";
  char input_line_1[95] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
           intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%lx%*20x%lx%lx%lx%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%lx%*20x%lx%lx%lx%s", &intt6,
                              &intt7, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_hexadecimal_22) {
  char input_line_0[] =
      "0x774adadad5 112233445566aaafffecce22333abc555  -55ADFFDA  5BADAB5.44C4 "
      " end\0";
  char input_line_1[95] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
           intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%lx%*20x%lx%lx%lx%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%lx%*20x%lx%lx%lx%s", &intt6,
                              &intt7, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_hexadecimal_23) {
  char input_line_0[] =
      "-0x77adad45 112233445566aaafffecce22333abc555  -55ADFFDA  5BADAB5.44C4  "
      "end\0";
  char input_line_1[95] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
           intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%lx%*20x%lx%lx%lx%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%lx%*20x%lx%lx%lx%s", &intt6,
                              &intt7, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_hexadecimal_24) {
  char input_line_0[] =
      "-x774adad5 112233445566aaafffecce22333abc555  -55ADFFDA  5BADAB5.44C4  "
      "end\0";
  char input_line_1[95] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
           intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%lx%*20x%lx%lx%lx%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%lx%*20x%lx%lx%lx%s", &intt6,
                              &intt7, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_hexadecimal_25) {
  char input_line_0[] =
      "+x774aaa5 112233445566aaafffecce22333abc555  -55ADFFDA  5BADAB5.44C4  "
      "end\0";
  char input_line_1[95] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
           intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%lx%*20x%lx%lx%lx%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%lx%*20x%lx%lx%lx%s", &intt6,
                              &intt7, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_hexadecimal_26) {
  char input_line_0[] =
      "+077ddd45 112233445566aaafffecce22333abc555  -55ADFFDA  5BADAB5.44C4  "
      "end\0";
  char input_line_1[95] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
           intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%lx%*20x%lx%lx%lx%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%lx%*20x%lx%lx%lx%s", &intt6,
                              &intt7, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_hexadecimal_33) {
  char input_line_0[] = "   92ff37203685 55AD end\0";
  char input_line_1[95] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long int intt1 = 1, intt2 = 2, intt7 = 2, intt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%5lx%lx%s", &intt1, &intt2, endd1),
      s21_sscanf(input_line_1, "%5lx%lx%s", &intt6, &intt7, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_hexadecimal_34) {
  char input_line_0[] = "   72a3                    55AD end\0";
  char input_line_1[95] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long int intt1 = 1, intt2 = 2, intt7 = 2, intt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%8lx%lx%s", &intt1, &intt2, endd1),
      s21_sscanf(input_line_1, "%8lx%lx%s", &intt6, &intt7, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_hexadecimal_35) {
  char input_line_0[] = "   +923a567                    55AD end\0";
  char input_line_1[95] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long int intt1 = 1, intt2 = 2, intt7 = 2, intt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%8lx%lx%s", &intt1, &intt2, endd1),
      s21_sscanf(input_line_1, "%8lx%lx%s", &intt6, &intt7, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_str_eq(endd1, endd2);
}
/*
START_TEST(test_sscanf_long_hexadecimal_40) {
  char input_line_0[] = "  0xg                  -4294967304 end\0";
  char input_line_1[95] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long int intt1 = 1, intt2 = 2, intt7 = 2, intt6 = 1;
  ck_assert_int_eq(sscanf(input_line_0, "%lx%lx%s", &intt1, &intt2, endd1),
                   s21_sscanf(input_line_1, "%lx%lx%s", &intt6, &intt7, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_hexadecimal_41) {
  char input_line_0[] = "  -0x                   -4294 end\0";
  char input_line_1[95] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long int intt1 = 1, intt2 = 2, intt7 = 2, intt6 = 1;
  ck_assert_int_eq(sscanf(input_line_0, "%lx%lx%s", &intt1, &intt2, endd1),
                   s21_sscanf(input_line_1, "%lx%lx%s", &intt6, &intt7, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_str_eq(endd1, endd2);
}
*/
START_TEST(test_sscanf_long_hexadecimal_42) {
  char input_line_0[] = "  +0x5                   -4296 end\0";
  char input_line_1[95] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long int intt1 = 1, intt2 = 2, intt7 = 2, intt6 = 1;
  ck_assert_int_eq(sscanf(input_line_0, "%lx%lx%s", &intt1, &intt2, endd1),
                   s21_sscanf(input_line_1, "%lx%lx%s", &intt6, &intt7, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_hexadecimal_43) {
  char input_line_0[] = "  +0xf                   -4296 end\0";
  char input_line_1[95] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long int intt1 = 1, intt2 = 2, intt7 = 2, intt6 = 1;
  ck_assert_int_eq(sscanf(input_line_0, "%lx%lx%s", &intt1, &intt2, endd1),
                   s21_sscanf(input_line_1, "%lx%lx%s", &intt6, &intt7, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_str_eq(endd1, endd2);
}
/*
START_TEST(test_sscanf_long_hexadecimal_44) {
  char input_line_0[] = "  +0xd                   -0x5 end\0";
  char input_line_1[95] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long int intt1 = 1, intt2 = 2, intt7 = 2, intt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%lx%3lx%s", &intt1, &intt2, endd1),
      s21_sscanf(input_line_1, "%lx%3lx%s", &intt6, &intt7, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_hexadecimal_45) {
  char input_line_0[] = "  +0                   0X5 end\0";
  char input_line_1[95] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long int intt1 = 1, intt2 = 2, intt7 = 2, intt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%lx%2lx%s", &intt1, &intt2, endd1),
      s21_sscanf(input_line_1, "%lx%2lx%s", &intt6, &intt7, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_str_eq(endd1, endd2);
}
*/

// 9.13    //elevator
START_TEST(test_sscanf_float_12) {
  char input_line_0[] = "    e-30           +12342131.3111e-30       end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  float floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%f/n/n  %f%s", &floatt1, &floatt2, endd1),
      s21_sscanf(input_line_1, "%f/n/n  %f%s", &floatt6, &floatt7, endd2));
  ck_assert_float_eq(floatt1, floatt6);
  ck_assert_float_eq(floatt2, floatt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_float_13) {
  char input_line_0[] =
      "    -5.5e-3           +12342131.3111e-30    -421   end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  float floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%*f/n/n  %f%f%s", &floatt1, &floatt2, endd1),
      s21_sscanf(input_line_1, "%*f/n/n  %f%f%s", &floatt6, &floatt7, endd2));
  ck_assert_float_eq(floatt2, floatt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_float_14) {
  char input_line_0[] =
      "    -5.5e-3           +12342131.3111e-30    -421   end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  float floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%*5f/n/n  %f%f%s", &floatt1, &floatt2, endd1),
      s21_sscanf(input_line_1, "%*5f/n/n  %f%f%s", &floatt6, &floatt7, endd2));
  ck_assert_float_eq(floatt1, floatt6);
  ck_assert_float_eq(floatt2, floatt7);
  ck_assert_str_eq(endd1, endd2);
}
/*
START_TEST(test_sscanf_float_15) {
  char input_line_0[] =
      "    -5.5e-3           +12342131.3111e-30    -421   end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  float floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%6f/n/n %f%s", &floatt1, &floatt2, endd1),
      s21_sscanf(input_line_1, "%6f/n/n %f%s", &floatt6, &floatt7, endd2));
  ck_assert_float_eq(floatt1, floatt6);
  ck_assert_float_eq(floatt2, floatt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_float_16) {
  char input_line_0[] =
      "    -5.5e -3           +12342131.3111e   -30    -421   end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  float floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1, floatt3 = 3,
        floatt8 = 3;
  ck_assert_int_eq(sscanf(input_line_0, "%6f/n/n %f%f%s", &floatt1, &floatt2,
                          &floatt3, endd1),
                   s21_sscanf(input_line_1, "%6f/n/n %f%f%s", &floatt6,
                              &floatt7, &floatt8, endd2));
  ck_assert_float_eq(floatt1, floatt6);
  ck_assert_float_eq(floatt2, floatt7);
  ck_assert_float_eq(floatt3, floatt8);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_float_17) {
  char input_line_0[] =
      "    -5.5e -3           +12342131.3111e-30    -421   end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  float floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1, floatt3 = 3,
        floatt8 = 3;
  ck_assert_int_eq(sscanf(input_line_0, "%f/n/n %f%f%s", &floatt1, &floatt2,
                          &floatt3, endd1),
                   s21_sscanf(input_line_1, "%f/n/n %f%f%s", &floatt6, &floatt7,
                              &floatt8, endd2));
  ck_assert_float_eq(floatt1, floatt6);
  ck_assert_float_eq(floatt2, floatt7);
  ck_assert_float_eq(floatt3, floatt8);
  ck_assert_str_eq(endd1, endd2);
}
*/
START_TEST(test_sscanf_float_23) {
  char input_line_0[] =
      "    +.402823466           +12342131.3111e-30    -421   end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  float floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1, floatt3 = 3,
        floatt8 = 3;
  ck_assert_int_eq(sscanf(input_line_0, "%2f/n/n %f%f%s", &floatt1, &floatt2,
                          &floatt3, endd1),
                   s21_sscanf(input_line_1, "%2f/n/n %f%f%s", &floatt6,
                              &floatt7, &floatt8, endd2));
  ck_assert_float_eq(floatt1, floatt6);
  ck_assert_float_eq(floatt2, floatt7);
  ck_assert_float_eq(floatt3, floatt8);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_float_24) {
  char input_line_0[] =
      "    .402823466           +12342131.3111e-30    -421   end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  float floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1, floatt3 = 3,
        floatt8 = 3;
  ck_assert_int_eq(sscanf(input_line_0, "%1f/n/n %f%f%s", &floatt1, &floatt2,
                          &floatt3, endd1),
                   s21_sscanf(input_line_1, "%1f/n/n %f%f%s", &floatt6,
                              &floatt7, &floatt8, endd2));
  ck_assert_float_eq(floatt1, floatt6);
  ck_assert_float_eq(floatt2, floatt7);
  ck_assert_float_eq(floatt3, floatt8);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_float_25) {
  char input_line_0[] = "    .e4           +12342131.3111e-30    -421   end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  float floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1, floatt3 = 3,
        floatt8 = 3;
  ck_assert_int_eq(sscanf(input_line_0, "%3f/n/n %f%f%s", &floatt1, &floatt2,
                          &floatt3, endd1),
                   s21_sscanf(input_line_1, "%3f/n/n %f%f%s", &floatt6,
                              &floatt7, &floatt8, endd2));
  ck_assert_float_eq(floatt1, floatt6);
  ck_assert_float_eq(floatt2, floatt7);
  ck_assert_float_eq(floatt3, floatt8);
  ck_assert_str_eq(endd1, endd2);
}
// 9.14    //elevator
START_TEST(test_sscanf_double_1) {
  char input_line_0[] =
      "    0.5e4           +12342131.3111e-3    -421   end\\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1, floatt3 = 3,
         floatt8 = 3;
  ck_assert_int_eq(sscanf(input_line_0, "%lf/n/n %lf%lf%s", &floatt1, &floatt2,
                          &floatt3, endd1),
                   s21_sscanf(input_line_1, "%lf/n/n %lf%lf%s", &floatt6,
                              &floatt7, &floatt8, endd2));
  ck_assert_double_eq(floatt1, floatt6);
  ck_assert_double_eq(floatt2, floatt7);
  ck_assert_double_eq(floatt3, floatt8);
  ck_assert_str_eq(endd1, endd2);
}
// 9.15    //elevator
START_TEST(test_sscanf_long_double_1) {
  char input_line_0[] = "    1234567890         1234.21313111       end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%Lf%Lf%s", &floatt1, &floatt2, endd1),
      s21_sscanf(input_line_1, "%Lf%Lf%s", &floatt6, &floatt7, endd2));
  ck_assert_ldouble_eq(floatt1, floatt6);
  ck_assert_ldouble_eq(floatt2, floatt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_2) {
  char input_line_0[] =
      "    340282346638528859811704183484515925001           +12342133111e-30  "
      "  -421   end\0";
  char input_line_1[95] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1, floatt3 = 3,
              floatt8 = 3;
  ck_assert_int_eq(sscanf(input_line_0, "%Lf/n/n %Lf%Lf%s", &floatt1, &floatt2,
                          &floatt3, endd1),
                   s21_sscanf(input_line_1, "%Lf/n/n %Lf%Lf%s", &floatt6,
                              &floatt7, &floatt8, endd2));
  ck_assert_ldouble_eq(floatt1, floatt6);
  ck_assert_ldouble_eq(floatt2, floatt7);
  ck_assert_ldouble_eq(floatt3, floatt8);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_3) {
  char input_line_0[] = "    1234.567890hi         1234.21313111       end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%Lf/n/n hi%Lf%s", &floatt1, &floatt2, endd1),
      s21_sscanf(input_line_0, "%Lf/n/n hi%Lf%s", &floatt6, &floatt7, endd2));
  ck_assert_ldouble_eq_tol(floatt1, floatt6, 0.1e-10);
  ck_assert_ldouble_eq_tol(floatt2, floatt7, 0.1e-10);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_6) {
  char input_line_0[] =
      "    1234.567890e-3         1234.21313111E-5       end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%Lf/n/n  %Lf%s", &floatt1, &floatt2, endd1),
      s21_sscanf(input_line_1, "%Lf/n/n  %Lf%s", &floatt6, &floatt7, endd2));
  ck_assert_ldouble_eq_tol(floatt1, floatt6, 0.1e-10);
  ck_assert_ldouble_eq_tol(floatt2, floatt7, 0.1e-10);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_7) {
  char input_line_0[] =
      "    1234.567890e-30         1234.21313111E+30       end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%Lf/n/n  %Lf%s", &floatt1, &floatt2, endd1),
      s21_sscanf(input_line_1, "%Lf/n/n  %Lf%s", &floatt6, &floatt7, endd2));
  ck_assert_ldouble_eq_tol(floatt1, floatt6, 0.1e-10);
  ck_assert_ldouble_eq_tol(floatt2, floatt7, 0.1e-10);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_8) {
  char input_line_0[] =
      "    1234.567890E-30         1234.21313111e+30       end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%Lf/n/n  %Lf%s", &floatt1, &floatt2, endd1),
      s21_sscanf(input_line_1, "%Lf/n/n  %Lf%s", &floatt6, &floatt7, endd2));
  ck_assert_ldouble_eq_tol(floatt1, floatt6, 0.1e-10);
  ck_assert_ldouble_eq_tol(floatt2, floatt7, 0.1e-10);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_9) {
  char input_line_0[] =
      "    1234.567890-30         -12342131.3111e-30       end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%Lf/n/n  %Lf%s", &floatt1, &floatt2, endd1),
      s21_sscanf(input_line_1, "%Lf/n/n  %Lf%s", &floatt6, &floatt7, endd2));
  ck_assert_ldouble_eq_tol(floatt1, floatt6, 0.1e-10);
  ck_assert_ldouble_eq_tol(floatt2, floatt7, 0.1e-10);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_10) {
  char input_line_0[] =
      "    -12342131.3111e-30           +12342131.3111e-30       end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%Lf/n/n  %Lf%s", &floatt1, &floatt2, endd1),
      s21_sscanf(input_line_1, "%Lf/n/n  %Lf%s", &floatt6, &floatt7, endd2));
  ck_assert_ldouble_eq_tol(floatt1, floatt6, 0.1e-10);
  ck_assert_ldouble_eq_tol(floatt2, floatt7, 0.1e-10);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_12) {
  char input_line_0[] = "    e-30           +12342131.3111e-30       end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%Lf/n/n  %Lf%s", &floatt1, &floatt2, endd1),
      s21_sscanf(input_line_1, "%Lf/n/n  %Lf%s", &floatt6, &floatt7, endd2));
  ck_assert_ldouble_eq(floatt1, floatt6);
  ck_assert_ldouble_eq(floatt2, floatt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_13) {
  char input_line_0[] =
      "    -5.5e-3           +12342131.3111e-30    -421   end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%*f/n/n  %Lf%Lf%s", &floatt1, &floatt2, endd1),
      s21_sscanf(input_line_1, "%*f/n/n  %Lf%Lf%s", &floatt6, &floatt7, endd2));
  ck_assert_ldouble_eq(floatt2, floatt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_14) {
  char input_line_0[] =
      "    -5.5e-3           +12342131.3111e-30    -421   end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%*5f/n/n  %Lf%Lf%s", &floatt1, &floatt2, endd1),
      s21_sscanf(input_line_1, "%*5f/n/n  %Lf%Lf%s", &floatt6, &floatt7,
                 endd2));
  ck_assert_ldouble_eq(floatt1, floatt6);
  ck_assert_ldouble_eq(floatt2, floatt7);
  ck_assert_str_eq(endd1, endd2);
}
/*
START_TEST(test_sscanf_long_double_15) {
  char input_line_0[] =
      "    -5.5e-3           +12342131.3111e-30    -421   end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%6Lf/n/n %Lf%s", &floatt1, &floatt2, endd1),
      s21_sscanf(input_line_1, "%6Lf/n/n %Lf%s", &floatt6, &floatt7, endd2));
  ck_assert_ldouble_eq(floatt1, floatt6);
  ck_assert_ldouble_eq(floatt2, floatt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_16) {
  char input_line_0[] =
      "    -5.5e -3           +12342131.3111e   -30    -421   end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1, floatt3 = 3,
              floatt8 = 3;
  ck_assert_int_eq(sscanf(input_line_0, "%6Lf/n/n %Lf%Lf%s", &floatt1, &floatt2,
                          &floatt3, endd1),
                   s21_sscanf(input_line_1, "%6Lf/n/n %Lf%Lf%s", &floatt6,
                              &floatt7, &floatt8, endd2));
  ck_assert_ldouble_eq(floatt1, floatt6);
  ck_assert_ldouble_eq(floatt2, floatt7);
  ck_assert_ldouble_eq(floatt3, floatt8);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_17) {
  char input_line_0[] =
      "    -5.5e -3           +12342131.3111e-30    -421   end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1, floatt3 = 3,
              floatt8 = 3;
  ck_assert_int_eq(sscanf(input_line_0, "%Lf/n/n %Lf%Lf%s", &floatt1, &floatt2,
                          &floatt3, endd1),
                   s21_sscanf(input_line_1, "%Lf/n/n %Lf%Lf%s", &floatt6,
                              &floatt7, &floatt8, endd2));
  ck_assert_ldouble_eq(floatt1, floatt6);
  ck_assert_ldouble_eq(floatt2, floatt7);
  ck_assert_ldouble_eq(floatt3, floatt8);
  ck_assert_str_eq(endd1, endd2);
}
*/

START_TEST(test_sscanf_long_double_20) {
  char input_line_0[] =
      "    3.40282346638528859811704183484516925e-38           "
      "+12342131.3111e-30    -421   end\0";
  char input_line_1[95] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1, floatt3 = 3,
              floatt8 = 3;
  ck_assert_int_eq(sscanf(input_line_0, "%Lf/n/n %Lf%Lf%s", &floatt1, &floatt2,
                          &floatt3, endd1),
                   s21_sscanf(input_line_1, "%Lf/n/n %Lf%Lf%s", &floatt6,
                              &floatt7, &floatt8, endd2));
  ck_assert_ldouble_eq_tol(floatt1, floatt6, 1e-10);
  ck_assert_ldouble_eq_tol(floatt2, floatt7, 1e-10);
  ck_assert_ldouble_eq_tol(floatt3, floatt8, 1e-10);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_21) {
  char input_line_0[] =
      "    -3.40282346638528859811704183484516925e-38           "
      "+12342131.3111e-30    -421   end\0";
  char input_line_1[95] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1, floatt3 = 3,
              floatt8 = 3;
  ck_assert_int_eq(sscanf(input_line_0, "%Lf/n/n %Lf%Lf%s", &floatt1, &floatt2,
                          &floatt3, endd1),
                   s21_sscanf(input_line_1, "%Lf/n/n %Lf%Lf%s", &floatt6,
                              &floatt7, &floatt8, endd2));
  ck_assert_ldouble_eq_tol(floatt1, floatt6, 1e-10);
  ck_assert_ldouble_eq_tol(floatt2, floatt7, 1e-10);
  ck_assert_ldouble_eq_tol(floatt3, floatt8, 1e-10);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_23) {
  char input_line_0[] =
      "    +.402823466           +12342131.3111e-30    -421   end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1, floatt3 = 3,
              floatt8 = 3;
  ck_assert_int_eq(sscanf(input_line_0, "%2Lf/n/n %Lf%Lf%s", &floatt1, &floatt2,
                          &floatt3, endd1),
                   s21_sscanf(input_line_1, "%2Lf/n/n %Lf%Lf%s", &floatt6,
                              &floatt7, &floatt8, endd2));
  ck_assert_ldouble_eq(floatt1, floatt6);
  ck_assert_ldouble_eq(floatt2, floatt7);
  ck_assert_ldouble_eq(floatt3, floatt8);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_24) {
  char input_line_0[] =
      "    .402823466           +12342131.3111e-30    -421   end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1, floatt3 = 3,
              floatt8 = 3;
  ck_assert_int_eq(sscanf(input_line_0, "%1Lf/n/n %Lf%Lf%s", &floatt1, &floatt2,
                          &floatt3, endd1),
                   s21_sscanf(input_line_1, "%1Lf/n/n %Lf%Lf%s", &floatt6,
                              &floatt7, &floatt8, endd2));
  ck_assert_ldouble_eq(floatt1, floatt6);
  ck_assert_ldouble_eq(floatt2, floatt7);
  ck_assert_ldouble_eq(floatt3, floatt8);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_25) {
  char input_line_0[] = "    .e4           +12342131.3111e-30    -421   end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1, floatt3 = 3,
              floatt8 = 3;
  ck_assert_int_eq(sscanf(input_line_0, "%3Lf/n/n %Lf%Lf%s", &floatt1, &floatt2,
                          &floatt3, endd1),
                   s21_sscanf(input_line_1, "%3Lf/n/n %Lf%Lf%s", &floatt6,
                              &floatt7, &floatt8, endd2));
  ck_assert_ldouble_eq(floatt1, floatt6);
  ck_assert_ldouble_eq(floatt2, floatt7);
  ck_assert_ldouble_eq(floatt3, floatt8);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_30) {
  char input_line_0[] =
      "    1.79769313486231570814527423731704357e-308          "
      "-1.79769313486231570814527423731704357e-308   -421   end\0";
  char input_line_1[140] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1, floatt3 = 3,
              floatt8 = 3;
  ck_assert_int_eq(sscanf(input_line_0, "%Lf/n/n %Lf%Lf%s", &floatt1, &floatt2,
                          &floatt3, endd1),
                   s21_sscanf(input_line_1, "%Lf/n/n %Lf%Lf%s", &floatt6,
                              &floatt7, &floatt8, endd2));
  // printf(">>%.20Lf\n>>%.20Lf\n\n", floatt1, floatt6);
  ck_assert_ldouble_eq_tol(floatt1, floatt6, 1e-16);
  ck_assert_ldouble_eq(floatt2, floatt7);
  ck_assert_ldouble_eq(floatt3, floatt8);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_31) {
  char input_line_0[] =
      "    1.79769313486231570814527423731704357e-308          "
      "-1.79769313486231570814527423731704357e-308   -421   end\0";
  char input_line_1[140] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt3 = 3, floatt8 = 3;
  ck_assert_int_eq(
      sscanf(input_line_0, "%*f/n/n %*f%Lf%s", &floatt3, endd1),
      s21_sscanf(input_line_1, "%*f/n/n %*f%Lf%s", &floatt8, endd2));
  ck_assert_ldouble_eq(floatt3, floatt8);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_32) {
  char input_line_0[] =
      "    "
      "123453245345435345345345345535353453532424324253254342434456789087654321"
      "3456789098763455432          +12342131.3111e-30    -421   end\0";
  char input_line_1[140] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1, floatt3 = 3,
              floatt8 = 3;
  ck_assert_int_eq(sscanf(input_line_0, "%*79f/n/n %Lf%Lf%Lf%s", &floatt1,
                          &floatt2, &floatt3, endd1),
                   s21_sscanf(input_line_1, "%*79f/n/n %Lf%Lf%Lf%s", &floatt6,
                              &floatt7, &floatt8, endd2));
  ck_assert_ldouble_eq(floatt2, floatt7);
  ck_assert_ldouble_eq(floatt3, floatt8);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_33) {
  char input_line_0[] =
      "    "
      "123453245345435345345345345535353453532424324253254342434456789087654321"
      "3456789098763455432          +12342131.3111e-30    -421   end\0";
  char input_line_1[140] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt2 = 2, floatt7 = 2, floatt3 = 3, floatt8 = 3;
  ck_assert_int_eq(
      sscanf(input_line_0, "%*f/n/n %Lf%Lf%s", &floatt2, &floatt3, endd1),
      s21_sscanf(input_line_1, "%*f/n/n %Lf%Lf%s", &floatt7, &floatt8, endd2));
  ck_assert_ldouble_eq(floatt2, floatt7);
  ck_assert_ldouble_eq(floatt3, floatt8);
  ck_assert_str_eq(endd1, endd2);
}
// 9.16    //elevator
START_TEST(test_sscanf_long_double_g_1) {
  char input_line_0[] = "    1234567890         1234.21313111       end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%Lg%Lg%s", &floatt1, &floatt2, endd1),
      s21_sscanf(input_line_1, "%Lg%Lg%s", &floatt6, &floatt7, endd2));
  ck_assert_ldouble_eq(floatt1, floatt6);
  ck_assert_ldouble_eq(floatt2, floatt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_g_2) {
  char input_line_0[] =
      "    340282346638528859811704183484515925001           +12342133111e-30  "
      "  -421   end\0";
  char input_line_1[95] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1, floatt3 = 3,
              floatt8 = 3;
  ck_assert_int_eq(sscanf(input_line_0, "%Lg/n/n %Lg%Lg%s", &floatt1, &floatt2,
                          &floatt3, endd1),
                   s21_sscanf(input_line_1, "%Lg/n/n %Lg%Lg%s", &floatt6,
                              &floatt7, &floatt8, endd2));
  ck_assert_ldouble_eq(floatt1, floatt6);
  ck_assert_ldouble_eq(floatt2, floatt7);
  ck_assert_ldouble_eq(floatt3, floatt8);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_g_3) {
  char input_line_0[] = "    1234.567890hi         1234.21313111       end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%Lg/n/n hi%Lg%s", &floatt1, &floatt2, endd1),
      s21_sscanf(input_line_0, "%Lg/n/n hi%Lg%s", &floatt6, &floatt7, endd2));
  // printf(">>%.40Lf\n>>%.40Lf\n", floatt1, floatt6);
  ck_assert_ldouble_eq_tol(floatt1, floatt6, 0.1e-10);
  ck_assert_ldouble_eq_tol(floatt2, floatt7, 0.1e-10);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_g_6) {
  char input_line_0[] =
      "    1234.567890e-3         1234.21313111E-5       end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%Lg/n/n  %Lg%s", &floatt1, &floatt2, endd1),
      s21_sscanf(input_line_1, "%Lg/n/n  %Lg%s", &floatt6, &floatt7, endd2));
  ck_assert_ldouble_eq_tol(floatt1, floatt6, 0.1e-10);
  ck_assert_ldouble_eq_tol(floatt2, floatt7, 0.1e-10);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_g_7) {
  char input_line_0[] =
      "    1234.567890e-30         1234.21313111E+30       end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%Lg/n/n  %Lg%s", &floatt1, &floatt2, endd1),
      s21_sscanf(input_line_1, "%Lg/n/n  %Lg%s", &floatt6, &floatt7, endd2));
  ck_assert_ldouble_eq_tol(floatt1, floatt6, 0.1e-10);
  ck_assert_ldouble_eq_tol(floatt2, floatt7, 0.1e-10);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_g_8) {
  char input_line_0[] =
      "    1234.567890E-30         1234.21313111e+30       end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%Lg/n/n  %Lg%s", &floatt1, &floatt2, endd1),
      s21_sscanf(input_line_1, "%Lg/n/n  %Lg%s", &floatt6, &floatt7, endd2));
  ck_assert_ldouble_eq_tol(floatt1, floatt6, 0.1e-10);
  ck_assert_ldouble_eq_tol(floatt2, floatt7, 0.1e-10);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_g_9) {
  char input_line_0[] =
      "    1234.567890-30         -12342131.3111e-30       end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%Lg/n/n  %Lg%s", &floatt1, &floatt2, endd1),
      s21_sscanf(input_line_1, "%Lg/n/n  %Lg%s", &floatt6, &floatt7, endd2));
  ck_assert_ldouble_eq_tol(floatt1, floatt6, 0.1e-10);
  ck_assert_ldouble_eq_tol(floatt2, floatt7, 0.1e-10);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_g_10) {
  char input_line_0[] =
      "    -12342131.3111e-30           +12342131.3111e-30       end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%Lg/n/n  %Lg%s", &floatt1, &floatt2, endd1),
      s21_sscanf(input_line_1, "%Lg/n/n  %Lg%s", &floatt6, &floatt7, endd2));
  ck_assert_ldouble_eq_tol(floatt1, floatt6, 0.1e-10);
  ck_assert_ldouble_eq_tol(floatt2, floatt7, 0.1e-10);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_G_1) {
  char input_line_0[] = "    1234567890         1234.21313111       end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%LG%LG%s", &floatt1, &floatt2, endd1),
      s21_sscanf(input_line_1, "%LG%LG%s", &floatt6, &floatt7, endd2));
  ck_assert_ldouble_eq(floatt1, floatt6);
  ck_assert_ldouble_eq(floatt2, floatt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_G_2) {
  char input_line_0[] =
      "    340282346638528859811704183484515925001           +12342133111e-30  "
      "  -421   end\0";
  char input_line_1[95] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1, floatt3 = 3,
              floatt8 = 3;
  ck_assert_int_eq(sscanf(input_line_0, "%LG/n/n %LG%LG%s", &floatt1, &floatt2,
                          &floatt3, endd1),
                   s21_sscanf(input_line_1, "%LG/n/n %LG%LG%s", &floatt6,
                              &floatt7, &floatt8, endd2));
  ck_assert_ldouble_eq(floatt1, floatt6);
  ck_assert_ldouble_eq(floatt2, floatt7);
  ck_assert_ldouble_eq(floatt3, floatt8);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_G_3) {
  char input_line_0[] = "    1234.567890hi         1234.21313111       end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%LG/n/n hi%LG%s", &floatt1, &floatt2, endd1),
      s21_sscanf(input_line_0, "%LG/n/n hi%LG%s", &floatt6, &floatt7, endd2));
  ck_assert_ldouble_eq_tol(floatt1, floatt6, 0.1e-10);
  ck_assert_ldouble_eq_tol(floatt2, floatt7, 0.1e-10);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_G_6) {
  char input_line_0[] =
      "    1234.567890e-3         1234.21313111E-5       end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%LG/n/n  %LG%s", &floatt1, &floatt2, endd1),
      s21_sscanf(input_line_1, "%LG/n/n  %LG%s", &floatt6, &floatt7, endd2));
  ck_assert_ldouble_eq_tol(floatt1, floatt6, 0.1e-10);
  ck_assert_ldouble_eq_tol(floatt2, floatt7, 0.1e-10);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_G_7) {
  char input_line_0[] =
      "    1234.567890e-30         1234.21313111E+30       end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%LG/n/n  %LG%s", &floatt1, &floatt2, endd1),
      s21_sscanf(input_line_1, "%LG/n/n  %LG%s", &floatt6, &floatt7, endd2));
  ck_assert_ldouble_eq_tol(floatt1, floatt6, 0.1e-10);
  ck_assert_ldouble_eq_tol(floatt2, floatt7, 0.1e-10);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_G_8) {
  char input_line_0[] =
      "    1234.567890E-30         1234.21313111e+30       end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%LG/n/n  %LG%s", &floatt1, &floatt2, endd1),
      s21_sscanf(input_line_1, "%LG/n/n  %LG%s", &floatt6, &floatt7, endd2));
  ck_assert_ldouble_eq_tol(floatt1, floatt6, 0.1e-10);
  ck_assert_ldouble_eq_tol(floatt2, floatt7, 0.1e-10);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_G_9) {
  char input_line_0[] =
      "    1234.567890-30         -12342131.3111e-30       end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%LG/n/n  %LG%s", &floatt1, &floatt2, endd1),
      s21_sscanf(input_line_1, "%LG/n/n  %LG%s", &floatt6, &floatt7, endd2));
  ck_assert_ldouble_eq_tol(floatt1, floatt6, 0.1e-10);
  ck_assert_ldouble_eq_tol(floatt2, floatt7, 0.1e-10);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_G_10) {
  char input_line_0[] =
      "    -12342131.3111e-30           +12342131.3111e-30       end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%LG/n/n  %LG%s", &floatt1, &floatt2, endd1),
      s21_sscanf(input_line_1, "%LG/n/n  %LG%s", &floatt6, &floatt7, endd2));
  ck_assert_ldouble_eq_tol(floatt1, floatt6, 0.1e-10);
  ck_assert_ldouble_eq_tol(floatt2, floatt7, 0.1e-10);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_e_1) {
  char input_line_0[] = "    1234567890         1234.21313111       end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%Le%Le%s", &floatt1, &floatt2, endd1),
      s21_sscanf(input_line_1, "%Le%Le%s", &floatt6, &floatt7, endd2));
  ck_assert_ldouble_eq(floatt1, floatt6);
  ck_assert_ldouble_eq(floatt2, floatt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_e_2) {
  char input_line_0[] =
      "    340282346638528859811704183484515925001           +12342133111e-30  "
      "  -421   end\0";
  char input_line_1[95] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1, floatt3 = 3,
              floatt8 = 3;
  ck_assert_int_eq(sscanf(input_line_0, "%Le/n/n %Le%Le%s", &floatt1, &floatt2,
                          &floatt3, endd1),
                   s21_sscanf(input_line_1, "%Le/n/n %Le%Le%s", &floatt6,
                              &floatt7, &floatt8, endd2));
  ck_assert_ldouble_eq(floatt1, floatt6);
  ck_assert_ldouble_eq(floatt2, floatt7);
  ck_assert_ldouble_eq(floatt3, floatt8);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_e_3) {
  char input_line_0[] = "    1234.567890hi         1234.21313111       end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%Le/n/n hi%Le%s", &floatt1, &floatt2, endd1),
      s21_sscanf(input_line_0, "%Le/n/n hi%Le%s", &floatt6, &floatt7, endd2));
  ck_assert_ldouble_eq_tol(floatt1, floatt6, 0.1e-10);
  ck_assert_ldouble_eq_tol(floatt2, floatt7, 0.1e-10);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_e_6) {
  char input_line_0[] =
      "    1234.567890e-3         1234.21313111E-5       end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%Le/n/n  %Le%s", &floatt1, &floatt2, endd1),
      s21_sscanf(input_line_1, "%Le/n/n  %Le%s", &floatt6, &floatt7, endd2));
  ck_assert_ldouble_eq_tol(floatt1, floatt6, 0.1e-10);
  ck_assert_ldouble_eq_tol(floatt2, floatt7, 0.1e-10);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_e_7) {
  char input_line_0[] =
      "    1234.567890e-30         1234.21313111E+30       end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%Le/n/n  %Le%s", &floatt1, &floatt2, endd1),
      s21_sscanf(input_line_1, "%Le/n/n  %Le%s", &floatt6, &floatt7, endd2));
  ck_assert_ldouble_eq_tol(floatt1, floatt6, 0.1e-10);
  ck_assert_ldouble_eq_tol(floatt2, floatt7, 0.1e-10);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_e_8) {
  char input_line_0[] =
      "    1234.567890E-30         1234.21313111e+30       end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%Le/n/n  %Le%s", &floatt1, &floatt2, endd1),
      s21_sscanf(input_line_1, "%Le/n/n  %Le%s", &floatt6, &floatt7, endd2));
  ck_assert_ldouble_eq_tol(floatt1, floatt6, 0.1e-10);
  ck_assert_ldouble_eq_tol(floatt2, floatt7, 0.1e-10);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_e_9) {
  char input_line_0[] =
      "    1234.567890-30         -12342131.3111e-30       end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%Le/n/n  %Le%s", &floatt1, &floatt2, endd1),
      s21_sscanf(input_line_1, "%Le/n/n  %Le%s", &floatt6, &floatt7, endd2));
  ck_assert_ldouble_eq_tol(floatt1, floatt6, 0.1e-10);
  ck_assert_ldouble_eq_tol(floatt2, floatt7, 0.1e-10);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_e_10) {
  char input_line_0[] =
      "    -12342131.3111e-30           +12342131.3111e-30       end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%LE/n/n  %LE%s", &floatt1, &floatt2, endd1),
      s21_sscanf(input_line_1, "%LE/n/n  %LE%s", &floatt6, &floatt7, endd2));
  ck_assert_ldouble_eq_tol(floatt1, floatt6, 0.1e-10);
  ck_assert_ldouble_eq_tol(floatt2, floatt7, 0.1e-10);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_E_1) {
  char input_line_0[] = "    1234567890         1234.21313111       end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%LE%LE%s", &floatt1, &floatt2, endd1),
      s21_sscanf(input_line_1, "%LE%LE%s", &floatt6, &floatt7, endd2));
  ck_assert_ldouble_eq(floatt1, floatt6);
  ck_assert_ldouble_eq(floatt2, floatt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_E_2) {
  char input_line_0[] =
      "    340282346638528859811704183484515925001           +12342133111e-30  "
      "  -421   end\0";
  char input_line_1[95] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1, floatt3 = 3,
              floatt8 = 3;
  ck_assert_int_eq(sscanf(input_line_0, "%LE/n/n %LE%LE%s", &floatt1, &floatt2,
                          &floatt3, endd1),
                   s21_sscanf(input_line_1, "%LE/n/n %LE%LE%s", &floatt6,
                              &floatt7, &floatt8, endd2));
  ck_assert_ldouble_eq(floatt1, floatt6);
  ck_assert_ldouble_eq(floatt2, floatt7);
  ck_assert_ldouble_eq(floatt3, floatt8);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_E_3) {
  char input_line_0[] = "    1234.567890hi         1234.21313111       end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%LE/n/n hi%LE%s", &floatt1, &floatt2, endd1),
      s21_sscanf(input_line_0, "%LE/n/n hi%LE%s", &floatt6, &floatt7, endd2));
  ck_assert_ldouble_eq_tol(floatt1, floatt6, 0.1e-10);
  ck_assert_ldouble_eq_tol(floatt2, floatt7, 0.1e-10);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_E_6) {
  char input_line_0[] =
      "    1234.567890e-3         1234.21313111E-5       end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%LE/n/n  %LE%s", &floatt1, &floatt2, endd1),
      s21_sscanf(input_line_1, "%LE/n/n  %LE%s", &floatt6, &floatt7, endd2));
  ck_assert_ldouble_eq_tol(floatt1, floatt6, 0.1e-10);
  ck_assert_ldouble_eq_tol(floatt2, floatt7, 0.1e-10);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_E_7) {
  char input_line_0[] =
      "    1234.567890e-30         1234.21313111E+30       end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%LE/n/n  %LE%s", &floatt1, &floatt2, endd1),
      s21_sscanf(input_line_1, "%LE/n/n  %LE%s", &floatt6, &floatt7, endd2));
  ck_assert_ldouble_eq_tol(floatt1, floatt6, 0.1e-10);
  ck_assert_ldouble_eq_tol(floatt2, floatt7, 0.1e-10);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_E_8) {
  char input_line_0[] =
      "    1234.567890E-30         1234.21313111e+30       end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%LE/n/n  %LE%s", &floatt1, &floatt2, endd1),
      s21_sscanf(input_line_1, "%LE/n/n  %LE%s", &floatt6, &floatt7, endd2));
  ck_assert_ldouble_eq_tol(floatt1, floatt6, 0.1e-10);
  ck_assert_ldouble_eq_tol(floatt2, floatt7, 0.1e-10);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_E_9) {
  char input_line_0[] =
      "    1234.567890-30         -12342131.3111e-30       end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%LE/n/n  %LE%s", &floatt1, &floatt2, endd1),
      s21_sscanf(input_line_1, "%LE/n/n  %LE%s", &floatt6, &floatt7, endd2));
  ck_assert_ldouble_eq_tol(floatt1, floatt6, 0.1e-10);
  ck_assert_ldouble_eq_tol(floatt2, floatt7, 0.1e-10);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_double_E_10) {
  char input_line_0[] =
      "    -12342131.3111e-30           +12342131.3111e-30       end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long double floatt1 = 1, floatt2 = 2, floatt7 = 2, floatt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, "%LE/n/n  %LE%s", &floatt1, &floatt2, endd1),
      s21_sscanf(input_line_1, "%LE/n/n  %LE%s", &floatt6, &floatt7, endd2));
  ck_assert_ldouble_eq_tol(floatt1, floatt6, 0.1e-10);
  ck_assert_ldouble_eq_tol(floatt2, floatt7, 0.1e-10);
  ck_assert_str_eq(endd1, endd2);
}
// 9.17    //elevator
START_TEST(test_sscanf_i_1) {
  char input_line_0[] =
      "111111  11223344556677889900111222333444555  -55555  5555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(
      sscanf(input_line_0, "%i%i%i%i%s", &intt1, &intt2, &intt3, &intt4, endd1),
      s21_sscanf(input_line_1, "%i%i%i%i%s", &intt6, &intt7, &intt8, &intt9,
                 endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_i_2) {
  char input_line_0[] =
      "111111  11223344556677889900111222333444555  -55555  5555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%i%%%i%i%i%s", &intt1, &intt2, &intt3,
                          &intt4, endd1),
                   s21_sscanf(input_line_1, "%i%%%i%i%i%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_i_3) {
  char input_line_0[] =
      "111111  %11223344556677889900111222333444555  -55555  5555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%i%%%i%i%i%s", &intt1, &intt2, &intt3,
                          &intt4, endd1),
                   s21_sscanf(input_line_1, "%i%%%i%i%i%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_i_4) {
  char input_line_0[] =
      "111111  11223344556677889900111222333444555  -55555  5555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4, intt5 = 5, intt10 = 5;
  ck_assert_int_eq(sscanf(input_line_0, "%i%7i%i%i%i%s", &intt1, &intt2, &intt5,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%i%7i%i%i%i%s", &intt6, &intt7,
                              &intt10, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_int_eq(intt5, intt10);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_i_5) {
  char input_line_0[] =
      "111111  11223344556677889900111222333444555  -55555  5555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt6 = 1, intt7 = 2, intt8 = 3;
  ck_assert_int_eq(
      sscanf(input_line_0, "%i%*i%i%i%s", &intt1, &intt2, &intt3, endd1),
      s21_sscanf(input_line_1, "%i%*i%i%i%s", &intt6, &intt7, &intt8, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_i_6) {
  char input_line_0[] =
      "111111  11223344556677889900111222333444555  -55555  5555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%i%*26i%i%i%i%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%i%*26i%i%i%i%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_i_7) {
  char input_line_0[] =
      "111111  11223344556677889900111222333444555  -55555  5555.444  end\0";
  char input_line_1[85] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%i%*25i%i%i%i%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%i%*25i%i%i%i%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_i_8) {
  char input_line_0[] =
      "2147483647  11223344556677889900111222333444555  -55555  5555.444  "
      "end\0";
  char input_line_1[85] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%i%*25i%i%i%i%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%i%*25i%i%i%i%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_i_9) {
  char input_line_0[] =
      "-2147483647  11223344556677889900111222333444555  -55555  5555.444  "
      "end\0";
  char input_line_1[85] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%i%*25i%i%i%i%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%i%*25i%i%i%i%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_i_10) {
  char input_line_0[] =
      "0  11223344556677889900111222333444555  -55555  5555.444  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%i%*25i%i%i%i%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%i%*25i%i%i%i%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_i_11) {
  char input_line_0[] =
      "  05.5  11223344556677889900111222333444555  -55555  5555.444  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%i%*25i%i%i%i%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%i%*25i%i%i%i%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_i_12) {
  char input_line_0[] =
      "-2147483648  11223344556677889900111222333444555  -55555  5555.444  "
      "end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%i%*25i%i%i%i%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%i%*25i%i%i%i%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_i_13) {
  char input_line_0[] =
      "-2147483649  11223344556677889900111222333444555  -55555  5555.444  "
      "end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%i%*25i%i%i%i%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%i%*25i%i%i%i%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_i_14) {
  char input_line_0[] =
      "2147483655  11223344556677889900111222333444555  -55555  5555.444  "
      "end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%i%*25i%i%i%i%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%i%*25i%i%i%i%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_i_15) {
  char input_line_0[] = "   922337203685 55555 end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt7 = 2, intt6 = 1;
  ck_assert_int_eq(sscanf(input_line_0, "%5i%i%s", &intt1, &intt2, endd1),
                   s21_sscanf(input_line_1, "%5i%i%s", &intt6, &intt7, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_i_16) {
  char input_line_0[] =
      "0111111  01122334455667700111222333444555  -055555  05555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt3 = 3, uintt4 = 4, uintt6 = 1,
               uintt7 = 2, uintt8 = 3, uintt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%i%i%i%i%s", &uintt1, &uintt2, &uintt3,
                          &uintt4, endd1),
                   s21_sscanf(input_line_1, "%i%i%i%i%s", &uintt6, &uintt7,
                              &uintt8, &uintt9, endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_int_eq(uintt3, uintt8);
  ck_assert_uint_eq(uintt3, uintt8);
  ck_assert_int_eq(uintt4, uintt9);
  ck_assert_uint_eq(uintt4, uintt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_i_17) {
  char input_line_0[] =
      "abb  069  01122334455667700111222333444555  -055555  05555.444  end\0";
  char input_line_1[75] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[15] = "start\0", endd2[15] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt3 = 3, uintt4 = 4, uintt6 = 1,
               uintt7 = 2, uintt8 = 3, uintt9 = 4;
  ck_assert_int_eq(sscanf(input_line_1, "abb %i%i%i%i%s", &uintt1, &uintt2,
                          &uintt3, &uintt4, endd1),
                   s21_sscanf(input_line_0, "abb %i%i%i%i%s", &uintt6, &uintt7,
                              &uintt8, &uintt9, endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_int_eq(uintt3, uintt8);
  ck_assert_uint_eq(uintt3, uintt8);
  ck_assert_int_eq(uintt4, uintt9);
  ck_assert_uint_eq(uintt4, uintt9);
  ck_assert_str_eq(endd1, endd2);
}

START_TEST(test_sscanf_i_18) {
  char input_line_0[] =
      "   07779  01122334455667700111222333444555  -0556655  05555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[10] = "start\0", endd2[10] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt3 = 3, uintt4 = 4, uintt6 = 1,
               uintt7 = 2, uintt8 = 3, uintt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%i%i%i%i%s", &uintt1, &uintt2, &uintt3,
                          &uintt4, endd1),
                   s21_sscanf(input_line_1, "%i%i%i%i%s", &uintt6, &uintt7,
                              &uintt8, &uintt9, endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_int_eq(uintt3, uintt8);
  ck_assert_uint_eq(uintt3, uintt8);
  ck_assert_int_eq(uintt4, uintt9);
  ck_assert_uint_eq(uintt4, uintt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_i_19) {
  char input_line_0[] =
      "0111111  01122334455667700111222333444555  -055555  05555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt3 = 3, uintt4 = 4, uintt6 = 1,
               uintt7 = 2, uintt8 = 3, uintt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%i%%%i%i%i%s", &uintt1, &uintt2,
                          &uintt3, &uintt4, endd1),
                   s21_sscanf(input_line_1, "%i%%%i%i%i%s", &uintt6, &uintt7,
                              &uintt8, &uintt9, endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_int_eq(uintt3, uintt8);
  ck_assert_uint_eq(uintt3, uintt8);
  ck_assert_int_eq(uintt4, uintt9);
  ck_assert_uint_eq(uintt4, uintt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_i_20) {
  char input_line_0[] =
      "0111111  %01122334455667700111222333444555  -055555  05555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt3 = 3, uintt4 = 4, uintt6 = 1,
               uintt7 = 2, uintt8 = 3, uintt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%i%%%i%i%i%s", &uintt1, &uintt2,
                          &uintt3, &uintt4, endd1),
                   s21_sscanf(input_line_1, "%i%%%i%i%i%s", &uintt6, &uintt7,
                              &uintt8, &uintt9, endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_int_eq(uintt3, uintt8);
  ck_assert_uint_eq(uintt3, uintt8);
  ck_assert_int_eq(uintt4, uintt9);
  ck_assert_uint_eq(uintt4, uintt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_i_21) {
  char input_line_0[] =
      "0111111  01122334455667700111222333444555  -055555  05555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt3 = 3, uintt4 = 4, uintt6 = 1,
               uintt7 = 2, uintt8 = 3, uintt9 = 4, uintt5 = 5, uintt10 = 5;
  ck_assert_int_eq(sscanf(input_line_0, "%i%7i%i%i%i%s", &uintt1, &uintt2,
                          &uintt5, &uintt3, &uintt4, endd1),
                   s21_sscanf(input_line_1, "%i%7i%i%i%i%s", &uintt6, &uintt7,
                              &uintt10, &uintt8, &uintt9, endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_int_eq(uintt3, uintt8);
  ck_assert_uint_eq(uintt3, uintt8);
  ck_assert_int_eq(uintt4, uintt9);
  ck_assert_uint_eq(uintt4, uintt9);
  ck_assert_int_eq(uintt5, uintt10);
  ck_assert_uint_eq(uintt5, uintt10);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_i_22) {
  char input_line_0[] =
      "0111111  01122334455667700111222333444555  -055555  05555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt3 = 3, uintt6 = 1, uintt7 = 2,
               uintt8 = 3;
  ck_assert_int_eq(
      sscanf(input_line_0, "%i%*i%i%i%s", &uintt1, &uintt2, &uintt3, endd1),
      s21_sscanf(input_line_1, "%i%*i%i%i%s", &uintt6, &uintt7, &uintt8,
                 endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_int_eq(uintt3, uintt8);
  ck_assert_uint_eq(uintt3, uintt8);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_i_23) {
  char input_line_0[] =
      "0111111  01122334455667700111222333444555  -055555  05555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt3 = 3, uintt4 = 4, uintt6 = 1,
               uintt7 = 2, uintt8 = 3, uintt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%i%*26i%i%i%i%s", &uintt1, &uintt2,
                          &uintt3, &uintt4, endd1),
                   s21_sscanf(input_line_1, "%i%*26i%i%i%i%s", &uintt6, &uintt7,
                              &uintt8, &uintt9, endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_int_eq(uintt3, uintt8);
  ck_assert_uint_eq(uintt3, uintt8);
  ck_assert_int_eq(uintt4, uintt9);
  ck_assert_uint_eq(uintt4, uintt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_i_24) {
  char input_line_0[] =
      "0111111  011223344556677001191222333444555  -055555  05555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt3 = 3, uintt4 = 4, uintt6 = 1,
               uintt7 = 2, uintt8 = 3, uintt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%i%*26i%i%i%i%s", &uintt1, &uintt2,
                          &uintt3, &uintt4, endd1),
                   s21_sscanf(input_line_1, "%i%*26i%i%i%i%s", &uintt6, &uintt7,
                              &uintt8, &uintt9, endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_int_eq(uintt3, uintt8);
  ck_assert_uint_eq(uintt3, uintt8);
  ck_assert_int_eq(uintt4, uintt9);
  ck_assert_uint_eq(uintt4, uintt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_i_25) {
  char input_line_0[] =
      "017777777777  01122334455667700111222333444555  -055555  05555.444  "
      "end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt3 = 3, uintt4 = 4, uintt6 = 1,
               uintt7 = 2, uintt8 = 3, uintt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%i%*26i%i%i%i%s", &uintt1, &uintt2,
                          &uintt3, &uintt4, endd1),
                   s21_sscanf(input_line_1, "%i%*26i%i%i%i%s", &uintt6, &uintt7,
                              &uintt8, &uintt9, endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_int_eq(uintt3, uintt8);
  ck_assert_uint_eq(uintt3, uintt8);
  ck_assert_int_eq(uintt4, uintt9);
  ck_assert_uint_eq(uintt4, uintt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_i_26) {
  char input_line_0[] =
      "037777777777  01122334455667700111222333444555  -017777777777  "
      "05555.444  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt3 = 3, uintt4 = 4, uintt6 = 1,
               uintt7 = 2, uintt8 = 3, uintt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%i%*26i%i%i%i%s", &uintt1, &uintt2,
                          &uintt3, &uintt4, endd1),
                   s21_sscanf(input_line_1, "%i%*26i%i%i%i%s", &uintt6, &uintt7,
                              &uintt8, &uintt9, endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_int_eq(uintt3, uintt8);
  ck_assert_uint_eq(uintt3, uintt8);
  ck_assert_int_eq(uintt4, uintt9);
  ck_assert_uint_eq(uintt4, uintt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_i_27) {
  char input_line_0[] =
      "040000000000  01122334455667700111222333444555  -055555  05555.444  "
      "end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt3 = 3, uintt4 = 4, uintt6 = 1,
               uintt7 = 2, uintt8 = 3, uintt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%i%*26i%i%i%i%s", &uintt1, &uintt2,
                          &uintt3, &uintt4, endd1),
                   s21_sscanf(input_line_1, "%i%*26i%i%i%i%s", &uintt6, &uintt7,
                              &uintt8, &uintt9, endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_int_eq(uintt3, uintt8);
  ck_assert_uint_eq(uintt3, uintt8);
  ck_assert_int_eq(uintt4, uintt9);
  ck_assert_uint_eq(uintt4, uintt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_i_29) {
  char input_line_0[] =
      "-040000000001  01122334455667700111222333444555  -055555  05555.444  "
      "end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt3 = 3, uintt4 = 4, uintt6 = 1,
               uintt7 = 2, uintt8 = 3, uintt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%i%*26i%i%i%i%s", &uintt1, &uintt2,
                          &uintt3, &uintt4, endd1),
                   s21_sscanf(input_line_1, "%i%*26i%i%i%i%s", &uintt6, &uintt7,
                              &uintt8, &uintt9, endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_int_eq(uintt3, uintt8);
  ck_assert_uint_eq(uintt3, uintt8);
  ck_assert_int_eq(uintt4, uintt9);
  ck_assert_uint_eq(uintt4, uintt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_i_30) {
  char input_line_0[] =
      "   092233720 011223344556677889900111222333444555  -055555  05555.444  "
      "end\0";
  char input_line_1[90] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[90] = "start\0", endd2[90] = "start\0";
  unsigned int uintt1 = 1, uintt2 = 2, uintt3 = 3, uintt4 = 4, uintt6 = 1,
               uintt7 = 2, uintt8 = 3, uintt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%i%*26i%i%i%i%s", &uintt1, &uintt2,
                          &uintt3, &uintt4, endd1),
                   s21_sscanf(input_line_1, "%i%*26i%i%i%i%s", &uintt6, &uintt7,
                              &uintt8, &uintt9, endd2));
  ck_assert_int_eq(uintt1, uintt6);
  ck_assert_uint_eq(uintt1, uintt6);
  ck_assert_int_eq(uintt2, uintt7);
  ck_assert_uint_eq(uintt2, uintt7);
  ck_assert_int_eq(uintt3, uintt8);
  ck_assert_uint_eq(uintt3, uintt8);
  ck_assert_int_eq(uintt4, uintt9);
  ck_assert_uint_eq(uintt4, uintt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_i_31) {
  char input_line_0[] =
      "xa1  0x112233445566aaafffecce22333444555  -0x55AD5  0x55BB5.44C4  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(
      sscanf(input_line_0, "%i%i%i%i%s", &intt1, &intt2, &intt3, &intt4, endd1),
      s21_sscanf(input_line_1, "%i%i%i%i%s", &intt6, &intt7, &intt8, &intt9,
                 endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_i_32) {
  char input_line_0[] =
      "0x11afd1  0x112233445566aaafffecce22333444555  -0x55AD5  0x55BB5.44C4  "
      "end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[15] = "start\0", endd2[15] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%i%%%i%i%i%s", &intt1, &intt2, &intt3,
                          &intt4, endd1),
                   s21_sscanf(input_line_1, "%i%%%i%i%i%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_i_33) {
  char input_line_0[] =
      "0x11afd1  %0x112233445566aaafffecce22333444555  -0x55AD5  0x55BB5.44C4  "
      "end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[15] = "start\0", endd2[15] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%i%%%i%i%i%s", &intt1, &intt2, &intt3,
                          &intt4, endd1),
                   s21_sscanf(input_line_1, "%i%%%i%i%i%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_i_34) {
  char input_line_0[] =
      "0x11afd1 hello 0x11223a3445566aaafffecce22333444555  -0x55AD5  "
      "0x55BB5.44C4  end\0";
  char input_line_1[85] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[15] = "start\0", endd2[15] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4, intt5 = 5, intt10 = 5;
  ck_assert_int_eq(sscanf(input_line_0, "%i hello%7i%i%i%i%s", &intt1, &intt2,
                          &intt5, &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%i hello%7i%i%i%i%s", &intt6,
                              &intt7, &intt10, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_int_eq(intt5, intt10);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_i_35) {
  char input_line_0[] =
      "0x11afd1  0x112233445566aaafffecce22333444555  -0x55AD5  0x55BB5.44C4  "
      "end\0";
  char input_line_1[85] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[15] = "start\0", endd2[15] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt6 = 1, intt7 = 2, intt8 = 3;
  ck_assert_int_eq(
      sscanf(input_line_0, "%i%*i%i%i%s", &intt1, &intt2, &intt3, endd1),
      s21_sscanf(input_line_1, "%i%*i%i%i%s", &intt6, &intt7, &intt8, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_i_36) {
  char input_line_0[] =
      "0x11afd1  0x112233445566aaafffecce2233344f555  -0x55AD5  0x55BB5.44C4  "
      "end\0";
  char input_line_1[85] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[15] = "start\0", endd2[15] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%i%*26i%i%i%i%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%i%*26i%i%i%i%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_i_37) {
  char input_line_0[] =
      "0x11afd1  0x112233445566aaafffecce22333444555  -0x55AD5  0x55BB5.44C4  "
      "end\0";
  char input_line_1[85] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[15] = "start\0", endd2[15] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%i%*24i%i%i%i%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%i%*24i%i%i%i%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_i_38) {
  char input_line_0[] =
      "0xABCDEF  0x112233445566aaafffecce22333abc555  -0x55AD5  0x55BB5.44C4  "
      "end\0";
  char input_line_1[85] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[15] = "start\0", endd2[15] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%i%*25i%i%i%i%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%i%*25i%i%i%i%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_i_39) {
  char input_line_0[] =
      "0xabcdef  0x112233445566aaafffecce22333abc555  -0x55AD5  0x55BB5.44C4  "
      "end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[15] = "start\0", endd2[15] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%i%*25i%i%i%i%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%i%*25i%i%i%i%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_i_40) {
  char input_line_0[] =
      "0xABCDEF  0x112233445566aaafffecce22333abc555  -0x55AD5  0x55BB5.44C4  "
      "end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[15] = "start\0", endd2[15] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%i%*25i%i%i%i%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%i%*25i%i%i%i%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_i_41) {
  char input_line_0[] =
      "       0xabcdef  0x112233445566aaafffecce22333abc555  -0x55AD5  "
      "0x55BB5.44C4  end\0";
  char input_line_1[85] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[15] = "start\0", endd2[15] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%i%*25i%i%i%i%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%i%*25i%i%i%i%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_i_42) {
  char input_line_0[] =
      "  0x05.5  0x112233445566aaafffecce22333abc555  -0x55AD5  0x55BB5.44C4  "
      "end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[15] = "start\0", endd2[15] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%i%*25i%i%i%i%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%i%*25i%i%i%i%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_i_43) {
  char input_line_0[] =
      "0x0  0x112233445566aaafffecce22333abc555  -0x55AD5  0x55BB5.44C4  end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[15] = "start\0", endd2[15] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%i%*25i%i%i%i%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%i%*25i%i%i%i%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_i_44) {
  char input_line_0[] =
      "0x7fffffff  0x112233445566aaafffecce22333abc555  -0x55AD5  0x55BB5.44C4 "
      " end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[15] = "start\0", endd2[15] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%i%*25i%i%i%i%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%i%*25i%i%i%i%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_i_45) {
  char input_line_0[] =
      "-0x7fffffff 0x112233445566aaafffecce22333abc555  -0x55AD5  0x55BB5.44C4 "
      " end\0";
  char input_line_1[80] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
      intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%i%*25i%i%i%i%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%i%*25i%i%i%i%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
// 9.18    //elevator
START_TEST(test_sscanf_long_and_short_i_1) {
  char input_line_0[] =
      "11111  11223344556677889900111222333444555  -5555  555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short shortt1 = 1, shortt2 = 2, shortt3 = 3, shortt4 = 4, shortt6 = 1,
        shortt7 = 2, shortt8 = 3, shortt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hi%hi%hi%hi%s", &shortt1, &shortt2,
                          &shortt3, &shortt4, endd1),
                   s21_sscanf(input_line_1, "%hi%hi%hi%hi%s", &shortt6,
                              &shortt7, &shortt8, &shortt9, endd2));
  ck_assert_int_eq(shortt1, shortt6);
  ck_assert_int_eq(shortt2, shortt7);
  ck_assert_int_eq(shortt3, shortt8);
  ck_assert_int_eq(shortt4, shortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_and_short_i_2) {
  char input_line_0[] =
      "11111  11223344556677889900111222333444555  -5555  555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short shortt1 = 1, shortt2 = 2, shortt3 = 3, shortt4 = 4, shortt6 = 1,
        shortt7 = 2, shortt8 = 3, shortt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hi%%%hi%hi%hi%s", &shortt1, &shortt2,
                          &shortt3, &shortt4, endd1),
                   s21_sscanf(input_line_1, "%hi%%%hi%hi%hi%s", &shortt6,
                              &shortt7, &shortt8, &shortt9, endd2));
  ck_assert_int_eq(shortt1, shortt6);
  ck_assert_int_eq(shortt2, shortt7);
  ck_assert_int_eq(shortt3, shortt8);
  ck_assert_int_eq(shortt4, shortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_and_short_i_3) {
  char input_line_0[] =
      "11111  %\n\n11223344556677889900111222333444555  -5555  555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short shortt1 = 1, shortt2 = 2, shortt3 = 3, shortt4 = 4, shortt6 = 1,
        shortt7 = 2, shortt8 = 3, shortt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hi%%%hi%hi%hi%s", &shortt1, &shortt2,
                          &shortt3, &shortt4, endd1),
                   s21_sscanf(input_line_1, "%hi%%%hi%hi%hi%s", &shortt6,
                              &shortt7, &shortt8, &shortt9, endd2));
  ck_assert_int_eq(shortt1, shortt6);
  ck_assert_int_eq(shortt2, shortt7);
  ck_assert_int_eq(shortt3, shortt8);
  ck_assert_int_eq(shortt4, shortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_and_short_i_4) {
  char input_line_0[] =
      "11111  11223344556677889900111222333444555  -5555  555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short shortt1 = 1, shortt2 = 2, shortt3 = 3, shortt4 = 4, shortt6 = 1,
        shortt7 = 2, shortt8 = 3, shortt9 = 4, shortt5 = 5, shortt10 = 5;
  ck_assert_int_eq(sscanf(input_line_0, "%hi%7hi%hi%hi%hi%s", &shortt1,
                          &shortt2, &shortt5, &shortt3, &shortt4, endd1),
                   s21_sscanf(input_line_1, "%hi%7hi%hi%hi%hi%s", &shortt6,
                              &shortt7, &shortt10, &shortt8, &shortt9, endd2));
  ck_assert_int_eq(shortt1, shortt6);
  ck_assert_int_eq(shortt2, shortt7);
  ck_assert_int_eq(shortt3, shortt8);
  ck_assert_int_eq(shortt4, shortt9);
  ck_assert_int_eq(shortt5, shortt10);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_and_short_i_5) {
  char input_line_0[] =
      "11111  11223344556677889900111222333444555  -5555  555.444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short shortt1 = 1, shortt2 = 2, shortt3 = 3, shortt6 = 1, shortt7 = 2,
        shortt8 = 3;
  ck_assert_int_eq(sscanf(input_line_0, "%hi%*i%hi%hi%s", &shortt1, &shortt2,
                          &shortt3, endd1),
                   s21_sscanf(input_line_1, "%hi%*i%hi%hi%s", &shortt6,
                              &shortt7, &shortt8, endd2));
  ck_assert_int_eq(shortt1, shortt6);
  ck_assert_int_eq(shortt2, shortt7);
  ck_assert_int_eq(shortt3, shortt8);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_and_short_i_6) {
  char input_line_0[] =
      "0x11af  0x112233445566aaafffecce22333444555  -0x55AD  0xBB5.44C4  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
            intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hi%hi%hi%hi%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%hi%hi%hi%hi%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_and_short_i_7) {
  char input_line_0[] =
      "0x11af  0x112233445566aaafffecce22333444555  -0x55AD  0x5BB5.44C4  "
      "end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short int intt1 = 1, intt2 = 2, intt3 = 3, intt6 = 1, intt7 = 2, intt8 = 3;
  ck_assert_int_eq(
      sscanf(input_line_0, "%hi%*i%hi%hi%s", &intt1, &intt2, &intt3, endd1),
      s21_sscanf(input_line_1, "%hi%*i%hi%hi%s", &intt6, &intt7, &intt8,
                 endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_and_short_i_8) {
  char input_line_0[] =
      "0x11af  0x112233445566aaafffecce22333447555  -0x55AD  0x5BB5.44C4  "
      "end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
            intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hi%*29i%hi%hi%hi%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%hi%*29i%hi%hi%hi%s", &intt6,
                              &intt7, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_and_short_i_9) {
  char input_line_0[] =
      "0x11af  0x112233445566aaafffecce22333444555  -0x55AD  0x5BB5.44C4  "
      "end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
            intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hi%*24i%hi%hi%hi%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%hi%*24i%hi%hi%hi%s", &intt6,
                              &intt7, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_and_short_i_10) {
  char input_line_0[] =
      "0x7ABC  0x112233445566aaafffecce22333abc555  -0x55AD  0x5BB5.44C4  "
      "end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  short int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
            intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hi%*30i%hi%hi%hi%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%hi%*30i%hi%hi%hi%s", &intt6,
                              &intt7, &intt8, &intt9, endd2));
  // printf("%d\n",intt6);
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_and_short_i_12) {
  char input_line_0[] =
      "1111155  11223344556677889900111222333444555  -555555  55545.444  end\0";
  char input_line_1[100] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long longg1 = 1, longg2 = 2, longg3 = 3, longg4 = 4, longg6 = 1, longg7 = 2,
       longg8 = 3, longg9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%li%%%li%li%li%s", &longg1, &longg2,
                          &longg3, &longg4, endd1),
                   s21_sscanf(input_line_1, "%li%%%li%li%li%s", &longg6,
                              &longg7, &longg8, &longg9, endd2));
  ck_assert_int_eq(longg1, longg6);
  ck_assert_int_eq(longg2, longg7);
  ck_assert_int_eq(longg3, longg8);
  ck_assert_int_eq(longg4, longg9);
  ck_assert_str_eq(endd1, endd2);
}
/*
START_TEST(test_sscanf_long_and_short_i_11) {
  char input_line_0[] =
      "1111155  11223344556677889900111222333444555  -555555  55545.444  end\0";
  char input_line_1[100] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long longg1 = 1, longg2 = 2, longg3 = 3, longg4 = 4, longg6 = 1, longg7 = 2,
       longg8 = 3, longg9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%li%li%li%li%s", &longg1, &longg2,
                          &longg3, &longg4, endd1),
                   s21_sscanf(input_line_1, "%li%li%li%li%s", &longg6, &longg7,
                              &longg8, &longg9, endd2));
  ck_assert_int_eq(longg1, longg6);
  ck_assert_int_eq(longg2, longg7);
  ck_assert_int_eq(longg3, longg8);
  ck_assert_int_eq(longg4, longg9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_and_short_i_13) {
  char input_line_0[] =
      "1111155  %11223344556677889900111222333444555  -555555  55545.444  "
      "end\0";
  char input_line_1[100] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long longg1 = 1, longg2 = 2, longg3 = 3, longg4 = 4, longg6 = 1, longg7 = 2,
       longg8 = 3, longg9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%li%%%li%li%li%s", &longg1, &longg2,
                          &longg3, &longg4, endd1),
                   s21_sscanf(input_line_1, "%li%%%li%li%li%s", &longg6,
                              &longg7, &longg8, &longg9, endd2));
  ck_assert_int_eq(longg1, longg6);
  ck_assert_int_eq(longg2, longg7);
  ck_assert_int_eq(longg3, longg8);
  ck_assert_int_eq(longg4, longg9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_and_short_i_14) {
  char input_line_0[] =
      "1111155  11223344556677889900111222333444555  -555555  55545.444  end\0";
  char input_line_1[100] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long longg1 = 1, longg2 = 2, longg3 = 3, longg4 = 4, longg6 = 1, longg7 = 2,
       longg8 = 3, longg9 = 4, longg5 = 5, longg10 = 5;
  ck_assert_int_eq(sscanf(input_line_0, "%li%7li%li%li%li%s", &longg1, &longg2,
                          &longg5, &longg3, &longg4, endd1),
                   s21_sscanf(input_line_1, "%li%7li%li%li%li%s", &longg6,
                              &longg7, &longg10, &longg8, &longg9, endd2));
  ck_assert_int_eq(longg1, longg6);
  ck_assert_int_eq(longg2, longg7);
  ck_assert_int_eq(longg3, longg8);
  ck_assert_int_eq(longg4, longg9);
  ck_assert_int_eq(longg5, longg10);
  ck_assert_str_eq(endd1, endd2);
}
*/
START_TEST(test_sscanf_long_and_short_i_15) {
  char input_line_0[] =
      "1111155  11223344556677889900111222333444555  -555555  55545.444  end\0";
  char input_line_1[100] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long longg1 = 1, longg2 = 2, longg3 = 3, longg6 = 1, longg7 = 2, longg8 = 3;
  ck_assert_int_eq(
      sscanf(input_line_0, "%li%*i%li%li%s", &longg1, &longg2, &longg3, endd1),
      s21_sscanf(input_line_1, "%li%*i%li%li%s", &longg6, &longg7, &longg8,
                 endd2));
  ck_assert_int_eq(longg1, longg6);
  ck_assert_int_eq(longg2, longg7);
  ck_assert_int_eq(longg3, longg8);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_and_short_i_16) {
  char input_line_0[] = "0x11abcdef98  0xfffff11  -0x55AD  0xBB5.44C4  end\0";
  char input_line_1[85] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
           intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%li%li%li%li%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%li%li%li%li%s", &intt6, &intt7,
                              &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_and_short_i_17) {
  char input_line_0[] =
      "0x11abcdef98  0x112233445566aaafffecce22333444555  -0x55ADFFDA  "
      "0x5BADAB5.44C4  end\0";
  char input_line_1[95] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long int intt1 = 1, intt2 = 2, intt3 = 3, intt6 = 1, intt7 = 2, intt8 = 3;
  ck_assert_int_eq(
      sscanf(input_line_0, "%li%*i%li%li%s", &intt1, &intt2, &intt3, endd1),
      s21_sscanf(input_line_1, "%li%*i%li%li%s", &intt6, &intt7, &intt8,
                 endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_and_short_i_18) {
  char input_line_0[] =
      "0x11abcdef98  0x112233445566aaafffecce22333447555  -0x55ADFFDA  "
      "0x5BADAB5.44C4  end\0";
  char input_line_1[95] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
           intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%li%10li%*i%li%li%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%li%10li%*i%li%li%s", &intt6,
                              &intt7, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_and_short_i_19) {
  char input_line_0[] =
      "0x11abcdef98  0x112233445566aaafffecce22333447555  -0x55ADFFDA  "
      "0x5BADAB5.44C4  end\0";
  char input_line_1[95] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
           intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%li%*15i%li%li%li%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%li%*15i%li%li%li%s", &intt6,
                              &intt7, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_and_short_i_20) {
  char input_line_0[] =
      "0x7ABCAFF  0x112233445566aaafffecce22333abc555  -0x55ADFFDA  "
      "0x5BADAB5.44C4  end\0";
  char input_line_1[95] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  long int intt1 = 1, intt2 = 2, intt3 = 3, intt4 = 4, intt6 = 1, intt7 = 2,
           intt8 = 3, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%li%*20i%li%li%li%s", &intt1, &intt2,
                          &intt3, &intt4, endd1),
                   s21_sscanf(input_line_1, "%li%*20i%li%li%li%s", &intt6,
                              &intt7, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_and_short_i_21) {
  char input_line_0[] =
      "01111155  011223344556677  -0555555  055545.0444  end\0";
  char input_line_1[100] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned long ulongg1 = 1, ulongg2 = 2, ulongg3 = 3, ulongg4 = 4, ulongg6 = 1,
                ulongg7 = 2, ulongg8 = 3, ulongg9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%li%li%li%li%s", &ulongg1, &ulongg2,
                          &ulongg3, &ulongg4, endd1),
                   s21_sscanf(input_line_1, "%li%li%li%li%s", &ulongg6,
                              &ulongg7, &ulongg8, &ulongg9, endd2));
  ck_assert_uint_eq(ulongg1, ulongg6);
  ck_assert_int_eq(ulongg1, ulongg6);
  ck_assert_uint_eq(ulongg2, ulongg7);
  ck_assert_int_eq(ulongg2, ulongg7);
  ck_assert_uint_eq(ulongg3, ulongg8);
  ck_assert_int_eq(ulongg3, ulongg8);
  ck_assert_uint_eq(ulongg4, ulongg9);
  ck_assert_int_eq(ulongg4, ulongg9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_and_short_i_22) {
  char input_line_0[] =
      "01111155  011223344556677000111222333444555  -0555555  055545.04044  "
      "end\0";
  char input_line_1[100] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned long ulongg1 = 1, ulongg2 = 2, ulongg3 = 3, ulongg4 = 4, ulongg6 = 1,
                ulongg7 = 2, ulongg8 = 3, ulongg9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%li%%%li%li%li%s", &ulongg1, &ulongg2,
                          &ulongg3, &ulongg4, endd1),
                   s21_sscanf(input_line_1, "%li%%%li%li%li%s", &ulongg6,
                              &ulongg7, &ulongg8, &ulongg9, endd2));
  ck_assert_uint_eq(ulongg1, ulongg6);
  ck_assert_int_eq(ulongg1, ulongg6);
  ck_assert_uint_eq(ulongg2, ulongg7);
  ck_assert_int_eq(ulongg2, ulongg7);
  ck_assert_uint_eq(ulongg3, ulongg8);
  ck_assert_int_eq(ulongg3, ulongg8);
  ck_assert_uint_eq(ulongg4, ulongg9);
  ck_assert_int_eq(ulongg4, ulongg9);
  ck_assert_str_eq(endd1, endd2);
}
/*
START_TEST(test_sscanf_long_and_short_i_24) {
  char input_line_0[] =
      "01111155  011223344556677000111222333444555  -0555555  055545.0444  "
      "end\0";
  char input_line_1[100] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned long ulongg1 = 1, ulongg2 = 2, ulongg3 = 3, ulongg4 = 4, ulongg6 = 1,
                ulongg7 = 2, ulongg8 = 3, ulongg9 = 4, ulongg5 = 5,
                ulongg10 = 5;
  ck_assert_int_eq(sscanf(input_line_0, "%li%7li%li%li%li%s", &ulongg1,
                          &ulongg2, &ulongg5, &ulongg3, &ulongg4, endd1),
                   s21_sscanf(input_line_1, "%li%7li%li%li%li%s", &ulongg6,
                              &ulongg7, &ulongg10, &ulongg8, &ulongg9, endd2));
  ck_assert_uint_eq(ulongg1, ulongg6);
  ck_assert_int_eq(ulongg1, ulongg6);
  ck_assert_uint_eq(ulongg2, ulongg7);
  ck_assert_int_eq(ulongg2, ulongg7);
  ck_assert_uint_eq(ulongg3, ulongg8);
  ck_assert_int_eq(ulongg3, ulongg8);
  ck_assert_uint_eq(ulongg4, ulongg9);
  ck_assert_int_eq(ulongg4, ulongg9);
  ck_assert_uint_eq(ulongg5, ulongg10);
  ck_assert_int_eq(ulongg5, ulongg10);
  ck_assert_str_eq(endd1, endd2);
}
*/
START_TEST(test_sscanf_long_and_short_i_25) {
  char input_line_0[] =
      "01111155  011223344556677000111222333444555  -0555555  055545.0444  "
      "end\0";
  char input_line_1[100] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned long ulongg1 = 1, ulongg2 = 2, ulongg3 = 3, ulongg6 = 1, ulongg7 = 2,
                ulongg8 = 3;
  ck_assert_int_eq(sscanf(input_line_0, "%li%*i%li%li%s", &ulongg1, &ulongg2,
                          &ulongg3, endd1),
                   s21_sscanf(input_line_1, "%li%*i%li%li%s", &ulongg6,
                              &ulongg7, &ulongg8, endd2));
  ck_assert_uint_eq(ulongg1, ulongg6);
  ck_assert_int_eq(ulongg1, ulongg6);
  ck_assert_uint_eq(ulongg2, ulongg7);
  ck_assert_int_eq(ulongg2, ulongg7);
  ck_assert_uint_eq(ulongg3, ulongg8);
  ck_assert_int_eq(ulongg3, ulongg8);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_and_short_i_26) {
  char input_line_0[] =
      "01111  0122334455667700111222333444555  -0555  055.044  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt3 = 3, ushortt4 = 4,
                 ushortt6 = 1, ushortt7 = 2, ushortt8 = 3, ushortt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hi%hi%hi%hi%s", &ushortt1, &ushortt2,
                          &ushortt3, &ushortt4, endd1),
                   s21_sscanf(input_line_1, "%hi%hi%hi%hi%s", &ushortt6,
                              &ushortt7, &ushortt8, &ushortt9, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_uint_eq(ushortt3, ushortt8);
  ck_assert_int_eq(ushortt3, ushortt8);
  ck_assert_uint_eq(ushortt4, ushortt9);
  ck_assert_int_eq(ushortt4, ushortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_and_short_i_27) {
  char input_line_0[] =
      "01111  0122334455667700111222333444555  -0555  055.0444  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt3 = 3, ushortt4 = 4,
                 ushortt6 = 1, ushortt7 = 2, ushortt8 = 3, ushortt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hi%%%hi%hi%hi%s", &ushortt1,
                          &ushortt2, &ushortt3, &ushortt4, endd1),
                   s21_sscanf(input_line_1, "%hi%%%hi%hi%hi%s", &ushortt6,
                              &ushortt7, &ushortt8, &ushortt9, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_uint_eq(ushortt3, ushortt8);
  ck_assert_int_eq(ushortt3, ushortt8);
  ck_assert_uint_eq(ushortt4, ushortt9);
  ck_assert_int_eq(ushortt4, ushortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_and_short_i_28) {
  char input_line_0[] =
      "01111  %\n\n0122334455667700111222333444555  -0555  055.044  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt3 = 3, ushortt4 = 4,
                 ushortt6 = 1, ushortt7 = 2, ushortt8 = 3, ushortt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, "%hi%%%hi%hi%hi%s", &ushortt1,
                          &ushortt2, &ushortt3, &ushortt4, endd1),
                   s21_sscanf(input_line_1, "%hi%%%hi%hi%hi%s", &ushortt6,
                              &ushortt7, &ushortt8, &ushortt9, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_uint_eq(ushortt3, ushortt8);
  ck_assert_int_eq(ushortt3, ushortt8);
  ck_assert_uint_eq(ushortt4, ushortt9);
  ck_assert_int_eq(ushortt4, ushortt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_and_short_i_29) {
  char input_line_0[] =
      "01111  0122334455667700111222333444555  -0555  055.044  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt3 = 3, ushortt4 = 4,
                 ushortt6 = 1, ushortt7 = 2, ushortt8 = 3, ushortt9 = 4,
                 ushortt5 = 5, ushortt10 = 5;
  ck_assert_int_eq(
      sscanf(input_line_0, "%hi%4hi%hi%hi%hi%s", &ushortt1, &ushortt2,
             &ushortt5, &ushortt3, &ushortt4, endd1),
      s21_sscanf(input_line_1, "%hi%4hi%hi%hi%hi%s", &ushortt6, &ushortt7,
                 &ushortt10, &ushortt8, &ushortt9, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_uint_eq(ushortt3, ushortt8);
  ck_assert_int_eq(ushortt3, ushortt8);
  ck_assert_uint_eq(ushortt4, ushortt9);
  ck_assert_int_eq(ushortt4, ushortt9);
  ck_assert_uint_eq(ushortt5, ushortt10);
  ck_assert_int_eq(ushortt5, ushortt10);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_long_and_short_i_30) {
  char input_line_0[] =
      "01111  0122334455667700111222333444555  -0555  055.044  end\0";
  char input_line_1[70] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[6] = "start\0", endd2[6] = "start\0";
  unsigned short ushortt1 = 1, ushortt2 = 2, ushortt3 = 3, ushortt6 = 1,
                 ushortt7 = 2, ushortt8 = 3;
  ck_assert_int_eq(sscanf(input_line_0, "%hi%*i%hi%hi%s", &ushortt1, &ushortt2,
                          &ushortt3, endd1),
                   s21_sscanf(input_line_1, "%hi%*i%hi%hi%s", &ushortt6,
                              &ushortt7, &ushortt8, endd2));
  ck_assert_uint_eq(ushortt1, ushortt6);
  ck_assert_int_eq(ushortt1, ushortt6);
  ck_assert_uint_eq(ushortt2, ushortt7);
  ck_assert_int_eq(ushortt2, ushortt7);
  ck_assert_uint_eq(ushortt3, ushortt8);
  ck_assert_int_eq(ushortt3, ushortt8);
  ck_assert_str_eq(endd1, endd2);
}
// 9.19    //elevator
START_TEST(test_sscanf_pointer_1) {
  char input_line_0[] =
      "0xa1  0x112233445566aaafffecce22333444555  0x55AD5saada  0x55BB5.44C4  "
      "end\0";
  char input_line_1[90] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[20] = "start\0", endd2[20] = "start\0";
  int *pointt1 = NULL, *pointt2 = NULL, *pointt3 = NULL, *pointt4 = NULL,
      *pointt6 = NULL, *pointt7 = NULL, *pointt8 = NULL, *pointt9 = NULL;
  ck_assert_int_eq(sscanf(input_line_0, "%p%p%p%p%s", &pointt1, &pointt2,
                          &pointt3, &pointt4, endd1),
                   s21_sscanf(input_line_1, "%p%p%p%p%s", &pointt6, &pointt7,
                              &pointt8, &pointt9, endd2));
  ck_assert_ptr_eq(pointt1, pointt6);
  ck_assert_ptr_eq(pointt2, pointt7);
  ck_assert_ptr_eq(pointt3, pointt8);
  ck_assert_ptr_eq(pointt4, pointt9);
  ck_assert_str_eq(endd1, endd2);
}
/*
START_TEST(test_sscanf_pointer_3) {
  char input_line_0[] =
      "0x11afd1  %0x112233445566aaa 0xfffecce22333444555  0x 0x55AD5  0x55BB5  "
      "end\0";
  char input_line_1[90] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[20] = "start\0", endd2[20] = "start\0";
  int *pointt1 = NULL, *pointt2 = NULL, *pointt3 = NULL, *pointt4 = NULL,
      *pointt6 = NULL, *pointt7 = NULL, *pointt8 = NULL, *pointt9 = NULL;
  ck_assert_int_eq(sscanf(input_line_0, "%p%%%p%p%p%s", &pointt1, &pointt2,
                          &pointt3, &pointt4, endd1),
                   s21_sscanf(input_line_1, "%p%%%p%p%p%s", &pointt6, &pointt7,
                              &pointt8, &pointt9, endd2));
  ck_assert_ptr_eq(pointt1, pointt6);
  ck_assert_ptr_eq(pointt2, pointt7);
  ck_assert_ptr_eq(pointt3, pointt8);
  ck_assert_ptr_eq(pointt4, pointt9);
  ck_assert_str_eq(endd1, endd2);
}
*/

START_TEST(test_sscanf_pointer_4) {
  char input_line_0[] =
      "0x11afd1 hello 0x11223a3445566aaafffecce22333444555  0x55AD5  0x55BB5 "
      "end\0";
  char input_line_1[90] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[20] = "start\0", endd2[20] = "start\0";
  unsigned long int *pointt1 = NULL, *pointt2 = NULL, *pointt3 = NULL,
                    *pointt4 = NULL, *pointt6 = NULL, *pointt7 = NULL,
                    *pointt8 = NULL, *pointt9 = NULL, *pointt5 = NULL,
                    *pointt10 = NULL;
  ck_assert_int_eq(sscanf(input_line_0, "%p hello%7p%p%p%p%s", &pointt1,
                          &pointt2, &pointt5, &pointt3, &pointt4, endd1),
                   s21_sscanf(input_line_1, "%p hello%7p%p%p%p%s", &pointt6,
                              &pointt7, &pointt10, &pointt8, &pointt9, endd2));
  ck_assert_ptr_eq(pointt1, pointt6);
  ck_assert_ptr_eq(pointt2, pointt7);
  ck_assert_ptr_eq(pointt3, pointt8);
  ck_assert_ptr_eq(pointt4, pointt9);
  ck_assert_ptr_eq(pointt5, pointt10);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_pointer_5) {
  char input_line_0[] =
      "0x11afd1  0x112233445566aaafffecce22333444555  0x55AD5  0x55BB5 0x44C4  "
      "end\0";
  char input_line_1[90] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[20] = "start\0", endd2[20] = "start\0";
  double *pointt1 = NULL, *pointt2 = NULL, *pointt3 = NULL, *pointt6 = NULL,
         *pointt7 = NULL, *pointt8 = NULL;
  ck_assert_int_eq(
      sscanf(input_line_0, "%p%*p%p%p%s", &pointt1, &pointt2, &pointt3, endd1),
      s21_sscanf(input_line_1, "%p%*p%p%p%s", &pointt6, &pointt7, &pointt8,
                 endd2));
  ck_assert_ptr_eq(pointt1, pointt6);
  ck_assert_ptr_eq(pointt2, pointt7);
  ck_assert_ptr_eq(pointt3, pointt8);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_pointer_6) {
  char input_line_0[] =
      "0x11afd1  0x112233445566aaafffecce220x330x344f555  0x55AD5  0x55BB5 "
      "0x44C4  end\0";
  char input_line_1[90] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[20] = "start\0", endd2[20] = "start\0";
  double *pointt1 = NULL, *pointt2 = NULL, *pointt3 = NULL, *pointt4 = NULL,
         *pointt6 = NULL, *pointt7 = NULL, *pointt8 = NULL, *pointt9 = NULL;
  ck_assert_int_eq(sscanf(input_line_0, "%p%*26p%p%p%p%s", &pointt1, &pointt2,
                          &pointt3, &pointt4, endd1),
                   s21_sscanf(input_line_1, "%p%*26p%p%p%p%s", &pointt6,
                              &pointt7, &pointt8, &pointt9, endd2));
  ck_assert_ptr_eq(pointt1, pointt6);
  ck_assert_ptr_eq(pointt2, pointt7);
  ck_assert_ptr_eq(pointt3, pointt8);
  ck_assert_ptr_eq(pointt4, pointt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_pointer_7) {
  char input_line_0[] =
      "0x11afd1  0x112233445566aaafffecce22333444555  0x55AD5  0x55BB5 0x44C4  "
      "end\0";
  char input_line_1[90] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[20] = "start\0", endd2[20] = "start\0";
  double *pointt1 = NULL, *pointt2 = NULL, *pointt3 = NULL, *pointt4 = NULL,
         *pointt6 = NULL, *pointt7 = NULL, *pointt8 = NULL, *pointt9 = NULL;
  ck_assert_int_eq(sscanf(input_line_0, "%p%*24p%p%p%p%s", &pointt1, &pointt2,
                          &pointt3, &pointt4, endd1),
                   s21_sscanf(input_line_1, "%p%*24p%p%p%p%s", &pointt6,
                              &pointt7, &pointt8, &pointt9, endd2));
  ck_assert_ptr_eq(pointt1, pointt6);
  ck_assert_ptr_eq(pointt2, pointt7);
  ck_assert_ptr_eq(pointt3, pointt8);
  ck_assert_ptr_eq(pointt4, pointt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_pointer_9) {
  char input_line_0[] =
      " 0xabcdef   0x112233445566aaafffecce20x2333abc555   0x55AD5   0x55BB5 "
      "0x44C4  end\0";
  char input_line_1[90] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[20] = "start\0", endd2[20] = "start\0";
  char *pointt1 = NULL, *pointt2 = NULL, *pointt3 = NULL, *pointt4 = NULL,
       *pointt6 = NULL, *pointt7 = NULL, *pointt8 = NULL, *pointt9 = NULL;
  ck_assert_int_eq(sscanf(input_line_0, "%p%*25p%p%p%p%s", &pointt1, &pointt2,
                          &pointt3, &pointt4, endd1),
                   s21_sscanf(input_line_1, "%p%*25p%p%p%p%s", &pointt6,
                              &pointt7, &pointt8, &pointt9, endd2));
  ck_assert_ptr_eq(pointt1, pointt6);
  ck_assert_ptr_eq(pointt2, pointt7);
  ck_assert_ptr_eq(pointt3, pointt8);
  ck_assert_ptr_eq(pointt4, pointt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_pointer_11) {
  char input_line_0[] =
      "        0xabcdef   0x112233445566aaafffecce20x2333abc555   0x55AD5   "
      "0x55BB5 0x44C4  end\0";
  char input_line_1[90] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[20] = "start\0", endd2[20] = "start\0";
  short *pointt1 = NULL, *pointt2 = NULL, *pointt3 = NULL, *pointt4 = NULL,
        *pointt6 = NULL, *pointt7 = NULL, *pointt8 = NULL, *pointt9 = NULL;
  ck_assert_int_eq(sscanf(input_line_0, "%p%*25p%p%p%p%s", &pointt1, &pointt2,
                          &pointt3, &pointt4, endd1),
                   s21_sscanf(input_line_1, "%p%*25p%p%p%p%s", &pointt6,
                              &pointt7, &pointt8, &pointt9, endd2));
  ck_assert_ptr_eq(pointt1, pointt6);
  ck_assert_ptr_eq(pointt2, pointt7);
  ck_assert_ptr_eq(pointt3, pointt8);
  ck_assert_ptr_eq(pointt4, pointt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_pointer_12) {
  char input_line_0[] =
      "   0x05.5   0x112233445566aaafffecc 0x33abc555   0x55AD5   0x55BB5 "
      "0x4C4  end\0";
  char input_line_1[90] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[20] = "start\0", endd2[20] = "start\0";
  float *pointt1 = NULL, *pointt2 = NULL, *pointt3 = NULL, *pointt4 = NULL,
        *pointt6 = NULL, *pointt7 = NULL, *pointt8 = NULL, *pointt9 = NULL;
  ck_assert_int_eq(sscanf(input_line_0, "%p%*25p%p%p%p%s", &pointt1, &pointt2,
                          &pointt3, &pointt4, endd1),
                   s21_sscanf(input_line_1, "%p%*25p%p%p%p%s", &pointt6,
                              &pointt7, &pointt8, &pointt9, endd2));
  ck_assert_ptr_eq(pointt1, pointt6);
  ck_assert_ptr_eq(pointt2, pointt7);
  ck_assert_ptr_eq(pointt3, pointt8);
  ck_assert_ptr_eq(pointt4, pointt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_pointer_13) {
  char input_line_0[] =
      " 0x0   0x112233445566aaafffecc 0x2333abc555   0x55AD5   0x55BB5 0x44C4  "
      "end\0";
  char input_line_1[90] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[20] = "start\0", endd2[20] = "start\0";
  float *pointt1 = NULL, *pointt2 = NULL, *pointt3 = NULL, *pointt4 = NULL,
        *pointt6 = NULL, *pointt7 = NULL, *pointt8 = NULL, *pointt9 = NULL;
  ck_assert_int_eq(sscanf(input_line_0, "%p%*25p%p%p%p%s", &pointt1, &pointt2,
                          &pointt3, &pointt4, endd1),
                   s21_sscanf(input_line_1, "%p%*25p%p%p%p%s", &pointt6,
                              &pointt7, &pointt8, &pointt9, endd2));
  ck_assert_ptr_eq(pointt1, pointt6);
  ck_assert_ptr_eq(pointt2, pointt7);
  ck_assert_ptr_eq(pointt3, pointt8);
  ck_assert_ptr_eq(pointt4, pointt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_pointer_14) {
  char input_line_0[] =
      " 0x7fffffff   0x112233445566aaa 0xce22333abc555   0x55AD5   0x55BB5. "
      "0x44C4  end\0";
  char input_line_1[90] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[20] = "start\0", endd2[20] = "start\0";
  unsigned long int *pointt1 = NULL, *pointt2 = NULL, *pointt3 = NULL,
                    *pointt4 = NULL, *pointt6 = NULL, *pointt7 = NULL,
                    *pointt8 = NULL, *pointt9 = NULL;
  ck_assert_int_eq(sscanf(input_line_0, "%p%*25p%p%p%p%s", &pointt1, &pointt2,
                          &pointt3, &pointt4, endd1),
                   s21_sscanf(input_line_1, "%p%*25p%p%p%p%s", &pointt6,
                              &pointt7, &pointt8, &pointt9, endd2));
  ck_assert_ptr_eq(pointt1, pointt6);
  ck_assert_ptr_eq(pointt2, pointt7);
  ck_assert_ptr_eq(pointt3, pointt8);
  ck_assert_ptr_eq(pointt4, pointt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_pointer_15) {
  char input_line_0[] =
      "null 0x112233445566aa 0xfece22333abc555   0x55AD5   0x55BB5 0x44C4  "
      "end\0";
  char input_line_1[90] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[20] = "start\0", endd2[20] = "start\0";
  char *pointt1 = &input_line_0[0], *pointt2 = NULL, *pointt3 = NULL,
       *pointt4 = NULL, *pointt6 = &input_line_0[0], *pointt7 = NULL,
       *pointt8 = NULL, *pointt9 = NULL;
  ck_assert_int_eq(sscanf(input_line_0, "%p%*25p%p%p%p%s", &pointt1, &pointt2,
                          &pointt3, &pointt4, endd1),
                   s21_sscanf(input_line_1, "%p%*25p%p%p%p%s", &pointt6,
                              &pointt7, &pointt8, &pointt9, endd2));
  ck_assert_ptr_eq(pointt1, pointt6);
  ck_assert_ptr_eq(pointt2, pointt7);
  ck_assert_ptr_eq(pointt3, pointt8);
  ck_assert_ptr_eq(pointt4, pointt9);
  ck_assert_str_eq(endd1, endd2);
}
// 9.20    //elevator
START_TEST(test_sscanf_char_and_long_char_1) {
  char input_line_0[] = "asdf end\0";
  char input_line_1[90] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[20] = "start\0", endd2[20] = "start\0";
  char charr1 = 0, charr2 = 0, charr3 = 0, charr4 = 0, charr6 = 0, charr7 = 0,
       charr8 = 0, charr9 = 0;
  ck_assert_int_eq(sscanf(input_line_0, "%c%c%c%c%s", &charr1, &charr2, &charr3,
                          &charr4, endd1),
                   s21_sscanf(input_line_1, "%c%c%c%c%s", &charr6, &charr7,
                              &charr8, &charr9, endd2));
  ck_assert_int_eq(charr1, charr6);
  ck_assert_int_eq(charr2, charr7);
  ck_assert_int_eq(charr3, charr8);
  ck_assert_int_eq(charr4, charr9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_char_and_long_char_8) {
  char input_line_0[] = {1,  2,  3,  4,  5,  6,   7,   8,   14,  15, 16,
                         17, 18, 19, 20, 21, 22,  23,  24,  25,  26, 27,
                         28, 29, 30, 31, 32, 'e', 'n', 'd', '\0'};
  char input_line_1[90] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[20] = "start\0", endd2[20] = "start\0";
  char charr1 = 0, charr2 = 0, charr3 = 0, charr4 = 0, charr6 = 0, charr7 = 0,
       charr8 = 0, charr9 = 0;
  ck_assert_int_eq(sscanf(input_line_0, "%5c%*7c%c%c%c%s", &charr1, &charr2,
                          &charr3, &charr4, endd1),
                   s21_sscanf(input_line_1, "%5c%*7c%c%c%c%s", &charr6, &charr7,
                              &charr8, &charr9, endd2));
  ck_assert_int_eq(charr1, charr6);
  ck_assert_int_eq(charr2, charr7);
  ck_assert_int_eq(charr3, charr8);
  ck_assert_int_eq(charr4, charr9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_char_and_long_char_10) {
  char input_line_0[] = "12456123456789023456 end\0";
  char input_line_1[90] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[20] = "start\0", endd2[20] = "start\0";
  char charr1 = 0, charr2 = 0, charr3 = 0, charr4 = 0, charr6 = 0, charr7 = 0,
       charr8 = 0, charr9 = 0;
  ck_assert_int_eq(sscanf(input_line_0, "%5c%*7c%c%c%c%s", &charr1, &charr2,
                          &charr3, &charr4, endd1),
                   s21_sscanf(input_line_1, "%5c%*7c%c%c%c%s", &charr6, &charr7,
                              &charr8, &charr9, endd2));
  ck_assert_int_eq(charr1, charr6);
  ck_assert_int_eq(charr2, charr7);
  ck_assert_int_eq(charr3, charr8);
  ck_assert_int_eq(charr4, charr9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_char_and_long_char_11) {
  char input_line_0[] = "asdf end\0";
  char input_line_1[90] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[20] = "start\0", endd2[20] = "start\0";
  wint_t charr1 = 0, charr2 = 0, charr3 = 0, charr4 = 0, charr6 = 0, charr7 = 0,
         charr8 = 0, charr9 = 0;
  ck_assert_int_eq(sscanf(input_line_0, "%lc%lc%lc%lc%s", &charr1, &charr2,
                          &charr3, &charr4, endd1),
                   s21_sscanf(input_line_1, "%lc%lc%lc%lc%s", &charr6, &charr7,
                              &charr8, &charr9, endd2));
  ck_assert_int_eq(charr1, charr6);
  ck_assert_int_eq(charr2, charr7);
  ck_assert_int_eq(charr3, charr8);
  ck_assert_int_eq(charr4, charr9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_char_and_long_char_18) {
  char input_line_0[] = {1,  2,  3,  4,  5,  6,   7,   8,   14,  15, 16,
                         17, 18, 19, 20, 21, 22,  23,  24,  25,  26, 27,
                         28, 29, 30, 31, 32, 'e', 'n', 'd', '\0'};
  char input_line_1[90] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[20] = "start\0", endd2[20] = "start\0";
  wint_t charr1 = 0, charr2 = 0, charr3 = 0, charr4 = 0, charr6 = 0, charr7 = 0,
         charr8 = 0, charr9 = 0;
  ck_assert_int_eq(sscanf(input_line_0, "%5lc%*7c%lc%lc%lc%s", &charr1, &charr2,
                          &charr3, &charr4, endd1),
                   s21_sscanf(input_line_1, "%5lc%*7c%lc%lc%lc%s", &charr6,
                              &charr7, &charr8, &charr9, endd2));
  ck_assert_int_eq(charr1, charr6);
  ck_assert_int_eq(charr2, charr7);
  ck_assert_int_eq(charr3, charr8);
  ck_assert_int_eq(charr4, charr9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_char_and_long_char_20) {
  char input_line_0[] = "12456123456789023456 end\0";
  char input_line_1[90] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[20] = "start\0", endd2[20] = "start\0";
  wint_t charr1 = 0, charr2 = 0, charr3 = 0, charr4 = 0, charr6 = 0, charr7 = 0,
         charr8 = 0, charr9 = 0;
  ck_assert_int_eq(sscanf(input_line_0, "%5lc%*7c%lc%lc%lc%s", &charr1, &charr2,
                          &charr3, &charr4, endd1),
                   s21_sscanf(input_line_1, "%5lc%*7c%lc%lc%lc%s", &charr6,
                              &charr7, &charr8, &charr9, endd2));
  ck_assert_int_eq(charr1, charr6);
  ck_assert_int_eq(charr2, charr7);
  ck_assert_int_eq(charr3, charr8);
  ck_assert_int_eq(charr4, charr9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_char_and_long_char_21) {
  char input_line_0[] = "asdfqwert end\0";
  char input_line_1[90] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[20] = "start\0", endd2[20] = "start\0";
  char charr1 = 0, charr2 = 0, charr3 = 0, charr4 = 0, charr6 = 0, charr7 = 0,
       charr8 = 0, charr9 = 0;
  ck_assert_int_eq(sscanf(input_line_0, "%3c%c%c%c%s", &charr1, &charr2,
                          &charr3, &charr4, endd1),
                   s21_sscanf(input_line_1, "%3c%c%c%c%s", &charr6, &charr7,
                              &charr8, &charr9, endd2));
  ck_assert_int_eq(charr1, charr6);
  ck_assert_int_eq(charr2, charr7);
  ck_assert_int_eq(charr3, charr8);
  ck_assert_int_eq(charr4, charr9);
  ck_assert_str_eq(endd1, endd2);
}
/*
//does not work in my architecture
START_TEST(test_sscanf_char_and_long_char_2){
    char input_line_0[]="a s d f end\0";
    char input_line_1[90]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[20]="start\0",endd2[20]="start\0";
    char charr1=0,charr2=0,charr3=0,charr4=0,charr6=0,charr7=0, charr8=0,
charr9=0;
    ck_assert_int_eq(sscanf(input_line_0,"%c%c%c%c%s",&charr1,&charr2,&charr3,&charr4,
endd1),s21_sscanf(input_line_1,"%c%c%c%c%s",&charr6,&charr7,&charr8,&charr9,
endd2)); ck_assert_int_eq(charr1,charr6); ck_assert_int_eq(charr2,charr7);
    ck_assert_int_eq(charr3,charr8);
    ck_assert_int_eq(charr4,charr9);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_char_and_long_char_3){
    char input_line_0[]="as end\0";
    char input_line_1[90]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[20]="start\0",endd2[20]="start\0";
    char charr1=0,charr2=0,charr3=0,charr4=0,charr6=0,charr7=0, charr8=0,
charr9=0;
    ck_assert_int_eq(sscanf(input_line_0,"%c%c%c%c%s",&charr1,&charr2,&charr3,&charr4,
endd1),s21_sscanf(input_line_1,"%c%c%c%c%s",&charr6,&charr7,&charr8,&charr9,
endd2)); ck_assert_int_eq(charr1,charr6); ck_assert_int_eq(charr2,charr7);
    ck_assert_int_eq(charr3,charr8);
    ck_assert_int_eq(charr4,charr9);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_char_and_long_char_4){
    char input_line_0[]="asasd dff end\0";
    char input_line_1[90]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[20]="start\0",endd2[20]="start\0";
    char charr1=0,charr2=0,charr3=0,charr4=0,charr6=0,charr7=0, charr8=0,
charr9=0;
    ck_assert_int_eq(sscanf(input_line_0,"%5c%c%c%c%s",&charr1,&charr2,&charr3,&charr4,
endd1),s21_sscanf(input_line_1,"%5c%c%c%c%s",&charr6,&charr7,&charr8,&charr9,
endd2)); ck_assert_int_eq(charr1,charr6); ck_assert_int_eq(charr2,charr7);
    ck_assert_int_eq(charr3,charr8);
    ck_assert_int_eq(charr4,charr9);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_char_and_long_char_5){
    char input_line_0[]="asasd dsfdfffdssfd end\0";
    char input_line_1[90]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[20]="start\0",endd2[20]="start\0";
    char charr1=0,charr2=0,charr3=0,charr4=0,charr6=0,charr7=0, charr8=0,
charr9=0;
    ck_assert_int_eq(sscanf(input_line_0,"%5c%*7c%c%c%c%s",&charr1,&charr2,&charr3,&charr4,
endd1),s21_sscanf(input_line_1,"%5c%*7c%c%c%c%s",&charr6,&charr7,&charr8,&charr9,
endd2)); ck_assert_int_eq(charr1,charr6); ck_assert_int_eq(charr2,charr7);
    ck_assert_int_eq(charr3,charr8);
    ck_assert_int_eq(charr4,charr9);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_char_and_long_char_6){
    char input_line_0[]="asasd dsf1234567890 end\0";
    char input_line_1[90]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[20]="start\0",endd2[20]="start\0";
    char charr1=0,charr2=0,charr3=0,charr4=0,charr6=0,charr7=0, charr8=0,
charr9=0;
    ck_assert_int_eq(sscanf(input_line_0,"%5c%*7c%c%c%c%s",&charr1,&charr2,&charr3,&charr4,
endd1),s21_sscanf(input_line_1,"%5c%*7c%c%c%c%s",&charr6,&charr7,&charr8,&charr9,
endd2)); ck_assert_int_eq(charr1,charr6); ck_assert_int_eq(charr2,charr7);
    ck_assert_int_eq(charr3,charr8);
    ck_assert_int_eq(charr4,charr9);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_char_and_long_char_7){
    char
input_line_0[]={'1',1,'2',2,'3',3,'4',4,'5',5,'6',6,'7',7,'8',8,'9',14,'0',15,'z',16,'x',17,'c',18,'v',19,'b',20,'n',21,'m',22,'a',23,'s',24,'d',25,'f',26,'g',27,'h',28,'j',29,'k',30,'l',31,'q',32,'w','e'};
    char input_line_1[90]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[20]="start\0",endd2[20]="start\0";
    char charr1=0,charr2=0,charr3=0,charr4=0,charr6=0,charr7=0, charr8=0,
charr9=0;
    ck_assert_int_eq(sscanf(input_line_0,"%5c%*7c%c%c%c%s",&charr1,&charr2,&charr3,&charr4,
endd1),s21_sscanf(input_line_1,"%5c%*7c%c%c%c%s",&charr6,&charr7,&charr8,&charr9,
endd2)); ck_assert_int_eq(charr1,charr6); ck_assert_int_eq(charr2,charr7);
    ck_assert_int_eq(charr3,charr8);
    ck_assert_int_eq(charr4,charr9);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_char_and_long_char_9){
    char input_line_0[]="12434 5 45 1234567890 end\0";
    char input_line_1[90]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[20]="start\0",endd2[20]="start\0";
    char charr1=0,charr2=0,charr3=0,charr4=0,charr6=0,charr7=0, charr8=0,
charr9=0;
    ck_assert_int_eq(sscanf(input_line_0,"%5c%*7c%c%c%c%s",&charr1,&charr2,&charr3,&charr4,
endd1),s21_sscanf(input_line_1,"%5c%*7c%c%c%c%s",&charr6,&charr7,&charr8,&charr9,
endd2)); ck_assert_int_eq(charr1,charr6); ck_assert_int_eq(charr2,charr7);
    ck_assert_int_eq(charr3,charr8);
    ck_assert_int_eq(charr4,charr9);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_char_and_long_char_12){
    char input_line_0[]="a s d f end\0";
    char input_line_1[90]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[20]="start\0",endd2[20]="start\0";
    wint_t charr1=0,charr2=0,charr3=0,charr4=0,charr6=0,charr7=0, charr8=0,
charr9=0;
    ck_assert_int_eq(sscanf(input_line_0,"%lc%lc%lc%lc%s",&charr1,&charr2,&charr3,&charr4,
endd1),s21_sscanf(input_line_1,"%lc%lc%lc%lc%s",&charr6,&charr7,&charr8,&charr9,
endd2)); ck_assert_int_eq(charr1,charr6); ck_assert_int_eq(charr2,charr7);
    ck_assert_int_eq(charr3,charr8);
    ck_assert_int_eq(charr4,charr9);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_char_and_long_char_13){
    char input_line_0[]="as end\0";
    char input_line_1[90]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[20]="start\0",endd2[20]="start\0";
    wint_t charr1=0,charr2=0,charr3=0,charr4=0,charr6=0,charr7=0, charr8=0,
charr9=0;
    ck_assert_int_eq(sscanf(input_line_0,"%lc%lc%lc%lc%s",&charr1,&charr2,&charr3,&charr4,
endd1),s21_sscanf(input_line_1,"%lc%lc%lc%lc%s",&charr6,&charr7,&charr8,&charr9,
endd2)); ck_assert_int_eq(charr1,charr6); ck_assert_int_eq(charr2,charr7);
    ck_assert_int_eq(charr3,charr8);
    ck_assert_int_eq(charr4,charr9);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_char_and_long_char_14){
    char input_line_0[]="asasd dff end\0";
    char input_line_1[90]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[20]="start\0",endd2[20]="start\0";
    wint_t charr1=0,charr2=0,charr3=0,charr4=0,charr6=0,charr7=0, charr8=0,
charr9=0;
    ck_assert_int_eq(sscanf(input_line_0,"%5lc%lc%lc%lc%s",&charr1,&charr2,&charr3,&charr4,
endd1),s21_sscanf(input_line_1,"%5lc%lc%lc%lc%s",&charr6,&charr7,&charr8,&charr9,
endd2)); ck_assert_int_eq(charr1,charr6); ck_assert_int_eq(charr2,charr7);
    ck_assert_int_eq(charr3,charr8);
    ck_assert_int_eq(charr4,charr9);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_char_and_long_char_15){
    char input_line_0[]="asasd dsfdfffdssfd end\0";
    char input_line_1[90]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[20]="start\0",endd2[20]="start\0";
    wint_t charr1=0,charr2=0,charr3=0,charr4=0,charr6=0,charr7=0, charr8=0,
charr9=0;
    ck_assert_int_eq(sscanf(input_line_0,"%5lc%*7c%lc%lc%lc%s",&charr1,&charr2,&charr3,&charr4,
endd1),s21_sscanf(input_line_1,"%5lc%*7c%lc%lc%lc%s",&charr6,&charr7,&charr8,&charr9,
endd2)); ck_assert_int_eq(charr1,charr6); ck_assert_int_eq(charr2,charr7);
    ck_assert_int_eq(charr3,charr8);
    ck_assert_int_eq(charr4,charr9);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_char_and_long_char_16){
    char input_line_0[]="asasd dsf1234567890 end\0";
    char input_line_1[90]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[20]="start\0",endd2[20]="start\0";
    wint_t charr1=0,charr2=0,charr3=0,charr4=0,charr6=0,charr7=0, charr8=0,
charr9=0;
    ck_assert_int_eq(sscanf(input_line_0,"%5lc%*7c%lc%lc%lc%s",&charr1,&charr2,&charr3,&charr4,
endd1),s21_sscanf(input_line_1,"%5lc%*7c%lc%lc%lc%s",&charr6,&charr7,&charr8,&charr9,
endd2)); ck_assert_int_eq(charr1,charr6); ck_assert_int_eq(charr2,charr7);
    ck_assert_int_eq(charr3,charr8);
    ck_assert_int_eq(charr4,charr9);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_char_and_long_char_17){
    char
input_line_0[]={'1',1,'2',2,'3',3,'4',4,'5',5,'6',6,'7',7,'8',8,'9',14,'0',15,'z',16,'x',17,'c',18,'v',19,'b',20,'n',21,'m',22,'a',23,'s',24,'d',25,'f',26,'g',27,'h',28,'j',29,'k',30,'l',31,'q',32,'w','e'};
    char input_line_1[90]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[20]="start\0",endd2[20]="start\0";
    wint_t charr1=0,charr2=0,charr3=0,charr4=0,charr6=0,charr7=0, charr8=0,
charr9=0;
    ck_assert_int_eq(sscanf(input_line_0,"%5lc%*7c%lc%lc%lc%s",&charr1,&charr2,&charr3,&charr4,
endd1),s21_sscanf(input_line_1,"%5lc%*7c%lc%lc%lc%s",&charr6,&charr7,&charr8,&charr9,
endd2)); ck_assert_int_eq(charr1,charr6); ck_assert_int_eq(charr2,charr7);
    ck_assert_int_eq(charr3,charr8);
    ck_assert_int_eq(charr4,charr9);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_char_and_long_char_19){
    char input_line_0[]="12434 5 45 1234567890 end\0";
    char input_line_1[90]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[20]="start\0",endd2[20]="start\0";
    wint_t charr1=0,charr2=0,charr3=0,charr4=0,charr6=0,charr7=0, charr8=0,
charr9=0;
    ck_assert_int_eq(sscanf(input_line_0,"%5lc%*7c%lc%lc%lc%s",&charr1,&charr2,&charr3,&charr4,
endd1),s21_sscanf(input_line_1,"%5lc%*7c%lc%lc%lc%s",&charr6,&charr7,&charr8,&charr9,
endd2)); ck_assert_int_eq(charr1,charr6); ck_assert_int_eq(charr2,charr7);
    ck_assert_int_eq(charr3,charr8);
    ck_assert_int_eq(charr4,charr9);
    ck_assert_str_eq(endd1,endd2);
}
*/
// 9.21   //elevator
START_TEST(test_sscanf_string_and_long_string_1) {
  char input_line_0[] = "12434 5 45 1234567890 end\0";
  char input_line_1[90] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[20] = "start\0", endd2[20] = "start\0";
  char strr1[20] = "\0", strr2[20] = "\0", strr3[20] = "\0", strr4[20] = "\0",
       strr6[20] = "\0", strr7[20] = "\0", strr8[20] = "\0", strr9[20] = "\0";
  ck_assert_int_eq(
      sscanf(input_line_0, "%s%s%s%s%s", strr1, strr2, strr3, strr4, endd1),
      s21_sscanf(input_line_1, "%s%s%s%s%s", strr6, strr7, strr8, strr9,
                 endd2));
  ck_assert_str_eq(strr1, strr6);
  ck_assert_str_eq(strr2, strr7);
  ck_assert_str_eq(strr3, strr8);
  ck_assert_str_eq(strr4, strr9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_string_and_long_string_2) {
  char input_line_0[] = "12434dvs 5sdcsdc 4cdcs5 12345csdcssc67890 end\0";
  char input_line_1[90] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[20] = "start\0", endd2[20] = "start\0";
  char strr1[20] = "\0", strr2[20] = "\0", strr3[20] = "\0", strr4[20] = "\0",
       strr6[20] = "\0", strr7[20] = "\0", strr8[20] = "\0", strr9[20] = "\0";
  ck_assert_int_eq(
      sscanf(input_line_0, "%s%s%s%s%s", strr1, strr2, strr3, strr4, endd1),
      s21_sscanf(input_line_1, "%s%s%s%s%s", strr6, strr7, strr8, strr9,
                 endd2));
  ck_assert_str_eq(strr1, strr6);
  ck_assert_str_eq(strr2, strr7);
  ck_assert_str_eq(strr3, strr8);
  ck_assert_str_eq(strr4, strr9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_string_and_long_string_3) {
  char input_line_0[] = "12434dvs 5sdcsdc 4cdcs5 12345csd cssc67890 end\0";
  char input_line_1[90] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[20] = "start\0", endd2[20] = "start\0";
  char strr1[20] = "\0", strr2[20] = "\0", strr3[20] = "\0", strr4[20] = "\0",
       strr6[20] = "\0", strr7[20] = "\0", strr8[20] = "\0", strr9[20] = "\0";
  ck_assert_int_eq(
      sscanf(input_line_0, "%*s %s%s%s%s%s", strr1, strr2, strr3, strr4, endd1),
      s21_sscanf(input_line_1, "%*s %s%s%s%s%s", strr6, strr7, strr8, strr9,
                 endd2));
  ck_assert_str_eq(strr1, strr6);
  ck_assert_str_eq(strr2, strr7);
  ck_assert_str_eq(strr3, strr8);
  ck_assert_str_eq(strr4, strr9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_string_and_long_string_4) {
  char input_line_0[] = "12434dvs 5sdcsdc 4cdcs5 12345csd cssc67890 end\0";
  char input_line_1[90] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[20] = "start\0", endd2[20] = "start\0";
  char strr1[20] = "\0", strr2[20] = "\0", strr3[20] = "\0", strr4[20] = "\0",
       strr6[20] = "\0", strr7[20] = "\0", strr8[20] = "\0", strr9[20] = "\0";
  ck_assert_int_eq(sscanf(input_line_0, "%*s %3s%5s%6s%s%s", strr1, strr2,
                          strr3, strr4, endd1),
                   s21_sscanf(input_line_1, "%*s %3s%5s%6s%s%s", strr6, strr7,
                              strr8, strr9, endd2));
  ck_assert_str_eq(strr1, strr6);
  ck_assert_str_eq(strr2, strr7);
  ck_assert_str_eq(strr3, strr8);
  ck_assert_str_eq(strr4, strr9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_string_and_long_string_5) {
  char input_line_0[] = "12434dvs 5sdcsdc 4cdcs5 12345csd cssc67890 end\0";
  char input_line_1[90] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[20] = "start\0", endd2[20] = "start\0";
  char strr1[20] = "\0", strr2[20] = "\0", strr3[20] = "\0", strr4[20] = "\0",
       strr6[20] = "\0", strr7[20] = "\0", strr8[20] = "\0", strr9[20] = "\0";
  ck_assert_int_eq(sscanf(input_line_0, "%*s %10s%5s%6s%s%s", strr1, strr2,
                          strr3, strr4, endd1),
                   s21_sscanf(input_line_1, "%*s %10s%5s%6s%s%s", strr6, strr7,
                              strr8, strr9, endd2));
  ck_assert_str_eq(strr1, strr6);
  ck_assert_str_eq(strr2, strr7);
  ck_assert_str_eq(strr3, strr8);
  ck_assert_str_eq(strr4, strr9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_string_and_long_string_6) {
  char input_line_0[] = "12434dvs 5sdcsdc 4cdcs5 12345csd cssc67890 end\0";
  char input_line_1[90] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[20] = "start\0", endd2[20] = "start\0";
  char strr1[20] = "\0", strr2[20] = "\0", strr3[20] = "\0", strr4[20] = "\0",
       strr6[20] = "\0", strr7[20] = "\0", strr8[20] = "\0", strr9[20] = "\0";
  ck_assert_int_eq(sscanf(input_line_0, "%*5s %10s%5s%6s%s%s", strr1, strr2,
                          strr3, strr4, endd1),
                   s21_sscanf(input_line_1, "%*5s %10s%5s%6s%s%s", strr6, strr7,
                              strr8, strr9, endd2));
  ck_assert_str_eq(strr1, strr6);
  ck_assert_str_eq(strr2, strr7);
  ck_assert_str_eq(strr3, strr8);
  ck_assert_str_eq(strr4, strr9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_string_and_long_string_7) {
  char input_line_0[] = {'1', 1,  '2', 2,  '3', 3,  '4', 4,  '5', 5,  '6', 6,
                         '7', 7,  '8', 8,  '9', 14, '0', 15, 'z', 16, 'x', 17,
                         'c', 18, 'v', 19, 'b', 20, 'n', 21, 'm', 22, 'a', 23,
                         's', 24, 'd', 25, 'f', 26, 'g', 27, 'h', 28, 'j', 29,
                         'k', 30, 'l', 31, 'q', 32, 'w', 'e'};
  char input_line_1[90] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[20] = "start\0", endd2[20] = "start\0";
  char strr1[20] = "\0", strr2[20] = "\0", strr3[20] = "\0", strr4[20] = "\0",
       strr6[20] = "\0", strr7[20] = "\0", strr8[20] = "\0", strr9[20] = "\0";
  ck_assert_int_eq(sscanf(input_line_0, "%*5s %3s%4s%5s%6s%s", strr1, strr2,
                          strr3, strr4, endd1),
                   s21_sscanf(input_line_1, "%*5s %3s%4s%5s%6s%s", strr6, strr7,
                              strr8, strr9, endd2));
  ck_assert_str_eq(strr1, strr6);
  ck_assert_str_eq(strr2, strr7);
  ck_assert_str_eq(strr3, strr8);
  ck_assert_str_eq(strr4, strr9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_string_and_long_string_8) {
  char input_line_0[] = "12434 5 45 1234567890 end\0";
  char input_line_1[90] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[20] = "start\0", endd2[20] = "start\0";
  wchar_t strr1[20] = {'\0'}, strr2[20] = {'\0'}, strr3[20] = {'\0'},
          strr4[20] = {'\0'}, strr6[20] = {'\0'}, strr7[20] = {'\0'},
          strr8[20] = {'\0'}, strr9[20] = {'\0'};
  ck_assert_int_eq(
      sscanf(input_line_0, "%ls%ls%ls%ls%s", strr1, strr2, strr3, strr4, endd1),
      s21_sscanf(input_line_1, "%ls%ls%ls%ls%s", strr6, strr7, strr8, strr9,
                 endd2));

  int i = 0;
  for (; strr1[i] != '\0' || strr6[i] != '\0'; i++) {
    ck_assert_int_eq(strr1[i], strr6[i]);
  }
  ck_assert_int_eq(strr1[i], strr6[i]);
  i = 0;
  for (int i = 0; strr2[i] != '\0' || strr7[i] != '\0'; i++) {
    ck_assert_int_eq(strr2[i], strr7[i]);
  }
  ck_assert_int_eq(strr2[i], strr7[i]);
  i = 0;
  for (int i = 0; strr3[i] != '\0' || strr8[i] != '\0'; i++) {
    ck_assert_int_eq(strr3[i], strr8[i]);
  }
  ck_assert_int_eq(strr3[i], strr8[i]);
  i = 0;
  for (int i = 0; strr4[i] != '\0' || strr9[i] != '\0'; i++) {
    ck_assert_int_eq(strr4[i], strr9[i]);
  }
  ck_assert_int_eq(strr4[i], strr9[i]);

  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_string_and_long_string_9) {
  char input_line_0[] = "12434dvs 5sdcsdc 4cdcs5 12345csdcssc67890 end\0";
  char input_line_1[90] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[20] = "start\0", endd2[20] = "start\0";
  wchar_t strr1[20] = {'\0'}, strr2[20] = {'\0'}, strr3[20] = {'\0'},
          strr4[20] = {'\0'}, strr6[20] = {'\0'}, strr7[20] = {'\0'},
          strr8[20] = {'\0'}, strr9[20] = {'\0'};
  ck_assert_int_eq(
      sscanf(input_line_0, "%ls%ls%ls%ls%s", strr1, strr2, strr3, strr4, endd1),
      s21_sscanf(input_line_1, "%ls%ls%ls%ls%s", strr6, strr7, strr8, strr9,
                 endd2));

  int i = 0;
  for (; strr1[i] != '\0' || strr6[i] != '\0'; i++) {
    ck_assert_int_eq(strr1[i], strr6[i]);
  }
  ck_assert_int_eq(strr1[i], strr6[i]);
  i = 0;
  for (int i = 0; strr2[i] != '\0' || strr7[i] != '\0'; i++) {
    ck_assert_int_eq(strr2[i], strr7[i]);
  }
  ck_assert_int_eq(strr2[i], strr7[i]);
  i = 0;
  for (int i = 0; strr3[i] != '\0' || strr8[i] != '\0'; i++) {
    ck_assert_int_eq(strr3[i], strr8[i]);
  }
  ck_assert_int_eq(strr3[i], strr8[i]);
  i = 0;
  for (int i = 0; strr4[i] != '\0' || strr9[i] != '\0'; i++) {
    ck_assert_int_eq(strr4[i], strr9[i]);
  }
  ck_assert_int_eq(strr4[i], strr9[i]);

  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_string_and_long_string_10) {
  char input_line_0[] = "12434dvs 5sdcsdc 4cdcs5 12345csd cssc67890 end\0";
  char input_line_1[90] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[20] = "start\0", endd2[20] = "start\0";
  wchar_t strr1[20] = {'\0'}, strr2[20] = {'\0'}, strr3[20] = {'\0'},
          strr4[20] = {'\0'}, strr6[20] = {'\0'}, strr7[20] = {'\0'},
          strr8[20] = {'\0'}, strr9[20] = {'\0'};
  ck_assert_int_eq(sscanf(input_line_0, "%*s %ls%ls%ls%ls%s", strr1, strr2,
                          strr3, strr4, endd1),
                   s21_sscanf(input_line_1, "%*s %ls%ls%ls%ls%s", strr6, strr7,
                              strr8, strr9, endd2));

  int i = 0;
  for (; strr1[i] != '\0' || strr6[i] != '\0'; i++) {
    ck_assert_int_eq(strr1[i], strr6[i]);
  }
  ck_assert_int_eq(strr1[i], strr6[i]);
  i = 0;
  for (int i = 0; strr2[i] != '\0' || strr7[i] != '\0'; i++) {
    ck_assert_int_eq(strr2[i], strr7[i]);
  }
  ck_assert_int_eq(strr2[i], strr7[i]);
  i = 0;
  for (int i = 0; strr3[i] != '\0' || strr8[i] != '\0'; i++) {
    ck_assert_int_eq(strr3[i], strr8[i]);
  }
  ck_assert_int_eq(strr3[i], strr8[i]);
  i = 0;
  for (int i = 0; strr4[i] != '\0' || strr9[i] != '\0'; i++) {
    ck_assert_int_eq(strr4[i], strr9[i]);
  }
  ck_assert_int_eq(strr4[i], strr9[i]);

  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_string_and_long_string_11) {
  char input_line_0[] = "12434dvs 5sdcsdc 4cdcs5 12345csd cssc67890 end\0";
  char input_line_1[90] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[20] = "start\0", endd2[20] = "start\0";
  wchar_t strr1[20] = {'\0'}, strr2[20] = {'\0'}, strr3[20] = {'\0'},
          strr4[20] = {'\0'}, strr6[20] = {'\0'}, strr7[20] = {'\0'},
          strr8[20] = {'\0'}, strr9[20] = {'\0'};
  ck_assert_int_eq(sscanf(input_line_0, "%*s %3ls%5ls%6ls%ls%s", strr1, strr2,
                          strr3, strr4, endd1),
                   s21_sscanf(input_line_1, "%*s %3ls%5ls%6ls%ls%s", strr6,
                              strr7, strr8, strr9, endd2));

  int i = 0;
  for (; strr1[i] != '\0' || strr6[i] != '\0'; i++) {
    ck_assert_int_eq(strr1[i], strr6[i]);
  }
  ck_assert_int_eq(strr1[i], strr6[i]);
  i = 0;
  for (int i = 0; strr2[i] != '\0' || strr7[i] != '\0'; i++) {
    ck_assert_int_eq(strr2[i], strr7[i]);
  }
  ck_assert_int_eq(strr2[i], strr7[i]);
  i = 0;
  for (int i = 0; strr3[i] != '\0' || strr8[i] != '\0'; i++) {
    ck_assert_int_eq(strr3[i], strr8[i]);
  }
  ck_assert_int_eq(strr3[i], strr8[i]);
  i = 0;
  for (int i = 0; strr4[i] != '\0' || strr9[i] != '\0'; i++) {
    ck_assert_int_eq(strr4[i], strr9[i]);
  }
  ck_assert_int_eq(strr4[i], strr9[i]);

  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_string_and_long_string_12) {
  char input_line_0[] = "12434dvs 5sdcsdc 4cdcs5 12345csd cssc67890 end\0";
  char input_line_1[90] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[20] = "start\0", endd2[20] = "start\0";
  wchar_t strr1[20] = {'\0'}, strr2[20] = {'\0'}, strr3[20] = {'\0'},
          strr4[20] = {'\0'}, strr6[20] = {'\0'}, strr7[20] = {'\0'},
          strr8[20] = {'\0'}, strr9[20] = {'\0'};
  ck_assert_int_eq(sscanf(input_line_0, "%*s %10ls%5ls%6ls%ls%s", strr1, strr2,
                          strr3, strr4, endd1),
                   s21_sscanf(input_line_1, "%*s %10ls%5ls%6ls%ls%s", strr6,
                              strr7, strr8, strr9, endd2));

  int i = 0;
  for (; strr1[i] != '\0' || strr6[i] != '\0'; i++) {
    ck_assert_int_eq(strr1[i], strr6[i]);
  }
  ck_assert_int_eq(strr1[i], strr6[i]);
  i = 0;
  for (int i = 0; strr2[i] != '\0' || strr7[i] != '\0'; i++) {
    ck_assert_int_eq(strr2[i], strr7[i]);
  }
  ck_assert_int_eq(strr2[i], strr7[i]);
  i = 0;
  for (int i = 0; strr3[i] != '\0' || strr8[i] != '\0'; i++) {
    ck_assert_int_eq(strr3[i], strr8[i]);
  }
  ck_assert_int_eq(strr3[i], strr8[i]);
  i = 0;
  for (int i = 0; strr4[i] != '\0' || strr9[i] != '\0'; i++) {
    ck_assert_int_eq(strr4[i], strr9[i]);
  }
  ck_assert_int_eq(strr4[i], strr9[i]);

  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_string_and_long_string_13) {
  char input_line_0[] = "12434dvs 5sdcsdc 4cdcs5 12345csd cssc67890 end\0";
  char input_line_1[90] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[20] = "start\0", endd2[20] = "start\0";
  wchar_t strr1[20] = {'\0'}, strr2[20] = {'\0'}, strr3[20] = {'\0'},
          strr4[20] = {'\0'}, strr6[20] = {'\0'}, strr7[20] = {'\0'},
          strr8[20] = {'\0'}, strr9[20] = {'\0'};
  ck_assert_int_eq(sscanf(input_line_0, "%*5s %10ls%5ls%6ls%ls%s", strr1, strr2,
                          strr3, strr4, endd1),
                   s21_sscanf(input_line_1, "%*5s %10ls%5ls%6ls%ls%s", strr6,
                              strr7, strr8, strr9, endd2));

  int i = 0;
  for (; strr1[i] != '\0' || strr6[i] != '\0'; i++) {
    ck_assert_int_eq(strr1[i], strr6[i]);
  }
  ck_assert_int_eq(strr1[i], strr6[i]);
  i = 0;
  for (int i = 0; strr2[i] != '\0' || strr7[i] != '\0'; i++) {
    ck_assert_int_eq(strr2[i], strr7[i]);
  }
  ck_assert_int_eq(strr2[i], strr7[i]);
  i = 0;
  for (int i = 0; strr3[i] != '\0' || strr8[i] != '\0'; i++) {
    ck_assert_int_eq(strr3[i], strr8[i]);
  }
  ck_assert_int_eq(strr3[i], strr8[i]);
  i = 0;
  for (int i = 0; strr4[i] != '\0' || strr9[i] != '\0'; i++) {
    ck_assert_int_eq(strr4[i], strr9[i]);
  }
  ck_assert_int_eq(strr4[i], strr9[i]);

  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_string_and_long_string_14) {
  char input_line_0[] = {'1', 1,  '2', 2,  '3', 3,  '4', 4,  '5', 5,  '6', 6,
                         '7', 7,  '8', 8,  '9', 14, '0', 15, 'z', 16, 'x', 17,
                         'c', 18, 'v', 19, 'b', 20, 'n', 21, 'm', 22, 'a', 23,
                         's', 24, 'd', 25, 'f', 26, 'g', 27, 'h', 28, 'j', 29,
                         'k', 30, 'l', 31, 'q', 32, 'w', 'e'};
  char input_line_1[90] = "\0";
  strcpy(input_line_1, input_line_0);
  char endd1[20] = "start\0", endd2[20] = "start\0";
  wchar_t strr1[20] = {'\0'}, strr2[20] = {'\0'}, strr3[20] = {'\0'},
          strr4[20] = {'\0'}, strr6[20] = {'\0'}, strr7[20] = {'\0'},
          strr8[20] = {'\0'}, strr9[20] = {'\0'};
  ck_assert_int_eq(sscanf(input_line_0, "%*5s %3ls%4ls%5ls%6ls%s", strr1, strr2,
                          strr3, strr4, endd1),
                   s21_sscanf(input_line_1, "%*5s %3ls%4ls%5ls%6ls%s", strr6,
                              strr7, strr8, strr9, endd2));

  int i = 0;
  for (; strr1[i] != '\0' || strr6[i] != '\0'; i++) {
    ck_assert_int_eq(strr1[i], strr6[i]);
  }
  ck_assert_int_eq(strr1[i], strr6[i]);
  i = 0;
  for (int i = 0; strr2[i] != '\0' || strr7[i] != '\0'; i++) {
    ck_assert_int_eq(strr2[i], strr7[i]);
  }
  ck_assert_int_eq(strr2[i], strr7[i]);
  i = 0;
  for (int i = 0; strr3[i] != '\0' || strr8[i] != '\0'; i++) {
    ck_assert_int_eq(strr3[i], strr8[i]);
  }
  ck_assert_int_eq(strr3[i], strr8[i]);
  i = 0;
  for (int i = 0; strr4[i] != '\0' || strr9[i] != '\0'; i++) {
    ck_assert_int_eq(strr4[i], strr9[i]);
  }
  ck_assert_int_eq(strr4[i], strr9[i]);

  ck_assert_str_eq(endd1, endd2);
}
// 9.22   //elevator
START_TEST(test_sscanf_n_1) {
  char input_line_0[] =
      "12434dvs 5sdcsdc 4cdcs5 12345csd 55555  cssc67890 end\0";
  char format[] =
      "12434dvs 5sdcsdc 4cdcs5 %n%s  %d  \n\n  %ncssc67890    %n %s\0";
  char endd1[20] = "start\0", endd2[20] = "start\0";
  char strr1[20] = "\0", strr6[20] = "\0";
  int length1 = 1, length2 = 2, length3 = 3, length6 = 1, length7 = 2,
      length8 = 3;
  int intt1 = 6, intt6 = 6;
  ck_assert_int_eq(sscanf(input_line_0, format, &length1, strr1, &intt1,
                          &length2, &length3, endd1),
                   s21_sscanf(input_line_0, format, &length6, strr6, &intt6,
                              &length7, &length8, endd2));
  ck_assert_str_eq(strr1, strr6);
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(length1, length6);
  ck_assert_int_eq(length2, length7);
  ck_assert_int_eq(length3, length8);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_n_2) {
  char input_line_0[] =
      "12434dvs 5sdcsdc 4cdcs5 12345csd 55555  cssc67890 end\0";
  char format[] =
      "12434dvs 5sdcsdc 4cdcs5 %n%s  %d  \n\n  %5ncssc67890    %n %s\0";
  char endd1[20] = "start\0", endd2[20] = "start\0";
  char strr1[20] = "\0", strr6[20] = "\0";
  int length1 = 1, length2 = 2, length3 = 3, length6 = 1, length7 = 2,
      length8 = 3;
  int intt1 = 6, intt6 = 6;
  ck_assert_int_eq(sscanf(input_line_0, format, &length1, strr1, &intt1,
                          &length2, &length3, endd1),
                   s21_sscanf(input_line_0, format, &length6, strr6, &intt6,
                              &length7, &length8, endd2));
  ck_assert_str_eq(strr1, strr6);
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(length1, length6);
  ck_assert_int_eq(length2, length7);
  ck_assert_int_eq(length3, length8);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_n_3) {
  char input_line_0[] = {'1', 1,  '2', 2,  '3', 3,  '4', 4,  '5', 5,  '6', 6,
                         '7', 7,  '8', 8,  '9', 14, '0', 15, 'z', 16, 'x', 17,
                         'c', 18, 'v', 19, 'b', 20, 'n', 21, 'm', 22, 'a', 23,
                         's', 24, 'd', 25, 'f', 26, 'g', 27, 'h', 28, 'j', 29,
                         'k', 30, 'l', 31, 'q', 32, 'w', 'e'};
  char format[] = {'1', 1,   '2', 2,   '3', 3,   '4', 4,   '5', 5,   '6',
                   6,   '7', 7,   '8', 8,   '9', 14,  '%', 'n', '0', 15,
                   'z', 16,  'x', 17,  'c', '%', 'd', 'v', 19,  'b', 20,
                   'n', 21,  '%', 'n', 'm', 22,  'a', 23,  's', 24,  'd',
                   25,  'f', 26,  'g', 27,  'h', 28,  '%', 'n', 'j', 29,
                   'k', 30,  'l', 31,  'q', 32,  'w', 'e'};
  int length1 = 1, length2 = 2, length3 = 3, length6 = 1, length7 = 2,
      length8 = 3;
  int intt1 = 6, intt6 = 6;
  ck_assert_int_eq(
      sscanf(input_line_0, format, &length1, &intt1, &length2, &length3),
      s21_sscanf(input_line_0, format, &length6, &intt6, &length7, &length8));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(length1, length6);
  ck_assert_int_eq(length2, length7);
  ck_assert_int_eq(length3, length8);
}

// 9.23   //elevator
START_TEST(test_sscanf_strange_tests_1) {
  char input_line_0[] = "12434  54321 end \0";
  char format[] = " %*l*u %lu %s\0";
  char endd1[20] = "start\0", endd2[20] = "start\0";
  unsigned long int intt1 = 6, intt6 = 6;
  ck_assert_uint_eq(sscanf(input_line_0, format, &intt1, endd1),
                    s21_sscanf(input_line_0, format, &intt6, endd2));
  ck_assert_uint_eq(intt1, intt6);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_strange_tests_2) {
  char input_line_0[] = "12434.55  54321 end \0";
  char format[] = " %*5L3f %lu %s\0";
  char endd1[20] = "start\0", endd2[20] = "start\0";
  unsigned long int intt1 = 6, intt6 = 6;
  ck_assert_uint_eq(sscanf(input_line_0, format, &intt1, endd1),
                    s21_sscanf(input_line_0, format, &intt6, endd2));
  ck_assert_uint_eq(intt1, intt6);
  ck_assert_str_eq(endd1, endd2);
}
/*
START_TEST(test_sscanf_strange_tests_4) {
  char input_line_0[] = "12435435555556464621 end \0";
  char format[] = " %-5lu %s\0";
  char endd1[20] = "start\0", endd2[20] = "start\0";
  unsigned long int intt1 = 6, intt6 = 6;
  ck_assert_uint_eq(sscanf(input_line_0, format, &intt1, endd1),
                    s21_sscanf(input_line_0, format, &intt6, endd2));
  ck_assert_uint_eq(intt1, intt6);
  ck_assert_str_eq(endd1, endd2);
}
*/
START_TEST(test_sscanf_strange_tests_5) {
  char input_line_0[] = "1243543555 555646.4621 end \0";
  char format[] = " %0lu%0f %s\0";
  char endd1[20] = "start\0", endd2[20] = "start\0";
  unsigned long int intt1 = 6, intt6 = 6;
  float floatt1 = 1, floatt6 = 1;
  ck_assert_uint_eq(sscanf(input_line_0, format, &intt1, &floatt1, endd1),
                    s21_sscanf(input_line_0, format, &intt6, &floatt6, endd2));
  ck_assert_uint_eq(intt1, intt6);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_strange_tests_6) {
  char input_line_0[] = "1243.435 55556464621 end \0";
  char format[] = "  %*5Llf %5lu %s\0";
  char endd1[20] = "start\0", endd2[20] = "start\0";
  unsigned long int intt1 = 6, intt6 = 6;
  ck_assert_uint_eq(sscanf(input_line_0, format, &intt1, endd1),
                    s21_sscanf(input_line_0, format, &intt6, endd2));
  ck_assert_uint_eq(intt1, intt6);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_strange_tests_7) {
  char input_line_0[] = "1243.435 55556464621 end \0";
  char format[] = "  %*5fd %5lu %s\0";
  char endd1[20] = "start\0", endd2[20] = "start\0";
  unsigned long int intt1 = 6, intt6 = 6;
  ck_assert_uint_eq(sscanf(input_line_0, format, &intt1, endd1),
                    s21_sscanf(input_line_0, format, &intt6, endd2));
  ck_assert_uint_eq(intt1, intt6);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_strange_tests_8) {
  char input_line_0[] = "1243.435 55556464621 end \0";
  char format[] = " %*5Ld %5lu %s\0";
  char endd1[20] = "start\0", endd2[20] = "start\0";
  unsigned long int intt1 = 6, intt6 = 6;
  ck_assert_uint_eq(sscanf(input_line_0, format, &intt1, endd1),
                    s21_sscanf(input_line_0, format, &intt6, endd2));
  ck_assert_uint_eq(intt1, intt6);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_strange_tests_9) {
  char input_line_0[] = "-1243.435 55556464621 end \0";
  char format[] = "%1d %s\0";
  char endd1[20] = "start\0", endd2[20] = "start\0";
  int intt1 = 6, intt6 = 6;
  ck_assert_int_eq(sscanf(input_line_0, format, &intt1, endd1),
                   s21_sscanf(input_line_0, format, &intt6, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_strange_tests_10) {
  char input_line_0[] = "-1243.435 55556464621 end \0";
  char format[] = "%2d %s\0";
  char endd1[20] = "start\0", endd2[20] = "start\0";
  int intt1 = 6, intt6 = 6;
  ck_assert_int_eq(sscanf(input_line_0, format, &intt1, endd1),
                   s21_sscanf(input_line_0, format, &intt6, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_strange_tests_11) {
  char input_line_0[] = "0xa || 0xA || a || A  end \0";
  char format[] = "%x || %x || %x || %x %s\0";
  char endd1[20] = "start\0", endd2[20] = "start\0";
  int intt1 = 1, intt6 = 1, intt2 = 2, intt7 = 2, intt8 = 3, intt3 = 3,
      intt4 = 4, intt9 = 9;
  ck_assert_int_eq(
      sscanf(input_line_0, format, &intt1, &intt2, &intt3, &intt4, endd1),
      s21_sscanf(input_line_0, format, &intt6, &intt7, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
/*
START_TEST(test_sscanf_strange_tests_12) {
  char input_line_0[] = "0xa || 0xA || a || a  end \0";
  char format[] = "%2x || %1x || %2x || %1x %s\0";
  char endd1[20] = "start\0", endd2[20] = "start\0";
  int intt1 = 1, intt6 = 1, intt2 = 2, intt7 = 2, intt8 = 3, intt3 = 3,
      intt4 = 4, intt9 = 4;
  ck_assert_int_eq(
      sscanf(input_line_0, format, &intt1, &intt2, &intt3, &intt4, endd1),
      s21_sscanf(input_line_0, format, &intt6, &intt7, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
*/
START_TEST(test_sscanf_strange_tests_13) {
  char input_line_0[] = "0xa || 0xA || a || a  end \0";
  char format[] = "\0";
  char endd1[20] = "start\0", endd2[20] = "start\0";
  int intt1 = 1, intt6 = 1, intt2 = 2, intt7 = 2, intt8 = 3, intt3 = 3,
      intt4 = 4, intt9 = 4;
  ck_assert_int_eq(
      sscanf(input_line_0, format, &intt1, &intt2, &intt3, &intt4, endd1),
      s21_sscanf(input_line_0, format, &intt6, &intt7, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
/*
START_TEST(test_sscanf_strange_tests_14) {
  char input_line_0[] = "0xa || 0xA || a || a  end \0";
  char format[] = "%2x || %1x || %2x || %1x %s\0";
  char endd1[20] = "start\0", endd2[20] = "start\0";
  int intt1 = 1, intt6 = 1, intt2 = 2, intt7 = 2, intt8 = 3, intt3 = 3,
      intt4 = 4, intt9 = 4;
  ck_assert_int_eq(sscanf(input_line_0, format, &intt1),
                   s21_sscanf(input_line_0, format, &intt6));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_strange_tests_15) {
  char input_line_0[] = "0xa || 0xA || a || a  end \0";
  char format[] = "%2x || %1x || %2x || %1x %s\0";
  char endd1[20] = "start\0", endd2[20] = "start\0";
  int intt1 = 1, intt6 = 1, intt2 = 2, intt7 = 2, intt8 = 3, intt3 = 3,
      intt4 = 4, intt9 = 4;
  ck_assert_int_eq(
      sscanf(input_line_0, format, &intt1, &intt2, &intt3, &intt4),
      s21_sscanf(input_line_0, format, &intt6, &intt7, &intt8, &intt9));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
*/
START_TEST(test_sscanf_strange_tests_16) {
  char input_line_0[] = " 0xa || 0xA || a || A  end \0";
  char format[] = "%x || %x || %x || %x\0";
  char endd1[20] = "start\0", endd2[20] = "start\0";
  int intt1 = 1, intt6 = 1, intt2 = 2, intt7 = 2, intt8 = 3, intt3 = 3,
      intt4 = 4, intt9 = 4;
  ck_assert_int_eq(
      sscanf(input_line_0, format, &intt2, &intt1, &intt3, &intt4, endd1),
      sscanf(input_line_0, format, &intt7, &intt6, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
/*
START_TEST(test_sscanf_strange_tests_19) {
  char input_line_0[] = "0.5e ||  0.5e2  || 100.5 || 0.5EE2  end \0";
  char format[] = "%f || %f || %f || %f %s\0";
  char endd1[20] = "start\0", endd2[20] = "start\0";
  float floatt1 = 1, floatt6 = 1, floatt2 = 2, floatt7 = 2, floatt8 = 3,
        floatt3 = 3, floatt4 = 4, floatt9 = 9;
  ck_assert_int_eq(sscanf(input_line_0, format, &floatt1, &floatt2, &floatt3,
                          &floatt4, endd1),
                   s21_sscanf(input_line_0, format, &floatt6, &floatt7,
                              &floatt8, &floatt9, endd2));
  ck_assert_float_eq(floatt1, floatt6);
  ck_assert_float_eq(floatt2, floatt7);
  ck_assert_float_eq(floatt3, floatt8);
  ck_assert_float_eq(floatt4, floatt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_strange_tests_21) {
  char input_line_0[] = "0.5e || end \0";
  char format[] = "%f || %s\0";
  char endd1[20] = "start\0", endd2[20] = "start\0";
  float floatt1 = 1, floatt6 = 1;
  ck_assert_int_eq(sscanf(input_line_0, format, &floatt1, endd1),
                   s21_sscanf(input_line_0, format, &floatt6, endd2));
  ck_assert_float_eq(floatt1, floatt6);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_strange_tests_24) {
  char input_line_0[] = "0.5e \0";
  char format[] = "%f %s %s %s\0";
  char endd1[20] = "start\0", endd2[20] = "start\0";
  char strr1[10] = "\0", strr6[10] = "\0", strr2[10] = "\0", strr7[10] = "\0";
  float floatt1 = 1, floatt6 = 1;
  ck_assert_int_eq(
      sscanf(input_line_0, format, &floatt1, strr1, strr2, endd1),
      s21_sscanf(input_line_0, format, &floatt6, strr6, strr7, endd2));
  ck_assert_float_eq(floatt1, floatt6);
  ck_assert_str_eq(strr1, strr6);
  ck_assert_str_eq(strr2, strr7);
  ck_assert_str_eq(endd1, endd2);
}
*/
START_TEST(test_sscanf_strange_tests_25) {
  char input_line_0[] = "apple 0.5e || end \0";
  char format[] = "bpple %f || %s\0";
  char endd1[20] = "start\0", endd2[20] = "start\0";
  float floatt1 = 1, floatt6 = 1;
  ck_assert_int_eq(sscanf(input_line_0, format, &floatt1, endd1),
                   s21_sscanf(input_line_0, format, &floatt6, endd2));
  ck_assert_float_eq(floatt1, floatt6);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_strange_tests_26) {
  char input_line_0[] = "     0.5e || end \0";
  char format[] = {1,  2,   3,   4,   5,   6,   7,   8,
                   14, '%', 'f', '|', '|', '%', 's', '\0'};
  char endd1[20] = "start\0", endd2[20] = "start\0";
  float floatt1 = 1, floatt6 = 1;
  ck_assert_int_eq(sscanf(input_line_0, format, &floatt1, endd1),
                   s21_sscanf(input_line_0, format, &floatt6, endd2));
  ck_assert_float_eq(floatt1, floatt6);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_strange_tests_28) {
  char input_line_0[] = "apple 0.5e || end \0";
  char format[] = "bpple %d || %s\0";
  char endd1[20] = "start\0", endd2[20] = "start\0";
  float floatt1 = 1, floatt6 = 1;
  ck_assert_int_eq(sscanf(input_line_0, format, &floatt1, endd1),
                   s21_sscanf(input_line_0, format, &floatt6, endd2));
  ck_assert_float_eq(floatt1, floatt6);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_strange_tests_30) {
  char input_line_0[] =
      "0x7ffdd251f78c || f78c || 0xf78c || 0x7ffdd251f78c  end \0";
  char format[] = "%p || %p || %p || %p %s\0";
  char endd1[20] = "start\0", endd2[20] = "start\0";
  int *intt1 = NULL, *intt6 = NULL, *intt2 = NULL, *intt7 = NULL, *intt8 = NULL,
      *intt3 = NULL, *intt4 = NULL, *intt9 = NULL;
  ck_assert_int_eq(
      sscanf(input_line_0, format, &intt1, &intt2, &intt3, &intt4, endd1),
      s21_sscanf(input_line_0, format, &intt6, &intt7, &intt8, &intt9, endd2));
  ck_assert_ptr_eq(intt1, intt6);
  ck_assert_ptr_eq(intt2, intt7);
  ck_assert_ptr_eq(intt3, intt8);
  ck_assert_ptr_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_strange_tests_31) {
  char input_line_0[] = "010 || 10 || 0x10 || 10A  end \0";
  char format[] = "%i || %i || %i || %i %s\0";
  char endd1[20] = "start\0", endd2[20] = "start\0";
  int intt1 = 1, intt6 = 1, intt2 = 2, intt7 = 2, intt8 = 3, intt3 = 3,
      intt4 = 4, intt9 = 4;
  ck_assert_int_eq(
      sscanf(input_line_0, format, &intt1, &intt2, &intt3, &intt4, endd1),
      s21_sscanf(input_line_0, format, &intt6, &intt7, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_strange_tests_32) {
  char input_line_0[] = "-010 || -0X10 || -10 || 10a  end \0";
  char format[] = "%i || %i || %i || %i %s\0";
  char endd1[20] = "start\0", endd2[20] = "start\0";
  int intt1 = 1, intt6 = 1, intt2 = 2, intt7 = 2, intt8 = 3, intt3 = 3,
      intt4 = 4, intt9 = 4;
  ck_assert_int_eq(
      sscanf(input_line_0, format, &intt1, &intt2, &intt3, &intt4, endd1),
      s21_sscanf(input_line_0, format, &intt6, &intt7, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_strange_tests_33) {
  char input_line_0[] = "-010 || -0X10 || -10 || 10a  end \0";
  char format[] = "%i || %i || %*i %*n || %i %s\0";
  char endd1[20] = "start\0", endd2[20] = "start\0";
  int intt1 = 1, intt6 = 1, intt2 = 2, intt7 = 2, intt4 = 4, intt9 = 4;
  ck_assert_int_eq(
      sscanf(input_line_0, format, &intt1, &intt2, &intt4, endd1),
      s21_sscanf(input_line_0, format, &intt6, &intt7, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt2, intt7);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_strange_tests_41) {
  char input_line_0[] = "-010 || -0X10 || -10 || 10a  end \0";
  char format[] = "%i || %  %*i || %i || %i %s\0";
  char endd1[20] = "start\0", endd2[20] = "start\0";
  int intt1 = 1, intt6 = 1, intt8 = 3, intt3 = 3, intt4 = 4, intt9 = 4;
  ck_assert_int_eq(
      sscanf(input_line_0, format, &intt1, &intt3, &intt4, endd1),
      s21_sscanf(input_line_0, format, &intt6, &intt8, &intt9, endd2));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_int_eq(intt3, intt8);
  ck_assert_int_eq(intt4, intt9);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_strange_tests_35) {
  char input_line_0[] = ".5 || end \0";
  char format[] = "%f || %s\0";
  char endd1[20] = "start\0", endd2[20] = "start\0";
  float floatt1 = 1, floatt6 = 1;
  ck_assert_int_eq(sscanf(input_line_0, format, &floatt1, endd1),
                   s21_sscanf(input_line_0, format, &floatt6, endd2));
  ck_assert_float_eq(floatt1, floatt6);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_strange_tests_36) {
  char input_line_0[] = "-0.5 || end \0";
  char format[] = "%0f || %s\0";
  char endd1[20] = "start\0", endd2[20] = "start\0";
  float floatt1 = 1, floatt6 = 1;
  ck_assert_int_eq(sscanf(input_line_0, format, &floatt1, endd1),
                   s21_sscanf(input_line_0, format, &floatt6, endd2));
  ck_assert_float_eq(floatt1, floatt6);
  ck_assert_str_eq(endd1, endd2);
}
/*
START_TEST(test_sscanf_strange_tests_37) {
  char input_line_0[] = "-0x5 ||  end \0";
  char format[] = "%3x ||  %s\0";
  char endd1[20] = "start\0", endd2[20] = "start\0";
  int intt1 = 1, intt6 = 1;
  ck_assert_int_eq(sscanf(input_line_0, format, &intt1),
                   s21_sscanf(input_line_0, format, &intt6));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_str_eq(endd1, endd2);
}
*/
START_TEST(test_sscanf_strange_tests_39) {
  char input_line_0[] = "-g  ||  end \0";
  char format[] = "%3x ||  %s\0";
  char endd1[20] = "start\0", endd2[20] = "start\0";
  int intt1 = 1, intt6 = 1;
  ck_assert_int_eq(sscanf(input_line_0, format, &intt1),
                   s21_sscanf(input_line_0, format, &intt6));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_strange_tests_38) {
  char input_line_0[] = "-a65  ||  end \0";
  char format[] = "%3x ||  %s\0";
  char endd1[20] = "start\0", endd2[20] = "start\0";
  int intt1 = 1, intt2 = 1;
  ck_assert_int_eq(sscanf(input_line_0, format, &intt1),
                   s21_sscanf(input_line_0, format, &intt2));
  ck_assert_int_eq(intt1, intt2);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_strange_tests_40) {
  char input_line_0[] = "\0";
  char format[] = "%3x ||  %s\0";
  char endd1[20] = "start\0", endd2[20] = "start\0";
  int intt1 = 1, intt6 = 1;
  ck_assert_int_eq(sscanf(input_line_0, format, &intt1),
                   s21_sscanf(input_line_0, format, &intt6));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_strange_tests_42) {
  char input_line_0[] = "hello\0";
  char* format = "\0";
  char endd1[20] = "start\0", endd2[20] = "start\0";
  int intt1 = 1, intt6 = 1;
  ck_assert_int_eq(sscanf(input_line_0, format, &intt1),
                   s21_sscanf(input_line_0, format, &intt6));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_str_eq(endd1, endd2);
}
/*
START_TEST(test_sscanf_strange_tests_0) {
  char input_line_0[] = "hello\0";
  char* format = NULL;
  char endd1[20] = "start\0", endd2[20] = "start\0";
  int intt1 = 1, intt6 = 1;
  ck_assert_int_eq(sscanf(input_line_0, format, &intt1),
                   s21_sscanf(input_line_0, format, &intt6));
  ck_assert_int_eq(intt1, intt6);
  ck_assert_str_eq(endd1, endd2);
}
*/
START_TEST(test_sscanf_cov_test_1) {
  char input_line_0[] = "  +.3e3 end\0";
  char format[] = "%f  %s\0";
  char endd1[20] = "start\0", endd2[20] = "start\0";
  float floatt1 = 1, floatt6 = 1;
  ck_assert_int_eq(sscanf(input_line_0, format, &floatt1, endd1),
                   s21_sscanf(input_line_0, format, &floatt6, endd2));
  ck_assert_float_eq(floatt1, floatt6);
  ck_assert_str_eq(endd1, endd2);
}
/*
START_TEST(test_sscanf_cov_test_2) {
  char input_line_0[] = "  +0x  end\0";
  char format[] = "%x  %s\0";
  char endd1[20] = "start\0", endd2[20] = "start\0";
  int intt1 = 1, intt6 = 1;
  ck_assert_int_eq(sscanf(input_line_0, format, &intt1, endd1),
                   s21_sscanf(input_line_0, format, &intt6, endd2));
  ck_assert_int_eq(intt1,intt6);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_cov_test_3) {
  char input_line_0[] = "  +.3e3 end\0";
  char format[] = "%hf  %s\0";
  char endd1[20] = "start\0", endd2[20] = "start\0";
  float floatt1 = 1, floatt6 = 1;
  //ck_assert_int_eq(sscanf(input_line_0, format, &floatt1, endd1),
s21_sscanf(input_line_0, format, &floatt6, endd2)); sscanf(input_line_0, format,
&floatt1, endd1); s21_sscanf(input_line_0, format, &floatt6, endd2);
  ck_assert_float_eq(floatt1, floatt6);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_cov_test_4) {
  char input_line_0[] = "  +.3e3 end\0";
  char format[] = "%hc  %s\0";
  char endd1[20] = "start\0", endd2[20] = "start\0";
  float floatt1 = 1, floatt6 = 1;
  ck_assert_int_eq(sscanf(input_line_0, format, &floatt1, endd1),
                   s21_sscanf(input_line_0, format, &floatt6, endd2));
  ck_assert_float_eq(floatt1, floatt6);
  ck_assert_str_eq(endd1, endd2);
}
*/
START_TEST(test_sscanf_cov_test_5) {
  char input_line_0[] = "  +.3e3 end\0";
  char format[] = "%g  %s\0";
  char endd1[20] = "start\0", endd2[20] = "start\0";
  float floatt1 = 1, floatt6 = 1;
  ck_assert_int_eq(sscanf(input_line_0, format, &floatt1, endd1),
                   s21_sscanf(input_line_0, format, &floatt6, endd2));
  ck_assert_float_eq(floatt1, floatt6);
  ck_assert_str_eq(endd1, endd2);
}
START_TEST(test_sscanf_cov_test_6) {
  char input_line_0[] = "  +.3e3 end\0";
  char format[] = "%lp  %s\0";
  char endd1[20] = "start\0", endd2[20] = "start\0";
  float floatt1 = 1, floatt6 = 1;
  ck_assert_int_eq(sscanf(input_line_0, format, &floatt1, endd1),
                   s21_sscanf(input_line_0, format, &floatt6, endd2));
  ck_assert_float_eq(floatt1, floatt6);
  ck_assert_str_eq(endd1, endd2);
}

// elevator

START_TEST(test_spritf_c) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%c";
  char c = 21;
  int expected = sprintf(buff_exp, format, c);
  int result = s21_sprintf(buff_res, format, c);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_d) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%d";
  int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_d_len) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%10d";
  int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_d_acc) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%.10d";
  int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_d_len_acc1) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%20.10d";
  int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_d_len_acc2) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%10.20d";
  int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_d_len_acc_neg) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%-20.10d";
  int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_d_len_acc_plus) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%+20.10d";
  int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_d_len_acc_space) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "% 20.10d";
  int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_d_len_acc_neg_plus) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%-+20.10d";
  int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_d_len_acc_neg_space) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%- 20.10d";
  int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_ld) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%ld";
  long int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_ld_len) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%10ld";
  long int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_ld_acc) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%.10ld";
  long int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_ld_len_acc1) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%20.10ld";
  long int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_ld_len_acc2) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%10.20ld";
  long int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_ld_len_acc_neg) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%-20.10ld";
  long int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_ld_len_acc_plus) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%+20.10ld";
  long int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_ld_len_acc_space) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "% 20.10ld";
  long int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_ld_len_acc_neg_plus) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%-+20.10ld";
  long int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_ld_len_acc_neg_space) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%- 20.10ld";
  long int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_hd) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%hd";
  short int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_hd_len) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%10hd";
  short int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_hd_acc) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%.10hd";
  short int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_hd_len_acc1) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%20.10hd";
  short int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_hd_len_acc2) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%10.20hd";
  short int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_hd_len_acc_neg) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%-20.10hd";
  short int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_hd_len_acc_plus) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%+20.10hd";
  short int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_hd_len_acc_space) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "% 20.10hd";
  short int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_hd_len_acc_neg_plus) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%-+20.10hd";
  short int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_hd_len_acc_neg_space) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%- 20.10hd";
  short int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_f) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%f";
  float f = 21.123123123123;
  int expected = sprintf(buff_exp, format, f);
  int result = s21_sprintf(buff_res, format, f);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_f_neg) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%f";
  float f = -21.123123123123;
  int expected = sprintf(buff_exp, format, f);
  int result = s21_sprintf(buff_res, format, f);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_f_len) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%10f";
  float f = 21.123123123123;
  int expected = sprintf(buff_exp, format, f);
  int result = s21_sprintf(buff_res, format, f);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_f_acc) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%.10f";
  float f = 21.123123123123;
  int expected = sprintf(buff_exp, format, f);
  int result = s21_sprintf(buff_res, format, f);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_f_len_acc1) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%20.10f";
  float f = 21.123123123123;
  int expected = sprintf(buff_exp, format, f);
  int result = s21_sprintf(buff_res, format, f);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_f_len_acc2) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%10.20f";
  float f = 21.123123123123;
  int expected = sprintf(buff_exp, format, f);
  int result = s21_sprintf(buff_res, format, f);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_f_len_acc_neg) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%-20.10f";
  float f = 21.123123123123;
  int expected = sprintf(buff_exp, format, f);
  int result = s21_sprintf(buff_res, format, f);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_f_len_acc_plus) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%+20.10f";
  float f = 21.123123123123;
  int expected = sprintf(buff_exp, format, f);
  int result = s21_sprintf(buff_res, format, f);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_f_len_acc_space) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "% 20.10f";
  float f = 21.123123123123;
  int expected = sprintf(buff_exp, format, f);
  int result = s21_sprintf(buff_res, format, f);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_f_len_acc_neg_plus) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%-+20.10f";
  float f = 21.123123123123;
  int expected = sprintf(buff_exp, format, f);
  int result = s21_sprintf(buff_res, format, f);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_f_len_acc_neg_space) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%- 20.10f";
  float f = 21.123123123123;
  int expected = sprintf(buff_exp, format, f);
  int result = s21_sprintf(buff_res, format, f);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_s) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%s";
  ;
  char s[] = "SCHOOL21!:)";
  ;
  int expected = sprintf(buff_exp, format, s);
  int result = s21_sprintf(buff_res, format, s);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_u) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%u";
  unsigned int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_u_len) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%10u";
  unsigned int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_u_acc) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%.10u";
  unsigned int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_u_len_acc1) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%20.10u";
  unsigned int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_u_len_acc2) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%10.20u";
  unsigned int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_u_len_acc_neg) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%-20.10u";
  unsigned int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_u_len_acc_plus) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%+20.10u";
  unsigned int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_u_len_acc_space) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "% 20.10u";
  unsigned int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_u_len_acc_neg_plus) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%-+20.10u";
  unsigned int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_u_len_acc_neg_space) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%- 20.10u";
  unsigned int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_lu) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%lu";
  unsigned long int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_lu_len) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%10lu";
  unsigned long int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_lu_acc) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%.10lu";
  unsigned long int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_lu_len_acc1) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%20.10lu";
  unsigned long int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_lu_len_acc2) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%10.20lu";
  unsigned long int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_lu_len_acc_neg) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%-20.10lu";
  unsigned long int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_lu_len_acc_plus) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%+20.10lu";
  unsigned long int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_lu_len_acc_space) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "% 20.10lu";
  unsigned long int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_lu_len_acc_neg_plus) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%-+20.10lu";
  unsigned long int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_lu_len_acc_neg_space) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%- 20.10lu";
  unsigned long int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_hu) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%hu";
  unsigned short int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_hu_len) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%10hu";
  unsigned short int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_hu_acc) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%.10hu";
  unsigned short int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_hu_len_acc1) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%20.10hu";
  unsigned short int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_hu_len_acc2) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%10.20hu";
  unsigned short int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_hu_len_acc_neg) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%-20.10hu";
  unsigned short int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_hu_len_acc_plus) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%+20.10hu";
  unsigned short int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_hu_len_acc_space) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "% 20.10hu";
  unsigned short int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_hu_len_acc_neg_plus) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%-+20.10hu";
  unsigned short int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_hu_len_acc_neg_space) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%- 20.10hu";
  unsigned short int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_multi) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%c %d %f %u %s";
  char c = 'c';
  int d = 123;
  float f = 123.123123123;
  unsigned int u = -123;
  char s[] = "hello :)";
  int expected = sprintf(buff_exp, format, c, d, f, u, s);
  int result = s21_sprintf(buff_res, format, c, d, f, u, s);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}
START_TEST(test_spritf_d_neg) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%d";
  int d = -21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_spritf_per) {
  char buff_exp[100] = {0};
  char buff_res[100] = {0};
  char format[] = "%% %d";
  int d = 21;
  int expected = sprintf(buff_exp, format, d);
  int result = s21_sprintf(buff_res, format, d);
  ck_assert_int_eq(result, expected);
  ck_assert_str_eq(buff_res, buff_exp);
}

START_TEST(test_to_upper) {
  char str[] = "hello";
  char* result = s21_to_upper(str);
  char* expected = "HELLO";
  ck_assert_str_eq(result, expected);
  free(result);
}

START_TEST(test_to_upper2) {
  char str[] = "hElLo";
  char* result = s21_to_upper(str);
  char* expected = "HELLO";
  ck_assert_str_eq(result, expected);
  free(result);
}

START_TEST(test_to_upper3) {
  char str[] =
      "`1234567890-=	"
      "qwertyuiop[]\\asdfghjkl;'zxcvbnm,./`1234567890-=	"
      "QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./~";
  char* result = s21_to_upper(str);
  char* expected =
      "`1234567890-=	"
      "QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./`1234567890-=	"
      "QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./~";
  ck_assert_str_eq(result, expected);
  free(result);
}

START_TEST(test_to_upper_empty) {
  char* str = "";
  char* result = s21_to_upper(str);
  char* expected = "";
  ck_assert_str_eq(result, expected);
  free(result);
}

START_TEST(test_to_lower) {
  char str[] = "HELLO";
  char* result = s21_to_lower(str);
  char* expected = "hello";
  ck_assert_str_eq(result, expected);
  free(result);
}

START_TEST(test_to_lower2) {
  char str[] = "hElLo";
  char* result = s21_to_lower(str);
  char* expected = "hello";
  ck_assert_str_eq(result, expected);
  free(result);
}

START_TEST(test_to_lower3) {
  char str[] =
      "`1234567890-=	"
      "qwertyuiop[]\\asdfghjkl;'zxcvbnm,./`1234567890-=	"
      "QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./~";
  char* result = s21_to_lower(str);
  char* expected =
      "`1234567890-=	"
      "qwertyuiop[]\\asdfghjkl;'zxcvbnm,./`1234567890-=	"
      "qwertyuiop[]\\asdfghjkl;'zxcvbnm,./~";
  ck_assert_str_eq(result, expected);
  free(result);
}

START_TEST(test_to_lower_empty) {
  const char* str = "";
  char* result = s21_to_lower(str);
  char* expected = "";
  ck_assert_str_eq(result, expected);
  free(result);
}

START_TEST(test_insert1) {
  char str1[] = "123";
  char str2[] = "hello";
  char* result = s21_insert(str1, str2, 2);
  char* expected = "12hello3";
  ck_assert_str_eq(result, expected);
  free(result);
}

START_TEST(test_insert2) {
  char str1[] = "123";
  char str2[] = "hello";
  char* result = s21_insert(str1, str2, -1);
  char* expected = NULL;
  ck_assert_ptr_eq(result, expected);
}

START_TEST(test_insert3) {
  char str1[] = "123";
  char str2[] = "hello";
  char* result = s21_insert(str1, str2, 123);
  char* expected = NULL;
  ck_assert_ptr_eq(result, expected);
}

START_TEST(test_insert4) {
  const char* str1 = "";
  char str2[] = "hello";
  char* result = s21_insert(str1, str2, 0);
  char* expected = "hello";
  ck_assert_str_eq(result, expected);
  free(result);
}

START_TEST(test_trim1) {
  char str1[] = "hello there dude!";
  char str2[] = "heled!";
  char* result = s21_trim(str1, str2);
  char* expected = "o there du";
  ck_assert_str_eq(result, expected);
  free(result);
}

START_TEST(test_trim2) {
  char str1[] = "hello there dude!";
  char str2[] = "te";
  char* result = s21_trim(str1, str2);
  char* expected = "hello there dude!";
  ck_assert_str_eq(result, expected);
  free(result);
}

START_TEST(test_trim3) {
  char str1[] = "hello";
  char str2[] = "olleh";
  char* result = s21_trim(str1, str2);
  char* expected = "";
  ck_assert_str_eq(result, expected);
  free(result);
}

START_TEST(test_trim4) {
  char str1[] = "hello";
  char str2[] = "hello";
  char* result = s21_trim(str1, str2);
  char* expected = "";
  ck_assert_str_eq(result, expected);
  free(result);
}

START_TEST(test_trim5) {
  char str1[] = "";
  char str2[] = "hello";
  char* result = s21_trim(str1, str2);
  char* expected = "";
  ck_assert_str_eq(result, expected);
  free(result);
}

START_TEST(test_trim6) {
  char str1[] = "a";
  char str2[] = "aaa";
  char* result = s21_trim(str1, str2);
  char* expected = "";
  ck_assert_str_eq(result, expected);
  free(result);
}

START_TEST(test_trim7) {
  char str1[] = "hello";
  char str2[] = "";
  char* result = s21_trim(str1, str2);
  char* expected = "hello";
  ck_assert_str_eq(result, expected);
  free(result);
}

START_TEST(test_trim8) {
  char str1[] = "ab";
  char str2[] = "a";
  char* result = s21_trim(str1, str2);
  char* expected = "b";
  ck_assert_str_eq(result, expected);
  free(result);
}

START_TEST(test_strerror) {
  char* result = s21_strerror(10);
  char* expected = strerror(10);
  ck_assert_str_eq(result, expected);
}

START_TEST(test_strerror2) {
  char* result = s21_strerror(1000);
  char* expected = strerror(1000);
  ck_assert_str_eq(result, expected);
}

START_TEST(test_strerror3) {
  char* result = s21_strerror(-1);
  char* expected = strerror(-1);
  ck_assert_str_eq(result, expected);
}
// elevator
START_TEST(test_fixing_insert_1) {
  const char* src = "hello\0";
  char str[] = "ass\0";
  int position=3;
  char* result = s21_insert(src, str, position);
  char* expected = "helasslo\0";
  ck_assert_pstr_eq(result, expected);
  free(result);
  // printf("here\n");
}
START_TEST(test_fixing_insert_2) {
  const char* src = "hello\0";
  char str[] = "ass\0";
  int position=6;
  char* result = s21_insert(src, str, position);
  char* expected = NULL;
  ck_assert_pstr_eq(result, expected);
  free(result);
  // printf("here\n");
}
START_TEST(test_fixing_insert_3) {
  const char* src = "hello\0";
  char str[] = "ass\0";
  int position=5;
  char* result = s21_insert(src, str, position);
  char* expected = "helloass\0";
  ck_assert_pstr_eq(result, expected);
  free(result);
  // printf("here\n");
}
START_TEST(test_fixing_insert_4) {
  const char* src = "hello\0";
  char str[] = "ass\0";
  int position=0;
  char* result = s21_insert(src, str, position);
  char* expected = "asshello\0";
  ck_assert_pstr_eq(result, expected);
  free(result);
  // printf("here\n");
}
START_TEST(test_fixing_insert_5) {
  const char* src = "hello\0";
  char str[] = "ass\0";
  int position=-5;
  char* result = s21_insert(src, str, position);
  char* expected  = NULL;
  ck_assert_pstr_eq(result, expected);
  free(result);
  // printf("here\n");
}
START_TEST(test_fixing_insert_6) {
  const char* src = "hello\0";
  char str[] = "\0";
  int position=4;
  char* result = s21_insert(src, str, position);
  char* expected = "hello\0";
  ck_assert_pstr_eq(result, expected);
  free(result);
  // printf("here\n");
}
START_TEST(test_fixing_insert_7) {
  const char* src = "\0";
  char str[] = "ass\0";
  int position=2;
  //printf("here\n");
  char* result = s21_insert(src, str, position);
  char* expected = NULL;
  ck_assert_pstr_eq(result, expected);
  free(result);
  //printf("here\n");
}
START_TEST(test_fixing_insert_8) {
  const char* src = NULL;
  char str[] = "ass\0";
  int position=2;
  char* result = s21_insert(src, str, position);
  char* expected = NULL;
  ck_assert_pstr_eq(result, expected);
  free(result);
  // printf("here\n");
}
START_TEST(test_fixing_insert_9) {
  const char* src = "hi\0";
  char* str = NULL;
  int position=2;
  char* result = s21_insert(src, str, position);
  char* expected = NULL;
  ck_assert_pstr_eq(result, expected);
  free(result);
  // printf("here\n");
}
START_TEST(test_fixing_insert_10) {
  const char* src = "hello\0";
  char str[] = "ass\0";
  int position=4;
  char* result = s21_insert(src, str, position);
  char* expected = "hellasso\0";
  ck_assert_pstr_eq(result, expected);
  free(result);
  // printf("here\n");
}
START_TEST(test_fixing_insert_11) {
  const char* src = "\0";
  char str[] = "ass\0";
  int position=0;
  char* result = s21_insert(src, str, position);
  char* expected = "ass\0";
  ck_assert_pstr_eq(result, expected);
  free(result);
  // printf("here\n");
}
START_TEST(test_fixing_trim_1) {
  char* str1 = "Hell to you!\0";
  char* str2 = "!Heu\0";
  char* result = s21_trim(str1, str2);
  char* expected = "ll to yo\0";
  ck_assert_pstr_eq(result, expected);
  free(result);
}
START_TEST(test_fixing_trim_2) {
  char* str1 = "Hell to you!\0";
  char* str2 = "Heltoyu!\0";
  char* result = s21_trim(str1, str2);
  char* expected = " to \0";
  ck_assert_pstr_eq(result, expected);
  free(result);
}
START_TEST(test_fixing_trim_3) {
  char* str1 = "Hell to you!\0";
  char* str2 = "Heltoyu! \0";
  char* result = s21_trim(str1, str2);
  char* expected = "\0";
  ck_assert_pstr_eq(result, expected);
  free(result);
}
START_TEST(test_fixing_trim_4) {
  char* str1 = "Hell to you!\0";
  char* str2 = "Helto yu! \0";
  char* result = s21_trim(str1, str2);
  char* expected = "\0";
  ck_assert_pstr_eq(result, expected);
  free(result);
}
START_TEST(test_fixing_trim_5) {
  char* str1 = "\0";
  char* str2 = "Helto yu! \0";
  char* result = s21_trim(str1, str2);
  char* expected = "\0";
  ck_assert_pstr_eq(result, expected);
  free(result);
}
START_TEST(test_fixing_trim_6) {
  char* str1 = "Hell to you!\0";
  char* str2 = "\0";
  char* result = s21_trim(str1, str2);
  char* expected = "Hell to you!\0";
  ck_assert_pstr_eq(result, expected);
  free(result);
}
START_TEST(test_fixing_trim_7) {
  char* str1 = "Hell to you!\0";
  char* str2 = "u\0";
  char* result = s21_trim(str1, str2);
  char* expected = "Hell to you!\0";
  ck_assert_pstr_eq(result, expected);
  free(result);
}
START_TEST(test_fixing_trim_8) {
  char* str1 = NULL;
  char* str2 = "u\0";
  char* result = s21_trim(str1, str2);
  char* expected = NULL;
  ck_assert_pstr_eq(result, expected);
  free(result);
}
START_TEST(test_fixing_trim_9) {
  char* str1 = "u\0";
  char* str2 = NULL;
  char* result = s21_trim(str1, str2);
  char* expected = "u\0";
  ck_assert_pstr_eq(result, expected);
  free(result);
}
START_TEST(test_fixing_trim_10) {
  char* str1 = "a\0";
  char* str2 = "a\0";
  char* result = s21_trim(str1, str2);
  char* expected = "\0";
  ck_assert_pstr_eq(result, expected);
  free(result);
}
START_TEST(test_fixing_trim_11) {
  char* str1 = "\0";
  char* str2 = "a\0";
  char* result = s21_trim(str1, str2);
  char* expected = "\0";
  ck_assert_pstr_eq(result, expected);
  free(result);
}
START_TEST(test_fixing_trim_12) {
  char* str1 = "b\0";
  char* str2 = "a\0";
  char* result = s21_trim(str1, str2);
  char* expected = "b\0";
  ck_assert_pstr_eq(result, expected);
  free(result);
}
START_TEST(test_fixing_trim_13) {
  char* str1 = "aa\0";
  char* str2 = "a\0";
  char* result = s21_trim(str1, str2);
  char* expected = "\0";
  ck_assert_pstr_eq(result, expected);
  free(result);
}
START_TEST(test_fixing_trim_14) {
  char* str1 = "ab\0";
  char* str2 = "a\0";
  char* result = s21_trim(str1, str2);
  char* expected = "b\0";
  ck_assert_pstr_eq(result, expected);
  free(result);
}
START_TEST(test_fixing_trim_15) {
  char* str1 = "aaa\0";
  char* str2 = "a\0";
  char* result = s21_trim(str1, str2);
  char* expected = "\0";
  ck_assert_pstr_eq(result, expected);
  free(result);
}
START_TEST(test_fixing_trim_16) {
  char* str1 = "aba\0";
  char* str2 = "a\0";
  char* result = s21_trim(str1, str2);
  char* expected = "b\0";
  ck_assert_pstr_eq(result, expected);
  free(result);
}
START_TEST(test_fixing_trim_17) {
  char* str1 = "baa\0";
  char* str2 = "a\0";
  char* result = s21_trim(str1, str2);
  char* expected = "b\0";
  ck_assert_pstr_eq(result, expected);
  free(result);
}
START_TEST(test_fixing_trim_18) {
  char* str1 = "aab\0";
  char* str2 = "a\0";
  char* result = s21_trim(str1, str2);
  char* expected = "b\0";
  ck_assert_pstr_eq(result, expected);
  free(result);
}
START_TEST(test_fixing_trim_19) {
  char* str1 = "abba\0";
  char* str2 = "a\0";
  char* result = s21_trim(str1, str2);
  char* expected = "bb\0";
  ck_assert_pstr_eq(result, expected);
  free(result);
}
START_TEST(test_fixing_trim_20) {
  char* str1 = "aabb\0";
  char* str2 = "a\0";
  char* result = s21_trim(str1, str2);
  char* expected = "bb\0";
  ck_assert_pstr_eq(result, expected);
  free(result);
}
START_TEST(test_fixing_trim_21) {
  char* str1 = "baaa\0";
  char* str2 = "a\0";
  char* result = s21_trim(str1, str2);
  char* expected = "b\0";
  ck_assert_pstr_eq(result, expected);
  free(result);
}
START_TEST(test_fixing_trim_22) {
  char* str1 = "aaabaaa\0";
  char* str2 = "a\0";
  char* result = s21_trim(str1, str2);
  char* expected = "b\0";
  ck_assert_pstr_eq(result, expected);
  free(result);
}
START_TEST(test_fixing_trim_23) {
  char* str1 = "aaaaaa\0";
  char* str2 = "a\0";
  char* result = s21_trim(str1, str2);
  char* expected = "\0";
  ck_assert_pstr_eq(result, expected);
  free(result);
}
START_TEST(test_fixing_trim_24) {
  char* str1 = "Hell to you!\0";
  char* str2 = "H";
  char* result = s21_trim(str1, str2);
  char* expected = "ell to you!\0";
  ck_assert_pstr_eq(result, expected);
  free(result);
}
START_TEST(test_fixing_trim_25) {
  char* str1 = "aaabbbaaa\0";
  char* str2 = "a\0";
  char* result = s21_trim(str1, str2);
  char* expected = "bbb\0";
  ck_assert_pstr_eq(result, expected);
  free(result);
}
START_TEST(test_fixing_trim_26) {
  char* str1 = "aaabbbaaa    \n\n  \0";
  char* str2 = "a \0";
  char* result = s21_trim(str1, str2);
  char* expected = "bbbaaa    \n\n\0";
  ck_assert_pstr_eq(result, expected);
  free(result);
}
START_TEST(test_fixing_trim_27) {
  char* str1 = "     aaabbbaaa    \n\n  \0";
  char* str2 = "\0";
  char* result = s21_trim(str1, str2);
  char* expected = "aaabbbaaa\0";
  ck_assert_pstr_eq(result, expected);
  free(result);
}
START_TEST(test_fixing_trim_28) {
  char* str1 = "     aaabbbaaa    \n\n  \0";
  char* str2 = NULL;
  char* result = s21_trim(str1, str2);
  char* expected = "aaabbbaaa\0";
  ck_assert_pstr_eq(result, expected);
  free(result);
}
START_TEST(test_fixing_trim_29) {
  char* str1 = "  \t\n\r\v\f \t\n\r\v\f \t\n\r\v\f    aaabbbaaa   \t\n\r\v\f \t\n\r\v\f  \n\n  \0";
  char* str2 = NULL;
  char* result = s21_trim(str1, str2);
  char* expected = "aaabbbaaa\0";
  ck_assert_pstr_eq(result, expected);
  free(result);
}
START_TEST(test_fixing_trim_30) {
  char* str1 = "  \t\n\r\v\f \t\n\r\v\f \t\n\r\v\f    aaabbbaaa   \t\n\r\v\f \t\n\r\v\f  \n\n  \0";
  char* str2 = "\0";
  char* result = s21_trim(str1, str2);
  char* expected = "aaabbbaaa\0";
  ck_assert_pstr_eq(result, expected);
  free(result);
}

// elevator
Suite* my_string_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("My_String");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_settings);

  // s21_memcmp
  tcase_add_test(tc_core, test_memcmp);
  tcase_add_test(tc_core, test_memcmp_2);
  tcase_add_test(tc_core, test_memcmp_3);
  // tcase_add_test(tc_core, test_memcmp_4);
  // tcase_add_test(tc_core, test_memcmp_5);
  // tcase_add_test(tc_core, test_memcmp_6);

  // s21_strncmp
  tcase_add_test(tc_core, test_strncmp);
  tcase_add_test(tc_core, test_strncmp_2);
  tcase_add_test(tc_core, test_strncmp_3);
  tcase_add_test(tc_core, test_strncmp_4);
  tcase_add_test(tc_core, test_strncmp_5);
  tcase_add_test(tc_core, test_strncmp_6);

  // s21_memchr
  tcase_add_test(tc_core, test_memchr);
  tcase_add_test(tc_core, test_memchr_2);
  // tcase_add_test(tc_core, test_memchr_3);

  // s21_strchr
  tcase_add_test(tc_core, test_strchr);
  tcase_add_test(tc_core, test_strchr_2);
  tcase_add_test(tc_core, test_strchr_3);
  tcase_add_test(tc_core, test_strchr_4);

  // s21_strrchr
  tcase_add_test(tc_core, test_strrchr);
  tcase_add_test(tc_core, test_strrchr_2);
  tcase_add_test(tc_core, test_strrchr_3);
  tcase_add_test(tc_core, test_strrchr_4);

  // s21_strstr
  tcase_add_test(tc_core, test_strstr);
  tcase_add_test(tc_core, test_strstr_2);
  tcase_add_test(tc_core, test_strstr_3);
  tcase_add_test(tc_core, test_strstr_4);
  tcase_add_test(tc_core, test_strstr_5);
  tcase_add_test(tc_core, test_strstr_6);

  // S21_strlen  -->1.1-1.6
  tcase_add_test(tc_core, test_strlen_usual_1);
  tcase_add_test(tc_core, test_strlen_usual_2);
  tcase_add_test(tc_core, test_strlen_usual_3);
  tcase_add_test(tc_core, test_strlen_usual_4);
  tcase_add_test(tc_core, test_strlen_nullline);
  tcase_add_test(tc_core, test_strlen_nullendline);
  tcase_add_test(tc_core, test_strlen_enterendline_1);
  tcase_add_test(tc_core, test_strlen_enterendline_2);
  tcase_add_test(tc_core, test_strlen_tabendline_1);
  tcase_add_test(tc_core, test_strlen_tabendline_2);
  tcase_add_test(tc_core, test_strlen_nullmidline_1);
  tcase_add_test(tc_core, test_strlen_nullmidline_2);
  tcase_add_test(tc_core, test_strlen_entermidline_1);
  tcase_add_test(tc_core, test_strlen_entermidline_2);
  tcase_add_test(tc_core, test_strlen_tabmidline_1);
  tcase_add_test(tc_core, test_strlen_tabmidline_2);
  tcase_add_test(tc_core, test_strlen_invisible_1);
  tcase_add_test(tc_core, test_strlen_invisible_2);
  tcase_add_test(tc_core, test_memset_normal_1);
  tcase_add_test(tc_core, test_strlen_long);

  // s21_memset -->2.0-2.7
  tcase_add_test(tc_core, test_memset_pointertest);
  tcase_add_test(tc_core, test_memset_normal_1);
  tcase_add_test(tc_core, test_memset_normal_2);
  tcase_add_test(tc_core, test_memset_nullline);
  tcase_add_test(tc_core, test_memset_numzero);
  tcase_add_test(tc_core, test_memset_nummore_5);
  tcase_add_test(tc_core, test_memset_numsame);
  tcase_add_test(tc_core, test_memset_charenter);
  tcase_add_test(tc_core, test_memset_charspace);
  tcase_add_test(tc_core, test_memset_charnull);
  tcase_add_test(tc_core, test_memset_chartab);
  tcase_add_test(tc_core, test_memset_charinvis_1);
  tcase_add_test(tc_core, test_memset_charinvis_2);
  tcase_add_test(tc_core, test_memset_charinvis_3);
  tcase_add_test(tc_core, test_memset_midline_1);
  tcase_add_test(tc_core, test_memset_midline_3);
  tcase_add_test(tc_core, test_memset_midline_2);
  tcase_add_test(tc_core, test_memset_midline_4);
  tcase_add_test(tc_core, test_memset_long_2);
  tcase_add_test(tc_core, test_memset_long_3);
  tcase_add_test(tc_core, test_memset_long_4);

  // s21_memcpy  -->3.0-3.5
  tcase_add_test(tc_core, test_memcpy_pointertes);
  tcase_add_test(tc_core, test_memcpy_norm);
  tcase_add_test(tc_core, test_memcpy_nullend_1);
  tcase_add_test(tc_core, test_memcpy_nullend_2);
  tcase_add_test(tc_core, test_memcpy_nullmid_1);
  tcase_add_test(tc_core, test_memcpy_nullmid_2);
  tcase_add_test(tc_core, test_memcpy_nullmid_3);
  tcase_add_test(tc_core, test_memcpy_entermid_1);
  tcase_add_test(tc_core, test_memcpy_entermid_2);
  tcase_add_test(tc_core, test_memcpy_entermid_3);
  tcase_add_test(tc_core, test_memcpy_invis_1);
  tcase_add_test(tc_core, test_memcpy_invis_2);
  tcase_add_test(tc_core, test_memcpy_invis_3);
  tcase_add_test(tc_core, test_memcpy_different_n_1);
  tcase_add_test(tc_core, test_memcpy_different_n_2);
  tcase_add_test(tc_core, test_memcpy_different_n_3);
  tcase_add_test(tc_core, test_memcpy_different_n_6);
  tcase_add_test(tc_core, test_memcpy_different_n_7);
  tcase_add_test(tc_core, test_memcpy_nullline_1);
  tcase_add_test(tc_core, test_memcpy_nullline_2);
  tcase_add_test(tc_core, test_memcpy_long_1);
  tcase_add_test(tc_core, test_memcpy_long_2);
  tcase_add_test(tc_core, test_memcpy_long_3);
  tcase_add_test(tc_core, test_memcpy_long_4);

  // s21_strncpy -->4.0-4.5
  tcase_add_test(tc_core, test_strncpy_pointertes);
  tcase_add_test(tc_core, test_strncpy_norm_1);
  tcase_add_test(tc_core, test_strncpy_norm_2);
  tcase_add_test(tc_core, test_strncpy_nullend_1);
  tcase_add_test(tc_core, test_strncpy_nullend_2);
  tcase_add_test(tc_core, test_strncpy_nullmid_1);
  tcase_add_test(tc_core, test_strncpy_nullmid_2);
  tcase_add_test(tc_core, test_strncpy_nullmid_3);
  tcase_add_test(tc_core, test_strncpy_entermid_1);
  tcase_add_test(tc_core, test_strncpy_entermid_2);
  tcase_add_test(tc_core, test_strncpy_entermid_3);
  tcase_add_test(tc_core, test_strncpy_invis_1);
  tcase_add_test(tc_core, test_strncpy_invis_2);
  tcase_add_test(tc_core, test_strncpy_invis_3);
  tcase_add_test(tc_core, test_strncpy_different_n_1);
  tcase_add_test(tc_core, test_strncpy_different_n_2);
  tcase_add_test(tc_core, test_strncpy_different_n_3);
  tcase_add_test(tc_core, test_strncpy_different_n_6);
  tcase_add_test(tc_core, test_strncpy_different_n_7);
  tcase_add_test(tc_core, test_strncpy_different_n_10);
  tcase_add_test(tc_core, test_strncpy_different_n_11);
  tcase_add_test(tc_core, test_strncpy_different_n_12);
  tcase_add_test(tc_core, test_strncpy_nullline_1);
  tcase_add_test(tc_core, test_strncpy_nullline_2);
  tcase_add_test(tc_core, test_strncpy_long_1);
  tcase_add_test(tc_core, test_strncpy_long_2);
  tcase_add_test(tc_core, test_strncpy_long_3);
  tcase_add_test(tc_core, test_strncpy_long_4);

  // s21_strncat -->5.0-5.5
  tcase_add_test(tc_core, test_strncat_pointertes);
  tcase_add_test(tc_core, test_strncat_norm_1);
  tcase_add_test(tc_core, test_strncat_norm_2);
  tcase_add_test(tc_core, test_strncat_nullend_1);
  tcase_add_test(tc_core, test_strncat_nullend_2);
  tcase_add_test(tc_core, test_strncat_nullend_3);
  tcase_add_test(tc_core, test_strncat_nullmid_4);
  tcase_add_test(tc_core, test_strncat_nullmid_5);
  tcase_add_test(tc_core, test_strncat_nullmid_6);
  tcase_add_test(tc_core, test_strncat_nullmid_1);
  tcase_add_test(tc_core, test_strncat_nullmid_2);
  tcase_add_test(tc_core, test_strncat_nullmid_3);
  tcase_add_test(tc_core, test_strncat_entermid_1);
  tcase_add_test(tc_core, test_strncat_entermid_2);
  tcase_add_test(tc_core, test_strncat_entermid_3);
  tcase_add_test(tc_core, test_strncat_invis_1);
  tcase_add_test(tc_core, test_strncat_invis_2);
  tcase_add_test(tc_core, test_strncat_invis_3);
  tcase_add_test(tc_core, test_strncat_different_n_1);
  tcase_add_test(tc_core, test_strncat_different_n_2);
  tcase_add_test(tc_core, test_strncat_different_n_3);
  tcase_add_test(tc_core, test_strncat_different_n_13);
  tcase_add_test(tc_core, test_strncat_different_n_14);
  tcase_add_test(tc_core, test_strncat_different_n_15);
  tcase_add_test(tc_core, test_strncat_different_n_11);
  tcase_add_test(tc_core, test_strncat_nullline_1);
  tcase_add_test(tc_core, test_strncat_nullline_2);
  tcase_add_test(tc_core, test_strncat_long_1);
  tcase_add_test(tc_core, test_strncat_long_2);
  tcase_add_test(tc_core, test_strncat_long_3);
  tcase_add_test(tc_core, test_strncat_long_4);
  tcase_add_test(tc_core, test_strncat_long_5);

  // s21_strcspn -->6.0-6.4
  tcase_add_test(tc_core, test_strcspn_types);
  tcase_add_test(tc_core, test_strcspn_norm_1);
  tcase_add_test(tc_core, test_strcspn_norm_2);
  tcase_add_test(tc_core, test_strcspn_norm_3);
  tcase_add_test(tc_core, test_strcspn_norm_4);
  tcase_add_test(tc_core, test_strcspn_norm_5);
  tcase_add_test(tc_core, test_strcspn_nullend_1);
  tcase_add_test(tc_core, test_strcspn_nullend_2);
  tcase_add_test(tc_core, test_strcspn_nullend_3);
  tcase_add_test(tc_core, test_strcspn_nullend_4);
  tcase_add_test(tc_core, test_strcspn_nullend_5);
  tcase_add_test(tc_core, test_strcspn_nullmid_1);
  tcase_add_test(tc_core, test_strcspn_nullmid_2);
  tcase_add_test(tc_core, test_strcspn_nullmid_3);
  tcase_add_test(tc_core, test_strcspn_entermid_1);
  tcase_add_test(tc_core, test_strcspn_entermid_2);
  tcase_add_test(tc_core, test_strcspn_entermid_3);
  tcase_add_test(tc_core, test_strcspn_tabmid_1);
  tcase_add_test(tc_core, test_strcspn_tabmid_2);
  tcase_add_test(tc_core, test_strcspn_tabmid_3);
  tcase_add_test(tc_core, test_strcspn_enterend_1);
  tcase_add_test(tc_core, test_strcspn_invis_1);
  tcase_add_test(tc_core, test_strcspn_invis_2);
  tcase_add_test(tc_core, test_strcspn_invis_3);
  tcase_add_test(tc_core, test_strcspn_invis_4);
  tcase_add_test(tc_core, test_strcspn_invis_5);
  tcase_add_test(tc_core, test_strcspn_invis_6);
  tcase_add_test(tc_core, test_strcspn_invis_7);
  tcase_add_test(tc_core, test_strcspn_nullline_1);
  tcase_add_test(tc_core, test_strcspn_nullline_3);
  tcase_add_test(tc_core, test_strcspn_long_1);
  tcase_add_test(tc_core, test_strcspn_long_2);
  tcase_add_test(tc_core, test_strcspn_long_3);
  tcase_add_test(tc_core, test_strcspn_long_4);
  tcase_add_test(tc_core, test_strcspn_long_5);
  tcase_add_test(tc_core, test_strcspn_long_6);
  tcase_add_test(tc_core, test_strcspn_long_7);

  // s21_strpbrk -->7.0-7.4
  tcase_add_test(tc_core, test_strpbrk_types);
  tcase_add_test(tc_core, test_strpbrk_norm_1);
  tcase_add_test(tc_core, test_strpbrk_norm_2);
  tcase_add_test(tc_core, test_strpbrk_norm_3);
  tcase_add_test(tc_core, test_strpbrk_norm_4);
  tcase_add_test(tc_core, test_strpbrk_norm_5);
  tcase_add_test(tc_core, test_strpbrk_norm_6);
  tcase_add_test(tc_core, test_strpbrk_nullend_1);
  tcase_add_test(tc_core, test_strpbrk_nullend_2);
  tcase_add_test(tc_core, test_strpbrk_nullend_3);
  tcase_add_test(tc_core, test_strpbrk_nullend_4);
  tcase_add_test(tc_core, test_strpbrk_nullend_5);
  tcase_add_test(tc_core, test_strpbrk_nullmid_1);
  tcase_add_test(tc_core, test_strpbrk_nullmid_2);
  tcase_add_test(tc_core, test_strpbrk_nullmid_3);
  tcase_add_test(tc_core, test_strpbrk_entermid_1);
  tcase_add_test(tc_core, test_strpbrk_entermid_2);
  tcase_add_test(tc_core, test_strpbrk_entermid_3);
  tcase_add_test(tc_core, test_strpbrk_tabmid_1);
  tcase_add_test(tc_core, test_strpbrk_tabmid_2);
  tcase_add_test(tc_core, test_strpbrk_tabmid_3);
  tcase_add_test(tc_core, test_strpbrk_enterend_1);
  tcase_add_test(tc_core, test_strpbrk_invis_1);
  tcase_add_test(tc_core, test_strpbrk_invis_2);
  tcase_add_test(tc_core, test_strpbrk_invis_3);
  tcase_add_test(tc_core, test_strpbrk_invis_4);
  tcase_add_test(tc_core, test_strpbrk_invis_5);
  tcase_add_test(tc_core, test_strpbrk_invis_6);
  tcase_add_test(tc_core, test_strpbrk_invis_7);
  tcase_add_test(tc_core, test_strpbrk_invis_8);
  tcase_add_test(tc_core, test_strpbrk_invis_9);
  tcase_add_test(tc_core, test_strpbrk_nullline_1);
  tcase_add_test(tc_core, test_strpbrk_nullline_3);
  tcase_add_test(tc_core, test_strpbrk_long_1);
  tcase_add_test(tc_core, test_strpbrk_long_2);
  tcase_add_test(tc_core, test_strpbrk_long_3);
  tcase_add_test(tc_core, test_strpbrk_long_4);
  tcase_add_test(tc_core, test_strpbrk_long_5);
  tcase_add_test(tc_core, test_strpbrk_long_6);
  tcase_add_test(tc_core, test_strpbrk_long_7);

  // s21_strtok -->8.0-8.4
  tcase_add_test(tc_core,
                 test_strtok_lineschange);  // does it change the line it self?!
  tcase_add_test(tc_core, test_strtok_types);
  tcase_add_test(tc_core, test_strtok_diflines_1);
  tcase_add_test(tc_core, test_strtok_diflines_2);
  tcase_add_test(tc_core, test_strtok_diflines_3);
  tcase_add_test(tc_core, test_strtok_diflines_4);
  tcase_add_test(tc_core, test_strtok_norm_1);
  tcase_add_test(tc_core, test_strtok_norm_2);
  tcase_add_test(tc_core, test_strtok_norm_3);
  tcase_add_test(tc_core, test_strtok_norm_4);
  tcase_add_test(tc_core, test_strtok_norm_5);
  tcase_add_test(tc_core, test_strtok_norm_6);
  tcase_add_test(tc_core, test_strtok_norm_7);
  tcase_add_test(tc_core, test_strtok_norm_8);
  tcase_add_test(tc_core, test_strtok_norm_9);
  tcase_add_test(tc_core, test_strtok_norm_10);
  tcase_add_test(tc_core, test_strtok_norm_11);
  tcase_add_test(tc_core, test_strtok_norm_12);
  tcase_add_test(tc_core, test_strtok_norm_13);
  tcase_add_test(tc_core, test_strtok_norm_14);
  tcase_add_test(tc_core, test_strtok_nullendline_1);
  tcase_add_test(tc_core, test_strtok_nullendline_2);
  tcase_add_test(tc_core, test_strtok_nullmidline_1);
  tcase_add_test(tc_core, test_strtok_nullmidline_2);
  tcase_add_test(tc_core, test_strtok_nullmidline_3);
  tcase_add_test(tc_core, test_strtok_nullmidline_4);
  tcase_add_test(tc_core, test_strtok_enterendline);
  tcase_add_test(tc_core, test_strtok_entermidline_1);
  tcase_add_test(tc_core, test_strtok_entermidline_2);
  tcase_add_test(tc_core, test_strtok_entermidline_3);
  tcase_add_test(tc_core, test_strtok_tabendline);
  tcase_add_test(tc_core, test_strtok_tabmidline_1);
  tcase_add_test(tc_core, test_strtok_tabmidline_2);
  tcase_add_test(tc_core, test_strtok_tabmidline_3);
  tcase_add_test(tc_core, test_strtok_tabmidline_4);
  tcase_add_test(tc_core, test_strtok_invis_1);
  tcase_add_test(tc_core, test_strtok_invis_2);
  tcase_add_test(tc_core, test_strtok_invis_3);
  tcase_add_test(tc_core, test_strtok_invis_4);
  tcase_add_test(tc_core, test_strtok_invis_5);
  tcase_add_test(tc_core, test_strtok_invis_6);
  tcase_add_test(tc_core, test_strtok_invis_7);
  tcase_add_test(tc_core, test_strtok_invis_8);
  tcase_add_test(tc_core, test_strtok_invis_9);
  tcase_add_test(tc_core, test_strtok_nullline_1);
  tcase_add_test(tc_core, test_strtok_nullline_2);
  tcase_add_test(tc_core, test_strtok_nullline_3);
  tcase_add_test(tc_core, test_strtok_nullline_4);
  tcase_add_test(tc_core, test_strtok_nullline_5);
  //  tcase_add_test(tc_core, test_strtok_longline_1);
  //  tcase_add_test(tc_core, test_strtok_longline_2);
  // tcase_add_test(tc_core, test_strtok_longline_3);      //too much time!
  tcase_add_test(tc_core, test_strtok_longline_4);
  tcase_add_test(tc_core, test_strtok_longline_5);
  tcase_add_test(tc_core, test_strtok_longline_6);

  // s21_sscanf -->9.0-9.23
  tcase_add_test(tc_core, test_sscanf_blanks);
  tcase_add_test(tc_core, test_sscanf_unsigned_1);
  tcase_add_test(tc_core, test_sscanf_unsigned_2);
  tcase_add_test(tc_core, test_sscanf_unsigned_3);
  tcase_add_test(tc_core, test_sscanf_unsigned_5);
  tcase_add_test(tc_core, test_sscanf_unsigned_6);
  tcase_add_test(tc_core, test_sscanf_unsigned_7);
  tcase_add_test(tc_core, test_sscanf_unsigned_8);
  tcase_add_test(tc_core, test_sscanf_unsigned_9);
  tcase_add_test(tc_core, test_sscanf_unsigned_10);
  tcase_add_test(tc_core, test_sscanf_unsigned_11);
  tcase_add_test(tc_core, test_sscanf_unsigned_12);
  tcase_add_test(tc_core, test_sscanf_unsigned_13);
  tcase_add_test(tc_core, test_sscanf_unsigned_14);
  tcase_add_test(tc_core, test_sscanf_unsigned_15);
  tcase_add_test(tc_core, test_sscanf_unsigned_16);
  tcase_add_test(tc_core, test_sscanf_unsigned_17);
  tcase_add_test(tc_core, test_sscanf_int_1);
  tcase_add_test(tc_core, test_sscanf_int_2);
  tcase_add_test(tc_core, test_sscanf_int_3);
  tcase_add_test(tc_core, test_sscanf_int_5);
  tcase_add_test(tc_core, test_sscanf_int_6);
  tcase_add_test(tc_core, test_sscanf_int_7);
  tcase_add_test(tc_core, test_sscanf_int_8);
  tcase_add_test(tc_core, test_sscanf_int_9);
  tcase_add_test(tc_core, test_sscanf_int_10);
  tcase_add_test(tc_core, test_sscanf_int_11);
  tcase_add_test(tc_core, test_sscanf_int_12);
  tcase_add_test(tc_core, test_sscanf_int_14);
  tcase_add_test(tc_core, test_sscanf_int_13);
  tcase_add_test(tc_core, test_sscanf_int_15);
  tcase_add_test(tc_core, test_sscanf_int_16);
  tcase_add_test(tc_core, test_sscanf_int_17);
  tcase_add_test(tc_core, test_sscanf_int_18);
  tcase_add_test(tc_core, test_sscanf_int_19);
  tcase_add_test(tc_core, test_sscanf_int_20);
  tcase_add_test(tc_core, test_sscanf_int_22);
  tcase_add_test(tc_core, test_sscanf_int_21);
  tcase_add_test(tc_core, test_sscanf_int_23);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_1);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_2);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_3);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_5);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_6);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_7);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_8);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_9);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_10);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_11);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_12);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_16);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_17);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_18);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_19);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_20);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_22);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_21);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_23);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_24);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_25);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_26);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_27);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_28);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_29);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_30);
  tcase_add_test(tc_core, test_sscanf_short_1);
  tcase_add_test(tc_core, test_sscanf_short_2);
  tcase_add_test(tc_core, test_sscanf_short_3);
  tcase_add_test(tc_core, test_sscanf_short_5);
  tcase_add_test(tc_core, test_sscanf_short_6);
  tcase_add_test(tc_core, test_sscanf_short_7);
  tcase_add_test(tc_core, test_sscanf_short_8);
  tcase_add_test(tc_core, test_sscanf_short_9);
  tcase_add_test(tc_core, test_sscanf_short_10);
  tcase_add_test(tc_core, test_sscanf_short_11);
  tcase_add_test(tc_core, test_sscanf_short_12);
  tcase_add_test(tc_core, test_sscanf_short_16);
  tcase_add_test(tc_core, test_sscanf_short_17);
  tcase_add_test(tc_core, test_sscanf_short_18);
  tcase_add_test(tc_core, test_sscanf_short_19);
  tcase_add_test(tc_core, test_sscanf_short_20);
  tcase_add_test(tc_core, test_sscanf_short_22);
  tcase_add_test(tc_core, test_sscanf_short_21);
  tcase_add_test(tc_core, test_sscanf_short_23);
  tcase_add_test(tc_core, test_sscanf_short_24);
  tcase_add_test(tc_core, test_sscanf_short_25);
  tcase_add_test(tc_core, test_sscanf_short_26);
  tcase_add_test(tc_core, test_sscanf_short_27);
  tcase_add_test(tc_core, test_sscanf_short_28);
  tcase_add_test(tc_core, test_sscanf_short_29);
  tcase_add_test(tc_core, test_sscanf_short_30);
  tcase_add_test(tc_core, test_sscanf_short_31);
  tcase_add_test(tc_core, test_sscanf_short_32);
  tcase_add_test(tc_core, test_sscanf_unsigned_long_1);
  tcase_add_test(tc_core, test_sscanf_unsigned_long_2);
  tcase_add_test(tc_core, test_sscanf_unsigned_long_3);
  tcase_add_test(tc_core, test_sscanf_unsigned_long_5);
  tcase_add_test(tc_core, test_sscanf_unsigned_long_7);
  tcase_add_test(tc_core, test_sscanf_unsigned_long_8);
  tcase_add_test(tc_core, test_sscanf_unsigned_long_12);
  tcase_add_test(tc_core, test_sscanf_unsigned_long_16);
  tcase_add_test(tc_core, test_sscanf_unsigned_long_17);
  tcase_add_test(tc_core, test_sscanf_unsigned_long_18);
  tcase_add_test(tc_core, test_sscanf_unsigned_long_19);
  tcase_add_test(tc_core, test_sscanf_unsigned_long_20);
  tcase_add_test(tc_core, test_sscanf_unsigned_long_22);
  tcase_add_test(tc_core, test_sscanf_unsigned_long_21);
  tcase_add_test(tc_core, test_sscanf_unsigned_long_23);
  tcase_add_test(tc_core, test_sscanf_unsigned_long_30);
  // tcase_add_test(tc_core, test_sscanf_long_1);     --MaC
  tcase_add_test(tc_core, test_sscanf_long_2);
  // tcase_add_test(tc_core, test_sscanf_long_3);     --MaC
  tcase_add_test(tc_core, test_sscanf_long_5);
  //  tcase_add_test(tc_core, test_sscanf_long_6);      --Vertor
  // tcase_add_test(tc_core, test_sscanf_long_7);     --MaC
  // tcase_add_test(tc_core, test_sscanf_long_8);     --MaC
  tcase_add_test(tc_core, test_sscanf_long_12);
  tcase_add_test(tc_core, test_sscanf_long_16);
  tcase_add_test(tc_core, test_sscanf_long_17);
  tcase_add_test(tc_core, test_sscanf_long_18);
  tcase_add_test(tc_core, test_sscanf_long_19);
  tcase_add_test(tc_core, test_sscanf_long_20);
  tcase_add_test(tc_core, test_sscanf_long_22);
  tcase_add_test(tc_core, test_sscanf_long_21);
  tcase_add_test(tc_core, test_sscanf_long_23);
  // tcase_add_test(tc_core, test_sscanf_long_27);      --Vertor
  //  tcase_add_test(tc_core, test_sscanf_long_29);     --MaC
  tcase_add_test(tc_core, test_sscanf_long_30);
  tcase_add_test(tc_core, test_sscanf_unsigned_octal_1);
  tcase_add_test(tc_core, test_sscanf_unsigned_octal_2);
  tcase_add_test(tc_core, test_sscanf_unsigned_octal_3);
  tcase_add_test(tc_core, test_sscanf_unsigned_octal_5);
  tcase_add_test(tc_core, test_sscanf_unsigned_octal_6);
  tcase_add_test(tc_core, test_sscanf_unsigned_octal_7);
  tcase_add_test(tc_core, test_sscanf_unsigned_octal_8);
  tcase_add_test(tc_core, test_sscanf_unsigned_octal_9);
  tcase_add_test(tc_core, test_sscanf_unsigned_octal_10);
  tcase_add_test(tc_core, test_sscanf_unsigned_octal_11);
  tcase_add_test(tc_core, test_sscanf_unsigned_octal_12);
  tcase_add_test(tc_core, test_sscanf_unsigned_octal_13);
  tcase_add_test(tc_core, test_sscanf_unsigned_octal_14);
  tcase_add_test(tc_core, test_sscanf_unsigned_octal_15);
  tcase_add_test(tc_core, test_sscanf_unsigned_octal_16);
  tcase_add_test(tc_core, test_sscanf_unsigned_octal_18);
  tcase_add_test(tc_core, test_sscanf_unsigned_octal_19);
  tcase_add_test(tc_core, test_sscanf_unsigned_octal_20);
  tcase_add_test(tc_core, test_sscanf_unsigned_octal_21);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_octal_1);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_octal_2);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_octal_3);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_octal_4);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_octal_5);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_octal_6);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_octal_7);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_octal_8);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_octal_9);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_octal_10);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_octal_28);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_octal_11);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_octal_14);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_octal_15);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_octal_16);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_octal_17);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_octal_18);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_octal_19);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_octal_20);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_octal_22);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_octal_21);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_octal_23);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_octal_24);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_octal_25);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_octal_26);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_octal_27);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_octal_29);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_octal_30);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_octal_31);
  tcase_add_test(tc_core, test_sscanf_unsigned_short_octal_32);
  tcase_add_test(tc_core, test_sscanf_unsigned_long_octal_1);
  tcase_add_test(tc_core, test_sscanf_unsigned_long_octal_2);
  tcase_add_test(tc_core, test_sscanf_unsigned_long_octal_3);
  tcase_add_test(tc_core, test_sscanf_unsigned_long_octal_4);
  tcase_add_test(tc_core, test_sscanf_unsigned_long_octal_5);
  tcase_add_test(tc_core, test_sscanf_unsigned_long_octal_7);
  tcase_add_test(tc_core, test_sscanf_unsigned_long_octal_8);
  tcase_add_test(tc_core, test_sscanf_unsigned_long_octal_9);
  tcase_add_test(tc_core, test_sscanf_unsigned_long_octal_28);
  tcase_add_test(tc_core, test_sscanf_unsigned_long_octal_14);
  tcase_add_test(tc_core, test_sscanf_unsigned_long_octal_15);
  tcase_add_test(tc_core, test_sscanf_unsigned_long_octal_17);
  tcase_add_test(tc_core, test_sscanf_unsigned_long_octal_18);
  tcase_add_test(tc_core, test_sscanf_unsigned_long_octal_22);
  tcase_add_test(tc_core, test_sscanf_unsigned_long_octal_25);
  tcase_add_test(tc_core, test_sscanf_unsigned_long_octal_26);
  tcase_add_test(tc_core, test_sscanf_unsigned_long_octal_27);
  tcase_add_test(tc_core, test_sscanf_unsigned_long_octal_29);
  tcase_add_test(tc_core, test_sscanf_unsigned_long_octal_30);
  tcase_add_test(tc_core, test_sscanf_unsigned_long_octal_31);
  tcase_add_test(tc_core, test_sscanf_unsigned_long_octal_32);
  tcase_add_test(tc_core, test_sscanf_hexadecimal_1);
  tcase_add_test(tc_core, test_sscanf_hexadecimal_2);
  tcase_add_test(tc_core, test_sscanf_hexadecimal_3);
  tcase_add_test(tc_core, test_sscanf_hexadecimal_4);
  tcase_add_test(tc_core, test_sscanf_hexadecimal_5);
  tcase_add_test(tc_core, test_sscanf_hexadecimal_6);
  tcase_add_test(tc_core, test_sscanf_hexadecimal_7);
  tcase_add_test(tc_core, test_sscanf_hexadecimal_8);
  tcase_add_test(tc_core, test_sscanf_hexadecimal_9);
  tcase_add_test(tc_core, test_sscanf_hexadecimal_10);
  tcase_add_test(tc_core, test_sscanf_hexadecimal_11);
  tcase_add_test(tc_core, test_sscanf_hexadecimal_12);
  tcase_add_test(tc_core, test_sscanf_hexadecimal_13);
  tcase_add_test(tc_core, test_sscanf_hexadecimal_14);
  tcase_add_test(tc_core, test_sscanf_hexadecimal_15);
  tcase_add_test(tc_core, test_sscanf_hexadecimal_16);
  tcase_add_test(tc_core, test_sscanf_hexadecimal_17);
  tcase_add_test(tc_core, test_sscanf_hexadecimal_20);
  tcase_add_test(tc_core, test_sscanf_hexadecimal_22);
  tcase_add_test(tc_core, test_sscanf_hexadecimal_23);
  tcase_add_test(tc_core, test_sscanf_hexadecimal_24);
  tcase_add_test(tc_core, test_sscanf_hexadecimal_25);
  tcase_add_test(tc_core, test_sscanf_hexadecimal_26);
  tcase_add_test(tc_core, test_sscanf_hexadecimal_27);
  tcase_add_test(tc_core, test_sscanf_hexadecimal_28);
  //  tcase_add_test(tc_core, test_sscanf_hexadecimal_29);      --Vertor
  tcase_add_test(tc_core, test_sscanf_hexadecimal_30);
  tcase_add_test(tc_core, test_sscanf_hexadecimal_31);
  tcase_add_test(tc_core, test_sscanf_hexadecimal_32);
  tcase_add_test(tc_core, test_sscanf_hexadecimal_33);
  tcase_add_test(tc_core, test_sscanf_hexadecimal_34);
  tcase_add_test(tc_core, test_sscanf_hexadecimal_35);
  tcase_add_test(tc_core, test_sscanf_hexadecimal_36);
  tcase_add_test(tc_core, test_sscanf_hexadecimal_37);
  tcase_add_test(tc_core, test_sscanf_hexadecimal_38);
  tcase_add_test(tc_core, test_sscanf_hexadecimal_39);
  // tcase_add_test(tc_core, test_sscanf_hexadecimal_40);      --Vertor
  // tcase_add_test(tc_core, test_sscanf_hexadecimal_41);      --Vertor
  tcase_add_test(tc_core, test_sscanf_hexadecimal_42);
  tcase_add_test(tc_core, test_sscanf_hexadecimal_43);
  // tcase_add_test(tc_core, test_sscanf_hexadecimal_44);      --Vertor
  // tcase_add_test(tc_core, test_sscanf_hexadecimal_45);      --Vertor
  tcase_add_test(tc_core, test_sscanf_short_hexadecimal_1);
  tcase_add_test(tc_core, test_sscanf_short_hexadecimal_5);
  tcase_add_test(tc_core, test_sscanf_short_hexadecimal_6);
  tcase_add_test(tc_core, test_sscanf_short_hexadecimal_7);
  tcase_add_test(tc_core, test_sscanf_short_hexadecimal_8);
  tcase_add_test(tc_core, test_sscanf_short_hexadecimal_9);
  tcase_add_test(tc_core, test_sscanf_short_hexadecimal_10);
  tcase_add_test(tc_core, test_sscanf_short_hexadecimal_11);
  tcase_add_test(tc_core, test_sscanf_short_hexadecimal_12);
  tcase_add_test(tc_core, test_sscanf_short_hexadecimal_13);
  tcase_add_test(tc_core, test_sscanf_short_hexadecimal_14);
  tcase_add_test(tc_core, test_sscanf_short_hexadecimal_15);
  tcase_add_test(tc_core, test_sscanf_short_hexadecimal_16);
  tcase_add_test(tc_core, test_sscanf_short_hexadecimal_17);
  tcase_add_test(tc_core, test_sscanf_short_hexadecimal_20);
  tcase_add_test(tc_core, test_sscanf_short_hexadecimal_22);
  tcase_add_test(tc_core, test_sscanf_short_hexadecimal_23);
  tcase_add_test(tc_core, test_sscanf_short_hexadecimal_24);
  tcase_add_test(tc_core, test_sscanf_short_hexadecimal_25);
  tcase_add_test(tc_core, test_sscanf_short_hexadecimal_26);
  tcase_add_test(tc_core, test_sscanf_short_hexadecimal_27);
  tcase_add_test(tc_core, test_sscanf_short_hexadecimal_28);
  //  tcase_add_test(tc_core, test_sscanf_short_hexadecimal_29);      --Vertor
  tcase_add_test(tc_core, test_sscanf_short_hexadecimal_32);
  tcase_add_test(tc_core, test_sscanf_short_hexadecimal_33);
  tcase_add_test(tc_core, test_sscanf_short_hexadecimal_34);
  tcase_add_test(tc_core, test_sscanf_short_hexadecimal_35);
  // tcase_add_test(tc_core, test_sscanf_short_hexadecimal_40);      --Vertor
  // tcase_add_test(tc_core, test_sscanf_short_hexadecimal_41);      --Vertor
  tcase_add_test(tc_core, test_sscanf_short_hexadecimal_42);
  tcase_add_test(tc_core, test_sscanf_short_hexadecimal_43);
  // tcase_add_test(tc_core, test_sscanf_short_hexadecimal_44);      --Vertor
  // tcase_add_test(tc_core, test_sscanf_short_hexadecimal_45);      --Vertor
  tcase_add_test(tc_core, test_sscanf_long_hexadecimal_1);
  tcase_add_test(tc_core, test_sscanf_long_hexadecimal_5);
  tcase_add_test(tc_core, test_sscanf_long_hexadecimal_6);
  tcase_add_test(tc_core, test_sscanf_long_hexadecimal_7);
  tcase_add_test(tc_core, test_sscanf_long_hexadecimal_8);
  tcase_add_test(tc_core, test_sscanf_long_hexadecimal_9);
  tcase_add_test(tc_core, test_sscanf_long_hexadecimal_12);
  tcase_add_test(tc_core, test_sscanf_long_hexadecimal_13);
  tcase_add_test(tc_core, test_sscanf_long_hexadecimal_16);
  tcase_add_test(tc_core, test_sscanf_long_hexadecimal_17);
  tcase_add_test(tc_core, test_sscanf_long_hexadecimal_22);
  tcase_add_test(tc_core, test_sscanf_long_hexadecimal_23);
  tcase_add_test(tc_core, test_sscanf_long_hexadecimal_24);
  tcase_add_test(tc_core, test_sscanf_long_hexadecimal_25);
  tcase_add_test(tc_core, test_sscanf_long_hexadecimal_26);
  tcase_add_test(tc_core, test_sscanf_long_hexadecimal_33);
  tcase_add_test(tc_core, test_sscanf_long_hexadecimal_34);
  tcase_add_test(tc_core, test_sscanf_long_hexadecimal_35);
  // tcase_add_test(tc_core, test_sscanf_long_hexadecimal_40);      --Vertor
  // tcase_add_test(tc_core, test_sscanf_long_hexadecimal_41);      --Vertor
  tcase_add_test(tc_core, test_sscanf_long_hexadecimal_42);
  tcase_add_test(tc_core, test_sscanf_long_hexadecimal_43);
  // tcase_add_test(tc_core, test_sscanf_long_hexadecimal_44);      --Vertor
  // tcase_add_test(tc_core, test_sscanf_long_hexadecimal_45);      --Vertor
  tcase_add_test(tc_core, test_sscanf_float_12);
  tcase_add_test(tc_core, test_sscanf_float_13);
  tcase_add_test(tc_core, test_sscanf_float_14);
  // tcase_add_test(tc_core, test_sscanf_float_15);      --Vertor
  // tcase_add_test(tc_core, test_sscanf_float_16);      --Vertor
  // tcase_add_test(tc_core, test_sscanf_float_17);      --Vertor
  tcase_add_test(tc_core, test_sscanf_float_23);
  tcase_add_test(tc_core, test_sscanf_float_24);
  tcase_add_test(tc_core, test_sscanf_float_25);
  tcase_add_test(tc_core, test_sscanf_double_1);
  tcase_add_test(tc_core, test_sscanf_long_double_1);
  tcase_add_test(tc_core, test_sscanf_long_double_2);
  tcase_add_test(tc_core, test_sscanf_long_double_3);
  tcase_add_test(tc_core, test_sscanf_long_double_6);
  tcase_add_test(tc_core, test_sscanf_long_double_7);
  tcase_add_test(tc_core, test_sscanf_long_double_8);
  tcase_add_test(tc_core, test_sscanf_long_double_9);
  tcase_add_test(tc_core, test_sscanf_long_double_10);
  tcase_add_test(tc_core, test_sscanf_long_double_12);
  tcase_add_test(tc_core, test_sscanf_long_double_13);
  tcase_add_test(tc_core, test_sscanf_long_double_14);
  // tcase_add_test(tc_core, test_sscanf_long_double_15);      --Vertor
  // tcase_add_test(tc_core, test_sscanf_long_double_16);      --Vertor
  // tcase_add_test(tc_core, test_sscanf_long_double_17);      --Vertor
  tcase_add_test(tc_core, test_sscanf_long_double_20);
  tcase_add_test(tc_core, test_sscanf_long_double_21);
  tcase_add_test(tc_core, test_sscanf_long_double_23);
  tcase_add_test(tc_core, test_sscanf_long_double_24);
  tcase_add_test(tc_core, test_sscanf_long_double_25);
  tcase_add_test(tc_core, test_sscanf_long_double_30);
  tcase_add_test(tc_core, test_sscanf_long_double_31);
  tcase_add_test(tc_core, test_sscanf_long_double_32);
  tcase_add_test(tc_core, test_sscanf_long_double_33);
  tcase_add_test(tc_core, test_sscanf_long_double_g_1);
  tcase_add_test(tc_core, test_sscanf_long_double_g_2);
  tcase_add_test(tc_core, test_sscanf_long_double_g_3);
  tcase_add_test(tc_core, test_sscanf_long_double_g_6);
  tcase_add_test(tc_core, test_sscanf_long_double_g_7);
  tcase_add_test(tc_core, test_sscanf_long_double_g_8);
  tcase_add_test(tc_core, test_sscanf_long_double_g_9);
  tcase_add_test(tc_core, test_sscanf_long_double_g_10);
  tcase_add_test(tc_core, test_sscanf_long_double_G_1);
  tcase_add_test(tc_core, test_sscanf_long_double_G_2);
  tcase_add_test(tc_core, test_sscanf_long_double_G_3);
  tcase_add_test(tc_core, test_sscanf_long_double_G_6);
  tcase_add_test(tc_core, test_sscanf_long_double_G_7);
  tcase_add_test(tc_core, test_sscanf_long_double_G_8);
  tcase_add_test(tc_core, test_sscanf_long_double_G_9);
  tcase_add_test(tc_core, test_sscanf_long_double_G_10);
  tcase_add_test(tc_core, test_sscanf_long_double_e_1);
  tcase_add_test(tc_core, test_sscanf_long_double_e_2);
  tcase_add_test(tc_core, test_sscanf_long_double_e_3);
  tcase_add_test(tc_core, test_sscanf_long_double_e_6);
  tcase_add_test(tc_core, test_sscanf_long_double_e_7);
  tcase_add_test(tc_core, test_sscanf_long_double_e_8);
  tcase_add_test(tc_core, test_sscanf_long_double_e_9);
  tcase_add_test(tc_core, test_sscanf_long_double_e_10);
  tcase_add_test(tc_core, test_sscanf_long_double_E_1);
  tcase_add_test(tc_core, test_sscanf_long_double_E_2);
  tcase_add_test(tc_core, test_sscanf_long_double_E_3);
  tcase_add_test(tc_core, test_sscanf_long_double_E_6);
  tcase_add_test(tc_core, test_sscanf_long_double_E_7);
  tcase_add_test(tc_core, test_sscanf_long_double_E_8);
  tcase_add_test(tc_core, test_sscanf_long_double_E_9);
  tcase_add_test(tc_core, test_sscanf_long_double_E_10);
  tcase_add_test(tc_core, test_sscanf_i_1);
  tcase_add_test(tc_core, test_sscanf_i_2);
  tcase_add_test(tc_core, test_sscanf_i_3);
  tcase_add_test(tc_core, test_sscanf_i_4);
  tcase_add_test(tc_core, test_sscanf_i_5);
  tcase_add_test(tc_core, test_sscanf_i_6);
  tcase_add_test(tc_core, test_sscanf_i_7);
  tcase_add_test(tc_core, test_sscanf_i_8);
  tcase_add_test(tc_core, test_sscanf_i_9);
  tcase_add_test(tc_core, test_sscanf_i_10);
  tcase_add_test(tc_core, test_sscanf_i_11);
  tcase_add_test(tc_core, test_sscanf_i_12);
  tcase_add_test(tc_core, test_sscanf_i_13);
  tcase_add_test(tc_core, test_sscanf_i_14);
  tcase_add_test(tc_core, test_sscanf_i_15);
  tcase_add_test(tc_core, test_sscanf_i_16);
  tcase_add_test(tc_core, test_sscanf_i_17);
  tcase_add_test(tc_core, test_sscanf_i_18);
  tcase_add_test(tc_core, test_sscanf_i_19);
  tcase_add_test(tc_core, test_sscanf_i_20);
  tcase_add_test(tc_core, test_sscanf_i_22);
  tcase_add_test(tc_core, test_sscanf_i_21);
  tcase_add_test(tc_core, test_sscanf_i_23);
  tcase_add_test(tc_core, test_sscanf_i_24);
  tcase_add_test(tc_core, test_sscanf_i_25);
  tcase_add_test(tc_core, test_sscanf_i_26);
  tcase_add_test(tc_core, test_sscanf_i_27);
  tcase_add_test(tc_core, test_sscanf_i_29);
  tcase_add_test(tc_core, test_sscanf_i_30);
  tcase_add_test(tc_core, test_sscanf_i_31);
  tcase_add_test(tc_core, test_sscanf_i_32);
  tcase_add_test(tc_core, test_sscanf_i_33);
  tcase_add_test(tc_core, test_sscanf_i_34);
  tcase_add_test(tc_core, test_sscanf_i_35);
  tcase_add_test(tc_core, test_sscanf_i_36);
  tcase_add_test(tc_core, test_sscanf_i_37);
  tcase_add_test(tc_core, test_sscanf_i_38);
  tcase_add_test(tc_core, test_sscanf_i_39);
  tcase_add_test(tc_core, test_sscanf_i_40);
  tcase_add_test(tc_core, test_sscanf_i_41);
  tcase_add_test(tc_core, test_sscanf_i_42);
  tcase_add_test(tc_core, test_sscanf_i_43);
  tcase_add_test(tc_core, test_sscanf_i_44);
  tcase_add_test(tc_core, test_sscanf_i_45);
  tcase_add_test(tc_core, test_sscanf_long_and_short_i_1);
  tcase_add_test(tc_core, test_sscanf_long_and_short_i_2);
  tcase_add_test(tc_core, test_sscanf_long_and_short_i_3);
  tcase_add_test(tc_core, test_sscanf_long_and_short_i_4);
  tcase_add_test(tc_core, test_sscanf_long_and_short_i_5);
  tcase_add_test(tc_core, test_sscanf_long_and_short_i_6);
  tcase_add_test(tc_core, test_sscanf_long_and_short_i_7);
  tcase_add_test(tc_core, test_sscanf_long_and_short_i_8);
  tcase_add_test(tc_core, test_sscanf_long_and_short_i_9);
  tcase_add_test(tc_core, test_sscanf_long_and_short_i_10);
  tcase_add_test(tc_core, test_sscanf_long_and_short_i_12);
  // tcase_add_test(tc_core, test_sscanf_long_and_short_i_11);
  // tcase_add_test(tc_core, test_sscanf_long_and_short_i_13);
  // tcase_add_test(tc_core, test_sscanf_long_and_short_i_14);
  tcase_add_test(tc_core, test_sscanf_long_and_short_i_15);
  tcase_add_test(tc_core, test_sscanf_long_and_short_i_16);
  tcase_add_test(tc_core, test_sscanf_long_and_short_i_17);
  tcase_add_test(tc_core, test_sscanf_long_and_short_i_18);
  tcase_add_test(tc_core, test_sscanf_long_and_short_i_19);
  tcase_add_test(tc_core, test_sscanf_long_and_short_i_20);
  tcase_add_test(tc_core, test_sscanf_long_and_short_i_21);
  tcase_add_test(tc_core, test_sscanf_long_and_short_i_22);
  // tcase_add_test(tc_core, test_sscanf_long_and_short_i_24);
  tcase_add_test(tc_core, test_sscanf_long_and_short_i_25);
  tcase_add_test(tc_core, test_sscanf_long_and_short_i_26);
  tcase_add_test(tc_core, test_sscanf_long_and_short_i_27);
  tcase_add_test(tc_core, test_sscanf_long_and_short_i_28);
  tcase_add_test(tc_core, test_sscanf_long_and_short_i_29);
  tcase_add_test(tc_core, test_sscanf_long_and_short_i_30);
  tcase_add_test(tc_core, test_sscanf_pointer_1);
  // tcase_add_test(tc_core, test_sscanf_pointer_3);      --Vertor
  tcase_add_test(tc_core, test_sscanf_pointer_4);
  tcase_add_test(tc_core, test_sscanf_pointer_5);
  tcase_add_test(tc_core, test_sscanf_pointer_6);
  tcase_add_test(tc_core, test_sscanf_pointer_7);
  tcase_add_test(tc_core, test_sscanf_pointer_9);
  tcase_add_test(tc_core, test_sscanf_pointer_11);
  tcase_add_test(tc_core, test_sscanf_pointer_12);
  tcase_add_test(tc_core, test_sscanf_pointer_13);
  tcase_add_test(tc_core, test_sscanf_pointer_14);
  tcase_add_test(tc_core, test_sscanf_pointer_15);
  tcase_add_test(tc_core, test_sscanf_char_and_long_char_1);
  tcase_add_test(tc_core, test_sscanf_char_and_long_char_8);
  tcase_add_test(tc_core, test_sscanf_char_and_long_char_10);
  tcase_add_test(tc_core, test_sscanf_char_and_long_char_11);
  tcase_add_test(tc_core, test_sscanf_char_and_long_char_18);
  tcase_add_test(tc_core, test_sscanf_char_and_long_char_20);
  tcase_add_test(tc_core, test_sscanf_char_and_long_char_21);
  // tcase_add_test(tc_core, test_sscanf_char_and_long_char_2);          //does
  // not work in my architecture tcase_add_test(tc_core,
  // test_sscanf_char_and_long_char_3);          //does not work in my
  // architecture tcase_add_test(tc_core, test_sscanf_char_and_long_char_4);
  // //does not work in my architecture tcase_add_test(tc_core,
  // test_sscanf_char_and_long_char_5);          //does not work in my
  // architecture tcase_add_test(tc_core, test_sscanf_char_and_long_char_6);
  // //does not work in my architecture tcase_add_test(tc_core,
  // test_sscanf_char_and_long_char_7);          //does not work in my
  // architecture tcase_add_test(tc_core, test_sscanf_char_and_long_char_9);
  // //does not work in my architecture tcase_add_test(tc_core,
  // test_sscanf_char_and_long_char_12);         //does not work in my
  // architecture tcase_add_test(tc_core, test_sscanf_char_and_long_char_13);
  // //does not work in my architecture tcase_add_test(tc_core,
  // test_sscanf_char_and_long_char_14);         //does not work in my
  // architecture tcase_add_test(tc_core, test_sscanf_char_and_long_char_15);
  // //does not work in my architecture tcase_add_test(tc_core,
  // test_sscanf_char_and_long_char_16);         //does not work in my
  // architecture tcase_add_test(tc_core, test_sscanf_char_and_long_char_17);
  // //does not work in my architecture tcase_add_test(tc_core,
  // test_sscanf_char_and_long_char_19);         //does not work in my
  // architecture
  tcase_add_test(tc_core, test_sscanf_string_and_long_string_1);
  tcase_add_test(tc_core, test_sscanf_string_and_long_string_2);
  tcase_add_test(tc_core, test_sscanf_string_and_long_string_3);
  tcase_add_test(tc_core, test_sscanf_string_and_long_string_4);
  tcase_add_test(tc_core, test_sscanf_string_and_long_string_5);
  tcase_add_test(tc_core, test_sscanf_string_and_long_string_6);
  tcase_add_test(tc_core, test_sscanf_string_and_long_string_7);
  tcase_add_test(tc_core, test_sscanf_string_and_long_string_8);
  tcase_add_test(tc_core, test_sscanf_string_and_long_string_9);
  tcase_add_test(tc_core, test_sscanf_string_and_long_string_10);
  tcase_add_test(tc_core, test_sscanf_string_and_long_string_11);
  tcase_add_test(tc_core, test_sscanf_string_and_long_string_12);
  tcase_add_test(tc_core, test_sscanf_string_and_long_string_13);
  tcase_add_test(tc_core, test_sscanf_string_and_long_string_14);
  tcase_add_test(tc_core, test_sscanf_n_1);
  tcase_add_test(tc_core, test_sscanf_n_2);
  tcase_add_test(tc_core, test_sscanf_n_3);
  tcase_add_test(tc_core, test_sscanf_strange_tests_1);
  tcase_add_test(tc_core, test_sscanf_strange_tests_2);
  // tcase_add_test(tc_core, test_sscanf_strange_tests_4);      --Vertor
  tcase_add_test(tc_core, test_sscanf_strange_tests_5);
  tcase_add_test(tc_core, test_sscanf_strange_tests_6);
  tcase_add_test(tc_core, test_sscanf_strange_tests_7);
  tcase_add_test(tc_core, test_sscanf_strange_tests_8);
  tcase_add_test(tc_core, test_sscanf_strange_tests_9);
  tcase_add_test(tc_core, test_sscanf_strange_tests_10);
  tcase_add_test(tc_core, test_sscanf_strange_tests_11);
  // tcase_add_test(tc_core, test_sscanf_strange_tests_12);      --Vertor
  tcase_add_test(tc_core, test_sscanf_strange_tests_13);
  // tcase_add_test(tc_core, test_sscanf_strange_tests_14);      --Vertor
  // tcase_add_test(tc_core, test_sscanf_strange_tests_15);      --Vertor
  tcase_add_test(tc_core, test_sscanf_strange_tests_16);
  // tcase_add_test(tc_core, test_sscanf_strange_tests_19);      --Vertor
  // tcase_add_test(tc_core, test_sscanf_strange_tests_21);      --Vertor
  tcase_add_test(tc_core, test_sscanf_strange_tests_25);
  tcase_add_test(tc_core, test_sscanf_strange_tests_26);
  tcase_add_test(tc_core, test_sscanf_strange_tests_28);
  // tcase_add_test(tc_core, test_sscanf_strange_tests_24);      --Vertor
  tcase_add_test(tc_core, test_sscanf_strange_tests_30);
  tcase_add_test(tc_core, test_sscanf_strange_tests_31);
  tcase_add_test(tc_core, test_sscanf_strange_tests_32);
  tcase_add_test(tc_core, test_sscanf_strange_tests_33);
  tcase_add_test(tc_core, test_sscanf_strange_tests_35);
  tcase_add_test(tc_core, test_sscanf_strange_tests_36);
  // tcase_add_test(tc_core, test_sscanf_strange_tests_37);      --Vertor
  tcase_add_test(tc_core, test_sscanf_strange_tests_38);
  tcase_add_test(tc_core, test_sscanf_strange_tests_39);
  tcase_add_test(tc_core, test_sscanf_strange_tests_41);
  tcase_add_test(tc_core, test_sscanf_strange_tests_40);
  tcase_add_test(tc_core, test_sscanf_strange_tests_42);
  // tcase_add_test(tc_core, test_sscanf_strange_tests_0);      --Vertor
  //  interesting fact: in original sscanf(str,"%xhello",&sf1);     -->>Error!!
  tcase_add_test(tc_core, test_sscanf_cov_test_1);
  // tcase_add_test(tc_core, test_sscanf_cov_test_2);      --verter+MaC
  // tcase_add_test(tc_core, test_sscanf_cov_test_3);       --%hf
  // tcase_add_test(tc_core, test_sscanf_cov_test_4);       --%hc
  tcase_add_test(tc_core, test_sscanf_cov_test_5);
  tcase_add_test(tc_core, test_sscanf_cov_test_6);

  tcase_add_test(tc_core, test_spritf_c);
  tcase_add_test(tc_core, test_spritf_d);
  tcase_add_test(tc_core, test_spritf_d_neg);
  tcase_add_test(tc_core, test_spritf_d_len);
  tcase_add_test(tc_core, test_spritf_d_acc);
  tcase_add_test(tc_core, test_spritf_d_len_acc1);
  tcase_add_test(tc_core, test_spritf_d_len_acc2);
  tcase_add_test(tc_core, test_spritf_d_len_acc_neg);
  tcase_add_test(tc_core, test_spritf_d_len_acc_plus);
  tcase_add_test(tc_core, test_spritf_d_len_acc_space);
  tcase_add_test(tc_core, test_spritf_d_len_acc_neg_plus);
  tcase_add_test(tc_core, test_spritf_d_len_acc_neg_space);
  tcase_add_test(tc_core, test_spritf_ld);
  tcase_add_test(tc_core, test_spritf_ld_len);
  tcase_add_test(tc_core, test_spritf_ld_acc);
  tcase_add_test(tc_core, test_spritf_ld_len_acc1);
  tcase_add_test(tc_core, test_spritf_ld_len_acc2);
  tcase_add_test(tc_core, test_spritf_ld_len_acc_neg);
  tcase_add_test(tc_core, test_spritf_ld_len_acc_plus);
  tcase_add_test(tc_core, test_spritf_ld_len_acc_space);
  tcase_add_test(tc_core, test_spritf_ld_len_acc_neg_plus);
  tcase_add_test(tc_core, test_spritf_ld_len_acc_neg_space);
  tcase_add_test(tc_core, test_spritf_hd);
  tcase_add_test(tc_core, test_spritf_hd_len);
  tcase_add_test(tc_core, test_spritf_hd_acc);
  tcase_add_test(tc_core, test_spritf_hd_len_acc1);
  tcase_add_test(tc_core, test_spritf_hd_len_acc2);
  tcase_add_test(tc_core, test_spritf_hd_len_acc_neg);
  tcase_add_test(tc_core, test_spritf_hd_len_acc_plus);
  tcase_add_test(tc_core, test_spritf_hd_len_acc_space);
  tcase_add_test(tc_core, test_spritf_hd_len_acc_neg_plus);
  tcase_add_test(tc_core, test_spritf_hd_len_acc_neg_space);
  tcase_add_test(tc_core, test_spritf_f);
  tcase_add_test(tc_core, test_spritf_f_neg);
  tcase_add_test(tc_core, test_spritf_f_len);
  tcase_add_test(tc_core, test_spritf_f_acc);
  tcase_add_test(tc_core, test_spritf_f_len_acc1);
  tcase_add_test(tc_core, test_spritf_f_len_acc2);
  tcase_add_test(tc_core, test_spritf_f_len_acc_neg);
  tcase_add_test(tc_core, test_spritf_f_len_acc_plus);
  tcase_add_test(tc_core, test_spritf_f_len_acc_space);
  tcase_add_test(tc_core, test_spritf_f_len_acc_neg_plus);
  tcase_add_test(tc_core, test_spritf_f_len_acc_neg_space);
  tcase_add_test(tc_core, test_spritf_s);
  tcase_add_test(tc_core, test_spritf_u);
  tcase_add_test(tc_core, test_spritf_u_len);
  tcase_add_test(tc_core, test_spritf_u_acc);
  tcase_add_test(tc_core, test_spritf_u_len_acc1);
  tcase_add_test(tc_core, test_spritf_u_len_acc2);
  tcase_add_test(tc_core, test_spritf_u_len_acc_neg);
  tcase_add_test(tc_core, test_spritf_u_len_acc_plus);
  tcase_add_test(tc_core, test_spritf_u_len_acc_space);
  tcase_add_test(tc_core, test_spritf_u_len_acc_neg_plus);
  tcase_add_test(tc_core, test_spritf_u_len_acc_neg_space);
  tcase_add_test(tc_core, test_spritf_lu);
  tcase_add_test(tc_core, test_spritf_lu_len);
  tcase_add_test(tc_core, test_spritf_lu_acc);
  tcase_add_test(tc_core, test_spritf_lu_len_acc1);
  tcase_add_test(tc_core, test_spritf_lu_len_acc2);
  tcase_add_test(tc_core, test_spritf_lu_len_acc_neg);
  tcase_add_test(tc_core, test_spritf_lu_len_acc_plus);
  tcase_add_test(tc_core, test_spritf_lu_len_acc_space);
  tcase_add_test(tc_core, test_spritf_lu_len_acc_neg_plus);
  tcase_add_test(tc_core, test_spritf_lu_len_acc_neg_space);
  tcase_add_test(tc_core, test_spritf_hu);
  tcase_add_test(tc_core, test_spritf_hu_len);
  tcase_add_test(tc_core, test_spritf_hu_acc);
  tcase_add_test(tc_core, test_spritf_hu_len_acc1);
  tcase_add_test(tc_core, test_spritf_hu_len_acc2);
  tcase_add_test(tc_core, test_spritf_hu_len_acc_neg);
  tcase_add_test(tc_core, test_spritf_hu_len_acc_plus);
  tcase_add_test(tc_core, test_spritf_hu_len_acc_space);
  tcase_add_test(tc_core, test_spritf_hu_len_acc_neg_plus);
  tcase_add_test(tc_core, test_spritf_hu_len_acc_neg_space);
  tcase_add_test(tc_core, test_spritf_multi);
  tcase_add_test(tc_core, test_spritf_per);

  tcase_add_test(tc_core, test_to_upper);
  tcase_add_test(tc_core, test_to_upper2);
  tcase_add_test(tc_core, test_to_upper3);
  tcase_add_test(tc_core, test_to_upper_empty);

  tcase_add_test(tc_core, test_to_lower);
  tcase_add_test(tc_core, test_to_lower2);
  tcase_add_test(tc_core, test_to_lower3);
  tcase_add_test(tc_core, test_to_lower_empty);

  tcase_add_test(tc_core, test_insert1);
  tcase_add_test(tc_core, test_insert2);
  tcase_add_test(tc_core, test_insert3);
  tcase_add_test(tc_core, test_insert4);

  tcase_add_test(tc_core, test_trim1);
  tcase_add_test(tc_core, test_trim2);
  tcase_add_test(tc_core, test_trim3);
  tcase_add_test(tc_core, test_trim4);
  tcase_add_test(tc_core, test_trim5);
  tcase_add_test(tc_core, test_trim6);
  tcase_add_test(tc_core, test_trim7);
  tcase_add_test(tc_core, test_trim8);

  tcase_add_test(tc_core, test_strerror);
  tcase_add_test(tc_core, test_strerror2);
  tcase_add_test(tc_core, test_strerror3);

  tcase_add_test(tc_core,test_fixing_insert_1);
  tcase_add_test(tc_core,test_fixing_insert_2);
  tcase_add_test(tc_core,test_fixing_insert_3);
  tcase_add_test(tc_core,test_fixing_insert_4);
  tcase_add_test(tc_core,test_fixing_insert_5);
  tcase_add_test(tc_core,test_fixing_insert_6);
  tcase_add_test(tc_core,test_fixing_insert_7);
  tcase_add_test(tc_core,test_fixing_insert_8);
  tcase_add_test(tc_core,test_fixing_insert_9);
  tcase_add_test(tc_core,test_fixing_insert_10);
  tcase_add_test(tc_core,test_fixing_insert_11);
  tcase_add_test(tc_core,test_fixing_trim_1);
  tcase_add_test(tc_core,test_fixing_trim_2);
  tcase_add_test(tc_core,test_fixing_trim_3);
  tcase_add_test(tc_core,test_fixing_trim_4);
  tcase_add_test(tc_core,test_fixing_trim_5);
  tcase_add_test(tc_core,test_fixing_trim_6);
  tcase_add_test(tc_core,test_fixing_trim_7);
  tcase_add_test(tc_core,test_fixing_trim_8);
  tcase_add_test(tc_core,test_fixing_trim_9);
  tcase_add_test(tc_core,test_fixing_trim_10);
  tcase_add_test(tc_core,test_fixing_trim_11);
  tcase_add_test(tc_core,test_fixing_trim_12);
  tcase_add_test(tc_core,test_fixing_trim_13);
  tcase_add_test(tc_core,test_fixing_trim_14);
  tcase_add_test(tc_core,test_fixing_trim_15);
  tcase_add_test(tc_core,test_fixing_trim_16);
  tcase_add_test(tc_core,test_fixing_trim_17);
  tcase_add_test(tc_core,test_fixing_trim_18);
  tcase_add_test(tc_core,test_fixing_trim_19);
  tcase_add_test(tc_core,test_fixing_trim_10);
  tcase_add_test(tc_core,test_fixing_trim_20);
  tcase_add_test(tc_core,test_fixing_trim_21);
  tcase_add_test(tc_core,test_fixing_trim_22);
  tcase_add_test(tc_core,test_fixing_trim_23);
  tcase_add_test(tc_core,test_fixing_trim_24);
  tcase_add_test(tc_core,test_fixing_trim_25);
  tcase_add_test(tc_core,test_fixing_trim_26);
  tcase_add_test(tc_core,test_fixing_trim_27);
  tcase_add_test(tc_core,test_fixing_trim_28);
  tcase_add_test(tc_core,test_fixing_trim_29);
  tcase_add_test(tc_core,test_fixing_trim_30);

  suite_add_tcase(s, tc_core);
  return s;
}
// elevator
int main(void) {
  int number_failed;
  Suite* s;
  SRunner* sr;

  s = my_string_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
