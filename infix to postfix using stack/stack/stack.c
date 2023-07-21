#include "stack.h"

#ifdef LIMITED_MEMORY
	
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
	StackNode* pn = ps->top;
	while(pn){
		pn = pn->next;
		free(ps->top);
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
#else 
	
void Initialize_Stack(Stack* ps){
	ps->top = 0;
}

void Push(Stack* ps, StackEntry val){
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

void display(StackEntry val, int index){
	printf("Element %d = %d\n",index,val); 
}

void Traverse_Stack(Stack* ps, void(*pf)(StackEntry val, int index)){
	for(int i = ps->top, j = 1; i > 0;i--,j++){
		(*pf)(ps->entry[i - 1],j);
	}
}

#endif
