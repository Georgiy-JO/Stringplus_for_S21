#include <stdio.h>
#include <string.h>
#include "s21_string.h"
#include <check.h>
#include <stdlib.h>

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



//s21_strlen -->1.1-1.5 //!add test for 2000 symbols
//s21_memset -->2.0-2.6 //!add test for 2000 symbols
//s21_memcpy  -->3.1-3.
//s21_strncpy -->4.1-4.
//s21_strncat -->5.1-5.
//s21_strcspn -->6.1-6.
//s21_strpbrk -->7.1-7.
//s21_strtok -->8.1-8.

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
/* //(*6.1) Segmentation fault (core dumped)  -  both original and our strlen
START_TEST(test_memset_numerror) {
    char line1[6] = FRIVE_CHAR_1;
    char line2[6] = FRIVE_CHAR_1;
    char letter = 'g';
    int len = -3;
    void* p1=memset(line1,letter,len);
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

START_TEST(test_memchr_3) {
	char* str1 = "hello";
	int c = 'f';
	size_t n = 10;
	char* result = s21_memchr(str1, c, n);
	char* expected = memchr(str1, c, n);
	ck_assert_ptr_eq(result, expected);
}

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

Suite *my_string_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("My_String");
    tc_core = tcase_create("Core");

    //S21_strlen  -->1.1-1.5
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

    //s21_memset -->2.0-2.6
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

	//memcmp
	tcase_add_test(tc_core, test_memcmp);
	tcase_add_test(tc_core, test_memcmp_2);
	tcase_add_test(tc_core, test_memcmp_3);
	tcase_add_test(tc_core, test_memcmp_4);
	tcase_add_test(tc_core, test_memcmp_5);
	tcase_add_test(tc_core, test_memcmp_6);

	//strncmp
	tcase_add_test(tc_core, test_strncmp);
	tcase_add_test(tc_core, test_strncmp_2);
	tcase_add_test(tc_core, test_strncmp_3);
	tcase_add_test(tc_core, test_strncmp_4);
	tcase_add_test(tc_core, test_strncmp_5);
	tcase_add_test(tc_core, test_strncmp_6);

	//memchr
	tcase_add_test(tc_core, test_memchr);
	tcase_add_test(tc_core, test_memchr_2);
	tcase_add_test(tc_core, test_memchr_3);

	//strchr
	tcase_add_test(tc_core, test_strchr);
	tcase_add_test(tc_core, test_strchr_2);
	tcase_add_test(tc_core, test_strchr_3);
	tcase_add_test(tc_core, test_strchr_4);

	//strrchr
	tcase_add_test(tc_core, test_strrchr);
	tcase_add_test(tc_core, test_strrchr_2);
	tcase_add_test(tc_core, test_strrchr_3);
	tcase_add_test(tc_core, test_strrchr_4);

	//strstr
	tcase_add_test(tc_core, test_strstr);
	tcase_add_test(tc_core, test_strstr_2);
	tcase_add_test(tc_core, test_strstr_3);
	tcase_add_test(tc_core, test_strstr_4);
	tcase_add_test(tc_core, test_strstr_5);
	tcase_add_test(tc_core, test_strstr_6);

    //s21_memcpy  -->3.1-3.
    //s21_strncpy -->4.1-4.
    //s21_strncat -->5.1-5.
    //s21_strcspn -->6.1-6.
    //s21_strpbrk -->7.1-7.
    //s21_strtok -->8.1-8.

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
