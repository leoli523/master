#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DataNum 10

void bubble_sort(int data[], int size)
{
    int i, j, tmp;
    for (i=0;i<size;i++)
    {
        for (j=1;j<size-i;j++)
        {
            if (data[j-1]>data[j])
            {
                tmp = data[j];
                data[j] = data[j-1];
                data[j-1] = tmp;
            }
        }
    }
}

void main()
{
    int data[DataNum];
    int i;

    srand((unsigned)time(NULL));

    for(i=0;i<DataNum;i++)
    {
        data[i] = rand() % 101;
    }

    printf("before:");

    for(i=0;i<DataNum;i++)
    {
        printf("%d ",data[i]);
    }

    bubble_sort(data, DataNum);

    printf("\nafter:");

    for(i=0;i<DataNum;i++)
    {
        printf("%d ",data[i]);
    }


}



