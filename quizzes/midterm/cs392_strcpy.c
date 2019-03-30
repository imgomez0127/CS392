//"I pledge my honor that I have abided by the Stevens honor system" - igomez1 Ian Gomez
#include"cs392_midterm.h"
char * cs392_strcpy(char *dest, char *src){
    /*
    *   Args:
    *       dest(char *): A pointer to the first element of the 
    *                     destination character array
    *       src(char *): A pointer to the first element of the 
    *                    source character array
    *   Returns:
    *       dest(char *): The pointer to the destination array after copying
    *                     the data from the source
    *   This function copies the contents of the source array to the
    *   destination array and returns the pointer to the destination array
    */
    int i = 0;
    for(i ; src[i] != '\0'; ++i){
        dest[i] = src[i];
   }
    dest[i] = '\0';
    return dest;
}

