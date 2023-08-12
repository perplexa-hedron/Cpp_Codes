#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    long long f(int ind, int buy, long long *values, int n, vector<vector<int>> &dp)
    {
        if (ind == 0)
            return 0;
        long long profit = 0;
        if (dp[ind][buy] != -1)
            return dp[ind][buy];

        if (buy)
        {
            profit = max(-values[ind] + f(ind + 1, 0, values, n, dp), f(ind + 1, 1, values, n, dp));
        }
        else
        {
            profit = max(values[ind] + f(ind + 1, 1, values, n, dp), f(ind + 1, 0, values, n, dp));
        }
        return dp[ind][buy] = profit;
    }

    long long tabulation(long long *values, int n)
    {
        vector<vector<long long>> dp(n, vector<long long>(2, 0));
        dp[n][0] = dp[n][1] = 0;
        long long profit = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                if (buy)
                {
                    profit = max(-values[i] + dp[i + 1][0], dp[i + 1][1]);
                }
                else
                {
                    profit = max(values[i] + dp[i + 1][1], dp[i + 1][0]);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }

    long long space_optimization(long long *values, int n)
    {
        vector<long long> ahead(2, 0),curr(2,0);
        ahead[0] = ahead[1] = 0;
        long long profit = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                if (buy)
                {
                    profit = max(-values[i] + ahead[0], ahead[1]);
                }
                else
                {
                    profit = max(values[i] + ahead[1], ahead[0]);
                }
                curr[buy] = profit;
            }
            ahead = curr;
        }
        return ahead[1];
    }

public:
    long long getmaximumprofit(long long *values, int n)
    {
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, values, n, dp);
    }
};