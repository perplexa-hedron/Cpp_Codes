#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
ll aModM(string s, ll mod)
{
    ll number = 0;
    for (ll i = 0; i < s.length(); i++) {
        number = (number * 10 + (s[i] - '0'));
        number %= mod;
    }
    return number;
}

ll ApowBmodM(string& a, string& b, ll m)
{
    ll res = 1;
 
    // Find a%m
    ll x = aModM(a, m);
 
    // Find b%m
    ll y = aModM(b, m);
 
    while (y) {
        if (y & 1)
            res = (res * x) % m;
        y = y >> 1;
        x = ((x % m) * (x % m)) % m;
    }
    return (res % m + m) % m;
}

int main()
{
    string a,b;
    ll m;
    cin>>a>>b>>m;
    cout << ApowBmodM(a, b, m);
    return 0;
}