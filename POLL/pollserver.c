#include <stdio.h>
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

int main(int argc, char *argv[])
{
    int listen_fd, connected_fd;
    int ready_number;
    ssize_t n;
    char buf[MAXLINE];
    struct sockaddr_in client_addr;

    listen_fd = tcp_server_listen(SERV_PORT);

    //初始化pollfd数组，这个数组的第一个元素是listen_fd,其余的用来记录将要连接的connect_fd
    //将监听套接字 listen_fd 和对应的 POLLRDNORM 事件加入到 event_set 里，表示我们期望系统内核检测监听套接字上的连接建立完成事件。
    struct pollfd event_set[INIT_SIZE];
    event_set[0].fd = listen_fd;
    event_set[0].events = POLLRDNORM;

    //用-1表示这个数组位置还没有被占用
    //对应 pollfd 里的文件描述字 fd 为负数，poll 函数将会忽略这个 pollfd
    int i;
    for(int i = 1; i < INIT_SIZE; i++)
    {
        event_set[i].fd = -1;
    }

    for(;;)
    {
        //调用 poll 函数来进行事件检测。poll 函数传入的参数为 event_set 数组，数组大小 INIT_SIZE 和 -1
        //之所以传入 INIT_SIZE，是因为 poll 函数已经能保证可以自动忽略 fd 为 -1 的 pollfd，否则我们每次都需要计算一下 event_size 里真正需要被检测的元素大小；
        //timeout 设置为 -1，表示在 I/O 事件发生之前 poll 调用一直阻塞。
        if((ready_number = poll(event_set, INIT_SIZE, -1)) < 0)
        {
            perror("poll failed");
            return -1;
        }
        // 使用了如 event_set[0].revent 来和对应的事件类型进行位与操作
        // 因为 event 都是通过二进制位来进行记录的，位与操作是和对应的二进制位进行操作，一个文件描述字是可以对应到多个事件类型的。
        if(event_set[0].revents & POLLRDNORM)
        {
            socklen_t client_len = sizeof(client_addr);
            //调用 accept 函数获取了连接描述字
            connected_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &client_len);

            //找到一个可以记录该连接套接字的位置
            for(i = 1; i < INIT_SIZE; i++)
            {
                if(event_set[i].fd < 0)
                {
                    printf("event_set:%d\n",i);
                    event_set[i].fd = connected_fd;
                    event_set[i].events = POLLRDNORM;
                    break;
                }
            }
            //event_set 已经被很多连接充满了，没有办法接收更多的连接了
            if( i == INIT_SIZE)
            {
                perror("can not hold so many clients");
                return -1;
            }
            //加速优化能力，因为 poll 返回的一个整数，说明了这次 I/O 事件描述符的个数，
            //如果处理完监听套接字之后，就已经完成了这次 I/O 复用所要处理的事情，那么我们就可以跳过后面的处理，再次进入 poll 调用。
            if(--ready_number <= 0)
                continue;
        }
        //循环处理是查看 event_set 里面其他的事件，也就是已连接套接字的可读事件
        for(i = 1; i < INIT_SIZE; i++)
        {
            int socket_fd;
            if((socket_fd = event_set[i].fd) < 0)
                continue;
            //通过检测 revents 的事件类型是 POLLRDNORM 或者 POLLERR，我们可以进行读操作。
            if(event_set[i].revents & (POLLRDNORM | POLLERR))
            {
              
                //读取数据正常之后，再通过 write 操作回显给客户端；
                if((n = read(socket_fd, buf, MAXLINE)) > 0)
                {  
                    if(write(socket_fd, buf, n) < 0)
                    {  
                        perror("write error");
                        return -1;
                    }
                }
                else if(n == 0 || errno == ECONNRESET)
                {
                    //如果读到 EOF 或者是连接重置，则关闭这个连接，并且把 event_set 对应的 pollfd 重置
                    close(socket_fd);
                    event_set[i].fd = -1;
                }
                else 
                {
                    perror("read error");
                    return -1;
                }
                if(--ready_number <= 0)
                    break;
            }
        }
    }
}