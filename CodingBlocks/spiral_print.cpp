#include <iostream>
// #include <vector>
using namespace std;
void anticlockwise(int arr[10][10], int n, int m)
{
    // sc sr->er
    // er sc->ec
    // ec er->sr
    // sr ec->sc
    int sr = 0, er = n - 1, sc = 0, ec = m - 1;
    while (sr <= er && sc <= ec)
    {
        for (int i = sr; i <= er; i++)
        {
            cout << arr[i][sc] << ", ";
        }
        sc++;
        for (int i = sc; i <= ec; i++)
        {
            cout << arr[er][i] << ", ";
        }
        er--;
        if (sc <ec)
        {
            for (int i = er; i <= sr; i--)
            {
                cout << arr[i][ec] << ", ";
            }
            ec--;
        }
        if (sr <er)
        {
            for (int i = ec; i <= sc; i--)
            {
                cout << arr[sr][i] << ", ";
            }
            sr++;
        }
    }
    cout << "END";
}
void clockwise(int arr[10][10], int n, int m)
{
    int sr = 0, er = n - 1, sc = 0, ec = m - 1;
    while (sr <= er && sc <= ec)
    {
        for (int i = sc; i <= ec; i++)
        {
            cout << arr[sr][i] << ", ";
        }
        sr++;
        for (int i = sr; i <= er; i++)
        {
            cout << arr[i][ec] << ", ";
        }
        ec--;
        if (sr < er)
        {
            for (int i = ec; i >= sc; i--)
            {
                cout << arr[er][i] << ", ";
            }
            er--;
        }
        if (sc < ec)
        {
            for (int i = er; i >= sr; i--)
            {
                cout << arr[i][sc] << ", ";
            }
            sc++;
        }
    }
    cout << "END";
}
int main()
{
    int n, m;
    cin >> n >> m;
    int arr[10][10];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    // clockwise(arr, n, m);
    anticlockwise(arr, n, m);
    return 0;
}