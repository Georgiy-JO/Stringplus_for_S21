#include <stdio.h>
#include <string.h>
#include "s21_string.h"
#include <check.h>
#include <stdlib.h>
#include <time.h>

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

    //printf("%s--%s--%s\n", line1,line2,sourceline);

    int len = 3;
    void* p1=strncpy(line1,sourceline,len);
    void* p2=s21_strncpy(line2,sourceline,len);

    //printf("%s--%s--%s--%s\n", line1,line2,p1, p2);

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
/*
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

Suite *my_string_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("My_String");
    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_settings);
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
    tcase_add_test(tc_core, test_strtok_nullline_6);
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
