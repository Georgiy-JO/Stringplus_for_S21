#include <stdio.h>
#include <string.h>
#include <check.h>
#include <stdlib.h>
#include <time.h>
#include "s21_string.h"
//elevator

#define NULL_LINE "\0"  //2+
#define INVIS_CHAR {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32} //32(33)
#define NULL_END_line {'g','h','t','\0'} //4(5)
#define ENTER_END_line {'g','h','t','\n'} //4(5)
#define TAB_END_line {'g','h','t','\t'} //4(5)
#define NULL_MID_line {'Z','F','\0','T'} //4(5)
#define ENTER_MID_line {'g','h','\n','t'} //4(5)
#define TAB_MID_line {'g','\t','h','t'} //4(5)
#define FRIVE_CHAR_1 "ggggg"//5(6)
#define FRIVE_CHAR_2 "fffff" //5(6)
#define FOUR_CHAR "asdf"  //4(5)
#define SEVEN_CHAR "asdfghj"  //7(8)
#define LONG_CHECK_LINE 100001
#define STRLINES_FIVE 5
#define NORMLINES_SIX 6

//s21_strlen -->1.1-1.6
//s21_memset -->2.0-2.7
//s21_memcpy  -->3.0-3.5
//s21_strncpy -->4.0-4.5
//s21_strncat -->5.0-5.5
//s21_strcspn -->6.0-6.4
//s21_strpbrk -->7.0-7.4
//s21_strtok -->8.0-8.4

/*  //(*5)  TOO LONG　LINES CHECK  -- HOW?!

#define MAX_32 4294967295
#define MAX_64 18446744073709551615


void fromfile(char** line, char* filename, char n){
    FILE* file=fopen(filename,"r");
    if(n==1){
        for(int i=0;i<MAX_32;i++)
        {
            *line[i]=fgetc(file);
        }
    }
    else if(n==2){
        for(int i=0;i<MAX_64;i++)
        {
            *line[i]=fgetc(file);
        }
    }
    fclose;
}

START_TEST(test_strlen_TooBig_32) {
    char line[MAX_32];
    fromfile(&line, "large_64.txt", 1);
    ck_assert_int_eq(strlen(line), s21_strlen(line));
}

START_TEST(test_strlen_TooBig_64) {
    char* line=(char*) calloc(MAX_64, sizeof(char));
    fromfile(&line, "large_64.txt", 2);
    ck_assert_int_eq(strlen(line), s21_strlen(line));
    free(line);
}
*/
 
void rand_str (char* line, size_t n){
    srand((unsigned) time(NULL));
    symbol sim = C_ZERO;
    for(size_t i=0;i<n;i++){
        sim=rand()%255+1;
        if(sim=='\t'||sim=='\n')    sim=55;
        line[i]=sim;
    }
}

START_TEST(test_settings) {
    //ck_assert_int_eq(NULL, MY_NULL);
    //ck_assert_str_eq(NULL, MY_NULL);
    ck_assert_ptr_eq(NULL, MY_NULL);
}

//s21_memcmp
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

//s21_strmcmp
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
	ck_assert_int_eq(result, expected);
}
START_TEST(test_strncmp_3) {
	char* str1 = "hello";
	char* str2 = "h3llo";
	size_t n = 4;
	int result = s21_strncmp(str1, str2, n);
	int expected = strncmp(str1, str2, n);
	ck_assert_int_eq(result, expected);
}
START_TEST(test_strncmp_4) {
	char* str1 = "hello";
	char* str2 = "";
	size_t n = 4;
	int result = s21_strncmp(str1, str2, n);
	int expected = strncmp(str1, str2, n);
	ck_assert_int_eq(result, expected);
}
START_TEST(test_strncmp_5) {
	char* str1 = "";
	char* str2 = "hello";
	size_t n = 4;
	int result = s21_strncmp(str1, str2, n);
	int expected = strncmp(str1, str2, n);
	ck_assert_int_eq(result, expected);
}
START_TEST(test_strncmp_6) {
	char* str1 = "";
	char* str2 = "";
	size_t n = 4;
	int result = s21_strncmp(str1, str2, n);
	int expected = strncmp(str1, str2, n);
	ck_assert_int_eq(result, expected);
}

//s21_memchr
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
/*                              //WERROR -- overread
START_TEST(test_memchr_3) {
	char* str1 = "hello";
	int c = 'f';
	size_t n = 10;
	char* result = s21_memchr(str1, c, n);
	char* expected = memchr(str1, c, n);
	ck_assert_ptr_eq(result, expected);
}
*/

//s21_strchr
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

//s21_strrchr
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

//s21_strstr
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

//s21_strlen 
//1.1
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
//1.2
START_TEST(test_strlen_nullline) {
    char line[8] = NULL_LINE;
    ck_assert_int_eq(strlen(line), s21_strlen(line));
}
//  //(*4.1)   Werror does not like these lines: ‘strlen’ reading 1 or more bytes from a region of size 0
// START_TEST(test_strlen_zeroline) {   
//     char line[0];
//     ck_assert_int_eq(strlen(line), s21_strlen(line));
// }

// //(*4.1)  Werror does not like these lines: ‘strlen’ reading 1 or more bytes from a region of size 0
// START_TEST(test_strlen_zeronullline) {       
//     char line[0] = NULL_LINE;
//     ck_assert_int_eq(strlen(line), s21_strlen(line));
// }

/*  //(*1.1) Segmentation fault (core dumped)  -  both original and our strlen
START_TEST(test_strlen_absolutenullline) {
    char* line = NULL;
    ck_assert_int_eq(strlen(line), s21_strlen(line));
}
*/
//1.3
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
//1.4
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
//1.5
START_TEST(test_strlen_invisible_1) {
    char line[32] = INVIS_CHAR;
    ck_assert_int_eq(strlen(line), s21_strlen(line));
}
START_TEST(test_strlen_invisible_2) {
    char line[33] = INVIS_CHAR;
    ck_assert_int_eq(strlen(line), s21_strlen(line));
}
//1.6
START_TEST(test_strlen_long) {
    char line[LONG_CHECK_LINE] = {'\0'};
    rand_str(line, LONG_CHECK_LINE-1);
    //printf("\n\n%s\n\n",line);
    ck_assert_int_eq(strlen(line), s21_strlen(line));
}

//s21_memset
//2.0
START_TEST(test_memset_pointertest) {
    char line1[6] = FRIVE_CHAR_1;
    char line2[6] = FRIVE_CHAR_1;
    char letter = 'f';
    int len = 4;
    void* p1=memset(line1,letter,len);
    void* p2=s21_memset(line2,letter,len);
    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(memset(line1,letter,len),s21_memset(line2,letter,len));
    ck_assert_str_eq(p1,memset(line1,letter,len));
    ck_assert_str_eq(p2,s21_memset(line2,letter,len));
    ck_assert_str_eq(p1,s21_memset(line2,letter,len));
    ck_assert_str_eq(p2,memset(line1,letter,len));
    ck_assert_str_eq(line1,p1);
    ck_assert_str_eq(line2,p2);
    ck_assert_str_eq(line1,line2);
    ck_assert_str_eq(line1,p2);
    ck_assert_str_eq(line2,p1);
}
/*  (*0)
if we didn't locate enough space for string - we got errors(owerlapping: memset(line1,letter,len) == "fffgg��~�", s21_memset(line2,letter,len) == "fffggfffgg��~�")
START_TEST(test_memset_normal_1) {
    char line1[5] = FRIVE_CHAR_1;
    char line2[5] = FRIVE_CHAR_1;
    char letter = 'f';
    int len = 3;
    ck_assert_str_eq(memset(line1,letter,len),s21_memset(line2,letter,len));
    ck_assert_str_eq(line1,line2);
}
*/
//2.1
START_TEST(test_memset_normal_1) {
    char line1[6] = FRIVE_CHAR_1;
    char line2[6] = FRIVE_CHAR_1;
    char letter = 'f';
    int len = 3;
    void* p1=memset(line1,letter,len);
    void* p2=s21_memset(line2,letter,len);
    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);
}
START_TEST(test_memset_normal_2) {
    char line1[6] = FRIVE_CHAR_1;
    char line2[6] = FRIVE_CHAR_1;
    char letter = 'f';
    int len = 1;
    void* p1=memset(line1,letter,len);
    void* p2=s21_memset(line2,letter,len);
    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);
}
//2.2
START_TEST(test_memset_nullline) {
    char line1[5] = NULL_LINE;
    char line2[5] = NULL_LINE;
    char letter = 'f';
    int len = 3;
    void* p1=memset(line1,letter,len);
    void* p2=s21_memset(line2,letter,len);
    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);
}
// //(*4.2)  Werror does not like these: ‘memset’ writing 2 bytes into a region of size 0 overflows the destination
// START_TEST(test_memset_zeroline) {
//     char line1[0];
//     char line2[0];
//     char letter = 'f';
//     int len = 2;
//     void* p1=memset(line1,letter,len);
//     void* p2=s21_memset(line2,letter,len);
//     ck_assert_str_eq(p1,p2);
//     ck_assert_str_eq(line1,line2);
// }

/*  //(*1.1) Segmentation fault (core dumped)  -  both original and our strlen
START_TEST(test_memset_absolutenullline) {
    char* line1=NULL;
    char* line2=NULL;
    char letter = 'f';
    int len = 2;
    void* p1=memset(line1,letter,len);
    void* p2=s21_memset(line2,letter,len);
    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);
}
*/
//2.3
START_TEST(test_memset_numzero) {
    char line1[6] = FRIVE_CHAR_1;
    char line2[6] = FRIVE_CHAR_1;
    char letter = 'f';
    int len = 0;
    void* p1=memset(line1,letter,len);
    void* p2=s21_memset(line2,letter,len);
    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);
}
/*
(*2) There is an error acquired due to the fact that "memset" works with raw memory, 
so if you give it more that the length of the original string, it overflows and 
does not put '\0' at the end. As the result the output is unpredictable.
p1 == "ffffffff�#�*�", p2 == "ffffffffffffffff�#�*�"
*/

/*
(*3) not sure how memset works outside of the given str length. Memory works illogical it that zone.
memset_nummore_4: line1 == "ffffffff�#�*�", line2 == "ffffffffffffffff�#�*�"
*/

// //(*4.2)  Werror does not like  ‘memset’ writing more bytes into a region than its size   --->  overflows the destination
// START_TEST(test_memset_nummore_1) {
//     char line1[6] = FRIVE_CHAR_1;
//     char line2[6] = FRIVE_CHAR_1;
//     char letter = 'f';
//     int len = 7;
//     void* p1=memset(line1,letter,len);
//     void* p2=s21_memset(line2,letter,len);
//     //ck_assert_str_eq(memset(line1,letter,len),s21_memset(line2,letter,len));  //(*2)
//     ck_assert_mem_eq(p1,p2,6);
//     ck_assert_mem_eq(p1,p2,len);
//     //ck_assert_str_eq(line1,line2);  //(*2)
//     ck_assert_mem_eq(line1,line2,6);
//     ck_assert_ptr_eq(line1,p1);
//     ck_assert_ptr_eq(line2,p2);   
//     //ck_assert_mem_eq(line1,line2,len); //(*3) 
// }
// //(*4.2)  Werror does not like  ‘memset’ writing more bytes into a region than its size   --->  overflows the destination
// START_TEST(test_memset_nummore_2) {
//     char line1[6] = FRIVE_CHAR_1;
//     char line2[6] = FRIVE_CHAR_1;
//     char letter = 'f';
//     int len = 9;
//     void* p1=memset(line1,letter,len);
//     void* p2=s21_memset(line2,letter,len);
//     //ck_assert_str_eq(p1,p2);    //(*2)
//     ck_assert_mem_eq(p1,p2,6);
//     ck_assert_mem_eq(p1,p2,len);
//     ck_assert_mem_eq(line1,line2,6);
//     ck_assert_ptr_eq(line1,p1);
//     ck_assert_ptr_eq(line2,p2); 
//     //ck_assert_mem_eq(line1,line2,len); //(*3) 
//     //ck_assert_str_eq(line1,line2);  //(*2)
// }
// //(*4.2)  Werror does not like  ‘memset’ writing more bytes into a region than its size   --->  overflows the destination
// START_TEST(test_memset_nummore_3) {
//     char line1[8] = FRIVE_CHAR_1;
//     char line2[8] = FRIVE_CHAR_1;
//     char letter = 'f';
//     int len = 9;
//     void* p1=memset(line1,letter,len);
//     void* p2=s21_memset(line2,letter,len);
//     //ck_assert_str_eq(p1,p2);    //(*2)
//     ck_assert_mem_eq(p1,p2,8);
//     ck_assert_mem_eq(p1,p2,len);
//     ck_assert_mem_eq(line1,line2,8);
//     ck_assert_ptr_eq(line1,p1);
//     ck_assert_ptr_eq(line2,p2); 
//     //ck_assert_str_eq(line1,line2);  //(*2)
// }
// //(*4.2)  Werror does not like  ‘memset’ writing more bytes into a region than its size   --->  overflows the destination
// START_TEST(test_memset_nummore_4) {
//     char line1[8] = FRIVE_CHAR_1;
//     char line2[8] = FRIVE_CHAR_1;
//     char letter = 'f';
//     int len = 13;
//     void* p1=memset(line1,letter,len);
//     void* p2=s21_memset(line2,letter,len);
//     //ck_assert_str_eq(p1,p2);    //(*2)
//     ck_assert_mem_eq(p1,p2,8);
//     ck_assert_mem_eq(p1,p2,len);
//     ck_assert_mem_eq(line1,line2,8);
//     ck_assert_ptr_eq(line1,p1);
//     ck_assert_ptr_eq(line2,p2); 
//     //ck_assert_str_eq(line1,line2);  //(*2)
// }
START_TEST(test_memset_nummore_5) {
    char line1[10] = FRIVE_CHAR_1;
    char line2[10] = FRIVE_CHAR_1;
    char letter = 'f';
    int len = 8;
    void* p1=memset(line1,letter,len);
    void* p2=s21_memset(line2,letter,len);
    //ck_assert_str_eq(p1,p2);    //(*2)
    ck_assert_mem_eq(p1,p2,10);
    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,10);
    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
    //ck_assert_str_eq(line1,line2);  //(*2)
}
START_TEST(test_memset_numsame) {
    char line1[6] = FRIVE_CHAR_1;
    char line2[6] = FRIVE_CHAR_1;
    char letter = 'f';
    int len = 6;
    void* p1=memset(line1,letter,len);
    void* p2=s21_memset(line2,letter,len);
    //ck_assert_str_eq(p1,p2);    //(*2)
    ck_assert_mem_eq(p1,p2,6);
    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,6);
    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
    //ck_assert_str_eq(line1,line2);  //(*2)
}
//2.4
START_TEST(test_memset_charenter) {
    char line1[6] = FRIVE_CHAR_1;
    char line2[6] = FRIVE_CHAR_1;
    char letter = '\n';
    int len = 3;
    void* p1=memset(line1,letter,len);
    void* p2=s21_memset(line2,letter,len);
    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);
}
START_TEST(test_memset_charspace) {
    char line1[6] = FRIVE_CHAR_1;
    char line2[6] = FRIVE_CHAR_1;
    char letter = ' ';
    int len = 3;
    void* p1=memset(line1,letter,len);
    void* p2=s21_memset(line2,letter,len);
    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);
}
START_TEST(test_memset_chartab) {
    char line1[6] = FRIVE_CHAR_1;
    char line2[6] = FRIVE_CHAR_1;
    char letter = '\t';
    int len = 3;
    void* p1=memset(line1,letter,len);
    void* p2=s21_memset(line2,letter,len);
    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);
}
START_TEST(test_memset_charnull) {
    char line1[6] = FRIVE_CHAR_1;
    char line2[6] = FRIVE_CHAR_1;
    char letter = '\0';
    int len = 3;
    void* p1=memset(line1,letter,len);
    void* p2=s21_memset(line2,letter,len);
    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);
}
START_TEST(test_memset_charinvis_1) {
    char line1[6] = FRIVE_CHAR_1;
    char line2[6] = FRIVE_CHAR_1;
    char letter = 6;
    int len = 3;
    void* p1=memset(line1,letter,len);
    void* p2=s21_memset(line2,letter,len);
    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);
}
START_TEST(test_memset_charinvis_2) {
    char line1[6] = FRIVE_CHAR_1;
    char line2[6] = FRIVE_CHAR_1;
    char letter = 20;
    int len = 3;
    void* p1=memset(line1,letter,len);
    void* p2=s21_memset(line2,letter,len);
    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);
}
START_TEST(test_memset_charinvis_3) {
    char line1[6] = FRIVE_CHAR_1;
    char line2[6] = FRIVE_CHAR_1;
    char letter = 15;
    int len = 3;
    void* p1=memset(line1,letter,len);
    void* p2=s21_memset(line2,letter,len);
    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);
}
//2.5
/*//(*6.1) Segmentation fault (core dumped)  -  both original and our strlen
START_TEST(test_memset_numerror) {
    char line1[6] = FRIVE_CHAR_1;
    char line2[6] = FRIVE_CHAR_1;
    char letter = 'g';
    int len = -3;
    void* p1=s21_memset(line1,letter,len);
    void* p2=s21_memset(line2,letter,len);
    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);
}
*/
//2.6
START_TEST(test_memset_midline_1) {
    char line1[5] = ENTER_MID_line;
    char line2[5] = ENTER_MID_line;
    char letter = 'g';
    int len = 3;
    void* p1=memset(line1,letter,len);
    void* p2=s21_memset(line2,letter,len);
    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);
}
START_TEST(test_memset_midline_2) {
    char line1[5] = NULL_MID_line;
    char line2[5] = NULL_MID_line;
    char letter = 'g';
    int len = 2;
    void* p1=memset(line1,letter,len);
    void* p2=s21_memset(line2,letter,len);
    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);
}
START_TEST(test_memset_midline_3) {
    char line1[5] = NULL_MID_line;
    char line2[5] = NULL_MID_line;
    char letter = 'g';
    int len = 3;
    void* p1=memset(line1,letter,len);
    void* p2=s21_memset(line2,letter,len);
    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);
}
START_TEST(test_memset_midline_4) {
    char line1[5] = NULL_MID_line;
    char line2[5] = NULL_MID_line;
    char letter = 'g';
    int len = 4;
    void* p1=memset(line1,letter,len);
    void* p2=s21_memset(line2,letter,len);
    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);
}
//2.7
//-->werror
// START_TEST(test_memset_long_1) {
//     char line1[6] = FRIVE_CHAR_1;
//     char line2[6] = FRIVE_CHAR_1;
//     char letter = 'f';
//     int len = 9;
//     void* p1=memset(line1,letter,len);
//     void* p2=s21_memset(line2,letter,len);
//     ck_assert_mem_eq(p1,p2,6);
//     ck_assert_mem_eq(p1,p2,len);
//     ck_assert_mem_eq(line1,line2,6);
//     ck_assert_ptr_eq(line1,p1);
//     ck_assert_ptr_eq(line2,p2); 
// }
START_TEST(test_memset_long_2) {
    char line1[LONG_CHECK_LINE] = NULL_LINE;
    char line2[LONG_CHECK_LINE] = NULL_LINE;
    rand_str(line1,LONG_CHECK_LINE-1);
    strcpy(line2,line1);
    char letter = 'f';
    int len = 9;
    void* p1=memset(line1,letter,len);
    void* p2=s21_memset(line2,letter,len);
    ck_assert_mem_eq(p1,p2,LONG_CHECK_LINE);
    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,LONG_CHECK_LINE);
    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);
    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_memset_long_3) {
    char line1[LONG_CHECK_LINE] = NULL_LINE;
    char line2[LONG_CHECK_LINE] = NULL_LINE;
    rand_str(line1,LONG_CHECK_LINE-1);
    strcpy(line2,line1);
    char letter = 'f';
    int len = LONG_CHECK_LINE-1;
    void* p1=memset(line1,letter,len);
    void* p2=s21_memset(line2,letter,len);
    ck_assert_mem_eq(p1,p2,LONG_CHECK_LINE);
    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,LONG_CHECK_LINE);
    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);
    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_memset_long_4) {
    char line1[LONG_CHECK_LINE] = NULL_LINE;
    char line2[LONG_CHECK_LINE] = NULL_LINE;
    rand_str(line1,LONG_CHECK_LINE-1);
    strcpy(line2,line1);
    char letter = 'f';
    int len = LONG_CHECK_LINE;
    void* p1=memset(line1,letter,len);
    void* p2=memset(line2,letter,len);
    ck_assert_mem_eq(p1,p2,LONG_CHECK_LINE);
    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,LONG_CHECK_LINE);
    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
//s21_memcpy
//3.0
START_TEST(test_memcpy_pointertes) {
    char line1[6] = FRIVE_CHAR_1;
    char line2[6] = FRIVE_CHAR_1;
    char sourceline[6] = FRIVE_CHAR_2;
    int len = 4;
    void* p1=memcpy(line1,sourceline,len);
    void* p2=s21_memcpy(line2,sourceline,len);
    ck_assert_str_eq(p1,line1);
    ck_assert_str_eq(p2,line2);
    ck_assert_ptr_eq(p1,line1);
    ck_assert_ptr_eq(p2,line2);
    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);
    ck_assert_str_eq(memcpy(line1,sourceline,len),s21_memcpy(line2,sourceline,len));    
}
//3.1
START_TEST(test_memcpy_norm) {
    char line1[6] = FRIVE_CHAR_1;
    char line2[6] = FRIVE_CHAR_1;
    char sourceline[6] = FRIVE_CHAR_2;
    int len = 4;
    void* p1=memcpy(line1,sourceline,len);
    void* p2=s21_memcpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,6);
    ck_assert_mem_eq(line1,line2,6);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
//3.2
START_TEST(test_memcpy_nullend_1) {
    char line1[5] = NULL_END_line;
    char line2[5] = NULL_END_line;
    char sourceline[5] = TAB_END_line;
    int len = 3;
    void* p1=memcpy(line1,sourceline,len);
    void* p2=s21_memcpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,5);
    ck_assert_mem_eq(line1,line2,5);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_memcpy_nullend_2) {
    char line1[5] = NULL_END_line;
    char line2[5] = NULL_END_line;
    char sourceline[5] = TAB_END_line;
    int len = 4;
    void* p1=memcpy(line1,sourceline,len);
    void* p2=s21_memcpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,5);
    ck_assert_mem_eq(line1,line2,5);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_memcpy_nullmid_1) {
    char line1[5] = NULL_MID_line;
    char line2[5] = NULL_MID_line;
    char sourceline[5] = TAB_END_line;
    int len = 2;
    void* p1=memcpy(line1,sourceline,len);
    void* p2=s21_memcpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,5);
    ck_assert_mem_eq(line1,line2,5);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_memcpy_nullmid_2) {
    char line1[5] = NULL_MID_line;
    char line2[5] = NULL_MID_line;
    char sourceline[5] = TAB_END_line;
    int len = 3;
    void* p1=memcpy(line1,sourceline,len);
    void* p2=s21_memcpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,5);
    ck_assert_mem_eq(line1,line2,5);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_memcpy_nullmid_3) {
    char line1[5] = NULL_MID_line;
    char line2[5] = NULL_MID_line;
    char sourceline[5] = TAB_END_line;
    int len = 4;
    void* p1=memcpy(line1,sourceline,len);
    void* p2=s21_memcpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,5);
    ck_assert_mem_eq(line1,line2,5);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_memcpy_entermid_1) {
    char line1[5] = ENTER_MID_line;
    char line2[5] = ENTER_MID_line;
    char sourceline[5] = TAB_END_line;
    int len = 2;
    void* p1=memcpy(line1,sourceline,len);
    void* p2=s21_memcpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,5);
    ck_assert_mem_eq(line1,line2,5);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_memcpy_entermid_2) {
    char line1[5] = ENTER_MID_line;
    char line2[5] = ENTER_MID_line;
    char sourceline[5] = TAB_END_line;
    int len = 3;
    void* p1=memcpy(line1,sourceline,len);
    void* p2=s21_memcpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,5);
    ck_assert_mem_eq(line1,line2,5);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_memcpy_entermid_3) {
    char line1[5] = ENTER_MID_line;
    char line2[5] = ENTER_MID_line;
    char sourceline[5] = TAB_END_line;
    int len = 4;
    void* p1=memcpy(line1,sourceline,len);
    void* p2=s21_memcpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,5);
    ck_assert_mem_eq(line1,line2,5);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_memcpy_invis_1) {
    char line1[33] = INVIS_CHAR;
    char line2[33] = INVIS_CHAR;
    char sourceline[5] = TAB_END_line;
    int len = 4;
    void* p1=memcpy(line1,sourceline,len);
    void* p2=s21_memcpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,33);
    ck_assert_mem_eq(line1,line2,33);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_memcpy_invis_2) {
    char line1[33] = INVIS_CHAR;
    char line2[33] = INVIS_CHAR;
    char sourceline[33] = INVIS_CHAR;
    int len = 4;
    void* p1=memcpy(line1,sourceline,len);
    void* p2=s21_memcpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,33);
    ck_assert_mem_eq(line1,line2,33);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_memcpy_invis_3) {
    char line1[33] = INVIS_CHAR;
    char line2[33] = INVIS_CHAR;
    char sourceline[33] = INVIS_CHAR;
    int len = 32;
    void* p1=memcpy(line1,sourceline,len);
    void* p2=s21_memcpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,33);
    ck_assert_mem_eq(line1,line2,33);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
//3.3
START_TEST(test_memcpy_different_n_1) {
    char line1[6] = FRIVE_CHAR_1;
    char line2[6] = FRIVE_CHAR_1;
    char sourceline[6] = FRIVE_CHAR_2;
    int len = 0;
    void* p1=memcpy(line1,sourceline,len);
    void* p2=s21_memcpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,6);
    ck_assert_mem_eq(line1,line2,6);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_memcpy_different_n_2) {
    char line1[6] = FRIVE_CHAR_1;
    char line2[6] = FRIVE_CHAR_1;
    char sourceline[6] = FRIVE_CHAR_2;
    int len = 5;
    void* p1=memcpy(line1,sourceline,len);
    void* p2=s21_memcpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,6);
    ck_assert_mem_eq(line1,line2,6);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_memcpy_different_n_3) {
    char line1[6] = FRIVE_CHAR_1;
    char line2[6] = FRIVE_CHAR_1;
    char sourceline[6] = FRIVE_CHAR_2;
    int len = 6;
    void* p1=memcpy(line1,sourceline,len);
    void* p2=s21_memcpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,6);
    ck_assert_mem_eq(line1,line2,6);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
/*
--->overlapping:
START_TEST(test_memcpy_different_n_4) {
    char line1[6] = FRIVE_CHAR_1;
    char line2[6] = FRIVE_CHAR_1;
    char sourceline[8] = SEVEN_CHAR;
    int len = 7;
    void* p1=memcpy(line1,sourceline,len);
    void* p2=s21_memcpy(line2,sourceline,len);

    //ck_assert_str_eq(p1,p2);
    //ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,6);
    ck_assert_mem_eq(line1,line2,6);

    //ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_memcpy_different_n_5) {
    char line1[6] = FRIVE_CHAR_1;
    char line2[6] = FRIVE_CHAR_1;
    char sourceline[8] = SEVEN_CHAR;
    int len = 8;
    void* p1=memcpy(line1,sourceline,len);
    void* p2=s21_memcpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,6);
    ck_assert_mem_eq(line1,line2,6);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_memcpy_different_n_8) {
    char line1[6] = FRIVE_CHAR_1;
    char line2[6] = FRIVE_CHAR_1;
    char sourceline[5] = FOUR_CHAR;
    int len = 10;
    void* p1=memcpy(line1,sourceline,len);
    void* p2=s21_memcpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,6);
    ck_assert_mem_eq(line1,line2,6);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}

--->probably the same because of size_t
START_TEST(test_memcpy_different_n_9) {
    char line1[6] = FRIVE_CHAR_1;
    char line2[6] = FRIVE_CHAR_1;
    char sourceline[5] = FOUR_CHAR;
    size_t len = -3;
    void* p1=memcpy(line1,sourceline,len);
    void* p2=s21_memcpy(line2,sourceline,len);
    printf("%s---%s\n",line1,line2);
    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,6);
    ck_assert_mem_eq(line1,line2,6);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
*/
START_TEST(test_memcpy_different_n_6) {
    char line1[6] = FRIVE_CHAR_1;
    char line2[6] = FRIVE_CHAR_1;
    char sourceline[5] = FOUR_CHAR;
    int len = 4;
    void* p1=memcpy(line1,sourceline,len);
    void* p2=s21_memcpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,6);
    ck_assert_mem_eq(line1,line2,6);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_memcpy_different_n_7) {
    char line1[6] = FRIVE_CHAR_1;
    char line2[6] = FRIVE_CHAR_1;
    char sourceline[5] = FOUR_CHAR;
    int len = 5;
    void* p1=memcpy(line1,sourceline,len);
    void* p2=s21_memcpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,6);
    ck_assert_mem_eq(line1,line2,6);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
//3.4
START_TEST(test_memcpy_nullline_1) {
    char line1[6] = FRIVE_CHAR_1;
    char line2[6] = FRIVE_CHAR_1;
    char sourceline[5] = NULL_LINE;
    int len = 3;
    void* p1=memcpy(line1,sourceline,len);
    void* p2=s21_memcpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,6);
    ck_assert_mem_eq(line1,line2,6);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_memcpy_nullline_2) {
    char line1[NORMLINES_SIX] = NULL_LINE;
    char line2[NORMLINES_SIX] = NULL_LINE;
    char sourceline[6] = FRIVE_CHAR_1;
    int len = 3;
    void* p1=memcpy(line1,sourceline,len);
    void* p2=s21_memcpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,NORMLINES_SIX);
    ck_assert_mem_eq(line1,line2,NORMLINES_SIX);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
//3.5
START_TEST(test_memcpy_long_1) {
    char line1[LONG_CHECK_LINE] = NULL_LINE;
    char line2[LONG_CHECK_LINE] = NULL_LINE;
    rand_str(line1,LONG_CHECK_LINE-1);
    strcpy(line2,line1);
    char sourceline[6] = FRIVE_CHAR_1;
    int len = 5;
    void* p1=memcpy(line1,sourceline,len);
    void* p2=s21_memcpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,LONG_CHECK_LINE);
    ck_assert_mem_eq(line1,line2,LONG_CHECK_LINE);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_memcpy_long_2) {
    char line1[LONG_CHECK_LINE] = NULL_LINE;
    char line2[LONG_CHECK_LINE] = NULL_LINE;
    rand_str(line1,LONG_CHECK_LINE-1);
    strcpy(line2,line1);
    char sourceline[LONG_CHECK_LINE] = NULL_LINE;
    int len = 5;
    void* p1=memcpy(line1,sourceline,len);
    void* p2=s21_memcpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,LONG_CHECK_LINE);
    ck_assert_mem_eq(line1,line2,LONG_CHECK_LINE);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_memcpy_long_3) {
    char line1[LONG_CHECK_LINE] = NULL_LINE;
    char line2[LONG_CHECK_LINE] = NULL_LINE;
    rand_str(line1,LONG_CHECK_LINE-1);
    strcpy(line2,line1);
    char sourceline[LONG_CHECK_LINE] = NULL_LINE;
    rand_str(sourceline,LONG_CHECK_LINE-1);
    int len = LONG_CHECK_LINE-1;
    void* p1=memcpy(line1,sourceline,len);
    void* p2=s21_memcpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,LONG_CHECK_LINE);
    ck_assert_mem_eq(line1,line2,LONG_CHECK_LINE);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_memcpy_long_4) {
    char line1[LONG_CHECK_LINE] = NULL_LINE;
    char line2[LONG_CHECK_LINE] = NULL_LINE;
    rand_str(line1,LONG_CHECK_LINE-1);
    strcpy(line2,line1);
    char sourceline[LONG_CHECK_LINE] = NULL_LINE;
    rand_str(sourceline,LONG_CHECK_LINE-1);
    int len = LONG_CHECK_LINE;
    void* p1=memcpy(line1,sourceline,len);
    void* p2=s21_memcpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,LONG_CHECK_LINE);
    ck_assert_mem_eq(line1,line2,LONG_CHECK_LINE);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}

//s21_strncpy 
//4.0
START_TEST(test_strncpy_pointertes) {
    char line1[6] = FRIVE_CHAR_1;
    char line2[6] = FRIVE_CHAR_1;
    char sourceline[6] = FRIVE_CHAR_2;
    int len = 4;
    void* p1=strncpy(line1,sourceline,len);
    void* p2=s21_strncpy(line2,sourceline,len);
    ck_assert_str_eq(p1,line1);
    ck_assert_str_eq(p2,line2);
    ck_assert_ptr_eq(p1,line1);
    ck_assert_ptr_eq(p2,line2);
    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);
    ck_assert_str_eq(strncpy(line1,sourceline,len),s21_strncpy(line2,sourceline,len));    
}
//4.1
START_TEST(test_strncpy_norm_1) {
    char line1[6] = FRIVE_CHAR_1;
    char line2[6] = FRIVE_CHAR_1;
    char sourceline[6] = FRIVE_CHAR_2;
    int len = 4;
    void* p1=strncpy(line1,sourceline,len);
    void* p2=s21_strncpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,6);
    ck_assert_mem_eq(line1,line2,6);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncpy_norm_2) {
    char line1[6] = FRIVE_CHAR_1;
    char line2[6] = FRIVE_CHAR_1;
    char sourceline[6] = FRIVE_CHAR_2;
    int len = 5;
    void* p1=strncpy(line1,sourceline,len);
    void* p2=s21_strncpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,6);
    ck_assert_mem_eq(line1,line2,6);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
