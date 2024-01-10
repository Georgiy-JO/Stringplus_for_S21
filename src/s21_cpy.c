#include "s21_string.h"

//Copies n characters from src to dest.
void *s21_memcpy(void *dest, const void *src, size_t n){
    symbol* destination=dest;
    symbol* source=(void *)src;
    for(size_t i=0;i<n;i++){
        //*(pointer+(sizeof(char)*i))=*(char*)(src+(sizeof(char)*i));
        *(destination+i)=*(source+i);
    }
    //*(destination+n)=C_ZERO;
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
    9)check VOID type

*/

// char *s21_strncpy(char *dest, const char *src, size_t n){
//     for(size_t i=0;i<n;i++){
//         *(dest+i)=*(src+i);
//     }
//     size_t delta=0, len=0;
//     -


// }

// void padding(char* place, size_t length){

// }