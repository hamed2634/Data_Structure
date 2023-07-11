#include "queue.h"

void Initialize_Queue(Queue* pq){
	pq->front = 0;
	pq->back = -1;
	pq->size = 0;
}

void Push(Queue* pq, int val){
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

void display(int val, int index){
	printf("Element %d = %d\n",index,val); 
}

void Traverse_Queue(Queue* pq, void(*pf)(int val, int index)){
	for(int i = 0; i < pq->size ;i++){
		(*pf)(pq->entry[(pq->front + i)%MAX_SIZE ],i + 1);
	}
}