//4.2
START_TEST(test_strncpy_nullend_1) {
    char line1[5] = NULL_END_line;
    char line2[5] = NULL_END_line;
    char sourceline[5] = TAB_END_line;
    int len = 3;
    void* p1=strncpy(line1,sourceline,len);
    void* p2=s21_strncpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,5);
    ck_assert_mem_eq(line1,line2,5);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncpy_nullend_2) {
    char line1[5] = NULL_END_line;
    char line2[5] = NULL_END_line;
    char sourceline[5] = TAB_END_line;
    int len = 4;
    void* p1=strncpy(line1,sourceline,len);
    void* p2=s21_strncpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,5);
    ck_assert_mem_eq(line1,line2,5);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncpy_nullmid_1) {
    char line1[5] = NULL_MID_line;
    char line2[5] = NULL_MID_line;
    char sourceline[5] = TAB_END_line;
    int len = 2;
    void* p1=strncpy(line1,sourceline,len);
    void* p2=s21_strncpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,5);
    ck_assert_mem_eq(line1,line2,5);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncpy_nullmid_2) {
    char line1[5] = NULL_MID_line;
    char line2[5] = NULL_MID_line;
    char sourceline[5] = TAB_END_line;

    int len = 3;
    void* p1=strncpy(line1,sourceline,len);
    void* p2=s21_strncpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,5);
    ck_assert_mem_eq(line1,line2,5);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncpy_nullmid_3) {
    char line1[5] = NULL_MID_line;
    char line2[5] = NULL_MID_line;
    char sourceline[5] = TAB_END_line;
    int len = 4;
    void* p1=strncpy(line1,sourceline,len);
    void* p2=s21_strncpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,5);
    ck_assert_mem_eq(line1,line2,5);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncpy_entermid_1) {
    char line1[5] = ENTER_MID_line;
    char line2[5] = ENTER_MID_line;
    char sourceline[5] = TAB_END_line;
    int len = 2;
    void* p1=strncpy(line1,sourceline,len);
    void* p2=s21_strncpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,5);
    ck_assert_mem_eq(line1,line2,5);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncpy_entermid_2) {
    char line1[5] = ENTER_MID_line;
    char line2[5] = ENTER_MID_line;
    char sourceline[5] = TAB_END_line;
    int len = 3;
    void* p1=strncpy(line1,sourceline,len);
    void* p2=s21_strncpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,5);
    ck_assert_mem_eq(line1,line2,5);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncpy_entermid_3) {
    char line1[5] = ENTER_MID_line;
    char line2[5] = ENTER_MID_line;
    char sourceline[5] = TAB_END_line;
    int len = 4;
    void* p1=strncpy(line1,sourceline,len);
    void* p2=s21_strncpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,5);
    ck_assert_mem_eq(line1,line2,5);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncpy_invis_1) {
    char line1[33] = INVIS_CHAR;
    char line2[33] = INVIS_CHAR;
    char sourceline[5] = TAB_END_line;
    int len = 4;
    void* p1=strncpy(line1,sourceline,len);
    void* p2=s21_strncpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,33);
    ck_assert_mem_eq(line1,line2,33);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncpy_invis_2) {
    char line1[33] = INVIS_CHAR;
    char line2[33] = INVIS_CHAR;
    char sourceline[33] = INVIS_CHAR;
    int len = 4;
    void* p1=strncpy(line1,sourceline,len);
    void* p2=s21_strncpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,33);
    ck_assert_mem_eq(line1,line2,33);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncpy_invis_3) {
    char line1[33] = INVIS_CHAR;
    char line2[33] = INVIS_CHAR;
    char sourceline[33] = INVIS_CHAR;
    int len = 32;
    void* p1=strncpy(line1,sourceline,len);
    void* p2=s21_strncpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,33);
    ck_assert_mem_eq(line1,line2,33);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
//4.3
START_TEST(test_strncpy_different_n_1) {
    char line1[6] = FRIVE_CHAR_1;
    char line2[6] = FRIVE_CHAR_1;
    char sourceline[6] = FRIVE_CHAR_2;
    int len = 0;
    void* p1=strncpy(line1,sourceline,len);
    void* p2=s21_strncpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,6);
    ck_assert_mem_eq(line1,line2,6);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncpy_different_n_2) {
    char line1[6] = FRIVE_CHAR_1;
    char line2[6] = FRIVE_CHAR_1;
    char sourceline[6] = FRIVE_CHAR_2;
    int len = 5;
    void* p1=strncpy(line1,sourceline,len);
    void* p2=s21_strncpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,6);
    ck_assert_mem_eq(line1,line2,6);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncpy_different_n_3) {
    char line1[6] = FRIVE_CHAR_1;
    char line2[6] = FRIVE_CHAR_1;
    char sourceline[6] = FRIVE_CHAR_2;
    int len = 6;
    void* p1=strncpy(line1,sourceline,len);
    void* p2=s21_strncpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,6);
    ck_assert_mem_eq(line1,line2,6);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
/*
//--->overlapping:
START_TEST(test_strncpy_different_n_4) {
    char line1[6] = FRIVE_CHAR_1;
    char line2[6] = FRIVE_CHAR_1;
    char sourceline[8] = SEVEN_CHAR;
    int len = 7;
    void* p1=strncpy(line1,sourceline,len);
    void* p2=s21_strncpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,6);
    ck_assert_mem_eq(line1,line2,6);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncpy_different_n_5) {
    char line1[6] = FRIVE_CHAR_1;
    char line2[6] = FRIVE_CHAR_1;
    char sourceline[8] = SEVEN_CHAR;
    int len = 8;
    void* p1=strncpy(line1,sourceline,len);
    void* p2=s21_strncpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,6);
    ck_assert_mem_eq(line1,line2,6);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncpy_different_n_8) {
    char line1[6] = FRIVE_CHAR_1;
    char line2[6] = FRIVE_CHAR_1;
    char sourceline[5] = FOUR_CHAR;
    int len = 10;
    void* p1=strncpy(line1,sourceline,len);
    void* p2=s21_strncpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,6);
    ck_assert_mem_eq(line1,line2,6);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}

//--->probably the same because of size_t
START_TEST(test_strncpy_different_n_9) {
    char line1[6] = FRIVE_CHAR_1;
    char line2[6] = FRIVE_CHAR_1;
    char sourceline[5] = FOUR_CHAR;
    size_t len = -3;
    void* p1=strncpy(line1,sourceline,len);
    void* p2=strncpy(line2,sourceline,len);
    //printf("%s---%s\n",line1,line2);
    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,6);
    ck_assert_mem_eq(line1,line2,6);

    //ck_assert_mem_eq(p1,p2,len);
    //ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
*/
START_TEST(test_strncpy_different_n_6) {
    char line1[6] = FRIVE_CHAR_1;
    char line2[6] = FRIVE_CHAR_1;
    char sourceline[5] = FOUR_CHAR;
    int len = 4;
    void* p1=strncpy(line1,sourceline,len);
    void* p2=s21_strncpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,6);
    ck_assert_mem_eq(line1,line2,6);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncpy_different_n_7) {
    char line1[6] = FRIVE_CHAR_1;
    char line2[6] = FRIVE_CHAR_1;
    char sourceline[5] = FOUR_CHAR;
    int len = 5;
    void* p1=strncpy(line1,sourceline,len);
    void* p2=s21_strncpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,6);
    ck_assert_mem_eq(line1,line2,6);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncpy_different_n_10) {
    char line1[8] = FRIVE_CHAR_1;
    char line2[8] = FRIVE_CHAR_1;
    char sourceline[5] = FOUR_CHAR;
    int len = 6;
    void* p1=strncpy(line1,sourceline,len);
    void* p2=s21_strncpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,8);
    ck_assert_mem_eq(line1,line2,8);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncpy_different_n_11) {
    char line1[10] = "ggggggggg";
    char line2[10] = "ggggggggg";
    char sourceline[5] = FOUR_CHAR;
    int len = 9;
    void* p1=strncpy(line1,sourceline,len);
    void* p2=s21_strncpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,10);
    ck_assert_mem_eq(line1,line2,10);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncpy_different_n_12) {
    char line1[10] = FRIVE_CHAR_1;
    char line2[10] = FRIVE_CHAR_1;
    char sourceline[5] = FOUR_CHAR;
    int len = 5;
    void* p1=strncpy(line1,sourceline,len);
    void* p2=s21_strncpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,10);
    ck_assert_mem_eq(line1,line2,10);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
//4.4
START_TEST(test_strncpy_nullline_1) {
    char line1[6] = FRIVE_CHAR_1;
    char line2[6] = FRIVE_CHAR_1;
    char sourceline[5] = NULL_LINE;
    int len = 3;
    void* p1=strncpy(line1,sourceline,len);
    void* p2=s21_strncpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,6);
    ck_assert_mem_eq(line1,line2,6);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncpy_nullline_2) {
    char line1[NORMLINES_SIX] = NULL_LINE;
    char line2[NORMLINES_SIX] = NULL_LINE;
    char sourceline[NORMLINES_SIX] = FRIVE_CHAR_1;
    int len = 3;
    void* p1=strncpy(line1,sourceline,len);
    void* p2=s21_strncpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,NORMLINES_SIX);
    ck_assert_mem_eq(line1,line2,NORMLINES_SIX);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
//4.5
START_TEST(test_strncpy_long_1) {
    char line1[LONG_CHECK_LINE] = NULL_LINE;
    char line2[LONG_CHECK_LINE] = NULL_LINE;
    rand_str(line1,LONG_CHECK_LINE-1);
    strcpy(line2,line1);
    char sourceline[6] = FRIVE_CHAR_1;
    int len = 5;
    void* p1=strncpy(line1,sourceline,len);
    void* p2=s21_strncpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,LONG_CHECK_LINE);
    ck_assert_mem_eq(line1,line2,LONG_CHECK_LINE);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncpy_long_2) {
    char line1[LONG_CHECK_LINE] = NULL_LINE;
    char line2[LONG_CHECK_LINE] = NULL_LINE;
    rand_str(line1,LONG_CHECK_LINE-1);
    strcpy(line2,line1);
    char sourceline[LONG_CHECK_LINE] = NULL_LINE;
    int len = 5;
    void* p1=strncpy(line1,sourceline,len);
    void* p2=s21_strncpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,LONG_CHECK_LINE);
    ck_assert_mem_eq(line1,line2,LONG_CHECK_LINE);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncpy_long_3) {
    char line1[LONG_CHECK_LINE] = NULL_LINE;
    char line2[LONG_CHECK_LINE] = NULL_LINE;
    rand_str(line1,LONG_CHECK_LINE-1);
    strcpy(line2,line1);
    char sourceline[LONG_CHECK_LINE] = NULL_LINE;
    rand_str(sourceline,LONG_CHECK_LINE-1);
    int len = LONG_CHECK_LINE-1;
    void* p1=strncpy(line1,sourceline,len);
    void* p2=s21_strncpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,LONG_CHECK_LINE);
    ck_assert_mem_eq(line1,line2,LONG_CHECK_LINE);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncpy_long_4) {
    char line1[LONG_CHECK_LINE] = NULL_LINE;
    char line2[LONG_CHECK_LINE] = NULL_LINE;
    rand_str(line1,LONG_CHECK_LINE-1);
    strcpy(line2,line1);
    char sourceline[LONG_CHECK_LINE] = NULL_LINE;
    rand_str(sourceline,LONG_CHECK_LINE-1);
    int len = LONG_CHECK_LINE;
    void* p1=strncpy(line1,sourceline,len);
    void* p2=s21_strncpy(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,LONG_CHECK_LINE);
    ck_assert_mem_eq(line1,line2,LONG_CHECK_LINE);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}

