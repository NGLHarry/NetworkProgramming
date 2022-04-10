#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

#define BUFFER_SIZE 4096
#define MAX_LINE 4096


int main(int argc,char* argv[])
{
    if(argc != 2)
    {
        perror("usage: unixdataserver <local path>");
        return -1;
    }

    int socket_fd;
    socket_fd = socket(AF_LOCAL, SOCK_DGRAM, 0);
    if(socket_fd < 0)
    {
        perror("socket create failed");
        return -1;
    }

    struct sockaddr_un servaddr;
    char *local_path = argv[1];
    unlink(local_path);
    bzero(&servaddr,sizeof(servaddr));
    servaddr.sun_family = AF_LOCAL;
    strcpy(servaddr.sun_path,local_path);

    if(bind(socket_fd,(struct sockaddr *)&servaddr,sizeof(servaddr)) < 0)
    {
        perror("bind faild\n");
        return -1;
    }

    char buf[BUFFER_SIZE];

    struct sockaddr_un client_addr;
    socklen_t client_len = sizeof(client_addr);
    while(1)
    {
        bzero(buf,sizeof(buf));
        if(recvfrom(socket_fd, buf, BUFFER_SIZE, 0, (struct sockaddr *)&client_addr, &client_len) == 0)
        { 
            printf("client quit\n");
            break;
        }
        printf("Receive: %s \n",buf);

        char send_line[MAX_LINE];
        bzero(send_line,MAX_LINE);
        sprintf(send_line,"Hi, %s",buf);

        size_t nybtes = strlen(send_line);
        printf("now sending :%s \n",send_line);

        if(sendto(socket_fd,send_line,nybtes, 0, (struct sockaddr *)&client_addr, client_len) != nybtes)
        {
            perror("sendto error\n");
            break;
        }
    }
    close(socket_fd);

    exit(0);

}