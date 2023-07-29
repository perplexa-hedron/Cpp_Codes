#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int f(int i, int j, vector<vector<int>> path, vector<vector<int>> &dp)
    {
        if (i == 0 && j == 0)
            return dp[i][j] = path[0][0];
        if (i < 0 || j < 0)
            return INT_MAX;
        if (dp[i][j] != -1)
            return dp[i][j];
        int up = path[i][j] + dp[i - 1][j];
        int left = path[i][j] + dp[i][j - 1];

        return dp[i][j] = min(up, left);
    }

    int tabulation(vector<vector<int>> &path, int n, int m)
    {
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 && j == 0)
                    return dp[i][j] = path[i][j];
                else
                {
                    int up = path[i][j], left = path[i][j];
                    if (i > 0)
                        up += dp[i - 1][j];
                    else
                        up += INT_MAX;
                    if (j > 0)
                        left += dp[i][j - 1];
                    else
                        left += INT_MAX;

                    dp[i][j] = min(up, left);
                }
            }
            return dp[n - 1][m - 1];
        }
    }

    int spaceoptimized(vector<vector<int>> &path, int n, int m)
    {
        vector<int> prev(m,0);
        for (int i = 0; i < n; i++)
        {
            vector<int> curr(m,0);
            for (int j = 0; j < m; j++)
            {
                if (i == 0 && j == 0)
                    return curr[j] = path[i][j];
                else
                {
                    int up = path[i][j], left = path[i][j];
                    if (i > 0)
                        up += prev[j];
                    else
                        up += INT_MAX;
                    if (j > 0)
                        left += curr[j - 1];
                    else
                        left += INT_MAX;

                    curr[j] = min(up, left);
                }
            }
            prev = curr;
        }
        return prev[m - 1];
    }

public:
    int minimumpathsum(vector<vector<int>> &path, int n, int m)
    {
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, path, dp);
    }
};