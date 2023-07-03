#include "lib.h"

char* takestring_v2(){
    char* s = (char *)calloc(1,sizeof(char));
    int len = 1;
    *s = '\0';
    char t;
    t = getchar();
    int c = 1;
    while(t != '\n'){
        if(c == len)
        {
            s = (char *)realloc(s, (2 * len) * sizeof(char));
            len = 2 * len;
        }
        *(s + c - 1) = t;
        *(s + c) = '\0';
        c++;
        t = getchar();
    }
	fflush(stdin);
	if(len == 1)  return takestring_v2();
	if(*s == ' ') {
		printf("Cannot Start With Spaces!\nEnter Again: ");
		return takestring_v2();
	}

    return s;
}

int string_to_int(char* string_num){
	long long num = 0, temp = 0, neg = 0;
	for(int i = 0; i < strlen(string_num); i++)
	{
		if(i == 0 && string_num[0] == '-'){
			neg = 1;
			continue;
		}	
		if(!isdigit(string_num[i])) return -1;
		temp *= 10;
		if(temp < num) return -1;
		temp += string_num[i] - '0';
		if(temp < num) return -1;
		num = temp;
	}
	if(num > INT_MAX) return -1;
	if(neg) num *= -1;
	return (int)num;
}