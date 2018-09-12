#include <stdio.h>
#include <sys/socket.h>
#include <sys/un.h>
#include "ipc.h"

int main(){
    int fd;
    struct sockaddr_un addr;
    int ret;
    char buff[256];
    int len;

    if((fd = socket(PF_UNIX, SOCK_DGRAM, 0)) < 0) {
        perror("socket");
        return -1;
    }

    memset(&addr, 0, sizeof(addr));
    addr.sun_family = AF_UNIX;
    strcpy(addr.sun_path, CLIENT_SOCK_FILE);
    unlink(CLIENT_SOCK_FILE);
    if(bind(fd, (struct sockaddr *)&addr, sizeof(addr)) < 0){
        perror("bind");
        return -1;
    }

    memset(&addr, 0, sizeof(addr));
    addr.sun_family = AF_UNIX;
    strcpy(addr.sun_path, SERVER_SOCK_FILE);
    if (connect(fd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        return -1;
    }

    strcpy(buff, "Leo Test");
    if(send(fd, buff, strlen(buff) + 1, 0) == -1) {
        perror("send");
        return -1;
    }
    printf("send Leo Test\n");

    if((len = recv(fd, buff, sizeof(buff), 0)) < 0) {
        perror("recv");
        return -1;
    }
    printf ("receive %d %s\n", len, buff);
}
