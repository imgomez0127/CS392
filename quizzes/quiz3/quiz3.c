#include<stdio.h>
#include<signal.h>
#include<string.h>
#include<unistd.h>
static void hdl(int sig, siginfo_t *siginfo, void *context){
    if(sig == SIGINT){
        printf(" Sending PID:%ld, UID: %ld\n", (long)siginfo->si_pid, (long)siginfo->si_uid);
    }
}
int main(int argc, char* argv[]){
    struct sigaction act;
    memset(&act, '\0', sizeof(act));
    act.sa_sigaction = &hdl;
    act.sa_flags = SA_SIGINFO | SA_RESETHAND;
    if(sigaction(SIGINT, &act, NULL) < 0){
        perror("sigaction failed");
        return 1;
    }
    while(1){
        sleep(1);
    }
    return 0;
}
    
