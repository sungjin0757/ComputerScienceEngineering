#ifndef __PRIORITY_QUEUE_H__
#define __PRIORITY_QUEUE_H__

#include"SimpleHeap.h"

typedef Heap PQueue;
typedef HData PData;

void PQueueInit(PQueue* pq,Priority comp);
int PQIsEmpty(PQueue* pq);

void Enqueue(PQueue* pq, PData data);
PData Dequeue(PQueue* pq);

#endif