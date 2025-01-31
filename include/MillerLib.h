/* 
 * This File is the start of the Miller Library
 * 
 * The Miller Library is a simple library that 
 *  was started January 2025 in order to include
 *  examples and functions for different use 
 *  cases. As more information is learned, these
 *  functions will be updated to try to make 
 *  them the most efficient while also being the
 *  most secure. Since the catalyst for creating
 *  this library was a Computer Science class 
 *  which limits the C Langeuage Version to 
 *  C Standard 90, I will be using that and 
 *  optimizing for the UMD Grace Server. That 
 *  being said, the CMake version is also limited
 *  to CMake 2.8. 
 */

/* 
 * Header Guard (I don't think pragma once was 
 *  invented yet 
 */
#ifndef MILLER_LIB
#define MILLER_LIB

/*
 * Here I will include the general includes 
 *  specific to this individual header
 */
#include <stdio.h>
#include <pthread.h>
#include <stddef.h> 
#include <stdlib.h>
#include <string.h>


/*
 * Includes for the primary library
 */
#include "Threading/MillerThreads.h"
#include "MillerTypeDef.h"

/* Shortcut for endline */
#define ENDL() printf("\n")

/*
 * Here I will write the function signatures 
 *  that are defined in the Miller Library Core
 */ 
 
/* Returns true or false (1|0) verifying setup */
bool isLibraryInitialized(void);



#endif





































