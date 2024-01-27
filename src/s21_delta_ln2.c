#include "s21_string.h"

//Calculates the length of the initial segment of str1 which consists entirely of characters not in str2.
size_t s21_strcspn(const char *str1, const char *str2){
    size_t delta=0;
    for(size_t i=0;*(str1+i)!=C_ZERO;i++){
        if(s21_isinstr(*(str1+i),str2))  
            break;
        else
            delta++;
    }
    return delta;
}
//checking if the CHAR is in STR
/*
//v1
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
*/
char s21_isinstr(const char a, const char* str){
    char flag=0;
    for(size_t i=0;*(str+i)!='\0' && flag!=1;i++){
        if(*(str+i)==a)     flag=1;
    }
    return flag;
}
//Finds the first character in the string str1 that matches any character specified in str2.
char *s21_strpbrk(const char *str1, const char *str2){
    char* founder=MY_NULL;
    for(size_t i=0;*(str1+i)!=C_ZERO;i++){
        if(s21_isinstr(*(str1+i),str2)){
            founder=(char *)str1+i;
            break;
        }
    }
    return founder;
}
