#include <bits/stdc++.h>
using namespace std;
class brute_force_solution{
    private:
    void toposort(int node,vector<pair<int,int>> adj[], int vis[],stack<int> &st){
        vis[node] = 1;
        for(auto it: adj[node]){
            int v = it.first;
            if(!vis[v]){
                toposort(v,adj,vis,st);
            }
        }
        st.push(node);
    }
    public:
    vector<int> shortestpath(int N,int M,vector<int> edges[]){
        vector<pair<int,int>> adj[N];
        for(int i =0;i<M;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
        }

        //finding the topo sort
        int vis[N] = {0};
        stack<int> st;
        for(int i =0;i<N;i++){
            if(!vis[i]){
                toposort(i,adj,vis,st);
            }
        }

        vector<int> dist;
        for(int i =0;i<N;i++){
            dist[i] = 1e9;
        }
        dist[0] = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            for(auto it: adj[node]){
                int v = it.first;
                int wt = it.second;

                if(dist[node] + wt <dist[v]){
                    dist[v] = dist[node] + wt;
                }
            }
        }
        return dist;
    }
};