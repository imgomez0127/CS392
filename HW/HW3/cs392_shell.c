#include"cs392_exec.h"
#include<stdio.h>
#include<stdlib.h>
int main(){
    while(1){
        char command[1000];
        printf("cs392_shell $:");
        gets(str);
        executeCommand(command);
        pid_t pid;
        if((pid = fork()) < 0){
            perror("fork");
        }
        else if(pid == 0){
            int amtOfCommands = countSpaces(unparsedCommand);
            char ** commandArr = parseCommand(char * unparsedCommand);
            execv("./",commandArr);
            for(int i = 0; i < amtOfCommands; ++i){
                free(commandArr[i]);
            }
            exit();
        }
        else{
            if(waitpid(pid,, NULL, WIFEXITED) < 0){
                err_sys("error in waiting");
            }
        }
}
