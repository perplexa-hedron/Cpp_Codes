#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int ans[100][100] = {0};
bool maze(int i, int j, int n, int m, char arr[][100])
{
    if (i == n - 1 && j == m - 1)
    {
        ans[i][j] = 1;
        for (int k = 0; k < n; k++)
        {
            for (int l = 0; l < m; l++)
            {
                cout << ans[k][l] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }

    ans[i][j] = 1;
    if (j + 1 < m && arr[i][j + 1] != 'X')
    {
        bool sfr = maze(i, j + 1, n, m, arr);
        if (sfr == true)
        {
            return true;
        }
    }
    if (i + 1 < n && arr[i + 1][j] != 'X')
    {
        bool sfd = maze(i + 1, j, n, m, arr);
        if (sfd == true)
        {
            return true;
        }
    }


    ans[i][j] = 0;
    return false;
}
int main()
{
    int n, m;
    cin >> n >> m;
    char arr[n][100];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    bool bans = maze(0, 0, n, m, arr);
    if (bans == false)
    {
        cout << -1;
    }
    return 0;
}