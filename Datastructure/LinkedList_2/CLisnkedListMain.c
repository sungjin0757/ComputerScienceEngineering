#include<stdio.h>
#include<stdlib.h>
#include"CLinkedList.h"

int main(void) {
	List list;
	int data;
	int i,nodeNum;
	ListInit(&list);

	LInsert(&list, 11);
	LInsert(&list, 11);
	LInsert(&list, 22);
	LInsert(&list, 22);
	LInsert(&list, 33);

	printf("현재 데이터의 수:%d \n", LCount(&list));

	if (LFirst(&list, &data)) {
		printf("%d ", data);
		for (i = 0; i < LCount(&list) * 3 - 1; i++)
		{
			if(LNext(&list,&data))
				printf("%d ", data);
		}
	}
	printf("\n\n");
	nodeNum = LCount(&list);
	if (nodeNum != 0) {
		LFirst(&list, &data);
		if (data % 2 == 0)
			LRemove(&list);
		for (i = 0; i < nodeNum - 1; i++) {
			LNext(&list, &data);
			if (data % 2 == 0)
				LRemove(&list);
		}
	}

	printf("현재 데이터의 수:%d \n", LCount(&list));


	if (LFirst(&list, &data)) {
		printf("%d ", data);
		for (i = 0; i < LCount(&list) * 3 - 1; i++)
		{
			if (LNext(&list, &data))
				printf("%d ", data);
		}
	}
	printf("\n\n");

	return 0;
}