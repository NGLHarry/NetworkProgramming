#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAXLINE 1024
#define SERV_PORT 43211

tcp_client(char *address, int port)
{
    int socket_fd;
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERV_PORT);
    inet_pton(AF_INET, address, server_addr.sin_addr);

    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int connfd_rt  = connect(socket_fd, (struct sockaddr *)&client_addr, client_len);
    if(connfd_rt < 0)
    {
        perror("connect failed");
        return -1;
    }
    return socket_fd;
}

int main(int argc, char *argv[])
{   
    if(argc != 2)
    {
        perror("usage:select <IPaddress>");
        return -1;
    }

    int socket_fd;
    socket_fd = tcp_client(argv[1], SERV_PORT);

    char recv_line[MAXLINE], send_line[MAXLINE];
    int n;

    fd_set readmask;
    fd_set allreads;
    FD_ZERO(&allreads);
    FD_SET(0, &allreads);
    FD_SET(socket_fd, &allreads);

    for(;;)
    {
        readmask = allreads;
        int rc = select(socket_fd+1, &readmask, NULL, NULL, NULL);
        if(rc <= 0)
        {
            perror("select failed");
            return -1;
        }

        if(FD_ISSET(socket_fd, &readmask))
        {
            n = read(socket_fd, recv_line, MAXLINE);
            if(n < 0)
            {
                perror("read error");
                return -1;
            }
            else if(n == 0)
            {
                printf("server terminated\n");
                return 0;
            }
            recv_line[n] = 0;
            fputs(recv_line, stdout);
            fputs("\n", stdout);
        }

        if(FD_ISSET(STDIN_FILENO, &readmask))
        {
            if(fgets(send_line, MAXLINE, stdin) != NULL)
            {
                int i = strlen(send_line);
                if(send_line[i - 1] == '\n')
                {
                    send_line[i - 1] = 0;
                }
                printf("now sending %s\n",send_line);
                ssize_t rt = write(socket_fd, send_line, strlen(send_line));
                if(rt < 0)
                {
                    perror("write failed");
                    return -1;
                }
                printf("send bytes: %zu \n",rt);
            }
        }
    }
}