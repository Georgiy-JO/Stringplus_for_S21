#include <stdio.h> 
#include "s21_string.h"

int main(){
	char buffer[500] = {'\0'};
	char buffer2[500] = {'\0'};
	char c = 'l'; //c 
	wint_t* wc1 = L"ツ"; //c 
	wint_t* wc2 = L"\u30c4"; //c 
	wchar_t wstr1[] = L"Hello world!";
	wchar_t wstr2[] = L"ツツツツツツ";
	int digit = -344; //d i g G o u x X
	int udigit = -34; //d i g G o u x X
	float fdigit = -21.2100210012120021312; //e E f
	float fdigit2 = 21.111111; //e E f
	float fdigit3 = -0.000001; //e E f
	char* str = "hello"; //s
	int *ptr = &digit; //p
	//n
	//%
	//s21_sprintf(buffer, "s21_sprintf---\n%%%% hel%%lo %-40.10d %8.4d\nchar is %c\nfloat is %f |%+-20.10f| %f\nstr is %s%s\n%u", digit, (int)fdigit, c, fdigit, fdigit2, fdigit3, str, str, udigit);
//	sprintf(buffer2, "sprintf---\n%%%% hel%%lo %-40.10d %8.4d\nchar is %c\nfloat is %f |%+-20.10f| %f\nstr is %s%s\n%u\nwchar1 = %lc\nwchar2 = %lc\nwstring1 = %ls\nwstring2 = %ls\n", digit, (int)fdigit, c, fdigit, fdigit2, fdigit3, str, str, udigit, wc1, wc2, wstr1, wstr2);
	sprintf(buffer, " wchar1 = %lc\nwchar2 = %lc\nwstring1 = %ls\nwstring2 = %ls\n", wc1, wc2, wstr1, wstr2);
	sprintf(buffer2, " wchar1 = %lc\nwchar2 = %lc\nwstring1 = %ls\nwstring2 = %ls\n", wc1, wc2, wstr1, wstr2);
	printf("%s", buffer);
	printf("\n----\n");
	printf("%s\n", buffer2);


	for (int i = 0; i < 500; i++){
		printf("%c", buffer[i]);
	}
	printf("\n----\n");
	for (int i = 0; i < 500; i++){
		printf("%c", buffer2[i]);
	}
	printf("\n----\n");
	return 0;
}
