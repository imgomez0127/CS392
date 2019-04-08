#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<string.h>
#include"cs392_exec.h"
void copyRange(char * input, char * dest, int begin, int end){
    int i;
    for(i = begin; i < end; ++i){
        dest[i-begin] = input[i];
    }
    dest[i+1] = '\0';
}
int countSpaces(char * inputString){
    int amountOfSpaces = 0;
    for(int i = 0; inputString[i] != '\0'; ++i){
        if(inputString[i] == ' '){
            ++amountOfSpaces;
        }
    }
    return amountOfSpaces; 
}
char ** parseCommand(char * unparsedCommand,int amtOfCommands){
    char * arguments[amtOfCommands];
    int argumentLength = 0;
    int curArgument = 0;
    char * argument;
    for(int i = 0; unparsedCommand[i] != '0'; ++i){
        if(unparsedCommand[i] == ' '){
            argument = malloc(argumentLength+1);
            copyRange(unparsedCommand,argument,curArgument,argumentLength+curArgument);
            argumentLength = 0;
            curArgument = ++i;
        }
    }
}

