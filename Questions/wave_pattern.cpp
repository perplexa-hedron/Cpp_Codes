#include <iostream>
// #include <vector>
using namespace std;
void wave_print_row(int arr[100][100], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < m; j++)
            {
                cout << arr[i][j] << ", ";
            }
        }
        else
        {
            for (int j = m - 1; j >= 0; j--)
            {
                cout << arr[i][j] << ", ";
            }
        }
    }
    cout << "END";
}
void wave_print_column(int arr[][100], int n, int m)
{
    for (int j = 0; j < m; j++)
    {
        if (j % 2 == 0)
        {
            for (int i = 0; i < n; i++)
            {
                cout << arr[i][j] << ", ";
            }
        }
        else
        {
            for (int i = n - 1; i >= 0; i--)
            {
                cout << arr[i][j] << ", ";
            }
        }
    }
    cout << "END";
}
int main()
{
    int n, m;
    cin >> n >> m;
    int arr[100][100];
    // int val=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            // arr[i][j] = val;
            // val++;
        }
    }
    // wave_print_column(arr, n, m);
    wave_print_row(arr, n, m);
    return 0;
}