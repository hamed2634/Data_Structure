#include "stack.h"

void Initialize_Stack(Stack* ps){
	ps->top = NULL;
	ps->size = 0;
}

void Push(Stack* ps, StackEntry val){
	StackNode* pn = (StackNode*) malloc(sizeof(StackNode));
	pn->entry = val;
	pn->next = ps->top;
	ps->top = pn; 
	ps->size++;
}

int Stack_Full(Stack* ps){
	return 0;
}

void Pop(StackEntry *pe,Stack* ps){
	*pe = ps->top->entry;
	StackNode* pn = ps->top;
	ps->top = ps->top->next;
	free(pn);
	ps->size--;
}

int Stack_Empty(Stack* ps){
	return ps->top == NULL;
}

int Stack_Size(Stack* ps){
	return ps->size;
}

void Clear_Stack(Stack* ps){
	for(StackNode* pn = ps->top; pn;pn = pn->next)
	{
		free(pn);
		ps->top = pn;
	}
	ps->size = 0;
}


StackEntry Top(Stack* ps){
	return ps->top->entry;
}

void display(StackEntry val,int index){
	printf("Element %d = %d\n",index,val); 
}

void Traverse_Stack(Stack* ps, void(*pf)(StackEntry val, int index)){
	StackNode* pn = ps-> top;
	for(int i = 1; pn; pn = pn->next, i++){
		(*pf)(pn->entry,i);
	}
}
