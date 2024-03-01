#include <stdio.h>      //debug
#include "s21_string.h"

#define S21_SSCANF_DIGITS "0123456789"
#define S21_SSCANF_LENGTH "hlL"
#define S21_SSCANF_INT_SPEC "diouxX"    //hl
#define S21_SSCANF_FLOAT_SPEC "eEfgG"   //L
#define S21_SSCANF_CHAR_SPEC "cs"   //l
#define S21_SSCANF_SPECIAL_SPEC "pn"   //--'%'??  --- "%%"??
#define S21_SSCANF_SKIP '*'
#define S21_SSCANF_PERCENT '%'
#define S21_SSCANF_PERCENT_LINE "%"
#define S21_SSCANF_SPACE ' '
#define HEXADECIMAL_BIG "ABCDEF"
#define HEXADECIMAL_SMALL "abcdef"
#define WHITESPACES   {9,10,11,12,13,32,0}  //"\t\n\v\f\r\0"   

#define S21_SSCANF_ZERO_SYMBOLS "+-"
#define S21_SSCANF_FLOAT_SYMBOLS "eE"       //--??
#define S21_SSCANF_HEX_ULTIMATE "ABCDEF0123456789abcdef"

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
                    //EOF??         https://www.tutorialspoint.com/c_standard_library/c_function_sscanf.htm
#define ERROR (-1)

typedef struct variables
{
    char skip;
    char spec;
    char length;
    size_t width;

} variables;

int s21_sscanf(const char *str, const char *format, ...){
	if(str == NULL || format==NULL)     return ERROR;          //EOF??
    size_t var_amount =0;
    size_t var_number=0;
    var_amount=var_counting(format);

    if(var_amount){
        va_list var;                        //=0????
        va_start(var, format);

        variables var_spec={0, C_ZERO,C_ZERO,0};
        char *str_coursor=(char*) str;
        char *format_coursor=(char*)format;
        for(size_t i=0; str_coursor!=NULL && format_coursor!=NULL && i<var_amount && *str_coursor!=C_ZERO ; zero_struct(&var_spec)){
            //printf("\n1)$$%s$$%s$$\n",str_coursor, format_coursor );
            if(*format_coursor!=S21_SSCANF_PERCENT) {
                format_coursor = string_cutter(&str_coursor,format_coursor);    //??format_coursor==NULL    --different lines in format and str
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
                format_coursor=spec_translator(&var_spec, (format_coursor+1));      //???format_coursor==NULL         --spec error
                if(format_coursor!=NULL ){
                    //printf("\n4)$$%s$$%s$$\n",str_coursor, format_coursor );
                    if(var_spec.spec=='n')  *(va_arg(var,int*))=str_coursor- str;
                    else{
                        str_coursor=var_filling(&var, var_spec, str_coursor);
                        if(str_coursor!=NULL && var_spec.skip!=1)   var_number++;                       //????str_coursor!=NULL           --reading/wrighting var error?                        
                    }
                }
  
            }
            //printf("\n2)$$%s$$%s$$\n",str_coursor, format_coursor );
        }
        va_end(var);         
    }
    return var_number;
}

char char_is_invis (const char tmp){
    return ((tmp<=32 && tmp>=1) || tmp==127)? 1:0;
}
char char_is_whitespace (const char tmp){ //9,10,11,12,13,32,0
    return ((tmp>=9 && tmp<=13) || tmp==32 || tmp==0)? 1:0;
}
char char_is_num (const char tmp){
    return (tmp>='0' && tmp<='9')? 1:0;
}
char char_is_hex (const char tmp){
    return ((tmp>='0' && tmp<='9') || s21_isinstr(tmp,HEXADECIMAL_BIG) || s21_isinstr(tmp,HEXADECIMAL_SMALL))? 1:0;
}
int char_to_num (const char n){
    return n-'0';
}
char num_to_char (const int n){
    return n +'0';
}
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
char can_read_spec_numbers (const char* str_coursor, size_t lenth){
    return (s21_isinstr(*str_coursor,S21_SSCANF_DIGITS) || (s21_isinstr(*str_coursor,S21_SSCANF_ZERO_SYMBOLS)&& lenth!=1&&s21_isinstr(*(str_coursor+1),S21_SSCANF_DIGITS)))? 1:0;
}
char can_read_spec_hex (const char* str_coursor, size_t lenth){
    return (s21_isinstr(*str_coursor,S21_SSCANF_HEX_ULTIMATE) || (s21_isinstr(*str_coursor,S21_SSCANF_ZERO_SYMBOLS)&& lenth!=1&&s21_isinstr(*(str_coursor+1),S21_SSCANF_HEX_ULTIMATE)))? 1:0;
}

