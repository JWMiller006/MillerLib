#include <stdio.h>
#include "include/MillerLib.h"
#include "include/ProgramConnectors/SharedMemory.h"



int main(void){
  int segment; 
  int size; 
  void* sharedMemory;
  int ShmId;
  char in; 
  const char* file = "file.txt";
  
  printf("\nHello World\n"); 
 	printf("Checking if the Library is initialized\n");
  
  isLibraryInitialized();
  
  scanf("\nEnter the segment number: %d", &segment); 
  
  size = sizeof(long);  
  
  ShmId = GetSharedId(file, segment, size);
  
  sharedMemory = AttachToSharedMemory(ShmId);
  
  scanf("%c", &in); 
  
  ReleaseSharedMemory(ShmId, sharedMemory); 
  
	return 0; 
}
