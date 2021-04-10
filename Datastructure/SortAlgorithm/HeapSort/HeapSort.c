#include<stdio.h>
#include"usefulHeap.h"

int Pricomp(int n1, int n2) {
	return n2 - n1;
}
void HeapSort(int arr[], int n) {
	Heap heap;
	int i;

	HeapInit(&heap,Pricomp);
	
	for (i = 0; i < n; i++)
		HInsert(&heap, arr[i]);

	for (i = 0; i < n; i++)
		arr[i] = HDelete(&heap);
}

int main(void) {
	int arr[4] = { 2,3,1,4 };
	int i;
	HeapSort(arr, 4);
	for (i = 0; i < 4; i++)
		printf("%d ", arr[i]);

	return 0;
}