#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <netinet/in.h>


#define SERV_PORT 43211
#define LISTENQ 1024
#define MAX_LINE 4096

int tcp_server_listen(int port)
{
    int listen_fd;
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    int on = 1;
    setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));

    int rt1 = bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if(rt1 < 0)
    {
        perror("bind failed");
        return -1;
    }

    int rt2 = listen(listen_fd, LISTENQ);
    if(rt2 < 0)
    {
        perror("listen failed");
        return -1;
    }

    signal(SIGPIPE, SIG_IGN);

    return listen_fd;
}
char rot13_char(char c) {
    if ((c >= 'a' && c <= 'm') || (c >= 'A' && c <= 'M'))
        return c + 13;
    else if ((c >= 'n' && c <= 'z') || (c >= 'N' && c <= 'Z'))
        return c - 13;
    else
        return c;
}
void sigchld_handler(int sig)
{
    while(waitpid(-1, 0, WNOHANG) > 0);
    return;
}
void child_run(int fd)
{
    char outbuf[MAX_LINE + 1];
    size_t outbuf_used = 0;
    ssize_t result;

    while(1)
    {
        char ch;
        result = recv(fd, &ch, 1, 0);
        if(result == 0)
        {
            break;
        }
        else if(result == -1)
        {
            perror("read failed");
            return -1;
        }

        if(outbuf_used < sizeof(outbuf))
        {
            outbuf[outbuf_used++] = rot13_char(ch);
        }
        if(ch == '\n')
        {
            send(fd, outbuf, outbuf_used, 0);
            outbuf_used = 0;
            continue;
        }
    }
}

int main(int argc, char *argv[])
{
    int listener_fd = tcp_server_listen(SERV_PORT);
    signal(SIGCHLD, sigchld_handler);
    while(1)
    {
        struct sockaddr_storage ss;
        socklen_t slen = sizeof(ss);
        int fd = accept(listener_fd, (struct sockaddr *)&ss, &slen);
        if(fd < 0)
        {
            perror("accept failed");
            return -1;
        }
        if(fork()  == 0)
        {
            close(listener_fd);
            child_run(fd);
            exit(0);
        }
        else
        {
            close(fd);
        }
    }
    return 0;
}