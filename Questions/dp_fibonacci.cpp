#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    int memoization_fibonacci(int n, vector<int> &dp)
    {
        if (n <= 1)
        {
            return dp[n] = n;
        }

        return dp[n] = memoization_fibonacci(n - 1, dp) + memoization_fibonacci(n - 2, dp);
    }
    int tabulation(int n){
        int prev2 = 0;
        int prev = 1;
        for(int i =2;i<=n;i++){
            int curi = prev+prev2;
            prev2 = prev;
            prev = curi;
        }
        return prev; 
    }
};