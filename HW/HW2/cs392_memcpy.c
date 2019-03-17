//"I pledge my honor that I have abided by the Stevens honor system" - igomez1 Ian Gomez
#include "cs392_string.h"
void * cs392_memcpy(void * dst, void * src, unsigned int n){
    /*
    *   Args:
    *       dst(void *): A pointer to the destination array
    *       src(void *): A pointer to the source array
    *       n(unsigned int): The amount of bytes to transfer from 
    *                        dst to src
    *   Returns:
    *       dst(void *): A pointer to the destination array after
    *                    being copied to
    *   This function copies n bytes from the src array into the dst array.
    *   This function does not account for n being greater than src
    */
    
    char * dstC = dst;
    char * srcC = src;
    for(unsigned int i = 0; i < n; i++){
        dstC[i] = srcC[i];
    }
    return dst; 
}


