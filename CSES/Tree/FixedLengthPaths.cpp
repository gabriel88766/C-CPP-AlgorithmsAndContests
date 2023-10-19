#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int n, k;
ll ans = 0;

int ct = 0;

struct centroid{
    vector<bool> ac;
    vector<int> sub;
    vector<int> par; //parent array after dec.
    vector<vector<int>> tree; //old tree
    vector<vector<int>> adj;
    vector<int> d;
    vector<ll> qt;
    vector<int> alld;
    int rt; //after dec
    int cnt;
    void dfsT(int u, int p){
        sub[u] = 1;
        for(auto v : tree[u]){
            if(v != p && !ac[v]){
                dfsT(v, u);
                sub[u] += sub[v];
            }
        }
    }
    int find_centroid(int u){
        dfsT(u, 0);
        int sz = sub[u]/2, p = 0;
        while(true){
            int nxt = 0;
            for(auto v: tree[u]){
                if(!ac[v] && sub[v] > sz && v != p){
                    nxt = v;
                }
            }
            if(nxt){
                p = u;
                u = nxt;
            }else break;
        }
        return u;
    }
    void build(){
        sub.resize(tree.size());
        par.resize(tree.size());
        adj.resize(tree.size());
        ac.assign(tree.size(), false);
        rt = find_centroid(1);
        ac[rt] = true;
        queue<int> q;
        q.push(rt);
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            for(auto v : tree[u]){
                if(!ac[v]){
                    int t = find_centroid(v);
                    adj[u].push_back(t);
                    par[t] = u;
                    ac[t] = true;
                    q.push(t);
                }
            }
        }
    }
    //Fixed Length Paths specific
    void dfs1(int u){
        cnt++;
        d[u] = INF_INT;
        for(auto v : adj[u]){
            dfs1(v);
        }
    }
    void dfs2(int u, int p){
        alld.push_back(d[u]);
        for(auto v: tree[u]){
            if(v != p && !ac[v]){
                d[v] = d[u] + 1;
                dfs2(v, u);
            }
        }
    }
    void solve(){
        fill(ac.begin(), ac.end(), false);
        d.resize(tree.size());
        qt.resize(tree.size());
        qt[0] = 1;
        queue<int > q;
        q.push(rt);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            cnt = 0;
            dfs1(u);
            for(int i=1;i<=cnt;i++) qt[i] = 0;
            ac[u] = true;
            for(auto v : tree[u]){
                if(ac[v]) continue;
                d[v] = 1;
                dfs2(v, 0);
                for(auto x : alld){
                    if(k-x >= 0 && k-x <= cnt) ans += qt[k-x];
                }
                while(alld.size()){
                    qt[alld.back()]++;
                    alld.pop_back();
                }
            }
            for(auto v : adj[u]) q.push(v);
        }
    }
};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in", "r", stdin); //test input
    cin >> n >> k;
    centroid c;
    c.tree.resize(n+1);
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        c.tree[a].push_back(b);
        c.tree[b].push_back(a);
    }
    
    c.build();
    c.solve();
    cout << ans << "\n";
}   
