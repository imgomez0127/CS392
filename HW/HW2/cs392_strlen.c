//"I pledge my honor that I have abided by the Stevens honor system" - igomez1 Ian Gomez
#include "cs392_string.h"
#include <stdio.h>
unsigned int cs392_strlen(char *str){
    /*
    *   Args:
    *       str(char *): An array of characters
    *   Returns
    *       length(unsigned int): the length of the original string
    *
    *   This function takes in an array of characters str and returns
    *   the length of the array excluding the null byte
    */ 
    unsigned int length = 0;
    for(unsigned i = 0; str[i] != '\0'; ++i){
        length++;
    }
    return length;
}
 
