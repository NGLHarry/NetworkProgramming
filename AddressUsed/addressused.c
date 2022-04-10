#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define SERV_PORT 43211
#define LISTENQ 1024
#define MAXLINE 4096

static int count;

int main(int argc, char *argv[])
{
    int listenfd;
    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERV_PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    int on = 1;
    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));

    int rt1 = bind(listenfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if(rt1 < 0)
    {
        perror("bind failed");
        return -1;
    }

    int rt2 = listen(listenfd, LISTENQ);
    if(rt2 < 0)
    {
        perror("listen failed");
        return -1;
    }

    signal(SIGPIPE, SIG_IGN);

    int connfd;
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);

    if((connfd = accept(listenfd, (struct sockaddr *)&client_addr, &client_addr)) < 0)
    {
        perror("accept failed");
        return -1;
    }

    char message[MAXLINE];
    count = 0;
    for(;;)
    {
        int n  = read(connfd, message, MAXLINE);
        if(n < 0)
        {
            perror("error read");
            return -1;
        }
        else if(n == 0)
        {
            printf("client close");
            return 0;
        }
        message[n] = 0;
        printf("received %d bytes;%s\n",n,message);
        count++; 
    }
}