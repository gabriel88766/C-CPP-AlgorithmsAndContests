#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


struct centroid{
    vector<bool> ac;
    vector<int> sub;
    vector<int> par; //parent array after dec.
    vector<vector<int>> tree; //old tree
    vector<vector<int>> adj;
    vector<vector<int>> anc;
    vector<int> h;
    vector<vector<int>> allch; //all nodes in subtree. 359G specific.
    vector<int> val;//359G specific.
    vector<long long> aux, aux2;//also 359G specific.
    int rt; //after dec
    void build_distances(){ //LCA
        anc.resize(tree.size());
        h.resize(tree.size());
        h[0] = -1;
        for(int i=0;i<tree.size();i++) anc[i].resize(20);
        function<void(int,int)> dfs = [&](int u, int p){
            anc[u][0] = p;
            h[u] = h[p] + 1;
            for(auto v : tree[u]){
                if(v != p){
                    dfs(v, u);
                }
            }
        };
        dfs(1, 0);
        for(int i=1;i<20;i++){
            for(int j=1;j<tree.size();j++){
                anc[j][i] = anc[anc[j][i-1]][i-1];
            }
        }
    }
    int dist(int a, int b){ //O(log n);
        int ans = 0;
        if(h[a] > h[b]) swap(a, b);
        for(int i=19;i>=0;i--){
            if(h[a] + (1 << i) <= h[b]){
                ans += (1 << i);
                b = anc[b][i];
            }
        }
        if(a == b) return ans;
        for(int i=19;i>=0;i--){
            if(anc[a][i] != anc[b][i]){
                ans += 2 * (1 << i);
                a = anc[a][i];
                b = anc[b][i];
            }
        }
        return ans + 2;
    }
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
        build_distances();
    }
    ll solve(int u){
        ll ans = 0;
        for(auto &v : adj[u]){
            ans += solve(v);
        }
        allch[u].push_back(u);
        aux2[val[u]]++;
        for(auto &v : adj[u]){
            for(auto &x : allch[v]){
                allch[u].push_back(x);
                ans += dist(x, u) * aux2[val[x]] + aux[val[x]];
            }
            for(auto &x : allch[v]){
                aux[val[x]] += dist(x, u);
                aux2[val[x]] += 1;
            }
        }
        for(auto&v : adj[u]){
            for(auto &x : allch[v]){
                aux[val[x]] = aux2[val[x]] = 0;
            }
        }
        aux[val[u]] = aux2[val[u]] = 0;
        return ans;
    }
};


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    centroid ct;
    ct.tree.resize(n+1);
    ct.allch.resize(n+1);
    ct.val.resize(n+1);
    ct.aux.resize(n+1);
    ct.aux2.resize(n+1);
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        ct.tree[a].push_back(b);
        ct.tree[b].push_back(a);
    }
    for(int i=1;i<=n;i++) cin >> ct.val[i];
    ct.build();
    cout << ct.solve(ct.rt) << "\n";
}
