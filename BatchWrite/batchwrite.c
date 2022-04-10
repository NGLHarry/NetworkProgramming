#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define SERV_PORT 43211

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        perror("usage:batchwrite <IPADDRESS>");
        return -1;
    }
    int socket_fd;
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERV_PORT);
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);
    int connect_fd = connect(socket_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if(connect_fd < 0)
    {
        perror("connect failed");
        return -1;
    }

    char buf[128];
    struct iovec iov[2];
    char *send_one = "hello";
    iov[0].iov_base = send_one;
    iov[0].iov_len = strlen(send_one);
    iov[1].iov_base = buf;
    while(fgets(buf, sizeof(buf), stdin) != NULL)
    {
        iov[1].iov_len = strlen(buf);
        int n = htonl(iov[1].iov_len);
        if(writev(socket_fd, iov, 2) < 0)
        {
            perror("write failure");
            return -1;
        }
    }
    exit(0);
}