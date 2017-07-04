#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
 
int main() {
    int a = 0x12345678;
    int b = htonl(a);
    printf("%x",b);
    if (b == a)
        printf("Big Endian\n");
    else
        printf("Little Endian\n");
    return 0;
}
