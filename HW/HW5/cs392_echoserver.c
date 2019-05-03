#include<stdio.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<string.h>
#include<netinet/in.h>
#include<unistd.h>
#include<arpa/inet.h>
#include"cs392_log.h"
#define MAXCONNECTIONS 5 
int main(int argc, char ** argv){
    if(argc != 2){
        printf("Usage: ./cs392_echoserver <Port>\n"); 
        exit(1);
    }
    int port = atoi(argv[1]);
    int socketFD,clientFD;
    struct sockaddr_in socketAddr,clientAddr; 
    unsigned int clientlen;
    socketFD = socket(AF_INET,SOCK_STREAM,0); 
    if(socketFD == -1){
        printf("Error in creating socket\n");
        exit(1);
    }
    memset(&socketAddr,0,sizeof(struct sockaddr_in));
    socketAddr.sin_family = AF_INET;
    socketAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    socketAddr.sin_port = htons(port);    
    if(bind(socketFD,(struct sockaddr *) &socketAddr, sizeof(struct sockaddr_in)) == -1){
        printf("Error in binding socket\n");
        exit(1);
    }
    listen(socketFD,MAXCONNECTIONS);
    char buff[1024];
    while(1){
        clientFD = accept(socketFD,(struct sockaddr *) &clientAddr,&clientlen);
        cs392_socket_log(inet_ntoa(clientAddr.sin_addr),argv[1]);
        recv(clientFD,buff,1024,0);
        send(clientFD,buff,1024,0); 
        close(clientFD);
    }
    return 0;
}

