#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

#define    SERV_PORT      43211
#define    MAXLINE        4096

static int count;

static void recvfrom_int(int signo)
{
    printf("\nrecevied %d datagrams\n",count);
    exit(0);
}

int main(int argc,char*argv[])
{
    int socket_fd;
    struct sockaddr_in server_addr;

    socket_fd = socket(AF_INET,SOCK_DGRAM,0);

    bzero(&server_addr,sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(SERV_PORT);
    bind(socket_fd,(struct sockaddr *)&server_addr,sizeof(server_addr));

    socklen_t client_len;
    char message[MAXLINE];
    count = 0;

    signal(SIGINT,recvfrom_int);

    struct sockaddr_in client_addr;
    client_len = sizeof(client_addr);
    for(;;)
    {
        int n = recvfrom(socket_fd,message,MAXLINE,0,(struct sockaddr *) &client_addr, &client_len);
        message[n] = 0;
        printf("received %d bytes: %s\n",n,message);

        char send_line[MAXLINE];
        sprintf(send_line,"Hi,%s\n",message);

        sendto(socket_fd,send_line,strlen(send_line),0, (struct sockaddr *) &client_addr, client_len);

        count++;
    }
}