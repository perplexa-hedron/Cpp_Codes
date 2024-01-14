#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    long long f(long long index, long long target, vector<long long> coins, vector<vector<long long>> &dp)
    {
        if (index == 0)
        {
            return (target % coins[0] == 0);
        }
        if (dp[index][target] != -1)
            return dp[index][target];
        long long not_take = f(index - 1, target, coins, dp);
        long long take = 0;
        if (coins[index] <= target)
            take = f(index, target - coins[index], coins, dp);
        return dp[index][target] = not_take + take;
    }

    long long tabular(vector<long long> &coin, long long target, long long n)
    {
        vector<vector<long long>> dp(n, vector<long long>(target + 1, 0));
        for (long long t = 0; t <= target; t++)
        {
            dp[0][t] = (t % coin[0] == 0);
        }
        for (long long ind = 1; ind < n; ind++)
        {
            for (long long tar = 0; tar <= target; tar++)
            {
                long long not_take = 0 + dp[ind - 1][tar];
                long long take = 1e9;
                if (coin[ind] <= tar)
                    take = 1 + dp[ind][tar - coin[ind]];
                dp[ind][tar] = take + not_take;
            }
        }
        return dp[n - 1][target];
    }

    long long space_optimization(vector<long long> &coin, long long target, long long n)
    {
        vector<long long> prev(target + 1, 0), curr(target + 1, 0);
        for (long long t = 0; t <= target; t++)
        {
            prev[t] = (t % coin[0] == 0);
        }
        for (long long ind = 1; ind < n; ind++)
        {
            for (long long tar = 0; tar <= target; tar++)
            {
                long long not_take = 0 + prev[tar];
                long long take = 1e9;
                if (coin[ind] <= tar)
                    take = 1 + curr[tar - coin[ind]];
                curr[tar] = take + not_take;
            }
            prev = curr;
        }
        return prev[target];
    }

    long long one_d_array_space_optimization(vector<long long> &coin, long long target, long long n)
    {
        vector<long long> prev(target + 1, 0);
        for (long long t = 0; t <= target; t++)
        {
            prev[t] = (t % coin[0] == 0);
        }
        for (long long ind = 1; ind < n; ind++)
        {
            for (long long tar = target; tar >= 0; tar--)
            {
                long long not_take = 0 + prev[tar];
                long long take = 1e9;
                if (coin[ind] <= tar)
                    take = 1 + prev[tar - coin[ind]];
                prev[tar] = (take + not_take);
            }
        }
        return prev[target];
    }

public:
    long long number_of_ways(vector<long long> coins, long long target)
    {
        long long n = coins.size();
        vector<vector<long long>> dp(n, vector<long long>(target + 1, -1));
    }
};