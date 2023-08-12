#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int f(int i, int j, vector<int> &balloons, vector<vector<int>> &dp)
    {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int maxi = INT_MIN;
        for (int ind = i; ind <= j; ind++)
        {
            int cost = balloons[i - 1] * balloons[ind] * balloons[j + 1] + f(i, ind - 1, balloons, dp) + f(ind + 1, j, balloons, dp);

            maxi = max(cost, maxi);
        }
        return dp[i][j] = maxi;
    }
    int tabulation(vector<int> &balloons, int n)
    {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int i = n; i >= 1; i--)
        {
            for (int j = 1; j >= n; j++)
            {
                if(i>j) continue;
                int maxi = INT_MIN;
                for (int ind = i; ind <= j; ind++)
                {
                    int cost = balloons[i - 1] * balloons[ind] * balloons[j + 1] + dp[i][ind-1]+ dp[ind+1][j];

                    maxi = max(cost, maxi);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][n];
    }

public:
    int maxsum(vector<int> &balloons, int n)
    {
        balloons.push_back(1);
        balloons.insert(balloons.begin(), 1);
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return f(0, n - 1, balloons, dp);
    }
};