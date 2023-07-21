#ifndef STACK_H
#define STACK_H

	#include "..\.\lib\lib.h"
	//#define LIMITED_MEMORY
#ifdef LIMITED_MEMORY
	typedef char StackEntry ;
	
	typedef struct StackNode{
		StackEntry entry;
		struct StackNode* next;
	}StackNode;
		
	
	typedef struct Stack{
		StackNode* top;
		int size;
	}Stack;
#else 
	#define MAX_SIZE 1000
	
	typedef char StackEntry ;
	typedef struct Stack{
		StackEntry top;
		StackEntry entry[MAX_SIZE];
	}Stack;
	
#endif
	void Initialize_Stack(Stack* ps);
	void Push(Stack* ps, StackEntry val);
	int Stack_Full(Stack* ps);
	void Pop(StackEntry *e,Stack* ps);
	int Stack_Empty(Stack* ps);
	int Stack_Size(Stack* ps);
	StackEntry Top(Stack* ps);
	void Clear_Stack(Stack* ps);
	void display(StackEntry val,int index);
	void Traverse_Stack(Stack* ps, void(*pf)(StackEntry val,int index));
	
#endif