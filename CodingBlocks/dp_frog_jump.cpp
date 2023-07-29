#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int minjump(int index, vector<int> &dp, vector<int> steps)
    {
        if (index == 0)
            return dp[index] = 0;
        if (dp[index] != -1)
            return dp[index];
        int left = minjump(index - 1, dp, steps) + abs(steps[index] - steps[index - 1]);
        int right = INT_MAX;
        if (index > 1)
        {
            right = minjump(index - 2, dp, steps) + abs(steps[index] - steps[index - 2]);
        }

        return dp[index] = min(left, right);
    }
    int minjumptabular(int n, vector<int> steps)
    {
        int prev = 0, prev2 = 0;
        for (int i = 1; i < n; i++)
        {
            int fs = prev + abs(steps[i] - steps[i - 1]);
            int ss = INT_MAX;
            if (i > 1)
            {
                ss = prev2 + abs(steps[i] - steps[i - 2]);
            }

            int curri = min(fs, ss);
            prev2 = prev;
            prev = curri;
        }

        return prev;
    }

public:
    int frog_jump(vector<int> steps, int n)
    {
        vector<int> dp(n + 1, -1);
        // return minjump(n - 1, dp, steps);


        // return minjumptabular(n, steps);
    }
};