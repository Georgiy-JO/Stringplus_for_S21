#include <stdio.h> 
#include "s21_string.h"

int main(){
	char buffer[50] = {'\0'};
	char buffer2[50] = {'\0'};
	char c = 'l'; //c 
	int digit = 34; //d i g G o u x X
	float fdigit = 21.212121; //e E f
	float fdigit2 = 21; //e E f
	float fdigit3 = 0.000001; //e E f
	char* str = "hello"; //s
	int *ptr = &digit; //p
	//n
	//%
	s21_sprintf(buffer, "hello %d %d char is %c", digit, (int)fdigit, c);
	sprintf(buffer2, "hello %d %d char is %c", digit, (int)fdigit, c);
	printf("%s", buffer);
	printf("\n----\n");
	printf("%s\n", buffer2);
	return 0;
}
