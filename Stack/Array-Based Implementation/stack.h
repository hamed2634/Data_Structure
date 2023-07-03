#ifndef STACK_H
	#include "..\.\lib\lib.h"
	
	#define MAX_SIZE 1000
	
	typedef int StackEntry ;
	typedef struct Stack{
		StackEntry top;
		StackEntry entry[MAX_SIZE];
	}Stack;
	
	void Initialize_Stack(Stack* ps);
	void Push(Stack* ps, StackEntry val);
	int Stack_Full(Stack* ps);
	void Pop(StackEntry *e,Stack* ps);
	int Stack_Empty(Stack* ps);
	int Stack_Size(Stack* ps);
	StackEntry Top(Stack* ps);
	void Clear_Stack(Stack* ps);
	void display(int val, int index);
	void Traverse_Stack(Stack* ps, void(*pf)(int val, int index));
	
#endif