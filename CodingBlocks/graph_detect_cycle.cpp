#include <bits/stdc++.h>
using namespace std;
class solution_bfs
{
private:
    bool detect(int src, vector<int> adj[], int vis[])
    {
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});
        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto adjacentNode : adj[node])
            {
                if (!vis[adjacentNode])
                {
                    vis[adjacentNode] = 1;
                    q.push({adjacentNode, node});
                }
                else if (parent != adjacentNode)
                {
                    return true;
                }
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[])
    {
        int vis[V] = {0};
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (detect(i, adj, vis))
                {
                    return true;
                }
            }
        }

        return false;
    }
};
class solution_dfs
{
private:
    bool dfs(int node, int parent, int vis[], vector<int> adj[])
    {
        vis[node] = 1;
        for (auto adjacentnode : adj[node])
        {
            if (!vis[adjacentnode])
            {
                if (dfs(adjacentnode, node, vis, adj) == true)
                {
                    return true;
                }
            }
            else if (adjacentnode != parent)
            {
                return true;
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[])
    {
        int vis[V] = {0};
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, -1, vis, adj) == true)
                {
                    return true;
                }
            }
        }
        return false;
    }
};