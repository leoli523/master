#include <stdio.h>
#include <stdlib.h>
// BKDR Hash Function
unsigned int BKDRHash(char *str)
{
    unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
    unsigned int hash = 0;

    while (*str)
    {
        hash = hash * seed + (*str++);
    }

    return (hash & 0x7FFFFFFF);
}

int main(){
    char a[]="Facebook";
    char aa[]="Facebook Like";
    unsigned int b, bb;
    b = BKDRHash(a);
    bb = BKDRHash(aa);
    printf("%s:%u\n",a, b);
    printf("%s:%u\n",aa, bb);
}
