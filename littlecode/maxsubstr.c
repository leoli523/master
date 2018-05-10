#include <stdio.h>
#include <stdlib.h>
#define SECONDS_PER_YEAR 60 * 60 * 24 * 365UL
#define MIN(a,b) ((a >= b) ? a : b)
void func(void) {
  int a = 14;
  int b = sizeof(a);
  ++a;
  printf("%d, %d\n", a, b);
}

int substrNum(char *s1, char *s2)
{
    
    char *p1 = s1;
    char *p2 = s2;
    int num = 0;
    while(*p1 != '\0'){
        if (*p1 == *p2)
            p2++;
        p1++;
        if (*p2 == '\0')
        {
            num++;
            p2 = s2;
        }

    }
    fprintf(stderr, "---%s +%d---%s----LEO DEBUG------%d--------\n", __FILE__, __LINE__, __FUNCTION__, num);
    return 10;
}

void main(){
    char str1[200];
    char str2[200];
    int num = 0;
    printf("---INPUT STRING--1---\n");
    scanf("%s", str1);
    printf("---INPUT STRING--2---\n");
    scanf("%s", str2);
    fprintf(stderr, "---%s +%d---%s----LEO DEBUG------str1:%s---str2:%s-----\n", __FILE__, __LINE__, __FUNCTION__, str1, str2);
    num = substrNum(str1, str2);
    fprintf(stderr, "---%s +%d---%s----LEO DEBUG------num:%d-------\n", __FILE__, __LINE__, __FUNCTION__, num);
}

