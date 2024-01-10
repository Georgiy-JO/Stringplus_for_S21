#include "s21_string.h"

//Copies the character c (an unsigned char) to the first n characters of the string pointed to, by the argument str.
void *s21_memset(void *str, int c, size_t n){
    symbol* pointer=str;
    for(size_t i=0;i<n;i++){
        *(pointer+i)=c;
    }
    return str;
}
/*posible thin places:
    1)too long (longer than str)
    2)NULL line
    3)\n
    4)\t
    5)other zero-chars
*/