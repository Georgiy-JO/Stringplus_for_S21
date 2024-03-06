//#include <stdio.h>      //debug
#include "s21_string.h"

#define S21_SSCANF_LENGTH "hlL"
#define S21_SSCANF_INT_SPEC "diouxX"    //hl
#define S21_SSCANF_FLOAT_SPEC "eEfgG"   //L
#define S21_SSCANF_CHAR_SPEC "cs"       //l
#define S21_SSCANF_SPECIAL_SPEC "pn"
#define S21_SSCANF_SKIP '*'
#define S21_SSCANF_PERCENT '%'
#define HEXADECIMAL_BIG "ABCDEF"
#define HEXADECIMAL_SMALL "abcdef"
// #define WHITESPACES   {9,10,11,12,13,32,0}  //"\t\n\v\f\r\0"   

#define S21_SSCANF_ZERO_SYMBOLS "+-"
//#define S21_SSCANF_HEX_ULTIMATE "ABCDEF0123456789abcdef"

#ifndef __INT_MAX__
#define __INT_MAX__ 0x7fffffff   
#endif
#ifndef __UINT_MAX__
#define __UINT_MAX__ __INT_MAX__* 2L + 1L
#endif
#ifndef __SHRT_MAX__
#define __SHRT_MAX__ 0x7fff 
#endif
#ifndef __USHRT_MAX__
#define __USHRT_MAX__ __SHRT_MAX__*2+1 
#endif
#ifndef __LONG_MAX__
#define __LONG_MAX__ 0x7fffffffffffffffL 
#endif
#ifndef __ULONG_MAX__
#define __ULONG_MAX__ __LONG_MAX__* 2UL + 1UL                       
#endif
#ifndef __CHAR_MAX__
#define __CHAR_MAX__ 0x7f 
#endif
#ifndef __UCHAR_MAX__
#define __UCHAR_MAX__ __CHAR_MAX__*2+1 
#endif
#ifndef __FLT_MAX__
#define __FLT_MAX__ 3.40282346638528859811704183484516925e+38L 
#endif
#ifndef __DBL_MAX__
#define __DBL_MAX__ (double)1.79769313486231570814527423731704357e+308L 
#endif
#ifndef __SIZE_T_MAX__
#define __SIZE_T_MAX__ __ULONG_MAX__
#endif

#ifndef EOF
#define EOF (-1)        
#endif
// #define ERROR (-1)       //EOF??         https://www.tutorialspoint.com/c_standard_library/c_function_sscanf.htm

typedef struct variables{
    char skip;
    char spec;
    char length;
    size_t width;
} variables;

int s21_sscanf(const char *str, const char *format, ...){
	if(str == NULL || format==NULL || str[0]==C_ZERO)     return EOF;
    size_t var_amount =0;
    size_t var_number=0;
    var_amount=var_counting(format);
    if(var_amount){
        va_list var;
        va_start(var, format);

        variables var_spec={0, C_ZERO,C_ZERO,0};
        char *str_coursor=(char*) str;
        char *format_coursor=(char*)format;
        //printf("\n0)$$%s$$%s$$\n",str_coursor, format_coursor );
        for(size_t i=0; str_coursor!=NULL && format_coursor!=NULL && i<var_amount && *str_coursor!=C_ZERO ; zero_struct(&var_spec)){
            //printf("\n1)$$%s$$%s$$\n",str_coursor, format_coursor );
            if(*format_coursor!=S21_SSCANF_PERCENT) {
                format_coursor = string_cutter(&str_coursor,format_coursor); 
            }
            else{
                if (char_is_whitespace(*str_coursor)) str_coursor=whitespace_romover(str_coursor);
                if(*(format_coursor+1)==S21_SSCANF_PERCENT){
                    i+=2;
                    format_coursor+=2;
                    if (*str_coursor==S21_SSCANF_PERCENT)        str_coursor++;
                    else         str_coursor=NULL;
                    //printf("\n3)$$%s$$%s$$\n",str_coursor, format_coursor );
                    continue;
                }
                //printf("\n2)$$%s$$%s$$\n",str_coursor, format_coursor );
                i++;
                format_coursor=spec_translator(&var_spec, (format_coursor+1)); 
                //printf("\n2)$$%s$$%s$$\n",str_coursor, format_coursor );
                if(format_coursor!=NULL && *str_coursor!=C_ZERO){
                    //printf("\n4)$$%s$$%s$$\n",str_coursor, format_coursor );
                    if(var_spec.spec=='n')  {
                        if (var_spec.skip!=1)   *(va_arg(var,int*))=str_coursor- str;
                    }else{
                        str_coursor=var_filling(&var, var_spec, str_coursor);
                        //printf("\n5)$$%s$$%s$$\n",str_coursor, format_coursor );
                        if(str_coursor!=NULL && var_spec.skip!=1)   var_number++;                 
                    }
                }
  
            }
            //printf("\n2)$$%s$$%s$$\n",str_coursor, format_coursor );
        }
        va_end(var);         
    }
    return var_number;
}

