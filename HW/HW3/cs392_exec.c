//"I pledge my honor that I have abided by the Stevens honor system" - igomez1 Ian Gomez
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<string.h>
#include"cs392_exec.h"
int countCommands(char * str){
    /*
    *   Args
    *       str (char *): string to count commands from
    *   This function returns the amount of commands in the given string
    *
    */
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
    /*
    *   Args
    *       unparsedCommand (char *): the command which needs to be parsed
    *   This function takes in a command and returns a pointer to the array of the parsed commands
    *
    */
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
    /*
    *   Args:
    *       str(char *)
    *   This function takes in a string and returns the string up to the first new line
    *
    */ 
    const char tok[2] = "\n";
    char * token = strtok(str,tok);
    return token;
}
void executeCommand(char * command){
    /*
    *   Args:
    *       command (char*): the command which needs to be run
    *   This function takes in a commands forks the current process and in the parent process waits for the command to finish
    *   and in the child process it executes the command and then exits
    */
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
        waitpid(pid,NULL,0);
        printf("cs392_shell $:");
    }
}
