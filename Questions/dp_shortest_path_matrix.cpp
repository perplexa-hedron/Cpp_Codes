#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int f(int i, int j, vector<vector<int>> &dp)
    {
        if (i == 0 && j == 0)
            return dp[i][j] = 1;
        if (i < 0 || j < 0)
            return dp[i][j] = 0;

        if (dp[i][j] != -1)
            return dp[i][j];
        int left = f(i, j - 1, dp);
        int up = f(i - 1, j, dp);

        return dp[i][j] = left + up;
    }

    int tabulation(int n,int m){
        vector<vector<int>> dp(n,vector<int>(m,-1));

        for(int i =0;i<n;i++){
            for(int j =0 ; j<m;j++){
                int left=0, up=0;
                if(i==0 && j ==0) dp[i][j]=1;
                else{
                    if(i>0) left = dp[i][j-1];
                    if(j>0) up = dp[i-1][j];
                    dp[i][j] = up + left ;
                }
            }
        }

        return dp[n-1][m-1];
    }

    int spaceOptimized(int n,int m){
        vector<int> prev(m,0);
        for(int i =0;i<n;i++){
            vector<int> curr(m,0);
            for(int j =0;j<m;j++){
                if(i == 0 && j ==0)curr[j] = 1;
                else{
                    int up = 0,left =0;
                    if(i>0) up = prev[j];
                    if(j>0) left = curr[j-1];    
                    curr[j] = up+left; 
                } 
            }
            prev = curr;
        }
        return prev[n-1];
    }

public:
    int minimumPathSum(int n, int m)
    {
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, dp);
    }
};