// char char_is_invis (const char tmp){
//     return ((tmp<=32 && tmp>=1) || tmp==127)? 1:0;
// }
char char_is_whitespace (const char tmp){           //9,10,11,12,13,32,0 
    return ((tmp>=9 && tmp<=13) || tmp==32 /*|| tmp==0*/)? 1:0;
}
char char_is_num (const char tmp){
    return (tmp>='0' && tmp<='9')? 1:0;
}
char char_is_oct (const char tmp){
    return (tmp>='0' && tmp<='7')? 1:0;
}
char char_is_hex (const char tmp){
    return ((tmp>='0' && tmp<='9') || s21_isinstr(tmp,HEXADECIMAL_BIG) || s21_isinstr(tmp,HEXADECIMAL_SMALL))? 1:0;
}
char char_is_big_hexes (const char tmp){
    return (s21_isinstr(tmp,HEXADECIMAL_BIG))? 1:0;
}
char char_is_small_hexes (const char tmp){
    return (s21_isinstr(tmp,HEXADECIMAL_SMALL))? 1:0;
}

int char_to_num (const char n){
    return n-'0';
}
// char num_to_char (const int n){
//     return n +'0';
// }
int big_hex_to_num (const char n){
    return n - 'A'+10;
}
int small_hex_to_num (const char n){
    return n - 'a'+10;
}

