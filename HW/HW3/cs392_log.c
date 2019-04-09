#include"cs392_log.h"
#include<stdio.h>
void writeToLog(char * command){
    FILE * f = fopen("cs392_shell.log","a");
    fputs(command,f);
    fclose(f);
}
