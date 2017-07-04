#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int test(const char *mask){
    printf("%s\n",mask);
    regex_t regex;
    int ret = 0;

    ret = regcomp(&regex, "(^255.(0|128|192|224|24[08]|25[245]).0.0$)|(^255.255.(0|128|192|224|24[08]|25[245]).0$)|(^255.255.255.(0|128|192|224|24[08]|252)$)", REG_ICASE  |REG_EXTENDED);

    if( ret ) {
        fprintf(stderr, "Error compiling Mask validation regex\n");
        return 1;
    }

    ret = regexec(&regex, mask, 0, NULL, 0);
    printf("%d\n",ret);
    if (ret != 0 && ret == REG_NOMATCH ) {
        printf("error\n");
        // error
        char errorbuf[100];
        regerror(ret, &regex, errorbuf, sizeof(errorbuf));
        fprintf(stderr, "Error validating Mask: %s\n", errorbuf);
    }

    regfree(&regex);

    return ret == 0;
}

void main(){

    int  a=255,b=255,c=128,d=0;
    char m[16];
    int ipaddr = (a<<24) + (b<<16) + (c<<8) + d;
    snprintf(m,sizeof(m),"%d.%d.%d.%d",a,b,c,d);
    printf("%s\n",m);
    test(m);
    printf("%x\n",ipaddr);

}
