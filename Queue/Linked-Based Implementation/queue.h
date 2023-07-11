#ifndef QUEUE_H
	#include "..\.\lib\lib.h"
	
	
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
	
	void Initialize_Queue(Queue* pq);
	void Push(Queue* pq, int val);
	int Queue_Full(Queue* pq);
	void Serve(QueueEntry* pe,Queue* pq);
	int Queue_Empty(Queue* pq);
	int Queue_Size(Queue* pq);
	QueueEntry Front(Queue* pq);
	QueueEntry Back(Queue* pq);
	void Clear_Queue(Queue* pq);
	void display(int val, int index);
	void Traverse_Queue(Queue* pq, void(*pf)(int val, int index));

	
#endif