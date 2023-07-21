#ifndef STACK_H
#define STACK_H
	#include "..\.\lib\lib.h"
	
	
	typedef int StackEntry ;
	
	typedef struct StackNode{
		StackEntry entry;
		struct StackNode* next;
	}StackNode;
		
	
	typedef struct Stack{
		StackNode* top;
		int size;
	}Stack;
	
	void Initialize_Stack(Stack* ps);
	void Push(Stack* ps, StackEntry val);
	int Stack_Full(Stack* ps);
	void Pop(StackEntry *e,Stack* ps);
	int Stack_Empty(Stack* ps);
	int Stack_Size(Stack* ps);
	StackEntry Top(Stack* ps);
	void Clear_Stack(Stack* ps);
	void display(StackEntry val,int index);
	void Traverse_Stack(Stack* ps, void(*pf)(int val,int index));
	
#endif