#include <stdio.h>
int main()
{
    int arr[10];
    printf("Enter the array\n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the number you want to search \n");
    int n;
    scanf("%d", &n);
    int i = 0;
    while (i < 10)
    {
        if (arr[i] == n)
        {
            printf("Found at %d", i);
        }
        i++;
    }
    return 0;
}