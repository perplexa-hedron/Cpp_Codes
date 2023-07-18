#include <iostream>
#include <vector>
using namespace std;
int ways(int n, int ld)
{
    if (n <= 0)
    {
        return 0;
    }
    if (n == 1)
    {
        if (ld == 0)
        {
            return 2;
        }
        else
        {
            return 1;
        }
    }
    int sum = 0;
    if (ld == 0)
    {
        return (ways(n - 1, 0) + ways(n - 1, 1));
    }
    if (ld == 1)
    {
        return ways(n - 1, 0);
    }
}
int main()
{
    int n, ld;
    cin >> n >> ld;
    cout << ways(n, ld);
    return 0;
}