#include <stdarg.h>

#include "s21_string.h"

#define S21_SPRINTF_FLAGS "-+ "
#define S21_SPRINTF_WIDTH "0123456789*"
#define S21_SPRINTF_ACCURACY "0123456789*"
#define S21_SPRINTF_LENGTH "hl"
#define S21_SPRINTF_SPEC "cdfsu"
#define S21_SPRINTF_DIGITS "0123456789"
#define S21_SPRINTF_DEFAULT_ACCURACY 6
#define S21_SPRINTF_DEFAULT_BUFFER_SIZE 4096

typedef struct opts {
  // specs
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

  // flags
  char flag_minus;
  char flag_plus;
  char flag_space;
  char flag_hash;
  char flag_zero;

  // width
  int width_digit;
  char width_any;

  // accuracy
  int accuracy_digit;
  char accuracy_any;

  // length
  char length_h;
  char length_l;
  char length_L;
} opts;

int is_start(char ch) { return ch == '%' ? 1 : 0; }

int is_flag(char ch) {
  return s21_strchr(S21_SPRINTF_FLAGS, ch) != NULL ? 1 : 0;
}

int is_width(char ch) {
  return s21_strchr(S21_SPRINTF_WIDTH, ch) != NULL ? 1 : 0;
}

int is_accuracy_dot(char ch) { return s21_strchr(".", ch) != NULL ? 1 : 0; }

int is_accuracy(char ch) {
  return s21_strchr(S21_SPRINTF_ACCURACY, ch) != NULL ? 1 : 0;
}

int is_length(char ch) {
  return s21_strchr(S21_SPRINTF_LENGTH, ch) != NULL ? 1 : 0;
}

int is_spec(char ch) {
  return s21_strchr(S21_SPRINTF_SPEC, ch) != NULL ? 1 : 0;
}

int is_digit(char ch) {
  return s21_strchr(S21_SPRINTF_DIGITS, ch) != NULL ? 1 : 0;
}

char* get_flag(char ch) { return s21_strchr(S21_SPRINTF_FLAGS, ch); }

char* get_length(char ch) { return s21_strchr(S21_SPRINTF_LENGTH, ch); }

char* get_spec(char ch) { return s21_strchr(S21_SPRINTF_SPEC, ch); }

int convert_digit_char_to_int(char ch) { return ch - '0'; }

int convert_digit_int_to_char(int integer) { return integer + '0'; }

long int s21_abs(long int integer) { return integer < 0 ? -integer : integer; }

double s21_fabs(double dbl) { return dbl < 0 ? -dbl : dbl; }

int get_digit_int_len(long int digit) {
  int len = 0;
  do {
    digit /= 10;
    len++;
  } while (digit);
  return len;
}

int get_digit_uint_len(unsigned long int digit) {
  int len = 0;
  do {
    digit /= 10;
    len++;
  } while (digit);
  return len;
}

int get_digit_sign(long int digit) { return digit < 0 ? -1 : 1; }

int fget_digit_sign(double digit) { return digit < 0 ? -1 : 1; }

int add_sign_to_str(char* str, int sign, opts opt) {
  int status = 0;
  if (sign < 0) {
    str[0] = '-';
    status = 1;
  }
  if (sign > 0) {
    if (opt.flag_plus) {
      str[0] = '+';
      status = 1;
    } else if (opt.flag_space) {
      str[0] = ' ';
      status = 1;
    }
  }
  return status;
}

int convert_digit_int_to_str(long int integer, char* str) {
  int digit_len = get_digit_int_len(integer);
  for (int i = 0; i < digit_len; i++) {
    int single_digit = integer % 10;
    integer /= 10;
    char single_digit_char = convert_digit_int_to_char(single_digit);
    str[digit_len - i - 1] = single_digit_char;
  }
  return 0;
}

int convert_digit_uint_to_str(unsigned long int integer, char* str) {
  int digit_len = get_digit_uint_len(integer);
  for (int i = 0; i < digit_len; i++) {
    int single_digit = integer % 10;
    integer /= 10;
    char single_digit_char = convert_digit_int_to_char(single_digit);
    str[digit_len - i - 1] = single_digit_char;
  }
  return 0;
}

