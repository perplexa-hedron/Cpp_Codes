#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    long long f(int ind, int buy, vector<int> &prices, int n, vector<vector<vector<int>>> &dp, int cap)
    {
        if (cap == 0)
            return 0;
        if (ind == 0)
            return 0;
        long long profit = 0;
        if (dp[ind][buy][cap] != -1)
            return dp[ind][buy][cap];

        if (buy)
        {
           return dp[ind][buy][cap] = max(-prices[ind] + f(ind + 1, 0, prices, n, dp, cap), f(ind + 1, 1, prices, n, dp, cap));
        }
        else
        {
            return dp[ind][buy][cap] = max(prices[ind] + f(ind + 1, 1, prices, n, dp, cap - 1), f(ind + 1, 0, prices, n, dp, cap));
        }
    }

    long long tabulation(vector<int> &prices, int n)
    {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, 0)));

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int cap = 1; cap <= 2; cap++)
                {
                    if (buy)
                    {
                        dp[ind][buy][cap] = max(-prices[ind] +dp[ind+1][0][cap], dp[ind+1][1][cap]);
                    }
                    else
                    {
                        dp[ind][buy][cap] = max(prices[ind] + dp[ind+1][1][cap-1],dp[ind+1][0][cap]);
                    }
                }
            }
        }
        return dp[0][1][2];
    }

    long long space_optimization(vector<int> &prices, int n)
    {
        vector<vector<int>> after(2,vector<int>(3, 0));
        vector<vector<int>> curr(2,vector<int>(3, 0));

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int cap = 1; cap <= 2; cap++)
                {
                    if (buy)
                    {
                        curr[buy][cap] = max(-prices[ind] +after[0][cap], after[1][cap]);
                    }
                    else
                    {
                        curr[buy][cap] = max(prices[ind] + after[1][cap-1],after[0][cap]);
                    }
                }
            }
            after = curr;
        }
        return after[1][2];
    }

public:
    long long getmaximumprofit(vector<int> &prices, int n)
    {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0, 1, prices, n, dp, 2);
    }
};