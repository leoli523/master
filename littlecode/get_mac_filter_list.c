#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

void main(){
    int len;
    int *count;
    int j=0,a=1;
    char *c;
    char val[]="00:00:00:01:00:0f 00:00:00:00:00:02 00:00:00:00:00:03";
    unsigned int mac[6];
    if(val[0] == '\0')
    {
        printf("%s\n", "no macfilter");
    }

    len = strlen(val);

    while(val[len - 1] == ' ')
    {
        val[len - 1] = '\0';
        len--;
        printf("%d\n", len);
    }  

    count = &a;
    c = val;

    while(*c != '\0')
    {

        if(*c == ' ')
        {
            (*count)++;
        }
        c++;
    }
    int i=0;
    c = val;
    printf("%d\n", *count);
    printf("%s\n",c);
    do
    {
        sscanf(c, "%x:%x:%x:%x:%x:%x",&mac[0], &mac[1], &mac[2], &mac[3], &mac[4], &mac[5]) ;
        
        for (j=0;j<6;j++)
        {
            printf("%02x\n", (unsigned char) mac[j]);
        }


        while(*c != ' ' && *c != '\0')
        {
            c++;
        }

        if(*c == '\0')
        {
            break;
        }
        else
        {
            c++;
        }
        i++;
    }
    while(1);

}

