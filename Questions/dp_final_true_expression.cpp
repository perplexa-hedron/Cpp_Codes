#include <bits/stdc++.h>
using namespace std;
using ll = long long;
class Solution
{
private:
    int mod = 1000000007;
    long long f(int i, int j, int istrue, string &exp, vector<vector<vector<ll>>> &dp)
    {
        if (i > j)
            return 0;
        if (i == j)
        {
            if (istrue)
                return exp[i] == 'T';
            else
                return exp[i] == 'F';
        }
        if(dp[i][j][istrue] != -1) return dp[i][j][istrue];
        ll ways = 0;
        for (int ind = i + 1; ind <= j - 1; ind + 2)
        {
            ll lT = f(i, ind - 1, 1, exp, dp);
            ll lF = f(i, ind - 1, 0, exp, dp);
            ll rT = f(ind + 1, j, 1, exp, dp);
            ll rF = f(ind + 1, j, 0, exp, dp);

            if (exp[ind] == '&')
            {
                if (istrue)
                    ways = (ways + (rT * lT) % mod) % mod;
                else
                    ways = (ways + (rT * lF) % mod + (rF * lT) % mod + (rF * lF) % mod) % mod;
            }
            else if (exp[ind] == '|')
            {
                if (istrue)
                    ways = (ways + (rT * lT) % mod + (rT * lF) % mod + (rF * lT) % mod) % mod;
                else
                    ways = (ways + (rF * lF) % mod) % mod;
            }
            else
            {
                if (istrue)
                    ways = (ways + (rT * lF) % mod + (rF * lT) % mod) % mod;
                else
                    ways = (ways + (rT * lT) % mod + (rF * lF) % mod);
            }
        }
        return dp[i][j][istrue] = ways;
    }

public:
    int evaluateExp(string &exp)
    {
        int n = exp.size();
        vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, -1)));
        return f(0,n-1,1,exp,dp);
    }
};