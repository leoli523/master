#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void RemoveSpaces(char* source)
{
    char* i = source;
    char* j = source;
    while(*j != 0)
    {
        *i = *j++;
        if(*i != ' ')
            i++;
    }
    *i = 0;
}

int main() {
    char a[]="LEO DEBUG";
    RemoveSpaces(a);
    fprintf(stderr, "---%s +%d---%s----LEO DEBUG------a:%s--------\n", __FILE__, __LINE__, __FUNCTION__, a);
    return 0;
}
