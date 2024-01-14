#include <bits/stdc++.h>
#include <climits>
using namespace std;
const int n = 1000000;
bitset<1000005> b;
vector<int> primes;
vector<int> primesieve(int *p, int n)
{
    p[0] = p[1] = 0;
    p[2] = 1;
    for (int i = 3; i <= n; i += 2)
    {
        p[i] = 1;
    }
    for (int i = 3; i <= n; i += 2)
    {
        if (p[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                p[j] = 0;
            }
        }
    }
    primes.push_back(2);
    for (int i = 3; i <= n; i += 2)
    {
        if (p[i] == 1)
        {
            primes.push_back(i);
        }
    }
    return primes;
}
vector<int> factorize(int no, vector<int> &primes)
{
    vector<int> factors;
    factors.clear();
    int i = 0;
    int p = primes[0];
    while (p * p <= no)
    {
        if (no % p == 0)
        {
            factors.push_back(p);
            while (no % p == 0)
            {
                no = no / p;
            }
        }
        i++;
        p = primes[i];
    }
    if (no != 1)
    {
        factors.push_back(no);
    }
    return factors;
}/*
int divisors(int no, vector<int> &primes)
{
    int i = 0;
    int p = primes[0];
    int ans = 1;
    while (p * p <= no)
    {
        if (no % p == 0)
        {
            int cnt = 0;
            while (no % p == 0)
            {
                cnt++;
                no = no / p;
            }
            ans = ans * (cnt + 1);
        }
        i++;
        p = primes[i];
    }
    if (no != 1)
    {
        ans = ans * 2;
    }
    return ans;
}
*/
bool isprime(long long no)
{
    if (no <= n)
    {
        return b[no] == 1?true:false;
    }
    for(long long i =0;primes[i] *(long long)primes[i]<=no ;i++){
        if(no%primes[i] == 0){
            return false;
        }
    }
    return true;
}
int main()
{
    int N = 1000000;
    int p[N] = {0};
    vector<int> primes = primesieve(p, 100);
    // int t;
    // cin >> t;
    // while (t--)
    // {
        int no;
        cin >> no;
        if(isprime(no)){
            cout<<"It is what it is";
        }
        else{
            cout<<"It is not what is should be";
        }
        // vector<int> factors = factorize(no, primes);
        // cout << divisors(no, primes) << endl;
        // for (auto f : factors)
        // {
        //     cout << f << " ";
        // }
        // cout << endl;
    // }
    return 0;
}