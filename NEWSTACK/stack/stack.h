#ifndef STACK_H
#define STACK_H

	#include "..\.\lib\lib.h"
	#define LIMITED_MEMORY
#ifdef LIMITED_MEMORY
	typedef int StackEntry ;
	
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
	
	typedef int StackEntry ;
	typedef struct Stack{
		StackEntry top;
		StackEntry entry[MAX_SIZE];
	}Stack;
	
#endif
	void Initialize_Stack(Stack* );
	void Push(Stack* , StackEntry );
	int Stack_Full(Stack* );
	void Pop(StackEntry* ,Stack* );
	int Stack_Empty(Stack* );
	int Stack_Size(Stack* );
	StackEntry Top(Stack* );
	void Clear_Stack(Stack* );
	void display(StackEntry ,int );
	void Traverse_Stack(Stack* ps, void(*pf)(StackEntry ,int ));
	
#endif