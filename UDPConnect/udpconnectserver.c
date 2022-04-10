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

int main(int argc, char *argv[])
{
    int socket_fd;
    socket_fd = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERV_PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    signal(SIGINT, recvfrom_int);

    char message[MAXLINE];
    message[0] = 0;
    count = 0;

    socklen_t client_len;
    struct sockaddr_in client_addr;
    client_len = sizeof(client_addr);

    int n = recvfrom(socket_fd, message, MAXLINE, 0, 
        (struct sockaddr *)&client_addr, &client_len);
    if(n < 0)
    {
        perror("recvfrom failed");
        return -1;
    }
    message[n] = 0;
    printf("received %d byte:%s\n",n, message);

    if(connect(socket_fd, (struct sockaddr *)&client_addr, client_len))
    {
        perror("connect failed");
        return -1;
    }
    while(strncmp(message, "goodbye", 7) !=0 )
    {
        char send_line[MAXLINE];
        sprintf(send_line, "Hi,%s",message);

        size_t rt = send(socket_fd, send_line, strlen(send_line), 0);
        if(rt < 0)
        {
            perror("send failed");
            return -1;
        }
        printf("send bytes :%zu \n",rt);

        size_t rc = recv(socket_fd, message, MAXLINE, 0);
        if(rc < 0)
        {
            perror("recv failed");
        }
        count++;
    }
    exit(0);
}