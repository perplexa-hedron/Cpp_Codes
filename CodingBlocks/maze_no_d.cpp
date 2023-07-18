#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int k = 0;
bool safe(int n, int m, int i, int j)
{
    if (i > n - 1 || j > m - 1)
    {
        return false;
    }
    return true;
}
bool maze(int n, int m, int i, int j, string ans)
{
    if (i >= n || j >= m)
    {
        return false;
    }
    if (i == n - 1 && j == m - 1)
    {
        cout << ans << " ";
        k++;
        return false;
    }

    if (safe(n, m, i + 1, j))
    {
        if (maze(n, m, i + 1, j, ans + 'V'))
        {
            return true;
        }
    }
    if (safe(n, m, i, j + 1))
    {
        if (maze(n, m, i, j + 1, ans + 'H'))
        {
            return true;
        }
    }
    // if (safe(n, m, i + 1, j + 1))
    // {
    //     if (maze(n, m, i + 1, j + 1, ans + 'D'))
    //     {
    //         return true;
    //     }
    // }
    return false;
}
int main()
{
    int n, m;
    cin >> n >> m;
    maze(n, m, 0, 0, "");
    cout << endl
         << k;
    return 0;
}