//s21_strncat
//5.0
START_TEST(test_strncat_pointertes) {
    char line1[10] = FRIVE_CHAR_1;
    char line2[10] = FRIVE_CHAR_1;
    char sourceline[6] = FRIVE_CHAR_2;
    int len = 4;
    void* p1=strncat(line1,sourceline,len);
    void* p2=s21_strncat(line2,sourceline,len);
    ck_assert_str_eq(p1,line1);
    ck_assert_str_eq(p2,line2);
    ck_assert_ptr_eq(p1,line1);
    ck_assert_ptr_eq(p2,line2);
    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);
}
//5.1
START_TEST(test_strncat_norm_1) {
    char line1[10] = FRIVE_CHAR_1;
    char line2[10] = FRIVE_CHAR_1;
    char sourceline[6] = FRIVE_CHAR_2;
    int len = 4;
    void* p1=strncat(line1,sourceline,len);
    void* p2=s21_strncat(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,10);
    ck_assert_mem_eq(line1,line2,10);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncat_norm_2) {
    char line1[11] = FRIVE_CHAR_1;
    char line2[11] = FRIVE_CHAR_1;
    char sourceline[6] = FRIVE_CHAR_2;
    int len = 5;
    void* p1=strncat(line1,sourceline,len);
    void* p2=s21_strncat(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,11);
    ck_assert_mem_eq(line1,line2,11);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
//5.2
START_TEST(test_strncat_nullend_1) {
    char line1[11] = NULL_END_line;
    char line2[11] = NULL_END_line;
    char sourceline[5] = TAB_END_line;
    int len = 3;
    void* p1=strncat(line1,sourceline,len);
    void* p2=s21_strncat(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,11);
    ck_assert_mem_eq(line1,line2,11);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncat_nullend_2) {
    char line1[11] = NULL_END_line;
    char line2[11] = NULL_END_line;
    char sourceline[5] = TAB_END_line;
    int len = 4;
    void* p1=strncat(line1,sourceline,len);
    void* p2=s21_strncat(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,11);
    ck_assert_mem_eq(line1,line2,11);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncat_nullend_3) {
    char line1[11] = TAB_END_line;
    char line2[11] = TAB_END_line;
    char sourceline[5] = NULL_END_line;
    int len = 4;
    void* p1=strncat(line1,sourceline,len);
    void* p2=s21_strncat(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,11);
    ck_assert_mem_eq(line1,line2,11);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncat_nullmid_4) {
    char line1[11] = TAB_END_line;
    char line2[11] = TAB_END_line;
    char sourceline[5] = NULL_MID_line;
    int len = 4;
    void* p1=strncat(line1,sourceline,len);
    void* p2=s21_strncat(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,11);
    ck_assert_mem_eq(line1,line2,11);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncat_nullmid_5) {
    char line1[11] = TAB_END_line;
    char line2[11] = TAB_END_line;
    char sourceline[5] = NULL_MID_line;
    int len = 3;
    void* p1=strncat(line1,sourceline,len);
    void* p2=s21_strncat(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,11);
    ck_assert_mem_eq(line1,line2,11);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncat_nullmid_6) {
    char line1[11] = TAB_END_line;
    char line2[11] = TAB_END_line;
    char sourceline[5] = NULL_MID_line;
    int len = 2;
    void* p1=strncat(line1,sourceline,len);
    void* p2=s21_strncat(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,11);
    ck_assert_mem_eq(line1,line2,11);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncat_nullmid_1) {
    char line1[11] = NULL_MID_line;
    char line2[11] = NULL_MID_line;
    char sourceline[5] = TAB_END_line;
    int len = 2;
    void* p1=strncat(line1,sourceline,len);
    void* p2=s21_strncat(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,11);
    ck_assert_mem_eq(line1,line2,11);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncat_nullmid_2) {
    char line1[11] = NULL_MID_line;
    char line2[11] = NULL_MID_line;
    char sourceline[5] = TAB_END_line;

    //printf("%s--%s--%s\n", line1,line2,sourceline);

    int len = 3;
    void* p1=strncat(line1,sourceline,len);
    void* p2=s21_strncat(line2,sourceline,len);

    //printf("%s--%s--%s--%s\n", line1,line2,p1, p2);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,11);
    ck_assert_mem_eq(line1,line2,11);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncat_nullmid_3) {
    char line1[11] = NULL_MID_line;
    char line2[11] = NULL_MID_line;
    char sourceline[5] = TAB_END_line;
    int len = 4;
    void* p1=strncat(line1,sourceline,len);
    void* p2=s21_strncat(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,11);
    ck_assert_mem_eq(line1,line2,11);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncat_entermid_1) {
    char line1[11] = ENTER_MID_line;
    char line2[11] = ENTER_MID_line;
    char sourceline[5] = TAB_END_line;
    int len = 2;
    void* p1=strncat(line1,sourceline,len);
    void* p2=s21_strncat(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,11);
    ck_assert_mem_eq(line1,line2,11);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncat_entermid_2) {
    char line1[11] = ENTER_MID_line;
    char line2[11] = ENTER_MID_line;
    char sourceline[5] = TAB_END_line;
    int len = 3;
    void* p1=strncat(line1,sourceline,len);
    void* p2=s21_strncat(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,11);
    ck_assert_mem_eq(line1,line2,11);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncat_entermid_3) {
    char line1[11] = ENTER_MID_line;
    char line2[11] = ENTER_MID_line;
    char sourceline[5] = TAB_END_line;
    int len = 4;
    void* p1=strncat(line1,sourceline,len);
    void* p2=s21_strncat(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,11);
    ck_assert_mem_eq(line1,line2,11);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncat_invis_1) {
    char line1[38] = INVIS_CHAR;
    char line2[38] = INVIS_CHAR;
    char sourceline[5] = TAB_END_line;
    int len = 4;
    void* p1=strncat(line1,sourceline,len);
    void* p2=s21_strncat(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,38);
    ck_assert_mem_eq(line1,line2,38);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncat_invis_3) {
    char line1[66] = INVIS_CHAR;
    char line2[66] = INVIS_CHAR;
    char sourceline[33] = INVIS_CHAR;
    int len = 32;
    void* p1=strncat(line1,sourceline,len);
    void* p2=s21_strncat(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,66);
    ck_assert_mem_eq(line1,line2,66);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncat_invis_2) {
    char line1[38] = FRIVE_CHAR_1;
    char line2[38] = FRIVE_CHAR_1;
    char sourceline[33] = INVIS_CHAR;
    int len = 32;
    void* p1=strncat(line1,sourceline,len);
    void* p2=s21_strncat(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,38);
    ck_assert_mem_eq(line1,line2,38);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}


//5.3
START_TEST(test_strncat_different_n_1) {
    char line1[6] = FRIVE_CHAR_1;
    char line2[6] = FRIVE_CHAR_1;
    char sourceline[6] = FRIVE_CHAR_2;
    int len = 0;
    void* p1=strncat(line1,sourceline,len);
    void* p2=s21_strncat(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,6);
    ck_assert_mem_eq(line1,line2,6);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncat_different_n_13) {
    char line1[11] = FRIVE_CHAR_1;
    char line2[11] = FRIVE_CHAR_1;
    char sourceline[6] = FRIVE_CHAR_2;
    int len = 0;
    void* p1=strncat(line1,sourceline,len);
    void* p2=s21_strncat(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,11);
    ck_assert_mem_eq(line1,line2,11);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncat_different_n_2) {
    char line1[11] = FRIVE_CHAR_1;
    char line2[11] = FRIVE_CHAR_1;
    char sourceline[6] = FRIVE_CHAR_2;
    int len = 5;
    void* p1=strncat(line1,sourceline,len);
    void* p2=s21_strncat(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,11);
    ck_assert_mem_eq(line1,line2,11);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncat_different_n_3) {
    char line1[12] = FRIVE_CHAR_1;
    char line2[12] = FRIVE_CHAR_1;
    char sourceline[6] = FRIVE_CHAR_2;
    int len = 6;
    void* p1=strncat(line1,sourceline,len);
    void* p2=s21_strncat(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,12);
    ck_assert_mem_eq(line1,line2,12);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncat_different_n_14) {
    char line1[11] = FRIVE_CHAR_1;
    char line2[11] = FRIVE_CHAR_1;
    char sourceline[6] = FRIVE_CHAR_2;
    int len = 6;
    void* p1=s21_strncat(line1,sourceline,len);
    void* p2=strncat(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    //ck_assert_mem_eq(p1,p2,12);
    //ck_assert_mem_eq(line1,line2,12);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncat_different_n_15) {
    char line1[14] = FRIVE_CHAR_1;
    char line2[14] = FRIVE_CHAR_1;
    char sourceline[6] = FRIVE_CHAR_2;
    int len = 7;
    void* p1=strncat(line1,sourceline,len);
    void* p2=s21_strncat(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,14);
    ck_assert_mem_eq(line1,line2,14);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
/*
//--->overlapping:
START_TEST(test_strncat_different_n_4) {
    char line1[6] = FRIVE_CHAR_1;
    char line2[6] = FRIVE_CHAR_1;
    char sourceline[8] = SEVEN_CHAR;
    int len = 7;
    void* p1=strncat(line1,sourceline,len);
    void* p2=s21_strncat(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,6);
    ck_assert_mem_eq(line1,line2,6);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncat_different_n_5) {
    char line1[12] = FRIVE_CHAR_1;
    char line2[12] = FRIVE_CHAR_1;
    char sourceline[8] = SEVEN_CHAR;
    int len = 7;
    void* p1=strncat(line1,sourceline,len);
    void* p2=s21_strncat(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,12);
    ck_assert_mem_eq(line1,line2,12);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncat_different_n_8) {
    char line1[11] = FRIVE_CHAR_1;
    char line2[11] = FRIVE_CHAR_1;
    char sourceline[8] = SEVEN_CHAR;
    int len = 7;
    void* p1=strncat(line1,sourceline,len);
    void* p2=s21_strncat(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,11);
    ck_assert_mem_eq(line1,line2,11);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncat_different_n_6) {
    char line1[6] = FRIVE_CHAR_1;
    char line2[6] = FRIVE_CHAR_1;
    char sourceline[5] = FOUR_CHAR;
    int len = 4;
    void* p1=strncat(line1,sourceline,len);
    void* p2=s21_strncat(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,6);
    ck_assert_mem_eq(line1,line2,6);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncat_different_n_16) {
    char line1[10] = FRIVE_CHAR_1;
    char line2[10] = FRIVE_CHAR_1;
    char sourceline[10] = "HHHHHHHHH";
    int len = 9;
    void* p1=strncat(line1,sourceline,len);
    void* p2=s21_strncat(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,10);
    ck_assert_mem_eq(line1,line2,10);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
//--->probably the same because of size_t
START_TEST(test_strncat_different_n_9) {
    char line1[11] = FRIVE_CHAR_1;
    char line2[11] = FRIVE_CHAR_1;
    char sourceline[5] = FOUR_CHAR;
    size_t len = -3;
    void* p1=strncat(line1,sourceline,len);
    void* p2=s21_strncat(line2,sourceline,len);
    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,11);
    ck_assert_mem_eq(line1,line2,11);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
*/
START_TEST(test_strncat_different_n_11) {
    char line1[14] = "ggggggggg";
    char line2[14] = "ggggggggg";
    char sourceline[5] = FOUR_CHAR;
    int len = 9;
    void* p1=strncat(line1,sourceline,len);
    void* p2=s21_strncat(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,10);
    ck_assert_mem_eq(line1,line2,10);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
//5.4
START_TEST(test_strncat_nullline_1) {
    char line1[9] = FRIVE_CHAR_1;
    char line2[9] = FRIVE_CHAR_1;
    char sourceline[5] = NULL_LINE;
    int len = 3;
    void* p1=strncat(line1,sourceline,len);
    void* p2=s21_strncat(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,9);
    ck_assert_mem_eq(line1,line2,9);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncat_nullline_2) {
    char line1[NORMLINES_SIX*2-1] = NULL_LINE;
    char line2[NORMLINES_SIX*2-1] = NULL_LINE;
    char sourceline[NORMLINES_SIX] = FRIVE_CHAR_1;
    int len = 3;
    void* p1=strncat(line1,sourceline,len);
    void* p2=s21_strncat(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,NORMLINES_SIX*2-1);
    ck_assert_mem_eq(line1,line2,NORMLINES_SIX*2-1);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
//5.5
START_TEST(test_strncat_long_1) {
    char line1[LONG_CHECK_LINE*2-1] = NULL_LINE;
    char line2[LONG_CHECK_LINE*2-1] = NULL_LINE;
    rand_str(line1,LONG_CHECK_LINE-1);
    strcpy(line2,line1);
    char sourceline[6] = FRIVE_CHAR_1;
    int len = 5;
    void* p1=strncat(line1,sourceline,len);
    void* p2=s21_strncat(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,LONG_CHECK_LINE*2-1);
    ck_assert_mem_eq(line1,line2,LONG_CHECK_LINE*2-1);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}

START_TEST(test_strncat_long_2) {
    char line1[LONG_CHECK_LINE*2-1] = NULL_LINE;
    char line2[LONG_CHECK_LINE*2-1] = NULL_LINE;
    rand_str(line1,LONG_CHECK_LINE-1);
    strcpy(line2,line1);
    char sourceline[LONG_CHECK_LINE] = NULL_LINE;
    rand_str(sourceline,LONG_CHECK_LINE-1);
    int len = 5;
    void* p1=strncat(line1,sourceline,len);
    void* p2=s21_strncat(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,LONG_CHECK_LINE*2-1);
    ck_assert_mem_eq(line1,line2,LONG_CHECK_LINE*2-1);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncat_long_3) {
    char line1[LONG_CHECK_LINE*2-1] = NULL_LINE;
    char line2[LONG_CHECK_LINE*2-1] = NULL_LINE;
    rand_str(line1,LONG_CHECK_LINE-1);
    strcpy(line2,line1);
    char sourceline[LONG_CHECK_LINE] = NULL_LINE;
    rand_str(sourceline,LONG_CHECK_LINE-1);
    int len = LONG_CHECK_LINE-1;
    void* p1=strncat(line1,sourceline,len);
    void* p2=s21_strncat(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,LONG_CHECK_LINE*2-1);
    ck_assert_mem_eq(line1,line2,LONG_CHECK_LINE*2-1);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncat_long_4) {
    char line1[LONG_CHECK_LINE*2-1] = NULL_LINE;
    char line2[LONG_CHECK_LINE*2-1] = NULL_LINE;
    rand_str(line1,LONG_CHECK_LINE-1);
    strcpy(line2,line1);
    char sourceline[LONG_CHECK_LINE] = NULL_LINE;
    rand_str(sourceline,LONG_CHECK_LINE-1);
    int len = LONG_CHECK_LINE;
    void* p1=strncat(line1,sourceline,len);
    void* p2=s21_strncat(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,LONG_CHECK_LINE*2-1);
    ck_assert_mem_eq(line1,line2,LONG_CHECK_LINE*2-1);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
START_TEST(test_strncat_long_5) {
    char line1[LONG_CHECK_LINE*2-1] = NULL_LINE;
    char line2[LONG_CHECK_LINE*2-1] = NULL_LINE;
    char sourceline[LONG_CHECK_LINE] = NULL_LINE;
    rand_str(sourceline,LONG_CHECK_LINE-1);
    int len = LONG_CHECK_LINE-1;
    void* p1=strncat(line1,sourceline,len);
    void* p2=s21_strncat(line2,sourceline,len);

    ck_assert_str_eq(p1,p2);
    ck_assert_str_eq(line1,line2);

    ck_assert_mem_eq(p1,p2,LONG_CHECK_LINE*2-1);
    ck_assert_mem_eq(line1,line2,LONG_CHECK_LINE*2-1);

    ck_assert_mem_eq(p1,p2,len);
    ck_assert_mem_eq(line1,line2,len);

    ck_assert_ptr_eq(line1,p1);
    ck_assert_ptr_eq(line2,p2); 
}
//strcspn
//6.0
START_TEST(test_strcspn_types) {
    char line[6] = "asdfg";
    char searchline[6] = "fghjk";
    size_t n=0, m=0;
    n=strcspn(line,searchline);
    m=s21_strcspn(line,searchline);
    ck_assert_int_eq(n,m);
    ck_assert_uint_eq(n,m);
    ck_assert_float_eq(n,m);
    ck_assert_double_eq(n,m);
    ck_assert_ldouble_eq(n,m);
}
//6.1
START_TEST(test_strcspn_norm_1) {
    char line[6] = "asdfg";
    char searchline[6] = "fghjk";
    size_t n=0, m=0;
    n=strcspn(line,searchline);
    m=s21_strcspn(line,searchline);

    ck_assert_int_eq(n,m);
    ck_assert_uint_eq(n,m);
}
START_TEST(test_strcspn_norm_2) {
    char line[6] = "asdfg";
    char searchline[6] = "hjkl;";
    size_t n=0, m=0;
    n=strcspn(line,searchline);
    m=s21_strcspn(line,searchline);

    ck_assert_int_eq(n,m);
    ck_assert_uint_eq(n,m);
}
START_TEST(test_strcspn_norm_3) {
    char line[6] = "asdfg";
    char searchline[6] = "asdfg";
    size_t n=0, m=0;
    n=strcspn(line,searchline);
    m=s21_strcspn(line,searchline);

    ck_assert_int_eq(n,m);
    ck_assert_uint_eq(n,m);
}
START_TEST(test_strcspn_norm_4) {
    char line[6] = "asdfg";
    char searchline[6] = "d";
    size_t n=0, m=0;
    n=strcspn(line,searchline);
    m=s21_strcspn(line,searchline);

    ck_assert_int_eq(n,m);
    ck_assert_uint_eq(n,m);
}
START_TEST(test_strcspn_norm_5) {
    char line[6] = "asdfg";
    char searchline[6] = "D";
    size_t n=0, m=0;
    n=strcspn(line,searchline);
    m=s21_strcspn(line,searchline);

    ck_assert_int_eq(n,m);
    ck_assert_uint_eq(n,m);
}
//6.2
START_TEST(test_strcspn_nullend_1) {
    char line[6] = NULL_END_line;
    char searchline[6] = "th";
    size_t n=0, m=0;
    n=strcspn(line,searchline);
    m=s21_strcspn(line,searchline);

    ck_assert_int_eq(n,m);
    ck_assert_uint_eq(n,m);
}
START_TEST(test_strcspn_nullend_2) {
    char line[6] = NULL_END_line;
    char searchline[6] = "t\0";
    size_t n=0, m=0;
    n=strcspn(line,searchline);
    m=s21_strcspn(line,searchline);

    ck_assert_int_eq(n,m);
    ck_assert_uint_eq(n,m);
}
START_TEST(test_strcspn_nullend_3) {
    char line[6] = NULL_END_line;
    char searchline[6] = "\0";
    size_t n=0, m=0;
    n=strcspn(line,searchline);
    m=s21_strcspn(line,searchline);

    ck_assert_int_eq(n,m);
    ck_assert_uint_eq(n,m);
}
START_TEST(test_strcspn_nullend_4) {
    char line[6] = NULL_END_line;
    char searchline[6] = {'G','H','T','\0'} ;
    size_t n=0, m=0;
    n=strcspn(line,searchline);
    m=s21_strcspn(line,searchline);

    ck_assert_int_eq(n,m);
    ck_assert_uint_eq(n,m);
}
START_TEST(test_strcspn_nullend_5) {
    char line[6] = FRIVE_CHAR_1;
    char searchline[6] = {'G','H','T','\0'} ;
    size_t n=0, m=0;
    n=strcspn(line,searchline);
    m=s21_strcspn(line,searchline);

    ck_assert_int_eq(n,m);
    ck_assert_uint_eq(n,m);
}
START_TEST(test_strcspn_nullmid_1) {
    char line[6] = NULL_MID_line;
    char searchline[6] = NULL_LINE;
    size_t n=0, m=0;
    n=strcspn(line,searchline);
    m=s21_strcspn(line,searchline);

    ck_assert_int_eq(n,m);
    ck_assert_uint_eq(n,m);
}
START_TEST(test_strcspn_nullmid_2) {
    char line[6] = NULL_MID_line;
    char searchline[6] = "NTM";
    size_t n=0, m=0;
    n=strcspn(line,searchline);
    m=s21_strcspn(line,searchline);

    ck_assert_int_eq(n,m);
    ck_assert_uint_eq(n,m);
}
START_TEST(test_strcspn_nullmid_3) {
    char line[5] = {'Z','F','\0','T'};
    char searchline[5] = {'\0','T','Z','k'};
    size_t n=0, m=0;
    n=strcspn(line,searchline);
    m=s21_strcspn(line,searchline);

    ck_assert_int_eq(n,m);
    ck_assert_uint_eq(n,m);
}
START_TEST(test_strcspn_entermid_1) {
    char line[5] = ENTER_MID_line;
    char searchline[5] = "\n";
    size_t n=0, m=0;
    n=strcspn(line,searchline);
    m=s21_strcspn(line,searchline);

    ck_assert_int_eq(n,m);
    ck_assert_uint_eq(n,m);
}
START_TEST(test_strcspn_entermid_2) {
    char line[5] = ENTER_MID_line;
    char searchline[5] = "tmn";
    size_t n=0, m=0;
    n=strcspn(line,searchline);
    m=s21_strcspn(line,searchline);

    ck_assert_int_eq(n,m);
    ck_assert_uint_eq(n,m);
}
START_TEST(test_strcspn_entermid_3) {
    char line[5] = ENTER_MID_line;
    char searchline[5] = {'G','H','\n','T'};
    size_t n=0, m=0;
    n=strcspn(line,searchline);
    m=s21_strcspn(line,searchline);

    ck_assert_int_eq(n,m);
    ck_assert_uint_eq(n,m);
}
START_TEST(test_strcspn_tabmid_1) {
    char line[5] = TAB_MID_line;
    char searchline[5] = "\t";
    size_t n=0, m=0;
    n=strcspn(line,searchline);
    m=s21_strcspn(line,searchline);

    ck_assert_int_eq(n,m);
    ck_assert_uint_eq(n,m);
}
START_TEST(test_strcspn_tabmid_2) {
    char line[5] = TAB_MID_line;
    char searchline[5] = "tmn";
    size_t n=0, m=0;
    n=strcspn(line,searchline);
    m=s21_strcspn(line,searchline);

    ck_assert_int_eq(n,m);
    ck_assert_uint_eq(n,m);
}
START_TEST(test_strcspn_tabmid_3) {
    char line[5] = TAB_MID_line;
    char searchline[5] = {'G','H','\t','T'};
    size_t n=0, m=0;
    n=strcspn(line,searchline);
    m=s21_strcspn(line,searchline);

    ck_assert_int_eq(n,m);
    ck_assert_uint_eq(n,m);
}
START_TEST(test_strcspn_enterend_1) {
    char line[5] = ENTER_END_line;
    char searchline[5] = "\n";
    size_t n=0, m=0;
    n=strcspn(line,searchline);
    m=s21_strcspn(line,searchline);

    ck_assert_int_eq(n,m);
    ck_assert_uint_eq(n,m);
}
START_TEST(test_strcspn_invis_1) {
    char line[33] = INVIS_CHAR;
    char searchline[5] = {'g','m',15,'t'};
    size_t n=0, m=0;
    n=strcspn(line,searchline);
    m=s21_strcspn(line,searchline);

    ck_assert_int_eq(n,m);
    ck_assert_uint_eq(n,m);
}
START_TEST(test_strcspn_invis_2) {
    char line[33] = INVIS_CHAR;
    char searchline[5] = {'g','m',10,'t'};
    size_t n=0, m=0;
    n=strcspn(line,searchline);
    m=s21_strcspn(line,searchline);

    ck_assert_int_eq(n,m);
    ck_assert_uint_eq(n,m);
}
START_TEST(test_strcspn_invis_3) {
    char line[33] = INVIS_CHAR;
    char searchline[5] = {'g','m',25,'t'};
    size_t n=0, m=0;
    n=strcspn(line,searchline);
    m=s21_strcspn(line,searchline);

    ck_assert_int_eq(n,m);
    ck_assert_uint_eq(n,m);
}
START_TEST(test_strcspn_invis_4) {
    char line[6] = FRIVE_CHAR_1;
    char searchline[33] = INVIS_CHAR;
    size_t n=0, m=0;
    n=strcspn(line,searchline);
    m=s21_strcspn(line,searchline);

    ck_assert_int_eq(n,m);
    ck_assert_uint_eq(n,m);
}
START_TEST(test_strcspn_invis_5) {
    char line[33] = INVIS_CHAR;
    char searchline[33] = INVIS_CHAR;
    size_t n=0, m=0;
    n=strcspn(line,searchline);
    m=s21_strcspn(line,searchline);

    ck_assert_int_eq(n,m);
    ck_assert_uint_eq(n,m);
}
START_TEST(test_strcspn_invis_6) {
    char line[5]=NULL_MID_line;
    char searchline[33] = INVIS_CHAR;
    size_t n=0, m=0;
    n=strcspn(line,searchline);
    m=s21_strcspn(line,searchline);

    ck_assert_int_eq(n,m);
    ck_assert_uint_eq(n,m);
}
START_TEST(test_strcspn_invis_7) {
    char line[5]={'g',15,25,'f'};
    char searchline[33] = INVIS_CHAR;
    size_t n=0, m=0;
    n=strcspn(line,searchline);
    m=s21_strcspn(line,searchline);

    ck_assert_int_eq(n,m);
    ck_assert_uint_eq(n,m);
}
//6.3
START_TEST(test_strcspn_nullline_1) {
    char line[5]=NULL_LINE;
    char searchline[6] = FRIVE_CHAR_1;
    size_t n=0, m=0;
    n=strcspn(line,searchline);
    m=s21_strcspn(line,searchline);

    ck_assert_int_eq(n,m);
    ck_assert_uint_eq(n,m);
}
/*
//WERROR -- ZEROsize-line
START_TEST(test_strcspn_nullline_2) {
    char line[0];
    char searchline[6] = FRIVE_CHAR_1;
    size_t n=0, m=0;
    n=strcspn(line,searchline);
    m=s21_strcspn(line,searchline);

    ck_assert_int_eq(n,m);
    ck_assert_uint_eq(n,m);
}
START_TEST(test_strcspn_nullline_4) {
    char line[6]=FRIVE_CHAR_1;
    char searchline[0];
    size_t n=0, m=0;
    n=strcspn(line,searchline);
    m=s21_strcspn(line,searchline);

    ck_assert_int_eq(n,m);
    ck_assert_uint_eq(n,m);
}
*/
START_TEST(test_strcspn_nullline_3) {
    char line[6]=FRIVE_CHAR_1;
    char searchline[5]=NULL_LINE;
    size_t n=0, m=0;
    n=strcspn(line,searchline);
    m=s21_strcspn(line,searchline);

    ck_assert_int_eq(n,m);
    ck_assert_uint_eq(n,m);
}

//6.4
START_TEST(test_strcspn_long_1) {
    char line[LONG_CHECK_LINE] = NULL_LINE;
    rand_str(line,LONG_CHECK_LINE-1);
    char searchline[10]="asdfghjkl";
    size_t n=0, m=0;
    n=strcspn(line,searchline);
    m=s21_strcspn(line,searchline);

    ck_assert_int_eq(n,m);
    ck_assert_uint_eq(n,m);
}
START_TEST(test_strcspn_long_2) {
    char line[LONG_CHECK_LINE] = NULL_LINE;
    rand_str(line,LONG_CHECK_LINE-1);
    char searchline[LONG_CHECK_LINE] = NULL_LINE;
    rand_str(searchline,LONG_CHECK_LINE-1);
    size_t n=0, m=0;
    n=strcspn(line,searchline);
    m=s21_strcspn(line,searchline);

    ck_assert_int_eq(n,m);
    ck_assert_uint_eq(n,m);
}
START_TEST(test_strcspn_long_3) {
    char line[LONG_CHECK_LINE] = NULL_LINE;
    rand_str(line,LONG_CHECK_LINE-1);
    char searchline[33] = INVIS_CHAR;
    size_t n=0, m=0;
    n=strcspn(line,searchline);
    m=s21_strcspn(line,searchline);

    ck_assert_int_eq(n,m);
    ck_assert_uint_eq(n,m);
}
START_TEST(test_strcspn_long_4) {
    char line[LONG_CHECK_LINE] = NULL_LINE;
    rand_str(line,LONG_CHECK_LINE-1);
    char searchline[5] = ENTER_MID_line;
    size_t n=0, m=0;
    n=strcspn(line,searchline);
    m=s21_strcspn(line,searchline);

    ck_assert_int_eq(n,m);
    ck_assert_uint_eq(n,m);
}
START_TEST(test_strcspn_long_5) {
    char line[33] = INVIS_CHAR;
    char searchline[LONG_CHECK_LINE] = NULL_LINE;
    rand_str(searchline,LONG_CHECK_LINE-1);
    size_t n=0, m=0;
    n=strcspn(line,searchline);
    m=s21_strcspn(line,searchline);

    ck_assert_int_eq(n,m);
    ck_assert_uint_eq(n,m);
}
START_TEST(test_strcspn_long_6) {
    char line[5] = "asdf";
    char searchline[LONG_CHECK_LINE] = NULL_LINE;
    rand_str(searchline,LONG_CHECK_LINE-1);
    size_t n=0, m=0;
    n=strcspn(line,searchline);
    m=s21_strcspn(line,searchline);

    ck_assert_int_eq(n,m);
    ck_assert_uint_eq(n,m);
}
START_TEST(test_strcspn_long_7) {
    char line[5] = "\n";
    char searchline[LONG_CHECK_LINE*10] = NULL_LINE;
    rand_str(searchline,LONG_CHECK_LINE*10-1);
    size_t n=0, m=0;
    n=strcspn(line,searchline);
    m=s21_strcspn(line,searchline);

    ck_assert_int_eq(n,m);
    ck_assert_uint_eq(n,m);
}

//strpbrk
//7.0
START_TEST(test_strpbrk_types) {
    char line[6] = "asdfg";
    char searchline[6] = "fghjk";
    char* n=NULL, *m=MY_NULL;
    n=strpbrk(line,searchline);
    m=s21_strpbrk(line,searchline);

    ck_assert_pstr_eq(n,m);
    ck_assert_ptr_eq(n,m);
    ck_assert_str_eq(n,m);
}
//7.1
START_TEST(test_strpbrk_norm_1) {
    char line[6] = "asdfg";
    char searchline[6] = "fghjk";
    char* n=NULL, *m=MY_NULL;
    n=strpbrk(line,searchline);
    m=s21_strpbrk(line,searchline);

    ck_assert_pstr_eq(n,m);
    ck_assert_ptr_eq(n,m);  
}
START_TEST(test_strpbrk_norm_2) {
    char line[6] = "asdfg";
    char searchline[6] = "hjkl;";
    char* n=NULL, *m=MY_NULL;
    n=strpbrk(line,searchline);
    m=s21_strpbrk(line,searchline);

    ck_assert_pstr_eq(n,m);
    ck_assert_ptr_eq(n,m); 
}
START_TEST(test_strpbrk_norm_3) {
    char line[6] = "asdfg";
    char searchline[6] = "asdfg";
    char* n=NULL, *m=MY_NULL;
    n=strpbrk(line,searchline);
    m=s21_strpbrk(line,searchline);

    ck_assert_pstr_eq(n,m);
    ck_assert_ptr_eq(n,m); 
}
START_TEST(test_strpbrk_norm_4) {
    char line[6] = "asdfg";
    char searchline[6] = "d";
    char* n=NULL, *m=MY_NULL;
    n=strpbrk(line,searchline);
    m=s21_strpbrk(line,searchline);

    ck_assert_pstr_eq(n,m);
    ck_assert_ptr_eq(n,m); 
}
START_TEST(test_strpbrk_norm_5) {
    char line[6] = "asdfg";
    char searchline[6] = "D";
    char* n=NULL, *m=MY_NULL;
    n=strpbrk(line,searchline);
    m=s21_strpbrk(line,searchline);

    ck_assert_pstr_eq(n,m);
    ck_assert_ptr_eq(n,m); 
}
START_TEST(test_strpbrk_norm_6) {
    char line[6] = "asdfg";
    char searchline[6] = "gooo";
    char* n=NULL, *m=MY_NULL;
    n=strpbrk(line,searchline);
    m=s21_strpbrk(line,searchline);

    ck_assert_pstr_eq(n,m);
    ck_assert_ptr_eq(n,m); 
}
//7.2
START_TEST(test_strpbrk_nullend_1) {
    char line[6] = NULL_END_line;
    char searchline[6] = "th";
    char* n=NULL, *m=MY_NULL;
    n=strpbrk(line,searchline);
    m=s21_strpbrk(line,searchline);

    ck_assert_pstr_eq(n,m);
    ck_assert_ptr_eq(n,m); 
}
START_TEST(test_strpbrk_nullend_2) {
    char line[6] = NULL_END_line;
    char searchline[6] = "t\0";
    char* n=NULL, *m=MY_NULL;
    n=strpbrk(line,searchline);
    m=s21_strpbrk(line,searchline);

    ck_assert_pstr_eq(n,m);
    ck_assert_ptr_eq(n,m); 
}
START_TEST(test_strpbrk_nullend_3) {
    char line[6] = NULL_END_line;
    char searchline[6] = "\0";
    char* n=NULL, *m=MY_NULL;
    n=strpbrk(line,searchline);
    m=s21_strpbrk(line,searchline);

    ck_assert_pstr_eq(n,m);
    ck_assert_ptr_eq(n,m); 
}
START_TEST(test_strpbrk_nullend_4) {
    char line[6] = NULL_END_line;
    char searchline[6] = {'G','H','T','\0'} ;
    char* n=NULL, *m=MY_NULL;
    n=strpbrk(line,searchline);
    m=s21_strpbrk(line,searchline);

    ck_assert_pstr_eq(n,m);
    ck_assert_ptr_eq(n,m); 
}
START_TEST(test_strpbrk_nullend_5) {
    char line[6] = FRIVE_CHAR_1;
    char searchline[6] = {'G','H','T','\0'} ;
    char* n=NULL, *m=MY_NULL;
    n=strpbrk(line,searchline);
    m=s21_strpbrk(line,searchline);

    ck_assert_pstr_eq(n,m);
    ck_assert_ptr_eq(n,m); 
}
START_TEST(test_strpbrk_nullmid_1) {
    char line[6] = NULL_MID_line;
    char searchline[6] = NULL_LINE;
    char* n=NULL, *m=MY_NULL;
    n=strpbrk(line,searchline);
    m=s21_strpbrk(line,searchline);

    ck_assert_pstr_eq(n,m);
    ck_assert_ptr_eq(n,m); 
}
START_TEST(test_strpbrk_nullmid_2) {
    char line[6] = NULL_MID_line;
    char searchline[6] = "NTM";
    char* n=NULL, *m=MY_NULL;
    n=strpbrk(line,searchline);
    m=s21_strpbrk(line,searchline);

    ck_assert_pstr_eq(n,m);
    ck_assert_ptr_eq(n,m); 
}
START_TEST(test_strpbrk_nullmid_3) {
    char line[5] = {'Z','F','\0','T'};
    char searchline[5] = {'\0','T','Z','k'};
    char* n=NULL, *m=MY_NULL;
    n=strpbrk(line,searchline);
    m=s21_strpbrk(line,searchline);

    ck_assert_pstr_eq(n,m);
    ck_assert_ptr_eq(n,m); 
}
START_TEST(test_strpbrk_entermid_1) {
    char line[5] = ENTER_MID_line;
    char searchline[5] = "\n";
    char* n=NULL, *m=MY_NULL;
    n=strpbrk(line,searchline);
    m=s21_strpbrk(line,searchline);

    ck_assert_pstr_eq(n,m);
    ck_assert_ptr_eq(n,m); 
}
START_TEST(test_strpbrk_entermid_2) {
    char line[5] = ENTER_MID_line;
    char searchline[5] = "tmn";
    char* n=NULL, *m=MY_NULL;
    n=strpbrk(line,searchline);
    m=s21_strpbrk(line,searchline);

    ck_assert_pstr_eq(n,m);
    ck_assert_ptr_eq(n,m); 
}
START_TEST(test_strpbrk_entermid_3) {
    char line[5] = ENTER_MID_line;
    char searchline[5] = {'G','H','\n','T'};
    char* n=NULL, *m=MY_NULL;
    n=strpbrk(line,searchline);
    m=s21_strpbrk(line,searchline);

    ck_assert_pstr_eq(n,m);
    ck_assert_ptr_eq(n,m); 
}
START_TEST(test_strpbrk_tabmid_1) {
    char line[5] = TAB_MID_line;
    char searchline[5] = "\t";
    char* n=NULL, *m=MY_NULL;
    n=strpbrk(line,searchline);
    m=s21_strpbrk(line,searchline);

    ck_assert_pstr_eq(n,m);
    ck_assert_ptr_eq(n,m); 
}
START_TEST(test_strpbrk_tabmid_2) {
    char line[5] = TAB_MID_line;
    char searchline[5] = "tmn";
    char* n=NULL, *m=MY_NULL;
    n=strpbrk(line,searchline);
    m=s21_strpbrk(line,searchline);

    ck_assert_pstr_eq(n,m);
    ck_assert_ptr_eq(n,m); 
}
START_TEST(test_strpbrk_tabmid_3) {
    char line[5] = TAB_MID_line;
    char searchline[5] = {'G','H','\t','T'};
    char* n=NULL, *m=MY_NULL;
    n=strpbrk(line,searchline);
    m=s21_strpbrk(line,searchline);

    ck_assert_pstr_eq(n,m);
    ck_assert_ptr_eq(n,m); 
}
START_TEST(test_strpbrk_enterend_1) {
    char line[5] = ENTER_END_line;
    char searchline[5] = "\n";
    char* n=NULL, *m=MY_NULL;
    n=strpbrk(line,searchline);
    m=s21_strpbrk(line,searchline);

    ck_assert_pstr_eq(n,m);
    ck_assert_ptr_eq(n,m); 
}
START_TEST(test_strpbrk_invis_1) {
    char line[33] = INVIS_CHAR;
    char searchline[5] = {'g','m',15,'t'};
    char* n=NULL, *m=MY_NULL;
    n=strpbrk(line,searchline);
    m=s21_strpbrk(line,searchline);

    ck_assert_pstr_eq(n,m);
    ck_assert_ptr_eq(n,m); 
}
START_TEST(test_strpbrk_invis_2) {
    char line[33] = INVIS_CHAR;
    char searchline[5] = {'g','m',10,'t'};
    char* n=NULL, *m=MY_NULL;
    n=strpbrk(line,searchline);
    m=s21_strpbrk(line,searchline);

    ck_assert_pstr_eq(n,m);
    ck_assert_ptr_eq(n,m); 
}
START_TEST(test_strpbrk_invis_3) {
    char line[33] = INVIS_CHAR;
    char searchline[5] = {'g','m',25,'t'};
    char* n=NULL, *m=MY_NULL;
    n=strpbrk(line,searchline);
    m=s21_strpbrk(line,searchline);

    ck_assert_pstr_eq(n,m);
    ck_assert_ptr_eq(n,m); 
}
START_TEST(test_strpbrk_invis_4) {
    char line[6] = FRIVE_CHAR_1;
    char searchline[33] = INVIS_CHAR;
    char* n=NULL, *m=MY_NULL;
    n=strpbrk(line,searchline);
    m=s21_strpbrk(line,searchline);

    ck_assert_pstr_eq(n,m);
    ck_assert_ptr_eq(n,m); 
}
START_TEST(test_strpbrk_invis_8) {
    char line[6] = {'6','5','9','7','1'};
    char searchline[33] = INVIS_CHAR;
    char* n=NULL, *m=MY_NULL;
    n=strpbrk(line,searchline);
    m=s21_strpbrk(line,searchline);

    ck_assert_pstr_eq(n,m);
    ck_assert_ptr_eq(n,m); 
}
START_TEST(test_strpbrk_invis_9) {
    char line[6] = {'6','0','9',7,'1'};
    char searchline[33] = INVIS_CHAR;
    char* n=NULL, *m=MY_NULL;
    n=strpbrk(line,searchline);
    m=s21_strpbrk(line,searchline);

    ck_assert_pstr_eq(n,m);
    ck_assert_ptr_eq(n,m); 
}
START_TEST(test_strpbrk_invis_5) {
    char line[33] = INVIS_CHAR;
    char searchline[33] = INVIS_CHAR;
    char* n=NULL, *m=MY_NULL;
    n=strpbrk(line,searchline);
    m=s21_strpbrk(line,searchline);

    ck_assert_pstr_eq(n,m);
    ck_assert_ptr_eq(n,m); 
}
START_TEST(test_strpbrk_invis_6) {
    char line[5]=NULL_MID_line;
    char searchline[33] = INVIS_CHAR;
    char* n=NULL, *m=MY_NULL;
    n=strpbrk(line,searchline);
    m=s21_strpbrk(line,searchline);

    ck_assert_pstr_eq(n,m);
    ck_assert_ptr_eq(n,m); 
}
START_TEST(test_strpbrk_invis_7) {
    char line[5]={'g',15,25,'f'};
    char searchline[33] = INVIS_CHAR;
    char* n=NULL, *m=MY_NULL;
    n=strpbrk(line,searchline);
    m=s21_strpbrk(line,searchline);

    ck_assert_pstr_eq(n,m);
    ck_assert_ptr_eq(n,m); 
}
//7.3
START_TEST(test_strpbrk_nullline_1) {
    char line[5]=NULL_LINE;
    char searchline[6] = FRIVE_CHAR_1;
    char* n=NULL, *m=MY_NULL;
    n=strpbrk(line,searchline);
    m=s21_strpbrk(line,searchline);

    ck_assert_pstr_eq(n,m);
    ck_assert_ptr_eq(n,m); 
}
/*
//WERROR -- ZEROsize-line
START_TEST(test_strpbrk_nullline_2) {
    char line[0];
    char searchline[6] = FRIVE_CHAR_1;
    char* n=NULL, *m=MY_NULL;
    n=strpbrk(line,searchline);
    m=s21_strpbrk(line,searchline);

    ck_assert_pstr_eq(n,m);
    ck_assert_ptr_eq(n,m); 
}
START_TEST(test_strpbrk_nullline_4) {
    char line[6]=FRIVE_CHAR_1;
    char searchline[0];
    char* n=NULL, *m=MY_NULL;
    n=strpbrk(line,searchline);
    m=s21_strpbrk(line,searchline);

    ck_assert_pstr_eq(n,m);
    ck_assert_ptr_eq(n,m); 
}
*/
START_TEST(test_strpbrk_nullline_3) {
    char line[6]=FRIVE_CHAR_1;
    char searchline[5]=NULL_LINE;
    char* n=NULL, *m=MY_NULL;
    n=strpbrk(line,searchline);
    m=s21_strpbrk(line,searchline);

    ck_assert_pstr_eq(n,m);
    ck_assert_ptr_eq(n,m); 
}
//7.4
START_TEST(test_strpbrk_long_1) {
    char line[LONG_CHECK_LINE] = NULL_LINE;
    rand_str(line,LONG_CHECK_LINE-1);
    char searchline[10]="asdfghjkl";
    char* n=NULL, *m=MY_NULL;
    n=strpbrk(line,searchline);
    m=s21_strpbrk(line,searchline);

    ck_assert_pstr_eq(n,m);
    ck_assert_ptr_eq(n,m); 
}
START_TEST(test_strpbrk_long_2) {
    char line[LONG_CHECK_LINE] = NULL_LINE;
    rand_str(line,LONG_CHECK_LINE-1);
    char searchline[LONG_CHECK_LINE] = NULL_LINE;
    rand_str(searchline,LONG_CHECK_LINE-1);
    char* n=NULL, *m=MY_NULL;
    n=strpbrk(line,searchline);
    m=s21_strpbrk(line,searchline);

    ck_assert_pstr_eq(n,m);
    ck_assert_ptr_eq(n,m); 
}
START_TEST(test_strpbrk_long_3) {
    char line[LONG_CHECK_LINE] = NULL_LINE;
    rand_str(line,LONG_CHECK_LINE-1);
    char searchline[33] = INVIS_CHAR;
    char* n=NULL, *m=MY_NULL;
    n=strpbrk(line,searchline);
    m=s21_strpbrk(line,searchline);

    ck_assert_pstr_eq(n,m);
    ck_assert_ptr_eq(n,m); 
}
START_TEST(test_strpbrk_long_4) {
    char line[LONG_CHECK_LINE] = NULL_LINE;
    rand_str(line,LONG_CHECK_LINE-1);
    char searchline[5] = ENTER_MID_line;
    char* n=NULL, *m=MY_NULL;
    n=strpbrk(line,searchline);
    m=s21_strpbrk(line,searchline);

    ck_assert_pstr_eq(n,m);
    ck_assert_ptr_eq(n,m); 
}
START_TEST(test_strpbrk_long_5) {
    char line[33] = INVIS_CHAR;
    char searchline[LONG_CHECK_LINE] = NULL_LINE;
    rand_str(searchline,LONG_CHECK_LINE-1);
    char* n=NULL, *m=MY_NULL;
    n=strpbrk(line,searchline);
    m=s21_strpbrk(line,searchline);

    ck_assert_pstr_eq(n,m);
    ck_assert_ptr_eq(n,m); 
}
START_TEST(test_strpbrk_long_6) {
    char line[5] = "asdf";
    char searchline[LONG_CHECK_LINE] = NULL_LINE;
    rand_str(searchline,LONG_CHECK_LINE-1);
    char* n=NULL, *m=MY_NULL;
    n=strpbrk(line,searchline);
    m=s21_strpbrk(line,searchline);

    ck_assert_pstr_eq(n,m);
    ck_assert_ptr_eq(n,m); 
}
START_TEST(test_strpbrk_long_7) {
    char line[5] = "\n";
    char searchline[LONG_CHECK_LINE*10] = NULL_LINE;
    rand_str(searchline,LONG_CHECK_LINE*10-1);
    char* n=NULL, *m=MY_NULL;
    n=strpbrk(line,searchline);
    m=s21_strpbrk(line,searchline);

    ck_assert_pstr_eq(n,m);
    ck_assert_ptr_eq(n,m); 
}

//strtok
//8.0
START_TEST(test_strtok_lineschange) {
    char line[6] = "asdfg";
    char line2[6]=NULL_LINE;
    char line3[6]=NULL_LINE;
    strcpy(line3,line);
    strcpy(line2,line);
    char divline[6] = "fs";
    char* n=NULL, *m=MY_NULL;
    n=strtok(line,divline);
    m=s21_strtok(line3,divline);
    ck_assert_pstr_eq(n,m);
    ck_assert_pstr_ne(line,line2);
    ck_assert_pstr_ne(line3,line2);

    for(;n!=MY_NULL && m!=NULL;){
        n=strtok(MY_NULL,divline);
        m=s21_strtok(NULL,divline);
        ck_assert_pstr_eq(n,m);
        ck_assert_pstr_ne(line,line2);
        ck_assert_pstr_ne(line3,line2);
    }
}
START_TEST(test_strtok_types) {
    char line[6] = "asdfg";
    char line2[6]=NULL_LINE;
    strcpy(line2,line);
    char divline[6] = "fs";
    char* n=NULL, *m=MY_NULL;
    n=strtok(line,divline);
    m=s21_strtok(line2,divline);
    //printf("%s--%s\n",n,m);
    ck_assert_pstr_eq(n,m);
    //ck_assert_ptr_eq(n,m);
    for(;n!=MY_NULL && m!=NULL;){
        n=strtok(MY_NULL,divline);
        m=s21_strtok(NULL,divline);
        //printf("%s--%s\n",n,m);
        ck_assert_pstr_eq(n,m);
        //ck_assert_ptr_eq(n,m);
    }
}
START_TEST(test_strtok_diflines_1) {
    char line[6] = "asdfg";
    char line2[6] = "asdfg";
    char divline[6] = "fs";
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
START_TEST(test_strtok_diflines_2) {
    char line[6] = "asdfg";
    char line2[6] = "afdfg";
    char divline[6] = "fs";
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
START_TEST(test_strtok_diflines_3) {
    char line[6] = "asdfg";
    char line2[6] = "pfpfp";
    char divline[6] = "fs";
    char* n=NULL, *m=MY_NULL;
    n=strtok(line,divline);
    m=s21_strtok(line2,divline);
    ck_assert_pstr_ne(n,m);

    for(;n!=MY_NULL && m!=NULL;){
        n=strtok(MY_NULL,divline);
        m=s21_strtok(NULL,divline);
        if(n!=MY_NULL && m!=NULL)
            ck_assert_pstr_ne(n,m);
    }
}
START_TEST(test_strtok_diflines_4) {
    char line[6] = "asdfg";
    char line2[6] = "afpfp";
    char divline[6] = "fs";
    char* n=NULL, *m=MY_NULL;
    n=strtok(line,divline);
    m=s21_strtok(line2,divline);
    ck_assert_pstr_eq(n,m);

    for(;n!=MY_NULL && m!=NULL;){
        n=strtok(MY_NULL,divline);
        m=s21_strtok(NULL,divline);
        if(n!=MY_NULL && m!=NULL)
            ck_assert_pstr_ne(n,m);
    }
}
//8.1
START_TEST(test_strtok_norm_1) {
    char line[6] = "asdfg";
    char line2[6]=NULL_LINE;
    strcpy(line2,line);
    char divline[6] = "fs";
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
START_TEST(test_strtok_norm_2) {
    char line[6] = "asdfg";
    char line2[6]=NULL_LINE;
    strcpy(line2,line);
    char divline[6] = "afs";
    char* n=NULL, *m=MY_NULL;
    n=strtok(line,divline);
    m=s21_strtok(line2,divline);
    //printf("HEY: %s--%s",n, m);
    ck_assert_pstr_eq(n,m);
    for(;n!=MY_NULL && m!=NULL;){
        n=strtok(MY_NULL,divline);
        m=s21_strtok(NULL,divline);
        ck_assert_pstr_eq(n,m);
    }
}
START_TEST(test_strtok_norm_3) {
    char line[6] = "asdfg";
    char line2[6]=NULL_LINE;
    strcpy(line2,line);
    char divline[6] = "gfkps";
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
START_TEST(test_strtok_norm_4) {
    char line[84] = "https://youtu.be/dQw4w9WgXcQ?si=V_2-moWdSx-jhLE7";
    char line2[84]=NULL_LINE;
    strcpy(line2,line);
    char divline[6] = ":/.";
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
START_TEST(test_strtok_norm_5) {
    char line[84] = "/home/jackoneill/Programming/s21/StrString/C2_s21_stringplus-1/src";
    char line2[84]=NULL_LINE;
    strcpy(line2,line);
    char divline[6] = "/";
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
START_TEST(test_strtok_norm_6) {
    char line[370] = "You motherfucker, come on you little ass… fuck with me, eh? You fucking little asshole, dickhead cocksucker…You fuckin' come on, come fuck with me! I'll get your ass, you jerk! Oh, you fuckhead motherfucker! Fuck all you and your family! Come on, you cocksucker, slime bucket, shitface turdball! Come on, you scum sucker, you fucking with me? Come on, you asshole!";
    char line2[370]=NULL_LINE;
    strcpy(line2,line);
    char divline[6] = " ";
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
START_TEST(test_strtok_norm_7) {
    char line[15] = "Hello. .World";
    char line2[15]=NULL_LINE;
    strcpy(line2,line);
    char divline[6] = ".";
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
START_TEST(test_strtok_norm_8) {
    char line[20] = "Hello.....World";
    char line2[20]=NULL_LINE;
    strcpy(line2,line);
    char divline[6] = ".";
    char* n=NULL, *m=MY_NULL;
    n=strtok(line,divline);
    m=s21_strtok(line2,divline);
    ck_assert_pstr_eq(n,m);
    for(;n!=MY_NULL && m!=NULL;){
        //printf("%s--%s\n",n,m);
        n=strtok(MY_NULL,divline);
        m=s21_strtok(NULL,divline);
        ck_assert_pstr_eq(n,m);
    }
}
START_TEST(test_strtok_norm_9) {
    char line[16] = "Hello.....World";
    char line2[16]=NULL_LINE;
    strcpy(line2,line);
    char divline[6] = "_";
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
START_TEST(test_strtok_norm_10) {
    char line[16] = "Hello.....World";
    char line2[16]=NULL_LINE;
    strcpy(line2,line);
    char divline[6] = "a";
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
START_TEST(test_strtok_norm_11) {
    char line[116] = " fff..Fg.fgg  dscsdc scdscs.. . dcscsdcs.cs c..cs   .cdscs  .  .   ... cdscscs cdscs.cdscsd dcsc.csc s.cscs .scscsc";
    char line2[116]=NULL_LINE;
    strcpy(line2,line);
    char divline[6] = " .";
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
START_TEST(test_strtok_norm_12) {
    char line[116] = " fff..Fg.fgg  dscsdc scdscs.. . dcscsdcs.cs c..cs   .cdscs  .  .   ... cdscscs cdscs.cdscsd dcsc.csc s.cscs .scscsc";
    char line2[116]=NULL_LINE;
    strcpy(line2,line);
    char divline[6] = {'.',' '};
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
START_TEST(test_strtok_norm_13) {
    char line[116] = " fff..Fg.fgg  dscsdc scdscs.. . dcscsdcs.cs c..cs   .cdscs  .  .   ... cdscscs cdscs.cdscsd dcsc.csc s.cscs .scscsc";
    char line2[116]=NULL_LINE;
    strcpy(line2,line);
    char divline[6] = {'z'};
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
START_TEST(test_strtok_norm_14) {
    char line[120] = " fff..Fg.fgg  dscsdc scdscs.. . dcscsdcs.cs c..cs   .cdscs  .  .   ... cdscscs cdscs.cdscsd dcsc.csc s.cscs .scscsc";
    char line2[120]=NULL_LINE;
    strcpy(line2,line);
    char divline[6] = {' '};
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
//8.2
START_TEST(test_strtok_nullendline_1) {
    char line[6] = NULL_END_line;
    char line2[6]=NULL_LINE;
    strcpy(line2,line);
    char divline[6] = "t";
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
START_TEST(test_strtok_nullendline_2) {
    char line[6] = NULL_END_line;
    char line2[6]=NULL_LINE;
    strcpy(line2,line);
    char divline[6] = "\t \0";
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
START_TEST(test_strtok_nullmidline_1) {
    char line[5] = NULL_MID_line;
    char line2[5]=NULL_LINE;
    strcpy(line2,line);
    char divline[4] = "TZ";
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
START_TEST(test_strtok_nullmidline_3) {
    char line[5] = NULL_MID_line;
    char line2[5]=NULL_LINE;
    strcpy(line2,line);
    char divline[4] = "TZ\0";
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
START_TEST(test_strtok_nullmidline_2) {
    char line[8] = "ZggTffT";
    char line2[8]=NULL_LINE;
    strcpy(line2,line);
    char divline[5] = NULL_MID_line;
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
START_TEST(test_strtok_nullmidline_4) {
    char line[8] = {'z','t','t','\0','k','t','z'};
    char line2[8]=NULL_LINE;
    strcpy(line2,line);
    char divline[2] = {'t'};
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
START_TEST(test_strtok_entermidline_1) {
    char line[9] = ENTER_MID_line;
    char line2[9]=NULL_LINE;
    strcpy(line2,line);
    char divline[3] = {'\n'};
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
START_TEST(test_strtok_entermidline_2) {
    char line[9] = ENTER_MID_line;
    char line2[9]=NULL_LINE;
    strcpy(line2,line);
    char divline[3] = {'\n','h'};
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
START_TEST(test_strtok_entermidline_3) {
    char line[9] = {'g','h','\n','t','k','l'};
    char line2[9]=NULL_LINE;
    strcpy(line2,line);
    char divline[3] = {'\n','k'};
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
START_TEST(test_strtok_enterendline) {
    char line[9] = ENTER_END_line;
    char line2[9]=NULL_LINE;
    strcpy(line2,line);
    char divline[3] = {'\n','h'};
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
START_TEST(test_strtok_tabendline) {
    char line[9] = TAB_END_line;
    char line2[9]=NULL_LINE;
    strcpy(line2,line);
    char divline[3] = {'\t','h'};
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
START_TEST(test_strtok_tabmidline_1) {
    char line[9] = TAB_MID_line;
    char line2[9]=NULL_LINE;
    strcpy(line2,line);
    char divline[3] = {'\t'};
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
START_TEST(test_strtok_tabmidline_2) {
    char line[9] = TAB_MID_line;
    char line2[9]=NULL_LINE;
    strcpy(line2,line);
    char divline[3] = {'\t','h'};
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
START_TEST(test_strtok_tabmidline_3) {
    char line[9] = {'g','h','\t','t','k','l'};
    char line2[9]=NULL_LINE;
    strcpy(line2,line);
    char divline[3] = {'\t','k'};
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
START_TEST(test_strtok_tabmidline_4) {
    char line[9] = {'g','h','\t','t','k','l'};
    char line2[9]=NULL_LINE;
    strcpy(line2,line);
    char divline[4] = {'\n','k','\0'};
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
START_TEST(test_strtok_invis_1) {
    char line[33] = INVIS_CHAR;
    char line2[33]=NULL_LINE;
    strcpy(line2,line);
    char divline[4] = {'n','k','t'};
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
START_TEST(test_strtok_invis_2) {
    char line[33] = INVIS_CHAR;
    char line2[33]=NULL_LINE;
    strcpy(line2,line);
    char divline[4] = {'9','0','\0'};
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
START_TEST(test_strtok_invis_3) {
    char line[33] = INVIS_CHAR;
    char line2[33]=NULL_LINE;
    strcpy(line2,line);
    char divline[10] = {'9','0','\0', '\t','\n',10};
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
START_TEST(test_strtok_invis_4) {
    char line[33] = INVIS_CHAR;
    char line2[33]=NULL_LINE;
    strcpy(line2,line);
    char divline[10] = {10, 15, 5, 20, 25,30, 7, 32, 1};
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
START_TEST(test_strtok_invis_5) {
    char line[33] = INVIS_CHAR;
    char line2[33]=NULL_LINE;
    strcpy(line2,line);
    char divline[33] = INVIS_CHAR;
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
START_TEST(test_strtok_invis_6) {
    char line[10] = {10, 15, 5, 20, 25,30, 7, 32, 1};
    char line2[10]=NULL_LINE;
    strcpy(line2,line);
    char divline[33] = INVIS_CHAR;
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
START_TEST(test_strtok_invis_7) {
    char line[10] = {'1', '5', '5', '2', '2','3','0', '\t', '1'};
    char line2[10]=NULL_LINE;
    strcpy(line2,line);
    char divline[33] = INVIS_CHAR;
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
START_TEST(test_strtok_invis_8) {
    char line[15] = "asd\tasd\nasd";
    char line2[15]=NULL_LINE;
    strcpy(line2,line);
    char divline[33] = INVIS_CHAR;
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
START_TEST(test_strtok_invis_9) {
    char line[15] = {'a','f','\n','a','.',5,'\n','f','5',15,'d'};
    char line2[15]=NULL_LINE;
    strcpy(line2,line);
    char divline[33] = INVIS_CHAR;
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
//8.3
START_TEST(test_strtok_nullline_1) {
    char line[15] = NULL_LINE;
    char line2[15]=NULL_LINE;
    strcpy(line2,line);
    char divline[33] = ENTER_MID_line;
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
START_TEST(test_strtok_nullline_2) {
    char line[15] = NULL_LINE;
    char line2[15]=NULL_LINE;
    strcpy(line2,line);
    char divline[33] = NULL_MID_line;
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
START_TEST(test_strtok_nullline_3) {
    char line[15] = NULL_LINE;
    char line2[15]=NULL_LINE;
    strcpy(line2,line);
    char divline[5] = NULL_LINE;
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
START_TEST(test_strtok_nullline_4) {
    char line[15] = FRIVE_CHAR_1;
    char line2[15]=NULL_LINE;
    strcpy(line2,line);
    char divline[5] = NULL_LINE;
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
START_TEST(test_strtok_nullline_5) {
    char line[15] = NULL_MID_line;
    char line2[15]=NULL_LINE;
    strcpy(line2,line);
    char divline[5] = NULL_LINE;
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
/*
// sometimes error n == "", m == (null)
START_TEST(test_strtok_nullline_6) {
    char line[0];
    char line2[0];
    char divline[5] = NULL_MID_line;
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

//Segmentation fault
START_TEST(test_strtok_nullline_7) {
    char* line=MY_NULL;
    char* line2=NULL;
    char divline[5] = NULL_MID_line;
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
START_TEST(test_strtok_nullline_9) {
    char line[5] = NULL_MID_line;
    char line2[5] = NULL_MID_line;
    char* divline=NULL;
    char* n=NULL, *m=MY_NULL;
    n=s21_strtok(line,divline);
    m=strtok(line2,divline);
    ck_assert_pstr_eq(n,m);
    for(;n!=MY_NULL && m!=NULL;){
        n=strtok(MY_NULL,divline);
        m=s21_strtok(NULL,divline);
        ck_assert_pstr_eq(n,m);
    }
}
START_TEST(test_strtok_nullline_10) {
    char line[5] = NULL_MID_line;
    char line2[5] = NULL_MID_line;
    char* divline=MY_NULL;
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
START_TEST(test_strtok_nullline_11) {
    char *line = NULL;
    char *line2= MY_NULL;
    char *divline=MY_NULL;
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
START_TEST(test_strtok_nullline_12) {
    char* line = NULL;
    char* line2= MY_NULL;
    char* divline=MY_NULL;
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
//randome stuff (Don't know what is going on)
START_TEST(test_strtok_nullline_8) {
    char line[5] = NULL_MID_line;
    char line2[5] = NULL_MID_line;
    char divline[0];
    char* n=NULL, *m=MY_NULL;
    n=strtok(line,divline);         //try change places
    m=s21_strtok(line2,divline);
    ck_assert_pstr_eq(n,m);
                                    //comment below
    for(;n!=MY_NULL && m!=NULL;){
        n=strtok(MY_NULL,divline);
        m=s21_strtok(NULL,divline);
        ck_assert_pstr_eq(n,m);
    }
}
*/
//8.4
START_TEST(test_strtok_longline_1) {
    char line[LONG_CHECK_LINE*10] = NULL_LINE;
    rand_str(line,LONG_CHECK_LINE*10-1);
    char line2[LONG_CHECK_LINE*10]=NULL_LINE;
    strcpy(line2,line);
    char divline[33] = INVIS_CHAR;
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
START_TEST(test_strtok_longline_2) {
    char line[LONG_CHECK_LINE*10] = NULL_LINE;
    rand_str(line,LONG_CHECK_LINE*10-1);
    char line2[LONG_CHECK_LINE*10]=NULL_LINE;
    strcpy(line2,line);
    char divline[15] = "asdfghjkl;";
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
    char line2[35]=NULL_LINE;
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
START_TEST(test_strtok_longline_5) {
    char line[35] = "aaaaaaaaaaaaaaaaaaaa";
    char line2[35]=NULL_LINE;
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
START_TEST(test_strtok_longline_6) {
    char line[35] = {5,6,7,0};
    char line2[35]=NULL_LINE;
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
//s21_sscanf
//9.0
START_TEST(test_sscanf_blanks){
    char input_line_0[]="5  55 \n\t\n  -555                     zpep\t  \n 5555end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    int intt1=1, intt2=2, intt3=3, intt4=4, intt6=1, intt7=2, intt8=3, intt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%d\n\t\t\t\n%d%d zpep                    %d\n\n%s",&intt1,&intt2,&intt3,&intt4, endd1),s21_sscanf(input_line_1,"%d\n\t\t\t\n%d%d zpep                    %d\n\n%s",&intt6,&intt7,&intt8,&intt9, endd2));
    ck_assert_int_eq(intt1,intt6);
    ck_assert_int_eq(intt2,intt7);
    ck_assert_int_eq(intt3,intt8);
    ck_assert_int_eq(intt4,intt9);
    ck_assert_str_eq(endd1,endd2);
}
//9.1 //elevator
START_TEST(test_sscanf_unsigned_1){
    char input_line_0[]="111111  11223344556677889900111222333444555  -55555  5555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned int uintt1=1, uintt2=2, uintt3=3, uintt4=4, uintt6=1, uintt7=2, uintt8=3, uintt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%u%u%u%u%s",&uintt1,&uintt2,&uintt3,&uintt4, endd1),s21_sscanf(input_line_1,"%u%u%u%u%s",&uintt6,&uintt7,&uintt8,&uintt9, endd2));
    ck_assert_int_eq(uintt1,uintt6);
    ck_assert_uint_eq(uintt1,uintt6);
    ck_assert_int_eq(uintt2,uintt7);
    ck_assert_uint_eq(uintt2,uintt7);
    ck_assert_int_eq(uintt3,uintt8);
    ck_assert_uint_eq(uintt3,uintt8);
    ck_assert_int_eq(uintt4,uintt9);
    ck_assert_uint_eq(uintt4,uintt9);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_unsigned_2){
    char input_line_0[]="111111  11223344556677889900111222333444555  -55555  5555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned int uintt1=1, uintt2=2, uintt3=3, uintt4=4, uintt6=1, uintt7=2, uintt8=3, uintt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%u%%%u%u%u%s",&uintt1,&uintt2,&uintt3,&uintt4, endd1),s21_sscanf(input_line_1,"%u%%%u%u%u%s",&uintt6,&uintt7,&uintt8,&uintt9, endd2));
    ck_assert_int_eq(uintt1,uintt6);
    ck_assert_uint_eq(uintt1,uintt6);
    ck_assert_int_eq(uintt2,uintt7);
    ck_assert_uint_eq(uintt2,uintt7);
    ck_assert_int_eq(uintt3,uintt8);
    ck_assert_uint_eq(uintt3,uintt8);
    ck_assert_int_eq(uintt4,uintt9);
    ck_assert_uint_eq(uintt4,uintt9);
    ck_assert_str_eq(endd1,endd2);
}    
START_TEST(test_sscanf_unsigned_3){
    char input_line_0[]="111111  11223344556677889900111222333444555  -55555  5555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    //printf("\nHERE\n");
    unsigned int uintt1=1, uintt2=2, uintt3=3, uintt4=4, uintt6=1, uintt7=2, uintt8=3, uintt9=4, uintt5=5,uintt10=5;
    ck_assert_int_eq(sscanf(input_line_0,"%u%7u%u%u%u%s",&uintt1,&uintt2, &uintt5,&uintt3,&uintt4, endd1),s21_sscanf(input_line_1,"%u%7u%u%u%u%s",&uintt6,&uintt7,&uintt10,&uintt8,&uintt9, endd2));
    //printf("\nHERE\n");
    ck_assert_int_eq(uintt1,uintt6);
    ck_assert_uint_eq(uintt1,uintt6);
    ck_assert_int_eq(uintt2,uintt7);
    ck_assert_uint_eq(uintt2,uintt7);
    ck_assert_int_eq(uintt3,uintt8);
    ck_assert_uint_eq(uintt3,uintt8);
    ck_assert_int_eq(uintt4,uintt9);
    ck_assert_uint_eq(uintt4,uintt9);
    ck_assert_int_eq(uintt5,uintt10);
    ck_assert_uint_eq(uintt5,uintt10);
    ck_assert_str_eq(endd1,endd2);
}  
START_TEST(test_sscanf_unsigned_5){
    char input_line_0[]="111111  11223344556677889900111222333444555  -55555  5555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned int uintt1=1, uintt2=2, uintt3=3, uintt6=1, uintt7=2, uintt8=3;
    ck_assert_int_eq(sscanf(input_line_0,"%u%*u%u%u%s",&uintt1,&uintt2,&uintt3, endd1),s21_sscanf(input_line_1,"%u%*u%u%u%s",&uintt6,&uintt7,&uintt8, endd2));
    ck_assert_int_eq(uintt1,uintt6);
    ck_assert_uint_eq(uintt1,uintt6);
    ck_assert_int_eq(uintt2,uintt7);
    ck_assert_uint_eq(uintt2,uintt7);
    ck_assert_int_eq(uintt3,uintt8);
    ck_assert_uint_eq(uintt3,uintt8);
    ck_assert_str_eq(endd1,endd2);
}   
START_TEST(test_sscanf_unsigned_6){
    char input_line_0[]="111111  11223344556677889900111222333444555  -55555  5555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned int uintt1=1, uintt2=2, uintt3=3, uintt4=4, uintt6=1, uintt7=2, uintt8=3, uintt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%u%*26u%u%u%u%s",&uintt1,&uintt2,&uintt3,&uintt4, endd1),s21_sscanf(input_line_1,"%u%*26u%u%u%u%s",&uintt6,&uintt7,&uintt8,&uintt9, endd2));
    ck_assert_int_eq(uintt1,uintt6);
    ck_assert_uint_eq(uintt1,uintt6);
    ck_assert_int_eq(uintt2,uintt7);
    ck_assert_uint_eq(uintt2,uintt7);
    ck_assert_int_eq(uintt3,uintt8);
    ck_assert_uint_eq(uintt3,uintt8);
    ck_assert_int_eq(uintt4,uintt9);
    ck_assert_uint_eq(uintt4,uintt9);
    ck_assert_str_eq(endd1,endd2);
}   
START_TEST(test_sscanf_unsigned_7){
    char input_line_0[]="2147483647  11223344556677889900111222333444555  -55555  5555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned int uintt1=1, uintt2=2, uintt3=3, uintt4=4, uintt6=1, uintt7=2, uintt8=3, uintt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%u%*26u%u%u%u%s",&uintt1,&uintt2,&uintt3,&uintt4, endd1),s21_sscanf(input_line_1,"%u%*26u%u%u%u%s",&uintt6,&uintt7,&uintt8,&uintt9, endd2));
    ck_assert_int_eq(uintt1,uintt6);
    ck_assert_uint_eq(uintt1,uintt6);
    ck_assert_int_eq(uintt2,uintt7);
    ck_assert_uint_eq(uintt2,uintt7);
    ck_assert_int_eq(uintt3,uintt8);
    ck_assert_uint_eq(uintt3,uintt8);
    ck_assert_int_eq(uintt4,uintt9);
    ck_assert_uint_eq(uintt4,uintt9);
    ck_assert_str_eq(endd1,endd2);
}   
START_TEST(test_sscanf_unsigned_8){
    char input_line_0[]="21474  11223344556677889900111222333444555  -2147483647  5555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned int uintt1=1, uintt2=2, uintt3=3, uintt4=4, uintt6=1, uintt7=2, uintt8=3, uintt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%u%*26u%u%u%u%s",&uintt1,&uintt2,&uintt3,&uintt4, endd1),s21_sscanf(input_line_1,"%u%*26u%u%u%u%s",&uintt6,&uintt7,&uintt8,&uintt9, endd2));
    ck_assert_int_eq(uintt1,uintt6);
    ck_assert_uint_eq(uintt1,uintt6);
    ck_assert_int_eq(uintt2,uintt7);
    ck_assert_uint_eq(uintt2,uintt7);
    ck_assert_int_eq(uintt3,uintt8);
    ck_assert_uint_eq(uintt3,uintt8);
    ck_assert_int_eq(uintt4,uintt9);
    ck_assert_uint_eq(uintt4,uintt9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_unsigned_9){
    char input_line_0[]="4294967294  11223344556677889900111222333444555  -55555  5555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned int uintt1=1, uintt2=2, uintt3=3, uintt4=4, uintt6=1, uintt7=2, uintt8=3, uintt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%u%*26u%u%u%u%s",&uintt1,&uintt2,&uintt3,&uintt4, endd1),s21_sscanf(input_line_1,"%u%*26u%u%u%u%s",&uintt6,&uintt7,&uintt8,&uintt9, endd2));
    ck_assert_int_eq(uintt1,uintt6);
    ck_assert_uint_eq(uintt1,uintt6);
    ck_assert_int_eq(uintt2,uintt7);
    ck_assert_uint_eq(uintt2,uintt7);
    ck_assert_int_eq(uintt3,uintt8);
    ck_assert_uint_eq(uintt3,uintt8);
    ck_assert_int_eq(uintt4,uintt9);
    ck_assert_uint_eq(uintt4,uintt9);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_unsigned_10){
    char input_line_0[]="4294967295  11223344556677889900111222333444555  -55555  5555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned int uintt1=1, uintt2=2, uintt3=3, uintt4=4, uintt6=1, uintt7=2, uintt8=3, uintt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%u%*26u%u%u%u%s",&uintt1,&uintt2,&uintt3,&uintt4, endd1),s21_sscanf(input_line_1,"%u%*26u%u%u%u%s",&uintt6,&uintt7,&uintt8,&uintt9, endd2));
    ck_assert_int_eq(uintt1,uintt6);
    ck_assert_uint_eq(uintt1,uintt6);
    ck_assert_int_eq(uintt2,uintt7);
    ck_assert_uint_eq(uintt2,uintt7);
    ck_assert_int_eq(uintt3,uintt8);
    ck_assert_uint_eq(uintt3,uintt8);
    ck_assert_int_eq(uintt4,uintt9);
    ck_assert_uint_eq(uintt4,uintt9);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_unsigned_11){
    char input_line_0[]="-4294967297  11223344556677889900111222333444555  -55555  5555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned int uintt1=1, uintt2=2, uintt3=3, uintt4=4, uintt6=1, uintt7=2, uintt8=3, uintt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%u%*26u%u%u%u%s",&uintt1,&uintt2,&uintt3,&uintt4, endd1),s21_sscanf(input_line_1,"%u%*26u%u%u%u%s",&uintt6,&uintt7,&uintt8,&uintt9, endd2));
    ck_assert_int_eq(uintt1,uintt6);
    ck_assert_uint_eq(uintt1,uintt6);
    ck_assert_int_eq(uintt2,uintt7);
    ck_assert_uint_eq(uintt2,uintt7);
    ck_assert_int_eq(uintt3,uintt8);
    ck_assert_uint_eq(uintt3,uintt8);
    ck_assert_int_eq(uintt4,uintt9);
    ck_assert_uint_eq(uintt4,uintt9);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_unsigned_12){
    char input_line_0[]="   9223372036854774  11223344556677889900111222333444555  -55555  5555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned int uintt1=1, uintt2=2, uintt3=3, uintt4=4, uintt6=1, uintt7=2, uintt8=3, uintt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%u%*26u%u%u%u%s",&uintt1,&uintt2,&uintt3,&uintt4, endd1),s21_sscanf(input_line_1,"%u%*26u%u%u%u%s",&uintt6,&uintt7,&uintt8,&uintt9, endd2));
    ck_assert_int_eq(uintt1,uintt6);
    ck_assert_uint_eq(uintt1,uintt6);
    ck_assert_int_eq(uintt2,uintt7);
    ck_assert_uint_eq(uintt2,uintt7);
    ck_assert_int_eq(uintt3,uintt8);
    ck_assert_uint_eq(uintt3,uintt8);
    ck_assert_int_eq(uintt4,uintt9);
    ck_assert_uint_eq(uintt4,uintt9);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_unsigned_13){
    char input_line_0[]="   922337203685 55555 end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned int uintt1=1, uintt2=2, uintt7=2, uintt6=1;
    ck_assert_int_eq(sscanf(input_line_0,"%5u%u%s",&uintt1,&uintt2, endd1),s21_sscanf(input_line_1,"%5u%u%s",&uintt6,&uintt7,endd2));
    ck_assert_int_eq(uintt1,uintt6);
    ck_assert_uint_eq(uintt1,uintt6);
    ck_assert_int_eq(uintt2,uintt7);
    ck_assert_uint_eq(uintt2,uintt7);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_unsigned_14){
    char input_line_0[]="   92233                    55555 end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned int uintt1=1, uintt2=2, uintt7=2, uintt6=1;
    ck_assert_int_eq(sscanf(input_line_0,"%8u%u%s",&uintt1,&uintt2, endd1),s21_sscanf(input_line_1,"%8u%u%s",&uintt6,&uintt7,endd2));
    ck_assert_int_eq(uintt1,uintt6);
    ck_assert_uint_eq(uintt1,uintt6);
    ck_assert_int_eq(uintt2,uintt7);
    ck_assert_uint_eq(uintt2,uintt7);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_unsigned_15){
    char input_line_0[]="   +92233a567                    55555 end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned int uintt1=1, uintt2=2, uintt7=2, uintt6=1;
    ck_assert_int_eq(sscanf(input_line_0,"%8u%u%s",&uintt1,&uintt2, endd1),s21_sscanf(input_line_1,"%8u%u%s",&uintt6,&uintt7,endd2));
    ck_assert_int_eq(uintt1,uintt6);
    ck_assert_uint_eq(uintt1,uintt6);
    ck_assert_int_eq(uintt2,uintt7);
    ck_assert_uint_eq(uintt2,uintt7);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_unsigned_16){
    char input_line_0[]="   92233a567                    55555 end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned int uintt1=1, uintt2=2, uintt7=2, uintt6=1;
    ck_assert_int_eq(sscanf(input_line_0,"%8u%u%s",&uintt1,&uintt2, endd1),s21_sscanf(input_line_1,"%8u%u%s",&uintt6,&uintt7,endd2));
    ck_assert_int_eq(uintt1,uintt6);
    ck_assert_uint_eq(uintt1,uintt6);
    ck_assert_int_eq(uintt2,uintt7);
    ck_assert_uint_eq(uintt2,uintt7);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_unsigned_17){
    char input_line_0[]="   -4294967294                    -429496729455 end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned int uintt1=1, uintt2=2, uintt7=2, uintt6=1;
    ck_assert_int_eq(sscanf(input_line_0,"%u%u%s",&uintt1,&uintt2, endd1),s21_sscanf(input_line_1,"%u%u%s",&uintt6,&uintt7,endd2));
    ck_assert_int_eq(uintt1,uintt6);
    ck_assert_uint_eq(uintt1,uintt6);
    ck_assert_int_eq(uintt2,uintt7);
    ck_assert_uint_eq(uintt2,uintt7);
    ck_assert_str_eq(endd1,endd2);
}

/*  
//werror
START_TEST(test_sscanf_unsigned_4){
    char input_line_0[]="111111  11223344556677889900111222333444555  -55555  5555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned int uintt1=1, uintt2=2, uintt3=3, uintt4=4, uintt6=1, uintt7=2, uintt8=3, uintt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%l*u%u%u%u%s",&uintt1,&uintt2,&uintt3,&uintt4, endd1),s21_sscanf(input_line_1,"%l*u%u%u%u%s",&uintt6,&uintt7,&uintt8,&uintt9, endd2));
    ck_assert_int_eq(uintt1,uintt6);
    ck_assert_uint_eq(uintt1,uintt6);
    ck_assert_int_eq(uintt2,uintt7);
    ck_assert_uint_eq(uintt2,uintt7);
    ck_assert_int_eq(uintt3,uintt8);
    ck_assert_uint_eq(uintt3,uintt8);
    ck_assert_int_eq(uintt4,uintt9);
    ck_assert_uint_eq(uintt4,uintt9);
    ck_assert_str_eq(endd1,endd2);
}     
*/
//9.2 //elevator
START_TEST(test_sscanf_int_1){
    char input_line_0[]="111111  11223344556677889900111222333444555  -55555  5555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    int intt1=1,intt2=2,intt3=3,intt4=4,intt6=1,intt7=2, intt8=3, intt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%d%d%d%d%s",&intt1,&intt2,&intt3,&intt4, endd1),s21_sscanf(input_line_1,"%d%d%d%d%s",&intt6,&intt7,&intt8,&intt9, endd2));
    ck_assert_int_eq(intt1,intt6);
    ck_assert_int_eq(intt2,intt7);
    ck_assert_int_eq(intt3,intt8);
    ck_assert_int_eq(intt4,intt9);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_int_2){
    char input_line_0[]="111111  11223344556677889900111222333444555  -55555  5555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    int intt1=1,intt2=2,intt3=3,intt4=4,intt6=1,intt7=2, intt8=3, intt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%d%%%d%d%d%s",&intt1,&intt2,&intt3,&intt4, endd1),s21_sscanf(input_line_1,"%d%%%d%d%d%s",&intt6,&intt7,&intt8,&intt9, endd2));
    ck_assert_int_eq(intt1,intt6);
    ck_assert_int_eq(intt2,intt7);
    ck_assert_int_eq(intt3,intt8);
    ck_assert_int_eq(intt4,intt9);
    ck_assert_str_eq(endd1,endd2);
}    
START_TEST(test_sscanf_int_7){
    char input_line_0[]="111111  %11223344556677889900111222333444555  -55555  5555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    int intt1=1,intt2=2,intt3=3,intt4=4,intt6=1,intt7=2, intt8=3, intt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%d%%%d%d%d%s",&intt1,&intt2,&intt3,&intt4, endd1),s21_sscanf(input_line_1,"%d%%%d%d%d%s",&intt6,&intt7,&intt8,&intt9, endd2));
    ck_assert_int_eq(intt1,intt6);
    ck_assert_int_eq(intt2,intt7);
    ck_assert_int_eq(intt3,intt8);
    ck_assert_int_eq(intt4,intt9);
    ck_assert_str_eq(endd1,endd2);
}  
START_TEST(test_sscanf_int_3){
    char input_line_0[]="111111  11223344556677889900111222333444555  -55555  5555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    int intt1=1,intt2=2,intt3=3,intt4=4,intt6=1,intt7=2, intt8=3, intt9=4, intt5=5,intt10=5;
    ck_assert_int_eq(sscanf(input_line_0,"%d%7d%d%d%d%s",&intt1,&intt2,&intt5,&intt3,&intt4, endd1),s21_sscanf(input_line_1,"%d%7d%d%d%d%s",&intt6,&intt7,&intt10,&intt8,&intt9, endd2));
    ck_assert_int_eq(intt1,intt6);
    ck_assert_int_eq(intt2,intt7);
    ck_assert_int_eq(intt3,intt8);
    ck_assert_int_eq(intt4,intt9);
    ck_assert_int_eq(intt5,intt10);
    ck_assert_str_eq(endd1,endd2);
}  
START_TEST(test_sscanf_int_5){
    char input_line_0[]="111111  11223344556677889900111222333444555  -55555  5555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    int intt1=1,intt2=2,intt3=3,intt6=1,intt7=2, intt8=3;
    ck_assert_int_eq(sscanf(input_line_0,"%d%*d%d%d%s",&intt1,&intt2,&intt3, endd1),s21_sscanf(input_line_1,"%d%*d%d%d%s",&intt6,&intt7,&intt8, endd2));
    ck_assert_int_eq(intt1,intt6);
    ck_assert_int_eq(intt2,intt7);
    ck_assert_int_eq(intt3,intt8);
    ck_assert_str_eq(endd1,endd2);
}   
START_TEST(test_sscanf_int_6){
    char input_line_0[]="111111  11223344556677889900111222333444555  -55555  5555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    int intt1=1,intt2=2,intt3=3,intt4=4,intt6=1,intt7=2, intt8=3,intt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%d%*26d%d%d%d%s",&intt1,&intt2,&intt3,&intt4, endd1),s21_sscanf(input_line_1,"%d%*26d%d%d%d%s",&intt6,&intt7,&intt8,&intt9, endd2));
    ck_assert_int_eq(intt1,intt6);
    ck_assert_int_eq(intt2,intt7);
    ck_assert_int_eq(intt3,intt8);
    ck_assert_int_eq(intt4,intt9);
    ck_assert_str_eq(endd1,endd2);
}     
START_TEST(test_sscanf_int_8){
    char input_line_0[]="111111  11223344556677889900111222333444555  -55555  5555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    int intt1=1,intt2=2,intt3=3,intt4=4,intt6=1,intt7=2, intt8=3,intt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%d%*25d%d%d%d%s",&intt1,&intt2,&intt3,&intt4, endd1),s21_sscanf(input_line_1,"%d%*25d%d%d%d%s",&intt6,&intt7,&intt8,&intt9, endd2));
    ck_assert_int_eq(intt1,intt6);
    ck_assert_int_eq(intt2,intt7);
    ck_assert_int_eq(intt3,intt8);
    ck_assert_int_eq(intt4,intt9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_int_9){
    char input_line_0[]="2147483647  11223344556677889900111222333444555  -55555  5555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    int intt1=1,intt2=2,intt3=3,intt4=4,intt6=1,intt7=2, intt8=3,intt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%d%*25d%d%d%d%s",&intt1,&intt2,&intt3,&intt4, endd1),s21_sscanf(input_line_1,"%d%*25d%d%d%d%s",&intt6,&intt7,&intt8,&intt9, endd2));
    ck_assert_int_eq(intt1,intt6);
    ck_assert_int_eq(intt2,intt7);
    ck_assert_int_eq(intt3,intt8);
    ck_assert_int_eq(intt4,intt9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_int_10){
    char input_line_0[]="-2147483647  11223344556677889900111222333444555  -55555  5555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    int intt1=1,intt2=2,intt3=3,intt4=4,intt6=1,intt7=2, intt8=3,intt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%d%*25d%d%d%d%s",&intt1,&intt2,&intt3,&intt4, endd1),s21_sscanf(input_line_1,"%d%*25d%d%d%d%s",&intt6,&intt7,&intt8,&intt9, endd2));
    ck_assert_int_eq(intt1,intt6);
    ck_assert_int_eq(intt2,intt7);
    ck_assert_int_eq(intt3,intt8);
    ck_assert_int_eq(intt4,intt9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_int_11){
    char input_line_0[]="0  11223344556677889900111222333444555  -55555  5555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    int intt1=1,intt2=2,intt3=3,intt4=4,intt6=1,intt7=2, intt8=3,intt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%d%*25d%d%d%d%s",&intt1,&intt2,&intt3,&intt4, endd1),s21_sscanf(input_line_1,"%d%*25d%d%d%d%s",&intt6,&intt7,&intt8,&intt9, endd2));
    ck_assert_int_eq(intt1,intt6);
    ck_assert_int_eq(intt2,intt7);
    ck_assert_int_eq(intt3,intt8);
    ck_assert_int_eq(intt4,intt9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_int_12){
    char input_line_0[]="  05.5  11223344556677889900111222333444555  -55555  5555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    int intt1=1,intt2=2,intt3=3,intt4=4,intt6=1,intt7=2, intt8=3,intt9=4;
    //printf("%s\nHere==>%c\n",input_line_0, input_line_0[4]);
    ck_assert_int_eq(sscanf(input_line_0,"%d%*25d%d%d%d%s",&intt1,&intt2,&intt3,&intt4, endd1),s21_sscanf(input_line_1,"%d%*25d%d%d%d%s",&intt6,&intt7,&intt8,&intt9, endd2));
    ck_assert_int_eq(intt1,intt6);
    ck_assert_int_eq(intt2,intt7);
    ck_assert_int_eq(intt3,intt8);
    ck_assert_int_eq(intt4,intt9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_int_13){
    char input_line_0[]="-2147483648  11223344556677889900111222333444555  -55555  5555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    int intt1=1,intt2=2,intt3=3,intt4=4,intt6=1,intt7=2, intt8=3,intt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%d%*25d%d%d%d%s",&intt1,&intt2,&intt3,&intt4, endd1),s21_sscanf(input_line_1,"%d%*25d%d%d%d%s",&intt6,&intt7,&intt8,&intt9, endd2));
    ck_assert_int_eq(intt1,intt6);
    ck_assert_int_eq(intt2,intt7);
    ck_assert_int_eq(intt3,intt8);
    ck_assert_int_eq(intt4,intt9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_int_14){
    char input_line_0[]="-2147483649  11223344556677889900111222333444555  -55555  5555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    int intt1=1,intt2=2,intt3=3,intt4=4,intt6=1,intt7=2, intt8=3,intt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%d%*25d%d%d%d%s",&intt1,&intt2,&intt3,&intt4, endd1),s21_sscanf(input_line_1,"%d%*25d%d%d%d%s",&intt6,&intt7,&intt8,&intt9, endd2));
    ck_assert_int_eq(intt1,intt6);
    ck_assert_int_eq(intt2,intt7);
    ck_assert_int_eq(intt3,intt8);
    ck_assert_int_eq(intt4,intt9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_int_15){
    char input_line_0[]="2147483655  11223344556677889900111222333444555  -55555  5555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    int intt1=1,intt2=2,intt3=3,intt4=4,intt6=1,intt7=2, intt8=3,intt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%d%*25d%d%d%d%s",&intt1,&intt2,&intt3,&intt4, endd1),s21_sscanf(input_line_1,"%d%*25d%d%d%d%s",&intt6,&intt7,&intt8,&intt9, endd2));
    ck_assert_int_eq(intt1,intt6);
    ck_assert_int_eq(intt2,intt7);
    ck_assert_int_eq(intt3,intt8);
    ck_assert_int_eq(intt4,intt9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_int_16){
    char input_line_0[]="   922337203685 55555 end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    int intt1=1, intt2=2, intt7=2, intt6=1;
    ck_assert_int_eq(sscanf(input_line_0,"%5d%d%s",&intt1,&intt2, endd1),s21_sscanf(input_line_1,"%5d%d%s",&intt6,&intt7,endd2));
    ck_assert_int_eq(intt1,intt6);
    ck_assert_int_eq(intt2,intt7);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_int_17){
    char input_line_0[]="   92233                    55555 end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    int intt1=1, intt2=2, intt7=2, intt6=1;
    ck_assert_int_eq(sscanf(input_line_0,"%8d%d%s",&intt1,&intt2, endd1),s21_sscanf(input_line_1,"%8d%d%s",&intt6,&intt7,endd2));
    ck_assert_int_eq(intt1,intt6);
    ck_assert_int_eq(intt2,intt7);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_int_18){
    char input_line_0[]="   +92233a567                    55555 end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    int intt1=1, intt2=2, intt7=2, intt6=1;
    ck_assert_int_eq(sscanf(input_line_0,"%8d%d%s",&intt1,&intt2, endd1),s21_sscanf(input_line_1,"%8d%d%s",&intt6,&intt7,endd2));
    ck_assert_int_eq(intt1,intt6);
    ck_assert_int_eq(intt2,intt7);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_int_19){
    char input_line_0[]="   92233a567                    55555 end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    int intt1=1, intt2=2, intt7=2, intt6=1;
    ck_assert_int_eq(sscanf(input_line_0,"%8d%d%s",&intt1,&intt2, endd1),s21_sscanf(input_line_1,"%8d%d%s",&intt6,&intt7,endd2));
    ck_assert_int_eq(intt1,intt6);
    ck_assert_int_eq(intt2,intt7);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_int_20){
    char input_line_0[]="  -.6                   -0.6 end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    int intt1=1, intt2=2, intt7=2, intt6=1;
    ck_assert_int_eq(sscanf(input_line_0,"%8d%d%s",&intt1,&intt2, endd1),s21_sscanf(input_line_1,"%8d%d%s",&intt6,&intt7,endd2));
    ck_assert_int_eq(intt1,intt6);
    ck_assert_int_eq(intt2,intt7);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_int_21){
    char input_line_0[]="  .6                   -0.6 end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    int intt1=1, intt2=2, intt7=2, intt6=1;
    ck_assert_int_eq(sscanf(input_line_0,"%8d%d%s",&intt1,&intt2, endd1),s21_sscanf(input_line_1,"%8d%d%s",&intt6,&intt7,endd2));
    ck_assert_int_eq(intt1,intt6);
    ck_assert_int_eq(intt2,intt7);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_int_22){
    char input_line_0[]="  -f                   -0.6 end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    int intt1=1, intt2=2, intt7=2, intt6=1;
    ck_assert_int_eq(sscanf(input_line_0,"%8d%d%s",&intt1,&intt2, endd1),s21_sscanf(input_line_1,"%8d%d%s",&intt6,&intt7,endd2));
    ck_assert_int_eq(intt1,intt6);
    ck_assert_int_eq(intt2,intt7);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_int_23){
    char input_line_0[]="  4294967304                  -4294967304 end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    int intt1=1, intt2=2, intt7=2, intt6=1;
    ck_assert_int_eq(sscanf(input_line_0,"%d%d%s",&intt1,&intt2, endd1),s21_sscanf(input_line_1,"%d%d%s",&intt6,&intt7,endd2));
    ck_assert_int_eq(intt1,intt6);
    ck_assert_int_eq(intt2,intt7);
    ck_assert_str_eq(endd1,endd2);
}
/*
//werror
START_TEST(test_sscanf_int_4){
    char input_line_0[]="111111  11223344556677889900111222333444555  -55555  5555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    int intt1=1,intt2=2,intt3=3,intt4=4,intt6=1,intt7=2, intt8=3,intt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%l5d%d%d%d%s",&intt1,&intt2,&intt3,&intt4, endd1),s21_sscanf(input_line_1,"%l5d%d%d%d%s",&intt6,&intt7,&intt8,&intt9, endd2));
    ck_assert_int_eq(intt1,intt6);
    ck_assert_uint_eq(intt1,intt6);
    ck_assert_int_eq(intt2,intt7);
    ck_assert_uint_eq(intt2,intt7);
    ck_assert_int_eq(intt3,intt8);
    ck_assert_uint_eq(intt3,intt8);
    ck_assert_int_eq(intt4,intt9);
    ck_assert_uint_eq(intt4,intt9);
    ck_assert_str_eq(endd1,endd2);
}     
*/
//9.3 //elevator
START_TEST(test_sscanf_unsigned_short_1){
    char input_line_0[]="11111  11223344556677889900111222333444555  -5555  555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned short ushortt1=1,ushortt2=2,ushortt3=3,ushortt4=4,ushortt6=1,ushortt7=2,ushortt8=3,ushortt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%hu%hu%hu%hu%s",&ushortt1,&ushortt2,&ushortt3,&ushortt4, endd1),s21_sscanf(input_line_1,"%hu%hu%hu%hu%s",&ushortt6,&ushortt7,&ushortt8,&ushortt9, endd2));
    ck_assert_uint_eq(ushortt1,ushortt6);
    ck_assert_int_eq(ushortt1,ushortt6);
    ck_assert_uint_eq(ushortt2,ushortt7);
    ck_assert_int_eq(ushortt2,ushortt7);
    ck_assert_uint_eq(ushortt3,ushortt8);
    ck_assert_int_eq(ushortt3,ushortt8);
    ck_assert_uint_eq(ushortt4,ushortt9);
    ck_assert_int_eq(ushortt4,ushortt9);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_unsigned_short_2){
    char input_line_0[]="11111  11223344556677889900111222333444555  -5555  555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned short ushortt1=1,ushortt2=2,ushortt3=3,ushortt4=4,ushortt6=1,ushortt7=2,ushortt8=3,ushortt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%hu%%%hu%hu%hu%s",&ushortt1,&ushortt2,&ushortt3,&ushortt4, endd1),s21_sscanf(input_line_1,"%hu%%%hu%hu%hu%s",&ushortt6,&ushortt7,&ushortt8,&ushortt9, endd2));
    ck_assert_uint_eq(ushortt1,ushortt6);
    ck_assert_int_eq(ushortt1,ushortt6);
    ck_assert_uint_eq(ushortt2,ushortt7);
    ck_assert_int_eq(ushortt2,ushortt7);
    ck_assert_uint_eq(ushortt3,ushortt8);
    ck_assert_int_eq(ushortt3,ushortt8);
    ck_assert_uint_eq(ushortt4,ushortt9);
    ck_assert_int_eq(ushortt4,ushortt9);
    ck_assert_str_eq(endd1,endd2);
}    
START_TEST(test_sscanf_unsigned_short_7){
    char input_line_0[]="11111  %\n\n11223344556677889900111222333444555  -5555  555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned short ushortt1=1,ushortt2=2,ushortt3=3,ushortt4=4,ushortt6=1,ushortt7=2,ushortt8=3,ushortt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%hu%%%hu%hu%hu%s",&ushortt1,&ushortt2,&ushortt3,&ushortt4, endd1),s21_sscanf(input_line_1,"%hu%%%hu%hu%hu%s",&ushortt6,&ushortt7,&ushortt8,&ushortt9, endd2));
    ck_assert_uint_eq(ushortt1,ushortt6);
    ck_assert_int_eq(ushortt1,ushortt6);
    ck_assert_uint_eq(ushortt2,ushortt7);
    ck_assert_int_eq(ushortt2,ushortt7);
    ck_assert_uint_eq(ushortt3,ushortt8);
    ck_assert_int_eq(ushortt3,ushortt8);
    ck_assert_uint_eq(ushortt4,ushortt9);
    ck_assert_int_eq(ushortt4,ushortt9);
    ck_assert_str_eq(endd1,endd2);
}  
START_TEST(test_sscanf_unsigned_short_3){
    char input_line_0[]="11111  11223344556677889900111222333444555  -5555  555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned short ushortt1=1,ushortt2=2,ushortt3=3,ushortt4=4,ushortt6=1,ushortt7=2,ushortt8=3,ushortt9=4,ushortt5=5,ushortt10=5;
    ck_assert_int_eq(sscanf(input_line_0,"%hu%7hu%hu%hu%hu%s",&ushortt1,&ushortt2,&ushortt5, &ushortt3,&ushortt4, endd1),s21_sscanf(input_line_1,"%hu%7hu%hu%hu%hu%s",&ushortt6,&ushortt7,&ushortt10,&ushortt8,&ushortt9, endd2));
    ck_assert_uint_eq(ushortt1,ushortt6);
    ck_assert_int_eq(ushortt1,ushortt6);
    ck_assert_uint_eq(ushortt2,ushortt7);
    ck_assert_int_eq(ushortt2,ushortt7);
    ck_assert_uint_eq(ushortt3,ushortt8);
    ck_assert_int_eq(ushortt3,ushortt8);
    ck_assert_uint_eq(ushortt4,ushortt9);
    ck_assert_int_eq(ushortt4,ushortt9);
    ck_assert_uint_eq(ushortt5,ushortt10);
    ck_assert_int_eq(ushortt5,ushortt10);
    ck_assert_str_eq(endd1,endd2);
}  
START_TEST(test_sscanf_unsigned_short_5){
    char input_line_0[]="11111  11223344556677889900111222333444555  -5555  555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned short ushortt1=1,ushortt2=2,ushortt3=3,ushortt6=1,ushortt7=2,ushortt8=3;
    ck_assert_int_eq(sscanf(input_line_0,"%hu%*u%hu%hu%s",&ushortt1,&ushortt2,&ushortt3, endd1),s21_sscanf(input_line_1,"%hu%*u%hu%hu%s",&ushortt6,&ushortt7,&ushortt8, endd2));
    ck_assert_uint_eq(ushortt1,ushortt6);
    ck_assert_int_eq(ushortt1,ushortt6);
    ck_assert_uint_eq(ushortt2,ushortt7);
    ck_assert_int_eq(ushortt2,ushortt7);
    ck_assert_uint_eq(ushortt3,ushortt8);
    ck_assert_int_eq(ushortt3,ushortt8);
    ck_assert_str_eq(endd1,endd2);
}   
START_TEST(test_sscanf_unsigned_short_6){
    char input_line_0[]="11111  11223344556677889900111222333444555  -5555  555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned short ushortt1=1,ushortt2=2,ushortt3=3,ushortt4=4,ushortt6=1,ushortt7=2,ushortt8=3,ushortt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%hu%*30u%hu%hu%hu%s",&ushortt1,&ushortt2,&ushortt3,&ushortt4, endd1),s21_sscanf(input_line_1,"%hu%*30u%hu%hu%hu%s",&ushortt6,&ushortt7,&ushortt8,&ushortt9, endd2));
    ck_assert_uint_eq(ushortt1,ushortt6);
    ck_assert_int_eq(ushortt1,ushortt6);
    ck_assert_uint_eq(ushortt2,ushortt7);
    ck_assert_int_eq(ushortt2,ushortt7);
    ck_assert_uint_eq(ushortt3,ushortt8);
    ck_assert_int_eq(ushortt3,ushortt8);
    ck_assert_uint_eq(ushortt4,ushortt9);
    ck_assert_int_eq(ushortt4,ushortt9);
    ck_assert_str_eq(endd1,endd2);
}     
START_TEST(test_sscanf_unsigned_short_8){
    char input_line_0[]="11111  11223344556677889900111222333444555  -5555  555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned short ushortt1=1,ushortt2=2,ushortt3=3,ushortt4=4,ushortt6=1,ushortt7=2,ushortt8=3,ushortt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%hu%*25u%hu%hu%hu%s",&ushortt1,&ushortt2,&ushortt3,&ushortt4, endd1),s21_sscanf(input_line_1,"%hu%*25u%hu%hu%hu%s",&ushortt6,&ushortt7,&ushortt8,&ushortt9, endd2));
    ck_assert_uint_eq(ushortt1,ushortt6);
    ck_assert_int_eq(ushortt1,ushortt6);
    ck_assert_uint_eq(ushortt2,ushortt7);
    ck_assert_int_eq(ushortt2,ushortt7);
    ck_assert_uint_eq(ushortt3,ushortt8);
    ck_assert_int_eq(ushortt3,ushortt8);
    ck_assert_uint_eq(ushortt4,ushortt9);
    ck_assert_int_eq(ushortt4,ushortt9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_unsigned_short_9){
    char input_line_0[]="65534  11223344556677889900111222333444555  -5555  555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned short ushortt1=1,ushortt2=2,ushortt3=3,ushortt4=4,ushortt6=1,ushortt7=2,ushortt8=3,ushortt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%hu%*31u\n\n%hu%hu%hu%s",&ushortt1,&ushortt2,&ushortt3,&ushortt4, endd1),s21_sscanf(input_line_1,"%hu%*31u\n\n%hu%hu%hu%s",&ushortt6,&ushortt7,&ushortt8,&ushortt9, endd2));
    ck_assert_uint_eq(ushortt1,ushortt6);
    ck_assert_int_eq(ushortt1,ushortt6);
    ck_assert_uint_eq(ushortt2,ushortt7);
    ck_assert_int_eq(ushortt2,ushortt7);
    ck_assert_uint_eq(ushortt3,ushortt8);
    ck_assert_int_eq(ushortt3,ushortt8);
    ck_assert_uint_eq(ushortt4,ushortt9);
    ck_assert_int_eq(ushortt4,ushortt9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_unsigned_short_24){
    char input_line_0[]="-65534  11223344556677889900111222333444555  -5555  555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned short ushortt1=1,ushortt2=2,ushortt3=3,ushortt4=4,ushortt6=1,ushortt7=2,ushortt8=3,ushortt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%hu%*31u\n\n%hu%hu%hu%s",&ushortt1,&ushortt2,&ushortt3,&ushortt4, endd1),s21_sscanf(input_line_1,"%hu%*31u\n\n%hu%hu%hu%s",&ushortt6,&ushortt7,&ushortt8,&ushortt9, endd2));
    ck_assert_uint_eq(ushortt1,ushortt6);
    ck_assert_int_eq(ushortt1,ushortt6);
    ck_assert_uint_eq(ushortt2,ushortt7);
    ck_assert_int_eq(ushortt2,ushortt7);
    ck_assert_uint_eq(ushortt3,ushortt8);
    ck_assert_int_eq(ushortt3,ushortt8);
    ck_assert_uint_eq(ushortt4,ushortt9);
    ck_assert_int_eq(ushortt4,ushortt9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_unsigned_short_25){
    char input_line_0[]="32767  11223344556677889900111222333444555  -5555  555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned short ushortt1=1,ushortt2=2,ushortt3=3,ushortt4=4,ushortt6=1,ushortt7=2,ushortt8=3,ushortt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%hu%*31u\n\n%hu%hu%hu%s",&ushortt1,&ushortt2,&ushortt3,&ushortt4, endd1),s21_sscanf(input_line_1,"%hu%*31u\n\n%hu%hu%hu%s",&ushortt6,&ushortt7,&ushortt8,&ushortt9, endd2));
    ck_assert_uint_eq(ushortt1,ushortt6);
    ck_assert_int_eq(ushortt1,ushortt6);
    ck_assert_uint_eq(ushortt2,ushortt7);
    ck_assert_int_eq(ushortt2,ushortt7);
    ck_assert_uint_eq(ushortt3,ushortt8);
    ck_assert_int_eq(ushortt3,ushortt8);
    ck_assert_uint_eq(ushortt4,ushortt9);
    ck_assert_int_eq(ushortt4,ushortt9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_unsigned_short_26){
    char input_line_0[]="-32767  11223344556677889900111222333444555  -5555  555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned short ushortt1=1,ushortt2=2,ushortt3=3,ushortt4=4,ushortt6=1,ushortt7=2,ushortt8=3,ushortt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%hu%*31u\n\n%hu%hu%hu%s",&ushortt1,&ushortt2,&ushortt3,&ushortt4, endd1),s21_sscanf(input_line_1,"%hu%*31u\n\n%hu%hu%hu%s",&ushortt6,&ushortt7,&ushortt8,&ushortt9, endd2));
    ck_assert_uint_eq(ushortt1,ushortt6);
    ck_assert_int_eq(ushortt1,ushortt6);
    ck_assert_uint_eq(ushortt2,ushortt7);
    ck_assert_int_eq(ushortt2,ushortt7);
    ck_assert_uint_eq(ushortt3,ushortt8);
    ck_assert_int_eq(ushortt3,ushortt8);
    ck_assert_uint_eq(ushortt4,ushortt9);
    ck_assert_int_eq(ushortt4,ushortt9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_unsigned_short_27){
    char input_line_0[]="32770  11223344556677889900111222333444555  -5555  555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned short ushortt1=1,ushortt2=2,ushortt3=3,ushortt4=4,ushortt6=1,ushortt7=2,ushortt8=3,ushortt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%hu%*31u\n\n%hu%hu%hu%s",&ushortt1,&ushortt2,&ushortt3,&ushortt4, endd1),s21_sscanf(input_line_1,"%hu%*31u\n\n%hu%hu%hu%s",&ushortt6,&ushortt7,&ushortt8,&ushortt9, endd2));
    ck_assert_uint_eq(ushortt1,ushortt6);
    ck_assert_int_eq(ushortt1,ushortt6);
    ck_assert_uint_eq(ushortt2,ushortt7);
    ck_assert_int_eq(ushortt2,ushortt7);
    ck_assert_uint_eq(ushortt3,ushortt8);
    ck_assert_int_eq(ushortt3,ushortt8);
    ck_assert_uint_eq(ushortt4,ushortt9);
    ck_assert_int_eq(ushortt4,ushortt9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_unsigned_short_28){
    char input_line_0[]="65535   11223344556677889900111222333444555  -5555  555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned short ushortt1=1,ushortt2=2,ushortt3=3,ushortt4=4,ushortt6=1,ushortt7=2,ushortt8=3,ushortt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%hu%*31u\n\n%hu%hu%hu%s",&ushortt1,&ushortt2,&ushortt3,&ushortt4, endd1),s21_sscanf(input_line_1,"%hu%*31u\n\n%hu%hu%hu%s",&ushortt6,&ushortt7,&ushortt8,&ushortt9, endd2));
    ck_assert_uint_eq(ushortt1,ushortt6);
    ck_assert_int_eq(ushortt1,ushortt6);
    ck_assert_uint_eq(ushortt2,ushortt7);
    ck_assert_int_eq(ushortt2,ushortt7);
    ck_assert_uint_eq(ushortt3,ushortt8);
    ck_assert_int_eq(ushortt3,ushortt8);
    ck_assert_uint_eq(ushortt4,ushortt9);
    ck_assert_int_eq(ushortt4,ushortt9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_unsigned_short_29){
    char input_line_0[]="-65536   11223344556677889900111222333444555  -5555  555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned short ushortt1=1,ushortt2=2,ushortt3=3,ushortt4=4,ushortt6=1,ushortt7=2,ushortt8=3,ushortt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%hu%*31u\n\n%hu%hu%hu%s",&ushortt1,&ushortt2,&ushortt3,&ushortt4, endd1),s21_sscanf(input_line_1,"%hu%*31u\n\n%hu%hu%hu%s",&ushortt6,&ushortt7,&ushortt8,&ushortt9, endd2));
    ck_assert_uint_eq(ushortt1,ushortt6);
    ck_assert_int_eq(ushortt1,ushortt6);
    ck_assert_uint_eq(ushortt2,ushortt7);
    ck_assert_int_eq(ushortt2,ushortt7);
    ck_assert_uint_eq(ushortt3,ushortt8);
    ck_assert_int_eq(ushortt3,ushortt8);
    ck_assert_uint_eq(ushortt4,ushortt9);
    ck_assert_int_eq(ushortt4,ushortt9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_unsigned_short_10){
    char input_line_0[]="65536  11223344556677889900111222333444555  -55555  5555.444   end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned short ushortt1=1,ushortt2=2,ushortt3=3,ushortt4=4,ushortt6=1,ushortt7=2,ushortt8=3,ushortt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%hu%*31u\n\n%hu%hu%hu%s",&ushortt1,&ushortt2,&ushortt3,&ushortt4, endd1),s21_sscanf(input_line_1,"%hu%*31u\n\n%hu%hu%hu%s",&ushortt6,&ushortt7,&ushortt8,&ushortt9, endd2));
    ck_assert_uint_eq(ushortt1,ushortt6);
    ck_assert_int_eq(ushortt1,ushortt6);
    ck_assert_uint_eq(ushortt2,ushortt7);
    ck_assert_int_eq(ushortt2,ushortt7);
    ck_assert_uint_eq(ushortt3,ushortt8);
    ck_assert_int_eq(ushortt3,ushortt8);
    ck_assert_uint_eq(ushortt4,ushortt9);
    ck_assert_int_eq(ushortt4,ushortt9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_unsigned_short_11){
    char input_line_0[]="0  11223344556677889900111222333444555  -55555  5555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned short ushortt1=1,ushortt2=2,ushortt3=3,ushortt4=4,ushortt6=1,ushortt7=2,ushortt8=3,ushortt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%hu%*31u%hu%hu%hu%s",&ushortt1,&ushortt2,&ushortt3,&ushortt4, endd1),s21_sscanf(input_line_1,"%hu%*31u%hu%hu%hu%s",&ushortt6,&ushortt7,&ushortt8,&ushortt9, endd2));
    ck_assert_uint_eq(ushortt1,ushortt6);
    ck_assert_int_eq(ushortt1,ushortt6);
    ck_assert_uint_eq(ushortt2,ushortt7);
    ck_assert_int_eq(ushortt2,ushortt7);
    ck_assert_uint_eq(ushortt3,ushortt8);
    ck_assert_int_eq(ushortt3,ushortt8);
    ck_assert_uint_eq(ushortt4,ushortt9);
    ck_assert_int_eq(ushortt4,ushortt9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_unsigned_short_12){
    char input_line_0[]="  05.5  11223344556677889900111222333444555  -55555  5555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned short ushortt1=1,ushortt2=2,ushortt3=3,ushortt4=4,ushortt6=1,ushortt7=2,ushortt8=3,ushortt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%hu%*31u%hu\t\t%hu%hu%s",&ushortt1,&ushortt2,&ushortt3,&ushortt4, endd1),s21_sscanf(input_line_1,"%hu%*31u%hu\t\t%hu%hu%s",&ushortt6,&ushortt7,&ushortt8,&ushortt9, endd2));
    ck_assert_uint_eq(ushortt1,ushortt6);
    ck_assert_int_eq(ushortt1,ushortt6);
    ck_assert_uint_eq(ushortt2,ushortt7);
    ck_assert_int_eq(ushortt2,ushortt7);
    ck_assert_uint_eq(ushortt3,ushortt8);
    ck_assert_int_eq(ushortt3,ushortt8);
    ck_assert_uint_eq(ushortt4,ushortt9);
    ck_assert_int_eq(ushortt4,ushortt9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_unsigned_short_13){
    char input_line_0[]="9223372036854775807  11223344556677889900111222333444555  -55555  5555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned short ushortt1=1,ushortt2=2,ushortt3=3,ushortt4=4,ushortt6=1,ushortt7=2,ushortt8=3,ushortt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%hu%*31u%hu%hu%hu%s",&ushortt1,&ushortt2,&ushortt3,&ushortt4, endd1),s21_sscanf(input_line_1,"%hu%*31u%hu%hu%hu%s",&ushortt6,&ushortt7,&ushortt8,&ushortt9, endd2));
    ck_assert_uint_eq(ushortt1,ushortt6);
    ck_assert_int_eq(ushortt1,ushortt6);
    ck_assert_uint_eq(ushortt2,ushortt7);
    ck_assert_int_eq(ushortt2,ushortt7);
    ck_assert_uint_eq(ushortt3,ushortt8);
    ck_assert_int_eq(ushortt3,ushortt8);
    ck_assert_uint_eq(ushortt4,ushortt9);
    ck_assert_int_eq(ushortt4,ushortt9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_unsigned_short_14){

    char input_line_0[]="5 -9999999999999999  11223344556677889900111222333444555  -55555  5555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned short ushortt1=1,ushortt2=2,ushortt3=3,ushortt4=4,ushortt6=1,ushortt7=2,ushortt8=3,ushortt9=4, ushortt5=5, ushortt10=5;
    ck_assert_int_eq(sscanf(input_line_0,"%hu%hu%*31u%hu%hu%hu%s",&ushortt5,&ushortt1,&ushortt2,&ushortt3,&ushortt4, endd1),s21_sscanf(input_line_1,"%hu%hu%*31u%hu%hu%hu%s",&ushortt10,&ushortt6,&ushortt7,&ushortt8,&ushortt9, endd2));
    ck_assert_uint_eq(ushortt5,ushortt10);
    ck_assert_int_eq(ushortt5,ushortt10);
    ck_assert_uint_eq(ushortt1,ushortt6);
    ck_assert_int_eq(ushortt1,ushortt6);
    ck_assert_uint_eq(ushortt2,ushortt7);
    ck_assert_int_eq(ushortt2,ushortt7);
    ck_assert_uint_eq(ushortt3,ushortt8);
    ck_assert_int_eq(ushortt3,ushortt8);
    ck_assert_uint_eq(ushortt4,ushortt9);
    ck_assert_int_eq(ushortt4,ushortt9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_unsigned_short_15){
    char input_line_0[]="99999999999999999  11223344556677889900111222333444555  -55555  5555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned short ushortt1=1,ushortt2=2,ushortt3=3,ushortt4=4,ushortt6=1,ushortt7=2,ushortt8=3,ushortt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%hu%*31u%hu%hu%hu%s",&ushortt1,&ushortt2,&ushortt3,&ushortt4, endd1),s21_sscanf(input_line_1,"%hu%*31u%hu%hu%hu%s",&ushortt6,&ushortt7,&ushortt8,&ushortt9, endd2));
    ck_assert_uint_eq(ushortt1,ushortt6);
    ck_assert_int_eq(ushortt1,ushortt6);
    ck_assert_uint_eq(ushortt2,ushortt7);
    ck_assert_int_eq(ushortt2,ushortt7);
    ck_assert_uint_eq(ushortt3,ushortt8);
    ck_assert_int_eq(ushortt3,ushortt8);
    ck_assert_uint_eq(ushortt4,ushortt9);
    ck_assert_int_eq(ushortt4,ushortt9);
    ck_assert_str_eq(endd1,endd2);
} 
/*
//too small and too big
START_TEST(test_sscanf_unsigned_short_14){

    char input_line_0[]="5 -1000000000000000  11223344556677889900111222333444555  -55555  5555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned short ushortt1=1,ushortt2=2,ushortt3=3,ushortt4=4,ushortt6=1,ushortt7=2,ushortt8=3,ushortt9=4, ushortt5=5, ushortt10=5;
    //ck_assert_int_eq(sscanf(input_line_0,"%hu%*31hu%hu%hu%hu%s",&ushortt1,&ushortt2,&ushortt3,&ushortt4, endd1),s21_sscanf(input_line_1,"%hu%*31hu%hu%hu%hu%s",&ushortt6,&ushortt7,&ushortt8,&ushortt9, endd2));
    sscanf(input_line_0,"%hu%hu%*31hu%hu%hu%hu%s",&ushortt5,&ushortt1,&ushortt2,&ushortt3,&ushortt4, endd1);
    s21_sscanf(input_line_1,"%hu%hu%*31hu%hu%hu%hu%s",&ushortt10,&ushortt6,&ushortt7,&ushortt8,&ushortt9, endd2);
    ck_assert_uint_eq(ushortt5,ushortt10);
    ck_assert_int_eq(ushortt5,ushortt10);
    ck_assert_uint_eq(ushortt1,ushortt6);
    ck_assert_int_eq(ushortt1,ushortt6);
    ck_assert_uint_eq(ushortt2,ushortt7);
    ck_assert_int_eq(ushortt2,ushortt7);
    ck_assert_uint_eq(ushortt3,ushortt8);
    ck_assert_int_eq(ushortt3,ushortt8);
    ck_assert_uint_eq(ushortt4,ushortt9);
    ck_assert_int_eq(ushortt4,ushortt9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_unsigned_short_15){
    char input_line_0[]="100000000000000000  11223344556677889900111222333444555  -55555  5555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned short ushortt1=1,ushortt2=2,ushortt3=3,ushortt4=4,ushortt6=1,ushortt7=2,ushortt8=3,ushortt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%hu%*31hu%hu%hu%hu%s",&ushortt1,&ushortt2,&ushortt3,&ushortt4, endd1),s21_sscanf(input_line_1,"%hu%*31hu%hu%hu%hu%s",&ushortt6,&ushortt7,&ushortt8,&ushortt9, endd2));
    ck_assert_uint_eq(ushortt1,ushortt6);
    ck_assert_int_eq(ushortt1,ushortt6);
    ck_assert_uint_eq(ushortt2,ushortt7);
    ck_assert_int_eq(ushortt2,ushortt7);
    ck_assert_uint_eq(ushortt3,ushortt8);
    ck_assert_int_eq(ushortt3,ushortt8);
    ck_assert_uint_eq(ushortt4,ushortt9);
    ck_assert_int_eq(ushortt4,ushortt9);
    ck_assert_str_eq(endd1,endd2);
} 
*/
START_TEST(test_sscanf_unsigned_short_16){
    char input_line_0[]="   922337203685 55555 end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned short ushortt1=1,ushortt2=2,ushortt6=1,ushortt7=2;
    ck_assert_int_eq(sscanf(input_line_0,"%4hu%hu%s",&ushortt1,&ushortt2, endd1),s21_sscanf(input_line_1,"%4hu%hu%s",&ushortt6,&ushortt7,endd2));
    ck_assert_uint_eq(ushortt1,ushortt6);
    ck_assert_int_eq(ushortt1,ushortt6);
    ck_assert_uint_eq(ushortt2,ushortt7);
    ck_assert_int_eq(ushortt2,ushortt7);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_unsigned_short_17){
    char input_line_0[]="   9223                    55555 end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned short ushortt1=1,ushortt2=2,ushortt6=1,ushortt7=2;
    ck_assert_int_eq(sscanf(input_line_0,"%5hu%hu%s",&ushortt1,&ushortt2, endd1),s21_sscanf(input_line_1,"%5hu%hu%s",&ushortt6,&ushortt7,endd2));
    ck_assert_uint_eq(ushortt1,ushortt6);
    ck_assert_int_eq(ushortt1,ushortt6);
    ck_assert_uint_eq(ushortt2,ushortt7);
    ck_assert_int_eq(ushortt2,ushortt7);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_unsigned_short_18){
    char input_line_0[]="   +923a567                    55555 end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned short ushortt1=1,ushortt2=2,ushortt6=1,ushortt7=2;
    ck_assert_int_eq(sscanf(input_line_0,"%5hu%hu%s",&ushortt1,&ushortt2, endd1),s21_sscanf(input_line_1,"%5hu%hu%s",&ushortt6,&ushortt7,endd2));
    ck_assert_uint_eq(ushortt1,ushortt6);
    ck_assert_int_eq(ushortt1,ushortt6);
    ck_assert_uint_eq(ushortt2,ushortt7);
    ck_assert_int_eq(ushortt2,ushortt7);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_unsigned_short_30){
    char input_line_0[]="   +923a567                    55555 end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned short ushortt1=1,ushortt2=2,ushortt6=1,ushortt7=2;
    ck_assert_int_eq(sscanf(input_line_0,"%4hu\t\na%hu%s",&ushortt1,&ushortt2, endd1),s21_sscanf(input_line_1,"%4hu\t\na%hu%s",&ushortt6,&ushortt7,endd2));
    ck_assert_uint_eq(ushortt1,ushortt6);
    ck_assert_int_eq(ushortt1,ushortt6);
    ck_assert_uint_eq(ushortt2,ushortt7);
    ck_assert_int_eq(ushortt2,ushortt7);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_unsigned_short_19){
    char input_line_0[]="   9223a567                    55555 end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned short ushortt1=1,ushortt2=2,ushortt6=1,ushortt7=2;
    ck_assert_int_eq(sscanf(input_line_0,"%8hu%hu%s",&ushortt1,&ushortt2, endd1),s21_sscanf(input_line_1,"%8hu%hu%s",&ushortt6,&ushortt7,endd2));
    ck_assert_uint_eq(ushortt1,ushortt6);
    ck_assert_int_eq(ushortt1,ushortt6);
    ck_assert_uint_eq(ushortt2,ushortt7);
    ck_assert_int_eq(ushortt2,ushortt7);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_unsigned_short_20){
    char input_line_0[]="  -.6                   -0.6 end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned short ushortt1=1,ushortt2=2,ushortt6=1,ushortt7=2;
    ck_assert_int_eq(sscanf(input_line_0,"%5hu%hu%s",&ushortt1,&ushortt2, endd1),s21_sscanf(input_line_1,"%5hu%hu%s",&ushortt6,&ushortt7,endd2));
    ck_assert_uint_eq(ushortt1,ushortt6);
    ck_assert_int_eq(ushortt1,ushortt6);
    ck_assert_uint_eq(ushortt2,ushortt7);
    ck_assert_int_eq(ushortt2,ushortt7);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_unsigned_short_21){
    char input_line_0[]="  .6                   -0.6 end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned short ushortt1=1,ushortt2=2,ushortt6=1,ushortt7=2;
    ck_assert_int_eq(sscanf(input_line_0,"%5hu%hu%s",&ushortt1, &ushortt2, endd1),s21_sscanf(input_line_1,"%5hu%hu%s",&ushortt6,&ushortt7,endd2));
    ck_assert_uint_eq(ushortt1,ushortt6);
    ck_assert_int_eq(ushortt1,ushortt6);
    ck_assert_uint_eq(ushortt2,ushortt7);
    ck_assert_int_eq(ushortt2,ushortt7);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_unsigned_short_22){
    char input_line_0[]="  -f                   -0.6 end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned short ushortt1=1,ushortt2=2,ushortt6=1,ushortt7=2;
    ck_assert_int_eq(sscanf(input_line_0,"%5hu%hu%s",&ushortt1,&ushortt2, endd1),s21_sscanf(input_line_1,"%5hu%hu%s",&ushortt6,&ushortt7,endd2));
    ck_assert_uint_eq(ushortt1,ushortt6);
    ck_assert_int_eq(ushortt1,ushortt6);
    ck_assert_uint_eq(ushortt2,ushortt7);
    ck_assert_int_eq(ushortt2,ushortt7);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_unsigned_short_23){
    char input_line_0[]="  42945                  -4294967304 end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned short ushortt1=1,ushortt2=2,ushortt6=1,ushortt7=2;
    ck_assert_int_eq(sscanf(input_line_0,"%6hu%6hu%s",&ushortt1,&ushortt2, endd1),s21_sscanf(input_line_1,"%6hu%6hu%s",&ushortt6,&ushortt7,endd2));
    ck_assert_uint_eq(ushortt1,ushortt6);
    ck_assert_int_eq(ushortt1,ushortt6);
    ck_assert_uint_eq(ushortt2,ushortt7);
    ck_assert_int_eq(ushortt2,ushortt7);
    ck_assert_str_eq(endd1,endd2);
}
/*
//werror
START_TEST(test_sscanf_unsigned_short_4){
    char input_line_0[]="11111  11223344556677889900111222333444555  -55555  5555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned short ushortt1=1,ushortt2=2,ushortt3=3,ushortt4=4,ushortt6=1,ushortt7=2,ushortt8=3,ushortt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%h5u%hu%hu%hu%s",&ushortt1,&ushortt2,&ushortt3,&ushortt4, endd1),s21_sscanf(input_line_1,"%h5u%hu%hu%hu%s",&ushortt6,&ushortt7,&ushortt8,&ushortt9, endd2));
    ck_assert_uint_eq(ushortt1,ushortt6);
    ck_assert_int_eq(ushortt1,ushortt6);
    ck_assert_uint_eq(ushortt2,ushortt7);
    ck_assert_int_eq(ushortt2,ushortt7);
    ck_assert_uint_eq(ushortt3,ushortt8);
    ck_assert_int_eq(ushortt3,ushortt8);
    ck_assert_uint_eq(ushortt4,ushortt9);
    ck_assert_int_eq(ushortt4,ushortt9);
    ck_assert_str_eq(endd1,endd2);
} 
*/
//9.4 //elevator
START_TEST(test_sscanf_short_1){
    char input_line_0[]="11111  11223344556677889900111222333444555  -5555  555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    short shortt1=1,shortt2=2,shortt3=3,shortt4=4,shortt6=1,shortt7=2,shortt8=3,shortt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%hd%hd%hd%hd%s",&shortt1,&shortt2,&shortt3,&shortt4, endd1),s21_sscanf(input_line_1,"%hd%hd%hd%hd%s",&shortt6,&shortt7,&shortt8,&shortt9, endd2));
    ck_assert_int_eq(shortt1,shortt6);
    ck_assert_int_eq(shortt2,shortt7);
    ck_assert_int_eq(shortt3,shortt8);
    ck_assert_int_eq(shortt4,shortt9);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_short_2){
    char input_line_0[]="11111  11223344556677889900111222333444555  -5555  555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    short shortt1=1,shortt2=2,shortt3=3,shortt4=4,shortt6=1,shortt7=2,shortt8=3,shortt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%hd%%%hd%hd%hd%s",&shortt1,&shortt2,&shortt3,&shortt4, endd1),s21_sscanf(input_line_1,"%hd%%%hd%hd%hd%s",&shortt6,&shortt7,&shortt8,&shortt9, endd2));
    ck_assert_int_eq(shortt1,shortt6);
    ck_assert_int_eq(shortt2,shortt7);
    ck_assert_int_eq(shortt3,shortt8);
    ck_assert_int_eq(shortt4,shortt9);
    ck_assert_str_eq(endd1,endd2);
}    
START_TEST(test_sscanf_short_7){
    char input_line_0[]="11111  %\n\n11223344556677889900111222333444555  -5555  555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    short shortt1=1,shortt2=2,shortt3=3,shortt4=4,shortt6=1,shortt7=2,shortt8=3,shortt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%hd%%%hd%hd%hd%s",&shortt1,&shortt2,&shortt3,&shortt4, endd1),s21_sscanf(input_line_1,"%hd%%%hd%hd%hd%s",&shortt6,&shortt7,&shortt8,&shortt9, endd2));
    ck_assert_int_eq(shortt1,shortt6);
    ck_assert_int_eq(shortt2,shortt7);
    ck_assert_int_eq(shortt3,shortt8);
    ck_assert_int_eq(shortt4,shortt9);
    ck_assert_str_eq(endd1,endd2);
}  
START_TEST(test_sscanf_short_3){
    char input_line_0[]="11111  11223344556677889900111222333444555  -5555  555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    short shortt1=1,shortt2=2,shortt3=3,shortt4=4,shortt6=1,shortt7=2,shortt8=3,shortt9=4,shortt5=5,shortt10=5;
    ck_assert_int_eq(sscanf(input_line_0,"%hd%7hd%hd%hd%hd%s",&shortt1,&shortt2,&shortt5, &shortt3,&shortt4, endd1),s21_sscanf(input_line_1,"%hd%7hd%hd%hd%hd%s",&shortt6,&shortt7,&shortt10,&shortt8,&shortt9, endd2));
    ck_assert_int_eq(shortt1,shortt6);
    ck_assert_int_eq(shortt2,shortt7);
    ck_assert_int_eq(shortt3,shortt8);
    ck_assert_int_eq(shortt4,shortt9);
    ck_assert_int_eq(shortt5,shortt10);
    ck_assert_str_eq(endd1,endd2);
}  
START_TEST(test_sscanf_short_5){
    char input_line_0[]="11111  11223344556677889900111222333444555  -5555  555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    short shortt1=1,shortt2=2,shortt3=3,shortt6=1,shortt7=2,shortt8=3;
    ck_assert_int_eq(sscanf(input_line_0,"%hd%*d%hd%hd%s",&shortt1,&shortt2,&shortt3, endd1),s21_sscanf(input_line_1,"%hd%*d%hd%hd%s",&shortt6,&shortt7,&shortt8, endd2));
    ck_assert_int_eq(shortt1,shortt6);
    ck_assert_int_eq(shortt2,shortt7);
    ck_assert_int_eq(shortt3,shortt8);
    ck_assert_str_eq(endd1,endd2);
}   
START_TEST(test_sscanf_short_6){
    char input_line_0[]="11111  11223344556677889900111222333444555  -5555  555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    short shortt1=1,shortt2=2,shortt3=3,shortt4=4,shortt6=1,shortt7=2,shortt8=3,shortt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%hd%*30d%hd%hd%hd%s",&shortt1,&shortt2,&shortt3,&shortt4, endd1),s21_sscanf(input_line_1,"%hd%*30d%hd%hd%hd%s",&shortt6,&shortt7,&shortt8,&shortt9, endd2));
    ck_assert_int_eq(shortt1,shortt6);
    ck_assert_int_eq(shortt2,shortt7);
    ck_assert_int_eq(shortt3,shortt8);
    ck_assert_int_eq(shortt4,shortt9);
    ck_assert_str_eq(endd1,endd2);
}     
START_TEST(test_sscanf_short_8){
    char input_line_0[]="11111  11223344556677889900111222333444555  -5555  555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    short shortt1=1,shortt2=2,shortt3=3,shortt4=4,shortt6=1,shortt7=2,shortt8=3,shortt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%hd%*25d%hd%hd%hd%s",&shortt1,&shortt2,&shortt3,&shortt4, endd1),s21_sscanf(input_line_1,"%hd%*25d%hd%hd%hd%s",&shortt6,&shortt7,&shortt8,&shortt9, endd2));
    ck_assert_int_eq(shortt1,shortt6);
    ck_assert_int_eq(shortt2,shortt7);
    ck_assert_int_eq(shortt3,shortt8);
    ck_assert_int_eq(shortt4,shortt9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_short_9){
    char input_line_0[]="65534  11223344556677889900111222333444555  -5555  555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    short shortt1=1,shortt2=2,shortt3=3,shortt4=4,shortt6=1,shortt7=2,shortt8=3,shortt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%hd%*31d\n\n%hd%hd%hd%s",&shortt1,&shortt2,&shortt3,&shortt4, endd1),s21_sscanf(input_line_1,"%hd%*31d\n\n%hd%hd%hd%s",&shortt6,&shortt7,&shortt8,&shortt9, endd2));
    ck_assert_int_eq(shortt1,shortt6);
    ck_assert_int_eq(shortt2,shortt7);
    ck_assert_int_eq(shortt3,shortt8);
    ck_assert_int_eq(shortt4,shortt9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_short_24){
    char input_line_0[]="-65534  11223344556677889900111222333444555  -5555  555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    short shortt1=1,shortt2=2,shortt3=3,shortt4=4,shortt6=1,shortt7=2,shortt8=3,shortt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%hd%*31d\n\n%hd%hd%hd%s",&shortt1,&shortt2,&shortt3,&shortt4, endd1),s21_sscanf(input_line_1,"%hd%*31d\n\n%hd%hd%hd%s",&shortt6,&shortt7,&shortt8,&shortt9, endd2));
    ck_assert_int_eq(shortt1,shortt6);
    ck_assert_int_eq(shortt2,shortt7);
    ck_assert_int_eq(shortt3,shortt8);
    ck_assert_int_eq(shortt4,shortt9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_short_25){
    char input_line_0[]="32767  11223344556677889900111222333444555  -5555  555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    short shortt1=1,shortt2=2,shortt3=3,shortt4=4,shortt6=1,shortt7=2,shortt8=3,shortt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%hd%*31d\n\n%hd%hd%hd%s",&shortt1,&shortt2,&shortt3,&shortt4, endd1),s21_sscanf(input_line_1,"%hd%*31d\n\n%hd%hd%hd%s",&shortt6,&shortt7,&shortt8,&shortt9, endd2));
    ck_assert_int_eq(shortt1,shortt6);
    ck_assert_int_eq(shortt2,shortt7);
    ck_assert_int_eq(shortt3,shortt8);
    ck_assert_int_eq(shortt4,shortt9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_short_26){
    char input_line_0[]="-32767  11223344556677889900111222333444555  -5555  555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    short shortt1=1,shortt2=2,shortt3=3,shortt4=4,shortt6=1,shortt7=2,shortt8=3,shortt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%hd%*31d\n\n%hd%hd%hd%s",&shortt1,&shortt2,&shortt3,&shortt4, endd1),s21_sscanf(input_line_1,"%hd%*31d\n\n%hd%hd%hd%s",&shortt6,&shortt7,&shortt8,&shortt9, endd2));
    ck_assert_int_eq(shortt1,shortt6);
    ck_assert_int_eq(shortt2,shortt7);
    ck_assert_int_eq(shortt3,shortt8);
    ck_assert_int_eq(shortt4,shortt9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_short_27){
    char input_line_0[]="32770  11223344556677889900111222333444555  -5555  555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    short shortt1=1,shortt2=2,shortt3=3,shortt4=4,shortt6=1,shortt7=2,shortt8=3,shortt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%hd%*31d\n\n%hd%hd%hd%s",&shortt1,&shortt2,&shortt3,&shortt4, endd1),s21_sscanf(input_line_1,"%hd%*31d\n\n%hd%hd%hd%s",&shortt6,&shortt7,&shortt8,&shortt9, endd2));
    ck_assert_int_eq(shortt1,shortt6);
    ck_assert_int_eq(shortt2,shortt7);
    ck_assert_int_eq(shortt3,shortt8);
    ck_assert_int_eq(shortt4,shortt9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_short_28){
    char input_line_0[]="65535   11223344556677889900111222333444555  -5555  555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    short shortt1=1,shortt2=2,shortt3=3,shortt4=4,shortt6=1,shortt7=2,shortt8=3,shortt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%hd%*31d\n\n%hd%hd%hd%s",&shortt1,&shortt2,&shortt3,&shortt4, endd1),s21_sscanf(input_line_1,"%hd%*31d\n\n%hd%hd%hd%s",&shortt6,&shortt7,&shortt8,&shortt9, endd2));
    ck_assert_int_eq(shortt1,shortt6);
    ck_assert_int_eq(shortt2,shortt7);
    ck_assert_int_eq(shortt3,shortt8);
    ck_assert_int_eq(shortt4,shortt9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_short_29){
    char input_line_0[]="-65536   11223344556677889900111222333444555  -5555  555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    short shortt1=1,shortt2=2,shortt3=3,shortt4=4,shortt6=1,shortt7=2,shortt8=3,shortt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%hd%*31d\n\n%hd%hd%hd%s",&shortt1,&shortt2,&shortt3,&shortt4, endd1),s21_sscanf(input_line_1,"%hd%*31d\n\n%hd%hd%hd%s",&shortt6,&shortt7,&shortt8,&shortt9, endd2));
    ck_assert_int_eq(shortt1,shortt6);
    ck_assert_int_eq(shortt2,shortt7);
    ck_assert_int_eq(shortt3,shortt8);
    ck_assert_int_eq(shortt4,shortt9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_short_10){
    char input_line_0[]="65536  11223344556677889900111222333444555  -5555  5555.444   end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    short shortt1=1,shortt2=2,shortt3=3,shortt4=4,shortt6=1,shortt7=2,shortt8=3,shortt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%hd%*31d\n\n%hd%hd%hd%s",&shortt1,&shortt2,&shortt3,&shortt4, endd1),s21_sscanf(input_line_1,"%hd%*31d\n\n%hd%hd%hd%s",&shortt6,&shortt7,&shortt8,&shortt9, endd2));
    ck_assert_int_eq(shortt1,shortt6);
    ck_assert_int_eq(shortt2,shortt7);
    ck_assert_int_eq(shortt3,shortt8);
    ck_assert_int_eq(shortt4,shortt9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_short_11){
    char input_line_0[]="0  11223344556677889900111222333444555  -5555  5555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    short shortt1=1,shortt2=2,shortt3=3,shortt4=4,shortt6=1,shortt7=2,shortt8=3,shortt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%hd%*31d%hd%hd%hd%s",&shortt1,&shortt2,&shortt3,&shortt4, endd1),s21_sscanf(input_line_1,"%hd%*31d%hd%hd%hd%s",&shortt6,&shortt7,&shortt8,&shortt9, endd2));
    ck_assert_int_eq(shortt1,shortt6);
    ck_assert_int_eq(shortt2,shortt7);
    ck_assert_int_eq(shortt3,shortt8);
    ck_assert_int_eq(shortt4,shortt9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_short_12){
    char input_line_0[]="  05.5  11223344556677889900111222333444555  -5555  5555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    short shortt1=1,shortt2=2,shortt3=3,shortt4=4,shortt6=1,shortt7=2,shortt8=3,shortt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%hd%*31d%hd\t\t%hd%hd%s",&shortt1,&shortt2,&shortt3,&shortt4, endd1),s21_sscanf(input_line_1,"%hd%*31d%hd\t\t%hd%hd%s",&shortt6,&shortt7,&shortt8,&shortt9, endd2));
    ck_assert_int_eq(shortt1,shortt6);
    ck_assert_int_eq(shortt2,shortt7);
    ck_assert_int_eq(shortt3,shortt8);
    ck_assert_int_eq(shortt4,shortt9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_short_13){
    char input_line_0[]="9223372036854775807  11223344556677889900111222333444555  -5555  5555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    short shortt1=1,shortt2=2,shortt3=3,shortt4=4,shortt6=1,shortt7=2,shortt8=3,shortt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%hd%*31d%hd%hd%hd%s",&shortt1,&shortt2,&shortt3,&shortt4, endd1),s21_sscanf(input_line_1,"%hd%*31d%hd%hd%hd%s",&shortt6,&shortt7,&shortt8,&shortt9, endd2));
    ck_assert_int_eq(shortt1,shortt6);
    ck_assert_int_eq(shortt2,shortt7);
    ck_assert_int_eq(shortt3,shortt8);
    ck_assert_int_eq(shortt4,shortt9);
    ck_assert_str_eq(endd1,endd2);
} 

