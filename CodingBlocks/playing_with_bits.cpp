#include <iostream>
#include <vector>
using namespace std;
int count(int x)
{
    int ans = 0;
    while (x > 0)
    {
        if ((x & 1) == 1)
        {
            ans++;
        }
        x = x >> 1;
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        int ans = 0;
        for (int i = a; i < (b + 1); i++)
        {
            ans += count(i);
        }
        cout << ans << endl;
    }
    return 0;
}