/*
 * This section of the library contains logic
 *  that creates and manages arrays in the 
 *  form of a buffer. An array can easily be 
 *  allocated and stored in a buffer of the 
 *  required size and returns the buffer total
 *  size. 
 *   
 */

#ifndef MILLER_ARRAYS
#define MILLER_ARRAYS

#include <stddef.h> 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../MillerTypeDef.h"

/* 
 * This function creates an array on the specified buffer
 *  which is allocated on the size needed to have the 
 *  specified number of elements of the specified type. 
 *  Returns the buffer size. 
 */
uint8_t CreateBuffer(uint8_t itemSize, void** buffer, uint8_t items); 


/* 
 * This function takes the current buffer of your array and
 *  reallocates the memory for a new array. Returns the 
 *  new buffer size. 
 */
uint8_t ResizeBuffer(uint8_t itemSize, void** buffer, uint8_t currentSize, uint8_t newSize); 

/*
 * This function compares the difference between the two 
 *  buffers of the same length. If every single byte is 
 *  equal, it returns true, otherwise it returns false. 
 */
bool BufferEqual(void* bufferA, void* bufferB, const uint8_t bufferLenght); 

/* 
 * This is a function that is meant to find if the specified item
 *  is within the buffer, if so, return true, otherwise return false
 */
bool BufferContains(void* buffer, void* itemBuf, const uint8_t bufferLength, 
  const uint8_t itemSize);

/*
 * Creates an empty Miller Array with the specified parameters
 */
MArray CreateEmptyMArray(uint8_t length, uint8_t elementSize); 

/* Frees the memory used for the array */
void ReleaseMArray(MArray** arr); 

/* Resize the array buffer to the desired length */
MArray MArrResize(MArray arr, uint8_t newBufferSize);

/* Adds the item to the array */
MArray MArrAppend(MArray arr, void* item, uint8_t itemSize);

/* Returns a buffer of the specified item */
void* MArrayGet(const MArray arr, const uint8_t index); 




#endif