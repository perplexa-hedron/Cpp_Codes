#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int x, y;
    cin >> x >> y;
    int max = INT_MIN;
    for (int i = x; i < y; i++)
    {
        for (int j = y; j > x; j--)
        {
            int a = (i ^ j);
            if (a > max)
            {
                max = a;
            }
        }
    }
    cout << max;
    return 0;
}