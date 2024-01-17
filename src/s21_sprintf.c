#include "s21_string.h"
#include "stdarg.h"

#define S21_SPRINTF_FLAGS "-+ #0"
#define S21_SPRINTF_WIDTH "0123456789*"
#define S21_SPRINTF_ACCURACY "0123456789*"
#define S21_SPRINTF_LENGTH "hlL"
#define S21_SPRINTF_SPEC "cdieEfgGosuxXpn"
#define S21_SPRINTF_DIGITS "0123456789"

int is_start(char ch){
	return ch == '%' ? 1 : 0;
}
int count_percent_signs(const char* format){
	int len = s21_strlen(format);
	int count = 0;
	for (int i = 0; i < len; i++){
		if (format[i] == '%') count++;
	}
	return count;
}
int is_flag(char ch){
	return s21_strchr(S21_SPRINTF_FLAGS, ch) != NULL ? 1 : 0;
}
int is_width(char ch){
	return s21_strchr(S21_SPRINTF_WIDTH, ch) != NULL ? 1 : 0;
}
int is_accuracy_dot(char ch){
	return s21_strchr(".", ch) != NULL ? 1 : 0;
}
int is_accuracy(char ch){
	return s21_strchr(S21_SPRINTF_ACCURACY, ch) != NULL ? 1 : 0;
}
int is_length(char ch){
	return s21_strchr(S21_SPRINTF_LENGTH, ch) != NULL ? 1 : 0;
}
int is_spec(char ch){
	return s21_strchr(S21_SPRINTF_SPEC, ch) != NULL ? 1 : 0;
}
int is_digit(char ch){
	return s21_strchr(S21_SPRINTF_DIGITS, ch) != NULL ? 1 : 0;
}
int is_width(char ch){
	return s21_strchr(S21_SPRINTF_WIDTH, ch) != NULL ? 1 : 0;
}

char* get_flag(char ch){
	return s21_strchr(S21_SPRINTF_FLAGS, ch);
}

char* get_length(char ch){
	return s21_strchr(S21_SPRINTF_LENGTH, ch);
}

char* get_spec(char ch){
	return s21_strchr(S21_SPRINTF_SPEC, ch);
}
int convert_digit_char_to_int(char ch){
	return ch - '0';
}

// c d i e E f g G  o s u x X p n  [spec]
// - + ' ' # 0 [flags]
// (digit)  * [width]
// .(digit) .* [accuracy]
// h l L [length]

// %[flags][width][.accuracy][length][spec]

typedef struct opts {
	//specs
	char spec_c;
	char spec_d;
	char spec_i;
	char spec_e;
	char spec_E;
	char spec_f;
	char spec_g;
	char spec_G;
	char spec_o;
	char spec_s;
	char spec_u;
	char spec_x;
	char spec_X;
	char spec_p;
	char spec_n;

	//flags
	char flag_minus;
	char flag_plus;
	char flag_space;
	char flag_hash;
	char flag_zero;

	//width
	int width_digit;
	char width_any;

	//accuracy
	int accuracy_digit;
	char accuracy_any;

	//length
	char length_h;
	char length_l;
	char length_L;
} opts;

int flag_to_struct(opts* optarg, char ch){
	int status = 0;
	opts localoptarg = *optarg;
	switch (ch){
		case '-':
			localoptarg.flag_minus = 1;
			break;
		case '+':
			localoptarg.flag_plus = 1;
			break;
		case ' ':
			localoptarg.flag_space = 1;
			break;
		case '#':
			localoptarg.flag_hash = 1;
			break;
		case '0':
			localoptarg.flag_zero = 1;
			break;
		default:
			status = -1;
	}
	*optarg = localoptarg;
	return status;
}

int length_to_struct(opts* optarg, char ch){
	int status = 0;
	opts localoptarg = *optarg;
	switch (ch){
		case 'h':
			localoptarg.length_h = 1;
			break;
		case 'l':
			localoptarg.length_l = 1;
			break;
		case 'L':
			localoptarg.length_L = 1;
			break;
		default:
			status = -1;
	}
	*optarg = localoptarg;
	return status;
}

