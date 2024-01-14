#include <bits/stdc++.h>
using namespace std;
class Solution{
private:
    void dfs(int node, vector<int> &vis,vector<int> adj[], stack<int> &st){
        vis[node] =1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj,st);
            }
        }
        st.push(node);
    }

    void dfs3(int node,vector<int> &vis,vector<int> tadj[]){
        vis[node] =1;
        for(auto it: tadj[node]){
            if(!vis[it]){
                dfs3(it,vis,tadj);
            }
        }
    }

public:
    int kosaraju(int v,vector<int> adj[]){
        vector<int> vis(v,0);
        stack<int> st;
        for(int i =0;i<v;i++){
            if(!vis[i]){
                dfs(i,vis,adj,st);
            }
        }

        vector<int> tadj[v];
        for(int i =0;i<v;i++){
            vis[i] =0;
            for(auto it : adj[i]){
                tadj[it].push_back(i);
            }
        }
        vector<vector<int>> scc_vector;
        int scc =0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            vector<int> ans;
            if(!vis[node]){
                scc++;
                dfs3(node,vis,tadj);
                // scc_vector.push_back(ans);
            }
        }
        return scc;
    }
};