START_TEST(test_sscanf_short_14){
    char input_line_0[]="5 -9999999999999999  11223344556677889900111222333444555  -5555  5555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    short shortt1=1,shortt2=2,shortt3=3,shortt4=4,shortt6=1,shortt7=2,shortt8=3,shortt9=4, shortt5=5, shortt10=5;
    ck_assert_int_eq(sscanf(input_line_0,"%hd%hd%*31d%hd%hd%hd%s",&shortt5,&shortt1,&shortt2,&shortt3,&shortt4, endd1),s21_sscanf(input_line_1,"%hd%hd%*31d%hd%hd%hd%s",&shortt10,&shortt6,&shortt7,&shortt8,&shortt9, endd2));
    ck_assert_int_eq(shortt5,shortt10);
    ck_assert_int_eq(shortt1,shortt6);
    ck_assert_int_eq(shortt2,shortt7);
    ck_assert_int_eq(shortt3,shortt8);
    ck_assert_int_eq(shortt4,shortt9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_short_15){
    char input_line_0[]="99999999999999999  11223344556677889900111222333444555  -5555  5555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    short shortt1=1,shortt2=2,shortt3=3,shortt4=4,shortt6=1,shortt7=2,shortt8=3,shortt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%hd%*31d%hd%hd%hd%s",&shortt1,&shortt2,&shortt3,&shortt4, endd1),s21_sscanf(input_line_1,"%hd%*31d%hd%hd%hd%s",&shortt6,&shortt7,&shortt8,&shortt9, endd2));
    ck_assert_int_eq(shortt1,shortt6);
    ck_assert_int_eq(shortt2,shortt7);
    ck_assert_int_eq(shortt3,shortt8);
    ck_assert_int_eq(shortt4,shortt9);
    ck_assert_str_eq(endd1,endd2);
} 

