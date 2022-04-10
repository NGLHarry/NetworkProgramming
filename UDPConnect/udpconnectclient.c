#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>


#define MAXLINE 4096
#define SERV_PORT 43211

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        perror("usage: udpclient1 <IPaddress>");
        return -1;
    }

    int socket_fd;
    socket_fd = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERV_PORT);
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    socklen_t server_len = sizeof(server_addr);

    if(connect(socket_fd, (struct sockaddr *)&server_addr, server_len))
    {
        perror("connect failed");
        return -1;
    }

    struct sockaddr *reply_addr;
    reply_addr = malloc(server_len);

    char send_line[MAXLINE], recv_line[MAXLINE+1];
    socklen_t len;
    int n;

    while(fgets(send_line, MAXLINE, stdin) != NULL)
    {
        int i = strlen(send_line);
        if(send_line[i-1] == '\n')
        {
            send_line[i-1] = 0;
        }
        printf("now sending %s\n",send_line);
        size_t rt = sendto(socket_fd, send_line, strlen(send_line), 0, 
            (struct sockaddr *)&server_addr, server_len);
        // size_t rt = send(socket_fd, send_line, sizeof(send_line), 0);
        if(rt < 0)
        {
            perror("sendto failed");
            return -1;
        }
        printf("send bytes: %zu \n", rt);

        len = 0;
        recv_line[0] = 0;
        n = recvfrom(socket_fd, recv_line, MAXLINE, 0, 
            (struct sockaddr *)&reply_addr, &len);
        //n = recv(socket_fd, recv_line, MAXLINE, 0);
        if(n < 0)
        {
            perror("recvfrom failed");
            return -1;
        }
        recv_line[n] = 0;
        fputs(recv_line, stdout);
        fputs("\n",stdout);
    }
    exit(0);
}
