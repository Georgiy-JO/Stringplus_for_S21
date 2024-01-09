#include "s21_string.h"

//Computes the length of the string str up to but not including the terminating null character.
size_t s21_strlen(const char *str){
    size_t length=0;
    for(;str[length]!=C_ZERO;length++);
    return length;
}

/*posible thin places:
    1)too long
    2)NULL line
    3)\n
    4)\t
    5)other zero-chars
*/