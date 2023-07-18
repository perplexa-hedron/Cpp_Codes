#include <stdio.h>
int main()
{
    int arr[10], min, temp;
    printf("Enter the elements of array: \n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < 9; i++)
    {
        min = i;
        for (int j = i + 1; j < 10; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }

        if (min != i)
        {
            temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}