START_TEST(test_sscanf_short_31){
    char input_line_0[]="5 -1000000000000000  11223344556677889900111222333444555  -5555  5555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    short shortt1=1,shortt2=2,shortt3=3,shortt4=4,shortt6=1,shortt7=2,shortt8=3,shortt9=4, shortt5=5, shortt10=5;
    ck_assert_int_eq(sscanf(input_line_0,"%hd%hd%*31d%hd%hd%hd%s",&shortt5,&shortt1,&shortt2,&shortt3,&shortt4, endd1),s21_sscanf(input_line_1,"%hd%hd%*31d%hd%hd%hd%s",&shortt10,&shortt6,&shortt7,&shortt8,&shortt9, endd2));
    ck_assert_int_eq(shortt5,shortt10);
    ck_assert_int_eq(shortt1,shortt6);
    ck_assert_int_eq(shortt2,shortt7);
    ck_assert_int_eq(shortt3,shortt8);
    ck_assert_int_eq(shortt4,shortt9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_short_32){
    char input_line_0[]="100000000000000000  11223344556677889900111222333444555  -5555  5555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    short shortt1=1,shortt2=2,shortt3=3,shortt4=4,shortt6=1,shortt7=2,shortt8=3,shortt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%hd%*31d%hd%hd%hd%s",&shortt1,&shortt2,&shortt3,&shortt4, endd1),s21_sscanf(input_line_1,"%hd%*31d%hd%hd%hd%s",&shortt6,&shortt7,&shortt8,&shortt9, endd2));
    ck_assert_int_eq(shortt1,shortt6);
    ck_assert_int_eq(shortt2,shortt7);
    ck_assert_int_eq(shortt3,shortt8);
    ck_assert_int_eq(shortt4,shortt9);
    ck_assert_str_eq(endd1,endd2);
} 

