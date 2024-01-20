#include "s21_string.h"


//NOT CHECKED MANUALY!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//Breaks string str into a series of tokens separated by delim.
char *s21_strtok(char *str, const char *delim){
    static char* point=MY_NULL;
    static size_t i=0;
    point = (str!=NULL)? str:point+i;  //MY_NULL
    // if(str!=NULL)
    //     point=str;
    // else
    //     point=point+i;
    for(i=0;*(point+i)!=C_ZERO;i++){
        if(s21_isinstr(*(point+i),delim)){
            *(point+i)=C_ZERO;
            i++;
            break;
        }
    }
    return point;
}
/*posible thin places:
    1)speed with big lines 
    2)NULL line
    3n=0
    4)\n
    5)\t
    6)other zero-chars
    7)wrong counting
    8)not found
    9)found first
    10)not all delims used
    11)not all tokens returned
    12)wrong work of static char
    13)when the delim is the last symbol
    14)Changing the original line?????
    15)severl delims
*/