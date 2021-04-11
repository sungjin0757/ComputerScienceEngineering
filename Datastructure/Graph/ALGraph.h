#ifndef __ALGRAPH_H__
#define __ALGRAPH_H__

#include"DLinkedList.h"
#include"ArrayBaseStack.h"
enum{A,B,C,D,E,F,G,H,I,J};

typedef struct _ual {
	int numV;
	int numE;
	List* adjList;
	int* visitInfo;
}ALGraph;

void GraphInit(ALGraph* pg, int nv);
void GraphDestroy(ALGraph* pg);
void AddEdge(ALGraph* pg, int fromV, int toV);
void ShowGraphEdgeInfo(ALGraph* pg);
void DFShowGraphVertex(ALGraph* pg, int startV);
void BFShowGraphVertex(ALGraph* pg, int startV);
#endif