void zero_struct(variables * var){
    var->skip=0;
    var->spec=C_ZERO;
    var->length=C_ZERO;
    var->width=0;
}
size_t var_counting (const char *format){
    size_t amount=0;
    for(int i=0;format[i]!=C_ZERO;i++){
        if(format[i]==S21_SSCANF_PERCENT)
            amount++;
    }
    return amount;
}
char* whitespace_romover (const char* a_string){
    char* loc_str=(char*)a_string;
    for(;char_is_whitespace(*loc_str);) {loc_str++;}
    return loc_str;
}
char can_read_spec_numbers (const char* str_coursor, size_t length){
    return (char_is_num(*str_coursor) || (s21_isinstr(*str_coursor,S21_SSCANF_ZERO_SYMBOLS)&& length!=1&&char_is_num(*(str_coursor+1))))? 1:0;
}
// char can_read_spec_double (const char* str_coursor, size_t length){
//     return (char_is_num(*str_coursor) || (s21_isinstr(*str_coursor,S21_SSCANF_ZERO_SYMBOLS)&&             (  (length!=1&&char_is_num(*(str_coursor+1))) ||       (length!=2&&*(str_coursor+1)=='.'&&char_is_num(*(str_coursor+2)) )       )               )      ||    ((*str_coursor)== '.' && length!=1 && char_is_num(*(str_coursor+1)) )  )? 1:0;
// }
char can_read_spec_double (const char* str_coursor, size_t length){
    if(char_is_num(*str_coursor))   return 1;
    else if (s21_isinstr(*str_coursor,S21_SSCANF_ZERO_SYMBOLS) && length!=1 && char_is_num(*(str_coursor+1)))   return 1;
    else if (s21_isinstr(*str_coursor,S21_SSCANF_ZERO_SYMBOLS) && length>2 && (*(str_coursor+1))=='.' && char_is_num(*(str_coursor+2)))   return 1;
    else if ((*str_coursor)== '.' && length!=1 && char_is_num(*(str_coursor+1)))   return 1;
    else return 0;
}
char can_read_spec_oct (const char* str_coursor, size_t length){
    return (char_is_oct(*str_coursor) || (s21_isinstr(*str_coursor,S21_SSCANF_ZERO_SYMBOLS)&& length!=1&&char_is_oct(*(str_coursor+1))))? 1:0;
}
char can_read_spec_hex (const char* str_coursor, size_t length){
    return (char_is_hex(*str_coursor) || (s21_isinstr(*str_coursor,S21_SSCANF_ZERO_SYMBOLS)&& length!=1&&char_is_hex(*(str_coursor+1))))? 1:0;
}
char mantissa_switch(const char* line, const size_t local_move, const size_t move){
    // if(local_move!=move){
    //     if(*(line+local_move)=='e' || *(line+local_move)=='E'){
    //         if(char_is_num (*(line+local_move+1)))  return 1;
    //         else if (s21_isinstr(*(line+local_move+1),S21_SSCANF_ZERO_SYMBOLS)) return 1;
    //     }
    // }
    // return 0;
    return (    (local_move!=move||move==0) && (*(line+local_move)=='e' || *(line+local_move)=='E') /*&& (char_is_num (*(line+local_move+1)) || char_is_whitespace(*(line+local_move+1)))*/   )? 1:0;
}
long double my_spesial_pow(double n, double m){
    long double res=1;
    if(m>0){
        for(int i=0;i<m;i++){
            res*=n;
        }
    }
    else if (m<0){
        for(int i=0;i>m;i--){
            res/=n;
        }
    }
    return res;
}

