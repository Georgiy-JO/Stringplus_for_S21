#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle)
{
	unsigned char* ptr = NULL;
	unsigned char* haystackorig = (unsigned char*)haystack;
	unsigned char* needleorig = (unsigned char*)needle;
	unsigned char* haystacktmp = (unsigned char*)haystack;
	unsigned char* needletmp = (unsigned char*)needle;
	int status = 0;
	while(*haystackorig != '\0'){
		haystacktmp = haystackorig;
		needletmp = needleorig;
		status = 1;
		while(*haystacktmp != '\0' && status){
			if (*haystacktmp != *needletmp){
				status = 0;
			}
			else
			{
				haystacktmp++;
				needletmp++;
			}
		}
		if (status == 1) ptr = haystackorig;
		haystackorig++;	
	}
	return (char*)ptr;
}