long double ultimate_int_from_line(const char* line, size_t* move){
    long double local_num=0.0;
    size_t local_move=0;
    double neg_flag=1.0, overflow_flag=0.0;
    if(*line=='-'){
        local_move++; 
        neg_flag=-1.0;
    }
    else if (*line=='+')    local_move++;
    
    for(;char_is_num (*(line+local_move))&&(local_move < (*move) || (*move)==0);local_move++){
        //printf("===%c=%d===\n",*(line+local_move), char_is_num (*(line+local_move)));
        if(local_num>=__ULONG_MAX__ || local_num*10+char_to_num(*(line+local_move))<local_num)    overflow_flag=1;
        local_num=local_num*10.0+(double)char_to_num(*(line+local_move));
        //printf("^^%.1Lf\n",local_num);
    }
    //printf("=====\n");
    //printf("^^%.1Lf\n",local_num);
    if(*move==0 || *move>local_move)  *move=local_move;
    if(overflow_flag)   local_num=-neg_flag;
    //printf("^^%.1Lf\n",local_num);
    //printf("<<^^>>%.1Lf\n",local_num*neg_flag);
    return local_num*neg_flag;
}
unsigned int uint_from_line(const char* line, size_t* move){
    return (unsigned int)ultimate_int_from_line(line,move);
}
size_t ulong_from_line(const char* line, size_t* move){
    long long int loc=ultimate_int_from_line(line,move);
    return ((loc>0 && (unsigned long long int)loc>__SIZE_T_MAX__) || (loc<0 && (unsigned long long int)(-loc) > __SIZE_T_MAX__))?  (size_t)-1: (size_t)loc;
    //return (size_t)ultimate_int_from_line(line,move);
}
unsigned short ushort_from_line(const char* line, size_t* move){
    long long int loc=ultimate_int_from_line(line,move);
    return (loc>__USHRT_MAX__ || loc<__USHRT_MAX__)?  (unsigned short)-1: (unsigned short)loc;
    //return (unsigned short)ultimate_int_from_line(line,move);
}
int int_from_line(const char* line, size_t* move){
//    printf("==%s\n",line);
//    long int loc = 0;            
//    loc = ultimate_int_from_line(line,move);
//    printf(">>%d\n", loc);
//    return  loc;

    //return (loc>__INT_MAX__ || loc<-__INT_MAX__)?  -1: (int)loc;
   return (long int) ultimate_int_from_line(line,move);                         //fucking hell!!! WTF?! FUCKING STUPID BUSTARDS! FUUUUUUUUUUUUUUUUUUUUUUUUUUUUUCK!
}
long int long_from_line(const char* line, size_t* move){
    long long int loc=ultimate_int_from_line(line,move);
    return (loc>__LONG_MAX__ || loc<-__LONG_MAX__)?  -1: (long int)loc;
    //return (long int)ultimate_int_from_line(line,move);
}
short int short_from_line(const char* line, size_t* move){
    long long int loc=ultimate_int_from_line(line,move);
    return (loc>__SHRT_MAX__ || loc<-__SHRT_MAX__)?  -1: (short int)loc;
    //return (short int)ultimate_int_from_line(line,move);
}
unsigned int uoctal_from_line(const char* line, size_t* move){
    unsigned int local_num=0;
    size_t local_move=0;
    for(;char_is_num (*(line+local_move))&&(local_move < (*move) || (*move)==0);local_move++){
        local_num=local_num*8+char_to_num(*(line+local_move));
    }
    if(*move==0)  *move=local_move;
    return local_num;
}
unsigned short short_uoctal_from_line(const char* line, size_t* move){
    unsigned short local_num=0;
    size_t local_move=0;
    for(;char_is_num (*(line+local_move))&&(local_move < (*move) || (*move)==0);local_move++){
        local_num=local_num*8+char_to_num(*(line+local_move));
    }
    if(*move==0)  *move=local_move;
    return local_num;
}
size_t long_uoctal_from_line(const char* line, size_t* move){
    size_t local_num=0;
    size_t local_move=0;
    for(;char_is_num (*(line+local_move))&&(local_move < (*move) || (*move)==0);local_move++){
        local_num=local_num*8+char_to_num(*(line+local_move));
    }
    if(*move==0)  *move=local_move;
    return local_num;
}
int hex_from_line(const char* line, size_t* move){
    int local_num=0;
    unsigned int temp_digit=0;
    size_t local_move=0;
    int neg_flag=1;
    if(*line=='-'){
        local_move++;
        neg_flag=-1;
    }
    if(*(line+local_move)=='0' && (*(line+local_move+1)=='x' || *(line+local_move+1)=='X') && char_is_num (*(line+local_move+2)))    local_move+=2;
    //printf("\n---------%s--------\n", line+local_move);
    for(;char_is_hex (*(line+local_move))&&(local_move < (*move) || (*move)==0);local_move++){
        if(s21_isinstr(*(line+local_move),HEXADECIMAL_BIG)) temp_digit= big_hex_to_num (*(line+local_move));
        else if (s21_isinstr(*(line+local_move),HEXADECIMAL_SMALL)) temp_digit= small_hex_to_num (*(line+local_move));
        else    temp_digit=char_to_num(*(line+local_move));
        local_num=local_num*16+temp_digit;
    }
    if(*move==0)  *move=local_move;
    return local_num*neg_flag;
}
short int short_hex_from_line(const char* line, size_t* move){
    short local_num=0;
    unsigned int temp_digit=0;
    size_t local_move=0;
    int neg_flag=1;
    if(*line=='-'){
        local_move++;
        neg_flag=-1;
    }
    if(*(line+local_move)=='0' && (*(line+local_move+1)=='x' || *(line+local_move+1)=='X') && char_is_num (*(line+local_move+2)))    local_move+=2;
    //printf("\n---------%s--------\n", line+local_move);
    for(;char_is_hex (*(line+local_move))&&(local_move < (*move) || (*move)==0);local_move++){
        if(s21_isinstr(*(line+local_move),HEXADECIMAL_BIG)) temp_digit= big_hex_to_num (*(line+local_move));
        else if (s21_isinstr(*(line+local_move),HEXADECIMAL_SMALL)) temp_digit= small_hex_to_num (*(line+local_move));
        else    temp_digit=char_to_num(*(line+local_move));
        local_num=local_num*16+temp_digit;
    }
    if(*move==0)  *move=local_move;
    return local_num*neg_flag;
}
long int long_hex_from_line(const char* line, size_t* move){
    long int local_num=0;
    unsigned int temp_digit=0;
    size_t local_move=0;
    int neg_flag=1;
    if(*line=='-'){
        local_move++;
        neg_flag=-1;
    }
    if(*(line+local_move)=='0' && (*(line+local_move+1)=='x' || *(line+local_move+1)=='X') && char_is_num (*(line+local_move+2)))    local_move+=2;
    //printf("\n---------%s--------\n", line+local_move);
    for(;char_is_hex (*(line+local_move))&&(local_move < (*move) || (*move)==0);local_move++){
        if(s21_isinstr(*(line+local_move),HEXADECIMAL_BIG)) temp_digit= big_hex_to_num (*(line+local_move));
        else if (s21_isinstr(*(line+local_move),HEXADECIMAL_SMALL)) temp_digit= small_hex_to_num (*(line+local_move));
        else    temp_digit=char_to_num(*(line+local_move));
        local_num=local_num*16+temp_digit;
    }
    if(*move==0)  *move=local_move;
    return local_num*neg_flag;
}
float float_from_line(const char* line, size_t* move){          //  %Lf   The argument is interpreted as a long double   %f - double
    float local_num=0;
    size_t local_move=0;
    int neg_flag=1;
    if(*line=='-'){
        local_move++;
        neg_flag=-1;
    }
    for(;char_is_num (*(line+local_move))&&(local_move < (*move) || (*move)==0);local_move++){
        local_num=local_num*10+char_to_num(*(line+local_move));
    }
    if(*(line+local_move)=='.'){
        local_move++;
        for(float i=1;char_is_num (*(line+local_move))&&(local_move < (*move) || (*move)==0);local_move++, i++){
            local_num=local_num+(float)(char_to_num(*(line+local_move)))/(pow(10.0,i));
        }
    }
    if((*(line+local_move)=='e' || *(line+local_move)=='E') && char_is_num (*(line+local_move+1))){
        local_move++;
        float mantiss_num=0;
        for(;char_is_num (*(line+local_move))&&(local_move < (*move) || (*move)==0);local_move++){
            mantiss_num=mantiss_num*10+char_to_num(*(line+local_move));
        }
        local_num=local_num*pow(10.0,mantiss_num);
        //printf("\n============%f===========\n",local_num);
    }
    if(*move==0)  *move=local_move;
    return local_num*neg_flag;
}
double double_from_line(const char* line, size_t* move){
    double local_num=0;
    size_t local_move=0;
    int neg_flag=1;
    if(*line=='-'){
        local_move++;
        neg_flag=-1;
    }
    for(;char_is_num (*(line+local_move))&&(local_move < (*move) || (*move)==0);local_move++){
        local_num=local_num*10+char_to_num(*(line+local_move));
    }
    if(*(line+local_move)=='.'){
        local_move++;
        for(float i=1;char_is_num (*(line+local_move))&&(local_move < (*move) || (*move)==0);local_move++, i++){
            local_num=local_num+(float)(char_to_num(*(line+local_move)))/(pow(10.0,i));
        }
    }
    if((*(line+local_move)=='e' || *(line+local_move)=='E') && char_is_num (*(line+local_move+1))){
        local_move++;
        float mantiss_num=0;
        for(;char_is_num (*(line+local_move))&&(local_move < (*move) || (*move)==0);local_move++){
            mantiss_num=mantiss_num*10+char_to_num(*(line+local_move));
        }
        local_num=local_num*pow(10.0,mantiss_num);
    }
    if(*move==0)  *move=local_move;
    return local_num*neg_flag;
}
char char_from_line(const char* line, size_t* move){
    if(*move==0)  *move=1;
    return *line;
}
wint_t long_char_from_line(const char* line, size_t* move){
    if(*move==0)  *move=1;
    return (wint_t)(*line);
}
void string_from_line(const char* line, size_t* move, char* dest){
    size_t local_move=0;
    for(; !char_is_whitespace(*(line+local_move))&&(local_move < (*move) || (*move)==0);local_move++){
        *(dest+local_move)=*(line+local_move);
    }
    *(dest+local_move)=0;
    if(*move==0)  *move=local_move;
}
void long_string_from_line(const char* line, size_t* move, wchar_t* dest){
    size_t local_move=0;
    for(; !char_is_whitespace(*(line+local_move))&&(local_move < (*move) || (*move)==0);local_move++){
        *(dest+local_move)=(wchar_t)*(line+local_move);     //memset(   sizeof(wchar_t))
    }
    *(dest+local_move)=0;
    if(*move==0)  *move=local_move;
}
void** pointer_from_line(const char* line, size_t* move){
    size_t local_num=0;
    local_num= long_hex_from_line(line,move);
    return (void*)local_num;
}
int signed_num_from_line(const char* line, size_t* move){
    int local_num=0;
    size_t local_move=0;
    if(*line=='-')  local_move++;
    if(*(line+local_move)=='0' && (*(line+local_move+1)=='x' || *(line+local_move+1)=='X') && char_is_num (*(line+local_move+2)))    local_num=hex_from_line(line,move);
    else if (*(line+local_move)=='0' && char_is_num (*(line+local_move+1))) local_num=uoctal_from_line(line,move);      //signed!!!!?
    else    local_num=int_from_line(line,move);
    return local_num;
}
short short_signed_num_from_line(const char* line, size_t* move){
    short local_num=0;
    size_t local_move=0;
    if(*line=='-')  local_move++;
    if(*(line+local_move)=='0' && (*(line+local_move+1)=='x' || *(line+local_move+1)=='X') && char_is_num (*(line+local_move+2)))    local_num=short_hex_from_line(line,move);
    else if (*(line+local_move)=='0' && char_is_num (*(line+local_move+1))) local_num=short_uoctal_from_line(line,move);      //signed!!!!?
    else    local_num=short_from_line(line,move);
    return local_num;
}
long int long_signed_num_from_line(const char* line, size_t* move){
    long int local_num=0;
    size_t local_move=0;
    if(*line=='-')  local_move++;
    if(*(line+local_move)=='0' && (*(line+local_move+1)=='x' || *(line+local_move+1)=='X') && char_is_num (*(line+local_move+2)))    local_num= long_hex_from_line(line,move);
    else if (*(line+local_move)=='0' && char_is_num (*(line+local_move+1))) local_num=long_uoctal_from_line(line,move);      //signed!!!!?
    else    local_num=long_from_line(line,move);
    return local_num;
}

