#include <bits/stdc++.h>
using namespace std;
class Solution{
    int prims_algorithm(int V,vector<vector<int>> adj[]){
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
        vector <int> vis(V,0);
        //saving only node and weight
        pq.push({0,0});
        int sum =0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int wt = it.first;
            //adding the node into the MST
            if(vis[node]==1) continue;
            vis[node] =1;
            sum+= wt;

            for(auto it : adj[node]){
                int adjnode = it[0];
                int edgeweight = it[1];
                if(!vis[adjnode]){
                    pq.push({edgeweight,adjnode});
                }
            }
        }
        return sum;
    }
};