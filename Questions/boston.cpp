#include <iostream>
#include <math.h>
using namespace std;
int sum_prime(int n)
{
    int sum = 0;
    while (n % 2 == 0)
    {
        sum += 2;
        n /= 2;
    }
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        while (n % i == 0)
        {
            sum += i;
            n /= i;
        }
    }
    if (n > 2)
    {
        sum += n;
    }
    return sum;
}
int sum(int n)
{
    int sum = 0;
    while (n != 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int main()
{
    int n;
    cin >> n;
    if (sum(n) == sum_prime(n))
    {
        cout << 1 << "\n";
    }
    else
    {
        cout << 0 << "\n";
    }
    return 0;
}