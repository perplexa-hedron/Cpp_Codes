#include <bits/stdc++.h>
#include <climits>
using namespace std;
int last_digit(int n)
{
    if (n <= 1)
    {
        return n;
    }
    long long fibo[n];
    fibo[0] = 0;
    fibo[1] = 1;
    int i = 2;
    while (i < n)
    {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
        ++i;
    }
    //cout << fibo[n] << endl;
    return fibo[n] % 10;
}
int main()
{
    int n;
    cin >> n;
    cout << last_digit(n);
    return 0;
}