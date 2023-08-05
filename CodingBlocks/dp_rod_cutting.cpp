#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    long long f(int index, int len, vector<int> price, vector<vector<int>> &dp)
    {
        if (index == 0)
        {
            return len * price[0];
        }
        if (dp[index][len] != -1)
            return dp[index][len];
        int not_take = f(index - 1, len, price, dp);
        int take = INT_MIN;
        int rod_len = index + 1;
        if (rod_len <= len)
            take = price[index] + f(index, len - rod_len, price, dp);
        return dp[index][len] = max(take, not_take);
    }

    long long tabulation(vector<int> &price, int length)
    {
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(length + 1, 0));

        for (int len = 0; len <= length; len++)
        {
            dp[0][len] = len * price[0];
        }

        for (int index = 1; index < n; index++)
        {
            for (int len = 0; len <= length; len++)
            {
                int not_take = dp[index - 1][len];
                int take = INT_MIN;
                int rod_len = index + 1;
                if (rod_len <= len)
                    take = price[index] + dp[index][len - rod_len];
                dp[index][len] = max(take, not_take);
            }
        }
        return dp[n - 1][length];
    }

    long long space_optimization(vector<int> &price, int length)
    {
        vector<int> prev(length + 1, 0), curr(length + 1, 0);

        for (int len = 0; len <= length; len++)
        {
            prev[len] = len * price[0];
        }

        for (int index = 1; index < length; index++)
        {
            for (int len = 0; len <= length; len++)
            {
                int not_take = prev[len];
                int take = INT_MIN;
                int rod_len = index + 1;
                if (rod_len <= len)
                    take = price[index] + curr[len - rod_len];
                curr[len] = max(take, not_take);
            }
            prev = curr;
        }
        return prev[length];
    }
    long long one_d_space_optimization(vector<int> &price, int length)
    {
        vector<int> prev(length + 1, 0);

        for (int len = 0; len <= length; len++)
        {
            prev[len] = len * price[0];
        }

        for (int index = 1; index < length; index++)
        {
            for (int len = 0; len <= length; len++)
            {
                int not_take = prev[len];
                int take = INT_MIN;
                int rod_len = index + 1;
                if (rod_len <= len)
                    take = price[index] + prev[len - rod_len];
                prev[len] = max(take, not_take);
            }
        }
        return prev[length];
    }

public:
    long long maximumprice(vector<int> &price, int length)
    {
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(length + 1, -1));
        return f(n - 1, length, price, dp);
    }
};