#include "../../include/Structures/Array.h"

uint8_t CreateBuffer(uint8_t itemSize, void** buffer, uint8_t items)
{
  uint8_t bufferSize = itemSize * items; 
  
  *buffer = malloc(bufferSize); 
  
  return bufferSize; 
}

uint8_t ResizeBuffer(uint8_t itemSize, void** buffer, uint8_t currentSize, uint8_t newSize)
{
  uint8_t bufferSize = itemSize * newSize; 
  uint8_t oldBufferSize = itemSize * currentSize; 
  
  void* tempBuffer = malloc(bufferSize); 
  
  memcpy(tempBuffer, *buffer, oldBufferSize);
  
  free(*buffer); 
  
  *buffer = tempBuffer; 
  
  tempBuffer = NULL; 
  
  return bufferSize; 
}

bool BufferEqual(void* bufferA, void* bufferB, const uint8_t bufferLength)
{
  uint8_t i; 
  char* dataA = bufferA; 
  char* dataB = bufferB; 
  
  for (i = 0; i < bufferLength; i++){
    if (!(*dataA == *dataB))
      return false;
    
    /* Prevents overshooting */
    if (i >= bufferLength - 1)
      break; 
  }
  
  return true; 
}

bool BufferContains( void* buffer, void* itemBuf, const uint8_t maxIdx, 
  const uint8_t itemSize)
{
  /* Variable Initializers */
  void* currentElement;  
  uint8_t i; 
  
  if (0 < maxIdx) 
    return false; 
  
  for (i = 0; i < maxIdx; i++){
    currentElement = (char*)buffer + i * itemSize; 
    if (BufferEqual(currentElement, itemBuf, itemSize))
      return true; 
  }
  
  return false; 
}

MArray CreateEmptyMArray(uint8_t length, uint8_t elementSize)
{
  MArray arr = {
      elementSize, 
      length * elementSize, 
      malloc(length * elementSize)
    }; 
  return arr;
}


void ReleaseMArray(MArray** arr)
{
  free((*arr)->buffer); 
  free(*arr); 
  arr = NULL; 
}