long double ultimate_int_from_line(const char* line, size_t* move, char* overfflow){
    long double local_num=0.0;
    size_t local_move=0;
    double neg_flag=1.0;
    unsigned long limit = __ULONG_MAX__;
    if (*overfflow) limit = __LONG_MAX__;
    *overfflow = 0;
    if(*line=='-'){
        local_move++; 
        neg_flag=-1.0;
    }
    else if (*line=='+')    local_move++;
    for(;char_is_num (*(line+local_move))&&(local_move < (*move) || (*move)==0);local_move++){
        local_num=local_num*10.0+(double)char_to_num(*(line+local_move));
        if(local_num>limit || ((size_t)local_num==limit &&neg_flag==-1.0))    *overfflow=1;
    }                                                                                  
    if(*move==0 || *move>local_move)  *move=local_move;
    return local_num*neg_flag;
}
long double ultimate_octal_from_line(const char* line, size_t* move){
    long double local_num=0.0;
    size_t local_move=0;
    double neg_flag=1.0;
    size_t limit = __ULONG_MAX__;
    char overflow_flag=0;
    if(*line=='-'){
        local_move++; 
        neg_flag=-1.0;
    }
    else if (*line=='+')    local_move++;
    for(;char_is_oct (*(line+local_move))&&(local_move < (*move) || (*move)==0);local_move++){
        local_num=local_num*8+char_to_num(*(line+local_move));
        if(local_num>limit || ((size_t)local_num==limit &&neg_flag==-1.0))    overflow_flag=1;
    }
    if(*move==0 || *move>local_move)  *move=local_move;
    if (overflow_flag==1)   local_num=-neg_flag;
    return local_num*neg_flag;
}
long double ultimate_hex_from_line(const char* line, size_t* move){
    //printf(".Here>%s\n",line);    
    long double local_num=0.0;
    double single_digit=0;
    size_t local_move=0;
    double neg_flag=1.0;
    char overflow_flag=0;
    size_t limit = __ULONG_MAX__;
    if(*line=='-'){
        local_move++; 
        neg_flag=-1.0;
    }
    else if (*line=='+')    local_move++;
    if(*(line+local_move)=='0' && (*(line+local_move+1)=='x' || *(line+local_move+1)=='X') && (char_is_hex (*(line+local_move+2))|| char_is_whitespace(*(line+local_move+2))) /*&& (*move==0 || *move-local_move>2)*/)    local_move+=2;
    //printf(".Here>%s\n",line);  
    for(;char_is_hex (*(line+local_move))&&(local_move < (*move) || (*move)==0);local_move++){
        if(char_is_big_hexes(*(line+local_move))) single_digit= big_hex_to_num (*(line+local_move));
        else if (char_is_small_hexes(*(line+local_move))) single_digit= small_hex_to_num (*(line+local_move));
        else    single_digit=char_to_num(*(line+local_move));
        local_num=local_num*16+single_digit;
        if(local_num>limit || ((size_t)local_num==limit &&neg_flag==-1.0))    overflow_flag=1;        
    }
    if(*move==0 || *move>local_move)  *move=local_move;
    //printf(">>>>%d>>%f>>>%Lf\n", overflow_flag,neg_flag, local_num);
    if (overflow_flag==1)   local_num=-neg_flag;
    return local_num*neg_flag;
}
long double ultimate_double_from_line(const char* line, size_t* move){          //strtold() from stdlib.h
    long double local_num=0.0;
    size_t local_move=0;
    double  neg_flag=1.0; 
    
    if(*line=='-'){
        local_move++; 
        neg_flag=-1.0;
    }
    else if (*line=='+')    local_move++;
    //printf("1)>>%ld>>%Lf>>%s\n",local_move,local_num,(line+local_move));
    for(;char_is_num (*(line+local_move))&&(local_move < (*move) || (*move)==0);local_move++){
        local_num=local_num*10.0+(long double)char_to_num(*(line+local_move));
    }
    //printf("1.1)>>%ld>>%Lf>>%s\n",local_move,local_num,(line+local_move));
    if(*(line+local_move)=='.' && (local_move!=(*move) || (*move)==0)){
       //printf("2)>>%ld>>%Lf>>%s\n",local_move,local_num,(line+local_move));
        local_move++;
        for(double i=1;char_is_num (*(line+local_move))&&(local_move < (*move) || (*move)==0);local_move++, i++){
            local_num=local_num+(long double)(char_to_num(*(line+local_move)))/(my_spesial_pow(10.0,i));
        }
    }
    if(mantissa_switch(line, local_move, *move)){
        //printf("3)>>%ld>>%Lf>>%s\n",local_move,local_num,(line+local_move));
        local_move++;
        double mantiss_num=0, decimal_sign_flag=1;
        if(*(line+local_move)=='-')     decimal_sign_flag=-1;
        if(s21_isinstr(*(line+local_move),S21_SSCANF_ZERO_SYMBOLS)) local_move++;
        for(;char_is_num (*(line+local_move))&&(local_move < (*move) || (*move)==0);local_move++){
            mantiss_num=mantiss_num*10+(double)char_to_num(*(line+local_move));
        }
        mantiss_num*=decimal_sign_flag;
        local_num=local_num*my_spesial_pow(10.0,mantiss_num);
    }
    //printf("4)>>%ld>>%Lf>>%s\n",local_move,local_num,(line+local_move));
    if(*move==0 || *move>local_move)  *move=local_move;
    return local_num*(long double)neg_flag;
}
unsigned int uint_from_line(const char* line, size_t* move){
    char overfflow=0;
    unsigned int tmp=(unsigned int)ultimate_int_from_line(line,move,&overfflow);
    return (overfflow)? (unsigned int)-1:tmp;
}
unsigned short ushort_from_line(const char* line, size_t* move){    //99999999999999999>x>-9999999999999999 ????
    char overfflow=0;
    long int tmp=(long int)ultimate_int_from_line(line,move,&overfflow);
    return (overfflow)? (long int)-1:tmp;
}
int int_from_line(const char* line, size_t* move){
    char overfflow=0;
    long int tmp=(long int)ultimate_int_from_line(line,move,&overfflow);
    return (overfflow)? (long int)-1:tmp;                         //fucking hell!!! WTF?! FUCKING STUPID BUSTARDS! FUUUUUUUUUUUUUUUUUUUUUUUUUUUUUCK!
}
long int long_from_line(const char* line, size_t* move){
    char overfflow=1;
    long int tmp=(long int)ultimate_int_from_line(line,move,&overfflow);
    return (overfflow)? (long int)__LONG_MAX__:tmp;
}
short int short_from_line(const char* line, size_t* move){
    char overfflow=0;
    long int tmp=(long int)ultimate_int_from_line(line,move,&overfflow);
    return (overfflow)? (long int)-1:tmp;
}
size_t ulong_from_line(const char* line, size_t* move){
    char overfflow=0;
    size_t tmp=(size_t)ultimate_int_from_line(line,move,&overfflow);
    return (overfflow)? (size_t)-1:tmp;
}
unsigned int uoctal_from_line(const char* line, size_t* move){
    return (unsigned int) ultimate_octal_from_line(line,move); 
}
unsigned short short_uoctal_from_line(const char* line, size_t* move){
    return (long int) ultimate_octal_from_line(line,move); 
}
size_t long_uoctal_from_line(const char* line, size_t* move){
     return (size_t) ultimate_octal_from_line(line,move); 
}
int hex_from_line(const char* line, size_t* move){
    return (long int) ultimate_hex_from_line(line,move);
}
short int short_hex_from_line(const char* line, size_t* move){
    return (long int) ultimate_hex_from_line(line,move);
}
long int long_hex_from_line(const char* line, size_t* move){
    return (long int) ultimate_hex_from_line(line,move);
}
double double_from_line(const char* line, size_t* move){        
    return (double) ultimate_double_from_line(line,move);
}
int signed_num_from_line(const char* line, size_t* move){
    int local_num=0;
    size_t local_move=0;
    if(*line=='-' || *line=='+')  local_move++;
    if(*(line+local_move)=='0' && (*(line+local_move+1)=='x' || *(line+local_move+1)=='X') && char_is_hex (*(line+local_move+2)) && ((*move-local_move)>=2 || *move==0))    local_num=hex_from_line(line,move);
    else if (*(line+local_move)=='0') local_num=uoctal_from_line(line,move);
    else    local_num=int_from_line(line,move);
    return local_num;
}
short short_signed_num_from_line(const char* line, size_t* move){
    short local_num=0;
    size_t local_move=0;
    if(*line=='-' || *line=='+')  local_move++;
    if(*(line+local_move)=='0' && (*(line+local_move+1)=='x' || *(line+local_move+1)=='X') && char_is_hex (*(line+local_move+2)) && ((*move-local_move)>=2 || *move==0))    local_num=short_hex_from_line(line,move);
    else if (*(line+local_move)=='0') local_num=short_uoctal_from_line(line,move);
    else    local_num=short_from_line(line,move);
    return local_num;
}
long int long_signed_num_from_line(const char* line, size_t* move){
    long int local_num=0;
    size_t local_move=0;
    if(*line=='-')  local_move++;
    if(*(line+local_move)=='0' && (*(line+local_move+1)=='x' || *(line+local_move+1)=='X') && char_is_hex (*(line+local_move+2))&& ((*move-local_move)>=2 || *move==0))    local_num= long_hex_from_line(line,move);
    else if (*(line+local_move)=='0' /*&& char_is_oct (*(line+local_move+1))*/) local_num=long_uoctal_from_line(line,move);
    else    local_num=long_from_line(line,move);
    return local_num;
}
void** pointer_from_line(const char* line, size_t* move){
    size_t local_num=0;
    local_num= long_hex_from_line(line,move);
    return (void*)local_num;
}
char char_from_line(const char* line, size_t* move){                     //does not work in my architecture
    if(*move==0)  *move=1;
    return *line;
}
wint_t long_char_from_line(const char* line, size_t* move){          //does not work in my architecture
    if(*move==0)  *move=1;
    return (wint_t)(*line);
}
void string_from_line(const char* line, size_t* move, char* dest){
    size_t local_move=0;
    for(; !char_is_whitespace(*(line+local_move))&&(local_move < (*move) || (*move)==0) && *(line+local_move)!=C_ZERO;local_move++){
        *(dest+local_move)=*(line+local_move);
    }
    *(dest+local_move)=0;
    if(*move==0 || *move>local_move)  *move=local_move;
}
void long_string_from_line(const char* line, size_t* move, wchar_t* dest){
    size_t local_move=0;
    for(; !char_is_whitespace(*(line+local_move))&&(local_move < (*move) || (*move)==0) && *(line+local_move)!=C_ZERO;local_move++){
        *(dest+local_move)=(wchar_t)*(line+local_move); 
    }
    *(dest+local_move)=0;
    if(*move==0 || *move>local_move)  *move=local_move;
}
void string_from_line_skip(const char* line, size_t* move){
    size_t local_move=0;
    for(; !char_is_whitespace(*(line+local_move))&&(local_move < (*move) || (*move)==0) && *(line+local_move)!=C_ZERO;local_move++);
    if(*move==0 || *move>local_move)  *move=local_move;
}
 /*
    %ls && &lc
        wint_t is not necessarily an unsigned integer type. It is typically defined as an integer type capable of representing any 
        valid value of wchar_t, as well as an additional distinct value to represent the end-of-file indicator for wide-character 
        streams (WEOF).
        The C standard doesn't specify the exact underlying type of wint_t. Its size and signedness can vary depending on the 
        platform and the compiler implementation.
        On most systems, wint_t is defined in <wchar.h> as an integer type, but whether it's signed or unsigned can vary. 
        You would need to consult the documentation or the specific implementation of your compiler to determine its 
        characteristics on your system.

        %c- int which is internally converted to unsigned char
        %lc - wint_t
        %s - pointer to zero-terminated array of char
        %ls - pointer to zero-terminated array of wchar_t

        typedef unsigned int wint_t
        typedef int wchar_t
*/

