#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define CW_IPV4_PRINT_LIST(_addr) ((unsigned char*)&(_addr))[0],\
							((unsigned char*)&(_addr))[1],\
							((unsigned char*)&(_addr))[2],\
							((unsigned char*)&(_addr))[3]
void main(){
	unsigned long addr;
	char val[16]="192.168.50.20";
	char ipaddr[16];
	char *c;

	addr = inet_addr(val);
	//while(*c != ' ' && *c != '\0')
        //{
        //    c++;
        //}
	//c++;  

	printf("%lu\n",addr);
    printf("%u.%u.%u.%u\n",CW_IPV4_PRINT_LIST(addr));

	addr += htonl(50);

	printf("%lu\n",addr);
	printf("%u.%u.%u.%u\n",CW_IPV4_PRINT_LIST(addr));
}

