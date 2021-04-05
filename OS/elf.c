/*
 * ELF executable loading
 * Copyright (c) 2003, Jeffrey K. Hollingsworth <hollings@cs.umd.edu>
 * Copyright (c) 2003, David H. Hovemeyer <daveho@cs.umd.edu>
 *
 * All rights reserved.
 *
 * This code may not be resdistributed without the permission of the copyright holders.
 * Any student solutions using any of this code base constitute derviced work and may
 * not be redistributed in any form.  This includes (but is not limited to) posting on
 * public forums or web sites, providing copies to (past, present, or future) students
 * enrolled in similar operating systems courses the University of Maryland's CMSC412 course.
 *
 * $Revision: 1.31 $
 *
 */

#include <geekos/errno.h>
#include <geekos/kassert.h>
#include <geekos/ktypes.h>
#include <geekos/screen.h>      /* for debug Print() statements */
#include <geekos/pfat.h>
#include <geekos/malloc.h>
#include <geekos/string.h>
#include <geekos/user.h>
#include <geekos/fileio.h>
#include <geekos/elf.h>

#include <geekos/paging.h>

int elfDebug = 0;

/**
 * From the data of an ELF executable, determine how its segments
 * need to be loaded into memory.
 * @param exeFileData buffer containing the executable file
 * @param exeFileLength length of the executable file in bytes
 * @param exeFormat structure describing the executable's segments
 *   and entry address; to be filled in
 * @return 0 if successful, < 0 on error
 */
int Parse_ELF_Executable(char *exeFileData, ulong_t exeFileLength,
                         struct Exe_Format *exeFormat) {
	/*TODO("Parse an ELF executable image");*/
	int i;
	int numOfEmptySegment =0;
	elfHeader *pEhr;
	programHeader *pPhr;
	struct Exe_Segment *pExeSegment;

	pEhr = (elfHeader *)exeFileData;
	pPhr = (programHeader *)(exeFileData + pEhr->phoff);
	pExeSegment = exeFormat->segmentList;

	if(exeFileData==0){
		Print("Read fail");
		return 0;
	}

	if(!((pEhr->ident[0]==0x7f)&&(pEhr->ident[1]==0x45)&&(pEhr->ident[2]==0x4c)&&(pEhr->ident[3]==0x46)))
	{
		Print("not Elf File");
		return -1;
	}

	if(pEhr->type==0){
		Print("no file type\n");
		return -1;
	}

	if(pEhr->machine==0){
		Print("no machine\n");
		return -1;
	}

	if(pEhr->version==0){
		Print("invalid version\n");
		return -1;
	}

	if(pEhr->entry==0){
		Print("no entry point\n");
		return -1;
	}

	if(pEhr->phoff==0){
		Print("no pgm hdr table\n");
		return -1;
	}

	if(pEhr->sphoff==0){
		Print("no section hdr table\n");
		return -1;
	}

	if(pEhr->phnum > EXE_MAX_SEGMENTS){
		Print("invalid number of segment\n");
		return -1;
	}

	for(i = 0; i<pEhr->phnum; i++)
	{
		if(pEhr->phentsize==0) {
			pExeSegment++;
			pPhr++;
			numOfEmptySegment++;
			continue;
		}
		pExeSegment->offsetInFile = pPhr->offset;
		pExeSegment->lengthInFile = pPhr->fileSize;
		pExeSegment->startAddress = pPhr->vaddr;
		pExeSegment->sizeInMemory = pPhr->memSize;
		pExeSegment->protFlags = pPhr->flags;

		pExeSegment++;
		pPhr++;
	}

	exeFormat->numSegments = pEhr->phnum-numOfEmptySegment;
	exeFormat->entryAddr = pEhr->entry;

	return 0;
}
