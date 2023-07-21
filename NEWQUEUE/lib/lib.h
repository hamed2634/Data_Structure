#ifndef LIB_H
#define LIB_H
	#define PROGRAM_H
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <ctype.h> 
	#include <limits.h>

	#define invalid INT_MIN
	#define infinite INT_MAX
	
	char* takestring_v2();
	int string_to_int(char* string_num);
	int getnumber(char* message, int tries);
#endif	
