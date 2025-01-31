#include "../include/MillerLib.h"

bool isLibraryInitialized(void){
  #ifdef MILLER_LIB
    printf("Miller Library Core Initialized\n");
    return true;
  #else
    printf("Miller Library Core NOT Initialized\n");
    return false; 
  #endif
}

