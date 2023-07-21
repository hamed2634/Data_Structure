#ifndef LIST_H
#define LIST_H
	#include "..\.\Global\Global.h"
	#include "..\.\lib\lib.h"

#define LIMITED_MEMORY

#ifdef LIMITED_MEMORY
	#define MAX_SIZE infinite
	
	typedef struct ListNode{
		ListEntry entry; 
		struct ListNode* next;
	}ListNode;
	
	typedef struct List{
		ListNode* head;
		int size;
	}List;
	
#else	
	#define MAX_SIZE 1000
	
	typedef struct List{
		int size;
		ListEntry entry[MAX_SIZE];
	}List;
#endif
	Error Initialize_List(List* );
	Error Insert(int, ListEntry, List*);
	Error Delete(int, ListEntry* ,List* );
	Error Get(int, ListEntry* , List*);
	Error Replace(int, ListEntry, List*);
	int List_Full(List* );
	int List_Empty(List* );
	int List_Size(List* );
	void Destroy_List(List* );
	void display(ListEntry, int);
	void Traverse_List(List* , void(*pf)(ListEntry, int));

	
#endif