int convert_digit_frational_part_to_str(double frac, int len, char* str) {
  for (int i = 0; i < len; i++) {
    double temp = frac * 10;
    int single_digit = (int)temp;
    frac = temp - single_digit;
    if (i == len - 1 && frac >= 0.5) single_digit++;
    char single_digit_char = convert_digit_int_to_char(single_digit);
    str[i] = single_digit_char;
  }
  return 0;
}

int flag_to_struct(opts* optarg, char ch) {
  int status = 0;
  opts localoptarg = *optarg;
  switch (ch) {
    case '-':
      localoptarg.flag_minus = 1;
      break;
    case '+':
      localoptarg.flag_plus = 1;
      break;
    case ' ':
      localoptarg.flag_space = 1;
      break;
  }
  *optarg = localoptarg;
  return status;
}

int length_to_struct(opts* optarg, char ch) {
  int status = 0;
  opts localoptarg = *optarg;
  switch (ch) {
    case 'h':
      localoptarg.length_h = 1;
      break;
    case 'l':
      localoptarg.length_l = 1;
      break;
  }
  *optarg = localoptarg;
  return status;
}

int spec_to_struct(opts* optarg, char ch) {
  int status = 0;
  opts localoptarg = *optarg;
  switch (ch) {
    case 'c':
      localoptarg.spec_c = 1;
      break;
    case 'd':
      localoptarg.spec_d = 1;
      break;
    case 'f':
      localoptarg.spec_f = 1;
      break;
    case 's':
      localoptarg.spec_s = 1;
      break;
    case 'u':
      localoptarg.spec_u = 1;
      break;
  }
  *optarg = localoptarg;
  return status;
}

int width_digit_to_struct(opts* optarg, int digit) {
  int status = 0;
  opts localoptarg = *optarg;
  localoptarg.width_digit = digit;
  *optarg = localoptarg;
  return status;
}

int accuracy_digit_to_struct(opts* optarg, int digit) {
  int status = 0;
  opts localoptarg = *optarg;
  localoptarg.accuracy_digit = digit;
  *optarg = localoptarg;
  return status;
}

int get_full_number(const char* format, int* number) {
  int offset = 0;
  int localnumber = 0;
  while (is_digit(format[offset])) {
    int digit = convert_digit_char_to_int(format[offset]);
    localnumber = localnumber * 10 + digit;
    offset++;
  }
  *number = localnumber;
  return offset;
}

int get_opts(opts* optarg, const char* format) {
  int offset = 0;
  char* ptrch = NULL;
  int number = 0;
  opts localoptarg = *optarg;
  // flags
  while (is_flag(format[offset])) {
    ptrch = get_flag(format[offset]);
    flag_to_struct(&localoptarg, *ptrch);
    offset++;
  }
  // width
  if (is_width(format[offset])) {
    if (is_digit(format[offset])) {
      offset += get_full_number(&(format[offset]), &number);
      width_digit_to_struct(&localoptarg, number);
    }
  }
  // accuracy
  if (is_accuracy_dot(format[offset])) {
    offset++;
	accuracy_digit_to_struct(&localoptarg, 0);
    if (is_accuracy(format[offset])) {
      if (is_digit(format[offset])) {
        offset += get_full_number(&(format[offset]), &number);
        accuracy_digit_to_struct(&localoptarg, number);
      }
    }
  }
  // length
  if (is_length(format[offset])) {
    ptrch = get_length(format[offset]);
    length_to_struct(&localoptarg, *ptrch);
    offset++;
  }
  // spec
  if (is_spec(format[offset])) {
    ptrch = get_spec(format[offset]);
    spec_to_struct(&localoptarg, *ptrch);
    offset++;
  }
  // end of options for single variable

  *optarg = localoptarg;
  return offset;
}

int print_char(char argchar, char* str, opts opt) {
  char str_buffer[S21_SPRINTF_DEFAULT_BUFFER_SIZE] = {'\0'};
  int width = opt.width_digit;
	if (width == 0) width = 1;

	s21_memset(str_buffer, ' ', width);
	if (!opt.flag_minus){
		str_buffer[width - 1] = argchar;
	}else {
		str_buffer[0] = argchar;
	}
  int copied_len = s21_strlen(str_buffer);
  str = s21_memset(str, 0, copied_len + 1);
  s21_strncpy(str, str_buffer, copied_len + 1);
  return copied_len;
}

int add_width_int(char* str, opts opt) {
  int width = opt.width_digit;
  for (int i = 0; i < width; i++) {
    str[i] = ' ';
  }
  return 0;
}

