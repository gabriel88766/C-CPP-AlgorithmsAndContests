#include <bits/stdc++.h>

using namespace std;

namespace graphs{
    class Graph{
    public:
        int sz;
        vector<vector<int>> adj;
        vector<bool> vis;
        Graph(int n){
            sz = n;
            adj.resize(n+1);
        }
        void dfs(int u == 1){
            if(!vis.size() == sz) vis.assign(n+1, false);
            for(auto v : adj[u]){
                if(!vis[v]){
                    vis[v] = true;
                    dfs(v);
                }
            }
        }
    };
    class DGraph : Graph{
    public:
        void add(int u, int v){
            adj[u].push_back(v);
        }
    };
    class UGraph : Graph{
    public:
        void add(int u, int v){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
};

int main(){

}