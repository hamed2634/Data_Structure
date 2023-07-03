#include "stack.h"

void Initialize_Stack(Stack* ps){
	ps->top = 0;
}

void Push(Stack* ps, int val){
	ps->entry[ps->top++] = val; 
}

int Stack_Full(Stack* ps){
	return ps->top >= MAX_SIZE;
}

void Pop(StackEntry *e,Stack* ps){
	*e = ps->entry[(--ps->top)] ;
}

int Stack_Empty(Stack* ps){
	return !ps->top;
}

int Stack_Size(Stack* ps){
	return ps->top;
}

StackEntry Top(Stack* ps){
	return ps->entry[ps->top - 1] ;
}

void Clear_Stack(Stack* ps){
	ps->top = 0;
}

void display(int val, int index){
	printf("Element %d = %d\n",index,val); 
}

void Traverse_Stack(Stack* ps, void(*pf)(int val, int index)){
	for(int i = ps->top, j = 1; i > 0;i--,j++){
		(*pf)(ps->entry[i - 1],j);
	}
}
