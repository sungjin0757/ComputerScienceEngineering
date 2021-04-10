#ifndef __SIMPLE_HEAP_H__
#define __SIMPLE_HEAP_H__

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100
//�ּ��� ���̽��� ���� ����f ����
typedef char HData;
typedef int Priority(HData d1, HData d2);

/*typedef struct _heapElem {
	Priority pr;
	HData data;
}HeapElem;*/

typedef struct _heap {
	int numOfData;
	Priority* comp;
	HData heapArr[HEAP_LEN];
}Heap;

void HeapInit(Heap* ph, Priority pc);
int HIsEmpty(Heap* ph);

void HInsert(Heap* ph, HData data);
HData HDelete(Heap* ph);
#endif#pragma once
