#include <iostream>
#include <algorithm>
using namespace std;
int change(int *coins, int n, int money)
{
    int ans = 0;
    while (money > 0)
    {
        int idx = upper_bound(coins, coins + n, money) - 1 - coins;
        money = money - coins[idx];
        ans++;
    }
    return ans;
}
int main()
{
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int money;
    cin >> money;
    int n = sizeof(coins) / sizeof(int);
    cout << change(coins, n, money);
    return 0;
}