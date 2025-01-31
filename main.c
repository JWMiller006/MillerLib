#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

/* Sleep */
#ifdef _WIN32
/* Doesn't work yet, but ideal to get ready to work */
#include <windows.h>
#else
#include <unistd.h>
#endif

#include "include/MillerLib.h"
#include "include/ProgramConnectors/SharedMemory.h"

bool running = false; 

void runSharedMemExample(void); 
void WriteToBuffer(void* sharedMemoryStart, int numIterations, int* array); 
void ReadFromBuffer(void* sharedMemorystart, int numIterations, int* array); 



int main(void){
  runSharedMemExample();
  
  
  
	return 0; 
}


/* 
 * Shared Memory Example: 
 *  This example shows the usage of the shared memory section of the 
 *   library as well as some examples of how to use the buffer array
 */
void runSharedMemExample(void){
  /* Init Variables */
  int segment; 
  int size; 
  void* sharedMemory;
  int* data; 
  int ShmId;
  const char* file = "file.txt";
  
  /* Input */
  char in; 
  int numIterations; 
  int i = 0; 
  int* array; 
  long arrayLength = CreateBuffer(sizeof(int), &array, 1); 
  pthread_t* threads; 
  
  /* Set the random seed to the time */
  srand(time(NULL)); 
  
  printf("Enter the segment number: "); 
  scanf("\n%d", &segment); 
  
  size = 2 * sizeof(int);  
  
  /* Sets up the shared memory */
  ShmId = GetSharedId(file, segment, size);
  
  sharedMemory = AttachToSharedMemory(ShmId);
  
  data = sharedMemory; 
  
  /* Sets up the simulated data */
  printf("Enter the number of iterations: "); 
  scanf("\n %d", &numIterations); 
  
  ENDL(); 
  
  arrayLength = ResizeBuffer(sizeof(int), &array, 1, numIterations); 
  
  printf("Enter any character to continue or \"w\" to write to the buffer... ");

  scanf("\n %c", &in); 
  
  if (in == 'w'){
    WriteToBuffer(sharedMemory, numIterations, array); 
  }
  else {
    ReadFromBuffer(sharedMemory, numIterations, array); 
  }
  
  ReleaseSharedMemory(ShmId, &sharedMemory); 
  
  free(array);
}

void WriteToBuffer(void* sharedMemoryStart, int numIterations, int* array){
  int* data = (int*)sharedMemoryStart; 
  int i = 0; 
  

  while (i < numIterations)
  {
    array[i] = rand(); 
    printf("%d: Item: %d\n", i, array[i]); 
    data[0] = i; 
    data[1] = array[i]; 
    i++; 
    usleep(1000);     
  }
  
  ENDL(); 
  
  printf("Wrote %d sets of random data to shared memory", numIterations);
  
  data = NULL; 
}

void ReadFromBuffer(void* sharedMemoryStart, int numIterations, int* array){
  int* data = (int*)sharedMemoryStart;
  int i = 0; 
  int timeoutCount = 0; 
  
  while (i < numIterations)
  {
    if (i != data[0]){
      i = data[0]; 
      timeoutCount = 0; 
      array[i] = data[1]; 
      printf("Reading %d from shared memory; Message ID: %d\n", array[i], i); 
    }
    else {
      timeoutCount++; 
    }
    
    if (timeoutCount == 100000)
      break; 
      
    usleep(100); 
  }
  
  data = NULL; 
}