int print_str(char* argchar, char* str, opts opt) {
  char str_buffer[S21_SPRINTF_DEFAULT_BUFFER_SIZE] = {'\0'};
  char full_str_buffer[S21_SPRINTF_DEFAULT_BUFFER_SIZE] = {'\0'};
  int width = opt.width_digit;
  int str_len = s21_strlen(argchar);
  int accuracy = opt.accuracy_digit;
  if(accuracy != -1) if (accuracy < str_len) str_len = accuracy;
	s21_strncpy(full_str_buffer, argchar, str_len);

  int full_str_len = str_len;
  if (!opt.flag_minus) {
    add_width_int(str_buffer, opt);
    if (full_str_len > width) width = full_str_len;
    s21_strncpy(&(str_buffer[width - full_str_len]), full_str_buffer,
                full_str_len);
  } else {
    add_width_int(str_buffer, opt);
    s21_strncpy(str_buffer, full_str_buffer, full_str_len);
  }

  int copied_len = s21_strlen(str_buffer);
  str = s21_memset(str, 0, copied_len + 1);
  s21_strncpy(str, str_buffer, copied_len + 1);
  return copied_len;
}

int print_digit(long int argint, char* str, opts opt) {
  char integer_buffer[S21_SPRINTF_DEFAULT_BUFFER_SIZE] = {'\0'};
  char full_digit_buffer[S21_SPRINTF_DEFAULT_BUFFER_SIZE] = {'\0'};
  s21_memset(full_digit_buffer, '0', S21_SPRINTF_DEFAULT_BUFFER_SIZE - 1);
  int width = opt.width_digit;
  int digit_len = get_digit_int_len(argint);
  int accuracy = opt.accuracy_digit;
  if (accuracy < digit_len) accuracy = digit_len;

  int has_sign = 0;
  has_sign =
      add_sign_to_str(&(full_digit_buffer[0]), get_digit_sign(argint), opt);
  int digit_start_pos = 0;
  if (has_sign) digit_start_pos = 1;
  convert_digit_int_to_str(
      s21_abs(argint),
      &(full_digit_buffer[accuracy - digit_len + digit_start_pos]));

  int full_digit_len = accuracy + digit_start_pos;
  if (!opt.flag_minus) {
    add_width_int(integer_buffer, opt);
    if (full_digit_len > width) width = full_digit_len;
    s21_strncpy(&(integer_buffer[width - full_digit_len]), full_digit_buffer,
                full_digit_len);
  } else {
    add_width_int(integer_buffer, opt);
    s21_strncpy(integer_buffer, full_digit_buffer, full_digit_len);
  }

  int copied_len = s21_strlen(integer_buffer);
  str = s21_memset(str, 0, copied_len + 1);
  if (argint != 0 || opt.accuracy_digit != 0) s21_strncpy(str, integer_buffer, copied_len + 1);
  else copied_len = 0;
  return copied_len;
}

int print_udigit(unsigned long int arguint, char* str, opts opt) {
  char integer_buffer[S21_SPRINTF_DEFAULT_BUFFER_SIZE] = {'\0'};
  char full_digit_buffer[S21_SPRINTF_DEFAULT_BUFFER_SIZE] = {'\0'};
  s21_memset(full_digit_buffer, '0', S21_SPRINTF_DEFAULT_BUFFER_SIZE - 1);
  int offset = 0;
  int width = opt.width_digit;
  int digit_len = get_digit_uint_len(arguint);
  int accuracy = opt.accuracy_digit;
  if (accuracy < digit_len) accuracy = digit_len;
  if (accuracy > width) width = accuracy;

  offset += accuracy - digit_len;
  convert_digit_uint_to_str(arguint, &(full_digit_buffer[offset]));

  if (!opt.flag_minus) {
    add_width_int(integer_buffer, opt);
    s21_strncpy(&(integer_buffer[width - accuracy]), full_digit_buffer,
                accuracy);
  } else {
    add_width_int(integer_buffer, opt);
    s21_strncpy(integer_buffer, full_digit_buffer, accuracy);
  }

  int copied_len = s21_strlen(integer_buffer);
  str = s21_memset(str, 0, copied_len + 1);
  if (arguint != 0 || opt.accuracy_digit != 0) s21_strncpy(str, integer_buffer, copied_len + 1);
  return copied_len;
}

