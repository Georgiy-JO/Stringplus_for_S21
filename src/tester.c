#include <stdio.h>
#include <string.h>
#include "s21_string.h"

#define LIMIT_1 1800

int main(){
    char input[LIMIT_1];
    char input2[LIMIT_1];
    char input3[LIMIT_1];
    char c=0;
    size_t n=0;
    //char tmp=C_ZERO;
    int commands=0;
    input[0]='2';
    for(int i=1;input[0]!='1' && commands!=1;i++){
        if(i%10==0)
            printf("1-> exit, 2-> rechoose function, 3-> s21_len, 4-> s21_memcpy,\n5-> s21_memset, 6-> s21_strncpy\n\n");
        if(input[0]=='2'){
            printf("1-> exit, 2-> rechoose function, 3-> s21_len, 4-> s21_memcpy,\n5-> s21_memset, 6-> s21_strncpy\n\n");
            scanf("%d",&commands);
            getchar();
        }
        switch (commands)
        {
        case 1:             //exit
            break;
        case 2:             //change function
            input[0]='2';
            break; 
        case 3:             //s21_len
            printf("Input line or a-> test_ultimate.txt\n");
            fgets(input, LIMIT_1, stdin);
            if(input[0]=='a')
                //file_read_function("test_ultimate.txt");
                printf("TEMP\n\n");
            else{
                printf("\t%ld\n",strlen(input));
                printf("\t%ld\n\n",s21_strlen(input));
            }
            break;
        case 4:             //s21_memcpy
            printf("Input line1->\t");
            fgets(input, LIMIT_1, stdin);
            strcpy(input3,input);
            printf("Input line2->\t");
            fgets(input2, LIMIT_1, stdin);
            printf("Input length of copying->\t");
            scanf("%ld",&n);

            printf("\t%p-->%p-->%s\n",input, memcpy(input,input2,n), input);
            printf("\t%p-->%p-->%s\n\n",input3, s21_memcpy(input3,input2,n), input3);
            getchar();
            break;
        case 5:             //s21_memset
            printf("Input line->\t");
            fgets(input, LIMIT_1, stdin);
            strcpy(input3,input);
            printf("Input character->\t");
            scanf("%c",&c);
            //printf("----%d----", c);
            printf("Input length ->\t");
            scanf("%ld",&n);

            printf("\t%p-->%p-->%s\n",input, memset(input,c,n), input);
            printf("\t%p-->%p-->%s\n\n",input3, s21_memset(input3,c,n), input3);
            getchar();
            break;
        case 6:             //s21_strncpy
            printf("Input line1->\t");
            fgets(input, LIMIT_1, stdin);
            strcpy(input3,input);
            printf("Input line2->\t");
            fgets(input2, LIMIT_1, stdin);
            printf("Input length of copying->\t");
            scanf("%ld",&n);

            printf("\t%p-->%p-->%s\n",input, strncpy(input,input2,n), input);
            //printf("\t%p-->%p-->%s\n\n",input3, s21_memcpy(input3,input2,n), input3);
            getchar();
            break;


        default:
            input[0]='2';
            fprintf(stderr,"ERROR CHOICE!\n");
            break;
        }
    }


}