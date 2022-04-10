#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

#define MAXLINE 4096


int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        perror("usage: unixdataserver <local path>");
        return -1;
    }

    int sockfd;
    sockfd = socket(AF_LOCAL, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        perror("create socket failed...");
        return -1;
    }

    struct sockaddr_un servaddr;
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sun_family = AF_LOCAL;
    strcpy(servaddr.sun_path, argv[1]);

    if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("connect failed");
        return -1;
    }

    char send_line[MAXLINE];
    bzero(&send_line, MAXLINE);
    char recv_line[MAXLINE];

    while(fgets(send_line, MAXLINE, stdin) != NULL)
    {
        int nbytes = sizeof(send_line);
        if(write(sockfd, send_line, nbytes) != nbytes)
        {
            perror("write error");
            return -1;
        }

        if(read(sockfd, recv_line, MAXLINE) == 0)
        {
            perror("server terminated prematurely");
            return -1;
        }

        fputs(recv_line, stdout);
    }

    exit(0);
}
