#include <stdio.h>
void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int partition(int arr[], int f, int l)
{
    int pivot = arr[l];
    int i = f - 1;
    for (int j = f; j < l; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, l);
    return i + 1;
}
void quicksort(int arr[], int f, int l)
{
    if (f < l)
    {
        int pi = partition(arr, f, l);
        quicksort(arr, f, pi - 1);
        quicksort(arr, pi + 1, l);
    }
}
int main()
{
    int arr[] = {2, 1, 5, 3, 6, 7, 8, 9, 10, 4};
    quicksort(arr, 0, 9);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}