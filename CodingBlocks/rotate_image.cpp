#include <iostream>
#include <vector>
using namespace std;
void transpose(int arr[100][100], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < m; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
}
void rotate_clockwise(int arr[100][100], int n, int m)
{
    transpose(arr, n, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
void rotate_anti(int arr[100][100], int n, int m)
{
    transpose(arr, n, m);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
// int main()
// {
//     int val = 1;
//     int n, m;
//     cin >> n >> m;
//     int arr[100][100];
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             arr[i][j] = val;
//             val++;
//         }
//     }

//     // Frotate_clockwise(arr, n, m);
//     rotate_anti(arr, n, m);
//     transpose(arr,n,m);
//     return 0;
// }
int main()
{
    // int val = 1;
    int n;
    cin >> n;
    int arr[100][100];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            // arr[i][j] = val;
            // val++;
        }
    }

    // Frotate_clockwise(arr, n, m);
    rotate_anti(arr, n, n);
    // transpose(arr, n, n);
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //         // arr[i][j] = val;
    //         // val++;
    //     }
    //     cout << endl;
    // }
    return 0;
}