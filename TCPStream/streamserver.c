#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
#include <netinet/in.h>

#define SERV_PORT 43211
#define LISTENQ 1024

static int count;

size_t readn(int fd, void *buffer, size_t size)
{
    char *buffer_pointer = buffer;
    int length = size;

    while(length > 0)
    {
        int result = read(fd, buffer_pointer, length);
        if(result < 0)
        {
            if(errno == EINTR)
            {
                continue; // 考虑非阻塞的情况，需要再次调用read
            }
            else
            {
                return -1;
            }
        }
        else if(result == 0)
        {
            break;  //EOF (End of File)表示套接字关闭
        }
        length  -= result;
        buffer_pointer += result;
    }
    return(size - length); //返回的是实际读取的字节数
}

size_t read_message(int fd, char*buffer, size_t length)
{
    u_int32_t msg_length;
    u_int32_t msg_type;
    int rc;

    rc = readn(fd, (char *)&msg_length, sizeof(u_int32_t));
    if(rc != sizeof(u_int32_t))
    {
        return rc < 0 ? -1: 0;
    }
    msg_length = ntohl(msg_length);

    rc = readn(fd, (char *)&msg_type, sizeof(u_int32_t));
    if(rc != sizeof(u_int32_t))
    {
        return rc < 0 ? -1 : 0;
    }

    // 判断buffer是否可以容纳下数据
    if(msg_length > length)
    {
        perror("msg_length > length");
        return -1;
    }

    rc = readn(fd, buffer, msg_length);
    if(rc != msg_length)
    {
        return rc < 0 ? -1 : 0;
    }
    return rc;

}

int main(int argc, char *argv[])
{
    int listen_fd;
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(SERV_PORT);

    int on = 1;
    setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &on ,sizeof(on));

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

    int connfd;
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);

    if((connfd = accept(listen_fd, (struct sockaddr *)&client_addr, &client_addr)) < 0)
    {
        perror("accept failed");
        return -1;
    }

    char buf[128];
    count = 0;
    
    while(1)
    {
        int n = read_message(connfd, buf, sizeof(buf));
        if(n < 0)
        {
            perror("error read message");
            return -1;
        }
        else if(n == 0)
        {
            printf("client will closing");
            return 0;
        }
        buf[n] = 0;
        printf("received %d bytes: %s\n",n, buf);
        count++;
    }
    exit(0);

}

