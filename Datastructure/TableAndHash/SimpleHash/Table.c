#include<stdio.h>
#include<stdlib.h>
#include"Table.h"

void TBLInit(Table* pt, HashFunc* f) {
	int i;
	for (i = 0; i < MAX_TBL; i++)
		ListInit(&(pt->tbl[i]));
	pt->fc = f;
}
void TBLInsert(Table* pt, Key k, Value v) {
	int hv = pt->fc(k);
	Slot ns = { k,v };
	if (TBLSearch(pt, k) != NULL)
	{
		printf("키 중복 오류 발생!\n");
		return;
	}
	else {
		LInsert(&(pt->tbl[hv]),ns);
	}
}
Value TBLDelete(Table* pt, Key k) {
	int hv = pt->fc(k);
	Slot cSlot;
	if (LFirst(&(pt->tbl[hv]), &cSlot)) {
		if (cSlot.Key == k) {
			LRemove(&(pt->tbl[hv]));
			return cSlot.vl;
		}
		else {
			while (LNext(&(pt->tbl[hv]), &cSlot))
			{
				if (cSlot.Key == k)
				{
					LRemove(&(pt->tbl[hv]));
					return cSlot.vl;
				}
			}
		}
	}
	return NULL;
	
}
Value TBLSearch(Table* pt, Key k) {
	int hv = pt->fc(k);
	Slot cSlot;
	if (LFirst(&(pt->tbl[hv]), &cSlot)) {
		if (cSlot.Key == k) {
			return cSlot.vl;
		}
		else {
			while (LNext(&(pt->tbl[hv]), &cSlot))
			{
				if (cSlot.Key == k)
					return cSlot.vl;
			}
		}
	}
	return NULL;

}