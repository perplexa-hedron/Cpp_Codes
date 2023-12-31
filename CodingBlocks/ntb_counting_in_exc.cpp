#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;
int main()
{
    int t;
    cin >> t;
    ll primes[] = {2, 3, 5, 7, 11, 13, 17, 19};
    while (t--)
    {
        ll n;
        cin >> n;
        ll subsets = (1 << 8) - 1;
        ll ans = 0;
        for (ll i = 1; i <= subsets; i++)
        {
            ll denom = 1ll;
            ll setbits = __builtin_popcount(i);
            for (ll j = 0; j <= 7; j++)
            {
                if ((i & (1 << j)))
                {
                    denom = denom * primes[j];
                }
            }
            if (setbits & 1)
            {
                ans += n / denom;
            }
            else
            {
                ans -= n / denom;
            }
        }
        cout << ans << endl;
    }
    return 0;
}