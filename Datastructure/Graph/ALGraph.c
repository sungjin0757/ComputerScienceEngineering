#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"ALGraph.h"
#include"ArrayBaseStack.h"
#include"DLinkedList.h"
#include"Queue.h"
int WhoIsprecede(int data1, int data2) {
	if (data1 < data2)
		return 0;
	else
		return 1;
}
int VisitVertex(ALGraph* pg, int visitV) {
	if (pg->visitInfo[visitV] == 0) {
		pg->visitInfo[visitV]=1;
		printf("%c ", visitV + 65);
		return TRUE;
	}
	return FALSE;
}
void GraphInit(ALGraph* pg, int nv) {
	int i;
	pg->adjList = (List*)malloc(sizeof(List));
	pg->numV = nv;
	pg->numE = 0;
	pg->visitInfo = (int*)malloc(sizeof(int)*pg->numV);
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
	for (i = 0; i < nv; i++) {
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsprecede);
	}
}
void GraphDestroy(ALGraph* pg) {
	if (pg->adjList != NULL)
		free(pg->adjList);
	if (pg->visitInfo != NULL)
		free(pg->visitInfo);
}
void AddEdge(ALGraph* pg, int fromV, int toV) {
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE += 1;
}
void ShowGraphEdgeInfo(ALGraph* pg) {
	int i;
	int vx;

	for (i = 0; i < pg->numV; i++) {
		printf("%c와 연결된 정점:", i + 65);

		if (LFirst(&(pg->adjList[i]), &vx))
		{
			printf("%c ", vx + 65);

			while (LNext(&(pg->adjList[i]), &vx))
				printf("%c ", vx + 65);
		}
		printf("\n");
	}
	
}
void DFShowGraphVertex(ALGraph* pg, int startV) {
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
	Stack stack;
	int visitV = startV;
	int nextV;

	StackInit(&stack);
	VisitVertex(pg, visitV);
	//SPush(&stack, visitV);
	
	while (1) {
		int visitflag = FALSE;
		if (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE) {
			if (VisitVertex(pg, nextV) == TRUE)
			{
				SPush(&stack, visitV);
				visitV = nextV;
				visitflag = TRUE;
			}
			else {
				while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE)
				{
					if (VisitVertex(pg, nextV) == TRUE) {
						SPush(&stack, visitV);
						visitV = nextV;
						visitflag = TRUE;
						break;
					}

				}
			}
		}
		if (visitflag == FALSE) {
			if (SIsEmpty(&stack) == TRUE)
				break;
			else
				visitV = SPop(&stack);
		}
	}
	//memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}
void BFShowGraphVertex(ALGraph* pg, int startV) {
	int visitV = startV;
	Queue queue;
	int nextV;
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
	QueueInit(&queue);
	VisitVertex(pg, visitV);
	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE) {
		int visiFlag = FALSE;

		if (VisitVertex(pg, nextV) == TRUE) {
			Enqueue(&queue, visitV);
		}
		while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE) {
			if (VisitVertex(pg, nextV) == TRUE) {
				Enqueue(&queue, visitV);
			}
		}
		if (visiFlag == FALSE) {
			if (QIsEmpty(&queue) == TRUE)
				break;
			else
				visitV = Dequeue(&queue);
		}
	}
}