START_TEST(test_sscanf_short_16){
    char input_line_0[]="   922337203685 5555 end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    short shortt1=1,shortt2=2,shortt6=1,shortt7=2;
    ck_assert_int_eq(sscanf(input_line_0,"%4hd%hd%s",&shortt1,&shortt2, endd1),s21_sscanf(input_line_1,"%4hd%hd%s",&shortt6,&shortt7,endd2));
    ck_assert_int_eq(shortt1,shortt6);
    ck_assert_int_eq(shortt2,shortt7);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_short_17){
    char input_line_0[]="   9223                    5555 end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    short shortt1=1,shortt2=2,shortt6=1,shortt7=2;
    ck_assert_int_eq(sscanf(input_line_0,"%5hd%hd%s",&shortt1,&shortt2, endd1),s21_sscanf(input_line_1,"%5hd%hd%s",&shortt6,&shortt7,endd2));
    ck_assert_int_eq(shortt1,shortt6);
    ck_assert_int_eq(shortt2,shortt7);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_short_18){
    char input_line_0[]="   +923a567                    5555 end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    short shortt1=1,shortt2=2,shortt6=1,shortt7=2;
    ck_assert_int_eq(sscanf(input_line_0,"%5hd%hd%s",&shortt1,&shortt2, endd1),s21_sscanf(input_line_1,"%5hd%hd%s",&shortt6,&shortt7,endd2));
    ck_assert_int_eq(shortt1,shortt6);
    ck_assert_int_eq(shortt2,shortt7);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_short_30){
    char input_line_0[]="   +923a567                    5555 end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    short shortt1=1,shortt2=2,shortt6=1,shortt7=2;
    ck_assert_int_eq(sscanf(input_line_0,"%4hd\t\na%hd%s",&shortt1,&shortt2, endd1),s21_sscanf(input_line_1,"%4hd\t\na%hd%s",&shortt6,&shortt7,endd2));
    ck_assert_int_eq(shortt1,shortt6);
    ck_assert_int_eq(shortt2,shortt7);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_short_19){
    char input_line_0[]="   9223a567                    5555 end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    short shortt1=1,shortt2=2,shortt6=1,shortt7=2;
    ck_assert_int_eq(sscanf(input_line_0,"%8hd%hd%s",&shortt1,&shortt2, endd1),s21_sscanf(input_line_1,"%8hd%hd%s",&shortt6,&shortt7,endd2));
    ck_assert_int_eq(shortt1,shortt6);
    ck_assert_int_eq(shortt2,shortt7);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_short_20){
    char input_line_0[]="  -.6                   -0.6 end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    short shortt1=1,shortt2=2,shortt6=1,shortt7=2;
    ck_assert_int_eq(sscanf(input_line_0,"%5hd%hd%s",&shortt1,&shortt2, endd1),s21_sscanf(input_line_1,"%5hd%hd%s",&shortt6,&shortt7,endd2));
    ck_assert_int_eq(shortt1,shortt6);
    ck_assert_int_eq(shortt2,shortt7);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_short_21){
    char input_line_0[]="  .6                   -0.6 end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    short shortt1=1,shortt2=2,shortt6=1,shortt7=2;
    ck_assert_int_eq(sscanf(input_line_0,"%5hd%hd%s",&shortt1, &shortt2, endd1),s21_sscanf(input_line_1,"%5hd%hd%s",&shortt6,&shortt7,endd2));
    ck_assert_int_eq(shortt1,shortt6);
    ck_assert_int_eq(shortt2,shortt7);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_short_22){
    char input_line_0[]="  -f                   -0.6 end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    short shortt1=1,shortt2=2,shortt6=1,shortt7=2;
    ck_assert_int_eq(sscanf(input_line_0,"%5hd%hd%s",&shortt1,&shortt2, endd1),s21_sscanf(input_line_1,"%5hd%hd%s",&shortt6,&shortt7,endd2));
    ck_assert_int_eq(shortt1,shortt6);
    ck_assert_int_eq(shortt2,shortt7);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_short_23){
    char input_line_0[]="  -4294                  -4294967304 end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    short shortt1=1,shortt2=2,shortt6=1,shortt7=2;
    ck_assert_int_eq(sscanf(input_line_0,"%6hd%6hd%s",&shortt1,&shortt2, endd1),s21_sscanf(input_line_1,"%6hd%6hd%s",&shortt6,&shortt7,endd2));
    //printf("%d\n",shortt6);
    ck_assert_int_eq(shortt1,shortt6);
    ck_assert_int_eq(shortt2,shortt7);
    ck_assert_str_eq(endd1,endd2);
}
/*
//werror
START_TEST(test_sscanf_short_4){
    char input_line_0[]="11111  11223344556677889900111222333444555  -5555  5555.444  end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    short shortt1=1,shortt2=2,shortt3=3,shortt4=4,shortt6=1,shortt7=2,shortt8=3,shortt9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%h5d%hd%hd%hd%s",&shortt1,&shortt2,&shortt3,&shortt4, endd1),s21_sscanf(input_line_1,"%h5d%hd%hd%hd%s",&shortt6,&shortt7,&shortt8,&shortt9, endd2));
    ck_assert_int_eq(shortt1,shortt6);
    ck_assert_int_eq(shortt2,shortt7);
    ck_assert_int_eq(shortt3,shortt8);
    ck_assert_int_eq(shortt4,shortt9);
    ck_assert_str_eq(endd1,endd2);
} 
*/
//9.5   //elevator
START_TEST(test_sscanf_unsigned_long_1){
    char input_line_0[]="1111155  11223344556677889900111222333444555  -555555  55545.444  end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned long ulongg1=1,ulongg2=2,ulongg3=3,ulongg4=4,ulongg6=1,ulongg7=2,ulongg8=3,ulongg9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%lu%lu%lu%lu%s",&ulongg1,&ulongg2,&ulongg3,&ulongg4, endd1),s21_sscanf(input_line_1,"%lu%lu%lu%lu%s",&ulongg6,&ulongg7,&ulongg8,&ulongg9, endd2));
    ck_assert_uint_eq(ulongg1,ulongg6);
    ck_assert_int_eq(ulongg1,ulongg6);
    ck_assert_uint_eq(ulongg2,ulongg7);
    ck_assert_int_eq(ulongg2,ulongg7);
    ck_assert_uint_eq(ulongg3,ulongg8);
    ck_assert_int_eq(ulongg3,ulongg8);
    ck_assert_uint_eq(ulongg4,ulongg9);
    ck_assert_int_eq(ulongg4,ulongg9);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_unsigned_long_2){
    char input_line_0[]="1111155  11223344556677889900111222333444555  -555555  55545.444  end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned long ulongg1=1,ulongg2=2,ulongg3=3,ulongg4=4,ulongg6=1,ulongg7=2,ulongg8=3,ulongg9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%lu%%%lu%lu%lu%s",&ulongg1,&ulongg2,&ulongg3,&ulongg4, endd1),s21_sscanf(input_line_1,"%lu%%%lu%lu%lu%s",&ulongg6,&ulongg7,&ulongg8,&ulongg9, endd2));
    ck_assert_uint_eq(ulongg1,ulongg6);
    ck_assert_int_eq(ulongg1,ulongg6);
    ck_assert_uint_eq(ulongg2,ulongg7);
    ck_assert_int_eq(ulongg2,ulongg7);
    ck_assert_uint_eq(ulongg3,ulongg8);
    ck_assert_int_eq(ulongg3,ulongg8);
    ck_assert_uint_eq(ulongg4,ulongg9);
    ck_assert_int_eq(ulongg4,ulongg9);
    ck_assert_str_eq(endd1,endd2);
}    
START_TEST(test_sscanf_unsigned_long_7){
    char input_line_0[]="1111155  %11223344556677889900111222333444555  -555555  55545.444  end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned long ulongg1=1,ulongg2=2,ulongg3=3,ulongg4=4,ulongg6=1,ulongg7=2,ulongg8=3,ulongg9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%lu%%%lu%lu%lu%s",&ulongg1,&ulongg2,&ulongg3,&ulongg4, endd1),s21_sscanf(input_line_1,"%lu%%%lu%lu%lu%s",&ulongg6,&ulongg7,&ulongg8,&ulongg9, endd2));
    ck_assert_uint_eq(ulongg1,ulongg6);
    ck_assert_int_eq(ulongg1,ulongg6);
    ck_assert_uint_eq(ulongg2,ulongg7);
    ck_assert_int_eq(ulongg2,ulongg7);
    ck_assert_uint_eq(ulongg3,ulongg8);
    ck_assert_int_eq(ulongg3,ulongg8);
    ck_assert_uint_eq(ulongg4,ulongg9);
    ck_assert_int_eq(ulongg4,ulongg9);
    ck_assert_str_eq(endd1,endd2);
}  
START_TEST(test_sscanf_unsigned_long_3){
    char input_line_0[]="1111155  11223344556677889900111222333444555  -555555  55545.444  end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned long ulongg1=1,ulongg2=2,ulongg3=3,ulongg4=4,ulongg6=1,ulongg7=2,ulongg8=3,ulongg9=4,ulongg5=5,ulongg10=5;
    ck_assert_int_eq(sscanf(input_line_0,"%lu%7lu%lu%lu%lu%s",&ulongg1,&ulongg2,&ulongg5, &ulongg3,&ulongg4, endd1),s21_sscanf(input_line_1,"%lu%7lu%lu%lu%lu%s",&ulongg6,&ulongg7,&ulongg10,&ulongg8,&ulongg9, endd2));
    ck_assert_uint_eq(ulongg1,ulongg6);
    ck_assert_int_eq(ulongg1,ulongg6);
    ck_assert_uint_eq(ulongg2,ulongg7);
    ck_assert_int_eq(ulongg2,ulongg7);
    ck_assert_uint_eq(ulongg3,ulongg8);
    ck_assert_int_eq(ulongg3,ulongg8);
    ck_assert_uint_eq(ulongg4,ulongg9);
    ck_assert_int_eq(ulongg4,ulongg9);
    ck_assert_uint_eq(ulongg5,ulongg10);
    ck_assert_int_eq(ulongg5,ulongg10);
    ck_assert_str_eq(endd1,endd2);
}  
START_TEST(test_sscanf_unsigned_long_5){
    char input_line_0[]="1111155  11223344556677889900111222333444555  -555555  55545.444  end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned long ulongg1=1,ulongg2=2,ulongg3=3,ulongg6=1,ulongg7=2,ulongg8=3;
    ck_assert_int_eq(sscanf(input_line_0,"%lu%*u%lu%lu%s",&ulongg1,&ulongg2,&ulongg3, endd1),s21_sscanf(input_line_1,"%lu%*u%lu%lu%s",&ulongg6,&ulongg7,&ulongg8, endd2));
    ck_assert_uint_eq(ulongg1,ulongg6);
    ck_assert_int_eq(ulongg1,ulongg6);
    ck_assert_uint_eq(ulongg2,ulongg7);
    ck_assert_int_eq(ulongg2,ulongg7);
    ck_assert_uint_eq(ulongg3,ulongg8);
    ck_assert_int_eq(ulongg3,ulongg8);
    ck_assert_str_eq(endd1,endd2);
}   
START_TEST(test_sscanf_unsigned_long_6){
    char input_line_0[]="1111155  11223344556677889900111222333444555  -555555  55545.444  end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned long ulongg1=1,ulongg2=2,ulongg3=3,ulongg4=4,ulongg6=1,ulongg7=2,ulongg8=3,ulongg9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%lu%*16u%lu%lu%lu%s",&ulongg1,&ulongg2,&ulongg3,&ulongg4, endd1),s21_sscanf(input_line_1,"%lu%*16u%lu%lu%lu%s",&ulongg6,&ulongg7,&ulongg8,&ulongg9, endd2));
    ck_assert_uint_eq(ulongg1,ulongg6);
    ck_assert_int_eq(ulongg1,ulongg6);
    ck_assert_uint_eq(ulongg2,ulongg7);
    ck_assert_int_eq(ulongg2,ulongg7);
    ck_assert_uint_eq(ulongg3,ulongg8);
    ck_assert_int_eq(ulongg3,ulongg8);
    ck_assert_uint_eq(ulongg4,ulongg9);
    ck_assert_int_eq(ulongg4,ulongg9);
    ck_assert_str_eq(endd1,endd2);
}     
START_TEST(test_sscanf_unsigned_long_8){
    char input_line_0[]="1111155  11223344556677889900111222333444555  -532456755555  55545.444  end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned long ulongg1=1,ulongg2=2,ulongg3=3,ulongg4=4,ulongg6=1,ulongg7=2,ulongg8=3,ulongg9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%lu%*10u%lu%lu%lu%s",&ulongg1,&ulongg2,&ulongg3,&ulongg4, endd1),s21_sscanf(input_line_1,"%lu%*10u%lu%lu%lu%s",&ulongg6,&ulongg7,&ulongg8,&ulongg9, endd2));
    ck_assert_uint_eq(ulongg1,ulongg6);
    ck_assert_int_eq(ulongg1,ulongg6);
    ck_assert_uint_eq(ulongg2,ulongg7);
    ck_assert_int_eq(ulongg2,ulongg7);
    ck_assert_uint_eq(ulongg3,ulongg8);
    ck_assert_int_eq(ulongg3,ulongg8);
    ck_assert_uint_eq(ulongg4,ulongg9);
    ck_assert_int_eq(ulongg4,ulongg9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_unsigned_long_9){
    char input_line_0[]="2147483647   11223344556677889900111222333444555  -532456755555  55545.444  end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned long ulongg1=1,ulongg2=2,ulongg3=3,ulongg4=4,ulongg6=1,ulongg7=2,ulongg8=3,ulongg9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%lu%*17u\n\n%lu%lu%lu%s",&ulongg1,&ulongg2,&ulongg3,&ulongg4, endd1),s21_sscanf(input_line_1,"%lu%*17u\n\n%lu%lu%lu%s",&ulongg6,&ulongg7,&ulongg8,&ulongg9, endd2));
    ck_assert_uint_eq(ulongg1,ulongg6);
    ck_assert_int_eq(ulongg1,ulongg6);
    ck_assert_uint_eq(ulongg2,ulongg7);
    ck_assert_int_eq(ulongg2,ulongg7);
    ck_assert_uint_eq(ulongg3,ulongg8);
    ck_assert_int_eq(ulongg3,ulongg8);
    ck_assert_uint_eq(ulongg4,ulongg9);
    ck_assert_int_eq(ulongg4,ulongg9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_unsigned_long_24){
    char input_line_0[]="-2147483647   11223344556677889900111222333444555  -532456755555  55545.444  end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned long ulongg1=1,ulongg2=2,ulongg3=3,ulongg4=4,ulongg6=1,ulongg7=2,ulongg8=3,ulongg9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%lu%*17u\n\n%lu%lu%lu%s",&ulongg1,&ulongg2,&ulongg3,&ulongg4, endd1),s21_sscanf(input_line_1,"%lu%*17u\n\n%lu%lu%lu%s",&ulongg6,&ulongg7,&ulongg8,&ulongg9, endd2));
    ck_assert_uint_eq(ulongg1,ulongg6);
    ck_assert_int_eq(ulongg1,ulongg6);
    ck_assert_uint_eq(ulongg2,ulongg7);
    ck_assert_int_eq(ulongg2,ulongg7);
    ck_assert_uint_eq(ulongg3,ulongg8);
    ck_assert_int_eq(ulongg3,ulongg8);
    ck_assert_uint_eq(ulongg4,ulongg9);
    ck_assert_int_eq(ulongg4,ulongg9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_unsigned_long_25){
    char input_line_0[]="9223372036854775807   11223344556677889900111222333444555  -532456755555  55545.444  end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned long ulongg1=1,ulongg2=2,ulongg3=3,ulongg4=4,ulongg6=1,ulongg7=2,ulongg8=3,ulongg9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%lu%*17u\n\n%lu%lu%lu%s",&ulongg1,&ulongg2,&ulongg3,&ulongg4, endd1),s21_sscanf(input_line_1,"%lu%*17u\n\n%lu%lu%lu%s",&ulongg6,&ulongg7,&ulongg8,&ulongg9, endd2));
    ck_assert_uint_eq(ulongg1,ulongg6);
    ck_assert_int_eq(ulongg1,ulongg6);
    ck_assert_uint_eq(ulongg2,ulongg7);
    ck_assert_int_eq(ulongg2,ulongg7);
    ck_assert_uint_eq(ulongg3,ulongg8);
    ck_assert_int_eq(ulongg3,ulongg8);
    ck_assert_uint_eq(ulongg4,ulongg9);
    ck_assert_int_eq(ulongg4,ulongg9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_unsigned_long_26){
    char input_line_0[]="-9223372036854775807   11223344556677889900111222333444555  -532456755555  55545.444  end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned long ulongg1=1,ulongg2=2,ulongg3=3,ulongg4=4,ulongg6=1,ulongg7=2,ulongg8=3,ulongg9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%lu%*17u\n\n%lu%lu%lu%s",&ulongg1,&ulongg2,&ulongg3,&ulongg4, endd1),s21_sscanf(input_line_1,"%lu%*17u\n\n%lu%lu%lu%s",&ulongg6,&ulongg7,&ulongg8,&ulongg9, endd2));
    ck_assert_uint_eq(ulongg1,ulongg6);
    ck_assert_int_eq(ulongg1,ulongg6);
    ck_assert_uint_eq(ulongg2,ulongg7);
    ck_assert_int_eq(ulongg2,ulongg7);
    ck_assert_uint_eq(ulongg3,ulongg8);
    ck_assert_int_eq(ulongg3,ulongg8);
    ck_assert_uint_eq(ulongg4,ulongg9);
    ck_assert_int_eq(ulongg4,ulongg9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_unsigned_long_27){
    char input_line_0[]="9223372036854775999   11223344556677889900111222333444555  -532456755555  55545.444  end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned long ulongg1=1,ulongg2=2,ulongg3=3,ulongg4=4,ulongg6=1,ulongg7=2,ulongg8=3,ulongg9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%lu%*17u\n\n%lu%lu%lu%s",&ulongg1,&ulongg2,&ulongg3,&ulongg4, endd1),s21_sscanf(input_line_1,"%lu%*17u\n\n%lu%lu%lu%s",&ulongg6,&ulongg7,&ulongg8,&ulongg9, endd2));
    ck_assert_uint_eq(ulongg1,ulongg6);
    ck_assert_int_eq(ulongg1,ulongg6);
    ck_assert_uint_eq(ulongg2,ulongg7);
    ck_assert_int_eq(ulongg2,ulongg7);
    ck_assert_uint_eq(ulongg3,ulongg8);
    ck_assert_int_eq(ulongg3,ulongg8);
    ck_assert_uint_eq(ulongg4,ulongg9);
    ck_assert_int_eq(ulongg4,ulongg9);
    ck_assert_str_eq(endd1,endd2);
} 
/*
//too big, too small - strange stuff
START_TEST(test_sscanf_unsigned_long_10){
    char input_line_0[]="-18446744073709551615  11223344556677889900111222333444555  -55555  5555.444   end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned long ulongg1=1,ulongg2=2,ulongg3=3,ulongg4=4,ulongg6=1,ulongg7=2,ulongg8=3,ulongg9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%lu%*17u\n\n%lu%lu%lu%s",&ulongg1,&ulongg2,&ulongg3,&ulongg4, endd1),s21_sscanf(input_line_1,"%lu%*17u\n\n%lu%lu%lu%s",&ulongg6,&ulongg7,&ulongg8,&ulongg9, endd2));
    //printf(">>%d==%d<<\n",sscanf(input_line_0,"%lu%*17lu\n\n%lu%lu%lu%s",&ulongg1,&ulongg2,&ulongg3,&ulongg4, endd1),s21_sscanf(input_line_1,"%lu%*17lu\n\n%lu%lu%lu%s",&ulongg6,&ulongg7,&ulongg8,&ulongg9, endd2));
    ck_assert_uint_eq(ulongg1,ulongg6);
    ck_assert_int_eq(ulongg1,ulongg6);
    ck_assert_uint_eq(ulongg2,ulongg7);
    ck_assert_int_eq(ulongg2,ulongg7);
    ck_assert_uint_eq(ulongg3,ulongg8);
    ck_assert_int_eq(ulongg3,ulongg8);
    ck_assert_uint_eq(ulongg4,ulongg9);
    ck_assert_int_eq(ulongg4,ulongg9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_unsigned_long_28){
    char input_line_0[]="-9223375036854775999    11223344556677889900111222333444555  -532456755555  55545.444  end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    printf("\t\t\t\tSEparator\n");
    unsigned long ulongg1=1,ulongg2=2,ulongg3=3,ulongg4=4,ulongg6=1,ulongg7=2,ulongg8=3,ulongg9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%lu%*17u\n\n%lu%lu%lu%s",&ulongg1,&ulongg2,&ulongg3,&ulongg4, endd1),s21_sscanf(input_line_1,"%lu%*17u\n\n%lu%lu%lu%s",&ulongg6,&ulongg7,&ulongg8,&ulongg9, endd2));
    ck_assert_uint_eq(ulongg1,ulongg6);
    ck_assert_int_eq(ulongg1,ulongg6);
    ck_assert_uint_eq(ulongg2,ulongg7);
    ck_assert_int_eq(ulongg2,ulongg7);
    ck_assert_uint_eq(ulongg3,ulongg8);
    ck_assert_int_eq(ulongg3,ulongg8);
    ck_assert_uint_eq(ulongg4,ulongg9);
    ck_assert_int_eq(ulongg4,ulongg9);
    ck_assert_str_eq(endd1,endd2);
} 
*/
START_TEST(test_sscanf_unsigned_long_29){
    char input_line_0[]="18446744073709551615   11223344556677889900111222333444555  -532456755555  55545.444  end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned long ulongg1=1,ulongg2=2,ulongg3=3,ulongg4=4,ulongg6=1,ulongg7=2,ulongg8=3,ulongg9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%lu%*17u\n\n%lu%lu%lu%s",&ulongg1,&ulongg2,&ulongg3,&ulongg4, endd1),s21_sscanf(input_line_1,"%lu%*17u\n\n%lu%lu%lu%s",&ulongg6,&ulongg7,&ulongg8,&ulongg9, endd2));
    ck_assert_uint_eq(ulongg1,ulongg6);
    ck_assert_int_eq(ulongg1,ulongg6);
    ck_assert_uint_eq(ulongg2,ulongg7);
    ck_assert_int_eq(ulongg2,ulongg7);
    ck_assert_uint_eq(ulongg3,ulongg8);
    ck_assert_int_eq(ulongg3,ulongg8);
    ck_assert_uint_eq(ulongg4,ulongg9);
    ck_assert_int_eq(ulongg4,ulongg9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_unsigned_long_11){
    char input_line_0[]="0   11223344556677889900111222333444555  -532456755555  55545.444  end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned long ulongg1=1,ulongg2=2,ulongg3=3,ulongg4=4,ulongg6=1,ulongg7=2,ulongg8=3,ulongg9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%lu%*17u%lu%lu%lu%s",&ulongg1,&ulongg2,&ulongg3,&ulongg4, endd1),s21_sscanf(input_line_1,"%lu%*17u%lu%lu%lu%s",&ulongg6,&ulongg7,&ulongg8,&ulongg9, endd2));
    ck_assert_uint_eq(ulongg1,ulongg6);
    ck_assert_int_eq(ulongg1,ulongg6);
    ck_assert_uint_eq(ulongg2,ulongg7);
    ck_assert_int_eq(ulongg2,ulongg7);
    ck_assert_uint_eq(ulongg3,ulongg8);
    ck_assert_int_eq(ulongg3,ulongg8);
    ck_assert_uint_eq(ulongg4,ulongg9);
    ck_assert_int_eq(ulongg4,ulongg9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_unsigned_long_12){
    char input_line_0[]="  05.5   11223344556677889900111222333444555  -532456755555  55545.444  end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned long ulongg1=1,ulongg2=2,ulongg3=3,ulongg4=4,ulongg6=1,ulongg7=2,ulongg8=3,ulongg9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%lu%*17u%lu\t\t%lu%lu%s",&ulongg1,&ulongg2,&ulongg3,&ulongg4, endd1),s21_sscanf(input_line_1,"%lu%*17u%lu\t\t%lu%lu%s",&ulongg6,&ulongg7,&ulongg8,&ulongg9, endd2));
    ck_assert_uint_eq(ulongg1,ulongg6);
    ck_assert_int_eq(ulongg1,ulongg6);
    ck_assert_uint_eq(ulongg2,ulongg7);
    ck_assert_int_eq(ulongg2,ulongg7);
    ck_assert_uint_eq(ulongg3,ulongg8);
    ck_assert_int_eq(ulongg3,ulongg8);
    ck_assert_uint_eq(ulongg4,ulongg9);
    ck_assert_int_eq(ulongg4,ulongg9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_unsigned_long_13){
    char input_line_0[]="18446744073709551616   11223344556677889900111222333444555  -532456755555  55545.444  end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned long ulongg1=1,ulongg2=2,ulongg3=3,ulongg4=4,ulongg6=1,ulongg7=2,ulongg8=3,ulongg9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%lu%*17u%lu%lu%lu%s",&ulongg1,&ulongg2,&ulongg3,&ulongg4, endd1),s21_sscanf(input_line_1,"%lu%*17u%lu%lu%lu%s",&ulongg6,&ulongg7,&ulongg8,&ulongg9, endd2));
    ck_assert_uint_eq(ulongg1,ulongg6);
    ck_assert_int_eq(ulongg1,ulongg6);
    ck_assert_uint_eq(ulongg2,ulongg7);
    ck_assert_int_eq(ulongg2,ulongg7);
    ck_assert_uint_eq(ulongg3,ulongg8);
    ck_assert_int_eq(ulongg3,ulongg8);
    ck_assert_uint_eq(ulongg4,ulongg9);
    ck_assert_int_eq(ulongg4,ulongg9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_unsigned_long_33){
    char input_line_0[]="-18446744073709551616   11223344556677889900111222333444555  -532456755555  55545.444  end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned long ulongg1=1,ulongg2=2,ulongg3=3,ulongg4=4,ulongg6=1,ulongg7=2,ulongg8=3,ulongg9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%lu%*17u%lu%lu%lu%s",&ulongg1,&ulongg2,&ulongg3,&ulongg4, endd1),s21_sscanf(input_line_1,"%lu%*17u%lu%lu%lu%s",&ulongg6,&ulongg7,&ulongg8,&ulongg9, endd2));
    ck_assert_uint_eq(ulongg1,ulongg6);
    ck_assert_int_eq(ulongg1,ulongg6);
    ck_assert_uint_eq(ulongg2,ulongg7);
    ck_assert_int_eq(ulongg2,ulongg7);
    ck_assert_uint_eq(ulongg3,ulongg8);
    ck_assert_int_eq(ulongg3,ulongg8);
    ck_assert_uint_eq(ulongg4,ulongg9);
    ck_assert_int_eq(ulongg4,ulongg9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_unsigned_long_34){
    char input_line_0[]="-18446744073709551620   11223344556677889900111222333444555  -532456755555  55545.444  end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned long ulongg1=1,ulongg2=2,ulongg3=3,ulongg4=4,ulongg6=1,ulongg7=2,ulongg8=3,ulongg9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%lu%*17u%lu%lu%lu%s",&ulongg1,&ulongg2,&ulongg3,&ulongg4, endd1),s21_sscanf(input_line_1,"%lu%*17u%lu%lu%lu%s",&ulongg6,&ulongg7,&ulongg8,&ulongg9, endd2));
    ck_assert_uint_eq(ulongg1,ulongg6);
    ck_assert_int_eq(ulongg1,ulongg6);
    ck_assert_uint_eq(ulongg2,ulongg7);
    ck_assert_int_eq(ulongg2,ulongg7);
    ck_assert_uint_eq(ulongg3,ulongg8);
    ck_assert_int_eq(ulongg3,ulongg8);
    ck_assert_uint_eq(ulongg4,ulongg9);
    ck_assert_int_eq(ulongg4,ulongg9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_unsigned_long_14){
    char input_line_0[]="5 9999999999999999   11223344556677889900111222333444555  -532456755555  55545.444  end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned long ulongg1=1,ulongg2=2,ulongg3=3,ulongg4=4,ulongg6=1,ulongg7=2,ulongg8=3,ulongg9=4, ulongg5=5, ulongg10=5;
    ck_assert_int_eq(sscanf(input_line_0,"%lu%lu%*17u%lu%lu%lu%s",&ulongg5,&ulongg1,&ulongg2,&ulongg3,&ulongg4, endd1),s21_sscanf(input_line_1,"%lu%lu%*17u%lu%lu%lu%s",&ulongg10,&ulongg6,&ulongg7,&ulongg8,&ulongg9, endd2));
    //sscanf(input_line_0,"%lu%lu%*17lu%lu%lu%lu%s",&ulongg5,&ulongg1,&ulongg2,&ulongg3,&ulongg4, endd1);
    //s21_sscanf(input_line_1,"%lu%lu%*17lu%lu%lu%lu%s",&ulongg10,&ulongg6,&ulongg7,&ulongg8,&ulongg9, endd2);
    ck_assert_uint_eq(ulongg5,ulongg10);
    ck_assert_int_eq(ulongg5,ulongg10);
    ck_assert_uint_eq(ulongg1,ulongg6);
    ck_assert_int_eq(ulongg1,ulongg6);
    ck_assert_uint_eq(ulongg2,ulongg7);
    ck_assert_int_eq(ulongg2,ulongg7);
    ck_assert_uint_eq(ulongg3,ulongg8);
    ck_assert_int_eq(ulongg3,ulongg8);
    ck_assert_uint_eq(ulongg4,ulongg9);
    ck_assert_int_eq(ulongg4,ulongg9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_unsigned_long_15){
    char input_line_0[]="99999999999999999   11223344556677889900111222333444555  -532456755555  55545.444  end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned long ulongg1=1,ulongg2=2,ulongg3=3,ulongg4=4,ulongg6=1,ulongg7=2,ulongg8=3,ulongg9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%lu%*17u%lu%lu%lu%s",&ulongg1,&ulongg2,&ulongg3,&ulongg4, endd1),s21_sscanf(input_line_1,"%lu%*17u%lu%lu%lu%s",&ulongg6,&ulongg7,&ulongg8,&ulongg9, endd2));
    ck_assert_uint_eq(ulongg1,ulongg6);
    ck_assert_int_eq(ulongg1,ulongg6);
    ck_assert_uint_eq(ulongg2,ulongg7);
    ck_assert_int_eq(ulongg2,ulongg7);
    ck_assert_uint_eq(ulongg3,ulongg8);
    ck_assert_int_eq(ulongg3,ulongg8);
    ck_assert_uint_eq(ulongg4,ulongg9);
    ck_assert_int_eq(ulongg4,ulongg9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_unsigned_long_31){

    char input_line_0[]="5 -1000000000000000  11223344556677889900111222333444555  -532456755555  55545.444  end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned long ulongg1=1,ulongg2=2,ulongg3=3,ulongg4=4,ulongg6=1,ulongg7=2,ulongg8=3,ulongg9=4, ulongg5=5, ulongg10=5;
    ck_assert_int_eq(sscanf(input_line_0,"%lu%lu%*17u%lu%lu%lu%s",&ulongg5,&ulongg1,&ulongg2,&ulongg3,&ulongg4, endd1),s21_sscanf(input_line_1,"%lu%lu%*17u%lu%lu%lu%s",&ulongg10,&ulongg6,&ulongg7,&ulongg8,&ulongg9, endd2));
    ck_assert_uint_eq(ulongg5,ulongg10);
    ck_assert_int_eq(ulongg5,ulongg10);
    ck_assert_uint_eq(ulongg1,ulongg6);
    ck_assert_int_eq(ulongg1,ulongg6);
    ck_assert_uint_eq(ulongg2,ulongg7);
    ck_assert_int_eq(ulongg2,ulongg7);
    ck_assert_uint_eq(ulongg3,ulongg8);
    ck_assert_int_eq(ulongg3,ulongg8);
    ck_assert_uint_eq(ulongg4,ulongg9);
    ck_assert_int_eq(ulongg4,ulongg9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_unsigned_long_32){
    char input_line_0[]="100000000000000000   11223344556677889900111222333444555  -532456755555  55545.444  end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned long ulongg1=1,ulongg2=2,ulongg3=3,ulongg4=4,ulongg6=1,ulongg7=2,ulongg8=3,ulongg9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%lu%*17u%lu%lu%lu%s",&ulongg1,&ulongg2,&ulongg3,&ulongg4, endd1),s21_sscanf(input_line_1,"%lu%*17u%lu%lu%lu%s",&ulongg6,&ulongg7,&ulongg8,&ulongg9, endd2));
    ck_assert_uint_eq(ulongg1,ulongg6);
    ck_assert_int_eq(ulongg1,ulongg6);
    ck_assert_uint_eq(ulongg2,ulongg7);
    ck_assert_int_eq(ulongg2,ulongg7);
    ck_assert_uint_eq(ulongg3,ulongg8);
    ck_assert_int_eq(ulongg3,ulongg8);
    ck_assert_uint_eq(ulongg4,ulongg9);
    ck_assert_int_eq(ulongg4,ulongg9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_unsigned_long_16){
    char input_line_0[]="   922337203685 55555 end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned long ulongg1=1,ulongg2=2,ulongg6=1,ulongg7=2;
    ck_assert_int_eq(sscanf(input_line_0,"%4lu%lu%s",&ulongg1,&ulongg2, endd1),s21_sscanf(input_line_1,"%4lu%lu%s",&ulongg6,&ulongg7,endd2));
    ck_assert_uint_eq(ulongg1,ulongg6);
    ck_assert_int_eq(ulongg1,ulongg6);
    ck_assert_uint_eq(ulongg2,ulongg7);
    ck_assert_int_eq(ulongg2,ulongg7);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_unsigned_long_17){
    char input_line_0[]="   9223                    55555 end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned long ulongg1=1,ulongg2=2,ulongg6=1,ulongg7=2;
    ck_assert_int_eq(sscanf(input_line_0,"%5lu%lu%s",&ulongg1,&ulongg2, endd1),s21_sscanf(input_line_1,"%5lu%lu%s",&ulongg6,&ulongg7,endd2));
    ck_assert_uint_eq(ulongg1,ulongg6);
    ck_assert_int_eq(ulongg1,ulongg6);
    ck_assert_uint_eq(ulongg2,ulongg7);
    ck_assert_int_eq(ulongg2,ulongg7);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_unsigned_long_18){
    char input_line_0[]="   +923a567                    55555 end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned long ulongg1=1,ulongg2=2,ulongg6=1,ulongg7=2;
    ck_assert_int_eq(sscanf(input_line_0,"%5lu%lu%s",&ulongg1,&ulongg2, endd1),s21_sscanf(input_line_1,"%5lu%lu%s",&ulongg6,&ulongg7,endd2));
    ck_assert_uint_eq(ulongg1,ulongg6);
    ck_assert_int_eq(ulongg1,ulongg6);
    ck_assert_uint_eq(ulongg2,ulongg7);
    ck_assert_int_eq(ulongg2,ulongg7);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_unsigned_long_30){
    char input_line_0[]="   +923a567                    55555 end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned long ulongg1=1,ulongg2=2,ulongg6=1,ulongg7=2;
    ck_assert_int_eq(sscanf(input_line_0,"%4lu\t\na%lu%s",&ulongg1,&ulongg2, endd1),s21_sscanf(input_line_1,"%4lu\t\na%lu%s",&ulongg6,&ulongg7,endd2));
    ck_assert_uint_eq(ulongg1,ulongg6);
    ck_assert_int_eq(ulongg1,ulongg6);
    ck_assert_uint_eq(ulongg2,ulongg7);
    ck_assert_int_eq(ulongg2,ulongg7);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_unsigned_long_19){
    char input_line_0[]="   9223a567                    55555 end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned long ulongg1=1,ulongg2=2,ulongg6=1,ulongg7=2;
    ck_assert_int_eq(sscanf(input_line_0,"%8lu%lu%s",&ulongg1,&ulongg2, endd1),s21_sscanf(input_line_1,"%8lu%lu%s",&ulongg6,&ulongg7,endd2));
    ck_assert_uint_eq(ulongg1,ulongg6);
    ck_assert_int_eq(ulongg1,ulongg6);
    ck_assert_uint_eq(ulongg2,ulongg7);
    ck_assert_int_eq(ulongg2,ulongg7);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_unsigned_long_20){
    char input_line_0[]="  -.6                   -0.6 end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned long ulongg1=1,ulongg2=2,ulongg6=1,ulongg7=2;
    ck_assert_int_eq(sscanf(input_line_0,"%5lu%lu%s",&ulongg1,&ulongg2, endd1),s21_sscanf(input_line_1,"%5lu%lu%s",&ulongg6,&ulongg7,endd2));
    ck_assert_uint_eq(ulongg1,ulongg6);
    ck_assert_int_eq(ulongg1,ulongg6);
    ck_assert_uint_eq(ulongg2,ulongg7);
    ck_assert_int_eq(ulongg2,ulongg7);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_unsigned_long_21){
    char input_line_0[]="  .6                   -0.6 end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned long ulongg1=1,ulongg2=2,ulongg6=1,ulongg7=2;
    ck_assert_int_eq(sscanf(input_line_0,"%5lu%lu%s",&ulongg1, &ulongg2, endd1),s21_sscanf(input_line_1,"%5lu%lu%s",&ulongg6,&ulongg7,endd2));
    ck_assert_uint_eq(ulongg1,ulongg6);
    ck_assert_int_eq(ulongg1,ulongg6);
    ck_assert_uint_eq(ulongg2,ulongg7);
    ck_assert_int_eq(ulongg2,ulongg7);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_unsigned_long_22){
    char input_line_0[]="  -f                   -0.6 end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned long ulongg1=1,ulongg2=2,ulongg6=1,ulongg7=2;
    ck_assert_int_eq(sscanf(input_line_0,"%5lu%lu%s",&ulongg1,&ulongg2, endd1),s21_sscanf(input_line_1,"%5lu%lu%s",&ulongg6,&ulongg7,endd2));
    ck_assert_uint_eq(ulongg1,ulongg6);
    ck_assert_int_eq(ulongg1,ulongg6);
    ck_assert_uint_eq(ulongg2,ulongg7);
    ck_assert_int_eq(ulongg2,ulongg7);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_unsigned_long_23){
    char input_line_0[]="  42945                  -4294967304 end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned long ulongg1=1,ulongg2=2,ulongg6=1,ulongg7=2;
    ck_assert_int_eq(sscanf(input_line_0,"%6lu%6lu%s",&ulongg1,&ulongg2, endd1),s21_sscanf(input_line_1,"%6lu%6lu%s",&ulongg6,&ulongg7,endd2));
    ck_assert_uint_eq(ulongg1,ulongg6);
    ck_assert_int_eq(ulongg1,ulongg6);
    ck_assert_uint_eq(ulongg2,ulongg7);
    ck_assert_int_eq(ulongg2,ulongg7);
    ck_assert_str_eq(endd1,endd2);
}
/*
//werror
START_TEST(test_sscanf_unsigned_long_4){
    char input_line_0[]="11111  11223344556677889900111222333444555  -55555  5555.444  end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    unsigned long ulongg1=1,ulongg2=2,ulongg3=3,ulongg4=4,ulongg6=1,ulongg7=2,ulongg8=3,ulongg9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%h5u%lu%lu%lu%s",&ulongg1,&ulongg2,&ulongg3,&ulongg4, endd1),s21_sscanf(input_line_1,"%h5u%lu%lu%lu%s",&ulongg6,&ulongg7,&ulongg8,&ulongg9, endd2));
    ck_assert_uint_eq(ulongg1,ulongg6);
    ck_assert_int_eq(ulongg1,ulongg6);
    ck_assert_uint_eq(ulongg2,ulongg7);
    ck_assert_int_eq(ulongg2,ulongg7);
    ck_assert_uint_eq(ulongg3,ulongg8);
    ck_assert_int_eq(ulongg3,ulongg8);
    ck_assert_uint_eq(ulongg4,ulongg9);
    ck_assert_int_eq(ulongg4,ulongg9);
    ck_assert_str_eq(endd1,endd2);
} 
*/





