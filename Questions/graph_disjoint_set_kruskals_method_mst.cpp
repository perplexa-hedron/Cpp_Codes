#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
private:
    vector<int> parent, rank, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] =1;
        }
    }

    int findParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }

    void UnionByRank(int u, int v)
    {
        int ultimate_parent_u = findParent(u);
        int ultimate_parent_v = findParent(v);
        if (ultimate_parent_u == ultimate_parent_v)
            return;
        if (rank[ultimate_parent_u] < rank[ultimate_parent_v])
        {
            parent[ultimate_parent_u] = ultimate_parent_v;
        }
        else if (rank[ultimate_parent_u] > rank[ultimate_parent_v])
        {
            parent[ultimate_parent_v] = ultimate_parent_u;
        }
        else
        {
            parent[ultimate_parent_v] = ultimate_parent_u;
            rank[ultimate_parent_u]++;
        }
    }
    void UnionBySize(int u, int v)
    {
        int ultimate_parent_u = findParent(u);
        int ultimate_parent_v = findParent(v);
        if (ultimate_parent_u == ultimate_parent_v)
            return;
        if (size[ultimate_parent_u] < size[ultimate_parent_v])
        {
            parent[ultimate_parent_u] = ultimate_parent_v;
            size[ultimate_parent_v] += size[ultimate_parent_u];
        }
        else
        {
            parent[ultimate_parent_v] = ultimate_parent_u;
            size[ultimate_parent_u] += size[ultimate_parent_v];
        }
    }
};

class solution{
    public: 
    int spanningtree(int V,vector<vector<int>> adj[]){
        vector<pair<int,pair<int,int>>> edges;
        for(int i = 0;i<V;i++){
            for(auto it: adj[i]){
                int adjnode = it[0];
                int wt = it[1];
                int node = i;
                
                edges.push_back({wt,{node,adjnode}});
            }
        }

        DisjointSet ds(V);
        sort(edges.begin(),edges.end());
        int mstwt = 0;
        for(auto it : edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if(ds.findParent(u) != ds.findParent(v)){
                mstwt+=wt;
                ds.UnionBySize(u,v);
            }
        }

        return mstwt;
    }
};