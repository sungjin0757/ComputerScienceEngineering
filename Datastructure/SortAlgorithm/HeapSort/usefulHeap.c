#include<stdio.h>
#include<stdlib.h>
#include"usefulHeap.h"

void HeapInit(Heap* ph, Priority pc) {
	ph->numOfData = 0;
	ph->comp = pc;
}
int HIsEmpty(Heap* ph) {
	if (ph->numOfData == 0)
		return TRUE;
	return FALSE;
}
int GetParentIndex(int idx) {
	return idx / 2;
}
int GetLChildIndex(int idx) {
	return idx * 2;
}
int GetRChildIndex(int idx) {
	return idx * 2 + 1;
}
int GetHiPriChildIdx(Heap* ph, int idx) {
	if (GetLChildIndex(idx) > ph->numOfData)
		return 0;
	else if (GetLChildIndex(idx) == ph->numOfData)
		return GetLChildIndex(idx);
	else {
		/*if (ph->heapArr[GetLChildIndex(idx)].pr < ph->heapArr[GetRChildIndex(idx)].pr)
			return GetLChildIndex(idx);
		else
			return GetRChildIndex(idx);*/
		if (ph->comp(ph->heapArr[GetLChildIndex(idx)], ph->heapArr[GetRChildIndex(idx)]) < 0)
			return GetRChildIndex(idx);
		else
			return GetLChildIndex(idx);
	}
}
void HInsert(Heap* ph, HData data) {
	int idx = ph->numOfData + 1;
	//HeapElem newEle= { pr,data };
	ph->heapArr[idx] = data;
	while (idx != 1) {
		/*if (ph->heapArr[GetParentIndex(idx)].pr > ph->heapArr[idx].pr)
		{
			HeapElem temp = ph->heapArr[GetParentIndex(idx)];
			ph->heapArr[GetParentIndex(idx)] = ph->heapArr[idx];
			ph->heapArr[idx] = temp;
			idx = GetParentIndex(idx);
		}*/
		if (ph->comp(ph->heapArr[GetParentIndex(idx)], ph->heapArr[idx]) < 0) {
			HData temp = ph->heapArr[GetParentIndex(idx)];
			ph->heapArr[GetParentIndex(idx)] = ph->heapArr[idx];
			ph->heapArr[idx] = temp;
			idx = GetParentIndex(idx);
		}
		else {
			break;
		}
	}
	ph->numOfData++;
}
HData HDelete(Heap* ph) {
	HData rdata = ph->heapArr[1];
	HData lastElem = ph->heapArr[ph->numOfData];

	int parentindex = 1;

	while (GetHiPriChildIdx(ph, parentindex) != 0) {
		int childIndex = GetHiPriChildIdx(ph, parentindex);
		/*if (lastElem.pr <= ph->heapArr[childIndex].pr)
			break;*/
		if (ph->comp(lastElem, ph->heapArr[childIndex]) > 0)
			break;
		ph->heapArr[parentindex] = ph->heapArr[childIndex];
		parentindex = childIndex;
	}
	ph->heapArr[parentindex] = lastElem;
	ph->numOfData--;
	return rdata;
}