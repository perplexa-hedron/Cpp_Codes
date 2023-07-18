#include <iostream>
using namespace std;
long long int replace(long long int n)
{
    long long int sum = 0, i = 1;
    while (n != 0)
    {
        long long int num = n % 10;
        if (num == 0)
        {
            num = 5;
        }
        sum += num * i;
        i *= 10;
        n /= 10;
    }
    return sum;
}
int main()
{
    long long int n;
    cin >> n;
    cout << replace(n);
    return 0;
}