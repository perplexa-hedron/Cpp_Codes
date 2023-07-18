#include <stdio.h>
#include <math.h>
#include <string.h>
void swap(int *p1, int *p2)
{
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main()
{
    int a, b;
    printf("enter the numbers 1: ");
    scanf("%d", &a);
    printf("enter the numbers 2: ");
    scanf("%d", &b);
    int *ptr1 = &a, *ptr2 = &b;
    swap(&a, &b);
    printf("1=%d 2 =%d", a, b);
    return 0;
}
