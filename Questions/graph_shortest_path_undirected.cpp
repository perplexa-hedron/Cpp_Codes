#include <bits/stdc++.h>
using namespace std;
class brute_solution{
    public:
    vector<int> shortestPath(vector <vector<int>>& edges,int N,int M,int src){
        vector<int> adj[N];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        // int dist[N] = {1e9};
        int dist[N];
        for(int i =0;i<N;i++){
            dist[i] = 1e9;
        }
        dist[src] = 0;
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it: adj[node]){
                if(dist[node] + 1 < dist[it]){
                    dist[it] = dist[node]+1;
                    q.push(it);
                }
            }
        }
        vector<int> ans(N,-1);
        for(int i =0;i<M;i++){
            if(dist[i] !=1e9){
                ans[i] = dist[i];
            }
        }
        return ans;
    }
};


class priority_queue_dijsktra_solution{
    public:
    vector<int> dijsktra(int V,vector<vector<int>> adj[],int S){
        priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist;
        for(int i =0;i<V;i++){
            dist[i] = 1e9;
        }
        dist[S] = 0;
        pq.push({0,S});

        while(!pq.empty()){
            int weight = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it: adj[node]){
                int edgeweight = it[1];
                int adjnode = it[0];

                if(weight + edgeweight < dist[adjnode]){
                    dist[adjnode] = weight + edgeweight;
                    pq.push({dist[adjnode], adjnode});
                }
            }
        }

        return dist;
    }
};

class set_dijsktra_solution{
    public:
    vector<int> dijsktra(int V,vector<vector<int>> adj[],int S){
        set<pair<int,int>> st;
        vector<int> dist(V,1e9);
        st.insert({0,S});
        dist[S] = 0;

        while(!st.empty()){
            auto it = * (st.begin());
            int weight = it.first;
            int node = it.second;
            st.erase(it);
            for(auto it: adj[node]){
                int adjnode = it[0];
                int edgeweight = it[1];

                if(weight + edgeweight < dist[adjnode]){
                    if(dist[adjnode] != 1e9){
                        st.erase({dist[adjnode],adjnode});
                    }
                    dist[adjnode] = weight + edgeweight;
                    st.insert({dist[adjnode], adjnode});
                }
            }
        }
        return dist;
    }
};