//"I pledge my honor that I have abided by the Stevens honor system" - igomez1 Ian Gomez
#include"cs392_log.h"
#include<stdio.h>
void writeToLog(char * command){
    /*
    *   Args:
    *       command (char *): the command which needs to be logged
    *   This function takes in a command and appends it to the cs392_shell.log file
    *   it creates the file if it does not exist
    */
    FILE * f = fopen("cs392_shell.log","a");
    fputs(command,f);
    fclose(f);
}
