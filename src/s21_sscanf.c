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

#ifndef EOF
#define EOF (-1)        
#endif
                    //EOF??         https://www.tutorialspoint.com/c_standard_library/c_function_sscanf.htm
#define ERROR (-1)

typedef struct variables
{
    // char spec_type; //i-int, f-float, c-char, s-spesial
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
        for(size_t i=0;i<var_amount && *str_coursor!=C_ZERO && format_coursor!=NULL; zero_struct(&var_spec)){
            //printf("\n1)$$%s$$%s$$\n",str_coursor, format_coursor );
            if(*format_coursor!=S21_SSCANF_PERCENT) {
                format_coursor = string_cutter(&str_coursor,format_coursor);    //??format_coursor==NULL    --different lines in format and str
            }
            else{
                i++;
                format_coursor=spec_translator(&var_spec, (format_coursor+1));      //???format_coursor==NULL         --spec error
                if(format_coursor!=NULL ){
                    str_coursor=var_filling(&var, var_spec, str_coursor);
                    if(str_coursor!=NULL)   var_number++;                       //????str_coursor!=NULL           --reading/wrighting var error?

                }
  
            }
            //printf("\n2)$$%s$$%s$$\n",str_coursor, format_coursor );
        }
        va_end(var);         
    }
    return var_number;
}

void zero_struct(variables * var){
    var->skip=0;
    var->spec=C_ZERO;
    var->length=C_ZERO;
    var->width=0;
}
char char_is_invis (const char tmp){
    return ((tmp<=32 && tmp>=1) || tmp==127)? 1:0;
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

size_t var_counting (const char *format){
    size_t amount=0;
    for(int i=0;format[i]!=C_ZERO;i++){
        if(format[i]==S21_SSCANF_PERCENT)
            amount++;
    }
    return amount;
}

unsigned int uint_from_line(const char* line, size_t* move){
    unsigned int local_num=0;
    size_t local_move=0;
    for(;char_is_num (*(line+local_move))&&(local_move < (*move) || (*move)==0);local_move++){
        local_num=local_num*10+char_to_num(*(line+local_move));
    }
    if(*move==0)  *move=local_move;
    return local_num;
}
size_t ulong_from_line(const char* line, size_t* move){
    size_t local_num=0;
    size_t local_move=0;
    for(;char_is_num (*(line+local_move))&&(local_move < (*move) || (*move)==0);local_move++){
        local_num=local_num*10+char_to_num(*(line+local_move));
    }
    if(*move==0)  *move=local_move;
    return local_num;
}
unsigned short ushort_from_line(const char* line, size_t* move){
    unsigned short local_num=0;
    size_t local_move=0;
    for(;char_is_num (*(line+local_move))&&(local_move < (*move) || (*move)==0);local_move++){
        local_num=local_num*10+char_to_num(*(line+local_move));
    }
    if(*move==0)  *move=local_move;
    return local_num;
}
int int_from_line(const char* line, size_t* move){
    int local_num=0;
    size_t local_move=0;
    int neg_flag=1;
    if(*line=='-'){
        local_move++;
        neg_flag=-1;
    }
    for(;char_is_num (*(line+local_move))&&(local_move < (*move) || (*move)==0);local_move++){
        local_num=local_num*10+char_to_num(*(line+local_move));
    }
    if(*move==0)  *move=local_move;
    return local_num*neg_flag;
}
long int long_from_line(const char* line, size_t* move){
    long int local_num=0;
    size_t local_move=0;
    int neg_flag=1;
    if(*line=='-'){
        local_move++;
        neg_flag=-1;
    }
    for(;char_is_num (*(line+local_move))&&(local_move < (*move) || (*move)==0);local_move++){
        local_num=local_num*10+char_to_num(*(line+local_move));
    }
    if(*move==0)  *move=local_move;
    return local_num*neg_flag;
}
short int short_from_line(const char* line, size_t* move){
    short int local_num=0;
    size_t local_move=0;
    int neg_flag=1;
    if(*line=='-'){
        local_move++;
        neg_flag=-1;
    }
    for(;char_is_num (*(line+local_move))&&(local_move < (*move) || (*move)==0);local_move++){
        local_num=local_num*10+char_to_num(*(line+local_move));
    }
    if(*move==0)  *move=local_move;
    return local_num*neg_flag;
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

//0.5   0.5e2=50    0.5E2=50     0.5e=0.5    0.5e2 (%fe2)=50   
float float_from_line(const char* line, size_t* move){
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
    if(*move==0)  *move=local_move;
    return local_num*neg_flag;
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
    }//float (eEfgG)
    else if (s21_isinstr(*loc_format,S21_SSCANF_FLOAT_SPEC)){
        if (var_spec->length==C_ZERO||s21_isinstr(var_spec->length,"L"))
        {
            var_spec->spec=*loc_format;
            loc_format++;
        }
        else                    loc_format=NULL;
    }
    

    //float (eEfgG)
    //spesial(pn)
    //char (cs)
    //error spec

    return loc_format;
}

//%ld max -> 9223372036854775807 %d max -> 1535817955

char* var_filling(va_list* var, variables var_spec, char* str_coursor)
{
    size_t move=var_spec.width;
    switch (var_spec.spec)
    {
    case 'u':
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
        break;
    case 'd':
        if(var_spec.length=='l'){
            long int* var_point=va_arg(*var,long int*);
            *var_point=long_from_line(str_coursor,&move);
        }else if (var_spec.length=='h'){
            short int* var_point=va_arg(*var,short int*);
            *var_point=short_from_line(str_coursor,&move);
        }else{
            int* var_point=va_arg(*var,int*);
            *var_point=int_from_line(str_coursor,&move);
        }
        break;
    case 'i':               //wtf is this peace of shit?!
        /* code */
        break;
    case 'o':       //? unsigned/signed
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
        break;
    case 'x':
    case 'X':
        if(var_spec.length=='l'){
            size_t* var_point=va_arg(*var,size_t*);
            *var_point=long_hex_from_line(str_coursor,&move);
        }else if (var_spec.length=='h'){
            unsigned short int* var_point=va_arg(*var,unsigned short int*);
            *var_point=short_hex_from_line(str_coursor,&move);
        }else{
            int* var_point=va_arg(*var,int*);
            *var_point=hex_from_line(str_coursor,&move);
        }
        break;
    
    default:
        /* code */
        break;
    }
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
       
        if(char_is_invis(*loc_form_cours)) loc_form_cours++;
        else if (char_is_invis(*loc_str_cours)) loc_str_cours++;
        else if ((*loc_form_cours)==(*loc_str_cours))
        {
            loc_form_cours++;
            loc_str_cours++;
        }
        else   loc_form_cours = NULL;          //EOF??  //if strings before % in format and in str does not match
    }
    for(;char_is_invis(*loc_str_cours);) {loc_str_cours++;}
    //printf("\n|||%d--%s|||\n",*loc_str_cours,  loc_form_cours);
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