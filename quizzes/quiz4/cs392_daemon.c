#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
#include<syslog.h>
#include<string.h>
#include<time.h>

int main(){
    pid_t pid,sid;
    pid = fork();
    if(pid < 0){
        printf("??\n");
        exit(1);
    }
    if(pid > 0){

        exit(0);
    }

    umask(0);
    sid = setsid();
    if(sid < 0){
        exit(1);
    }
    if((chdir("/tmp")) < 0){
        exit(1);
    }
    close(STDIN_FILENO);
    close(STDERR_FILENO);
    close(STDOUT_FILENO);
    FILE * fp = fopen("cs392_daemon.log","a");
    while(1){
        time_t t = time(NULL);
        struct tm *tm = localtime(&t);
        fprintf(fp,"%s\n",asctime(tm));
        fflush(fp);
        sleep(2);
    }  
    fclose(fp);
    return 0;
}
