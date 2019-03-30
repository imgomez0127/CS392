//"I pledge my honor that I have abided by the Stevens honor system"-igomez1 Ian Gomez
#include"cs392_midterm.h"
int cs392_strcmp(char *s1, char *s2){
    /*
    *   Args:   
    *       s1(char *): A pointer to the first string array to be compared to
    *       s2(char *): A pointer to the second string array to be compared to 
    *   Returns:
    *       comparison_num(int): a number which represents if the first input
    *                            is greater than less than or equal to 
    *                            the second input
    *   This function takes in two char arrays and returns whether the first
    *   input is greater than less than or equal to the second input
    */
    int i = 0;
    for(i; s2[i] != '\0' && s1[i] != '\0';++i){
        unsigned int curS1CharAscii = s1[i];
        unsigned int curS2CharAscii = s2[i];
        if(curS1CharAscii > curS2CharAscii){
            return 1;
        }
        if(curS2CharAscii > curS1CharAscii){
            return -1;
        }
    }
    if(s1[i] == '\0' && s2[i] != '\0'){
        return -1;
    }
    if(s1[i] != '\0' && s2[i] == '\0'){
        return 1;
    }
    return 0;
}

