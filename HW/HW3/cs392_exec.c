#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<string.h>
#include"cs392_exec.h"
int countCommands(char * str){
    char str2[strlen(str)];
    strcpy(str2,str);
    const char tok[2] =  " ";
    char * token = strtok(str2,tok);
    int tokenCount = 0;
    while(token != NULL){
        ++tokenCount;
        token = strtok(NULL,tok);
    }
    return tokenCount;
}
char ** parseCommand(char * unparsedCommand){
    int amtOfCommands = countCommands(unparsedCommand);
    char ** arguments = malloc(amtOfCommands+1);
    const char tok[2] = " ";
    char * token = strtok(unparsedCommand,tok);
    int i = 0;
    while(token != NULL){
        arguments[i] = token;
        token = strtok(NULL,tok);
        ++i;
    } 
    arguments[amtOfCommands] = (char *) NULL;
    return arguments;
}
char * removeNewline(char * str){
    const char tok[2] = "\n";
    char * token = strtok(str,tok);
    return token;
}
void executeCommand(char * command){
    pid_t pid;
    if((pid = fork()) < 0){
        perror("fork");
    }
    else if(pid == 0){
        command = removeNewline(command);
        char ** commandArr = parseCommand(command);
        execvp(commandArr[0],commandArr);
        free(commandArr);
        exit(0);
    }
    else{
        if(waitpid(pid, NULL, 0) < 0){
            printf("Error in waiting");
            exit(0);
        }
    }
}
