#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int maximumfunction(int next_day, int last_task,vector<vector<int>> task,vector<vector<int>> &dp)
    {
        if(next_day == 0){
            int maxi = 0;
            for(int i =0;i<3;i++){
                if(i != last_task){
                    maxi = max(maxi,task[0][i]);
                }
            }
            return dp[next_day][last_task] = maxi;
        }

        int maxi =0;
        for(int i =0;i<3;i++){
            int points = 0;
            if(i != last_task){
                points = task[next_day][i] + maximumfunction(next_day-1,i,task,dp);
            }
            maxi = max(maxi,points);
        }

        return dp[next_day][last_task] = maxi;
    }

    int tabulation(int n, vector<vector<int>> points){
        vector<int> prev(4,0);

        prev[0] = max(points[0][1],points[0][2]);
        prev[1] = max(points[0][0],points[0][2]);
        prev[2] = max(points[0][0],points[0][1]);
        prev[3] = max(points[0][1],max(points[0][2],points[0][0]));

        for(int day =0;day<n;day++){
            vector<int> temp(4,0);
            for(int last = 0;last<4;last++){
                temp[last] = 0;
                for(int task=0;task<3;task++){
                    if(task != last){
                        temp[last] = max(temp[last],points[day][task] + prev[task]);
                    }
                }
            }
            prev = temp;
        }
        return prev[3];
    }
public:
    int maximumpoints(int n, vector<vector<int>> &task)
    {
        vector<vector<int>> dp(n,vector<int>(4,-1));
        return maximumfunction(n-1,3,task,dp);
    }
};