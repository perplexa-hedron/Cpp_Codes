#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int f(int i, int j, vector<vector<int>> path, vector<vector<int>> &dp, int n, int m)
    {
        if (j < 0 || j >= m)
            return dp[i][j] = -1e8;
        if (i == 0)
            return dp[i][j] = path[i][j];
        if (dp[i][j] != -1)
            return dp[i][j];
        int straight_up = path[i][j] + dp[i - 1][j];
        int left_diagonal = path[i][j] + dp[i - 1][j - 1];
        int right_diagonal = path[i][j] + dp[i - 1][j + 1];

        return dp[i][j] = max(straight_up, max(left_diagonal, right_diagonal));
    }

    int tabular(vector<vector<int>> &path, int n, int m)
    {
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int j = 0; j < m; j++)
        {
            dp[0][j] = path[0][j];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int straight_up = path[i][j] + dp[i - 1][j];
                int left_diagonal = path[i][j];
                if (j > 0)
                    left_diagonal += dp[i - 1][j - 1];
                else
                    left_diagonal += -1e8;
                int right_diagonal = path[i][j];
                if (j < m - 1)
                    right_diagonal += dp[i - 1][j + 1];
                else
                    right_diagonal += -1e8;
                dp[i][j] = max(straight_up, max(left_diagonal, right_diagonal));
            }
        }
        int maxi = dp[n - 1][0];
        for (int j = 0; j < m; j++)
        {
            maxi = max(maxi, dp[n - 1][j]);
        }
        return maxi;
    }

    int space_optimized(vector<vector<int>> &path, int n, int m)
    {
        vector<int> prev(m, 0);
        for (int j = 0; j < m; j++)
        {
            prev[j] = path[0][j];
        }
        for (int i = 1; i < n; i++)
        {
            vector<int> curr(m, 0);
            int straight_up = INT_MIN, left_diagonal = INT_MIN, right_diagonal = INT_MIN;
            for (int j = 0; j < m; j++)
            {
                straight_up = path[i][j] + prev[j];
                if (j > 0)
                    left_diagonal = path[i][j] + prev[j - 1];
                if (j < m - 1)
                    right_diagonal = path[i][j] + prev[j + 1];

                curr[j] = max(straight_up, max(left_diagonal, right_diagonal));
            }
            prev = curr;
        }
        int maxi = prev[0];
        for (int j = 0; j < m; j++)
        {
            maxi = max(maxi, prev[j]);
        }
        return maxi;
    }

public:
    int maxpathsum(vector<vector<int>> &path)
    {
        int n = path.size();
        int m = path[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, path, dp, n, m);
    }
};