#include <iostream>
#include <math.h>
using namespace std;
long long int num_inverse(long long int n)
{
    long long int sum = 0, i = 1;
    while (n != 0)
    {
        long long int num = n % 10;
        if (n > 10)
        {
            if (num >= 5 && num <= 9)
            {
                num = 9 - num;
            }
            sum = sum + num * i;
            n = n / 10;
            i *= 10;
        }
        else
        {
            if (num >= 5 && num < 9)
            {
                num = 9 - num;
            }
            sum = sum + num * i;
            n = n / 10;
            i *= 10;
        }
    }
    return sum;
}
int main()
{
    long long int n;
    cin >> n;
    cout << num_inverse(n);
    return 0;
}