size_t u_filler(va_list* var, variables var_spec, char* str_coursor){
    size_t move=var_spec.width;
    if(!can_read_spec_numbers(str_coursor,move))    move=0;
    else if(var_spec.skip==1)       uint_from_line(str_coursor,&move);
    else{
        if(var_spec.length=='l'){
            size_t* var_point=va_arg(*var,size_t*);
            *var_point= (size_t)ulong_from_line(str_coursor,&move);
        }else if (var_spec.length=='h'){
            unsigned short* var_point=va_arg(*var,unsigned short*);
            *var_point=ushort_from_line(str_coursor,&move);
        }else{
            unsigned int* var_point=va_arg(*var,unsigned int*);
            *var_point=uint_from_line(str_coursor,&move);
        }
    }
    return move;
}
size_t d_filler(va_list* var, variables var_spec, char* str_coursor){
    size_t move=var_spec.width;
    if(!can_read_spec_numbers(str_coursor,move))    move=0;
    else if(var_spec.skip==1)       int_from_line(str_coursor,&move);
    else{
        if(var_spec.length=='l'){
            long int* var_point=va_arg(*var,long int*);
            *var_point=long_from_line(str_coursor,&move);
        }else if (var_spec.length=='h'){
            short int* var_point=va_arg(*var,short int*);
            *var_point=short_from_line(str_coursor,&move);
        }else{
            int* var_point=va_arg(*var,int*);
            *var_point= int_from_line(str_coursor,&move);
        }
    }
    return move;
}
size_t i_filler(va_list* var, variables var_spec, char* str_coursor){
    size_t move=var_spec.width;
    if(!can_read_spec_numbers(str_coursor,move))        move=0;
    else if(var_spec.skip==1)   signed_num_from_line(str_coursor,&move);
    else{
        if(var_spec.length=='l'){
            long int* var_point=va_arg(*var,long int*);
            *var_point=long_signed_num_from_line(str_coursor,&move);
        }else if (var_spec.length=='h'){
            short int* var_point=va_arg(*var,short int*);
            *var_point=short_signed_num_from_line(str_coursor,&move);
        }else{
            int* var_point=va_arg(*var,int*);
            *var_point=signed_num_from_line(str_coursor,&move);
        }
    }
    return move;
}
size_t o_filler(va_list* var, variables var_spec, char* str_coursor){
    size_t move=var_spec.width;
    if(!can_read_spec_oct(str_coursor,move))     move=0;
    else if(var_spec.skip==1)   uoctal_from_line(str_coursor,&move);
    else{
        if(var_spec.length=='l'){
            size_t* var_point=va_arg(*var,size_t*);
            *var_point=long_uoctal_from_line(str_coursor,&move);
        }else if (var_spec.length=='h'){
            unsigned short int* var_point=va_arg(*var,unsigned short int*);
            *var_point=short_uoctal_from_line(str_coursor,&move);
        }else{
            unsigned int* var_point=va_arg(*var,unsigned int*);
            *var_point=uoctal_from_line(str_coursor,&move);
        }
    }
    return move;
}
size_t x_filler(va_list* var, variables var_spec, char* str_coursor){
    size_t move=var_spec.width;
    if(!can_read_spec_hex(str_coursor,move))        move=0;
    else if(var_spec.skip==1)       hex_from_line(str_coursor,&move);
    else{
        if(var_spec.length=='l'){
            long int* var_point=va_arg(*var,long int*);
            *var_point=long_hex_from_line(str_coursor,&move);
        }else if (var_spec.length=='h'){
            short int* var_point=va_arg(*var,short int*);
            *var_point=short_hex_from_line(str_coursor,&move);
        }else{
            int* var_point=va_arg(*var,int*);
            *var_point=hex_from_line(str_coursor,&move);
        }
    }
    return move;
}
size_t f_filler(va_list* var, variables var_spec, char* str_coursor){
    size_t move=var_spec.width;
    if(!can_read_spec_double(str_coursor,move))      move=0;
    else if(var_spec.skip==1)   double_from_line(str_coursor,&move);
    else{
        if(var_spec.length=='L'){
            long double* var_point=va_arg(*var,long double*);
            *var_point=ultimate_double_from_line(str_coursor,&move);
        }else if(var_spec.length=='l'){
            double* var_point=va_arg(*var,double*);
            *var_point=(double)ultimate_double_from_line(str_coursor,&move);
        }else{
            float* var_point=va_arg(*var,float*);
            *var_point=double_from_line(str_coursor,&move);
        }
    }
    return move;
}
size_t c_filler(va_list* var, variables var_spec, char* str_coursor){
    size_t move=var_spec.width;
    if(var_spec.skip==1)   char_from_line(str_coursor,&move);
    else{
        if(var_spec.length=='l'){
            wint_t* var_point=va_arg(*var,wint_t*);
            *var_point=long_char_from_line(str_coursor,&move);
        }else {
            char* var_point=va_arg(*var,char*);
            *var_point=char_from_line(str_coursor,&move);
        }
    }
    return move;
}
size_t s_filler(va_list* var, variables var_spec, char* str_coursor){
    size_t move=var_spec.width;
    if(var_spec.skip==1)        string_from_line_skip(str_coursor,&move);
    else{
        if(var_spec.length=='l'){
            wchar_t* var_point=va_arg(*var,wchar_t*);
            long_string_from_line(str_coursor,&move,var_point);
        }else {
            char* var_point=va_arg(*var,char*);
            string_from_line(str_coursor,&move,var_point);
        }
    }
    return move;
}
size_t p_filler(va_list* var, variables var_spec, char* str_coursor){
    size_t move=var_spec.width;
    if(!can_read_spec_hex(str_coursor,move))move=0;
    else if(var_spec.skip==1)    pointer_from_line(str_coursor,&move);
    else{
        void** var_point=va_arg(*var,void**);
        *var_point=pointer_from_line(str_coursor,&move);
    }
    return move;
}

