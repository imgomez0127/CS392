//"I pledge my honor that I have abided by the Stevens honor system" - igomez1 Ian Gomez
#include<stdio.h>
#include<signal.h>
#include"cs392_signal.h"
void sigHandler(int sig, siginfo_t * siginfo, void * context){
    /*
    *   Args:
    *       sig(int): number of the recieved signal
    *       siginfo*(siginfo_t *): Info about the recieved signal
    *       context(void *): Context about the recieved signal
    *   This function takes in a values from a signal and if it is a sigint or sigtstp it prints out a message
    */
    if(sig == SIGINT){
        printf("\nRecieved SIGINT\n");
    }
    if(sig == SIGTSTP){
        printf("\nRecieved SIGTSTP\n");
    }

}

