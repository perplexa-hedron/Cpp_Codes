#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls){
    vis[node] = 1;
    ls.push_back(node);
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis,ls);
        }
    }
}
vector<int> dfs_of_graph(int n,vector<int> adj[]){
    int vis[n] = {0};
    int start = 0;
    vector<int> ls;
    dfs(start, adj,vis, ls);
    return ls;
}
vector<int> bfs_traversal(int n, vector<int> adj[]){
    int visited[n] = {0};
    visited[0] = 1;
    queue<int> q;
    q.push(0);
    vector<int> bfs;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it: adj[node]){
            if(!visited[it]){
                visited[it]=1;
                q.push(it);
            }
        }
    }
    return bfs;
}