// format be like: %[*][width][length]specifier. -->%*10lu                   
char* spec_translator(variables* var_spec, const char* format){             //add other flags
    char* loc_format=(char*) format;

    //skip(*)
    if(*loc_format==S21_SSCANF_SKIP){
        var_spec->skip=1;
        loc_format++;
    }
    //width (nums)
    if(char_is_num (*loc_format)){
        size_t num_temp=0;
        var_spec->width=ulong_from_line(loc_format,&num_temp);
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
        if (var_spec->length==C_ZERO||s21_isinstr(var_spec->length,"L"))
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
            if (var_spec->width!=0 && *loc_format=='n')                     loc_format=NULL;
            else{
                var_spec->spec=*loc_format;
                loc_format++;
            }
        }
        else                    loc_format=NULL;  
    }
    else          loc_format=NULL; 
    return loc_format;
}


char* var_filling(va_list* var, variables var_spec, char* str_coursor)
{
    size_t move=var_spec.width;
    switch (var_spec.spec)
    {
    case 'u':
        if(!can_read_spec_numbers(str_coursor,move)){
            move=0;
            str_coursor=NULL;
        }
        else if(var_spec.skip==1){
            if(var_spec.length=='l')            ulong_from_line(str_coursor,&move);
            else if (var_spec.length=='h')      ushort_from_line(str_coursor,&move);
            else                                uint_from_line(str_coursor,&move);
        }
        else{
            if(var_spec.length=='l'){
                size_t* var_point=va_arg(*var,size_t*);
                *var_point=ulong_from_line(str_coursor,&move);
            }else if (var_spec.length=='h'){
                unsigned short* var_point=va_arg(*var,unsigned short*);
                *var_point=ushort_from_line(str_coursor,&move);
            }else{
                unsigned int* var_point=va_arg(*var,unsigned int*);
                *var_point=uint_from_line(str_coursor,&move);
                //printf("\n==%p==%u==\n",var_point,*var_point);
            }
        }
        break;
    case 'd':
        if(!can_read_spec_numbers(str_coursor,move)){
            move=0;
            str_coursor=NULL;
        }
        else if(var_spec.skip==1){
            if(var_spec.length=='l')            long_from_line(str_coursor,&move);
            else if (var_spec.length=='h')      short_from_line(str_coursor,&move);
            else                                int_from_line(str_coursor,&move);
        }
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
        break;
    case 'i':
        if(!can_read_spec_numbers(str_coursor,move)&&!can_read_spec_hex(str_coursor,move)){
            move=0;
            str_coursor=NULL;
        }
        else if(var_spec.skip==1){
            if(var_spec.length=='l')            long_signed_num_from_line(str_coursor,&move);
            else if (var_spec.length=='h')      short_signed_num_from_line(str_coursor,&move);
            else                                signed_num_from_line(str_coursor,&move);
        }
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
        break;
    case 'o':       //? unsigned/signed
        if(!can_read_spec_numbers(str_coursor,move)){
            move=0;
            str_coursor=NULL;
        }
        else if(var_spec.skip==1){
            if(var_spec.length=='l')            long_uoctal_from_line(str_coursor,&move);
            else if (var_spec.length=='h')      short_uoctal_from_line(str_coursor,&move);
            else                                uoctal_from_line(str_coursor,&move);
        }
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
        break;
    case 'x':
    case 'X':
        if(!can_read_spec_hex(str_coursor,move)){
            move=0;
            str_coursor=NULL;
        }
        else if(var_spec.skip==1){
            if(var_spec.length=='l')            long_hex_from_line(str_coursor,&move);
            else if (var_spec.length=='h')      short_hex_from_line(str_coursor,&move);
            else                                hex_from_line(str_coursor,&move);
        }
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
        break;
    case 'f':
    case 'g':
    case 'G':
    case 'e':
    case 'E':
        if(!can_read_spec_numbers(str_coursor,move)){
            move=0;
            str_coursor=NULL;
        }
        else if(var_spec.skip==1){
            if(var_spec.length=='L')            double_from_line(str_coursor,&move);
            else                                float_from_line(str_coursor,&move);
        }
        else{
            if(var_spec.length=='L'){
                double* var_point=va_arg(*var,double*);
                *var_point=double_from_line(str_coursor,&move);
            }else {
                float* var_point=va_arg(*var,float*);
                *var_point=float_from_line(str_coursor,&move);
                //printf("\n===%f=%ld===\n", *var_point, move);
            }
        }
        break;
    case 'c':
        if(var_spec.skip==1){
            if(var_spec.length=='l')            long_char_from_line(str_coursor,&move);
            else                                char_from_line(str_coursor,&move);
        }
        else{
            if(var_spec.length=='l'){
                wint_t* var_point=va_arg(*var,wint_t*);
                *var_point=long_char_from_line(str_coursor,&move);
            }else {
                char* var_point=va_arg(*var,char*);
                *var_point=char_from_line(str_coursor,&move);
            }
        }
        break;
    case 's':
        if(var_spec.skip==1){
            if(var_spec.length=='l'){   wchar_t* var_point=NULL;         long_string_from_line(str_coursor,&move,var_point);}
            else{ char* var_point=NULL;                               string_from_line(str_coursor,&move,var_point);}
        }
        else{
            if(var_spec.length=='l'){
                wchar_t* var_point=va_arg(*var,wchar_t*);
                long_string_from_line(str_coursor,&move,var_point);
            }else {
                char* var_point=va_arg(*var,char*);
                string_from_line(str_coursor,&move,var_point);
            }
        }
        break;
    case 'p':
        if(!can_read_spec_hex(str_coursor,move)){
            move=0;
            str_coursor=NULL;
        }
        else if(var_spec.skip==1)    pointer_from_line(str_coursor,&move);
        else{
            void** var_point=va_arg(*var,void**);
            *var_point=pointer_from_line(str_coursor,&move);
        }
        break;
    }
    //printf("$$%p1\n",str_coursor);
    return str_coursor+move;
}

