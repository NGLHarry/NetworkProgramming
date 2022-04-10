#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define MESSAGE_SIZE 102400

void send_data(int sockfd)
{
    char *query;
    query = (char *)malloc(MESSAGE_SIZE+1);
    for(int i = 0; i < MESSAGE_SIZE; i++)
    {
        query[i] = 'a';
    }
    query[MESSAGE_SIZE] = "\0";

    const char *cp;
    cp = query;
    size_t remaining = strlen(query);
    while(remaining)
    {
        int n_writen = send(sockfd, cp, remaining, 0);
        fprintf(stdout, "send into buffer %ld \n",n_writen);
        if(n_writen <= 0)
        {
            printf("send faild...\n");
            return ;
        }
        remaining -= n_writen;
        cp += n_writen;
    }
    return ;
}


int main(int argc,char *argv[])
{
    int sockfd;
    struct sockaddr_in servaddr;

    if(argc != 2)
    {
        printf("argc:%d\n",argc);
        printf("usage:tcpclient <IPaddress> \n");
        return -1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if( sockfd < 0 )
	{
		perror("socket");
		exit(EXIT_FAILURE);
	}

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(12345);
    inet_pton(AF_INET,argv[1], &servaddr.sin_addr);
    int connect_rt = connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    if(connect_rt < 0)
    {
        printf("connect failed \n");
        return -1;
    }
    send_data(sockfd);
    exit(0);

}