#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, ans = 0, j;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> j;
        ans = ans ^ j;
    }
    cout << ans;
    return 0;
}