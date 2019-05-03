#include<stdio.h>
#include"cs392_log.h"
void cs392_socket_log(char * ip, char * port){
    /*
    *   Args:
    *       ip (char *): A string that represent the ip of the client
    *       port (char*): A string that represents the port of the client
    *
    *   This function takes in an ip and a port and writes the client information
    *   to the cs392_socket.log file
    */
    FILE * fp = fopen("cs392_socket.log","a");
    fprintf(fp,"[%s:%s]\n",ip,port);
    fclose(fp);
}

