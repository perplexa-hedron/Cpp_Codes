#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    bool f(int i, int j, string &s1, string &s2, vector<vector<int>> dp)
    {
        if (i == 0 && j == 0)
            return true;

        if (i == 0 && j > 0)
            return false;

        if (j == 0 && i > 0)
        {
            for (int ii = 1; ii <= i; ii++)
            {
                if (s1[ii - 1] != '*')
                    return false;
            }
            return true;
        }
        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i - 1] == s2[j - 1] || s1[i - 1] == '?')
            return dp[i][j] = f(i - 1, j - 1, s1, s2, dp);

        if (s1[i - 1] == '*')
        {
            return dp[i][j] = f(i - 1, j, s1, s2, dp) || f(i, j - 1, s1, s2, dp);
        }

        return dp[i][j] = false;
    }

    bool tabulation(string s1, string s2)
    {
        int n = s1.size();
        int m = s2.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, 0));

        dp[0][0] = true;
        for (int j = 1; j <= m; j++)
        {
            dp[0][j] = false;
        }

        for (int i = 1; i <= n; i++)
        {
            bool flag = true;
            for (int ii = 1; ii <= i; ii++)
            {
                if (s1[ii - 1] != '*')
                {
                    flag = false;
                    break;
                }
            }
            dp[i][0] = flag;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j - 1] || s1[i - 1] == '?')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }

                else if (s1[i - 1] == '*')
                {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }

                else
                {
                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m];
    }

    bool space_optimization(string s1, string s2)
    {
        int n = s1.size();
        int m = s2.size();
        vector<bool> prev(m + 1, false), curr(m + 1, false);

        prev[0] = true;
        
        for (int i = 1; i <= n; i++)
        {
            bool flag = true;
            for (int ii = 1; ii <= i; ii++)
            {
                if (s1[ii - 1] != '*')
                {
                    flag = false;
                    break;
                }
            }
            curr[0] = flag;
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j - 1] || s1[i - 1] == '?')
                {
                    curr[j] = prev[j - 1];
                }

                else if (s1[i - 1] == '*')
                {
                    curr[j] = prev[j] || curr[j - 1];
                }

                else
                {
                    curr[j] = false;
                }
            }
            prev = curr;
        }

        return prev[m];
    }

public:
    bool match(string s1, string s2)
    {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return f(n, m, s1, s2, dp);
    }
};