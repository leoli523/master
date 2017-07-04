#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#define MAX1 5 
#define MAX2 5
#define SWAP(x,y) {int t; t = x; x = y; y = t;} 

int partition(int[], int, int); 
void quickSort(int[], int, int); 
void mergeSort(int[], int, int[], int, int[]); 

int main(void) { 
    srand(time(NULL)); 
    
    int number1[MAX1] = {0}; 
    int number2[MAX1] = {0}; 
    int number3[MAX1+MAX2] = {0}; 

    printf("before:"); 
    printf("\nnumber1[]:"); 
    int i;
    for(i = 0; i < MAX1; i++) { 
        number1[i] = rand() % 100; 
        printf("%d ", number1[i]); 
    }
    printf("\nnumber2[]:"); 
    for(i = 0; i < MAX2; i++) { 
        number2[i] = rand() % 100; 
        printf("%d ", number2[i]); 
    }

    quickSort(number1, 0, MAX1-1);
    quickSort(number2, 0, MAX2-1);


    printf("\nafter"); 
    printf("\nnumber1[]:"); 
    for(i = 0; i < MAX1; i++) 
        printf("%d ", number1[i]); 
    printf("\nnumber2[]:"); 
    for(i = 0; i < MAX2; i++) 
        printf("%d ", number2[i]); 


    mergeSort(number1, MAX1, number2, MAX2, number3); 

    printf("\nafter merge:"); 
    for(i = 0; i < MAX1+MAX2; i++) 
        printf("%d ", number3[i]); 
    
    printf("\n"); 

    return 0; 

}

int partition(int number[], int left, int right) { 
    int s = number[right]; 
    int i = left - 1; 
    int j;
    int g;

    for(j = left; j < right; j++) { 
        if(number[j] <= s) { 
            i++; 
            SWAP(number[i], number[j]);
        } 
    } 

    SWAP(number[i+1], number[right]); 
    printf("i+1:[%d]\n ", i+1);
    return i+1; 
} 

void quickSort(int number[], int left, int right) { 
    if(left < right) { 
        int q = partition(number, left, right); 
        quickSort(number, left, q-1); 
        quickSort(number, q+1, right); 
    } 
} 

void mergeSort(int number1[], int M, int number2[], 
                int N, int number3[]) { 
    int i = 0, j = 0, k = 0; 
    while(i < M && j < N) { 
        if(number1[i] <= number2[j]) 
            number3[k++] = number1[i++]; 
        else 
            number3[k++] = number2[j++]; 
    } 

    while(i < M) 
        number3[k++] = number1[i++]; 
    while(j < N) 
        number3[k++] = number2[j++]; 
} 