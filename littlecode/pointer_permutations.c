#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Practice 8 : Write a program in C to print all permutations of a given string using pointers. */

void changePosition(char *ptr1, char *ptr2){
    char tmp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = tmp;
}

void permutate(char *a, int l, int len){
    int i;
    if (l == len){
        printf("%s ", a);
    }
    else{
        for(i=l ; i <= len; i++)
        {
            changePosition((a+l), (a+i));
            permutate(a, l+1, len);
            changePosition((a+l), (a+i));
        }
    }
}

int main(){
    char str[] = "abcd";
    permutate(str, 0, strlen(str)-1);
    return 0;

}
