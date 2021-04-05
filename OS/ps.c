/*
 * Copyright (c) 2001,2003,2004 David H. Hovemeyer <daveho@cs.umd.edu>
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

#include <conio.h>
#include <process.h>

struct Process_Info ptable[80];
int main(int argc __attribute__ ((unused)), char **argv
         __attribute__ ((unused))) {

    char statustemp,coretemp,afftemp;
    int i=0;
    PS(ptable,80);
    Print("PID PPID PRIO STAT AFF TIME COMMAND\n");
    for(i=0;i<80;i++)
    {
    	if(ptable[i].pid==0)
    		return 0;
    	if(ptable[i].status== STATUS_RUNNABLE)
    		statustemp='R';
    	else if(ptable[i].status== STATUS_ZOMBIE)
    		statustemp='Z';
    	else if(ptable[i].status==STATUS_BLOCKED)
    		statustemp='B';
    	else
    		statustemp='U';

    	if(statustemp=='R')
    		coretemp=ptable[i].currCore+'0';
    	else
    		coretemp=' ';

    	if(ptable[i].affinity==-1)
    		afftemp='A';
    	else
    		afftemp=ptable[i].affinity+'0';

    	Print("%3d %4d %4d %2c%2c %3c %4d %s\n",ptable[i].pid,ptable[i].parent_pid,ptable[i].priority,coretemp,statustemp,afftemp,ptable[i].totalTime,ptable[i].name);
    }

    	
// format string for one process line should be "%3d %4d %4d %2c%2c %3c %4d %s\n"
    return 0;
}
