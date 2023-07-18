#include <iostream>
#include <vector>
using namespace std;
long long int ways(int n, int k)
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }
    long long int sum = 0;
    for (int i = 1; i <= k; i++)
    {
        sum += ways(n - i, k);
    }
    return sum;
}
int main()
{
    int n, k;
    cin >> n >> k;
    cout << ways(n, k);
    return 0;
}