//9.6   //elevator
START_TEST(test_sscanf_long_1){
    char input_line_0[]="1111155  11223344556677889900111222333444555  -555555  55545.444  end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    long longg1=1,longg2=2,longg3=3,longg4=4,longg6=1,longg7=2,longg8=3,longg9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%ld%ld%ld%ld%s",&longg1,&longg2,&longg3,&longg4, endd1),s21_sscanf(input_line_1,"%ld%ld%ld%ld%s",&longg6,&longg7,&longg8,&longg9, endd2));
    ck_assert_int_eq(longg1,longg6);
    ck_assert_int_eq(longg2,longg7);
    ck_assert_int_eq(longg3,longg8);
    ck_assert_int_eq(longg4,longg9);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_long_2){
    char input_line_0[]="1111155  11223344556677889900111222333444555  -555555  55545.444  end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    long longg1=1,longg2=2,longg3=3,longg4=4,longg6=1,longg7=2,longg8=3,longg9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%ld%%%ld%ld%ld%s",&longg1,&longg2,&longg3,&longg4, endd1),s21_sscanf(input_line_1,"%ld%%%ld%ld%ld%s",&longg6,&longg7,&longg8,&longg9, endd2));
    ck_assert_int_eq(longg1,longg6);
    ck_assert_int_eq(longg2,longg7);
    ck_assert_int_eq(longg3,longg8);
    ck_assert_int_eq(longg4,longg9);
    ck_assert_str_eq(endd1,endd2);
}    
START_TEST(test_sscanf_long_7){
    char input_line_0[]="1111155  %11223344556677889900111222333444555  -555555  55545.444  end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    long longg1=1,longg2=2,longg3=3,longg4=4,longg6=1,longg7=2,longg8=3,longg9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%ld%%%ld%ld%ld%s",&longg1,&longg2,&longg3,&longg4, endd1),s21_sscanf(input_line_1,"%ld%%%ld%ld%ld%s",&longg6,&longg7,&longg8,&longg9, endd2));
    ck_assert_int_eq(longg1,longg6);
    ck_assert_int_eq(longg2,longg7);
    ck_assert_int_eq(longg3,longg8);
    ck_assert_int_eq(longg4,longg9);
    ck_assert_str_eq(endd1,endd2);
}  
START_TEST(test_sscanf_long_3){
    char input_line_0[]="1111155  11223344556677889900111222333444555  -555555  55545.444  end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    long longg1=1,longg2=2,longg3=3,longg4=4,longg6=1,longg7=2,longg8=3,longg9=4,longg5=5,longg10=5;
    ck_assert_int_eq(sscanf(input_line_0,"%ld%7ld%ld%ld%ld%s",&longg1,&longg2,&longg5, &longg3,&longg4, endd1),s21_sscanf(input_line_1,"%ld%7ld%ld%ld%ld%s",&longg6,&longg7,&longg10,&longg8,&longg9, endd2));
    ck_assert_int_eq(longg1,longg6);
    ck_assert_int_eq(longg2,longg7);
    ck_assert_int_eq(longg3,longg8);
    ck_assert_int_eq(longg4,longg9);
    ck_assert_int_eq(longg5,longg10);
    ck_assert_str_eq(endd1,endd2);
}  
START_TEST(test_sscanf_long_5){
    char input_line_0[]="1111155  11223344556677889900111222333444555  -555555  55545.444  end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    long longg1=1,longg2=2,longg3=3,longg6=1,longg7=2,longg8=3;
    ck_assert_int_eq(sscanf(input_line_0,"%ld%*d%ld%ld%s",&longg1,&longg2,&longg3, endd1),s21_sscanf(input_line_1,"%ld%*d%ld%ld%s",&longg6,&longg7,&longg8, endd2));
    ck_assert_int_eq(longg1,longg6);
    ck_assert_int_eq(longg2,longg7);
    ck_assert_int_eq(longg3,longg8);
    ck_assert_str_eq(endd1,endd2);
}   
//too big, too small - strange stuff
START_TEST(test_sscanf_long_6){
    char input_line_0[]="1111155  11223344556677889900111222333444555  -555555  55545.444  end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    long longg1=1,longg2=2,longg3=3,longg4=4,longg6=1,longg7=2,longg8=3,longg9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%ld%*16d%ld%ld%ld%s",&longg1,&longg2,&longg3,&longg4, endd1),s21_sscanf(input_line_1,"%ld%*16d%ld%ld%ld%s",&longg6,&longg7,&longg8,&longg9, endd2));
    ck_assert_int_eq(longg1,longg6);
    ck_assert_int_eq(longg2,longg7);
    ck_assert_int_eq(longg3,longg8);
    ck_assert_int_eq(longg4,longg9);
    ck_assert_str_eq(endd1,endd2);
} 
/*  
//too big, too small - strange stuff
START_TEST(test_sscanf_long_10){
    char input_line_0[]="-18446744073709551615  11223344556677889900111222333444555  -55555  5555.444   end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    long longg1=1,longg2=2,longg3=3,longg4=4,longg6=1,longg7=2,longg8=3,longg9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%ld%*17d\n\n%ld%ld%ld%s",&longg1,&longg2,&longg3,&longg4, endd1),s21_sscanf(input_line_1,"%ld%*17d\n\n%ld%ld%ld%s",&longg6,&longg7,&longg8,&longg9, endd2));
    //printf(">>%d==%d<<\n",sscanf(input_line_0,"%ld%*17ld\n\n%ld%ld%ld%s",&longg1,&longg2,&longg3,&longg4, endd1),s21_sscanf(input_line_1,"%ld%*17ld\n\n%ld%ld%ld%s",&longg6,&longg7,&longg8,&longg9, endd2));
    ck_assert_int_eq(longg1,longg6);
    ck_assert_int_eq(longg2,longg7);
    ck_assert_int_eq(longg3,longg8);
    ck_assert_int_eq(longg4,longg9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_long_26){
    char input_line_0[]="-9223372036854775807   11223344556677889900111222333444555  -532456755555  55545.444  end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    long longg1=1,longg2=2,longg3=3,longg4=4,longg6=1,longg7=2,longg8=3,longg9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%ld%*17d\n\n%ld%ld%ld%s",&longg1,&longg2,&longg3,&longg4, endd1),s21_sscanf(input_line_1,"%ld%*17d\n\n%ld%ld%ld%s",&longg6,&longg7,&longg8,&longg9, endd2));
    ck_assert_int_eq(longg1,longg6);
    ck_assert_int_eq(longg2,longg7);
    ck_assert_int_eq(longg3,longg8);
    ck_assert_int_eq(longg4,longg9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_long_28){
    char input_line_0[]="-9223375036854775999    11223344556677889900111222333444555  -532456755555  55545.444  end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    printf("\t\t\t\tSEparator\n");
    long longg1=1,longg2=2,longg3=3,longg4=4,longg6=1,longg7=2,longg8=3,longg9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%ld%*17d\n\n%ld%ld%ld%s",&longg1,&longg2,&longg3,&longg4, endd1),s21_sscanf(input_line_1,"%ld%*17d\n\n%ld%ld%ld%s",&longg6,&longg7,&longg8,&longg9, endd2));
    ck_assert_uint_eq(longg1,longg6);
    ck_assert_int_eq(longg1,longg6);
    ck_assert_int_eq(longg2,longg7);
    ck_assert_int_eq(longg3,longg8);
    ck_assert_int_eq(longg4,longg9);
    ck_assert_str_eq(endd1,endd2);
}  
START_TEST(test_sscanf_long_34){
    char input_line_0[]="-18446744073709551620   11223344556677889900111222333444555  -532456755555  55545.444  end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    long longg1=1,longg2=2,longg3=3,longg4=4,longg6=1,longg7=2,longg8=3,longg9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%ld%*17d%ld%ld%ld%s",&longg1,&longg2,&longg3,&longg4, endd1),s21_sscanf(input_line_1,"%ld%*17d%ld%ld%ld%s",&longg6,&longg7,&longg8,&longg9, endd2));
    ck_assert_int_eq(longg1,longg6);
    ck_assert_int_eq(longg2,longg7);
    ck_assert_int_eq(longg3,longg8);
    ck_assert_int_eq(longg4,longg9);
    ck_assert_str_eq(endd1,endd2);
} 
*/ 
START_TEST(test_sscanf_long_27){
    char input_line_0[]="9223372036854775999   11223344556677889900111222333444555  -532456755555  55545.444  end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    long longg1=1,longg2=2,longg3=3,longg4=4,longg6=1,longg7=2,longg8=3,longg9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%ld%*17d\n\n%ld%ld%ld%s",&longg1,&longg2,&longg3,&longg4, endd1),s21_sscanf(input_line_1,"%ld%*17d\n\n%ld%ld%ld%s",&longg6,&longg7,&longg8,&longg9, endd2));
    ck_assert_int_eq(longg1,longg6);
    ck_assert_int_eq(longg2,longg7);
    ck_assert_int_eq(longg3,longg8);
    ck_assert_int_eq(longg4,longg9);
    ck_assert_str_eq(endd1,endd2);
}     
START_TEST(test_sscanf_long_29){
    char input_line_0[]="18446744073709551615   11223344556677889900111222333444585  -532456755555  55545.444  end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    long longg1=1,longg2=2,longg3=3,longg4=4,longg6=1,longg7=2,longg8=3,longg9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%ld%*17d\n\n%ld%ld%ld%s",&longg1,&longg2,&longg3,&longg4, endd1),s21_sscanf(input_line_1,"%ld%*17d\n\n%ld%ld%ld%s",&longg6,&longg7,&longg8,&longg9, endd2));
    ck_assert_int_eq(longg1,longg6);
    ck_assert_int_eq(longg2,longg7);
    ck_assert_int_eq(longg3,longg8);
    ck_assert_int_eq(longg4,longg9);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_long_8){
    char input_line_0[]="1111155  11223344556677889900111222333444555  -532456755555  55545.444  end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    long longg1=1,longg2=2,longg3=3,longg4=4,longg6=1,longg7=2,longg8=3,longg9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%ld%*10d%ld%ld%ld%s",&longg1,&longg2,&longg3,&longg4, endd1),s21_sscanf(input_line_1,"%ld%*10d%ld%ld%ld%s",&longg6,&longg7,&longg8,&longg9, endd2));
    ck_assert_int_eq(longg1,longg6);
    ck_assert_int_eq(longg2,longg7);
    ck_assert_int_eq(longg3,longg8);
    ck_assert_int_eq(longg4,longg9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_long_9){
    char input_line_0[]="2147483647   11223344556677889900111222333444555  -532456755555  55545.444  end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    long longg1=1,longg2=2,longg3=3,longg4=4,longg6=1,longg7=2,longg8=3,longg9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%ld%*17d\n\n%ld%ld%ld%s",&longg1,&longg2,&longg3,&longg4, endd1),s21_sscanf(input_line_1,"%ld%*17d\n\n%ld%ld%ld%s",&longg6,&longg7,&longg8,&longg9, endd2));
    ck_assert_int_eq(longg1,longg6);
    ck_assert_int_eq(longg2,longg7);
    ck_assert_int_eq(longg3,longg8);
    ck_assert_int_eq(longg4,longg9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_long_24){
    char input_line_0[]="-2147483647   11223344556677889900111222333444555  -532456755555  55545.444  end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    long longg1=1,longg2=2,longg3=3,longg4=4,longg6=1,longg7=2,longg8=3,longg9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%ld%*17d\n\n%ld%ld%ld%s",&longg1,&longg2,&longg3,&longg4, endd1),s21_sscanf(input_line_1,"%ld%*17d\n\n%ld%ld%ld%s",&longg6,&longg7,&longg8,&longg9, endd2));
    ck_assert_int_eq(longg1,longg6);
    ck_assert_int_eq(longg2,longg7);
    ck_assert_int_eq(longg3,longg8);
    ck_assert_int_eq(longg4,longg9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_long_25){
    char input_line_0[]="9223372036854775807   11223344556677889900111222333444555  -532456755555  55545.444  end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    long longg1=1,longg2=2,longg3=3,longg4=4,longg6=1,longg7=2,longg8=3,longg9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%ld%*17d\n\n%ld%ld%ld%s",&longg1,&longg2,&longg3,&longg4, endd1),s21_sscanf(input_line_1,"%ld%*17d\n\n%ld%ld%ld%s",&longg6,&longg7,&longg8,&longg9, endd2));
    ck_assert_int_eq(longg1,longg6);
    ck_assert_int_eq(longg2,longg7);
    ck_assert_int_eq(longg3,longg8);
    ck_assert_int_eq(longg4,longg9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_long_11){
    char input_line_0[]="0   11223344556677889900111222333444555  -532456755555  55545.444  end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    long longg1=1,longg2=2,longg3=3,longg4=4,longg6=1,longg7=2,longg8=3,longg9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%ld%*17d%ld%ld%ld%s",&longg1,&longg2,&longg3,&longg4, endd1),s21_sscanf(input_line_1,"%ld%*17d%ld%ld%ld%s",&longg6,&longg7,&longg8,&longg9, endd2));
    ck_assert_int_eq(longg1,longg6);
    ck_assert_int_eq(longg2,longg7);
    ck_assert_int_eq(longg3,longg8);
    ck_assert_int_eq(longg4,longg9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_long_12){
    char input_line_0[]="  05.5   11223344556677889900111222333444555  -532456755555  55545.444  end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    long longg1=1,longg2=2,longg3=3,longg4=4,longg6=1,longg7=2,longg8=3,longg9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%ld%*17d%ld\t\t%ld%ld%s",&longg1,&longg2,&longg3,&longg4, endd1),s21_sscanf(input_line_1,"%ld%*17d%ld\t\t%ld%ld%s",&longg6,&longg7,&longg8,&longg9, endd2));
    ck_assert_int_eq(longg1,longg6);
    ck_assert_int_eq(longg2,longg7);
    ck_assert_int_eq(longg3,longg8);
    ck_assert_int_eq(longg4,longg9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_long_13){
    char input_line_0[]="9223372036854775806   11223344556677889900111222333444555  -532456755555  55545.444  end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    long longg1=1,longg2=2,longg3=3,longg4=4,longg6=1,longg7=2,longg8=3,longg9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%ld%*17d%ld%ld%ld%s",&longg1,&longg2,&longg3,&longg4, endd1),s21_sscanf(input_line_1,"%ld%*17d%ld%ld%ld%s",&longg6,&longg7,&longg8,&longg9, endd2));
    ck_assert_int_eq(longg1,longg6);
    ck_assert_int_eq(longg2,longg7);
    ck_assert_int_eq(longg3,longg8);
    ck_assert_int_eq(longg4,longg9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_long_33){
    char input_line_0[]="-9223372036854775806   11223344556677889900111222333444555  -532456755555  55545.444  end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    long longg1=1,longg2=2,longg3=3,longg4=4,longg6=1,longg7=2,longg8=3,longg9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%ld%*17d%ld%ld%ld%s",&longg1,&longg2,&longg3,&longg4, endd1),s21_sscanf(input_line_1,"%ld%*17d%ld%ld%ld%s",&longg6,&longg7,&longg8,&longg9, endd2));
    ck_assert_int_eq(longg1,longg6);
    ck_assert_int_eq(longg2,longg7);
    ck_assert_int_eq(longg3,longg8);
    ck_assert_int_eq(longg4,longg9);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_long_14){
    char input_line_0[]="5 9999999999999999   11223344556677889900111222333444555  -532456755555  55545.444  end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    long longg1=1,longg2=2,longg3=3,longg4=4,longg6=1,longg7=2,longg8=3,longg9=4, longg5=5, longg10=5;
    ck_assert_int_eq(sscanf(input_line_0,"%ld%ld%*17d%ld%ld%ld%s",&longg5,&longg1,&longg2,&longg3,&longg4, endd1),s21_sscanf(input_line_1,"%ld%ld%*17d%ld%ld%ld%s",&longg10,&longg6,&longg7,&longg8,&longg9, endd2));
    //sscanf(input_line_0,"%ld%ld%*17ld%ld%ld%ld%s",&longg5,&longg1,&longg2,&longg3,&longg4, endd1);
    //s21_sscanf(input_line_1,"%ld%ld%*17ld%ld%ld%ld%s",&longg10,&longg6,&longg7,&longg8,&longg9, endd2);
    ck_assert_int_eq(longg5,longg10);
    ck_assert_int_eq(longg1,longg6);
    ck_assert_int_eq(longg2,longg7);
    ck_assert_int_eq(longg3,longg8);
    ck_assert_int_eq(longg4,longg9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_long_15){
    char input_line_0[]="99999999999999999   11223344556677889900111222333444555  -532456755555  55545.444  end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    long longg1=1,longg2=2,longg3=3,longg4=4,longg6=1,longg7=2,longg8=3,longg9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%ld%*17d%ld%ld%ld%s",&longg1,&longg2,&longg3,&longg4, endd1),s21_sscanf(input_line_1,"%ld%*17d%ld%ld%ld%s",&longg6,&longg7,&longg8,&longg9, endd2));
    ck_assert_int_eq(longg1,longg6);
    ck_assert_int_eq(longg2,longg7);
    ck_assert_int_eq(longg3,longg8);
    ck_assert_int_eq(longg4,longg9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_long_31){

    char input_line_0[]="5 -1000000000000000  11223344556677889900111222333444555  -532456755555  55545.444  end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    long longg1=1,longg2=2,longg3=3,longg4=4,longg6=1,longg7=2,longg8=3,longg9=4, longg5=5, longg10=5;
    ck_assert_int_eq(sscanf(input_line_0,"%ld%ld%*17d%ld%ld%ld%s",&longg5,&longg1,&longg2,&longg3,&longg4, endd1),s21_sscanf(input_line_1,"%ld%ld%*17d%ld%ld%ld%s",&longg10,&longg6,&longg7,&longg8,&longg9, endd2));
    ck_assert_int_eq(longg5,longg10);
    ck_assert_int_eq(longg1,longg6);
    ck_assert_int_eq(longg2,longg7);
    ck_assert_int_eq(longg3,longg8);
    ck_assert_int_eq(longg4,longg9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_long_32){
    char input_line_0[]="100000000000000000   11223344556677889900111222333444555  -532456755555  55545.444  end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    long longg1=1,longg2=2,longg3=3,longg4=4,longg6=1,longg7=2,longg8=3,longg9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%ld%*17d%ld%ld%ld%s",&longg1,&longg2,&longg3,&longg4, endd1),s21_sscanf(input_line_1,"%ld%*17d%ld%ld%ld%s",&longg6,&longg7,&longg8,&longg9, endd2));
    ck_assert_int_eq(longg1,longg6);
    ck_assert_int_eq(longg2,longg7);
    ck_assert_int_eq(longg3,longg8);
    ck_assert_int_eq(longg4,longg9);
    ck_assert_str_eq(endd1,endd2);
} 
START_TEST(test_sscanf_long_16){
    char input_line_0[]="   922337203685 55555 end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    long longg1=1,longg2=2,longg6=1,longg7=2;
    ck_assert_int_eq(sscanf(input_line_0,"%4ld%ld%s",&longg1,&longg2, endd1),s21_sscanf(input_line_1,"%4ld%ld%s",&longg6,&longg7,endd2));
    ck_assert_int_eq(longg1,longg6);
    ck_assert_int_eq(longg2,longg7);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_long_17){
    char input_line_0[]="   9223                    55555 end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    long longg1=1,longg2=2,longg6=1,longg7=2;
    ck_assert_int_eq(sscanf(input_line_0,"%5ld%ld%s",&longg1,&longg2, endd1),s21_sscanf(input_line_1,"%5ld%ld%s",&longg6,&longg7,endd2));
    ck_assert_int_eq(longg1,longg6);
    ck_assert_int_eq(longg2,longg7);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_long_18){
    char input_line_0[]="   +923a567                    55555 end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    long longg1=1,longg2=2,longg6=1,longg7=2;
    ck_assert_int_eq(sscanf(input_line_0,"%5ld%ld%s",&longg1,&longg2, endd1),s21_sscanf(input_line_1,"%5ld%ld%s",&longg6,&longg7,endd2));
    ck_assert_int_eq(longg1,longg6);
    ck_assert_int_eq(longg2,longg7);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_long_30){
    char input_line_0[]="   +923a567                    55555 end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    long longg1=1,longg2=2,longg6=1,longg7=2;
    ck_assert_int_eq(sscanf(input_line_0,"%4ld\t\na%ld%s",&longg1,&longg2, endd1),s21_sscanf(input_line_1,"%4ld\t\na%ld%s",&longg6,&longg7,endd2));
    ck_assert_int_eq(longg1,longg6);
    ck_assert_int_eq(longg2,longg7);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_long_19){
    char input_line_0[]="   9223a567                    55555 end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    long longg1=1,longg2=2,longg6=1,longg7=2;
    ck_assert_int_eq(sscanf(input_line_0,"%8ld%ld%s",&longg1,&longg2, endd1),s21_sscanf(input_line_1,"%8ld%ld%s",&longg6,&longg7,endd2));
    ck_assert_int_eq(longg1,longg6);
    ck_assert_int_eq(longg2,longg7);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_long_20){
    char input_line_0[]="  -.6                   -0.6 end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    long longg1=1,longg2=2,longg6=1,longg7=2;
    ck_assert_int_eq(sscanf(input_line_0,"%5ld%ld%s",&longg1,&longg2, endd1),s21_sscanf(input_line_1,"%5ld%ld%s",&longg6,&longg7,endd2));
    ck_assert_int_eq(longg1,longg6);
    ck_assert_int_eq(longg2,longg7);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_long_21){
    char input_line_0[]="  .6                   -0.6 end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    long longg1=1,longg2=2,longg6=1,longg7=2;
    ck_assert_int_eq(sscanf(input_line_0,"%5ld%ld%s",&longg1, &longg2, endd1),s21_sscanf(input_line_1,"%5ld%ld%s",&longg6,&longg7,endd2));
    ck_assert_int_eq(longg1,longg6);
    ck_assert_int_eq(longg2,longg7);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_long_22){
    char input_line_0[]="  -f                   -0.6 end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    long longg1=1,longg2=2,longg6=1,longg7=2;
    ck_assert_int_eq(sscanf(input_line_0,"%5ld%ld%s",&longg1,&longg2, endd1),s21_sscanf(input_line_1,"%5ld%ld%s",&longg6,&longg7,endd2));
    ck_assert_int_eq(longg1,longg6);
    ck_assert_int_eq(longg2,longg7);
    ck_assert_str_eq(endd1,endd2);
}
START_TEST(test_sscanf_long_23){
    char input_line_0[]="  42945                  -4294967304 end\0";
    char input_line_1[70]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    long longg1=1,longg2=2,longg6=1,longg7=2;
    ck_assert_int_eq(sscanf(input_line_0,"%6ld%6ld%s",&longg1,&longg2, endd1),s21_sscanf(input_line_1,"%6ld%6ld%s",&longg6,&longg7,endd2));
    ck_assert_int_eq(longg1,longg6);
    ck_assert_int_eq(longg2,longg7);
    ck_assert_str_eq(endd1,endd2);
}
/*
//werror
START_TEST(test_sscanf_long_4){
    char input_line_0[]="11111  11223344556677889900111222333444555  -55555  5555.444  end\0";
    char input_line_1[100]="\0";
    strcpy(input_line_1,input_line_0);
    char endd1[6]="start\0",endd2[6]="start\0";
    long longg1=1,longg2=2,longg3=3,longg4=4,longg6=1,longg7=2,longg8=3,longg9=4;
    ck_assert_int_eq(sscanf(input_line_0,"%h5u%ld%ld%ld%s",&longg1,&longg2,&longg3,&longg4, endd1),s21_sscanf(input_line_1,"%h5u%ld%ld%ld%s",&longg6,&longg7,&longg8,&longg9, endd2));
    ck_assert_int_eq(longg1,longg6);
    ck_assert_int_eq(longg2,longg7);
    ck_assert_int_eq(longg3,longg8);
    ck_assert_int_eq(longg4,longg9);
    ck_assert_str_eq(endd1,endd2);
} 
*/
//9.7       //elevator


