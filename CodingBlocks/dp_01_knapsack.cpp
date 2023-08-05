#include <bits/stdc++.h>
using namespace std;
class solution
{
private:
    int f(int index, int wt, vector<int> val, vector<int> w, vector<vector<int>> &dp)
    {
        if (index == 0)
        {
            if (w[0] <= wt)
            {
                return dp[index][wt] = val[0];
            }
            else
            {
                return 0;
            }
        }
        if (dp[index][wt] != -1)
            return dp[index][wt];
        int not_take = 0 + f(index-1,wt,val,w,dp);
        int take = INT_MIN;
        if (w[index] <= wt)
        {
            take = val[index] + f(index-1,wt-w[index],val,w,dp);
        }
        return dp[index][wt] = max(not_take, take);
    }

    int tabulation(vector<int> &value, vector<int> &weight, int wt)
    {
        int n = value.size();
        vector<vector<int>> dp(n, vector<int>(wt + 1, 0));
        for (int i = 0; i < wt; i++)
        {
            dp[0][i] = value[0];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= wt; j++)
            {
                int not_take = 0 + dp[i - 1][j];
                int take = INT_MIN;
                if (weight[i] <= j)
                {
                    take = value[i] + dp[i - 1][j - weight[i]];
                }
                dp[i][j] = max(not_take, take);
            }
        }
        return dp[n - 1][wt];
    }

    int space_optimization(vector<int> &value, vector<int> &weight, int wt, int n)
    {
        vector<int> prev(wt + 1, 0), curr(wt + 1, 0);
        for (int i = 0; i < wt; i++)
        {
            prev[i] = value[0];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= wt; j++)
            {
                int not_take = 0 + prev[j];
                int take = INT_MIN;
                if (weight[i] <= j)
                {
                    take = value[i] + prev[j - weight[i]];
                }
                curr[j] = max(not_take, take);
            }
            prev = curr;
        }
        return prev[wt];
    }

    int one_row_space_optimization(vector<int> &value, vector<int> &weight, int wt, int n)
    {
        vector<int> prev(wt + 1, 0);
        for (int i = 0; i < wt; i++)
        {
            prev[i] = value[0];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = wt; j >=0; j--)
            {
                int not_take = 0 + prev[j];
                int take = INT_MIN;
                if (weight[i] <= j)
                {
                    take = value[i] + prev[j - weight[i]];
                }
                prev[j] = max(not_take, take);
            }
        }
        return prev[wt];
    }

public:
    int knapsack(vector<int> &value, vector<int> &weight, int wt)
    {
        int n = value.size();
        int w = weight.size();
        vector<vector<int>> dp(n, vector<int>(w + 1, -1));
        return f(n - 1, wt, value, weight, dp);
    }
};