#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int min(int arr[], int n)
{
    int min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    int *index = find(arr, arr + n, min);
    return (index - arr);
}
int main()
{
    int n;
    cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    cin >> key;
    int m = min(arr, n);
    // cout<<m;
    if (m != 0)
    {
        if (arr[m - 1] < key)
        {
            cout << -1;
        }
        else if (arr[m - 1] > key)
        {
            bool b = binary_search(arr + m, arr + n, key);
            if (b == false)
            {
                cout << -1;
            }
            else
            {
                int *index = find(arr + m, arr + n, key);
                cout << (index - arr);
            }
        }
        else
        {
            cout << m;
        }
    }
    else
    {
        bool b = binary_search(arr + m, arr + n, key);
        if (b == false)
        {
            cout << -1;
        }
        else
        {
            int *index = find(arr + m, arr + n, key);
            cout << (index - arr);
        }
    }
    // bool b = binary_search(arr,arr+m,key);
    // bool b2 = binary_search(arr+m,arr+n,key);
    // if(b == true && b2 == false){

    // }
    // bool b = binary_search(arr, arr + n, key);
    // if (b == true)
    // {
    //     int *indx = find(arr, arr + n, key);
    //     cout << indx - arr;
    // }
    // else
    // {
    //     cout << -1;
    // }
    return 0;
}