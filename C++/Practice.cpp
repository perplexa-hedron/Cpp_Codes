#include <bits/stdc++.h>
using namespace std;
void merge(int arr[], int f, int mid, int l)
{
    int n1 = mid - f + 1;
    int n2 = l - mid;

    int a[n1];
    int b[n2];

    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[f + i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = f;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            arr[k] = a[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = b[j];
            j++;
            k++;
        }
    }
    while (i < n1)
    {
        arr[k] = a[i];
        k++;
        i++;
    }

    while (j < n2)
    {
        arr[k] = b[j];
        k++;
        j++;
    }
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

int main()
{
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    mergesort(a, 0, n);

    for (int i = 0; i < n; i++)
    {
        cout << a[i]<< " ";
    }
    return 0;
}