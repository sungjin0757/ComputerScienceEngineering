#include<stdio.h>
#include"PriorityQueue.h"

void PQueueInit(PQueue* pq, Priority comp) {
	HeapInit(pq, comp);
}
int PQIsEmpty(PQueue* pq) {
	return HIsEmpty(pq);
}

void Enqueue(PQueue* pq, PData data) {
	HInsert(pq, data);
}
PData Dequeue(PQueue* pq) {
	return HDelete(pq);
}