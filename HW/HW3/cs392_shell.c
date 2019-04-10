//"I pledge my honor that I have abided by the Stevens honor system" - igomez1 Ian Gomez
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>
#include<unistd.h>
#include"cs392_exec.h"
#include"cs392_log.h"
#include"cs392_signal.h"
int main(){
    /*
    *   The main fuction which will register all the signal handlers and run the shell until an exit command is recieved
    */
    struct sigaction act;
    memset(&act , '\0', sizeof(act));
    act.sa_sigaction = &sigHandler;
    act.sa_flags = SA_SIGINFO;
    if(sigaction(SIGINT, &act, NULL)<0){
        perror("sigaction failed for SIGINT");
        return 1;
    }
    if(sigaction(SIGTSTP, &act, NULL)<0){
        perror("sigaction failed for SIGTSTP");
        return 1;
    }
    char command[131072];
    printf("cs392_shell $:");
    while(1){
        fgets(command,131072,stdin);
        writeToLog(command); 
        if(strcmp(command,"exit\n") == 0){
            break;
        }
        executeCommand(command);
        command[0] = '\0';
    }
    return 0;
}
