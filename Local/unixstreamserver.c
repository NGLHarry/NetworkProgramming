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
#define MAXLINE 4096
#define LISTENQ 1024

int main(int argc,char *argv[])
{
    if(argc != 2)
    {
        perror("usage: unixdataserver <local path>");
        return -1;
    }

    int listenfd, connfd;

    listenfd = socket(AF_LOCAL, SOCK_STREAM, 0);
    if(listenfd < 0)
    {
        perror("socket create failed");
        return -1;
    }

    struct sockaddr_un servaddr, cliaddr;
    
    char *local_path = argv[1];
    unlink(local_path);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sun_family = AF_LOCAL;
    strcpy(servaddr.sun_path, local_path);

    if(bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("bind failed");
        return -1;
    }

    if(listen(listenfd, LISTENQ) < 0)
    {
        perror("listen failed");
        return -1;
    }

    socklen_t clilen;
    clilen = sizeof(cliaddr);
    if((connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &clilen)) < 0)
    {
        if(errno == EINTR)
        {
            perror("accept failed");
            return -1;
        }
        else
        {
            perror("accept failed");
            return -1;
        }
    }

    char buf[BUFFER_SIZE];
    while(1)
    {
        bzero(buf, sizeof(buf));
        if(read(connfd, buf, BUFFER_SIZE) == 0)
        {
            printf("client quit");
            break;
        }
        printf("Receive: %s\n",buf);

        char send_line[MAXLINE];
        bzero(send_line, MAXLINE);
        sprintf(send_line, "Hi, %s", buf);

        int nbytes = sizeof(send_line);

        if(write(connfd, send_line, nbytes) != nbytes)
        {
            perror("write error");
            return -1;
        }
    }
    close(listenfd);
    close(connfd);

    exit(0);
}


