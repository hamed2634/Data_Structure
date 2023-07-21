#include "queue.h"

#ifdef LIMITED_MEMORY
void Initialize_Queue(Queue* pq){
	pq->front = NULL;
	pq->back = NULL;
	pq->size = 0;
}

void Push(Queue* pq, QueueEntry val){
	QueueNode* pn = (QueueNode*)malloc(sizeof(QueueNode));
	pn->next = NULL;
	pn->entry = val;
	if(!pq->size){
		pq->front = pn;
		pq->back = pn;
	}
	else{
		pq->back->next = pn;
		pq->back = pn;
	}
	pq->size++;
}

int Queue_Full(Queue* pq){
	return 0;
}

void Serve(QueueEntry* pe,Queue* pq){
	*pe = pq->front->entry;
	QueueNode* pn = pq->front;
	pq->front= pq->front->next;
	free(pn);
	if(!pq->front) pq->back = NULL;
	pq->size--;
}

int Queue_Empty(Queue* pq){
	return !pq->size ;
}

int Queue_Size(Queue* pq){
	return pq->size;
}

QueueEntry Front(Queue* pq){
	return pq->front->entry ;
}

QueueEntry Back(Queue* pq){
	return pq->back->entry ;
}

void Clear_Queue(Queue* pq){
	QueueNode* pn = pq->front;
	while(pn){
		pq->front = pq->front->next;
		free(pn);
		pn = pq->front;
	}
	pq->size = 0;
}

void display(QueueEntry val, int index){
	printf("Element %d = %d\n",index,val); 
}

void Traverse_Queue(Queue* pq, void(*pf)(QueueEntry val, int index)){
	QueueNode* pn = pq->front;
	for(int i = 1; pn ; pn = pn->next, i++){
		(*pf)(pn->entry, i);
	}
}
#else
	
void Initialize_Queue(Queue* pq){
	pq->front = 0;
	pq->back = -1;
	pq->size = 0;
}

void Push(Queue* pq, QueueEntry val){
	pq->entry[(++pq->back) % MAX_SIZE] = val; 
	pq->size++;
}

int Queue_Full(Queue* pq){
	return pq->size == MAX_SIZE;
}

void Serve(QueueEntry* pe,Queue* pq){
	*pe = pq->entry[pq->front];
	pq->front = (pq->front + 1)%MAX_SIZE;
	pq->size--;
}

int Queue_Empty(Queue* pq){
	return !pq->size ;
}

int Queue_Size(Queue* pq){
	return pq->size;
}

QueueEntry Front(Queue* pq){
	return pq->entry[pq->front] ;
}

QueueEntry Back(Queue* pq){
	return pq->entry[pq->back] ;
}

void Clear_Queue(Queue* pq){
	pq->front = 0;
	pq->back = -1;
	pq->size = 0;
}

void display(QueueEntry val, int index){
	printf("Element %d = %d\n",index,val); 
}

void Traverse_Queue(Queue* pq, void(*pf)(QueueEntry val, int index)){
	for(int i = 0; i < pq->size ;i++){
		(*pf)(pq->entry[(pq->front + i)%MAX_SIZE ],i + 1);
	}
}
#endif