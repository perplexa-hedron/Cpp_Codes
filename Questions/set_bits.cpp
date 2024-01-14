#include <iostream>
#include <vector>
using namespace std;
int count(int b)
{
    int ans = 0;
    while (b > 0)
    {
        if ((b & 1) == 1)
        {
            ans++;
        }
        b >>= 1;
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        cout << count(arr[i]) << endl;
    }
    return 0;
}