#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int f(int i, int j, vector<int> &matrix, vector<vector<int>> &dp)
    {
        if (i == j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int mini = 1e9;
        int steps;
        for (int k = i; k < j - 1; k++)
        {
            steps = matrix[i - 1] * matrix[k] * matrix[j] + f(i, k, matrix, dp) + f(k + 1, j, matrix, dp);
            if (steps < mini)
                mini = steps;
        }
        return dp[i][j] = mini;
    }
    int tabulation(vector<int> &matrix, int n){
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i =1;i<n;i++){
            dp[i][i] =0;
        }
        for(int i =n-1;i>=0;i--){
            for(int j =i+1;j<n;j++){
                int mini = 1e9;
                int steps;
                for (int k = i; k < j - 1; k++)
                {
                    steps = matrix[i - 1] * matrix[k] * matrix[j] + dp[i][k] + dp[k+1][j];
                    if (steps < mini)
                        mini = steps;
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][n-1];
    }

public:
    int minimumsteps(vector<int> &matrix, int n)
    {
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(1, n - 1, matrix, dp);
    }
};