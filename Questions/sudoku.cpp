#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
bool safe(int num, int i, int j, int arr[][9], int n)
{
    for (int k = 0; k < n; k++)
    {
        if (arr[i][k] == num || arr[k][j] == num)
        {
            return false;
        }
    }
    int rt = sqrt(n);
    int sx = (i / rt) * rt;
    int sy = (j / rt) * rt;

    for (int x = sx; x < sx + 3; x++)
    {
        for (int y = sy; y < sy + 3; y++)
        {
            if (arr[x][y] == num)
            {
                return false;
            }
        }
    }

    return true;
}

bool sudoku(int arr[][9], int i, int j, int n)
{
    if (i == n)
    {
        for (int k = 0; k < n; k++)
        {
            for (int l = 0; l < n; l++)
            {
                // cout << arr[k][l] << " ";
            }
            // cout << endl;
        }
        // cout<<endl;
        return true;
    }
    if (j == n)
    {
        return sudoku(arr, i + 1, 0, n);
    }
    if (arr[i][j] != 0)
    {
        return sudoku(arr, i, j + 1, n);
    }
    for (int num = 1; num <= n; num++)
    {
        if (safe(num, i, j, arr, n))
        {
            arr[i][j] = num;
            if (sudoku(arr, i, j + 1, n) == true)
            {
                return true;
            }
        }
    }
    arr[i][j] = 0;
    return false;
}

int main()
{
    // int n;
    // cin>>n;
    int arr[9][9] = {0};
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> arr[i][j];
        }
    }

    bool ans = sudoku(arr, 0, 0, 9);
    if(ans == true) cout<<"Yes";
    else cout<<"N";
    return 0;
}