int spec_to_struct(opts* optarg, char ch){
	int status = 0;
	opts localoptarg = *optarg;
	switch (ch){
		case 'c':
			localoptarg.spec_c = 1;
			break;
		case 'd':
			localoptarg.spec_d = 1;
			break;
		case 'i':
			localoptarg.spec_i = 1;
			break;
		case 'e':
			localoptarg.spec_e = 1;
			break;
		case 'E':
			localoptarg.spec_E = 1;
			break;
		case 'f':
			localoptarg.spec_f = 1;
			break;
		case 'g':
			localoptarg.spec_g = 1;
			break;
		case 'G':
			localoptarg.spec_G = 1;
			break;
		case 'o':
			localoptarg.spec_o = 1;
			break;
		case 's':
			localoptarg.spec_s = 1;
			break;
		case 'u':
			localoptarg.spec_u = 1;
			break;
		case 'x':
			localoptarg.spec_x = 1;
			break;
		case 'X':
			localoptarg.spec_X = 1;
			break;
		case 'p':
			localoptarg.spec_p = 1;
			break;
		case 'n':
			localoptarg.spec_n = 1;
			break;
		default:
			status = -1;
	}
	*optarg = localoptarg;
	return status;
}

int width_digit_to_struct(opts* optarg, int digit){
	int status = 0;
	opts localoptarg = *optarg;
	localoptarg.width_digit = digit;
	*optarg = localoptarg;
	return status;
}

int accuracy_digit_to_struct(opts* optarg, int digit){
	int status = 0;
	opts localoptarg = *optarg;
	localoptarg.accuracy_digit = digit;
	*optarg = localoptarg;
	return status;
}

int get_full_number(const char *format, int *number){
	int offset = 0;
	int localnumber = 0;
	int digit = 0;
	while(is_digit(format[offset])){
		digit = convert_digit_char_to_int(format[offset]);
		localnumber = localnumber * 10 + digit;
		offset++;
	}
	*number = localnumber;
	return offset;
}

int get_opts(opts* optarg, const char* format){
	int offset = 0;
	char* ptrch = NULL;
	int number = 0;
	opts localoptarg = *optarg;
	//flags
	while(is_flag(format[offset])){
		ptrch = get_flag(format[offset]);
		flag_to_struct(localoptarg, *ptrch);
		offset++;
	}
	//width
	if(is_width(format[offset])){
		if (is_digit(format[offset])){
			offset += get_full_number(format[offset], &number);
			width_digit_to_struct(localoptarg, number);
		}else {
			localoptarg.width_any = 1;
			offset++;
		}
	}
	//accuracy
	if(is_accuracy_dot(format[offset])){
		offset++;
		if (is_accuracy(format[offset])){
			if (is_digit(format[offset])){
				offset += get_full_number(format[offset], &number);
				accuracy_digit_to_struct(localoptarg, number);
			} else {
				localoptarg.accuracy_any = 1;
				offset++;
			}
		}
	}
	//length
	if(is_length(format[offset])){
		ptrch = get_length(format[offset]);
		length_to_struct(localoptarg, *ptrch);
		offset++;
	}
	//spec
	if(is_spec(format[offset])){
		ptrch = get_spec(format[offset]);
		spec_to_struct(localoptarg, *ptrch);
		offset++;
	}
	//end of options for single variable
	
	*optarg = localoptarg;
	return offset;
}

int print_char(char argchar, char* str){
	*str = argchar;
	return 1;
}

int print(va_list args, opts opt, char* str, int offset){
	if (opt.spec_c) {
		char argchar = va_arg(args, char);
		offset += print_char(argchar, &(str[offset]));
	}
	if (opt.spec_d){
		int argint = va_arg(args, int);
	}
	if (opt.spec_f){
		float argfloat = va_arg(args, float);
	}
	return 0;
}

int s21_sprintf(char *str, const char *format, ...){
	int count = 0;
	if(str == NULL){
		return -1;
	}
	int num_args = count_percent_signs(format);
	va_list args;
	va_start(args, num_args);
	int len = s21_strlen(format);
	for (int i = 0; i < len;){
		opts opt = {0};
		if (is_start(format[i])){
			i++;
			i += get_opts(opt, format[i]);
			print(args, opt, str, i);
		} else {
			str[i] = format[i];
			i++;
		}
		count++;
	}
	va_end(args);
	return count;
}