/*
START_TEST(test_sscanf_settings) {
    char line[]="num:001234567890 -  - \n\n -1235---hello -0X1f0Aa----0.54E3 010\n--\nfghjklqw erty uiop 0x7FFdd251f78c   %   hell 12345 -0X10A  \0";
    //char templine[]={'1',1,'2',2,'3',3,'4',4,'5',5,'6',6,'7',7,'8',8,'9',14,'0',15,'z',16,'x',17,'c',18,'v',19,'b',20,'n',21,'m',22,'a',23,'s',24,'d',25,'f',26,'g',27,'h',28,'j',29,'k',30,'l',31,'q',32,'w','e'};
    //s21_strncat(line,templine,56);
    unsigned int num1=5, num2=5, num5=0, num6=0;
    int num3=0, num4=0, num9=0, num10=0; 
    long int num11=0, num12=0; 
    float num7=0, num8=0;
    char sym1=0, sym2=0;
    char line1[100]={0,}, line2[100]={0}, line3[10]="0", line4[10]="0";
    char* p1=NULL, *p2=NULL;
    int n1=0, n2=0;d
    //const char line[3] = "%d";
    //char* line2 = (char*) line;

    // size_t num2, num5, num6;
    // float num3;
    // char str1[100];
    //sscanf(line,"%20d, %3ld, %*s%s%*s %5f%5d %99ld %5ld", &num1,&num2,str1, &num3,&num4, &num5,&num6);
    //printf("Result:%d-->%ld-->%s-->%f-->%d---->%ld-->%ld\n", num1,num2,str1,num3,num4,num5,num6);
    
    //printf("--%s\n\n",s21_strtok(line2,"%"));
    //printf("--%s\n", line2);
    //line2=s21_strtok(line2,"%");
    //printf("==%s\n",line2);
    printf(">%d -- ",s21_sscanf(line,"num:%u \n-\t-%d ---hello %x---%7G %o--%3c   %serty uiop %p%n %% %s %*d%li",&num1, &num3, &num5, &num8, &num9, &sym2, line1,  &p2, &n2, line4, &num12));
    printf("%p==%u\t%p==%d\t%d\t %f\t%d\t%c\t%s\t%p\t%d\t%s\t%ld<\n", &num1,num1, &num3,num3, num5,num8,num9,sym2, line1,p2,  n2, line4, num12);
    //printf("\n{\n%s\n}\n",line);
    printf(">%d -- ",sscanf(line,"num:%u \n-\t-%d ---hello%X---%7G %o --\t %3c %s erty uiop %p       %n %%   %s %*d %li",&num2, &num4, &num6, &num7, &num10,  &sym1, line2, &p1, &n1, line3,&num11));
    printf("%p==%u\t%p==%d\t%d\t %f\t%d\t%c\t%s\t%p\t%d\t%s\t%ld<\n", &num2,num2, &num4,num4, num6, num7,num10,sym1, line2, p1,n1, line3,num11);
        //printf("%d\n", num1);
}
*/

Suite *my_string_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("My_String");
    tc_core = tcase_create("Core");

    
    tcase_add_test(tc_core, test_settings);

    //s21_memcmp
	tcase_add_test(tc_core, test_memcmp);
	tcase_add_test(tc_core, test_memcmp_2);
	tcase_add_test(tc_core, test_memcmp_3);
	// tcase_add_test(tc_core, test_memcmp_4);
	// tcase_add_test(tc_core, test_memcmp_5);
	// tcase_add_test(tc_core, test_memcmp_6);

	//s21_strncmp
	tcase_add_test(tc_core, test_strncmp);
	tcase_add_test(tc_core, test_strncmp_2);
	tcase_add_test(tc_core, test_strncmp_3);
	tcase_add_test(tc_core, test_strncmp_4);
	tcase_add_test(tc_core, test_strncmp_5);
	tcase_add_test(tc_core, test_strncmp_6);

	//s21_memchr
	tcase_add_test(tc_core, test_memchr);
	tcase_add_test(tc_core, test_memchr_2);
	// tcase_add_test(tc_core, test_memchr_3);

	//s21_strchr
	tcase_add_test(tc_core, test_strchr);
	tcase_add_test(tc_core, test_strchr_2);
	tcase_add_test(tc_core, test_strchr_3);
	tcase_add_test(tc_core, test_strchr_4);

	//s21_strrchr
	tcase_add_test(tc_core, test_strrchr);
	tcase_add_test(tc_core, test_strrchr_2);
	tcase_add_test(tc_core, test_strrchr_3);
	tcase_add_test(tc_core, test_strrchr_4);

	//s21_strstr
	tcase_add_test(tc_core, test_strstr);
	tcase_add_test(tc_core, test_strstr_2);
	tcase_add_test(tc_core, test_strstr_3);
	tcase_add_test(tc_core, test_strstr_4);
	tcase_add_test(tc_core, test_strstr_5);
	tcase_add_test(tc_core, test_strstr_6);

    //S21_strlen  -->1.1-1.6
    tcase_add_test(tc_core, test_strlen_usual_1);
    tcase_add_test(tc_core, test_strlen_usual_2);
    tcase_add_test(tc_core, test_strlen_usual_3);
    tcase_add_test(tc_core, test_strlen_usual_4);
    tcase_add_test(tc_core, test_strlen_nullline);
    // tcase_add_test(tc_core, test_strlen_zeroline);
    // tcase_add_test(tc_core, test_strlen_zeronullline);
    // tcase_add_test(tc_core, test_strlen_absolutenullline);
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

    //s21_memset -->2.0-2.7
    tcase_add_test(tc_core, test_memset_pointertest);
    tcase_add_test(tc_core, test_memset_normal_1);
    tcase_add_test(tc_core, test_memset_normal_2);
    tcase_add_test(tc_core, test_memset_nullline);
    // tcase_add_test(tc_core, test_memset_zeroline);
    //tcase_add_test(tc_core, test_memset_absolutenullline); 
    tcase_add_test(tc_core, test_memset_numzero);
    // tcase_add_test(tc_core, test_memset_nummore_1);  
    // tcase_add_test(tc_core, test_memset_nummore_2);
    // tcase_add_test(tc_core, test_memset_nummore_3);
    // tcase_add_test(tc_core, test_memset_nummore_4);
    tcase_add_test(tc_core, test_memset_nummore_5);
    tcase_add_test(tc_core, test_memset_numsame);
    tcase_add_test(tc_core, test_memset_charenter);
    tcase_add_test(tc_core, test_memset_charspace);
    tcase_add_test(tc_core, test_memset_charnull);
    tcase_add_test(tc_core, test_memset_chartab);
    tcase_add_test(tc_core, test_memset_charinvis_1);
    tcase_add_test(tc_core, test_memset_charinvis_2);
    tcase_add_test(tc_core, test_memset_charinvis_3);
    //tcase_add_test(tc_core, test_memset_numerror);
    tcase_add_test(tc_core, test_memset_midline_1);
    tcase_add_test(tc_core, test_memset_midline_3);
    tcase_add_test(tc_core, test_memset_midline_2);
    tcase_add_test(tc_core, test_memset_midline_4);
    //tcase_add_test(tc_core, test_memset_long_1);
    tcase_add_test(tc_core, test_memset_long_2);
    tcase_add_test(tc_core, test_memset_long_3);
    tcase_add_test(tc_core, test_memset_long_4);

    //s21_memcpy  -->3.0-3.5
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
    //tcase_add_test(tc_core, test_memcpy_different_n_4);
    //tcase_add_test(tc_core, test_memcpy_different_n_5);
    //tcase_add_test(tc_core, test_memcpy_different_n_8);
    //tcase_add_test(tc_core, test_memcpy_different_n_9);  ---?
    tcase_add_test(tc_core, test_memcpy_different_n_6);
    tcase_add_test(tc_core, test_memcpy_different_n_7);
    tcase_add_test(tc_core, test_memcpy_nullline_1);
    tcase_add_test(tc_core, test_memcpy_nullline_2);
    tcase_add_test(tc_core, test_memcpy_long_1);
    tcase_add_test(tc_core, test_memcpy_long_2);
    tcase_add_test(tc_core, test_memcpy_long_3);
    tcase_add_test(tc_core, test_memcpy_long_4);

    //s21_strncpy -->4.0-4.5
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
    // tcase_add_test(tc_core, test_strncpy_different_n_4);
    // tcase_add_test(tc_core, test_strncpy_different_n_5);
    // tcase_add_test(tc_core, test_strncpy_different_n_8);
    // tcase_add_test(tc_core, test_strncpy_different_n_9);  ---?
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

    //s21_strncat -->5.0-5.5
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
    //tcase_add_test(tc_core, test_strncat_different_n_4);
    //tcase_add_test(tc_core, test_strncat_different_n_5);
    //tcase_add_test(tc_core, test_strncat_different_n_8);
    //tcase_add_test(tc_core, test_strncat_different_n_6);
    //tcase_add_test(tc_core, test_strncat_different_n_9);  ---?
    //tcase_add_test(tc_core, test_strncat_different_n_16);
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

    //s21_strcspn -->6.0-6.4
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
    //tcase_add_test(tc_core, test_strcspn_nullline_2);
    //tcase_add_test(tc_core, test_strcspn_nullline_4);
    tcase_add_test(tc_core, test_strcspn_nullline_3);
    tcase_add_test(tc_core, test_strcspn_long_1);
    tcase_add_test(tc_core, test_strcspn_long_2);
    tcase_add_test(tc_core, test_strcspn_long_3);
    tcase_add_test(tc_core, test_strcspn_long_4);
    tcase_add_test(tc_core, test_strcspn_long_5);
    tcase_add_test(tc_core, test_strcspn_long_6);
    tcase_add_test(tc_core, test_strcspn_long_7); //speed with big lines (spesially 2)??

    //s21_strpbrk -->7.0-7.4
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
    //tcase_add_test(tc_core, test_strpbrk_nullline_2);
    //tcase_add_test(tc_core, test_strpbrk_nullline_4);
    tcase_add_test(tc_core, test_strpbrk_nullline_3);
    tcase_add_test(tc_core, test_strpbrk_long_1);
    tcase_add_test(tc_core, test_strpbrk_long_2);
    tcase_add_test(tc_core, test_strpbrk_long_3);
    tcase_add_test(tc_core, test_strpbrk_long_4);
    tcase_add_test(tc_core, test_strpbrk_long_5);
    tcase_add_test(tc_core, test_strpbrk_long_6);
    tcase_add_test(tc_core, test_strpbrk_long_7); //speed with big lines (spesially 2)??

    //s21_strtok -->8.0-8.4
    tcase_add_test(tc_core, test_strtok_lineschange);       //does it change the line it self?!
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
    //tcase_add_test(tc_core, test_strtok_nullline_6);
    //tcase_add_test(tc_core, test_strtok_nullline_7);
    //tcase_add_test(tc_core, test_strtok_nullline_9);
    //tcase_add_test(tc_core, test_strtok_nullline_10);
    //tcase_add_test(tc_core, test_strtok_nullline_11);
    //tcase_add_test(tc_core, test_strtok_nullline_12);
    //tcase_add_test(tc_core, test_strtok_nullline_8);  //?
    tcase_add_test(tc_core, test_strtok_longline_1);
    tcase_add_test(tc_core, test_strtok_longline_2);
    //tcase_add_test(tc_core, test_strtok_longline_3);      //too much time!
    tcase_add_test(tc_core, test_strtok_longline_4);
    tcase_add_test(tc_core, test_strtok_longline_5);
    tcase_add_test(tc_core, test_strtok_longline_6);
    
    //s21_sscanf -->9.0-
    //tcase_add_test(tc_core, test_sscanf_settings);
    tcase_add_test(tc_core, test_sscanf_blanks);
    tcase_add_test(tc_core, test_sscanf_unsigned_1);             //too big numbers 
    tcase_add_test(tc_core, test_sscanf_unsigned_2);
    tcase_add_test(tc_core, test_sscanf_unsigned_3);             //too big numbers
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
    //tcase_add_test(tc_core, test_sscanf_unsigned_4);      //werror
    tcase_add_test(tc_core, test_sscanf_int_1);
    tcase_add_test(tc_core, test_sscanf_int_2);
    tcase_add_test(tc_core, test_sscanf_int_3);
    //tcase_add_test(tc_core, test_sscanf_int_4);           //werror
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
    //tcase_add_test(tc_core, test_sscanf_unsigned_short_4);           //werror
    tcase_add_test(tc_core, test_sscanf_unsigned_short_5);
    tcase_add_test(tc_core, test_sscanf_unsigned_short_6);
    tcase_add_test(tc_core, test_sscanf_unsigned_short_7);
    tcase_add_test(tc_core, test_sscanf_unsigned_short_8);
    tcase_add_test(tc_core, test_sscanf_unsigned_short_9);
    tcase_add_test(tc_core, test_sscanf_unsigned_short_10);
    tcase_add_test(tc_core, test_sscanf_unsigned_short_11);
    tcase_add_test(tc_core, test_sscanf_unsigned_short_12);
    tcase_add_test(tc_core, test_sscanf_unsigned_short_13);
    tcase_add_test(tc_core, test_sscanf_unsigned_short_14);         //strange stuff
    tcase_add_test(tc_core, test_sscanf_unsigned_short_15);         //strange stuff
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
    //tcase_add_test(tc_core, test_sscanf_short_4);           //werror
    tcase_add_test(tc_core, test_sscanf_short_5);
    tcase_add_test(tc_core, test_sscanf_short_6);
    tcase_add_test(tc_core, test_sscanf_short_7);
    tcase_add_test(tc_core, test_sscanf_short_8);
    tcase_add_test(tc_core, test_sscanf_short_9);
    tcase_add_test(tc_core, test_sscanf_short_10);
    tcase_add_test(tc_core, test_sscanf_short_11);
    tcase_add_test(tc_core, test_sscanf_short_12);
    tcase_add_test(tc_core, test_sscanf_short_13);
    tcase_add_test(tc_core, test_sscanf_short_14);
    tcase_add_test(tc_core, test_sscanf_short_15);
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
    //tcase_add_test(tc_core, test_sscanf_unsigned_long_4);           //werror
    tcase_add_test(tc_core, test_sscanf_unsigned_long_5);
    tcase_add_test(tc_core, test_sscanf_unsigned_long_6);
    tcase_add_test(tc_core, test_sscanf_unsigned_long_7);
    tcase_add_test(tc_core, test_sscanf_unsigned_long_8);
    tcase_add_test(tc_core, test_sscanf_unsigned_long_9);
    //tcase_add_test(tc_core, test_sscanf_unsigned_long_10);        //too big, too small - strange stuff
    //tcase_add_test(tc_core, test_sscanf_unsigned_long_28);        //too big, too small - strange stuff
    tcase_add_test(tc_core, test_sscanf_unsigned_long_11);
    tcase_add_test(tc_core, test_sscanf_unsigned_long_12);
    tcase_add_test(tc_core, test_sscanf_unsigned_long_13);
    tcase_add_test(tc_core, test_sscanf_unsigned_long_14);
    tcase_add_test(tc_core, test_sscanf_unsigned_long_15);
    tcase_add_test(tc_core, test_sscanf_unsigned_long_16);
    tcase_add_test(tc_core, test_sscanf_unsigned_long_17);
    tcase_add_test(tc_core, test_sscanf_unsigned_long_18);
    tcase_add_test(tc_core, test_sscanf_unsigned_long_19);
    tcase_add_test(tc_core, test_sscanf_unsigned_long_20);
    tcase_add_test(tc_core, test_sscanf_unsigned_long_22);
    tcase_add_test(tc_core, test_sscanf_unsigned_long_21);
    tcase_add_test(tc_core, test_sscanf_unsigned_long_23);
    tcase_add_test(tc_core, test_sscanf_unsigned_long_24);
    tcase_add_test(tc_core, test_sscanf_unsigned_long_25);
    tcase_add_test(tc_core, test_sscanf_unsigned_long_26);
    tcase_add_test(tc_core, test_sscanf_unsigned_long_27);
    tcase_add_test(tc_core, test_sscanf_unsigned_long_29);
    tcase_add_test(tc_core, test_sscanf_unsigned_long_30);
    tcase_add_test(tc_core, test_sscanf_unsigned_long_31);
    tcase_add_test(tc_core, test_sscanf_unsigned_long_32);
    tcase_add_test(tc_core, test_sscanf_unsigned_long_33);
    tcase_add_test(tc_core, test_sscanf_unsigned_long_34);
    tcase_add_test(tc_core, test_sscanf_long_1);
    tcase_add_test(tc_core, test_sscanf_long_2);
    tcase_add_test(tc_core, test_sscanf_long_3);
    //tcase_add_test(tc_core, test_sscanf_long_4);           //werror
    tcase_add_test(tc_core, test_sscanf_long_5);
    tcase_add_test(tc_core, test_sscanf_long_6);
    tcase_add_test(tc_core, test_sscanf_long_7);
    tcase_add_test(tc_core, test_sscanf_long_8);
    tcase_add_test(tc_core, test_sscanf_long_9);
    // tcase_add_test(tc_core, test_sscanf_long_10);        //too big, too small - strange stuff
    // tcase_add_test(tc_core, test_sscanf_long_26);        //too big, too small - strange stuff
    // tcase_add_test(tc_core, test_sscanf_long_28);        //too big, too small - strange stuff
    // tcase_add_test(tc_core, test_sscanf_long_34);        //too big, too small - strange stuff
    tcase_add_test(tc_core, test_sscanf_long_11);
    tcase_add_test(tc_core, test_sscanf_long_12);
    tcase_add_test(tc_core, test_sscanf_long_13);
    tcase_add_test(tc_core, test_sscanf_long_14);
    tcase_add_test(tc_core, test_sscanf_long_15);
    tcase_add_test(tc_core, test_sscanf_long_16);
    tcase_add_test(tc_core, test_sscanf_long_17);
    tcase_add_test(tc_core, test_sscanf_long_18);
    tcase_add_test(tc_core, test_sscanf_long_19);
    tcase_add_test(tc_core, test_sscanf_long_20);
    tcase_add_test(tc_core, test_sscanf_long_22);
    tcase_add_test(tc_core, test_sscanf_long_21);
    tcase_add_test(tc_core, test_sscanf_long_23);
    tcase_add_test(tc_core, test_sscanf_long_24);
    tcase_add_test(tc_core, test_sscanf_long_25);
    tcase_add_test(tc_core, test_sscanf_long_27);
    tcase_add_test(tc_core, test_sscanf_long_29);
    tcase_add_test(tc_core, test_sscanf_long_30);
    tcase_add_test(tc_core, test_sscanf_long_31);
    tcase_add_test(tc_core, test_sscanf_long_32);
    tcase_add_test(tc_core, test_sscanf_long_33);
    
    
//elevator
    suite_add_tcase(s, tc_core);
    return s;
}

int main(void) {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = my_string_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}