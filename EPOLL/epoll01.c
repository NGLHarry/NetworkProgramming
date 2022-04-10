#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <netinet/in.h>

#define SERV_PORT 43211
#define LISTENQ 1024
#define MAXEVENTS 128

char rot13_char(char c) {
    if ((c >= 'a' && c <= 'm') || (c >= 'A' && c <= 'M'))
        return c + 13;
    else if ((c >= 'n' && c <= 'z') || (c >= 'N' && c <= 'Z'))
        return c - 13;
    else
        return c;
}

void make_nonblocking(int fd)
{
    fcntl(fd, F_SETFL, O_NONBLOCK);
}


int tcp_nonblocking_server_listen(int port)
{
    int listen_fd;
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);

    make_nonblocking(listen_fd);

    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    int on = 1;
    setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));

    int rt1 = bind(listen_fd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    if(rt1 < 0)
    {
        perror("bind error\n");
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


int main(int argc, char *argv[])
{
    int listen_fd, socket_fd;
    int n, i;
    int efd;
    struct epoll_event event;
    struct epoll_event *events;


    listen_fd = tcp_nonblocking_server_listen(SERV_PORT);

    //为epoll创建实例
    efd = epoll_create1(0);
    if(efd == -1)
    {
        perror("epoll create failed");
        return -1;
    }

    event.data.fd = listen_fd;
    event.events = EPOLLIN | EPOLLET;
    // 调用epoll_ctl将监听字对应的I/O事件进行注册，有新的连接建立，就可以感知，采用edge-triggered边缘触发
    if(epoll_ctl(efd, EPOLL_CTL_ADD, listen_fd, &event) == -1)
    {
        perror("epoll_ctl add listen fd failed");
        return -1;
    }

    // Buffer where events are returned
    events = calloc(MAXEVENTS, sizeof(event));

    while(1)
    {
        // 调用epoll_wait函数分发I/O事件，当epoll_wait成功返回后，通过遍历返回的event数组，就可知道发生的I/O事件
        n = epoll_wait(efd, events, MAXEVENTS, -1);
        printf("epoll_waite wakeup\n");
        for(i = 0; i < n; i++)
        {
            if((events[i].events & EPOLLERR) ||
                (events[i].events & EPOLLHUP) ||
                (!events[i].events & EPOLLIN))
                {
                    fprintf(stderr, "epoll error\n");
                    close(events[i].data.fd);
                    continue;
                }
                else if(listen_fd == events[i].data.fd)
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
                        // accept建立连接，并将该连接设置为非阻塞，在调用epoll_ctl把已连接套接字对应的可读事件
                        // 注册到epoll实例中，这里使用了event_data里面的fd字段，将连接套接字存储器中
                        make_nonblocking(fd);
                        event.data.fd = fd;
                        event.events = EPOLLET | EPOLLIN;// edge-triggered
                        if(epoll_ctl(efd, EPOLL_CTL_ADD, fd, &event) == -1)
                        {
                            perror("epoll_ctl add connection fd failed");
                            return -1;
                        }
                    }
                    continue;
                }
                else
                {
                    socket_fd = events[i].data.fd;
                    printf("get event on socket fd == %d\n",socket_fd);
                    while(1)
                    {
                        char buf[512];
                        if((n = read(socket_fd, buf, sizeof(buf))) < 0)
                        {
                            if(errno != EAGAIN)
                            {
                                perror("read error");
                                close(socket_fd);
                            }
                            break;
                        }
                        else if(n == 0)
                        {
                            close(socket_fd);
                            break;
                        }
                        else 
                        {
                            for(i = 0;i < n; ++i)
                            {
                                buf[i] = rot13_char(buf[i]);
                            }
                            if(write(socket_fd, buf, n) < 0)
                            {
                                perror("write error");
                                return -1;
                            }
                        }
                    }
                }
               
        }
    }
    free(events);
    close(listen_fd);
    return 0;
}