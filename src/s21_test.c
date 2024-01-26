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
    ck_assert_str_eq(strncat(line1,sourceline,len),s21_strncat(line2,sourceline,len));    
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

//--->probably the same because of size_t
START_TEST(test_strncat_different_n_9) {
    char line1[11] = FRIVE_CHAR_1;
    char line2[11] = FRIVE_CHAR_1;
    char sourceline[5] = FOUR_CHAR;
    size_t len = -3;
    void* p1=strncat(line1,sourceline,len);
    void* p2=strncat(line2,sourceline,len);
    printf("%s---%s\n",line1,line2);
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





























                                                                        // START_TEST(test_3_long_4) {
                                                                        //     char line1[LONG_CHECK_LINE] = NULL_LINE;
                                                                        //     char line2[LONG_CHECK_LINE] = NULL_LINE;
                                                                        //     rand_str(line1,LONG_CHECK_LINE-1);
                                                                        //     strcpy(line2,line1);
                                                                        //     char sourceline[LONG_CHECK_LINE] = NULL_LINE;
                                                                        //     int len = LONG_CHECK_LINE;
                                                                        //     void* p1=memcpy(line1,sourceline,len);
                                                                        //     void* p2=s21_memcpy(line2,sourceline,len);

                                                                        //     ck_assert_str_eq(p1,p2);
                                                                        //     ck_assert_str_eq(line1,line2);

                                                                        //     ck_assert_mem_eq(p1,p2,LONG_CHECK_LINE);
                                                                        //     ck_assert_mem_eq(line1,line2,LONG_CHECK_LINE);

                                                                        //     ck_assert_mem_eq(p1,p2,len);
                                                                        //     ck_assert_mem_eq(line1,line2,len);

                                                                        //     ck_assert_ptr_eq(line1,p1);
                                                                        //     ck_assert_ptr_eq(line2,p2); 
                                                                        // }




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
    //tcase_add_test(tc_core, test_memcpy_different_n_9);
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
    // tcase_add_test(tc_core, test_strncpy_different_n_9);
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
    tcase_add_test(tc_core, test_strncat_different_n_4);
    tcase_add_test(tc_core, test_strncat_different_n_5);
    tcase_add_test(tc_core, test_strncat_different_n_8);
    tcase_add_test(tc_core, test_strncat_different_n_9);
    tcase_add_test(tc_core, test_strncat_different_n_6);
    tcase_add_test(tc_core, test_strncat_different_n_13);
    tcase_add_test(tc_core, test_strncat_different_n_14);
    tcase_add_test(tc_core, test_strncat_different_n_15);
    tcase_add_test(tc_core, test_strncat_different_n_16);
    tcase_add_test(tc_core, test_strncat_different_n_11);
    tcase_add_test(tc_core, test_strncat_nullline_1);
    tcase_add_test(tc_core, test_strncat_nullline_2);
    tcase_add_test(tc_core, test_strncat_long_1);
    tcase_add_test(tc_core, test_strncat_long_2);
    tcase_add_test(tc_core, test_strncat_long_3);
    tcase_add_test(tc_core, test_strncat_long_4);
    tcase_add_test(tc_core, test_strncat_long_5);

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
