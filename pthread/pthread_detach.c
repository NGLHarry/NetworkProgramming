#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <sys/poll.h> 
#include <sys/socket.h>
#include <netinet/in.h>

#define SERV_PORT 43211
#define LISTENQ 1024
#define INIT_SIZE 128
#define MAXLINE 1024
#define MAX_LINE 16384

extern void loop_echo(int);

int tcp_server_listen(int port) {
    int listenfd;
    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port);

    int on = 1;
    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));

    int rt1 = bind(listenfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
    if (rt1 < 0) {
        perror( "bind failed ");
        return -1;
    }

    int rt2 = listen(listenfd, LISTENQ);
    if (rt2 < 0) {
        perror("listen failed ");
        return -1;
    }

    signal(SIGPIPE, SIG_IGN);

    return listenfd;
}

void pthread_run(void *arg)
{
    pthread_detach(pthread_self());
    int fd = (int)arg;
    loop_echo(fd);
}

int main(int argc, char* argv[])
{
    int listen_fd = tcp_server_listen(SERV_PORT);
    pthread_t tid;

    while(1)
    {
        struct sockaddr_storage ss;
        socklen_t slen = sizeof(ss);
        int fd = accept(listen_fd, (struct sockaddr *)&ss, &slen);
        if(fd < 0)
        {
            perror("accept failed");
            return -1;
        }
        else
        {
            pthread_create(&tid, NULL, &pthread_run, (void *)fd);
        }
    }
}