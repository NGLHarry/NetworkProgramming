#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

#define MAXLINE 4096

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        perror("usage: unixdataclient <local path>");
        return -1;
    }

    int sockfd;
    sockfd = socket(AF_LOCAL, SOCK_DGRAM, 0 );

    struct sockaddr_un client_addr, server_addr;
    
    bzero(&client_addr,sizeof(client_addr));
    client_addr.sun_family = AF_LOCAL;
    strcpy(client_addr.sun_path, tmpnam(NULL));

    if(bind(sockfd, (struct sockaddr *)&client_addr, sizeof(client_addr)) < 0)
    {
        perror("bind error\n");
        return -1;
    }

    bzero(&server_addr,sizeof(server_addr));
    server_addr.sun_family = AF_LOCAL;
    strcpy(server_addr.sun_path, argv[1]);

    char send_line[MAXLINE];
    bzero(send_line, sizeof(send_line));
    char recv_line[MAXLINE];

    while (fgets(send_line,MAXLINE,stdin) != NULL)
    {
        int i = strlen(send_line);
        if(send_line[i - 1] == '\n')
        {
            send_line[i - 1] = 0;
        }

        size_t nbytes = strlen(send_line);
        printf("now sending %s \n",send_line);

        if(sendto(sockfd, send_line, nbytes, 0, (struct sockaddr *)&server_addr,sizeof(server_addr)) != nbytes)
        {
            perror("sendto error\n");
            break;
        }

        int n = recvfrom(sockfd, recv_line, MAXLINE, 0, NULL, NULL);
        recv_line[n] = 0;

        fputs(recv_line, stdout);
        fputs("\n",stdout);
    }
    exit(0);
    
}