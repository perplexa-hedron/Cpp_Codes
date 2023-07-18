#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int k = 0;
bool safe(int i, int j, int arr[][100], int n)
{
    for (int k = 0; k < n; k++)
    {
        if (arr[k][j] == 1)
        {
            return false;
        }
        if (arr[i][k] == 1)
        {
            return false;
        }
    }

    int k = i, l = j;
    while (k >= 0 && l < n)
    {
        if (arr[k][l] == 1)
        {
            return false;
        }
        k--;
        l++;
    }
    while (i < n && j >= 0)
    {
        if (arr[i][j] == 1)
        {
            return false;
        }
        i--;
        j--;
    }

    return true;
}
bool nqueen(int n, int i, int arr[][100])
{
    if (i == n)
    {
        k++;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] == 1)
                {
                    cout << "{" << i + 1 << "-" << j + 1 << "}"
                         << " ";
                    // (arr[i][j] == 1) ? cout<<" Q " : cout<<" _ ";
                }
            }
            // cout << endl;
        }
        cout << " ";
        return false;
    }

    for (int j = 0; j < n; j++)
    {
        if (safe(i, j, arr, n))
        {
            arr[i][j] = 1;
            bool ans = nqueen(n, i + 1, arr);
            if (ans == true)
            {
                return true;
            }
            arr[i][j] = 0;
        }
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    int arr[n][100] = {0};
    bool ans = nqueen(n, 0, arr);
    cout << endl
         << k;
    return 0;
}