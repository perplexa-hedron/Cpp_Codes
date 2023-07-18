#include <iostream>
#include <vector>
using namespace std;
void staircase(int arr[30][30], int n, int m, int key)
{
    int i = 0, j = n - 1;
    bool found = 0;
    while (i < n && j >= 0)
    {
        if (arr[i][j] == key)
        {
            // cout<<i<<", "<<j;
            cout << 1;
            found = 1;
            break;
        }
        else if (arr[i][j] < key)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    if (found == 0)
    {
        cout << 0;
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    int arr[30][30];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    int key;
    cin >> key;
    staircase(arr, n, m, key);
    return 0;
}