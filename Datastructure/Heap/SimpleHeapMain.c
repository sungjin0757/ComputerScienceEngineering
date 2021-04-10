#include<stdio.h>
#include"SimpleHeap.h"

int DataPriorty(char ch1, char ch2) {
	return ch2 - ch1;
}
int main(void) {
	Heap heap;
	HeapInit(&heap,DataPriorty);

	HInsert(&heap, 'A', 1);
	HInsert(&heap, 'B', 2);
	HInsert(&heap, 'C', 3);
	printf("%c \n", HDelete(&heap));

	HInsert(&heap, 'A', 1);
	HInsert(&heap, 'B', 2);
	HInsert(&heap, 'C', 3);
	printf("%c \n", HDelete(&heap));

	while (!HIsEmpty(&heap)) {
		printf("%c \n", HDelete(&heap));
	}

	return 0;
}