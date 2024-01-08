#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, size_t n){
    char* destination=dest;
    char* source=src;
    for(unsigned long i=0;i<n;i++){
        //*(pointer+(sizeof(char)*i))=*(char*)(src+(sizeof(char)*i));
        *(destination+i)=*(source+i);
    }
    *(destination+n)=NULL;
    return dest;
}

/*posible thin places:
    1)too long
    2)NULL line
    3n=0
    4)\n
    5)\t
    6)other zero-chars
    7)something neative
    8)memory allocation error

*/