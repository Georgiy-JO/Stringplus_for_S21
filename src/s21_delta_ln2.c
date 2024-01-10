#include "s21_string.h"


//NOT CHECKED MANUALY!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//Calculates the length of the initial segment of str1 which consists entirely of characters not in str2.
size_t s21_strcspn(const char *str1, const char *str2){
    size_t delta;
    for(size_t i=0;*(str1+i)!=C_ZERO;i++){
        if(s21_isinstr(*(str1+i),str2))  
            break;
        else
            delta++;
    }
    return delta;
}
/*posible thin places:
    1)speed with big lines (spesially 2)
    2)NULL line
    3n=0
    4)\n
    5)\t
    6)other zero-chars
    7)wrong counting
*/


//checking if the CHAR is in STR
char s21_isinstr(const char a, const char* str){
    size_t length=s21_strlen(str);
    char flag=0;
    for(size_t i=0;i<length;i++){
        if(*(str+i)==a){
            flag=1;
            i=length;
        }
    }
    return flag;
}
/*ideas:
    can I make it smaller?
*/


//NOT CHECKED MANUALY!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//Finds the first character in the string str1 that matches any character specified in str2.
char *s21_strpbrk(const char *str1, const char *str2){
    char* founder=NULL;
    for(size_t i=0;*(str1+i)!=C_ZERO;i++){
        if(s21_isinstr(*(str1+i),str2)){
            founder=str1+i;
            break;
        }
    }
    return founder;
}
/*posible thin places:
    1)speed with big lines (spesially 2)
    2)NULL line
    3n=0
    4)\n
    5)\t
    6)other zero-chars
    7)wrong counting
    8)not found
    9)found first
    10)wring pointer setting
*/