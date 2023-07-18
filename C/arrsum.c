#include <stdio.h>
int arrsum(int *p, int n)
{
    int sum = 0, i = 0;
    for (i = 0; i < n; i++)
    {
        sum += *p;
        p++;
    }
    return sum;
}
int main()
{
    int n;
    printf("enter the size of array : ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int sum = arrsum(arr, n);
    printf("the sum of array is %d", sum);
    return 0;
}