#include "List.h"

#ifdef LIMITED_MEMORY

Error Initialize_List(List* pl){
	pl->head = NULL;
	pl->size = 0;
	return Valid;
}


Error Insert(int index, ListEntry val, List* pl){
	if(index > pl->size || index < 0) return Error1;
	
	ListNode* pn = pl->head;
	for(int i = 0; i < index - 1; i++)
		pn = pn->next;
	
	
	ListNode* newpn = (ListNode *) malloc(sizeof(ListNode));
	if(newpn == NULL) return Error3;
	
	newpn->entry = val;

	if(index){
		newpn->next = pn->next;
		pn->next = newpn;
	}
	else{
		newpn->next = pl->head;
		pl->head = newpn;
	}
	pl->size++;
	return Valid;
	
}

Error Delete(int index, ListEntry* val,List* pl){
	if(index > pl->size - 1 || index < 0) return Error1;
	
	ListNode* pn = pl->head;
	for(int i = 0; i < index - 1; i++)
		pn = pn->next;
	
	if(index){
		ListNode* tmpnode = pn->next;
		pn->next = pn->next->next;
		free(tmpnode);
	}
	else{
		pl->head = pl-> head->next;
		free(pn);
	}
	pl->size--;
	
	return Valid;
}

Error Get(int index, ListEntry* val, List* pl){
	if(index > pl->size - 1 || index < 0) return Error1;
	
	ListNode* pn = pl->head;
	for(int i = 0; i < index; i++)
		pn = pn->next;
	*val = pn->entry;
	return Valid;
}

Error Replace(int index, ListEntry val, List* pl){
	if(index > pl->size - 1 || index < 0) return Error1;
	ListNode* pn = pl->head;
	for(int i = 0; i < index; i++)
		pn = pn->next;
	pn->entry = val;
	return Valid;
}

int List_Full(List* pl){
	return false;
}

int List_Empty(List* pl){
	return !pl->size;
}
int List_Size(List* pl){
	return pl->size;
}

void Destroy_List(List* pl){
	ListNode* pn = pl->head;
	while(pn = pn->next){
		free(pl->head);
		pl->head = pn;
	}

	pl->size = 0;
}

void display(ListEntry val, int index){
	printf("Element %d = %d\n",index,val.intger); 
}

void Traverse_List(List* pl, void(*pf)(ListEntry val, int index)){
	ListNode* pn = pl->head;
	for(int i = 0; i < pl->size ;i++){
		(*pf)(pn->entry,i + 1);
		pn = pn->next;
	}
}

#else
	
Error Initialize_List(List* pl){
	pl->size = 0;
	return Valid;
}


Error Insert(int index, ListEntry val, List* pl){
	if(index > pl->size || index < 0) return Error1;
	if(pl->size == MAX_SIZE) return Error2;
	
	pl->size++;
	for(int i = pl->size - 1; i > index;i--)
		pl->entry[i] = pl->entry[i - 1];
	pl->entry[index] = val;

	return Valid;
	
}

Error Delete(int index, ListEntry* val,List* pl){
	if(index > pl->size - 1 || index < 0) return Error1;
	
	*val = pl->entry[index];
	pl->size--;
	while(index < pl->size){
		pl->entry[index] = pl->entry[index + 1];
		index++;
	}
	return Valid;
}

Error Get(int index, ListEntry* val, List* pl){
	if(index > pl->size - 1 || index < 0) return Error1;
	*val = pl->entry[index];
	return Valid;
}

Error Replace(int index, ListEntry val, List* pl){
	if(index > pl->size - 1 || index < 0) return Error1;
	pl->entry[index] = val;
	return Valid;
}

int List_Full(List* pl){
	return pl-> size == MAX_SIZE;
}

int List_Empty(List* pl){
	return !pl->size;
}
int List_Size(List* pl){
	return pl->size;
}

void Destroy_List(List* pl){
	pl->size = 0;
}

void display(ListEntry val, int index){
	printf("Element %d = %d\n",index,val.intger); 
}

void Traverse_List(List* pl, void(*pf)(ListEntry val, int index)){
	for(int i = 0; i < pl->size ;i++){
		(*pf)(pl->entry[i],i + 1);
	}
}
#endif