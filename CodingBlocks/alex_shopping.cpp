#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int q;
    cin >> q;
    int a[q];
    int k[q];
    for (int i = 0; i < q; i++)
    {
        cin >> a[i] >> k[i];
    }
    for (int i = 0; i < q; i++)
    {
        int r = 0;
        for (int j = 0; j < n; j++)
        {
            int x;
            if (a[i] % arr[j] == 0)
            {
                r++;
            }
            // r += a [i] % arr[j];
        }
        //cout << r << " ";
        // cout<<r-a[i]<<" ";
        if (r >= k[i])
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}