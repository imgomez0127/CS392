#include"cs392_exec.h"
#include"cs392_log.h"
#include<stdio.h>
#include<stdlib.h>
int main(){
    while(1){
        char command[131000];
        printf("cs392_shell $:");
        fgets(command, 131000, stdin);
        writeToLog(command); 
        executeCommand(command);
    }
    return 0;
}
