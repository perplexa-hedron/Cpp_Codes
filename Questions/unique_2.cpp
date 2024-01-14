#include <iostream>
#include <vector>
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
    int a = 0;
    for (int i = 0; i < n; i++)
    {
        a = (a ^ arr[i]);
    }
    int xr = a;
    // cout<<a;
    int in = 0;
    while (a > 0)
    {
        if ((a & 1) > 0)
        {
            break;
        }
        in++;
        a = a >> 1;
    }
    // cout<<a;
    int x = (1 << in);
    int u1 = 0;
    for (int i = 0; i < n; i++)
    {
        if ((arr[i] & x) == 0)
        {
            u1 ^= arr[i];
        }
    }
    cout << u1 << " " << (xr ^ u1);
    return 0;
}