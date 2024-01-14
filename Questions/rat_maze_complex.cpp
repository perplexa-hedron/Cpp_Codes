#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool ans[10][10] = {0};
bool safe(int i, int j, int n, int m, char arr[][10])
{
    if (i >= n || i < 0)
    {
        return false;
    }
    if (j >= m || j < 0)
    {
        return false;
    }
    if (arr[i][j] == 'X' || ans[i][j] == true)
    {
        return false;
    }
    return true;
}

bool maze(int i, int j, int n, int m, char arr[][10])
{

    if (i == n - 1 && j == m - 1)
    {
        ans[i][j] = true;
        return true;
    }

    if (safe(i, j, n, m, arr))
    {
        ans[i][j] = true;
        if (maze(i, j - 1, n, m, arr) == true)
        {
            return true;
        }
        if (maze(i, j + 1, n, m, arr) == true)
        {
            return true;
        }
        if (maze(i + 1, j, n, m, arr) == true)
        {
            return true;
        }
        if (maze(i - 1, j, n, m, arr) == true)
        {
            return true;
        }
        ans[i][j] = false;
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    char arr[n][10];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    if (maze(0, 0, n, m, arr))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    else
    {
        cout << "NO PATH FOUND";
    }
    return 0;
}