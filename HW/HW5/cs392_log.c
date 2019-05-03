#include<stdio.h>
#include"cs392_log.h"
void cs392_socket_log(char * ip, char * port){
    FILE * fp = fopen("cs392_socket.log","a");
    fprintf(fp,"[%s:%s]\n",ip,port);
    fclose(fp);
}

