#include <stdio.h> 
#include "s21_string.h"

int main(){
	char buffer[500] = {'\0'};
	char buffer2[500] = {'\0'};
	char c = 'l'; //c 
	int digit = 344; //d i g G o u x X
	int digit2 = -344; //d i g G o u x X
	int udigit = -34; //d i g G o u x X
	float fdigit = -21.2100210012120021312; //e E f
	float fdigit2 = 21.111111; //e E f
	float fdigit3 = -0.000001; //e E f
	char* str = "hello"; //s
	int *ptr = &digit; //p
	//n
	//%
	int s21_count = 0; 
	int count = 0; 
	//s21_count = s21_sprintf(buffer, "---\n%%%% hel%%lo %-40.10d %8.4d\nchar is %c\nfloat is %f |%+-20.10f| %f\nstr is %s%s\n%40.20u\n%d", digit, (int)fdigit, c, fdigit, fdigit2, fdigit3, str, str, udigit);
	//count = sprintf(buffer2, "---\n%%%% hel%%lo %-40.10d %8.4d\nchar is %c\nfloat is %f |%+-20.10f| %f\nstr is %s%s\n%40.20u\n%d", digit, (int)fdigit, c, fdigit, fdigit2, fdigit3, str, str, udigit);
	s21_count = s21_sprintf(buffer, "%d %d\n%10d %10d\n%-10d %-10d\n%.10d %.10d\n%-.10d %-.10d\n%8.10d %8.10d\n%-8.10d %-8.10d\n%10.8d %10.8d\n%-10.8d %-10.8d\n", digit, digit2, digit, digit2, digit, digit2, digit, digit2, digit, digit2, digit, digit2, digit, digit2, digit, digit2, digit, digit2);
	count = sprintf(buffer2, "%d %d\n%10d %10d\n%-10d %-10d\n%.10d %.10d\n%-.10d %-.10d\n%8.10d %8.10d\n%-8.10d %-8.10d\n%10.8d %10.8d\n%-10.8d %-10.8d\n", digit, digit2, digit, digit2, digit, digit2, digit, digit2, digit, digit2, digit, digit2, digit, digit2, digit, digit2, digit, digit2);
	printf("%s", buffer);
	printf("\n----\n");
	printf("%s\n", buffer2);
	printf("%d %d\n", s21_count, count);
	return 0;
}
