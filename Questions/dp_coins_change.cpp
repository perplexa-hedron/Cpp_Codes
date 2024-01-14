#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int f(vector<int> coin, int T, vector<vector<int>> &dp, int index)
    {
        if (index == 0)
        {
            if (T % coin[index] == 0)
                return dp[index][T] = T / coin[index];
            return 1e9;
        }
        if (dp[index][T] != -1)
            return dp[index][T];
        int not_take = 0 + f(coin, T, dp, index - 1);
        int take = 1e9;
        if (coin[index] <= T)
            take = 1 + f(coin, T - coin[index], dp, index);
        return dp[index][T] = min(take, not_take);
    }

    int tabular(vector<int> &coin, int target, int n)
    {
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        for (int t = 0; t <= target; t++)
        {
            if (t % coin[0] == 0)
                dp[0][t] = t / coin[0];
            else
                dp[0][t] = 1e9;
        }
        for (int ind = 1; ind < n; ind++)
        {
            for (int tar = 0; tar <= target; tar++)
            {
                int not_take = 0 + dp[ind - 1][tar];
                int take = 1e9;
                if (coin[ind] <= tar)
                    take = 1 + dp[ind][tar - coin[ind]];
                dp[ind][tar] = min(take, not_take);
            }
        }
        return dp[n - 1][target];
    }

    int space_optimization(vector<int> &coin, int target, int n)
    {
        vector<int> prev(target + 1, 0), curr(target + 1, 0);
        for (int t = 0; t <= target; t++)
        {
            if (t % coin[0] == 0)
                prev[t] = t / coin[0];
            else
                prev[t] = 1e9;
        }
        for (int ind = 1; ind < n; ind++)
        {
            for (int tar = 0; tar <= target; tar++)
            {
                int not_take = 0 + prev[tar];
                int take = 1e9;
                if (coin[ind] <= tar)
                    take = 1 + curr[tar - coin[ind]];
                curr[tar] = min(take, not_take);
            }
            prev = curr;
        }
        return prev[target];
    }

    int one_d_array_space_optimization(vector<int> &coin, int target, int n)
    {
        vector<int> prev(target + 1, 0);
        for (int t = 0; t <= target; t++)
        {
            if (t % coin[0] == 0)
                prev[t] = t / coin[0];
            else
                prev[t] = 1e9;
        }
        for (int ind = 1; ind < n; ind++)
        {
            for (int tar = target; tar >= 0; tar--)
            {
                int not_take = 0 + prev[tar];
                int take = 1e9;
                if (coin[ind] <= tar)
                    take = 1 + prev[tar - coin[ind]];
                prev[tar] = min(take, not_take);
            }
        }
        return prev[target];
    }

public:
    int minimumcoincount(vector<int> &coin, int target, int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
    }
};