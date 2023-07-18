#include <bits/stdc++.h>
#include <climits>
using namespace std;
long long gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        int a1 = a % b;
        return gcd(b, a1);
    }
}
int main()
{
    long long a, b;
    cin >> a >> b;
    long long hcf = gcd(a, b);
    long long lcm = (long long)(a * b/ hcf);
    cout << lcm;
}