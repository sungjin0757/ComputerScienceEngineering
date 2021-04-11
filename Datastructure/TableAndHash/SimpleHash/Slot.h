#ifndef __SLOT_H__
#define __SLOT_H__

#include"person.h"

typedef int Key;
typedef Person* Value;

//enum SlotStatus{EMPTY,DELETED,INUSE};

typedef struct _slot
{
	Key Key;
	Value vl;
	enum SlotStatus status;
}Slot;
#endif