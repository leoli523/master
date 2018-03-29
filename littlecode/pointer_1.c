#include <stdio.h>
#include <stdlib.h>

void main(){
    /* practice 1 */
    int m = 10;
    int *z = &m;

    printf("z sotres the address of m = %p\n", z);
    printf("*z stores the value of m  = %d\n", *z);
    printf("&m is the address of m = %p\n", &m);

    /* practice 2 */
    printf("=================================================\n");
    int n = 29;
    printf("address of m = %p , value of m = %d\n", &n, n);
    int *ab = &n;
    printf("Now ab is assigned with the address of m.\n ");
    printf("address of pointer ab = %p , value of pointer ab = %d\n", ab, *ab);
    n = 34;
    printf("The value of n assigned to 34 now.\n ");
    printf("address of pointer ab = %p , value of pointer ab = %d\n", ab, *ab);
    *ab=7;
    printf("The pointer variable ab is assigned with the value 7 now.\n ");
    printf("address of n = %p , value of n = %d\n", &n, n);

    /* practice 3 */
    printf("=================================================\n");
    m = 300;
    float fx = 300.60006;
    char cht = 'z';
    printf("address of m = %p , value of m = %d\n", &m, m);
    printf("address of fx = %p , value of fx = %f\n", &fx, fx);
    printf("address of cht = %p , value of cht = %c\n", &cht, cht);

    /* practice 4 */
    printf("==================== add two numbers using pointers =============================\n");
    int num1, num2;
    printf(" Input the first number : ");
    scanf("%d", &num1);
    printf(" Input the second  number : ");
    scanf("%d", &num2);
    int *ptr1 = &num1, *ptr2 = &num2;
    int sum = *ptr1 + *ptr2;
    printf("The sum of the entered numbers is : %d\n",sum);

    /* practice 5 */
    printf("==================== add numbers using call by reference =============================\n");
    int sum2 = twoSum(&num1, &num2);
    printf("The sum of the entered numbers is : %d\n",sum);

    /* practice 6 */
    printf("==================== find the maximum number between two numbers using a pointer. =============================\n");
    if ( *ptr1 > *ptr2 )
        printf("%d is the maximum number.\n", *ptr1);
    else
        printf("%d is the maximum number.\n", *ptr2);

    /* practice 7 */
    printf("==================== store n elements in an array and print the elements using pointer. =============================\n");
    int arr1[25] = {0}, d;
    printf(" Input the number of elements to store in the array :");
    scanf("%d", &d);
    for(int i=0;i<d;i++){
        printf("element %d : ", i);
        scanf("%d", arr1+i);
    };
    for(int j=0;j<d;j++){
        printf("element %d = %d \n",j,  *(arr1+j));
    };
}

int twoSum(int *a, int *b)
{
    return (*a + *b);
}
