#include <bits/stdc++.h>
using namespace std;
class dfs_solution{
    private:
    bool dfsCheck(int node,vector<int> adj[],int vis[],int pathVis[]){
        vis[node] = 1;
        pathVis[node] =1;
        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfsCheck(it,adj,vis,pathVis)){
                    return true;
                }
            }
            else if(pathVis[it]){
                return true;
            }
        }
        pathVis[node] =0;
        return false;
    }
    public:
    bool iscyclic(int V,vector <int> adj[]){
        int vis[V] = {0};
        int pathVis[V] = {0};
        for(int i =0;i<V;i++){
            if(!vis[i]){
                if(dfsCheck(i,adj,vis,pathVis)){
                    return true;
                }
            }
        }
        return false;
    }
};
class bfs_solution{
    public:
    bool iscyclic(int V, vector<int> adj[]){
        int indegree[V] = {0};
        for(int i =0;i<V;i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i =0;i<V;i++){
            if(indegree[i] ==0){
                q.push(i);
            }
        }
        int cnt =0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        if(cnt == V){
            return false;
        }
        return true;
    }
};