//compare according to the format line and cut string between %
char* string_cutter(char** str_coursor, const char* format_coursor){
    char* loc_str_cours = *str_coursor;
    char* loc_form_cours = (char*) format_coursor;
    
    for(;loc_form_cours != NULL && *loc_form_cours!=S21_SSCANF_PERCENT;){
        /*
        if((*loc_form_cours<=32 && *loc_form_cours>=1) || *loc_form_cours==127) { loc_form_cours++;  continue;}
        if ((*loc_str_cours<=32 && *loc_str_cours>=1) || *loc_str_cours==127) {loc_str_cours++;  continue;}
        if((*loc_form_cours)==(*loc_str_cours))
        {
            loc_form_cours++;
            loc_str_cours++;
        }
        else    loc_form_cours = NULL;     //EOF??  //if strings before % in format and in str does not match
        */
        if(char_is_whitespace(*loc_form_cours)) loc_form_cours++;
        else if (char_is_whitespace(*loc_str_cours)) loc_str_cours++;
        else if ((*loc_form_cours)==(*loc_str_cours))
        {
            loc_form_cours++;
            loc_str_cours++;
        }
        else   loc_form_cours = NULL;          //EOF??  //if strings before % in format and in str does not match
    }
    loc_str_cours=whitespace_romover(loc_str_cours);
    //printf("\n|||%d++++%s|||\n",*loc_str_cours,  loc_form_cours);
    *str_coursor = loc_str_cours;
    return loc_form_cours;
}