int print_float(double argfloat, int fractional_part_len, char* str, opts opt) {
  char float_buffer[S21_SPRINTF_DEFAULT_BUFFER_SIZE] = {'\0'};
  char float_fractional_buffer[S21_SPRINTF_DEFAULT_BUFFER_SIZE] = {'\0'};
  char final_buffer[S21_SPRINTF_DEFAULT_BUFFER_SIZE] = {'\0'};
  int offset = 0;
  add_width_int(final_buffer, opt);
  int width = opt.width_digit;
  int floor_len = get_digit_int_len((int)argfloat);
  int has_sign = 0;
  has_sign =
      add_sign_to_str(&(float_buffer[0]), fget_digit_sign(argfloat), opt);
  int digit_start_pos = 0;
  if (has_sign) digit_start_pos = 1;
  floor_len += digit_start_pos;
  double fract = s21_fabs(argfloat) - (int)s21_fabs(argfloat);
  if (fractional_part_len == 0 &&  fract > 0.5) {
	  if (argfloat < 0) argfloat-=1;
	  if (argfloat > 0) argfloat+=1;
  }
  convert_digit_int_to_str((int)s21_fabs(argfloat),
                           &(float_buffer[digit_start_pos]));
  convert_digit_frational_part_to_str(fract, fractional_part_len,
                                      float_fractional_buffer);

  if (!opt.flag_minus) {
    if (width > floor_len + fractional_part_len) {
      offset = width - (floor_len + fractional_part_len) - 1;
    }
  }

  s21_strncpy(&(final_buffer[offset]), float_buffer, floor_len);
  if (fractional_part_len != 0){
	  s21_strncpy(&(final_buffer[offset + floor_len]), ".", 1);
	  s21_strncpy(&(final_buffer[offset + floor_len + 1]), float_fractional_buffer,
			  fractional_part_len);
  }
  int copied_len = s21_strlen(final_buffer);
  str = s21_memset(str, 0, copied_len + 1);
  s21_strncpy(str, final_buffer, copied_len + 1);
  return copied_len;
}

int print(va_list args, opts opt, char* str) {
  int offset = 0;
  if (opt.spec_c) {
    char argchar = (char)va_arg(args, int);
    offset += print_char(argchar, str, opt);
  } else if (opt.spec_d) {
    long int argint = va_arg(args, long int);
    if (opt.length_h) {
      offset += print_digit((short int)argint, str, opt);
    } else if (opt.length_l) {
      offset += print_digit(argint, str, opt);
    } else {
      offset += print_digit((int)argint, str, opt);
    }
  } else if (opt.spec_f) {
    float argfloat = va_arg(args, double);
    int accuracy = S21_SPRINTF_DEFAULT_ACCURACY;
    if (opt.accuracy_digit != -1) accuracy = opt.accuracy_digit;
    offset += print_float(argfloat, accuracy, str, opt);
  } else if (opt.spec_s) {
    char* argstr = va_arg(args, char*);
    offset += print_str(argstr, str, opt);
  } else if (opt.spec_u) {
    unsigned long int arguint = (unsigned long int)va_arg(args, long int);
    if (opt.length_h) {
      offset += print_udigit((unsigned short int)arguint, str, opt);
    } else if (opt.length_l) {
      offset += print_udigit(arguint, str, opt);
    } else {
      offset += print_udigit((unsigned int)arguint, str, opt);
    }
  }
  return offset;
}

int print_percentage_char(char* str) {
  int offset = 0;
  *str = '%';
  offset++;
  return offset;
}

int s21_sprintf(char* str, const char* format, ...) {
  int count = 0;
  va_list args;
  va_start(args, format);
  int len = s21_strlen(format);
  int str_index = 0;
  for (int format_index = 0; format_index < len;) {
    opts opt = {0};
	opt.accuracy_digit = -1;
    if (is_start(format[format_index])) {
      format_index++;
      if (is_start(format[format_index])) {
        str_index += print_percentage_char(&(str[str_index]));
        format_index++;
      } else {
        format_index += get_opts(&opt, &(format[format_index]));
        str_index += print(args, opt, &(str[str_index]));
      }
    } else {
      str[str_index] = format[format_index];
      format_index++;
      str_index++;
    }
  }
  count = str_index;
  va_end(args);
  return count;
}
