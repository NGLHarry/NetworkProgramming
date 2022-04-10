#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SERV_PORT 43211

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        perror("usage: nonblockingclient <IPaddress>");
        return -1;
    }

    int socket_fd;
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERV_PORT);
    inet_pton(AF_INET, argv[1], &server_addr.sin_sockaddr);

    socklen_t server_len = sizeof(server_addr);
    int connect_rt = connect(socket_fd, (struct sockaddr *)&server_addr, server_len);
    if(connect_rt < 0)
    {
        perror("connect failed");
        return -1;
    }

    struct linger ling;
    ling.l_onoff = 1;
    ling.l_linger = 0;
    setsockopt(socket_fd, SOL_SOCKET, SO_LINGER, &ling, sizeof(ling));
    close(socket_fd);

    exit(0);

}