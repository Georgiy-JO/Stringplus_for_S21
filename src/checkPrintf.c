#include <stdio.h> 
#include "s21_string.h"

int main(){
	char buffer[500] = {'\0'};
	char buffer2[500] = {'\0'};
	char c = 'l'; //c 
	int digit = 34; //d i g G o u x X
	float fdigit = 21.2100210012120021312; //e E f
	float fdigit2 = 21.111111; //e E f
	float fdigit3 = 0.000001; //e E f
	char* str = "hello"; //s
	int *ptr = &digit; //p
	//n
	//%
	s21_sprintf(buffer, "s21_sprintf---\nhello %d %d\nchar is %c\nfloat is %f %.10f %f\nstr is %s%s\n", digit, (int)fdigit, c, fdigit, fdigit2, fdigit3, str, str);
	sprintf(buffer2, "s21_sprintf---\nhello %d %d\nchar is %c\nfloat is %f %.10f %f\nstr is %s%s\n", digit, (int)fdigit, c, fdigit, fdigit2, fdigit3, str, str);
	printf("%s", buffer);
	printf("\n----\n");
	printf("%s\n", buffer2);
	return 0;
}
