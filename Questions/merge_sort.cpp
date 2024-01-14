#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
void merge(vector<int> &arr, int s, int e)
{
    int mid = (s + e) / 2;
    int i = s;
    int j = mid+1;
    int k = s;
    vector<int> ans;
    while (i <= mid && j <= e)
    {
        if (arr[i] < arr[j])
        {
            ans[k++] = arr[i++];
        }

        else{
            ans[k++] = arr[j++];
        }
    }
    while(i<=mid){
        ans[k++] = arr[i++];
    }
    while(j<=e){
        ans[k++] = arr[j++];
    }
    for(int i = s;i<=e;i++){
        arr[i] = ans [i];
    }
}
void mergesort(vector<int> arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int mid = (s + e) / 2;
    mergesort(arr, s, mid);
    mergesort(arr, mid+1, e);

    merge(arr, s, e);
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    // vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    mergesort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i]<<" ";
    }
    return 0;
}