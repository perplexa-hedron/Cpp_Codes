#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, k = 0;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << "  ";
        }
        for (int j = 1; j <= i; j++)
        {
            ++k;
            cout << k << " ";
        }
        for (int j = 2; j <= i; j++)
        {
            --k;
            cout << k << " ";
        }
        cout << "\n";
    }
    k--;
    n--;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "  ";
        }
        for (int j = i; j < n; j++)
        {
            cout << k << " ";
            k++;
        }
        for (int j = i; j <= n; j++)
        {
            cout << k << " ";
            k--;
        }
        cout << "\n";
    }

    return 0;
}