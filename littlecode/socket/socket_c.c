#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <stdio.h>
int main()
{
    int sockfd;
    struct sockaddr_in dest;
    char buffer[128];
    char resp[10]="clientack";

    /* create socket */
    sockfd = socket(PF_INET, SOCK_STREAM, 0);

    /* initailize value in dest */
    bzero(&dest, sizeof(dest));
    dest.sin_family = PF_INET;
    dest.sin_port = htons(8889);
    dest.sin_addr.s_addr = inet_addr("127.0.0.1");

    /* Connecting to server */
    connect(sockfd, (struct sockaddr*)&dest, sizeof(dest));

    bzero(buffer,128);
    /* Receive message from the server and print to screen */
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("receive from server: %s\n", buffer);
    send(sockfd, resp, sizeof(resp), 0);

    /* Close connection */
    close(sockfd);

    return 0;
}

