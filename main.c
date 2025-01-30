#include <stdio.h>
#include <pthread.h>
#include "include/MillerLib.h"
#include "include/ProgramConnectors/SharedMemory.h"

static bool running = false; 

int main(void){
  int segment; 
  int size; 
  void* sharedMemory;
  int ShmId;
  char in; 
  const char* file = "file.txt";
  pthread_t* threads; 
  
  printf("\nHello World\n"); 
 	printf("Checking if the Library is initialized\n");
  
  isLibraryInitialized();
  
  printf("Enter the segment number: "); 
  scanf("\n%d", &segment); 
  
  size = sizeof(long);  
  
  ShmId = GetSharedId(file, segment, size);
  
  sharedMemory = AttachToSharedMemory(ShmId);
  
  printf("Enter any character to continue... ");

  scanf("\n%c", &in); 
  
  ReleaseSharedMemory(ShmId, sharedMemory); 
  
  
  
	return 0; 
}
