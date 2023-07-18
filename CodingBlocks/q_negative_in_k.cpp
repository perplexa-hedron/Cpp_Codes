#include <iostream>
using namespace std;

void negative_integer(long long arr[], long long k, long long n)
{
    long long n_idx = 0;
    long long n_ele;

    for (long long i = k - 1; i < n; i++)
    {
        while ((n_idx < i) && (n_idx <= i - k || arr[n_idx] >= 0))
        {
            n_idx++;
        }
        if (arr[n_idx] < 0)
        {
            n_ele = arr[n_idx];
        }
        else
        {
            n_ele = 0;
        }
        cout << n_ele << " ";
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        long long arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        negative_integer(arr, k, n);
        cout << endl;
    }
}
