/*
 * To most people looking at this, you may be wondering:
 *   "Of what use to me is a shared memory handler in 
 *     this library."
 *  and to that I would agree. You most likely won't have
 *  any use for having a shared memory library that can 
 *  simply connect different programs, but I thought that
 *  I could give myself more practice on creating and 
 *  monitoring a shared memory segment from C (I already
 *  know how to do so in "modern" C++). This seemed to be
 *  the perfect chance to relearn C and see what is 
 *  different on this device configuration. 
 */
 
#ifndef SHARED_MEM
#define SHARED_MEM

/*
 * Here I have listed some notes about using shared memory. 
 *  When you allocate the shared memory using the same file, 
 *  you can attach to the same segment. If your program does
 *  not call the release from shared memory at the end of its
 *  runtime, it will leave the shared memory segment active, 
 *  even if it will never be used again. To release it in C,
 *  simply connect to the segment using the same file path as 
 *  its hash and delete it that way. To do so in the terminal, 
 *  use the command "ipcs -m" to see all of the allocated 
 *  shared memory segments and their status. In order to remove
 *  one of them, you would run the command "ipcrm <shmid>" where
 *  the <shmid> is found in the "ipcs -m" command. This will set 
 *  the shared memory segment to be deleted upon the last client 
 *  disconnecting from the segment. If you leave these segments
 *  on the system, there is undefined behaviour that could occur
 *  when you try to reallocate the size of that specific segment. 
 *  It is suggested that you make sure that you clean up your 
 *  segments after each run, or at least before you try to change 
 *  the size of the bock. 
 */

/* Include the Core if not already */ 
#include "../MillerLib.h"

/* Include Shared Memoy Specific headers */
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/ipc.h>

void* GetSharedMemorySegment(const char* filePath, int Segment, int Size); 

int GetSharedId(const char* filePath, int segment, int size); 

void* AttachToSharedMemory(int Id); 

bool ReleaseSharedMemory(int Id, void** ptr); 

#endif