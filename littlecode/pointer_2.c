#include <stdio.h>
#include <stdlib.h>

void main(){
    /* practice 9 */
    printf("==================== Write a program in C to find the largest element using Dynamic Memory Allocation. =============================\n");
    int d, *ptr;
    printf(" Input the number of elements to store in the array :");
    scanf("%d", &d);
    ptr = malloc(d * sizeof(int));
    if (ptr == NULL){
        exit(-1);
    };
    for(int i=0;i<d;i++){
        printf("element %d : ", i);
        scanf("%d", ptr+i);
    };
    for(int j=0;j<d;j++){
        if (*ptr < *(ptr+j))
            *ptr=*(ptr+j);
    };
    printf("max : %d\n", *ptr);
    free(ptr);
}

