#include <iostream>
using namespace std;
#define ll long long
bool isprime(int n)
{
    if (n == 1)
    {
        return false;
    }
    if (n == 2)
    {
        return true;
    }
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
        return true;
    }
    return false;
}
void prime_sieve(int *p)
{
    // first mark all odd number's prime
    for (ll i = 3; i <= 1000000; i += 2)
    {
        p[i] = 1;
    }
    // sieve
    for (ll i = 3; i <= 1000000; i += 2)
    {
        if (p[i] == 1)
        {
            for (ll j = (i * i); j <= 1000000; j = j + i)
            {
                p[j] = 0;
            }
        }
    }
    p[2] = 1;
    p[1] = p[0] = 0;
    return;
}

int main()
{
    int p[1000005] ={0};
    prime_sieve(p);
    int csum[1000005] = {0};
    for(int i =1;i<=1000000;i++){
        csum[i] = csum[i-1] + p[i];
    }
    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<csum[b] - csum[a-1] <<endl;
    }

    //computing prime upto n
    // int n;
    // cin >> n;
    // int p[1000005] = {0};
    // prime_sieve(p);
    // for (int i = 0; i <= n; i++)
    // {
    //     if (p[i] == 1)
    //     {
    //         cout << i << " ";
    //     }
    // }
    return 0;
}