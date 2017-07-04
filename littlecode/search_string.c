#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

void main(){
    char *val, *c;
    int channel;
    char a[]="          Current Frequency:2.412 GHz (Channel 1)";
    int wlanIdx;

    val = a;

    if((c = strstr(val, "Channel ")) != NULL)
    {
        channel = atoi(c + strlen("Channel "));
    }

    printf("%d",channel);
}

