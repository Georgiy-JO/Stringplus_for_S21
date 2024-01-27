#include <stdio.h>
#include <string.h>
#include "s21_string.h"

#define LIMIT_1 1800

int main(){
/*
    //(*1.1)
    char* line=MY_NULL;
    printf("%ld",s21_strlen(line));
    scanf("%s",line);
*/

/*
    //(*3)
    char line[10]="ggggg";
    s21_memset(line, 'f', 13);
    for(int i=0; i<15;i++){
        printf("%c",line[i]);
    }
    scanf("%s",line);
*/

/*
    //(*1.2)
    char* line=MY_NULL;
    char letter = 'f';
    int len = 2;
    void* p=memset(line,letter,len);
    //void* p=s21_memset(line,letter,len);
    printf("%s",(char*)p);
    scanf("%s",line);
*/

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
            printf("1-> exit, 2-> rechoose function, 3-> s21_len, 4-> s21_memcpy,\n5-> s21_memset, 6-> s21_strncpy\n7-> s21_memchr\n8-> s21_memcmp\n9->s21_strchr.c\n10->s21_strncmp.c\n11->s21_strrchr\n12->s21_strstr");
        if(input[0]=='2'){
            printf("1-> exit, 2-> rechoose function, 3-> s21_len, 4-> s21_memcpy,\n5-> s21_memset, 6-> s21_strncpy\n7-> s21_memchr\n8-> s21_memcmp\n9->s21_strchr.c\n10->s21_strncmp.c\n11->s21_strrchr\n12->s21_strstr");
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
            getchar();
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
            getchar();
            printf("\t%p-->%p-->%s\n",input, memcpy(input,input2,n), input);
            printf("\t%p-->%p-->%s\n\n",input3, s21_memcpy(input3,input2,n), input3);
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
            getchar();
            printf("\t%p-->%p-->%s\n",input, memset(input,c,n), input);
            printf("\t%p-->%p-->%s\n\n",input3, s21_memset(input3,c,n), input3);
            break;
        case 6:             //s21_strncpy
            printf("Input line1->\t");
            fgets(input, LIMIT_1, stdin);
            strcpy(input3,input);
            printf("Input line2->\t");
            fgets(input2, LIMIT_1, stdin);
            printf("Input length of copying->\t");
            scanf("%ld",&n);
            getchar();
            printf("\t%p-->%p-->%s\n",input, strncpy(input,input2,n), input);
            printf("\t%p-->%p-->%s\n\n",input3, s21_memcpy(input3,input2,n), input3);
            break;
        case 7:             //s21_memchr
            printf("Input line1->\t");
            fgets(input, LIMIT_1, stdin);
            strcpy(input3,input);
            printf("Input character->\t");
			scanf("%c",&c);
            printf("Input size->\t");
			scanf("%ld",&n);

            printf("\t%p-->%p-->%c-->%s\n",input, memchr(input3, c, n), *(unsigned char*)(memchr(input3, c, n)) , input);
            printf("\t%p-->%p-->%c-->%s\n",input, s21_memchr(input, c, n), *(unsigned char*)(s21_memchr(input, c, n)), input);
            //printf("\t%p-->%p-->%s\n\n",input3, s21_memcpy(input3,input2,n), input3);
            getchar();
            break;
        case 8:             //s21_memcmp
            printf("Input line1->\t");
            fgets(input, LIMIT_1, stdin);
            strcpy(input3,input);
            printf("Input line2->\t");
            fgets(input2, LIMIT_1, stdin);
            printf("Input length->\t");
            scanf("%ld",&n);

            printf("\t%p-->%d-->%s\n",input, memcmp(input3,input2,n), input);
            printf("\t%p-->%d-->%s\n",input, s21_memcmp(input,input2,n), input);
            //printf("\t%p-->%p-->%s\n\n",input3, s21_memcpy(input3,input2,n), input3);
            getchar();
            break;
        case 9:             //s21_strchr
            printf("Input line1->\t");
            fgets(input, LIMIT_1, stdin);
            strcpy(input3,input);
            printf("Input character->\t");
			scanf("%c",&c);

            printf("\t%p-->%p-->%c-->%s\n",input, memchr(input3, c, n), *(unsigned char*)(strchr(input3, c)) , input);
            printf("\t%p-->%p-->%c-->%s\n",input, s21_memchr(input, c, n), *(unsigned char*)(s21_strchr(input, c)), input);
            //printf("\t%p-->%p-->%s\n\n",input3, s21_memcpy(input3,input2,n), input3);
            getchar();
            break;
        case 10:             //s21_strncmp
            printf("Input line1->\t");
            fgets(input, LIMIT_1, stdin);
            strcpy(input3,input);
            printf("Input line2->\t");
            fgets(input2, LIMIT_1, stdin);
            printf("Input length->\t");
            scanf("%ld",&n);

            printf("\t%p-->%d-->%s\n",input, strncmp(input3,input2,n), input);
            printf("\t%p-->%d-->%s\n",input, s21_strncmp(input,input2,n), input);
            //printf("\t%p-->%p-->%s\n\n",input3, s21_memcpy(input3,input2,n), input3);
            getchar();
            break;
        case 11:             //s21_strchr
            printf("Input line1->\t");
            fgets(input, LIMIT_1, stdin);
            strcpy(input3,input);
            printf("Input character->\t");
			scanf("%c",&c);

            printf("\t%p-->%p-->%c-->%s\n",input, memchr(input3, c, n), *(unsigned char*)(strrchr(input3, c)) , input);
            printf("\t%p-->%p-->%c-->%s\n",input, s21_memchr(input, c, n), *(unsigned char*)(s21_strrchr(input, c)), input);
            //printf("\t%p-->%p-->%s\n\n",input3, s21_memcpy(input3,input2,n), input3);
            getchar();
            break;
        case 12:             //s21_strstr
            printf("Input line1->\t");
            fgets(input, LIMIT_1, stdin);
            strcpy(input3,input);
            printf("Input line2->\t");
            fgets(input2, LIMIT_1, stdin);
            printf("\t%p-->%p-->%c-->%s\n",input, memchr(input3, c, n), *(unsigned char*)(strstr(input3, input2)) , input);
            printf("\t%p-->%p-->%c-->%s\n",input, s21_memchr(input, c, n), *(unsigned char*)(s21_strstr(input, input2)), input);
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