// format be like: %[*][width][length]specifier.                 
char* spec_translator(variables* var_spec, const char* format){
    char* loc_format=(char*) format;
    //skip(*)
    if(*loc_format==S21_SSCANF_SKIP){
        var_spec->skip=1;
        loc_format++;
    }
    //width (nums)
    if(char_is_num (*loc_format)){
        size_t num_temp=0;
        char overfflow=0;
        var_spec->width=(size_t) ultimate_int_from_line(loc_format,&num_temp, &overfflow);
        loc_format=loc_format+num_temp;
    }
    //length (hlL)
    if(s21_isinstr(*loc_format,S21_SSCANF_LENGTH)){
        var_spec->length=*loc_format;
        loc_format++;
    }
    //int (diouxX)
    if(s21_isinstr(*loc_format,S21_SSCANF_INT_SPEC)){
        if (var_spec->length==C_ZERO||s21_isinstr(var_spec->length,"hl"))
        {
            var_spec->spec=*loc_format;
            loc_format++;
        }
        else                    loc_format=NULL;
    }
    //float (eEfgG)
    else if (s21_isinstr(*loc_format,S21_SSCANF_FLOAT_SPEC)){
        if (var_spec->length==C_ZERO||s21_isinstr(var_spec->length,"Ll"))
        {
            var_spec->spec=*loc_format;
            loc_format++;
        }
        else                    loc_format=NULL;
    }
    //char (cs)
    else if (s21_isinstr(*loc_format,S21_SSCANF_CHAR_SPEC)){
        if (var_spec->length==C_ZERO||s21_isinstr(var_spec->length,"l"))
        {
            var_spec->spec=*loc_format;
            loc_format++;
        }
        else                    loc_format=NULL;
    }
    //spesial(pn)
    else if (s21_isinstr(*loc_format,S21_SSCANF_SPECIAL_SPEC))
    {
        if (var_spec->length==C_ZERO)
        {
            var_spec->spec=*loc_format;
            loc_format++;
            
        }
        else                    loc_format=NULL;  
    }
    else          loc_format=NULL; 
    return loc_format;
}
char* var_filling(va_list* var, variables var_spec, char* str_coursor){
    size_t move=var_spec.width;
    switch (var_spec.spec)
    {
    case 'u':
        move=u_filler(var,var_spec,str_coursor);
        break;
    case 'd':
        move=d_filler(var,var_spec,str_coursor);
        break;
    case 'i':
        move=i_filler(var,var_spec,str_coursor);
        break;
    case 'o':
        move=o_filler(var,var_spec,str_coursor);
        break;
    case 'x':
    case 'X':
        move=x_filler(var,var_spec,str_coursor);
        break;
    case 'f':
    case 'g':
    case 'G':
    case 'e':
    case 'E':
        move=f_filler(var,var_spec,str_coursor);
        break;
    case 'c':
        move=c_filler(var,var_spec,str_coursor);
        break;
    case 's':
        move=s_filler(var,var_spec,str_coursor);
        break;
    case 'p':
        move=p_filler(var,var_spec,str_coursor);
        break;
    }
    if(move==0) str_coursor=NULL;
    return str_coursor+move;
}
//compare according to the format line and cut string between %
char* string_cutter(char** str_coursor, const char* format_coursor){
    char* loc_str_cours = *str_coursor;
    char* loc_form_cours = (char*) format_coursor;
    for(;loc_form_cours != NULL && *loc_form_cours!=S21_SSCANF_PERCENT;){
        if(char_is_whitespace(*loc_form_cours)) loc_form_cours++;
        else if (char_is_whitespace(*loc_str_cours)) loc_str_cours++;
        else if ((*loc_form_cours)==(*loc_str_cours))
        {
            loc_form_cours++;
            loc_str_cours++;
        }
        else   loc_form_cours = NULL;
    }
    *str_coursor = loc_str_cours;
    return loc_form_cours;
}

