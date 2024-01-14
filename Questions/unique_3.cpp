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

    int cnt[64] = {0};
    for (int i = 0; i < n; i++)
    {
        int in = 0;
        int no = arr[i];
        while (no > 0)
        {
            if ((no & 1) == 1)
            {
                cnt[in]++;
                // arr[i] = arr[i] >> 1;
            }
            in++;
            no >>= 1;
        }
    }
    for (int i = 0; i < 64; i++)
    {
        cnt[i] %= 3;
    }
    int ans = 0;
    int j = 1;
    for (int i = 0; i < 64; i++)
    {
        ans += cnt[i] * j;
        j *= 2;
    }
    cout << ans;
    return 0;
}