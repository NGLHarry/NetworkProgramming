#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <signal.h>


#include "message_objecte.h"

#define SERV_PORT 43211
#define LISTENQ 1024

static int count;

static void sig_int(int signo) {
    printf("\nreceived %d datagrams\n", count);
    exit(0);
}


int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        perror("usage:tcpserver <sleepingtime>");
        return -1;
    }

    int sleepingTime = atoi(argv[1]);

    int listenfd;
    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERV_PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
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

    signal(SIGINT, sig_int);
    signal(SIGPIPE, SIG_IGN);

    int connfd;
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    if((connfd = accept(listenfd, (struct sockaddr *)&client_addr,&client_addr)) < 0)
    {
        perror("accept failed");
        return -1;
    }

    messageObject message;
    count = 0;

    for(;;)
    {
        printf("count:%d\n",count);
        int n = read(connfd, (char *)&message, sizeof(messageObject));
        if(n < 0)
        {
            perror("error read");
            return -1;
        }
        else if(n == 0)
        {
            perror("client closing ...");
            return 0;
        }

        printf("received %d bytes\n",n);
        count++;

        switch (ntohl(message.type))
        {
        case MSG_TYPE1:
            printf("process MSG_TYPE1 \n");
            break;
        case MSG_TYPE2:
            printf("process MSG_TYPE2 \n");
            break;
        case MSG_PING:
        {
            messageObject pong_message;
            pong_message.type = MSG_PONG;
            sleep(sleepingTime);
            ssize_t rc = send(connfd, (char *)&pong_message, sizeof(pong_message), 0);
            if(rc < 0)
            {
                perror("send failure");
                return -1;
            }
            break;
        }
        default:
            printf("unknow message type (%d) \n", ntohl(message.type));
            break;
        }
    }    

}

