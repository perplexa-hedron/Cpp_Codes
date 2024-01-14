#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    bool f(int index, int target, vector<int> &a, vector<vector<int>> &dp)
    {
        if (target == 0)
            return true;
        if (index == 0)
            return (a[0] == target);

        if (dp[index][target] != -1)
            return dp[index][target];
        bool not_take = f(index - 1, target, a, dp);
        bool take = false;

        if (target >= a[index])
        {
            take = f(index - 1, target - a[index], a, dp);
        }

        return dp[index][target] = (take | not_take);
    }

    bool tabulation(vector<int> &a, int k)
    {
        int n = a.size();
        vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));
        for (int i = 0; i < n; i++)
            dp[i][0] = true;
        dp[0][a[0]] = true;

        for (int index = 1; index < n; index++)
        {
            for (int target = 1; target <= k; target++)
            {
                bool not_take = dp[index][target];
                bool take = false;

                if (target >= a[index])
                {
                    take = dp[index][target - a[index]];
                }

                dp[index][target] = (take | not_take);
            }
        }
        return dp[n - 1][k];
    }

    bool space_optimized(vector<int> &a, int n, int k)
    {
        vector<bool> prev(k+1,0),curr(k+1,0);
        prev[0]=curr[0]=true;
        prev[a[0]] = true;

        for (int index = 1; index < n; index++)
        {
            for (int target = 1; target <= k; target++)
            {
                bool not_take = prev[target];
                bool take = false;

                if (target >= a[index])
                {
                    take = prev[target - a[index]];
                }

                curr[target] = (take | not_take);
            }
            prev = curr;
        }
        return prev[k];
    }

    bool subsetsum(int n, int k, vector<int> &arr)
    {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    }
};