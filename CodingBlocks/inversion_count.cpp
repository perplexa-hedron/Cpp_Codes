#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int merge(int arr[], int s, int e)
{
    int mid = (s + e) / 2;
    int i = s;
    int j = mid + 1;
    int k = s;

    int temp[100];
    int cnt = 0;
    while (i <= mid && j <= e)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            cnt += mid - i + 1;
        }
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= e)
    {
        temp[k++] = arr[j++];
    }
    for (int i = s; i <= e; i++)
    {
        arr[i] = temp[i];
    }
    return cnt;
}
int incount(int *arr, int s, int e)
{
    if (s >= e)
    {
        return 0;
    }
    int mid = (s + e) / 2;
    int x = incount(arr, s, mid);
    int y = incount(arr, mid + 1, e);
    int z = merge(arr, s, e);
    return x + y + z;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout<<incount(arr, 0, n - 1);
    return 0;
}