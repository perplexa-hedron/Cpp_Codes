#include <iostream>
#include <vector>
using namespace std;
void diagonal(int arr[100][100], int n, int m)
{
    int i = 0;
    int j = 0;
    bool count = 0;
    cout<<arr[i][j]<<" ";
    while (i < n && j < n)
    {
        // cout<<arr[i][j]<<" ";
        if(i <=n-1){
            
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    int arr[100][100];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    return 0;
}
// 11 12 21 31 22 13 23 32 33