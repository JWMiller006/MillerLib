/*
 * Here I will define specific macros that can
 *  be helpful shortcuts in day-to-day programming
 */

#ifndef MILLER_TYPES
#define MILLER_TYPES

/* 
 * Definition of types that are used in other
 *  C dialects that I would like to use. I 
 *  would prefer to specify the data type size
 *  for some things rather than guessing based
 *  on the system. These are specific to the 
 *  UMD Grace System. 
 */
/*
  typedef long            int8_t; 
typedef int             int4_t; 
typedef short           int2_t; 
typedef char            int1_t; */
typedef unsigned int    uint4_t; 
typedef unsigned long   uint8_t; 
typedef unsigned short  uint2_t; 
typedef unsigned char   uint1_t; 


/* 
 * Apparently C Standard 90 didn't have booleans, 
 *  so this is a workaround that should work
 */
typedef unsigned short bool; 
#define false 0
#define true 1

/*
 * This is the definition of the array that is 
 *  generally used in the rest of the library
 */
typedef struct {
  uint8_t itemLength; 
  uint8_t bufferLength; 
  void* buffer; 
} MArray; 

#endif