#include <bits/stdc++.h>
using namespace std;
class Solution
{
    private:
    int f(int i, int j, string s1, string s2, vector<vector<int>> &dp)
    {
        if (i == 0 || j == 0)
        {
            return 0;
        }

        if (dp[i][j] != -1)
            return dp[i][j];
        if (s1[i - 1] == s2[j - 1])
        {
            return dp[i][j] = 1 + f(i - 1, j - 1, s1, s2, dp);
        }

        return dp[i][j] = max(f(i - 1, j, s2, s2, dp), f(i, j - 1, s1, s2, dp));
    }

    int tabulation(string s1, string s2)
    {
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 0;
        }
        for (int j = 0; j <= m; j++)
        {
            dp[0][j] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];

                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }

    string printing_lcs(string s1, string s2)
    {
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 0;
        }
        for (int j = 0; j <= m; j++)
        {
            dp[0][j] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];

                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        int len = dp[n][m];
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            ans += "#";
        }

        int index = len - 1;
        int i = n, j = m;
        while (i > 0 && j > 0)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                ans[index] = s1[i - 1];
                index--;
                i--, j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }

        return ans;
    }

    int space_optimized(string s1, string s2)
    {
        int n = s1.length();
        int m = s2.length();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            prev[0] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                    curr[j] = 1 + prev[j - 1];

                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }
        return prev[m];
    }
    public:
    int longestcommonsubstring(string s1, string s2)
    {
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return f(n, m, s1, s2, dp);
    }
};