#include <bits/stdc++.h>
using namespace std;
class solution{
    private:
    int timer = 0;
    void dfs(int node,int parent,vector<int> &vis,int tin[],int low[],vector<int> &mark,vector<int>adj[]){
        vis[node] =1;
        tin[node] = low[node] = timer;
        timer++;
        int child =0;
        for(auto it: adj[node]){
            if(it == parent) continue;
            if(!vis[it]){
                dfs(it,node,vis,tin,low,mark,adj);
                low[node] = min(low[node],low[it]);
                if(low[it] >= tin[node] && parent != -1) mark[node] =1;
                child++;
            }
            else{
                low[node] = min(low[node],tin[it]);
            }
        }
        if(child >1 && parent ==-1){
            mark[node] =1;
        }
    }
    vector<int> articulationPoint(int V,vector<int> adj[]){
        vector<int> vis(V,0);
        int tin[V],low[V];
        vector<int> mark(V,0);

        for(int i =0;i<V;i++){
            if(!vis[i]){
                dfs(i,-1,vis,tin,low,mark,adj);
            }
        }

        vector<int> ans;
        for(int i =0;i<V;i++){
            if(mark[i]) ans.push_back(i);
        }
        if(!ans.size()) return {-1};

        return ans;
    }
};