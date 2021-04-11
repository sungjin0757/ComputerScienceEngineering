#include<stdio.h>
#include"ArrayBaseStack.h"

void StackInit(Stack* pstack) {
	pstack->topIndex = -1;
}
int SIsEmpty(Stack* pstack) {
	if (pstack->topIndex == -1)
		return TRUE;
	return FALSE;
}

void SPush(Stack* pstack, Data data) {
	(pstack->topIndex)++;
	pstack->StackArr[pstack->topIndex] = data;
}
Data SPop(Stack* pstack) {
	if (SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}
	Data data = pstack->StackArr[pstack->topIndex];

	(pstack->topIndex)--;
	return data;
}
Data SPeek(Stack* pstack) {
	if (SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}
	return pstack->StackArr[pstack->topIndex];
}