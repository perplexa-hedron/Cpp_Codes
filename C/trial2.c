#include <stdio.h>
void merge(int arr[], int f, int mid, int l){
    
}
void mergesort(int arr[], int f, int l)
{
    if (f < l)
    {
        int mid = (f + l) / 2; 
        mergesort(arr, f, mid);
        mergesort(arr, mid + 1, l);
        merge(arr, f, mid, l);
    }
}