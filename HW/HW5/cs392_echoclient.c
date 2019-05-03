#include<stdio.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<string.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#define MAXCONNECTIONS 5 
int main(int argc, char ** argv){
    if(argc != 3){
        printf("Usage: ./cs392_echoserver <Address> <Port>\n"); 
        exit(1);
    }
    int port = atoi(argv[2]),recieved = 0;
    unsigned int echolen;
    char buffer[1024];
    char response[1024];
    int socketFD;
    struct sockaddr_in socketAddr;
    socketFD = socket(AF_INET,SOCK_STREAM,0);
    if(socketFD == -1){
        printf("Error in creating socket\n");
        exit(1);
    }
    memset(&socketAddr,0,sizeof(struct sockaddr_in));
    socketAddr.sin_family = AF_INET;
    socketAddr.sin_addr.s_addr = inet_addr(argv[1]);
    socketAddr.sin_port = htons(port);
    if(connect(socketFD, (struct sockaddr *) &socketAddr, sizeof(socketAddr)) == -1){
        printf("Error in connect\n");
        exit(1);
    }
    printf("Enter text to send to the server:");
    fflush(stdout);
    fgets(buffer,1024,stdin);
    if(send(socketFD,buffer,1024,0) == -1){
        printf("Local error in send\n") ;
        exit(1);
    } 
    if(recv(socketFD,response,1024,0) == -1){
        printf("Error in recieve\n");
        exit(1);
    }
    printf("%s",response);
    return 0;
}

