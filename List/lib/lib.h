#ifndef LIB_H
#define LIB_H

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <ctype.h> 
	#include <limits.h>

	#define invalid INT_MIN
	#define infinite INT_MAX
	
	enum Bool {false, true};
	
	typedef enum {
    Valid,
    Error1,
    Error2,
    Error3,
    Error4,
    Error5,
    Error6
	} Error;
	
	char* takestring_v2();
	Error string_to_int(char* ,int* );
	Error getnumber(char* , int , int* );
#endif	
