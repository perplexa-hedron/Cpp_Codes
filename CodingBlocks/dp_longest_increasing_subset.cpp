#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int f(int ind, int pind, int n, int arr[], vector<vector<int>> &dp)
    {
        if (ind == n)
            return 0;

        if (dp[ind][pind + 1] != -1)
            return dp[ind][pind + 1];
        int len = f(ind + 1, pind, n, arr, dp);
        if (pind == -1 || arr[ind] > arr[pind])
        {
            len = max(len, 1 + f(ind + 1, ind, n, arr, dp));
        }
        return dp[ind][pind + 1] = len;
    }

    int tabulation(int arr[], int n)
    {
        vector<int> next(n + 1, 0), curr(n + 1, 0);
        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int pind = ind - 1; pind >= -1; pind--)
            {
                int len = next[pind + 1];
                if (pind == -1 || arr[ind] > arr[pind + 1])
                {
                    len = max(len, 1 + next[pind + 1]);
                }
                curr[pind + 1] = len;
            }
            next = curr;
        }
        return next[0];
    }

    int space_optimized(int arr[], int n)
    {
        vector<int> dp(n, 1);
        int maxi = 1;
        for (int i = 0; i < n; i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                if (arr[prev] < arr[i])
                {
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }
            }
            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }

    int space_optimized_hash(int arr[], int n)
    {
        vector<int> dp(n, 1), hash(n);
        int maxi = 1;
        int lastindex = 0;
        for (int i = 0; i < n; i++)
        {
            hash[i] = i;
            for (int prev = 0; prev < i; prev++)
            {
                if (arr[prev] < arr[i] && dp[prev] < dp[i])
                {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }

            if (dp[i] > maxi)
            {
                maxi = dp[i];
                lastindex = i;
            }
        }
        vector<int> temp;
        temp.push_back(arr[lastindex]);
        while (hash[lastindex] != lastindex)
        {
            lastindex = hash[lastindex];
            temp.push_back(arr[lastindex]);
        }

        reverse(temp.begin(), temp.end());

        // printing the LIS
        //  for(auto it: temp){
        //      cout<<it<<" ";
        //  }
        //  cout<<endl;
        return maxi;
    }

    int binary_search_LIS(int arr[], int n)
    {
        vector<int> temp;
        temp.push_back(arr[0]);
        int len = 1;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > temp.back())
            {
                temp.push_back(arr[i]);
                len++;
            }
            else
            {
                int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
                temp[ind] = arr[i];
            }
        }
        return len;
    }

    // counting the numbers of LIS(s)

    int findNumberofLIS(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> dp(n, 1), cnt(n, 1);
        int maxi = 1;
        for (int i = 0; i < n; i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                if (arr[prev] < arr[i] && 1 + arr[prev] > dp[i])
                {
                    dp[i] = 1 + dp[prev];
                    cnt[i] = cnt[prev];
                }
                else if (arr[prev] < arr[i] && 1 + dp[prev] == dp[i])
                {
                    cnt[i] += cnt[prev];
                }
            }
            maxi = max(maxi, dp[i]);
        }
        int nos = 0;
        for (int i = 0; i < n; i++)
        {
            if (dp[i] == maxi)
                nos += cnt[i];
        }
        return nos;
    }

public:
    int longestincreasingsubsequence(int arr[], int n)
    {
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(0, -1, n, arr, dp);
    }
};