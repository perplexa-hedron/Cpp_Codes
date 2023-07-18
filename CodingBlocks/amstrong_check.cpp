#include <iostream>
#include <math.h>
using namespace std;
int order(int n)
{
    int i = 0;
    while (n != 0)
    {
        i++;
        n /= 10;
    }
    return i;
}
bool armstrong(int n)
{
    int sum = 0, n1 = n;
    int o = order(n);
    while (n1 != 0)
    {
        int num = n1 % 10;
        sum += pow(num, o);
        n1 /= 10;
    }
    if (sum == n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int n;
    cin >> n;
    if (armstrong(n))
    {
        cout << "true"
             << "\n";
    }
    else
    {
        cout << "false"
             << "\n";
    }
    return 0;
}