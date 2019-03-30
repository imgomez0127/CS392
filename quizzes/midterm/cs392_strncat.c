//"I pledge my honor that I have abided by the Stevens honor system" - igomez1 Ian Gomez
#include"cs392_midterm.h"
char * cs392_strncat(char * dest, char * src,unsigned int n){
    /*
    *   Args:
    *       dest(char *): Pointer to first item in the destination array
    *       src(char *): Pointer to the first item in the source array
    *       n(unsigned int): The amount of values to be copied from the source
    *   Returns:
    *       dest(char *): The pointer to the first item in the destination array
    *                     after the source has been concatenated to it
    *   This function takes in two char arrays and returns the first n items of
    *   the source array into the destination array
    */
    int i = 0;
    for(i; dest[i] != '\0'; ++i){
    }
    for(int j = 0; j<n; ++j){
        dest[i] = src[j];
        ++i;
    }
    dest[i] = '\0';
    return dest;
}

