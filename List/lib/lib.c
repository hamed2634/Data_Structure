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




//convert string to int 
//return Error1 if the string consist of things other numbers
//return Error2 if the number overflowed

Error string_to_int(char* string_num,int* out){
	long long num = 0, temp = 0, neg = 0;
	for(int i = 0; i < strlen(string_num); i++)
	{
		if(i == 0 && string_num[0] == '-'){
			neg = 1;
			continue;
		}	
		if(!isdigit(string_num[i])) return Error1;
		temp *= 10;
		if(temp < num) return Error2;
		temp += string_num[i] - '0';
		if(temp < num) return Error2;
		num = temp;
	}
	if(num > INT_MAX) return Error2;
	if(neg) num *= -1;
	
	*out = num;
	
	return Valid;
}

//asks user to enter a valid number in specific number of tries
//return Error1 if user ran out of tries
Error getnumber(char* message, int tries, int* out){
	int num = invalid;
	printf("\n%s",message);
	Error state;
	if(tries == infinite){
		while(true){
			state = string_to_int(takestring_v2(), &num);
			if(state == Error1) printf("Invalid Input... \"MAKE SURE THAT THE NUMBER CONSISTS OF DIGITS ONLY!\"\n\n%s",message);
			else if(state == Error2) printf("Invalid Input... \"MAKE SURE THAT THE NUMBER ISN'T HUGE!\"\n\n%s",message);
			else break;
		}
	}
	else{
		
		while(tries--){
			state = string_to_int(takestring_v2(), &num);
			if(state == Error1) printf("Invalid Input... \"MAKE SURE THAT THE NUMBER CONSISTS OF DIGITS ONLY!\"\n");
			else if(state == Error2) printf("Invalid Input... \"MAKE SURE THAT THE NUMBER ISN'T HUGE!\"\n");
			else break;
			if(tries) printf("You Have %d More Tries!\n\n%s",tries,message);
		}
	}
	
	if(num == invalid) return Error1;
	
	*out = num;
	return Valid;
}