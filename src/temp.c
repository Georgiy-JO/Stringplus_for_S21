#include <stdio.h>
#include <stdlib.h>

#define size_t unsigned long int
#define MAX_32 4294967295
#define MAX_64 18446744073709551615

void randomizer(char *argv[], size_t n);            //I cerate very big file

int main (int argc, char *argv[]){
   switch (argv[1][0]-'0')
   {
   case 1:
    randomizer(argv,(size_t)argv[3]);
    break;
   
   default:
    break;
   }

}

void randomizer(char *argv[], size_t n){
    FILE* file=fopen(argv[2], "w");
    if(n==1) n=MAX_32;
    else if (n==2)  n=MAX_64;
    char ch='A';
    for(size_t i=0;i<=n;i++){
        fprintf(file,"%c",ch);
        ch++;
        if(ch>123)
            ch='A';
    }
    for(int i=0;i<5;i++){
        fprintf(file,"%c",ch);
        ch++;
    }
    fclose(file);
}