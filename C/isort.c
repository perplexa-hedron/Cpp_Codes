#include <stdio.h>
int main()
{
    int n;
    scanf("%d" ,&n);
    int arr[n], hole, temp;
    //printf("Enter the elements of array: \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    for(int i = 1; i < n; i++)
    {
        temp = arr[i];
        hole = i-1;
        while(temp < arr[hole] && hole >= 0)
        {
            arr[hole + 1] = arr[hole];
            hole = hole -1;
        }
        arr[hole + 1] = temp;
    }
    for(int i = 0;i < n; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}