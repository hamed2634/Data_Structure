#ifndef QUEUE_H
#define QUEUE_H

	#include "..\.\lib\lib.h"
	//#define LIMITED_MEMORY
	
#ifdef LIMITED_MEMORY
	#define MAX_SIZE infinite
	typedef int QueueEntry ;
	typedef struct QueueNode{
		QueueEntry entry;
		struct QueueNode* next;
	}QueueNode;
	typedef struct Queue{
		QueueNode* front;
		QueueNode* back;
		int size;
	}Queue;
#else
	
	#define MAX_SIZE 1000
	
	typedef int QueueEntry ;
	typedef struct Queue{
		int front;
		int back;
		int size;
		QueueEntry entry[MAX_SIZE];
	}Queue;

#endif
	void Initialize_Queue(Queue* );
	void Push(Queue* , QueueEntry );
	int Queue_Full(Queue* );
	void Serve(QueueEntry* ,Queue* );
	int Queue_Empty(Queue* );
	int Queue_Size(Queue* );
	QueueEntry Front(Queue* );
	QueueEntry Back(Queue* );
	void Clear_Queue(Queue* );
	void display(QueueEntry , int );
	void Traverse_Queue(Queue* , void(*pf)(QueueEntry , int ));

	
#endif