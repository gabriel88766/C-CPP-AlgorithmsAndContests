#include <bits/stdc++.h>
using namespace std;

struct centroid{
    vector<bool> hc;
    vector<int> sub;
    vector<vector<int>> adj; //tree after decomposition
    vector<vector<int>> tree; //old tree
    void dfs(int u, int p){
        sub[u] = 1;
        for(auto v : tree[u]){
            if(v != p && !hc[v]){
                dfs(v, u);
                sub[u] += sub[v];
            }
        }
    }
    int find_centroid(int u){
        dfs(u, 0);
        int tsz = sub[u];
        int p;
        while(true){
            int maxcur = 0, maxid;
            for(auto v: tree[u]){
                if(!hc[v] && sub[v] > maxcur && v != p){
                    maxcur = sub[v];
                    maxid = v;
                }
            }
            if(maxcur > tsz/2){
                p = u;
                u = maxid;
            }else break;
        }
        return u;
    }
    void build(){
        adj.resize(tree.size());
        sub.resize(tree.size());
        hc.assign(tree.size(), false);
        int c = find_centroid(1);
        hc[c] = true;
        queue<int> q;
        q.push(c);
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            for(auto v : tree[u]){
                if(!hc[v]){
                    int t = find_centroid(v);
                    adj[u].push_back(t);
                    hc[t] = true;
                    q.push(t);
                }
            }
        }
    }
};

int main(){
    centroid c;
    int n;
    cin >> n;
    c.tree.resize(n+1);
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        c.tree[a].push_back(b);
        c.tree[b].push_back(a);
    }
    c.build();
    vector<int> ans(n+1, -1);
    for(int i=1;i<=n;i++){
        for(auto v : c.adj[i]) ans[v] = i;
    }
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
    cout << "\n";
}