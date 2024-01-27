#include "s21_string.h"

//Breaks string str into a series of tokens separated by delim.
char *s21_strtok(char *str, const char *delim){
    static char* point=MY_NULL;
    static size_t i=0;
    point = (str!=NULL)? str:point+i;  //MY_NULL

        for(i=0;*(point+i)!=C_ZERO;i++){
            if(s21_isinstr(*(point+i),delim)){
                *(point+i)=C_ZERO;
                if(i!=0){
                    i++;
                    break;
                }
                else{
                    point=point+1;
                    i=-1;
                }
            }
        }
        if(*point==C_ZERO)
            point=MY_NULL;
    
    return point;
}