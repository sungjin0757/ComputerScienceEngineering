/*
 * Copyright (c) 2003,2013,2014 Jeffrey K. Hollingsworth <hollings@cs.umd.edu>
 *
 * All rights reserved.
 *
 * This code may not be resdistributed without the permission of the copyright holders.
 * Any student solutions using any of this code base constitute derviced work and may
 * not be redistributed in any form.  This includes (but is not limited to) posting on
 * public forums or web sites, providing copies to (past, present, or future) students
 * enrolled in similar operating systems courses the University of Maryland's CMSC412 course.
 */

#include <geekos/syscall.h>
#include <geekos/errno.h>
#include <geekos/kthread.h>
#include <geekos/int.h>
#include <geekos/elf.h>
#include <geekos/malloc.h>
#include <geekos/screen.h>
#include <geekos/keyboard.h>
#include <geekos/string.h>
#include <geekos/user.h>
#include <geekos/timer.h>
#include <geekos/vfs.h>
#include <geekos/signal.h>
#include <geekos/sem.h>
#include <geekos/projects.h>
#include <geekos/smp.h>

struct Semaphore{
	char *name;
	int thid;
	struct Thread_Queue waitThread;
	int count;
};

static struct Semaphore uSemaPhore[50];
static int num=1;
static int sid = 1;
static int Copy_User_String(ulong_t uaddr, ulong_t len, ulong_t maxLen, char** pStr) {
	int rc = 0;
	char* str;
	if (len > maxLen) {           
		return EINVALID;
	}
	str = (char*)Malloc(len + 1);     
	if (0 == str) {
		rc = ENOMEM;
		goto fail;
	}
	if (!Copy_From_User(str, uaddr, len)) {          
		rc = EINVALID;
		Free(str);
		goto fail;
	}
	str[len] = '\0';      
	*pStr = str;
fail:
	return rc;
}
/*
 * Create or find a semaphore.
 * Params:
 *   state->ebx - user address of name of semaphore
 *   state->ecx - length of semaphore name
 *   state->edx - initial semaphore count
 * Returns: the global semaphore id
 */
int Sys_Open_Semaphore(struct Interrupt_State *state) {
	int rc=0;
	int i;
	int j = num;
	char *name=0;
	bool iflag;
	if ((rc = Copy_User_String(state->ebx, state->ecx, VFS_MAX_PATH_LEN, &name)) != 0)
		return -1;
	iflag = Begin_Int_Atomic();
	for(i=0;i<j;i++)
	{
		if(strcmp(uSemaPhore[i].name,name)==0)
			return uSemaPhore[i].thid;
	}
	if (sid <= 0)
		sid++;
	if (num <= 0)
		num++;
	uSemaPhore[num-1].name=name;
	uSemaPhore[num-1].count=state->edx;
	uSemaPhore[num-1].thid = sid-1 ;
	Clear_Thread_Queue(&uSemaPhore[num-1].waitThread);
	num++;
	sid++;
	End_Int_Atomic(iflag);
	return uSemaPhore[num-2].thid;
}

/*
 * Acquire a semaphore.
 * Assume that the process has permission to access the semaphore,
 * the call will block until the semaphore count is >= 0.
 * Params:
 *   state->ebx - the semaphore id
 *
 * Returns: 0 if successful, error code (< 0) if unsuccessful
 */
int Sys_P(struct Interrupt_State *state) {
	bool iflag;
	
	if (uSemaPhore[state->ebx].thid < 0 || uSemaPhore[state->ebx].thid >= 50)
		return -1;
	iflag = Begin_Int_Atomic();
	
	uSemaPhore[state->ebx].count--;
	if(uSemaPhore[state->ebx].count<0)
		Wait(&uSemaPhore[state->ebx].waitThread);
	End_Int_Atomic(iflag);
	return 0;

}

/*
 * Release a semaphore.
 * Params:
 *   state->ebx - the semaphore id
 *
 * Returns: 0 if successful, error code (< 0) if unsuccessful
 */
int Sys_V(struct Interrupt_State *state) {
	bool iflag;
	
	if (uSemaPhore[state->ebx].thid < 0 || uSemaPhore[state->ebx].thid >= 50)
		return -1;
	iflag = Begin_Int_Atomic();
	
	uSemaPhore[state->ebx].count++;
	if(uSemaPhore[state->ebx].count>=0)
		Wake_Up_One(&uSemaPhore[state->ebx].waitThread);
	End_Int_Atomic(iflag);
	return 0;

}

/*
 * Destroy our reference to a semaphore.
 * Params:
 *   state->ebx - the semaphore id
 *
 * Returns: 0 if successful, error code (< 0) if unsuccessful
 */
int Sys_Close_Semaphore(struct Interrupt_State *state) {
	bool iflag;
	
	if (uSemaPhore[state->ebx].thid < 0 || uSemaPhore[state->ebx].thid >= 50)
		return -1;
	iflag = Begin_Int_Atomic();
	
	Wake_Up(&uSemaPhore[state->ebx].waitThread);
	
	uSemaPhore[state->ebx].name = 0;
	uSemaPhore[state->ebx].thid = -1;
	sid--;
	num--;
	End_Int_Atomic(iflag);
	return 0;
}