//dangerous parts:
//  %*l*u
//  %*5L3f
//  width (%10lu) --> 19-max 20-error reading but taking as much numbers as needed   --- check big numbers/negatives/zero
//  %*5Llf
//  %*5fd   or   %*5Ld
//  %lu     but     -12345
//  %d", a <float> ); --??
//  %1d     -12345          --> "-"??
//  %2d     -12345  --> "-1" || "-12"
//  does %ld || %hd effect how much numbers will be read?
//  %lu      num more that size_t ?? 
//  %u       num more that unsigned int ??
//  %o      --unsigned?!
//  %x && %x        for     0xa || 0xA || a || A
//  %2x         0xa || a
//  %1x         0xa || a
//  cientific notation (mantissa/exponent)   ==  10e10?
//  for presise are float and double
//  0.5   0.5e2=50    0.5E2=50     0.5e =0.5    0.5e2 (%fe2)=50   100  100.5
//  sscanf("%f %f %f", &num1, &num2);
//  sscanf("%f ", num1);
//  f==g==G==e==E ???? Decimal floating point or scientific notation (mantissa/exponent)
//  lc-? ls-?
            /*
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
//  wint_t char_from_line   char->wint_t ????????????
//  check some japaneses and other symbols


//  really??
            /*
            The %s format specifier in sscanf will read characters from the input string str until it encounters 
            a whitespace character (space, tab, newline, etc.) or until it reaches the end of the string.

            0-32
            or
            0,9,10,11,12,13,32      --  checked!!!
            */
//  %7G --\t %3lc
//  in format: does not matter: 0-32    or  0,9,10,11,12,13,32
//  errors in writing into veriables
//  %p  0x7ffdd251f78c  || 7ffdd251f78c     || 0XFFFFFFFFFFFF //0xFFFFFFFFFFFFFFFF
//  0x7ffdd251f78c  || 7ffdd251f78c ||  f78c  ==> 0x7ffdd251f78c || 0x7ffdd251f78c || 0xf78c
//  %lp     --?
//  %ln ||  %5n
//  %n ==>sscanf=?
//  %%  !!!
//  %i     010 || 10 || 0x10 || 10A || -010 || -0X10 || -10 ||10a
//  %*n
//  %   (SPACE)
//  e-6         %f
//  .5          %f
//  -0x5 %3x
//  -a6  %3x
//  -g     %3x  
