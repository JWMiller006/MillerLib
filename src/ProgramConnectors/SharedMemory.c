#include "../../include/ProgramConnectors/SharedMemory.h"

void* GetSharedMemorySegment(const char* filePath, int Segment, int Size)
{
  key_t key;
  int shmid; 
  void* data;   
  char input; 

  /* Get the shared memory segment key */  
  key = ftok(filePath, Segment); 
  
  /* Create the shared memory segment */
  shmid = shmget(key, Size, 0666 | IPC_CREAT); 
  
  if (shmid == -1)
  {
    perror("Could not get shared memory id"); 
    exit(121); 
  }
  
  data = shmat(shmid, (void*)0, 0); 
  
  if (data == (char*)-1) 
  {
    perror("Could not attach to shared memory");
    exit(122); 
  }
  
  scanf("%c", &input); 
  
  printf("%c\n\n", input); 
  
  shmdt(data);
  
  shmctl(shmid, IPC_RMID, NULL);

  return NULL; 
}


/* Gets the ID to the specific shared memory segment */
int GetSharedId(const char* filePath, int segment, int size)
{
  int shmid; 
  key_t key = ftok(filePath, segment); 
  
  /* Allocates the shared memory segment */
  shmid = shmget(key, size, 0666 | IPC_CREAT); 
  
  /* Validates the shared memory segment */
  if (shmid == -1)
  {
    perror("Could not get shared memory Id");
    exit(121); 
  }
  
  /* Returns the Id for the newly created segment */
  return shmid; 
}

/* Attaches to the shared memory segment and returns the pointer */
void* AttachToSharedMemory(int Id)
{
  void* ptr;
  
  ptr = shmat(Id, (void*)0, 0); 
  
  if (ptr == (char*)-1)
  {
    perror("Could not attach to shared memory");
    exit(122); 
  }
  
  return ptr; 
}

/* Releases the specified shared memory segment and releases the pointer */
bool ReleaseSharedMemory(int Id, void** ptr)
{
  shmdt(ptr);
  
  shmctl(Id, IPC_RMID, NULL);
  
  return true; 
}










